#include <stdint.h>

extern int main(void);

typedef union
{
    void (*pFunc)(void);
    void *topOfStack;
} tVectorEntry;
/*----------------------------------------------------------------------------
 * Linker generated Symbols
 *----------------------------------------------------------------------------*/
extern uint32_t __etext;
extern uint32_t __data_start__;
extern uint32_t __data_end__;
extern uint32_t __copy_table_start__;
extern uint32_t __copy_table_end__;
extern uint32_t __zero_table_start__;
extern uint32_t __zero_table_end__;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;
extern uint32_t __StackTop;
/*----------------------------------------------------------------------------
 * Internal References
 *----------------------------------------------------------------------------*/
void Default_Handler(void); /* Default empty handler */
void Reset_Handler(void);   /* Reset Handler */

#ifndef __STACK_SIZE
#define __STACK_SIZE 0x00002000
#endif
static uint8_t stack[__STACK_SIZE] __attribute__((aligned(8), used, section(".stack")));

#ifndef __HEAP_SIZE
#define __HEAP_SIZE 0x00000000
#endif
#if __HEAP_SIZE > 0
static uint8_t heap[__HEAP_SIZE] __attribute__((aligned(8), used, section(".heap")));
#endif

/*----------------------------------------------------------------------------
 * Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
/* Cortex-M Processor Exceptions */
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));

void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("Default_Handler")));

void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));

/* External Interrupts */
void WWDG_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void TAMPER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void RCC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void ADC1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void EXTI9_5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void UART1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void UART2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void UART3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTCAlarm_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USBAwake_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM2_BRK_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM2_UP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM2_TRG_COM_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM2_CC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel8_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TK80_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SDIO1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SDIO2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void UART4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void UART5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void TIM8_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM9_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM10_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void USB_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel8_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void I2C3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void FPU_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void SPI4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void TOUCHPAD_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void QSPI_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void LTDC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

void I2S1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

/*----------------------------------------------------------------------------
 * Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/
extern const tVectorEntry __Vectors[];
const tVectorEntry __Vectors[] __attribute__((aligned(512))) __attribute__((section(".vectors"))) = {
    /* Cortex-M Exception Handlers */
    {.topOfStack = &__StackTop}, /* Initial Stack Pointer */
    {Reset_Handler},             /* Reset Handler */
    {NMI_Handler},               /* NMI Handler */
    {HardFault_Handler},         /* Hard Fault Handler */
    {BusFault_Handler},          /* Bus Fault Handler */
    {MemManage_Handler},         /* MPU Fault Handler */
    {UsageFault_Handler},        /* Usage Fault Handler */
    {Default_Handler},           /* Reserved */
    {Default_Handler},           /* Reserved */
    {Default_Handler},           /* Reserved */
    {Default_Handler},           /* Reserved */
    {SVC_Handler},               /* SVCall Handler */
    {DebugMon_Handler},          /* Debug Monitor Handler */
    {Default_Handler},           /* Application properties*/
    {PendSV_Handler},            /* PendSV Handler */
    {SysTick_Handler},           /* SysTick Handler */

    /* External interrupts */
    {WWDG_IRQHandler},          /* 0 */
    {Default_Handler},          /* 1 */
    {TAMPER_IRQHandler},        /* 2 */
    {RTC_IRQHandler},           /* 3 */
    {Default_Handler},          /* 4 */
    {RCC_IRQHandler},           /* 5 */
    {EXTI0_IRQHandler},         /* 6 */
    {EXTI1_IRQHandler},         /* 7 */
    {EXTI2_IRQHandler},         /* 8 */
    {EXTI3_IRQHandler},         /* 9 */
    {EXTI4_IRQHandler},         /* 10 */
    {DMA1_Channel1_IRQHandler}, /* 11 */
    {DMA1_Channel2_IRQHandler}, /* 12 */
    {DMA1_Channel3_IRQHandler}, /* 13 */
    {DMA1_Channel4_IRQHandler}, /* 14 */
    {DMA1_Channel5_IRQHandler}, /* 15 */
    {DMA1_Channel6_IRQHandler}, /* 16 */
    {DMA1_Channel7_IRQHandler}, /* 17 */
    {ADC1_IRQHandler},          /* 18 */
    {CAN1_IRQHandler},          /* 19 */
    {Default_Handler},          /* 20 */
    {Default_Handler},          /* 21 */
    {Default_Handler},          /* 22 */
    {EXTI9_5_IRQHandler},       /* 23 */
    {TIM1_BRK_IRQHandler},      /* 24 */
    {TIM1_UP_IRQHandler},       /* 25 */
    {TIM1_TRG_COM_IRQHandler},  /* 26 */
    {TIM1_CC_IRQHandler},       /* 27 */
    {TIM3_IRQHandler},          /* 28 */
    {TIM4_IRQHandler},          /* 29 */
    {TIM5_IRQHandler},          /* 30 */
    {TIM6_IRQHandler},          /* 31 */
    {TIM7_IRQHandler},          /* 32 */
    {I2C1_IRQHandler},          /* 33 */
    {I2C2_IRQHandler},          /* 34 */
    {SPI1_IRQHandler},          /* 35 */
    {SPI2_IRQHandler},          /* 36 */
    {UART1_IRQHandler},         /* 37 */
    {UART2_IRQHandler},         /* 38 */
    {UART3_IRQHandler},         /* 39 */
    {EXTI15_10_IRQHandler},     /* 40 */
    {RTCAlarm_IRQHandler},      /* 41 */
    {USBAwake_IRQHandler},      /* 42 */
    {TIM2_BRK_IRQHandler},      /* 43 */
    {TIM2_UP_IRQHandler},       /* 44 */
    {TIM2_TRG_COM_IRQHandler},  /* 45 */
    {TIM2_CC_IRQHandler},       /* 46 */
    {DMA1_Channel8_IRQHandler}, /* 47 */
    {TK80_IRQHandler},          /* 48 */
    {SDIO1_IRQHandler},         /* 49 */
    {SDIO2_IRQHandler},         /* 50 */
    {SPI3_IRQHandler},          /* 51 */
    {UART4_IRQHandler},         /* 52 */
    {UART5_IRQHandler},         /* 53 */
    {Default_Handler},          /* 54 */
    {TIM8_IRQHandler},          /* 55 */
    {DMA2_Channel1_IRQHandler}, /* 56 */
    {DMA2_Channel2_IRQHandler}, /* 57 */
    {DMA2_Channel3_IRQHandler}, /* 58 */
    {DMA2_Channel4_IRQHandler}, /* 59 */
    {DMA2_Channel5_IRQHandler}, /* 60 */
    {TIM9_IRQHandler},          /* 61 */
    {TIM10_IRQHandler},         /* 61 */
    {CAN2_IRQHandler},          /* 61 */
    {Default_Handler},          /* 62 */
    {Default_Handler},          /* 63 */
    {Default_Handler},          /* 64 */
    {USB_IRQHandler},           /* 65 */
    {DMA2_Channel6_IRQHandler}, /* 66 */
    {DMA2_Channel7_IRQHandler}, /* 67 */
    {DMA2_Channel8_IRQHandler}, /* 67 */
    {Default_Handler},          /* 67 */
    {I2C3_IRQHandler},          /* 67 */
    {I2C4_IRQHandler},          /* 67 */
    {Default_Handler},          /* 67 */
    {Default_Handler},          /* 67 */
    {Default_Handler},          /* 67 */
    {Default_Handler},          /* 67 */
    {Default_Handler},          /* 67 */
    {Default_Handler},          /* 67 */
    {Default_Handler},          /* 67 */
    {FPU_IRQHandler},           /* 67 */
    {Default_Handler},          /* 67 */
    {Default_Handler},          /* 67 */
    {SPI4_IRQHandler},          /* 67 */
    {Default_Handler},          /* 67 */
    {TOUCHPAD_IRQHandler},      /* 67 */
    {QSPI_IRQHandler},          /* 67 */
    {LTDC_IRQHandler},          /* 67 */
    {Default_Handler},          /* 67 */
    {I2S1_IRQHandler},          /* 67 */
};

/*----------------------------------------------------------------------------
 * Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
void Reset_Handler(void)
{
    *((volatile uint32_t *)0xE000ED88) |= 0xF << 20; // Enable floating point operations CP10,CP11
    main();
}

void Default_Handler(void)
{
    while (1)
    {
    }
}
