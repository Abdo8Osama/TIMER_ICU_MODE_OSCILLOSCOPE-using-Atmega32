
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include<util/delay.h>
#include "TIMER0_int.h"
#include "TIMER1_int.h"
#include "TIMER1_register.h"
#include "LCD_int.h"

int main()
{
	u8 FLAG =0;
	u16 TON , TOFF;
	int Freq , DutyCycle ;
	TIMER1_INIT(FAST_PWM10,ICU_RISING_EDGE , FCPU256 , POLLING , 0 ,625 , 625 , 0 , NONINVERTING);
	ICF1_Flag_Clear();
	LCD_8voidInit();
	LCD_CLEAR_DISPLAY();
	while(1)
	{
		if(ICF1_Flag_Read()==1)
		{
			FLAG++;
			ICF1_Flag_Clear();
			if(FLAG==3)
			{
				TCNT1_REG_LOAD(0);
				ICU_SET_FALLING_EDGE();
			}
			if(FLAG==4)
			{
				TON =ICR1L_REG;
				TCNT1_REG_LOAD(0);
				ICU_SET_RISING_EDGE();
			}
			if(FLAG==5)
			{
				TOFF =ICR1L_REG;
				TCNT1_REG_LOAD(0);
				ICU_SET_RISING_EDGE();
			}

		}
		if(FLAG==6)
		{
			break;
		}
	}

	DutyCycle = (int)(((float)(TON))/((float)(TON+TOFF)));
	DutyCycle *= 100;
	Freq = 1000000 / ((int)(TON+TOFF));
	while(1)
	{
	LCD_voidGotoXY(0,0);
	LCD_voidWriteString((u8 *)"DC = ");
	LCD_WriteNum(DutyCycle);
	LCD_voidWriteString((u8 *)" %");

	LCD_voidGotoXY(1,1);
	LCD_voidWriteString((u8 *)"Freq = ");
	LCD_WriteNum(Freq);
	LCD_voidWriteString((u8 *)" Hz");
	}

	return 0;
}
