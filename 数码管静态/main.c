#include <REGX51.H>
void Delay(unsigned char a)		//@12.000MHz
{
	for(;a>0;a--)
	{
			unsigned char i, j;
			i = 2;
			j = 239;
			do
			{
				while (--j);
			} while (--i);
  }
}

void NixieTube(unsigned char x)
{
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
}
void NumberSelect(unsigned char y)
{
	unsigned char z[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F};
	P0=z[y];
	Delay(1);
	P0=0x00;
}
void main()
{
	unsigned char Position_1,Position_2,Position_3,Position_4,Position_5,Position_6,Position_7,Position_8,Number_0,Number_1,Number_2,Number_3,Number_4,Number_5,Number_6,Number_7,Number_8;
	Position_1=1;
	Position_2=2;
	Position_3=3;
	Position_4=4;
	Position_5=5;
	Position_6=6;
	Position_7=7;
	Position_8=8;
	Number_0=0;Number_1=1;Number_2=2;Number_3=3;Number_4=4;Number_5=5;Number_6=6;Number_7=7;Number_8=8;
	while(1)
	{
	  NixieTube(Position_1);
		NumberSelect(Number_5);
		Delay(1);
		NixieTube(Position_2);
		NumberSelect(Number_2);
		Delay(1);
		NixieTube(Position_3);
		NumberSelect(Number_0);
		Delay(1);
		NixieTube(Position_4);
		NumberSelect(Number_1);
		Delay(1);
		NixieTube(Position_5);
		NumberSelect(Number_3);
		Delay(1);
		NixieTube(Position_6);
		NumberSelect(Number_1);
		Delay(1);
		NixieTube(Position_7);
		NumberSelect(Number_4);
		Delay(1);
	}
}
