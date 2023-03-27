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
	
	
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
 
	/* ??? */
	GPIO_InitTypeDef typeDef;
	typeDef.GPIO_Pin = GPIO_Pin_13;
	typeDef.GPIO_Mode=GPIO_Mode_Out_PP;
	typeDef.GPIO_Speed=GPIO_Speed_50MHz;
	
    GPIO_Init(GPIOC, &typeDef);
	//int xms=1000*1000;
	
	while(1){
		GPIO_ResetBits(GPIOC, GPIO_Pin_13);
		delay(2);
		GPIO_SetBits(GPIOC, GPIO_Pin_13);
		delay(998);
	}
	
	
	
}