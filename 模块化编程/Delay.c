#include <intrins.h>
void Delay(unsigned short xms)		//@11.0592MHz
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
