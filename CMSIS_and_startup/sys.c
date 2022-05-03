#include "sys.h"
#include "HAL_misc.h"

void RemapVtorTable(void)
{
	int i;
	RCC->AHB1ENR |= 1 << 13; // bkp clk,enable sram
	// Disable interrupts
	for (i = 0; i < 90; i++)
	{
		NVIC_DisableIRQ((IRQn_Type)i);
	}
	SCB->VTOR = 0;
	SCB->VTOR |= 0x1 << 29;
	for (i = 0; i < 512; i += 4)
		*(u32 *)(T_SRAM_BASE + i) = *(u32 *)(T_SDRAM_BASE + i);
}

void AI_Responder_enable(void)
{
	AI_Responder->ADDR1 = 0x70807040;
	//	AI_Responder->ADDR0 = 0x70027080;
	AI_Responder->ADDR1 = 0;
	AI_Responder->CCR &= ~(0x3 << 3);
	AI_Responder->CCR |= 1;
	while ((AI_Responder->SR & 0x3) != 2)
		;
}
void AI_Responder_disable(void)
{
	AI_Responder->CCR &= ~1;
}

// External interrupt configuration function
// Only for GPIOA~E
// parameterד:
// GPIOx: 0~4, representing GPIOA~E
// BITx: The bit that needs to be enabled, such as PB12, 1 << 12;
// TRIM: trigger mode, 1, falling edge; 2, rising edge; 3, both
// This function can only configure one IO port at a time, and multiple IO ports need to be called multiple times.
// This function will automatically open the corresponding interrupt, and shield the line
void Ex_NVIC_Config(u8 GPIOx, u8 BITx, u8 TRIM)
{
	u8 EXTOFFSET = (BITx % 4) * 4;
	RCC->APB2ENR |= 1 << 14;							// enable SYSCFG clock
	SYSCFG->EXTICR[BITx / 4] &= ~(0x000F << EXTOFFSET); // Clear settings
	SYSCFG->EXTICR[BITx / 4] |= GPIOx << EXTOFFSET;		// EXTI.BITx maps toGPIOx.BITx

	// Configure interrupt
	EXTI->IMR |= 1 << BITx; // Enable interrupt for pin BITx (Reset bit to disable)
	if (TRIM & 0x01)
		EXTI->FTSR |= 1 << BITx; // Falling edge trigger
	if (TRIM & 0x02)
		EXTI->RTSR |= 1 << BITx; // Rising edge trigger
}

// THUMB instruction does not support assembly inlining
// The following method is used to execute the assembly instruction WFI
void WFI_SET(void)
{
	__ASM volatile("wfi");
}

// Disable all interrupts (except fault and NMI interrupts)
void INTX_DISABLE(void)
{
	__ASM volatile("cpsid i");
}

// Enable all interrupts
void INTX_ENABLE(void)
{
	__ASM volatile("cpsie i");
}
// set stack top address  __set_MSP(0x70002000);

// Enter standby mode
void Sys_Standby(void)
{
	SCB->SCR |= 1 << 2;		 // Enable SLEEPDEEP bit (SYS->CTRL)
	RCC->APB1ENR |= 1 << 28; // enable POWER clock
	PWR->CSR |= 1 << 8;		 // Set WKUP to wakeup
	PWR->CR |= 1 << 2;		 // Clear Wake-up flag
	PWR->CR |= 1 << 1;		 // Set PDDS
	WFI_SET();				 // Execute the wfi command to enter standby mode
}
// Soft system reset
void Sys_Soft_Reset(void)
{
	SCB->AIRCR = 0X05FA0000 | (u32)0x04;
}

//		TK499_NVIC_Init(2,2,TK80_IRQn,2);
// Set up NVIC
// NVIC_PreemptionPriority: Preemption priority
// NVIC_SubPriority : Response priority
// NVIC_Channel : interrupt number
// NVIC_Group : Interrupt group 0~4
// Note that the priority cannot exceed the range of the set group! Otherwise there will be unexpected errors
// Group division:
// Group 0: 0 bit preemption priority, 4 bit response priority
// Group 1: 1-bit preemption priority, 3-bit response priority
// Group 2: 2-bit preemption priority, 2-bit response priority
// Group 3: 3 bits for preemption priority, 1 bit for response priority
// Group 4: 4 bits for preemption priority, 0 bits for response priority
// The principle of NVIC_SubPriority and NVIC_PreemptionPriority is that the smaller the value, the higher the priority
void TK499_NVIC_Init(u8 NVIC_PreemptionPriority, u8 NVIC_SubPriority, u8 NVIC_Channel, u8 NVIC_Group)
{
	u32 temp;
	NVIC_SetPriorityGrouping(NVIC_Group);
	temp = NVIC_PreemptionPriority << (4 - NVIC_Group);
	temp |= NVIC_SubPriority & (0x0f >> NVIC_Group);
	temp &= 0xf;											 // Take the lower 4 digits
	NVIC->ISER[NVIC_Channel / 32] |= 1 << NVIC_Channel % 32; // Enable interrupt bit (to disable set the corresponding bit of ICER to 1)
	NVIC->IP[NVIC_Channel] |= temp << 4;					 // Set response priority
}

void TK80_IRQHandler(void)
{
	if (TK80->SR & 0x1)
	{
	}
	if (TK80->SR & 0x2)
	{
	}
	if (TK80->SR & 0x4)
	{
	}
	if (TK80->SR & 0x8)
	{
	}
	TK80->SR |= 0;
}
