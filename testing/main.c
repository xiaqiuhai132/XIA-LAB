#include <REGX52.H>
#include <INTRINS.H>
void Delay500ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 205;
	k = 187;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()
{
	int i;
	while(1)
	{
		P2=0x7F;
		Delay500ms();
		for(i=0;i<7;i++)
		{
			P2=~P2>>1;
			P2=~P2;
		Delay500ms();
		}
	}
}