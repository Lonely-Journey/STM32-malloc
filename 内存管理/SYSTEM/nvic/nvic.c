#include "sys.h"  
#include "stdio.h"
#include "nvic.h"
#include "delay.h"

/******************************************�����ж�******************************************/
/******************************************************************
*��������  ������1���жϷ�����
*������    ��USART1_IRQHandler
*��������  ��void
*��������ֵ��void
*����      ��
*******************************************************************/
void USART1_IRQHandler(void)
{
  static u8 i = 0;
  static u8 str[200];
  
  //�ж�����ʲô��ʽ�����ж�
	//��������ж�    SET=1   RESET=0
  if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE) == SET)
  {
    //ִ���ж�����
    str[i] = USART_ReceiveData(USART1); //��ȡһ���ֽڵ�����(USART1->DR)
    i++;
  }
	//�����ж�        SET=1   RESET=0
  if(USART_GetITStatus(USART1, USART_IT_IDLE) == SET)   
  {
		//�����־
    USART1->SR;
    USART1->DR;
    
    str[i] = '\0';
    printf("�㷢�͵������ǣ�%s\r\n",str);
    i = 0;
  }
}












