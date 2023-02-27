#include <REGX52.H>
#include <LCD1602.h>
void main()
{
	unsigned char a,b;
		a=111;
	  b=666;
	  LCD_Init();
	while(1)
	{
		LCD_ShowNum(2,1,a,3);
		LCD_ShowNum(2,4,b,3);
	}
}