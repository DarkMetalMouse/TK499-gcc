#ifndef __SYS_H
#define __SYS_H
#include "tk499.h"
#include "HAL_conf.h"

// Bit band operation to achieve 51 similar GPIO control functions
// For specific implementation ideas, refer to Chapter 5 (page 87~92) of "CM3 Authoritative Guide". M4 is similar to M3, but the register address has changed.
// IO port operation macro definition
#define BITBAND(addr, bitnum) ((addr & 0xF0000000) + 0x2000000 + ((addr & 0xFFFFF) << 5) + (bitnum << 2))
#define MEM_ADDR(addr) *((volatile unsigned long *)(addr))
#define BIT_ADDR(addr, bitnum) MEM_ADDR(BITBAND(addr, bitnum))

void RemapVtorTable(void);
void AI_Responder_enable(void);
void AI_Responder_disable(void);

void Sys_Soft_Reset(void); // Soft system reset
void Sys_Standby(void);    // Enter standby mode

void TK499_NVIC_Init(u8 NVIC_PreemptionPriority, u8 NVIC_SubPriority, u8 NVIC_Channel, u8 NVIC_Group);
void Ex_NVIC_Config(u8 GPIOx, u8 BITx, u8 TRIM); // External interrupt configuration function for for GPIOA~E

// Assembly functions
void WFI_SET(void);      // Execute the wfi command
void INTX_DISABLE(void); // Disable all interrupts
void INTX_ENABLE(void);  // Enable all interrupts

void TIM3_Config(u16 arr, u16 psc);
#endif
