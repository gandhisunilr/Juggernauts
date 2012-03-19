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
#include "string.h"
#include "printf.h"
#define SET_LINE_CODING             0x20

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
int main(void)
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
		

		//USB_To_USART_Send_Data(data_buffer, 80);
		//	USB_OTG_BSP_uDelay(1000);
		//USB_To_USART_Send_Data(data_buffer1, 80);
		//	USB_OTG_BSP_uDelay(1000);
//	      	USB_SIL_Write(EP1_IN, data_buffer, Nb_bytes);
//		SetEPTxValid(ENDP1);

//		USB_SIL_Write(EP1_IN, data_buffer1, 14);
    //		SetEPTxValid(ENDP1);
  	
	
  

  while (1)
  {
	printf("This is my : %s", data_buffer);
  }
}

/*******************************************************************************

* Function Name  : virtual_com_port_init
* Description    : Initialize virtual com port
* Input          : None                  
* Output         : None
* Return         : None
*******************************************************************************/
void virtual_com_port_init()
{
  char data_buffer1[80]="*****************************************\r\n\r\n";
  Set_System();
  Set_USBClock();
  USB_Interrupts_Config();
  USB_Init();


Virtual_Com_Port_Data_Setup(SET_LINE_CODING);

/*
Initialize the USART to default values
*/
  //USART_Config_Default();

	Virtual_Com_Port_init();

/*
Configure the USART with the parameters received by the SET_LINE_CODING
request
*/
	Virtual_Com_Port_Status_In();

  	USART_Config();
/*

Send the data received by the USART to the PC through USB
*/

	//USART_To_USB_Send_Data();

	//printf("This is my : %s", data_buffer);
	printf("This is my : %s", data_buffer1);


/*
Send the data received by the USB through USART
*/


	
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
