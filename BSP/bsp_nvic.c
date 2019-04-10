#include <bsp_nvic.h>

void BSP_NVIC_Init()
{
    
    NVIC_InitTypeDef  NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    
    //USART1 DBUS DMA接收  
    NVIC_InitStructure.NVIC_IRQChannel                    = DMA2_Stream2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority  = 3;
    NVIC_InitStructure.NVIC_IRQChannelCmd                 = ENABLE;			
    NVIC_Init(&NVIC_InitStructure);	
    DMA_ITConfig(DMA2_Stream2,DMA_IT_TC,ENABLE);
    
    //UASRT6 JUDGE USART接收
    NVIC_InitStructure.NVIC_IRQChannel                    = USART6_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority  = 6;
	NVIC_InitStructure.NVIC_IRQChannelCmd                 = ENABLE;			
	NVIC_Init(&NVIC_InitStructure);	
    USART_ITConfig(USART6, USART_IT_IDLE, ENABLE);
    
    //USART6 JUDGE DMA发送
    NVIC_InitStructure.NVIC_IRQChannel                     = DMA2_Stream7_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd                  = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority   = 5;
    NVIC_Init(&NVIC_InitStructure);
    DMA_ClearITPendingBit(DMA2_Stream7, DMA_IT_TCIF7);
    DMA_ITConfig(DMA2_Stream7,DMA_IT_TC,ENABLE);
	
	
	 //UART8 MiniPC USART接收
    NVIC_InitStructure.NVIC_IRQChannel                    = UART8_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority  = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd                 = ENABLE;			
	NVIC_Init(&NVIC_InitStructure);	
    USART_ITConfig(UART8, USART_IT_IDLE, ENABLE);
    
    //UART8 MiniPC DMA发送
    NVIC_InitStructure.NVIC_IRQChannel                     = DMA1_Stream0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd                  = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority   = 8;
    NVIC_Init(&NVIC_InitStructure);
    DMA_ClearITPendingBit(DMA1_Stream0, DMA_IT_TCIF7);
    DMA_ITConfig(DMA1_Stream0,DMA_IT_TC,ENABLE);
    
    //CAN1 接收
    NVIC_InitStructure.NVIC_IRQChannel                      = CAN1_RX0_IRQn;    //FIFO 0
    NVIC_InitStructure.NVIC_IRQChannelCmd                   = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority    = 2;
    NVIC_Init(&NVIC_InitStructure);
    CAN_ITConfig(CAN1,CAN_IT_FMP0,ENABLE);      //当FIFO 0中有数据时触发中断
    
    //CAN2 接收
    NVIC_InitStructure.NVIC_IRQChannel                      = CAN2_RX1_IRQn;    //FIFO 1
    NVIC_InitStructure.NVIC_IRQChannelCmd                   = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority    = 7;
    NVIC_Init(&NVIC_InitStructure);
    CAN_ITConfig(CAN2,CAN_IT_FMP1,ENABLE);      //当FIFO中有数据时触发中断
    
//    //TIM6更新中断
//    NVIC_InitStructure.NVIC_IRQChannel                      = TIM6_DAC_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelCmd                   = ENABLE;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority    = 6;
//    NVIC_Init(&NVIC_InitStructure);
//    TIM_ClearFlag(TIM6,TIM_FLAG_Update);
//    TIM_ITConfig(TIM6,TIM_IT_Update,ENABLE);
	
	//MPU6500 INT 中断
	EXTI_InitStructure.EXTI_Line=EXTI_Line8;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel                      = EXTI9_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd                   = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority    = 4;
    NVIC_Init(&NVIC_InitStructure);
	
}
