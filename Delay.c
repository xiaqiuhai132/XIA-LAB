#include <REGX52.H>
#include <intrins.h>
void Delay(unsigned int xms)
{
	while(xms--)
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