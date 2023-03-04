#include <MatrixKey.h>
#include <LCD1602.h>
#include <REGX52.H>
#include <Delay.h>
unsigned int KeyN,KeyD;
unsigned int x1,x2,y1,y2,x,y,count,a,b;
void main()
{
	x1=526;
	x2=307;
	y1=0;
	y2=0;
	count=6;
	x=x1*1000+x2;// Key Setting
	P1=0xFF;
	LCD_Init();
	LCD_ShowString(1,1,"KeyNumber");
	LCD_ShowNum(2,1,0,6);
	while(1)
	{
   while(KeyN!=11)
				{
					KeyN=MatrixKey();
					if(KeyN==12)
					{
						Delay(20);
						LCD_ShowNum(2,1,0,6);
						count=6;                              //count number reset
						y1=0;
						y2=0;
					}
					else if(KeyN&&count>3)
					{
						Delay(20);
						b=1;
						a=count-4;                          //initial a=2
						if(KeyN==10)
							{
								KeyN=0;                    //Number 0  
							}
						while(a>0)
						{
							b=b*10;
							a--;
						}                             //b=100,b=10
						y1=y1+KeyN*b;
						LCD_ShowNum(2,1,0,6);
						LCD_ShowNum(2,1,y1,3);
						count--;
					}
					else if(KeyN&&count>0)
					{
						Delay(20);
						b=1;
						a=count-1;                          //initial a=2
						if(KeyN==10)
							{
								KeyN=0;               //Number 0
							}
						while(a>0)
						{
							b=b*10;
							a--;
						}                           //b=100,b=10
						y2=y2+KeyN*b;
						LCD_ShowNum(2,4,y2,3);
						count--;
					}
							y=y1*1000+y2;
							
				}
		if(x1==y1&&x2==y2)
		{
			LCD_ShowString(2,1,"UnLockSuccess");
      KeyD=MatrixKey();			
			if(KeyD&&KeyD!=11)
			{
				LCD_ShowString(2,1,"              ");
				LCD_ShowNum(2,1,0,6);
				count=6;
				y1=0;
				y2=0;
				KeyN=MatrixKey();
			}
		}
		else
		{
			LCD_ShowString(2,1,"Fulse ");
			KeyD=MatrixKey();			
			if(KeyD&&KeyD!=11)
			{
				LCD_ShowString(2,1,"              ");
				LCD_ShowNum(2,1,0,6);
				count=6;
				y1=0;
				y2=0;
				KeyN=MatrixKey();
				Delay(20);
			}
		}	
	}
}