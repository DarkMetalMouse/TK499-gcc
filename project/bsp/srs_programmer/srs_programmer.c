#include "HAL_conf.h"
#include "UART.h"
#include "string.h"

#define map(x, x1, y1, x2, y2) ((x) - (x2)) * ((y2) - (y1)) / ((x2) - (x1)) + (y2)

#define UART4_RX_BUF_SIZE 256
static u8 get_angle_packet[] = {0xFF, 0xFF, 0xFE, 0x04, 0x02, 0x3B, 0x02, 0xBE};
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
    rx_i = 0;
    send_raw(get_angle_packet, sizeof(get_angle_packet));
    if (rx_i != 7) // since loopback is instant and send_raw is blocking, we must have received the amount we sent
        return INT32_MAX;

    if (memcmp((u8 *)rx_buf, get_angle_packet, sizeof(get_angle_packet)) != 0)
        return INT32_MAX;

    timeout = 1000;
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

    return map(angle, 0, -180, 1023, 179);
}

void srs_programmer_init()
{
    UART_InitTypeDef UART_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;

    GPIO_Init(GPIOD, &GPIO_InitStructure);

    GPIO_PinAFConfig(GPIOD, GPIO_Pin_6 | GPIO_Pin_7, GPIO_AF_UART_2345);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_UART4, ENABLE);
    UART_InitStructure.UART_BaudRate = 77170;
    UART_InitStructure.UART_WordLength = UART_WordLength_8b;
    UART_InitStructure.UART_StopBits = UART_StopBits_1;
    UART_InitStructure.UART_Parity = UART_Parity_No;
    UART_InitStructure.UART_Mode = UART_Mode_Rx | UART_Mode_Tx;
    UART_InitStructure.UART_HardwareFlowControl = UART_HardwareFlowControl_None;
    UART_Init(UART4, &UART_InitStructure);
    UART_Cmd(UART4, ENABLE);

    UART_ClearITPendingBit(UART4, 0xff);

    UART_ITConfig(UART4, UART_IT_RXIEN, ENABLE);
    NVIC_SetPriority(UART4_IRQn, 3);
    NVIC_EnableIRQ(UART4_IRQn);
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
