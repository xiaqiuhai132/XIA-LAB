#include <REGX52.H>
#include <intrins.h>
void Delay(unsigned char xms)		//@11.0592MHz
{
	for(;xms>0;xms--)
	{
		unsigned char i, j;
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
  } 
}
void NixieTube(unsigned char x,unsigned char y)
{
	 char Number[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F};
   switch(x)
	{
		case 1:
			P2_2=1;
	    P2_3=1;
		  P2_4=1;break;
		case 2:
		  P2_2=0;
		  P2_3=1;
		  P2_4=1;break;
		case 3:
			P2_2=1;
		  P2_3=0;
		  P2_4=1;break;
		case 4:
			P2_2=0;
		  P2_3=0;
		  P2_4=1;break;
		case 5:
			P2_2=1;
		  P2_3=1;
		  P2_4=0;break;
		case 6:
			P2_2=0;
		  P2_3=1;
		  P2_4=0;break;
		case 7:
			P2_2=1;
		  P2_3=0;
		  P2_4=0;break;
		case 8:
			P2_2=0;
		  P2_3=0;
		  P2_4=0;break;
	}
	P0=Number[y];
	Delay(1000);
	P0=0x00;
}
void main()
{
	while(1)
	{
	NixieTube(1,1);
	NixieTube(2,2);
	NixieTube(3,3);
	NixieTube(4,4);
	NixieTube(5,5);
	NixieTube(6,6);
	NixieTube(7,7);
	NixieTube(8,8);
	}
}