#include <REGX52.H>
unsigned char Key=0;
unsigned char KeyDetect()
{
	P1=0xFF;
	P1_3=0;
	if(P1_3==0&&(P1_7==0||P1_6==0||P1_5==0||P1_4==0))
	{
		Key=1;
	}
	P1=0xFF;
	P1_2=0;
	if(P1_2==0&&(P1_7==0||P1_6==0||P1_5==0||P1_4==0))
	{
		Key=1;
	}
	P1=0xFF;
	P1_1=0;
	if(P1_3==0&&(P1_7==0||P1_6==0||P1_5==0||P1_4==0))
	{
		Key=1;
	}
	P1=0xFF;
	P1_0=0;
	if(P1_3==0&&(P1_7==0||P1_6==0||P1_5==0||P1_4==0))
	{
		Key=1;
	}
	return (Key);
}	