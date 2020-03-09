#include "LBTY_int.h"
#include "DIO_int.h"
#include "ADC_int.h"
#include "GIE_int.h"
#include "USART_init.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delnms(u16 n)
{
	//delay n ms
	u16 x;

	while(n--)
	{
		x=2600;       //empirically determined fudge factor 16mhz
		while(x--);
	}
}

int main(void)
{
	DIO_void_Intialization();
	GIE_void_enable();
	USART_Init();
	ADC_voidInit();
	ADC_voidEnable();

	u8 *s ;
	u16 i=0,Human_Resistance;


	while(1)
	{

		i=ADC_u16ReadADC();

		Human_Resistance = (((2*i)+1024)*10)/(512-i);

		USART_TransmitString(itoa(i,s,10));
		USART_TransmitString("==> ");

		USART_TransmitString(itoa(Human_Resistance,s,10));
		USART_TransmitString(" Kohm\n");

		delnms(50);

	}





	return 0;
}
