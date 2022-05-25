#include "UART.h"
#include <stdio.h>
#include "ring_buffer.h"

ring_buffer RX_buffer = {0, 0};

void UartInit(UART_TypeDef *UARTx, int BaudRate)
{
	UART_InitTypeDef UART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; // uart1_tx  PA9
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; // uart1_rx  PA10
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;

	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_Pin_9 | GPIO_Pin_10, GPIO_AF_UART_1);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_UART1, ENABLE);
	UART_InitStructure.UART_BaudRate = BaudRate;
	UART_InitStructure.UART_WordLength = UART_WordLength_8b;
	UART_InitStructure.UART_StopBits = UART_StopBits_1;
	UART_InitStructure.UART_Parity = UART_Parity_No;
	UART_InitStructure.UART_Mode = UART_Mode_Rx | UART_Mode_Tx;
	UART_InitStructure.UART_HardwareFlowControl = UART_HardwareFlowControl_None;
	UART_Init(UARTx, &UART_InitStructure);
	UART_Cmd(UARTx, ENABLE);
	UART_ITConfig(UARTx, UART_IT_RXIEN, ENABLE);
	UART_ClearITPendingBit(UARTx, 0xff);

	NVIC_SetPriority(UART1_IRQn, 3);
	NVIC_EnableIRQ(UART1_IRQn);
}
u8 Uart1_Receive(void)
{
	// wait for data
	while ((UART1->CSR & (1 << 1)) == 0)
		;
	return UART1->RDR;
}
void UART1_IRQHandler(void)
{
	if (UART1->ISR & (1 << 1))
	{
		ring_buffer_write(&RX_buffer, Uart1_Receive());
		UART1->ICR |= 1 << 1;
		//		  printf("UART1_RDR = %d\n",UART1->RDR);
	}
}
void send_data(u8 data)
{
	while ((UART1->CSR & 0x1) == 0)
		;
	UART1->TDR = data;
}
u8 receive_byte(char *c)
{
	volatile u32 timeout = 100000;
	while (ring_buffer_available(&RX_buffer) == 0 && timeout)
		timeout--;
	if (timeout)
	{
		*c = ring_buffer_read(&RX_buffer);
		return 0;
	}
	return 1;
}

u8 receive_until(char *s, char delim)
{
	char c = 'x';
	while (receive_byte(&c) == 0 && c != delim)
	{
		*s++ = c;
	}
	*s = '\0';

	return c == delim;
}

void send_group(u8 *data, u16 len)
{
	while (len--)
		send_data(*data++);
}
void send_str(char *p)
{
	while (*p != '\0')
	{
		send_data(*p);
		p++;
	}
}
