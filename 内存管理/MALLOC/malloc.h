#ifndef _MOLLOC_H
#define _MOLLOC_H

	#include "sys.h"
	
	#ifndef NULL
		#define NULL 0
	#endif

	//���������ڴ��
	#define SRAMIN	 0		//�ڲ��ڴ��
	#define SRAMEX   1		//�ⲿ�ڴ��(��ӢSTM32�����岻֧���ⲿ�ڴ�) 
  //�����ֶ��ٸ�SRAM�ɹ���
	#define SRAMBANK 	2	//����֧�ֵ�SRAM����. ��Ӣ��ʵ����ֻ֧��1���ڴ�����,���ڲ��ڴ�.	
	
	//mem1�ڴ�����趨.mem1��ȫ�����ڲ�SRAM����.(�����ڲ�SARM���ڴ�غ��ڴ��Ĳ���)
	#define MEM1_BLOCK_SIZE			32  	  						              //һ���ڴ���СΪ32�ֽ�
	#define MEM1_MAX_SIZE			40*1024  						                //�������ڴ� 40K  (��������ڴ����ϵͳ���ڲ�SRAM�ɿ��Ƶ��ڴ��С)
	#define MEM1_ALLOC_TABLE_SIZE	MEM1_MAX_SIZE/MEM1_BLOCK_SIZE 	//�ڴ���С(�ж��ٿ��ڴ��)

	//mem2�ڴ�����趨.mem2���ڴ�ش����ⲿSRAM����
	#define MEM2_BLOCK_SIZE			32  	  						              //һ���ڴ���СΪ32�ֽ�
	#define MEM2_MAX_SIZE			1 *32  							                //��Ϊ��Ӣ��û�������ڴ�,����������һ����Сֵ
	#define MEM2_ALLOC_TABLE_SIZE	MEM2_MAX_SIZE/MEM2_BLOCK_SIZE 	//�ڴ���С 
		
	//�ڴ����������ṹ��
	//ע�⣺�ڴ�������ڴ�غ��ڴ��б����
	//SRAMBANK��SARM������һ�����ڲ�SRAM���ⲿSRAM��CCM
	struct _m_mallco_dev
	{
		void (*init)(u8);					    //��ʼ��
		u8 (*perused)(u8);		  	    //�ڴ�ʹ����
		u8 	*membase[SRAMBANK];				//�ڴ�� ����SRAMBANK��������ڴ�
		u16 *memmap[SRAMBANK]; 				//�ڴ����״̬��
		u8  memrdy[SRAMBANK]; 				//�ڴ�����Ƿ����
	};
	
	void my_mem_init(u8 memx);
	u8 my_mem_perused(u8 memx);

	void *mymalloc(u8 memx,u32 size);
	void myfree(u8 memx,void *ptr);
	void *myrealloc(u8 memx,void *ptr,u32 size);
	
#endif











