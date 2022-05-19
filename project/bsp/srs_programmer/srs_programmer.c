#include "HAL_conf.h"
#include "UART.h"
#include "string.h"
#include <stdbool.h>
#include "srs_programmer.h"
#include "lvgl.h"

bool is_pwm_mode();
void PD6_UART_conf();
void PD6_PWM_conf();

#define ENSURE_UART                 \
    if (is_pwm_mode())              \
    {                               \
        PD6_UART_conf();            \
        volatile u32 sleep = 10000; \
        while (sleep--)             \
            ;                       \
    }
#define ENSURE_PWM      \
    if (!is_pwm_mode()) \
    {                   \
        PD6_PWM_conf(); \
    }

#define UART4_RX_BUF_SIZE 256
#define PROGRAMMING_TIMEOUT 1000

static u8 get_angle_packet[] = {0xFF, 0xFF, 0xFE, 0x04, 0x02, 0x3B, 0x02, 0xBE};
static u8 write_enable_packet[] = {0xFF, 0xFF, 0x01, 0x04, 0x03, 0x34, 0x00, 0xC3};
static u8 program_continuos_packet[] = {0xFF, 0xFF, 0x01, 0x2F, 0x03, 0x06, 0x32, 0x14, 0x00, 0x05, 0x00, 0x0A, 0x00, 0x0A, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x03, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x41, 0x03, 0xC5, 0x01, 0xF4, 0x01, 0xFF, 0x00, 0x00, 0x02, 0x06, 0x0E, 0x05, 0xAA, 0x03, 0xE8, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x03, 0xE8, 0x00, 0x99};
static u8 program_angle_packet[] = {0x01, 0x2F, 0x03, 0x06, 0x02, 0x1E, 0x00, 0x05, 0x00, 0x0F, 0x00, 0x2D, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x03, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x41, 0x03, 0xC5, 0x00, 0x00, 0x01, 0xFF, 0x01, 0x00, 0x02, 0x09, 0xC4, 0x01, 0xF4, 0 /* left */, 0 /* left */, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0 /* right */, 0 /* right */, 0x00};
srs_programming_state_t state = NOT_PROGRAMMING;
static u32 programming_time = 0;

static u8 program_packet1[] = {0xFF, 0xFF, 0xFE, 0x02, 0x01, 0xFE};                  // FF FF 01 02 00 FC
static u8 get_mode_packet[] = {0xFF, 0xFF, 0x01, 0x04, 0x02, 0x15, 0x01, 0xE2};      // FF FF 01 03 00 00 FB
static u8 write_disable_packet[] = {0xFF, 0xFF, 0x01, 0x04, 0x03, 0x34, 0x01, 0xC2}; // FF FF 01 02 00 FC

static u8 get_angle_conf_packet[] = {0x01, 0x04, 0x02, 0x27, 0x0A};

#define PACK_BIG_ENDIAN_16(msb, lsb) ((((u16)(msb)) << 8) + (lsb))

static volatile u8 rx_buf[UART4_RX_BUF_SIZE];
static volatile u16 rx_i = 0;

u8 calc_checksum(u8 *message, u16 len)
{
    u8 sum = 0;
    while (len--)
        sum += *message++;

    return ~sum;
}

void send_byte(u8 byte)
{
    while ((UART4->CSR & UART_CSR_TXC) == 0)
        ;
    UART4->TDR = byte;
}

void send_raw(u8 *raw, u16 len)
{
    while (len--)
        send_byte(*raw++);
}

void send_message(u8 *message, u16 len)
{
    u8 checksum = calc_checksum(message, len);
    send_byte(0xFF);
    send_byte(0xFF);
    while (len--)
        send_byte(*message++);
    send_byte(checksum);
}

int get_angle()
{
    int angle;
    volatile u32 timeout;

    ENSURE_UART;

    rx_i = 0;
    send_raw(get_angle_packet, sizeof(get_angle_packet));

    timeout = 2000;
    while (rx_i < 9 && timeout != 0)
    {
        timeout--;
    }

    if (timeout == 0 || rx_i == UINT16_MAX)
    {
        return INT32_MAX;
    }

    timeout = 8000;
    while (rx_i < 16 && timeout != 0)
    {
        timeout--;
    }

    if (timeout == 0 || rx_i == UINT16_MAX)
    {
        return INT32_MAX;
    }

    angle = ((u16)(rx_buf[13] << 8)) + ((u16)rx_buf[14]);

    return map(angle, 0, -180 + 20, 1023, 179 - 20); // the range of the potentiometer is 320 degrees
}

srs_mode_t get_mode()
{
    volatile u32 timeout;
    u8 mode;
    rx_i = 0;

    ENSURE_UART;

    send_raw(get_mode_packet, sizeof(get_mode_packet));

    timeout = 2000;
    while (rx_i < sizeof(get_mode_packet) + 1 && timeout != 0)
    {
        timeout--;
    }
    if (timeout == 0)
    {
        return UNKNOWN;
    }

    timeout = 6000;
    while (timeout != 0)
    {
        timeout--;
    }
    if (rx_i < sizeof(get_mode_packet) + 7)
    {
        return UNKNOWN;
    }

    mode = rx_buf[sizeof(get_mode_packet) + 5];
    if (mode < 3)
    {
        return (srs_mode_t)mode; // 0 == servo, 1 == cont
    }
    return UNKNOWN;
}

bool send_write_enable()
{
    volatile u32 timeout;
    rx_i = 0;

    send_raw(program_packet1, sizeof(program_packet1));
    timeout = 2000;
    while (rx_i < sizeof(program_packet1) + 1 && timeout != 0)
    {
        timeout--;
    }
    if (timeout == 0)
    {
        return false;
    }
    timeout = 6000;
    while (timeout != 0)
    {
        timeout--;
    }
    if (rx_i < sizeof(program_packet1) + 6)
    {
        return false;
    }

    get_mode();

    rx_i = 0;
    send_raw(write_enable_packet, sizeof(write_enable_packet));

    timeout = 8000;
    while (timeout != 0)
    {
        timeout--;
    }
    if (rx_i < sizeof(write_enable_packet) + 6)
    {
        return false;
    }
    return true;
}

srs_programming_state_t get_programming_status()
{
    if (state == PROGRAMMING)
    {
        if (rx_i == sizeof(program_continuos_packet) + 6)
        {
            volatile u32 timeout = 1000;
            while (timeout)
                timeout--;
            timeout = 10000;

            rx_i = 0;
            send_raw(write_disable_packet, sizeof(write_disable_packet));
            while (rx_i < sizeof(write_disable_packet) + 6 && timeout)
                timeout--;
            if (timeout)
                state = PROGRAMMING_SUCCESS;
            else
                state = PROGRAMMING_FAIL;
        }
        else
        {

            if (lv_tick_elaps(programming_time) > 1000)
            {
                state = PROGRAMMING_FAIL;
            }
        }
    }
    if (state != PROGRAMMING)
    {
        srs_programming_state_t tmp = state;
        state = NOT_PROGRAMMING;
        return tmp;
    }
    return PROGRAMMING;
}

void program_continuos()
{
    ENSURE_UART;

    if (!send_write_enable())
    {
        state = PROGRAMMING_FAIL;
        return;
    }
    rx_i = 0;
    send_raw(program_continuos_packet, sizeof(program_continuos_packet));

    // programming takes too long, better do asynchronously (poll get_programming_status)
    state = PROGRAMMING;
    programming_time = lv_tick_get();
}

void program_servo_angles(int left_angle, int right_angle)
{
    ENSURE_UART;

    right_angle = map(right_angle, 135, 1000, 0, 0);
    left_angle = map(left_angle, -135, 1000, 0, 0);

    if (!send_write_enable())
    {
        state = PROGRAMMING_FAIL;
        return;
    }
    rx_i = 0;
    program_angle_packet[37] = (left_angle & 0xFF00) >> 8;
    program_angle_packet[38] = left_angle & 0x00FF;
    program_angle_packet[45] = (right_angle & 0xFF00) >> 8;
    program_angle_packet[46] = right_angle & 0x00FF;

    send_message(program_angle_packet, sizeof(program_angle_packet));

    // programming takes too long, better do asynchronously (poll get_programming_status)
    state = PROGRAMMING;
    programming_time = lv_tick_get();
}

void get_config(srs_conf_t *config)
{
    config->mode = get_mode();
    if (config->mode == UNKNOWN)
    {
        config->left_angle = 0;
        config->right_angle = 0;
        return;
    }
    rx_i = 0;
    send_message(get_angle_conf_packet, sizeof(get_angle_conf_packet));
    // timeout = 8000;
    while (rx_i < sizeof(get_angle_conf_packet) + 3 + 6 + 10)
    {
        // timeout--;
    }

    config->left_angle = map(PACK_BIG_ENDIAN_16(rx_buf[13], rx_buf[14]), 1000, -135, 0, 0);
    config->right_angle = map(PACK_BIG_ENDIAN_16(rx_buf[21], rx_buf[22]), 1000, 135, 0, 0);
}

bool is_pwm_mode()
{
    return (bool)TIM2->CR1 & TIM_CR1_CEN;
}

void set_pwm_output(int duty_us)
{
    ENSURE_PWM;
    //           ARR   - ARR   * (duty_us) / (1/Frequency (50Hz))
    TIM2->CCR2 = 10000 - 10000 * (duty_us) / 20000;
    TIM_Cmd(TIM2, ENABLE);
}

void PD6_UART_conf()
{
    GPIO_InitTypeDef GPIO_InitStructure;

    TIM_Cmd(TIM2, DISABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;

    GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_PinAFConfig(GPIOD, GPIO_Pin_6, GPIO_AF_UART_2345);

    UART_Cmd(UART4, ENABLE);
}

void PD6_PWM_conf()
{
    GPIO_InitTypeDef GPIO_InitStructure;

    UART_Cmd(UART4, DISABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_PinAFConfig(GPIOD, GPIO_Pin_6, GPIO_AF_TIM_1_2);
}

void UART_init()
{
    UART_InitTypeDef UART_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_PinAFConfig(GPIOD, GPIO_Pin_7, GPIO_AF_UART_2345);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_UART4, ENABLE);
    UART_InitStructure.UART_BaudRate = 77170;
    UART_InitStructure.UART_WordLength = UART_WordLength_8b;
    UART_InitStructure.UART_StopBits = UART_StopBits_1;
    UART_InitStructure.UART_Parity = UART_Parity_No;
    UART_InitStructure.UART_Mode = UART_Mode_Rx | UART_Mode_Tx;
    UART_InitStructure.UART_HardwareFlowControl = UART_HardwareFlowControl_None;
    UART_Init(UART4, &UART_InitStructure);

    UART_ClearITPendingBit(UART4, 0xff);

    UART_ITConfig(UART4, UART_IT_RXIEN, ENABLE);
    NVIC_SetPriority(UART4_IRQn, 3);
    NVIC_EnableIRQ(UART4_IRQn);
}

void PWM_init()
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM2, ENABLE);

    // 50Hz
    TIM_TimeBaseStructure.TIM_Period = 10000;
    TIM_TimeBaseStructure.TIM_Prescaler = 480;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

    // Hal is convoluted, simpler to do direct register operations
    TIM2->CCR2 = 0; // compare value (1 - crr/arr == duty cycle % -> 100%)

    TIM2->CCMR1 = 0;
    TIM2->CCMR1 |= (TIM_CCMR1_OC2M);  // Enable output compare for channel 2
    TIM2->CCMR1 |= (TIM_CCMR1_OC2PE); // Enable preload for channel 2

    TIM2->CCER = 0;
    TIM2->CCER |= TIM_CCER_CC2E; // Enable output compare for channel 2

    TIM2->BDTR |= TIM_BDTR_MOE; // main output enable
}
void srs_programmer_init()
{

    UART_init();

    PD6_UART_conf();

    PWM_init();
}
u8 Uart4_Receive(void)
{

    while ((UART4->CSR & UART_CSR_RXAVL) == 0)
        ;
    return UART4->RDR;
}
void UART4_IRQHandler(void)
{

    if (UART4->ISR & UART_ISR_RX_INTF)
    {

        u8 ch = Uart4_Receive();
        if (rx_i < UART4_RX_BUF_SIZE) // discard data if buffer is full
        {
            rx_buf[rx_i++] = ch;
            // send_data(ch);
        }
        UART4->ICR |= UART_ICR_RXICLR;
    }
}
