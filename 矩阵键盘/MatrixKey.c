#include <REGX52.H>
#include <Delay.h>
#include <LCD1602.h>
unsigned int MatrixKey()
{
	while(1)
	{
		unsigned char Keynumber=0;
		P1=0xFF;
		P1_3=0;
		if(P1_7==0)
		{
				Delay(20);
				while(P1_7==0);
				Delay(20);
				Keynumber=1;
			  return(Keynumber);
		}
			else if (P1_6==0)
			{
				Delay(20);
				while(P1_6==0);
				Delay(20);
				Keynumber=5;
				return(Keynumber);
			}
			else if (P1_5==0)
			{
				Delay(20);
				while(P1_5==0);
				Delay(20);
				Keynumber=9;
				return(Keynumber);
			}
			else if (P1_4==0)
			{
				Delay(20);
				while(P1_4==0);
				Delay(20);
				Keynumber=13;
				return(Keynumber);
			}
			P1=0xFF;
			P1_2=0;
			if(P1_7==0)
			{
				Delay(20);
				while(P1_7==0);
				Delay(20);
				Keynumber=2;
				return(Keynumber);
			}
			else if (P1_6==0)
			{
				Delay(20);
				while(P1_6==0);
				Delay(20);
				Keynumber=6;
				return(Keynumber);
			}
			else if (P1_5==0)
			{
				Delay(20);
				while(P1_5==0);
				Delay(20);
				Keynumber=10;
				return(Keynumber);
			}
			else if (P1_4==0)
			{
				Delay(20);
				while(P1_4==0);
				Delay(20);
				Keynumber=14;
				return(Keynumber);
			}
			P1=0xFF;
			P1_1=0;
			if(P1_7==0)
			{
				Delay(20);
				while(P1_7==0);
				Delay(20);
				Keynumber=3;
				return(Keynumber);
			}
			else if (P1_6==0)
			{
				Delay(20);
				while(P1_6==0);
				Delay(20);
				Keynumber=7;
				return(Keynumber);
			}
			else if (P1_5==0)
			{
				Delay(20);
				while(P1_5==0);
				Delay(20);
				Keynumber=11;
				return(Keynumber);
			}
			else if (P1_4==0)
			{
				Delay(20);
				while(P1_4==0);
				Delay(20);
				Keynumber=15;
				return(Keynumber);
			}
			P1=0xFF;
			P1_0=0;
			if(P1_7==0)
			{
				Delay(20);
				while(P1_7==0);
				Delay(20);
				Keynumber=4;
				return(Keynumber);
			}
			else if (P1_6==0)
			{
				Delay(20);
				while(P1_6==0);
				Delay(20);
				Keynumber=8;
				return(Keynumber);
			}
			else if (P1_5==0)
			{
				Delay(20);
				while(P1_5==0);
				Delay(20);
				Keynumber=12;
				return(Keynumber);
			}
			else if (P1_4==0)
			{
				Delay(20);
				while(P1_4==0);
				Delay(20);
				Keynumber=16;
				return(Keynumber);
			}
			return(Keynumber);
	 }
 }