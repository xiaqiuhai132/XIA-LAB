#include <REGX52.H>
void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
  while(xms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		--xms;
	}
}

void main()
{
	unsigned char a;
	a=0xFF;
	P2=a;
	while(1)
	{
	if(P3_1==0&&a==0xFF)
	{
	Delay(20);
	P2=0xFE;
	a=P2;
	while(P3_1==0);
	Delay(20);
	while(P3_1==1);
	}
	else if(P3_1==0&&a!=0xFF)
	{
		Delay(20);
		a=~a;
		a=a<<1;
		a=~a;
		P2=a;
		while(P3_1==0);
		Delay(20);
		while(P3_1==1);
	} 
	}
} 