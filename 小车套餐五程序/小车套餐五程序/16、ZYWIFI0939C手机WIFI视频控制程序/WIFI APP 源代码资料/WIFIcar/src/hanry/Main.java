package hanry;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.URL;
import android.app.Activity;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import bb.baibin.R;

public class Main extends Activity
{
   
    EditText edAlias,edIP,edPort,edUser,edPW;
    TextView t;
    private Button ForWard;
	private Button BackWard;
	private Button TurnLeft;
	private Button TurnRight;
	private Button button0;
	private Button button1;
	private Button button2;
	private Button button3;
	private Button button4;
	private Button button5;
	private Button button6;
	private Button button7;
	private Button button8;
	private Button button9;
    URL videoUrl;
    Bitmap bmp;
    private boolean isConnecting = false;
    private Thread mThreadClient = null;
	private Socket mSocketClient = null;
	static PrintWriter mPrintWriterClient = null;
	static BufferedReader mBufferedReaderClient	= null;
    public static String CameraIp;
    MySurfaceView r;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
      this.requestWindowFeature(Window.FEATURE_NO_TITLE);//隐去标题（应用的名字必须要写在setContentView之前，否则会有异常）
       this.getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
        WindowManager.LayoutParams.FLAG_FULLSCREEN);
        setContentView(R.layout.main);

        ForWard= (Button)findViewById(R.id.ForWard);
        TurnLeft= (Button)findViewById(R.id.TurnLeft);
        TurnRight= (Button)findViewById(R.id.TurnRight);
        BackWard= (Button)findViewById(R.id.BackWard);

        button0= (Button)findViewById(R.id.Button0);
        button0.setOnClickListener(button0ClickListener);
        button1= (Button)findViewById(R.id.Button1);
        button1.setOnClickListener(button1ClickListener);
        
      
        

        button4= (Button)findViewById(R.id.Button4);
        button4.setOnClickListener(button4ClickListener);
        button5= (Button)findViewById(R.id.Button5);
        button5.setOnClickListener(button5ClickListener);
        button6= (Button)findViewById(R.id.Button6);
        button6.setOnClickListener(button6ClickListener);

        button9= (Button)findViewById(R.id.Button9);
        button9.setOnClickListener(button9ClickListener);
        r=(MySurfaceView)findViewById(R.id.mySurfaceView1);

        CameraIp ="http://192.168.1.1:8080/?action=snapshot";

        	    r.GetCameraIP(CameraIp);
        	    mThreadClient = new Thread(mRunnable);
				mThreadClient.start();

				ForWard.setOnTouchListener(new View.OnTouchListener() 
		        {
					public boolean onTouch(View v, MotionEvent event) {
						int action = event.getAction();
						switch(action)
						{
						case MotionEvent.ACTION_DOWN:
						    	mPrintWriterClient.print("a");         
						    	mPrintWriterClient.flush();				    
						break;
						case MotionEvent.ACTION_UP:
						    	mPrintWriterClient.print("e");         
						    	mPrintWriterClient.flush();				    
						}
						return false;
					}
		        }
		        );
				BackWard.setOnTouchListener(new View.OnTouchListener() 
		        {
					public boolean onTouch(View v, MotionEvent event) {
						int action = event.getAction();
						switch(action)
						{
						case MotionEvent.ACTION_DOWN:
						    	mPrintWriterClient.print("b");           
						    	mPrintWriterClient.flush();				    
						break;
						case MotionEvent.ACTION_UP:
						    	mPrintWriterClient.print("e");         
						    	mPrintWriterClient.flush();				    
						}
						return false;
					}
		        	
		        }
		        );
				TurnRight.setOnTouchListener(new View.OnTouchListener() 
		        {
					public boolean onTouch(View v, MotionEvent event) {
						int action = event.getAction();
						switch(action)
						{
						case MotionEvent.ACTION_DOWN:
						    	mPrintWriterClient.print("d");       
						    	mPrintWriterClient.flush();				    
						break;
						case MotionEvent.ACTION_UP:
						    	mPrintWriterClient.print("e");     
						    	mPrintWriterClient.flush();				    
						}
						return false;
					}
		        }
		        );
				TurnLeft.setOnTouchListener(new View.OnTouchListener() 
		        {
					public boolean onTouch(View v, MotionEvent event) {
						int action = event.getAction();
						switch(action)
						{
						case MotionEvent.ACTION_DOWN:
						    	mPrintWriterClient.print("c");    
						    	mPrintWriterClient.flush();			
						break;
						case MotionEvent.ACTION_UP: 	
						    	mPrintWriterClient.print("e");   
						    	mPrintWriterClient.flush();		
						}
						return false;
					}
		        }
		        );
		}

	private OnClickListener button0ClickListener = new OnClickListener() {
		public void onClick(View arg0) {	    	
				    	mPrintWriterClient.print("j");
				    	mPrintWriterClient.flush();
			
		}
	};	
	private OnClickListener button1ClickListener = new OnClickListener() {
		public void onClick(View arg0) {   	
				    	mPrintWriterClient.print("m");
				    	mPrintWriterClient.flush();
		}
	};
	
	
	private OnClickListener button4ClickListener = new OnClickListener() {
		public void onClick(View arg0) {		    	
				    	mPrintWriterClient.print("i");
				    	mPrintWriterClient.flush();
		}
	};
	private OnClickListener button5ClickListener = new OnClickListener() {
		public void onClick(View arg0) {	    	
				    	mPrintWriterClient.print("l");
				    	mPrintWriterClient.flush();
		}
	};
	private OnClickListener button6ClickListener = new OnClickListener() {
		public void onClick(View arg0) {    	
				    	mPrintWriterClient.print("n");
				    	mPrintWriterClient.flush();
		}
	};
	
	private OnClickListener button9ClickListener = new OnClickListener() {
		public void onClick(View arg0) {    	
				    	mPrintWriterClient.print("k");
				    	mPrintWriterClient.flush();
		}
	};
	private Runnable	mRunnable	= new Runnable() 
	{
		public void run()
		{
			String msgText ="192.168.1.1:2001";

			int start = msgText.indexOf(":");

			String sIP = msgText.substring(0, start);
			String sPort = msgText.substring(start+1);
			int port = Integer.parseInt(sPort);				
			
			Log.d("gjz", "IP:"+ sIP + ":" + port);		

			try 
			{				
				//连接服务器
				mSocketClient = new Socket(sIP, port);	//portnum
				//取得输入、输出流
				mBufferedReaderClient = new BufferedReader(new InputStreamReader(mSocketClient.getInputStream()));
				
				mPrintWriterClient = new PrintWriter(mSocketClient.getOutputStream(), true);
				

				Message msg = new Message();
                msg.what = 1;
				mHandler.sendMessage(msg);		
				//break;
			}
			catch (Exception e) 
			{
				Message msg = new Message();
                msg.what = 1;
				mHandler.sendMessage(msg);
				return;
			}			

			char[] buffer = new char[256];
			while (isConnecting)
			{
				try
				{
					//if ( (recvMessageClient = mBufferedReaderClient.readLine()) != null )
					if((mBufferedReaderClient.read(buffer))>0)
					{						
						Message msg = new Message();
		                msg.what = 1;
						mHandler.sendMessage(msg);
					}
				}
				catch (Exception e)
				{
					Message msg = new Message();
	                msg.what = 1;
					mHandler.sendMessage(msg);
				}
			}
		}
	};
	
	Handler mHandler = new Handler()
	{										
		  public void handleMessage(Message msg)										
		  {											
			  super.handleMessage(msg);			

		  }									
	 };
		
		public void onDestroy() {
			super.onDestroy();
			if (isConnecting) 
			{				
				isConnecting = false;
				try {
					if(mSocketClient!=null)
					{
						mSocketClient.close();
						mSocketClient = null;
						
						mPrintWriterClient.close();
						mPrintWriterClient = null;
					}
				} catch (IOException e) {
					e.printStackTrace();
				}
				mThreadClient.interrupt();
			}

		}
}


