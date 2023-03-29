#include "stm32f10x.h"
 
#undef GPIO_Pin_13
#define GPIO_Pin_13 0x2000

static void delay(uint16_t n )//no asm not work
{
	uint16_t i,j;
	for(i=0;i<n;i++)
		for(j=0;j<8500;j++){
			__ASM("nop"); 
		}
}
    


int main(void) {
	*(unsigned int *)0x40021018 |=(1<<4);
	*(unsigned int *)0x40011004 &=~(1111<<(4*5));
	*(unsigned int *)0x40011004 |=(1<<(4*5));
	
	while(1){
		*(unsigned int*)0x4001100C &=~(1<<13);//输出低电平，点亮
		delay(92);
		*(unsigned int*)0x4001100C |=(1<<13);//输出高电平，熄灭
		delay(998);
	}
	
	
	
}
