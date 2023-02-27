/**********************ZYWIFI0939C-WIFI机器人实验板例程************************
*  平台：ZYWIFI0939C-WIFI机器人 + Keil U4 + STC89C52
*  名称：ZY-1智能小车参考程序
*  公司：湖南智宇科教设备有限公司                        
/蓝牙模块出厂默认参数：
从机，波特率：9600，N，8，1。配对密码：1234
*  平台：ZYWIFI0939C-WIFI机器人 + Keil U4 + STC89C52
*  名称：ZY-1智能小车参考程序
*  公司：湖南智宇科教设备有限公司
*  淘宝：https://hnzyrobot1688.taobao.com/     
*  网站：www.hnzhiyu.cn	
*  编写：智宇公司研发一部
*  日期：2015-1-15
*  交流:智能车QQ:261339276
*  晶振:11.0592MHZ
*  说明：免费开源，不提供源代码分析
*  硬件设置：要有自己动手能力，才能完成实验
*  使用说明：根据下面IO口自己用杜邦线连接各种模块，可以自己修改各种模块IO口
*  视频教程：本小车配套学习C语言详细视频教程，资料统一网盘下载
   重点提示：本程序只做参考，不提供技术支持，请自己研究吸收。
    
	//注意程序只做参考之用，要达到最理想的效果，还需要同学们细心调试。	
	//注意蓝牙模块接线，急性之人经常接错线，烧坏模块，请一定要核对好再通电试验，模块接错线烧坏不保修，不换货的。
	/****************************************************************************
	 硬件连接
	 蓝牙有4条线定义：
	  VCC
      GND
	  TDX
	  RXD
	 把蓝牙插入单片机J7接口中	 --注意不要接错线，否则烧坏蓝牙模块，不保修，不换货。
	****************************************************************************/

    #include<AT89x51.H>

    #define Left_moto_go      {P1_2=1,P1_3=0;}  //左电机向前走
	#define Left_moto_back    {P1_2=0,P1_3=1;} 	//左边电机向后转
	#define Left_moto_Stop    {P1_2=0,P1_3=0;}         //左边电机停转                     
	#define Right_moto_go     {P1_4=1,P1_5=0;}	//右边电机向前走
	#define Right_moto_back   {P1_4=0,P1_5=1;}	//右边电机向后走
	#define Right_moto_Stop   {P1_4=0,P1_5=0;}      	//右边电机停转   

	#define left     'C'
    #define right    'D'
	#define up       'A'
    #define down     'B'
	#define stop     'F'

	#define uint    unsigned int                          //重定义无符号整数类型
    #define uchar   unsigned char                         //重定义无符号字符类型

	char code str[] =  "收到指令，向前!\n";
	char code str1[] = "收到指令，向后!\n";
	char code str2[] = "收到指令，向左!\n";
	char code str3[] = "收到指令，向右!\n";
	char code str4[] = "收到指令，停止!\n";

	bit  flag_REC=0; 
	bit  flag    =0;  
	

	unsigned char  i=0;
	unsigned char  dat=0;
    unsigned char  buff[5]=0; //接收缓冲字节
	uchar code  LedShowData[]={0x03,0x9F,0x25,0x0D,0x99,  //定义数码管显示数据
                            0x49,0x41,0x1F,0x01,0x19};//0,1,2,3,4,5,6,7,8,9

	#define ShowPort P0                                   //定义数码管显示端口
   
/************************************************************************/	
//延时函数	
   void delay(unsigned int k)
{    
     unsigned int x,y;
	 for(x=0;x<k;x++) 
	   for(y=0;y<2000;y++);
}

/************************************************************************/
//字符串发送函数
	  void send_str( )
                   // 传送字串
    {
	    unsigned char i = 0;
	    while(str[i] != '\0')
	   {
		SBUF = str[i];
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
		i++;					// 下一个字符
	   }	
    }
	
		  void send_str1( )
                   // 传送字串
    {
	    unsigned char i = 0;
	    while(str1[i] != '\0')
	   {
		SBUF = str1[i];
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
		i++;					// 下一个字符
	   }	
    }	

			  void send_str2( )
                   // 传送字串
    {
	    unsigned char i = 0;
	    while(str2[i] != '\0')
	   {
		SBUF = str2[i];
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
		i++;					// 下一个字符
	   }	
    }	
	    	
			  void send_str3()
                   // 传送字串
    {
	    unsigned char i = 0;
	    while(str3[i] != '\0')
	   {
		SBUF = str3[i];
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
		i++;					// 下一个字符
	   }	
    }	

	      void send_str4()
                   // 传送字串
    {
	    unsigned char i = 0;
	    while(str4[i] != '\0')
	   {
		SBUF = str4[i];
		while(!TI);				// 等特数据传送
		TI = 0;					// 清除数据传送标志
		i++;					// 下一个字符
	   }	
    }	
	    	
	    	
/************************************************************************/
//前速前进
     void  run(void)
{
    
	 Left_moto_go ;   //左电机往前走
	 Right_moto_go ;  //右电机往前走
}

//前速后退
     void  backrun(void)
{
    
	 Left_moto_back ;   //左电机往后走
	 Right_moto_back ;  //右电机往后走
}

//右转
     void  rightrun(void) 
{
    

	  Left_moto_go ;   //左电机往前走
	 Right_moto_back ;  //右电机往后走
}

 //左转
     void   leftrun(void)
{
    
	 
	 Left_moto_back ;   //左电机往前走
	 Right_moto_go ;  //右电机往前走
}
//STOP
     void  stoprun(void)
{
    
	 Left_moto_Stop ;   //左电机往前走
	 Right_moto_Stop ;  //右电机往前走
}
/************************************************************************/
void sint() interrupt 4	  //中断接收3个字节
{ 
 
    if(RI)	                 //是否接收中断
    {
       RI=0;
       dat=SBUF;
       if(dat=='O'&&(i==0)) //接收数据第一帧
         {
            buff[i]=dat;
            flag=1;        //开始接收数据
         }
       else
      if(flag==1)
     {
      i++;
      buff[i]=dat;
      if(i>=2)
      {i=0;flag=0;flag_REC=1 ;}  // 停止接收
     }
	 }
}
/*********************************************************************/		 
/*--主函数--*/
	void main(void)
{
	TMOD=0x20;  
    TH1=0xFd;  		   //11.0592M晶振，9600波特率
    TL1=0xFd;
    SCON=0x50;  
    PCON=0x00; 
    TR1=1;
	ES=1;   
    EA=1;   
  	 ShowPort=LedShowData[0];
	while(1)							/*无限循环*/
	{ 
	  if(flag_REC==1)				    //
	   {
		flag_REC=0;
		if(buff[0]=='O'&&buff[1]=='N')	//第一个字节为O，第二个字节为N，第三个字节为控制码
		switch(buff[2])
	     {
		      case up :						    // 前进
			  send_str( );
			  run();
			  ShowPort=LedShowData[1]; 
			  break;
		      case down:						// 后退
			   send_str1( );
			  backrun();
			  ShowPort=LedShowData[2]; 
			  break;
		      case left:						// 左转
			   send_str3( );
			  leftrun();
			  ShowPort=LedShowData[3];  
			  break;
		      case right:						// 右转
			  send_str2( );
			  rightrun();
			  ShowPort=LedShowData[4];
			  break;
		      case stop:						// 停止
			   send_str4( );
			  stoprun();
			  ShowPort=LedShowData[0];
			  break;

	     }
      
					 
	 }
	}
}	