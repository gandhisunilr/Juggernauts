#define STM32F10X_CL

/******************** (C) COPYRIGHT 2011 STMicroelectronics *********************
* File Name          : main.c
* Author             : MCD Application Team
* Version            : V3.3.0
* Date               : 21-March-2011
* Description        : Virtual Com Port Demo main file
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#ifdef STM32L1XX_MD
 #include "stm32l1xx.h"
#else
 #include "stm32f10x.h"
#endif /* STM32L1XX_MD */
 
#include "usb_lib.h"
#include "usb_desc.h"
#include "hw_config.h"
#include "usb_pwr.h"
//#include "string.h"
#include "printf.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : main.
* Description    : Main routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int ibreak;	

void init()
{
  char data_buffer2[80]="\r\nSwapnilkumar Khorate \r\n\r\n";
  
  char data_buffer[80]="\r\nResetted Successfully.... \r\n\r\n";
  char data_buffer1[80]="*****************************************\r\n\r\n";

	ibreak=1;
	while(ibreak)  
	{
		//printf(" %s ", data_buffer1);
		//ibreak++;
		//USB_SIL_Read(EP3_OUT, data_buffer1);
		
		//if(strstr(data_buffer1, "start"))
		//	ibreak=0;
	}

	printf("On Demand Loading Of Code and Data of size constrained RAM in embedded system by Binary Re-writing: ");
	USB_OTG_BSP_uDelay(1000000);
  
		//printf("");
		

	
		printf("This is me : %s", data_buffer2);
}

extern int sum();
extern int sub();

int a;
int main(void)
{

	init();
	a = sum();
	a = sub();
	a = sum();

  	while (1)
  	{
		printf("\r\n\r\n Value Of a is :  %d",a);
  	}
}

#ifdef USE_FULL_ASSERT
/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert_param error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert_param error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {}
}
#endif

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
