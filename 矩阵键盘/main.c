#include <REGX52.H>
#include <Delay.h>
#include <LCD1602.h>	
unsigned char Keynumber=0;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"MatrixNumber");
	LCD_ShowNum(2,1,Keynumber,2);
	while(1)
	{
	
		P1=0xFF;
		P1_3=0;
		if(P1_7==0)
		{
				Delay(20);
				Keynumber=1;
				while(P1_7==0);
				Delay(20);
		}
			else if (P1_6==0)
			{
				Delay(20);
				Keynumber=5;
				while(P1_6==0);
				Delay(20);
			
			}
			else if (P1_5==0)
			{
				Delay(20);
				Keynumber=9;
				while(P1_5==0);
				Delay(20);
		
			}
			else if (P1_4==0)
			{
				Delay(20);				
				Keynumber=13;
				while(P1_4==0);
				Delay(20);

			}
			P1=0xFF;
			P1_2=0;
			if(P1_7==0)
			{
				Delay(20);
				Keynumber=2;
				while(P1_7==0);
				Delay(20);
				
			}
			else if (P1_6==0)
			{
				Delay(20);
				Keynumber=6;
				while(P1_6==0);
				Delay(20);
			
			}
			else if (P1_5==0)
			{
				Delay(20);
				Keynumber=10;
				while(P1_5==0);
				Delay(20);
				
			}
			else if (P1_4==0)
			{
				Delay(20);
				Keynumber=14;
				while(P1_4==0);
				Delay(20);
				
			}
			P1=0xFF;
			P1_1=0;
			if(P1_7==0)
			{
				Delay(20);
				Keynumber=3;
				while(P1_7==0);
				Delay(20);
				
			}
			else if (P1_6==0)
			{
				Delay(20);
				Keynumber=7;
				while(P1_6==0);
				Delay(20);
			
			}
			else if (P1_5==0)
			{
				Delay(20);
				Keynumber=11;
				while(P1_5==0);
				Delay(20);
				
			}
			else if (P1_4==0)
			{
				Delay(20);
				Keynumber=15;
				while(P1_4==0);
				Delay(20);
				
			}
			P1=0xFF;
			P1_0=0;
			if(P1_7==0)
			{
				Delay(20);
				Keynumber=4;
				while(P1_7==0);
				Delay(20);
				
			}
			else if (P1_6==0)
			{
				Delay(20);
				Keynumber=8;
				while(P1_6==0);
				Delay(20);
				
			}
			else if (P1_5==0)
			{
				Delay(20);
				Keynumber=12;
				while(P1_5==0);
				Delay(20);
				
			}
			else if (P1_4==0)
			{
				Delay(20);
				Keynumber=16;
				while(P1_4==0);
				Delay(20);
				
			}
			if(Keynumber)
			{
			LCD_ShowNum(2,1,Keynumber,2);
			}
	 }
 }