#include "timer.h"
#include "touch_CTP.h"
#include "stdio.h"
#include "lvgl.h"

void TIM3_Config(u16 arr, u16 psc)
{
   TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
   NVIC_InitTypeDef NVIC_InitStruct;                           //中断参数结构体
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);        // TIM8时钟使能
   TIM_TimeBaseStructure.TIM_Period = arr;                     //重装载值
   TIM_TimeBaseStructure.TIM_Prescaler = psc;                  //预分频值
   TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;     //不懂，不用管
   TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //向上计数
   TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);             //初始化
                                                               //中断优先级NVIC设置
   TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);                  //使能TIM8中断，允许更新中断
   NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn;                // TIM6中断
   NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;      //占先优先级0
   NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;             //次优先级0
   NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;                // IRQ通道被使能
   NVIC_Init(&NVIC_InitStruct);                                //初始化NVIC寄存器

   TIM_Cmd(TIM3, ENABLE); //使能TIM8
}

void TIM3_IRQHandler(void)
{

   if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //检查TIM3更新中断发生与否
   {
      lv_tick_inc(1);
      if ((GPIOB->IDR & GPIO_Pin_3) == 0)
      {
         GUI_TOUCH_Measure();
      }
   }
   TIM_ClearITPendingBit(TIM3, TIM_IT_Update); //清除TIMx更新中断标志
}
