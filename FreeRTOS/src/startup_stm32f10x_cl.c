/**
 ******************************************************************************
 * @file      startup_stm32f10x_cl.c
 * @author    MCD Application Team,
 * @version   V3.0.0
 * @date      01. April 2010
 * @brief     STM32F10x Medium Density Devices vector table for GNU toolchain.
 *            This module performs:
 *                - Set the initial SP
 *                - Set the initial PC == Reset_Handler,
 *                - Set the vector table entries with the exceptions ISR address,
 *                - Branches to main in the C library (which eventually
 *                  calls main()).
 *            After Reset the Cortex-M3 processor is in Thread mode,
 *            priority is Privileged, and the Stack is set to Main.
 *******************************************************************************
 * @copy
 *
 * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 *
 * <h2><center>&copy; COPYRIGHT 2009 STMicroelectronics</center></h2>
 */

/* Modified by Martin Thomas
   - to take VECT_TAB_RAM setting into account, also see the linker-script
   - to avoid warning "ISO C forbids initialization between function pointer and 'void *'".
   - added optional startup-delay to avoid unwanted operations while connecting with
     debugger/programmer
   - tested with the GNU arm-eabi toolchain as in CS G++ lite Q1/2009-161
   - minor modification in .data copy to avoid copy while "run from RAM"
     during debugging
 */

/* Includes ------------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
typedef void( *const intfunc )( void );

/* Private define ------------------------------------------------------------*/
#define WEAK __attribute__ ((weak))

/* Private macro -------------------------------------------------------------*/
extern unsigned long _etext;
/* start address for the initialization values of the .data section.
defined in linker script */
extern unsigned long _sidata;

/* start address for the .data section. defined in linker script */
extern unsigned long _sdata;

/* end address for the .data section. defined in linker script */
extern unsigned long _edata;

/* start address for the .bss section. defined in linker script */
extern unsigned long _sbss;

/* end address for the .bss section. defined in linker script */
extern unsigned long _ebss;

/* init value for the stack pointer. defined in linker script */
extern unsigned long _estack;

/* Emul Eeprom start address. defined in linker script */
extern unsigned long _seemul2;

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void Reset_Handler(void) __attribute__((__interrupt__));
void __Init_Data(void);
void Default_Handler(void);

/* External function prototypes ----------------------------------------------*/
extern int main(void);                /* Application's main function */
extern void virtual_com_port_init();
extern void __libc_init_array(void);  /* calls CTORS of static objects */


/*******************************************************************************
 *
 *            Forward declaration of the default fault handlers.
 *
 *******************************************************************************/
//mthomas void WEAK Reset_Handler(void);
void WEAK NMI_Handler(void);
void WEAK HardFault_Handler(void);
void WEAK MemManage_Handler(void);
void WEAK BusFault_Handler(void);
void WEAK UsageFault_Handler(void);
//mthomas void WEAK MemManage_Handler(void);
void WEAK SVC_Handler(void);
void WEAK DebugMon_Handler(void);
void WEAK PendSV_Handler(void);
void WEAK SysTick_Handler(void);

/* External Interrupts */
void WEAK WWDG_IRQHandler(void);
void WEAK PVD_IRQHandler(void);
void WEAK TAMPER_IRQHandler(void);
void WEAK RTC_IRQHandler(void);
void WEAK FLASH_IRQHandler(void);
void WEAK RCC_IRQHandler(void);
void WEAK EXTI0_IRQHandler(void);
void WEAK EXTI1_IRQHandler(void);
void WEAK EXTI2_IRQHandler(void);
void WEAK EXTI3_IRQHandler(void);
void WEAK EXTI4_IRQHandler(void);
void WEAK DMA1_Channel1_IRQHandler(void);
void WEAK DMA1_Channel2_IRQHandler(void);
void WEAK DMA1_Channel3_IRQHandler(void);
void WEAK DMA1_Channel4_IRQHandler(void);
void WEAK DMA1_Channel5_IRQHandler(void);
void WEAK DMA1_Channel6_IRQHandler(void);
void WEAK DMA1_Channel7_IRQHandler(void);
void WEAK ADC1_2_IRQHandler(void);
//void WEAK USB_HP_CAN1_TX_IRQHandler(void);
//void WEAK USB_LP_CAN1_RX0_IRQHandler(void);
void WEAK CAN1_TX_IRQHandler(void);
void WEAK CAN1_RX0_IRQHandler(void);
void WEAK CAN1_RX1_IRQHandler(void);
void WEAK CAN1_SCE_IRQHandler(void);
void WEAK EXTI9_5_IRQHandler(void);
void WEAK TIM1_BRK_IRQHandler(void);
void WEAK TIM1_UP_IRQHandler(void);
void WEAK TIM1_TRG_COM_IRQHandler(void);
void WEAK TIM1_CC_IRQHandler(void);
void WEAK TIM2_IRQHandler(void);
void WEAK TIM3_IRQHandler(void);
void WEAK TIM4_IRQHandler(void);
void WEAK I2C1_EV_IRQHandler(void);
void WEAK I2C1_ER_IRQHandler(void);
void WEAK I2C2_EV_IRQHandler(void);
void WEAK I2C2_ER_IRQHandler(void);
void WEAK SPI1_IRQHandler(void);
void WEAK SPI2_IRQHandler(void);
void WEAK USART1_IRQHandler(void);
void WEAK USART2_IRQHandler(void);
void WEAK USART3_IRQHandler(void);
void WEAK EXTI15_10_IRQHandler(void);
void WEAK RTCAlarm_IRQHandler(void);
//void WEAK USBWakeUp_IRQHandler(void);
void WEAK OTG_FS_WKUP_IRQHandler(void);
void WEAK TIM5_IRQHandler(void);
void WEAK SPI3_IRQHandler(void);
void WEAK UART4_IRQHandler(void);
void WEAK UART5_IRQHandler(void);
void WEAK TIM6_IRQHandler(void);
void WEAK TIM7_IRQHandler(void);
void WEAK DMA2_Channel1_IRQHandler(void);
void WEAK DMA2_Channel2_IRQHandler(void);
void WEAK DMA2_Channel3_IRQHandler(void);
void WEAK DMA2_Channel4_IRQHandler(void);
void WEAK DMA2_Channel5_IRQHandler(void);
void WEAK ETH_IRQHandler(void);
void WEAK ETH_WKUP_IRQHandler(void);
void WEAK CAN2_TX_IRQHandler(void);
void WEAK CAN2_RX0_IRQHandler(void);
void WEAK CAN2_RX1_IRQHandler(void);
void WEAK CAN2_SCE_IRQHandler(void);
void WEAK OTG_FS_IRQHandler(void);
void OTG_FS_IRQHandler(void);


/* Private functions ---------------------------------------------------------*/
/*****************************************************************************
 *
 * mthomas: If been built with VECT_TAB_RAM this creates two tables:
 * (1) a minimal table (stack-pointer, reset-vector) used during startup
 *     before relocation of the vector table using SCB_VTOR
 * (2) a full table which is copied to RAM and used after vector relocation
 *     (NVIC_SetVectorTable)
 * If been built without VECT_TAB_RAM the following comment from STM is valid:
 * The minimal vector table for a Cortex M3.  Note that the proper constructs
 * must be placed on this to ensure that it ends up at physical address
 * 0x0000.0000.
 *
 ******************************************************************************/

//#ifdef VECT_TAB_RAM
//__attribute__ ((section(".isr_vectorsflash")))
//void (* const g_pfnVectorsStartup[])(void) =
//{
//		(intfunc)((unsigned long)&_estack), /* The initial stack pointer during startup */
//		Reset_Handler,             /* The reset handler during startup */
//};
//__attribute__ ((section(".isr_vectorsram")))
//void (* g_pfnVectors[])(void) =
//#else /* VECT_TAB_RAM */
		__attribute__ ((section(".isr_vectorsflash")))
		void (* const g_pfnVectors[])(void) =
//#endif /* VECT_TAB_RAM */
//__attribute__ ((section(".isr_vectorsflash")))
//void (*const vector_table[]) (void) = 
				{
				(void*)&_estack,

				//(intfunc)((unsigned long)&_estack), /* The stack pointer after relocation */
				Reset_Handler,              /* Reset Handler */
				NMI_Handler,                /* NMI Handler */
				HardFault_Handler,          /* Hard Fault Handler */
				MemManage_Handler,          /* MPU Fault Handler */
				BusFault_Handler,           /* Bus Fault Handler */
				UsageFault_Handler,         /* Usage Fault Handler */
				0,                          /* Reserved */
				0,                          /* Reserved */
				0,                          /* Reserved */
				0,                          /* Reserved */
				SVC_Handler,                /* SVCall Handler */
				DebugMon_Handler,           /* Debug Monitor Handler */
				0,                          /* Reserved */
				PendSV_Handler,             /* PendSV Handler */
				SysTick_Handler,            /* SysTick Handler */

				/* External Interrupts */
				WWDG_IRQHandler,            /* Window Watchdog */
				PVD_IRQHandler,             /* PVD through EXTI Line detect */
				TAMPER_IRQHandler,          /* Tamper */
				RTC_IRQHandler,             /* RTC */
				FLASH_IRQHandler,           /* Flash */
				RCC_IRQHandler,             /* RCC */
				EXTI0_IRQHandler,           /* EXTI Line 0 */
				EXTI1_IRQHandler,           /* EXTI Line 1 */
				EXTI2_IRQHandler,           /* EXTI Line 2 */
				EXTI3_IRQHandler,           /* EXTI Line 3 */
				EXTI4_IRQHandler,           /* EXTI Line 4 */
				DMA1_Channel1_IRQHandler,   /* DMA1 Channel 1 */
				DMA1_Channel2_IRQHandler,   /* DMA1 Channel 2 */
				DMA1_Channel3_IRQHandler,   /* DMA1 Channel 3 */
				DMA1_Channel4_IRQHandler,   /* DMA1 Channel 4 */
				DMA1_Channel5_IRQHandler,   /* DMA1 Channel 5 */
				DMA1_Channel6_IRQHandler,   /* DMA1 Channel 6 */
				DMA1_Channel7_IRQHandler,   /* DMA1 Channel 7 */
				ADC1_2_IRQHandler,          /* ADC1 & ADC2 */
				CAN1_TX_IRQHandler,  		/* CAN1 TX */
				CAN1_RX0_IRQHandler, 		/* CAN1 RX0 */
				CAN1_RX1_IRQHandler,        /* CAN1 RX1 */
				CAN1_SCE_IRQHandler,        /* CAN1 SCE */
				EXTI9_5_IRQHandler,         /* EXTI Line 9..5 */
				TIM1_BRK_IRQHandler,        /* TIM1 Break */
				TIM1_UP_IRQHandler,         /* TIM1 Update */
				TIM1_TRG_COM_IRQHandler,    /* TIM1 Trigger and Commutation */
				TIM1_CC_IRQHandler,         /* TIM1 Capture Compare */
				TIM2_IRQHandler,            /* TIM2 */
				TIM3_IRQHandler,            /* TIM3 */
				TIM4_IRQHandler,            /* TIM4 */
				I2C1_EV_IRQHandler,         /* I2C1 Event */
				I2C1_ER_IRQHandler,         /* I2C1 Error */
				I2C2_EV_IRQHandler,         /* I2C2 Event */
				I2C2_ER_IRQHandler,         /* I2C2 Error */
				SPI1_IRQHandler,            /* SPI1 */
				SPI2_IRQHandler,            /* SPI2 */
				USART1_IRQHandler,          /* USART1 */
				USART2_IRQHandler,          /* USART2 */
				USART3_IRQHandler,          /* USART3 */
				EXTI15_10_IRQHandler,       /* EXTI Line 15..10 */
				RTCAlarm_IRQHandler,        /* RTC Alarm through EXTI Line */
				OTG_FS_WKUP_IRQHandler,       /* USB On-The-Go FS Wakeup through EXTI line interrupt */
				0,0,0,0,0,0,0,				// reserved
				TIM5_IRQHandler,			// TIM5 global interrupt 0x0000_0108
				SPI3_IRQHandler,			// SPI3 global interrupt 0x0000_010C
				UART4_IRQHandler,			// UART4 global interrupt 0x0000_0110
				UART5_IRQHandler,			// UART5 global interrupt 0x0000_0114
				TIM6_IRQHandler,			// TIM6 global interrupt 0x0000_0118
				TIM7_IRQHandler,			// TIM7 global interrupt 0x0000_011C
				DMA2_Channel1_IRQHandler, 	// DMA2 Channel1 global interrupt 0x0000_0120
				DMA2_Channel2_IRQHandler, 	// DMA2 Channel2 global interrupt 0x0000_0124
				DMA2_Channel3_IRQHandler, 	// DMA2 Channel3 global interrupt 0x0000_0128
				DMA2_Channel4_IRQHandler, 	// DMA2 Channel4 global interrupt 0x0000_012C
				DMA2_Channel5_IRQHandler, 	// DMA2 Channel5 global interrupt 0x0000_0130
				ETH_IRQHandler,				// Ethernet global interrupt 0x0000_0134
				ETH_WKUP_IRQHandler,		// Ethernet Wakeup through EXTI line interrupt0x0000_0138
				CAN2_TX_IRQHandler,			// CAN2 TX interrupts 0x0000_013C
				CAN2_RX0_IRQHandler,		// CAN2 RX0 interrupts 0x0000_0140
				CAN2_RX1_IRQHandler,		// CAN2 RX1 interrupt 0x0000_0144
				CAN2_SCE_IRQHandler,		// CAN2 SCE interrupt 0x0000_0148
				OTG_FS_IRQHandler,		// USB On The Go FS global interrupt 0x0000_014C
				0,0,0,0,0,0,0,0,0,0,		// reserved
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,0,0,0,0,
				0,0,0,0,0,0,
				(intfunc)0xF1E0F85F          /* @0x1E0. This is for boot in RAM mode for
                                   STM32F10x Connectivity Line devices. */
		};

/**
 * @brief  This is the code that gets called when the processor first
 *          starts execution following a reset event. Only the absolutely
 *          necessary set is performed, after which the application
 *          supplied main() routine is called.
 * @param  None
 * @retval : None
 */
int i;
void Reset_Handler(void) {
	//i=1;
	//while(i);

#ifdef STARTUP_DELAY
	volatile unsigned long i;
	for (i=0;i<500000;i++) { ; }
#endif

	/* Initialize data and bss */
	__Init_Data();

	/* Call CTORS of static objects */
				/// not needed for "pure C":
	//__libc_init_array();
	/* Call the application's entry point.*/
	SystemInit();
	//virtual_com_port_init();
	main();

	while(1) { ; }
}

/**
 * @brief  initializes data and bss sections
 * @param  None
 * @retval : None
 */

void __Init_Data(void) {
	unsigned long *pulSrc, *pulDest;

	/* Copy the data segment initializers from flash to SRAM */
	pulSrc  = &_sidata;
	pulDest = &_sdata;
	if ( pulSrc != pulDest ) {
		for(; pulDest < &_edata; ) {
			*(pulDest++) = *(pulSrc++);
		}
	}
	/* Zero fill the bss segment. */
	for(pulDest = &_sbss; pulDest < &_ebss; ) {
		*(pulDest++) = 0;
	}

	//EEEPROM_START = _seemul2;
}

/*******************************************************************************
 *
 * Provide weak aliases for each Exception handler to the Default_Handler.
 * As they are weak aliases, any function with the same name will override
 * this definition.
 *
 *******************************************************************************/
#pragma weak MMI_Handler = Default_Handler
#pragma weak MemManage_Handler = Default_Handler
#pragma weak BusFault_Handler = Default_Handler
#pragma weak UsageFault_Handler = Default_Handler
#pragma weak SVC_Handler = Default_Handler
#pragma weak DebugMon_Handler = Default_Handler
#pragma weak PendSV_Handler = Default_Handler
#pragma weak SysTick_Handler = Default_Handler
#pragma weak WWDG_IRQHandler = Default_Handler
#pragma weak PVD_IRQHandler = Default_Handler
#pragma weak TAMPER_IRQHandler = Default_Handler
#pragma weak RTC_IRQHandler = Default_Handler
#pragma weak FLASH_IRQHandler = Default_Handler
#pragma weak RCC_IRQHandler = Default_Handler
#pragma weak EXTI0_IRQHandler = Default_Handler
#pragma weak EXTI1_IRQHandler = Default_Handler
#pragma weak EXTI2_IRQHandler = Default_Handler
#pragma weak EXTI3_IRQHandler = Default_Handler
#pragma weak EXTI4_IRQHandler = Default_Handler
#pragma weak DMA1_Channel1_IRQHandler = Default_Handler
#pragma weak DMA1_Channel2_IRQHandler = Default_Handler
#pragma weak DMA1_Channel3_IRQHandler = Default_Handler
#pragma weak DMA1_Channel4_IRQHandler = Default_Handler
#pragma weak DMA1_Channel5_IRQHandler = Default_Handler
#pragma weak DMA1_Channel6_IRQHandler = Default_Handler
#pragma weak DMA1_Channel7_IRQHandler = Default_Handler
#pragma weak ADC1_2_IRQHandler = Default_Handler
#pragma weak CAN1_TX_IRQHandler = Default_Handler
#pragma weak CAN1_RX0_IRQHandler = Default_Handler
#pragma weak CAN1_RX1_IRQHandler = Default_Handler
#pragma weak CAN1_SCE_IRQHandler = Default_Handler
#pragma weak EXTI9_5_IRQHandler = Default_Handler
#pragma weak TIM1_BRK_IRQHandler = Default_Handler
#pragma weak TIM1_UP_IRQHandler = Default_Handler
#pragma weak TIM1_TRG_COM_IRQHandler = Default_Handler
#pragma weak TIM1_CC_IRQHandler = Default_Handler
#pragma weak TIM2_IRQHandler = Default_Handler
#pragma weak TIM3_IRQHandler = Default_Handler
#pragma weak TIM4_IRQHandler = Default_Handler
#pragma weak I2C1_EV_IRQHandler = Default_Handler
#pragma weak I2C1_ER_IRQHandler = Default_Handler
#pragma weak I2C2_EV_IRQHandler = Default_Handler
#pragma weak I2C2_ER_IRQHandler = Default_Handler
#pragma weak SPI1_IRQHandler = Default_Handler
#pragma weak SPI2_IRQHandler = Default_Handler
#pragma weak USART1_IRQHandler = Default_Handler
#pragma weak USART2_IRQHandler = Default_Handler
#pragma weak USART3_IRQHandler = Default_Handler
#pragma weak EXTI15_10_IRQHandler = Default_Handler
#pragma weak RTCAlarm_IRQHandler = Default_Handler
#pragma weak OTG_FS_WKUP_IRQHandler = Default_Handler
#pragma weak TIM5_IRQHandler = Default_Handler
#pragma weak SPI3_IRQHandler = Default_Handler
#pragma weak UART4_IRQHandler = Default_Handler
#pragma weak UART5_IRQHandler = Default_Handler
#pragma weak TIM6_IRQHandler = Default_Handler
#pragma weak TIM7_IRQHandler = Default_Handler
#pragma weak DMA2_Channel1_IRQHandler = Default_Handler
#pragma weak DMA2_Channel2_IRQHandler = Default_Handler
#pragma weak DMA2_Channel3_IRQHandler = Default_Handler
#pragma weak DMA2_Channel4_IRQHandler = Default_Handler
#pragma weak DMA2_Channel5_IRQHandler = Default_Handler
#pragma weak ETH_IRQHandler = Default_Handler
#pragma weak ETH_WKUP_IRQHandler = Default_Handler
#pragma weak CAN2_TX_IRQHandler = Default_Handler
#pragma weak CAN2_RX0_IRQHandler = Default_Handler
#pragma weak CAN2_RX1_IRQHandler = Default_Handler
#pragma weak CAN2_SCE_IRQHandler = Default_Handler
//#pragma weak OTG_FS_IRQHandler = Default_Handler



/**
 * @brief  This is the code that gets called when the processor receives an
 *         unexpected interrupt.  This simply enters an infinite loop, preserving
 *         the system state for examination by a debugger.
 *
 * @param  None
 * @retval : None
 */

void Default_Handler(void) {
	/* Go into an infinite loop. */
	while (1)  {
	  asm volatile ("nop");
  }
	asm volatile ("nop");
	asm volatile ("nop");
	asm volatile ("nop");
}

void NMI_Handler(void) {
	/* Go into an infinite loop. */
	while (1)  {
	  asm volatile ("nop");
  }

	asm volatile ("nop");
}
void HardFault_Handler(void){
	/* Go into an infinite loop. */
	while (1)  {
	  asm volatile ("nop");
  }

	asm volatile ("nop");
}


/******************* (C) COPYRIGHT 2009 STMicroelectronics *****END OF FILE****/
