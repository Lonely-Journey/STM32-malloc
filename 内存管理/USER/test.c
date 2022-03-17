#include "sys.h"	
#include "delay.h"	
#include "led.h"
#include "usart.h"
#include "stdio.h"
#include "malloc.h"

extern u32 IRnum;

int main(void)
{		
	u8 *p;
	
	SysTick_Init();	  	//��ʱ��ʼ��
	USART1_Init(115200);
  LED_Init();
	my_mem_init(0);
	
	p = mymalloc(0,3000);
	
	sprintf((char*)p,"���ѽ���úúð�");
	
	printf("%s\r\n",p);
	printf("�ڴ�������:%d%%\r\n",my_mem_perused(0));
	while(1)
	{
		
	}	 
}




