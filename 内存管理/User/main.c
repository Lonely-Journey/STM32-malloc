#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "malloc.h"

int main(void)
{
    uint8_t *p;

    SysTick_Init();       /* ��ʱ��ʼ�� */
    USART1_Init(115200);  /* ����1��ʼ�� 115200 */
    LED_Init();           /* LED��ʼ�� */
    my_mem_init(0);       /* ʹ���ڲ�SRAM��Ϊ�ڴ��������ʼ�� */

    printf("�ڴ�������:%d%%\r\n",my_mem_perused(0));

    p = mymalloc(0,3000); /* ��SRAM���ڴ����������3000�ֽڿռ� */
    sprintf((char*)p,"123���ѽ���úúð�");
    printf("\r\n�״�����ռ�\r\n");
    printf("%s\r\n",p);
    printf("p�ռ���׵�ַ%d\r\n",(uint32_t)p);
    printf("�ڴ�������:%d%%\r\n",my_mem_perused(0));

    p = myrealloc(0, p, 4000);
    printf("\r\n��������ռ�\r\n");
    printf("%s\r\n",p);
    printf("p�ռ���׵�ַ%d\r\n",(uint32_t)p);
    printf("�ڴ�������:%d%%\r\n",my_mem_perused(0));

    myfree(0, p);         /* �ͷ�p����Ŀռ� */
    printf("\r\n�ͷſռ�\r\n");
    printf("�ڴ�������:%d%%\r\n",my_mem_perused(0));

    /* �����ռ��Ƿ��������� */
    p = mymalloc(0,3000); /* ��SRAM���ڴ����������3000�ֽڿռ� */
    printf("\r\n�ٴ�����ռ�\r\n");
    printf("p[0] = %d\r\n",(uint8_t)p[0]);
    printf("p�ռ���׵�ַ%d\r\n",(uint32_t)p);
    printf("�ڴ�������:%d%%\r\n",my_mem_perused(0));

    while(1)
    {
        LED0_ON;
        LED1_ON;
        delay_ms(300);
        LED0_OFF;
        LED1_OFF;
        delay_ms(300);
    }
}


