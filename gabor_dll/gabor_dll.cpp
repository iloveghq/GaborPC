// gabor_dll.cpp : 定义 DLL 的初始化例程。
//


#include "stdafx.h"
#include "gabor_dll.h"
#include "math.h"
#include "gabordllFun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#ifdef _MANAGED
#pragma managed(push, off)
#endif

#ifdef _MANAGED
#pragma managed(pop)
#endif
////////
////////#define Avg_loss_1310  0.320
////////#define Avg_loss_1550  0.182
////////#define Avg_loss_1490  0.192
////////#define Avg_loss_1625  0.192
////////#define Avg_loss_1300  0.6
////////#define Avg_loss_850  3.0
////////#define Return_loss_1310_tybe 79.5
////////#define Return_loss_1550_tybe 81
////////#define Return_loss_1490_tybe 80.5
////////#define Return_loss_1625_tybe 80.5
////////#define Return_loss_1300_tybe 70.5
////////#define Return_loss_850_tybe 60.5


//TODO: 如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//


// Cgabor_dllApp

BEGIN_MESSAGE_MAP(Cgabor_dllApp, CWinApp)
END_MESSAGE_MAP()


// Cgabor_dllApp 构造

Cgabor_dllApp::Cgabor_dllApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 Cgabor_dllApp 对象

Cgabor_dllApp theApp;


// Cgabor_dllApp 初始化

BOOL Cgabor_dllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

//LPCTSTR Version_number()
//{
//
////#if SAMPLE_ERRO
////   #if FISCAN9
////	return _T("FISCAN9-G151117-OLD");
////   #else return _T("G151117-7lamda-OLD");
////   #endif
////#else
////	#if FISCAN9
////		return _T("FISCAN9-G151117-NEW");
////	#else 
////	    return _T("G151117-7lamda-NEW");
////	#endif
////#endif
//#if FTDR02
//	return _T("FTDR02-G150721-HZ");
//#elif FB_OTDR
//	return _T("FISCAN9-G150808-HZ");
//#else
//#if Hight_zone
//	return _T("G151116-HZ");
//#else
//	return _T("G150721");
//#endif
//#endif
//}


//////
////////////Gabor_Result K_Line_count(int puse_point,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
////////////Gabor_Result Acount_Loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
////////////Gabor_Result Acount_Total_Loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
////////////Gabor_Result Optical_grating(int wavelength,int pulsewidth,WORD input_data[],INT paramLen,Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float dB_reflex);
////////////Gabor_Result Acount_return_loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe);
////////////Gabor_Result Find_event_end_function(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
////////Gabor_Result K_Line_count(int puse_point,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
//////void K_Line_count(int puse_point,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq);
////////Gabor_Result Acount_Loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
//////void Acount_Loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq);
////////Gabor_Result Acount_Total_Loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
//////void Acount_Total_Loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq);
//////Gabor_Result Optical_grating(int wavelength,int pulsewidth,WORD input_data[],INT paramLen,Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float dB_reflex);
////////Gabor_Result Acount_return_loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe);
//////void Acount_return_loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe);
//////Gabor_Result Find_event_end_function(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
//////void deleteEvent_New(int deleteNum,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe);
//////int lEventGenerate(int pulseNum,int wavelength,float Sample_freaq);
////////Gabor_Result K_Line_limite(int wavelength,Gabor_Result sGabor_Result);
//////void K_Line_limite(int wavelength,Gabor_Result* sGabor_Result);
//////Gabor_Result Search_fiber_end_function(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,float Sample_freaq,float thresholdUpSet );
//////int Search_long_fiber_end(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,float Sample_freaq);
//////void K_Line_count(int puse_point,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result *sGabor_Result,float Index_N,float Sample_freaq)
//////{
//////
//////	//先求各段光纤的斜率：只要计算删除点所在点的下一个点的特性
//////	int up_limit,low_limit;
//////	int step_event=puse_point*2;
//////	if(Sample_freaq>=400)step_event=step_event/2;
//////	if(pulsewidth>=2000)/////////////////////////////////////////20130615
//////		step_event=2*pulsewidth/40*(Sample_freaq/25);
//////	if(step_event<20)step_event=20;
//////	float* sum_k=new float[2000];//短时傅里叶变化结果Cn
//////	memset(sum_k,0,2000*sizeof(float));
//////	//double sum_k[20];
//////	double dB_k_k_1=0,dB_k_k_2=0;
//////
//////	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
//////	//两个数据之间的时间间隔：
//////	double Sample_time=Sample_freaq;//放大了10^6倍
//////	Sample_time=1/Sample_time;
//////	//测量距离计算
//////	int Event_start_mark_cn=sGabor_Result->Event_Array[0];
//////	int for_num=0;
//////	int i=0,j=0,k=0;
//////	float damage_value=0;
//////	
//////	for(i=0;i<sGabor_Result->Valid_Num-1;i++)
//////	{
//////		for_num=0;
//////
//////		low_limit=sGabor_Result->Event_Array[i+1]-10;
//////		if(low_limit<=0)low_limit=10;
//////		up_limit=sGabor_Result->Event_Array[i]+(sGabor_Result->Event_Array[i+1]-sGabor_Result->Event_Array[i])/8;
//////		if(up_limit<=0)break;
//////		if(up_limit<sGabor_Result->Event_Array[i]+3*step_event/2)up_limit=sGabor_Result->Event_Array[i]+3*step_event/2;//20130625
//////
//////		low_limit=low_limit-(sGabor_Result->Event_Array[i+1]-sGabor_Result->Event_Array[i])/8;
//////
//////
//////		if(low_limit<=sGabor_Result->Event_Array[i]+step_event/8)//相邻两个事件的距离太近，不适合算斜率，
//////		{
//////			sGabor_Result->Line_k[i+1]=0;
//////				continue;
//////		}
//////		else if(low_limit<up_limit+step_event/4)
//////		{
//////			low_limit=sGabor_Result->Event_Array[i];
//////			up_limit=sGabor_Result->Event_Array[i]-step_event;
//////			if(up_limit<=0)up_limit=10;
//////		}
//////		else
//////		{
//////			sGabor_Result->Line_k[i+1]=0;
//////			for_num=(sGabor_Result->Event_Array[i+1]-sGabor_Result->Event_Array[i])/8;
//////			//	if(for_num<20)for_num=20;
//////			//else
//////			if(for_num>200)for_num=200;
//////			for(k=4;k<for_num;k++)
//////			{
//////				if(up_limit-k<=0)break;
//////				dB_k_k_1=input_data[up_limit+k];
//////				dB_k_k_2=input_data[low_limit+k];
//////				if(low_limit-up_limit>0)
//////					sum_k[k]=(dB_k_k_2-dB_k_k_1)/((low_limit-up_limit)*(Sample_time*Light_fiber_speed)/2);
//////				sGabor_Result->Line_k[i+1]=sGabor_Result->Line_k[i+1]+sum_k[k];
//////			}
//////			if(k!=5)
//////				sGabor_Result->Line_k[i+1]=(sGabor_Result->Line_k[i+1]/(k-5));
//////			else sGabor_Result->Line_k[i+1]=sGabor_Result->Line_k[i+1];
//////			//if(wavelength==1310)//1310
//////			//{
//////			//	if(sGabor_Result->Line_k[i+1]<0.28||sGabor_Result->Line_k[i+1]>0.42)
//////			//	{
//////			//		//sGabor_Result->Line_k[i+1]=0;//0;//0.326;
//////			//		damage_value=(sGabor_Result->Line_k[i+1]-Avg_loss_1310)/10;
//////			//		if(((low_limit-up_limit)*(Sample_time*Light_fiber_speed)/2)>400)
//////			//		{
//////			//			sGabor_Result->Line_k[i+1]=Avg_loss_1310+damage_value;
//////			//		}
//////			//		else sGabor_Result->Line_k[i+1]=sGabor_Result->Line_k[i+1];
//////			//	}
//////
//////			//}
//////			//else if(wavelength==1550)//1550
//////			//{
//////			//	if(sGabor_Result->Line_k[i+1]<0.12||sGabor_Result->Line_k[i+1]>0.24)//sGabor_Result->Line_k[i+1]=0;//0;//0.184;
//////			//	{
//////			//		damage_value=(sGabor_Result->Line_k[i+1]-Avg_loss_1550)/10;
//////			//		if(((low_limit-up_limit)*(Sample_time*Light_fiber_speed)/2)>400)
//////			//		{
//////			//			sGabor_Result->Line_k[i+1]=Avg_loss_1550+damage_value;
//////			//		}
//////			//		else sGabor_Result->Line_k[i+1]=sGabor_Result->Line_k[i+1];
//////			//	}
//////			//}
//////			//else if(wavelength==1625)//1625
//////			//{
//////			//	if(sGabor_Result->Line_k[i+1]<0.12||sGabor_Result->Line_k[i+1]>0.26)//sGabor_Result->Line_k[i+1]=0;//0;//0.184;
//////			//	{
//////			//		damage_value=(sGabor_Result->Line_k[i+1]-Avg_loss_1625)/10;
//////			//		if(((low_limit-up_limit)*(Sample_time*Light_fiber_speed)/2)>400)
//////			//		{
//////			//			sGabor_Result->Line_k[i+1]=Avg_loss_1625+damage_value;
//////			//		}
//////			//		else sGabor_Result->Line_k[i+1]=sGabor_Result->Line_k[i+1];
//////			//	}
//////			//}
//////
//////		}
//////
//////	}
//////	delete[] sum_k;
//////	//return sGabor_Result;
//////}
//////void K_Line_limite(int wavelength,Gabor_Result* sGabor_Result)
//////{
//////	int i=0;
//////	for(i=0;i<sGabor_Result->Valid_Num;i++)
//////	{
//////		if(wavelength==1310)//1310
//////		{
//////			if(sGabor_Result->Line_k[i]<0.28||sGabor_Result->Line_k[i]>0.42)
//////			{
//////				//sGabor_Result->Line_k[i]=0;//0;//0.326;			
//////			}
//////
//////		}
//////		else if(wavelength==1490)//1490
//////		{
//////			if(sGabor_Result->Line_k[i]<0.12||sGabor_Result->Line_k[i]>0.24)
//////			{
//////				//sGabor_Result->Line_k[i]=0;//0;//0.326;			
//////			}
//////		}
//////		else if(wavelength==1550)//1550
//////		{
//////			if(sGabor_Result->Line_k[i]<0.12||sGabor_Result->Line_k[i]>0.24)
//////			{
//////				//sGabor_Result->Line_k[i]=0;//0;//0.326;			
//////			}
//////		}
//////		else if(wavelength==1625)//1625
//////		{
//////			if(sGabor_Result->Line_k[i]<0.12||sGabor_Result->Line_k[i]>0.26)
//////			{
//////				//sGabor_Result->Line_k[i]=0;//0;//0.326;			
//////			}
//////		}
//////		else if(wavelength==1300)//1625
//////		{
//////			if(sGabor_Result->Line_k[i]<0.12||sGabor_Result->Line_k[i]>0.26)
//////			{
//////				//sGabor_Result->Line_k[i]=0;//0;//0.326;			
//////			}
//////		}
//////		else if(wavelength==850)//1625
//////		{
//////			if(sGabor_Result->Line_k[i]<0.12||sGabor_Result->Line_k[i]>0.26)
//////			{
//////				//sGabor_Result->Line_k[i]=0;//0;//0.326;			
//////			}
//////		}
//////	}
//////	//return sGabor_Result;
//////}
//////
//////int lEventGenerate(int pulseNum,int wavelength,float Sample_freaq)
//////{
//////	float kkk=0;
//////	int Freaq_num=0;
//////	Freaq_num=Sample_freaq/25;
//////	if(Freaq_num<=0)Freaq_num=1;
//////	int lEvent=200;
//////	//	Sample_freaq=25;
//////#if Hight_zone
//////		switch(pulseNum)
//////		{
//////		case 0://3ns
//////			//kkk=
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=8;break;  //25M
//////			case 2:lEvent=10;break;  //50M
//////			case 4:lEvent=40;break;  //100M
//////			case 8:lEvent=45;break;  //200M
//////			case 16:lEvent=50;break;  //400M
//////			case 82:lEvent=50;break;
//////			default:lEvent=5;break;
//////			}
//////			//lEvent=1;
//////			break;
//////		case 1://5ns
//////			//lEvent=2;
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=8;break;  //25M
//////			case 2:lEvent=10;break;  //50M
//////			case 4:lEvent=12;break;  //100M
//////			case 8:lEvent=16;break;  //200M
//////			case 16:lEvent=30;break;  //400M
//////			case 82:lEvent=100;break; //2G
//////			default:lEvent=10;break;
//////			}
//////			break;
//////		case 2://10ns
//////			//lEvent=4;
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=10;break;  //25M
//////			case 2:lEvent=14;break;  //50M
//////			case 4:lEvent=20;break;  //100M
//////			case 8:lEvent=30;break;  //200M
//////			case 16:lEvent=100;break;  //400M
//////			case 82:lEvent=350;break; //2G
//////			default:lEvent=10;break;
//////			}
//////			break;
//////		case 3://20ns
//////			//lEvent=25;
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=20;break;  //25M
//////			case 2:lEvent=16;break;  //50M
//////			case 4:lEvent=30;break;  //100M
//////			case 8:lEvent=60;break;  //200M
//////			case 16:lEvent=100;break;  //400M
//////			case 82:lEvent=800;break; //2G
//////			default:lEvent=15;break;
//////			}
//////			break;
//////		case 13://30ns
//////			//lEvent=25;
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=16;break;  //25M
//////			case 2:lEvent=20;break;  //50M
//////			case 4:lEvent=30;break;  //100M
//////			case 8:lEvent=50;break;  //200M
//////			case 16:lEvent=90;break;  //400M
//////			case 82:lEvent=500;break; //2G
//////			default:lEvent=50;break;
//////			}
//////			break;
//////		case 4://50ns
//////			//lEvent=25;
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=20;break;  //25M
//////			case 2:lEvent=20;break;  //50M
//////			case 4:lEvent=40;break;  //100M
//////			case 8:lEvent=90;break;  //200M
//////			case 16:lEvent=100;break;  //400M
//////			case 82:lEvent=700;break; //2G
//////			default:lEvent=100;break;
//////			}
//////			break;
//////		case 5://100ns
//////			//lEvent=35;
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=40;break;  //25M
//////			case 2:lEvent=40;break;  //50M
//////			case 4:lEvent=50;break;  //100M
//////			case 8:lEvent=100;break;  //200M
//////			case 16:lEvent=200;break;  //400M
//////			case 82:lEvent=800;break; //2G
//////			default:lEvent=30;break;
//////			}
//////			break;
//////		case 6://200ns
//////			//lEvent=50;
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=50;break;  //25M
//////			case 2:lEvent=60;break;  //50M
//////			case 4:lEvent=80;break;  //100M
//////			case 8:lEvent=220;break;  //200M
//////			case 16:lEvent=280;break;  //400M
//////			case 82:lEvent=1000;break; //2G
//////			default:lEvent=50;break;
//////			}
//////			break;
//////		case 14://300ns
//////			//lEvent=50;
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=44;break;  //25M
//////			case 2:lEvent=80;break;  //50M
//////			case 4:lEvent=140;break;  //100M
//////			case 8:lEvent=170;break;  //200M
//////			case 16:lEvent=300;break;  //400M
//////			case 82:lEvent=1000;break; //2G
//////			default:lEvent=50;break;
//////			}
//////			break;
//////		case 15://400ns
//////			//lEvent=50;
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=48;break;  //25M
//////			case 2:lEvent=90;break;  //50M
//////			case 4:lEvent=150;break;  //100M
//////			case 8:lEvent=180;break;  //200M
//////			case 16:lEvent=310;break;  //400M
//////			case 82:lEvent=1100;break; //2G
//////			default:lEvent=100;break;
//////			}
//////			break;
//////		case 7://500ns
//////			//lEvent=55;
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=70;break;  //25M
//////			case 2:lEvent=120;break;  //50M
//////			case 4:lEvent=160;break;  //100M
//////			case 8:lEvent=180;break;  //200M
//////			case 16:lEvent=320;break;  //400M
//////			case 82:lEvent=1200;break; //2G
//////			default:lEvent=100;break;
//////			}
//////			break;
//////		case 8://1us
//////			//lEvent=60;
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=104;break;  //25M
//////			case 2:lEvent=140;break;  //50M
//////			case 4:lEvent=200;break;  //100M
//////			case 8:lEvent=240;break;  //200M
//////			case 16:lEvent=380;break;  //400M
//////			case 82:lEvent=1400;break; //2G
//////			default:lEvent=120;break;
//////			}
//////			break;
//////		case 9://2us
//////			//lEvent=75;
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=150;break;  //25M
//////			case 2:lEvent=200;break;  //50M
//////			case 4:lEvent=240;break;  //100M
//////			case 8:lEvent=280;break;  //200M
//////			case 16:lEvent=420;break;  //400M
//////			case 82:lEvent=1600;break; //2G
//////			default:lEvent=160;break;
//////			}
//////			break;
//////		case 10://5us
//////			//lEvent=100;
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=220;break;  //25M
//////			case 2:lEvent=240;break;  //50M
//////			case 4:lEvent=280;break;  //100M
//////			case 8:lEvent=320;break;  //200M
//////			case 16:lEvent=500;break;  //400M
//////			case 82:lEvent=2000;break; //2G
//////			default:lEvent=120;break;
//////			}
//////			break;
//////		case 11://10us
//////			//lEvent=200;
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=320;break;  //25M
//////			case 2:lEvent=350;break;  //50M
//////			case 4:lEvent=400;break;  //100M
//////			case 8:lEvent=500;break;  //200M
//////			case 16:lEvent=600;break;  //400M
//////			case 82:lEvent=3000;break; //2G
//////			default:lEvent=200;break;
//////			}
//////			break;
//////		case 12://20us
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=300;break;  //25M
//////			case 2:lEvent=450;break;  //50M
//////			case 4:lEvent=500;break;  //100M
//////			case 8:lEvent=550;break;  //200M
//////			case 16:lEvent=700;break;  //400M
//////			case 82:lEvent=3500;break; //2G
//////			default:lEvent=200;break;
//////			}
//////			break;
//////		default:
//////			//lEvent=200;
//////			switch(Freaq_num)
//////			{
//////			case 1:lEvent=1;break;  //25M
//////			case 2:lEvent=1;break;  //50M
//////			case 4:lEvent=1;break;  //100M
//////			case 8:lEvent=2;break;  //200M
//////			case 16:lEvent=3;break;  //400M
//////			case 82:lEvent=15;break; //2G
//////			default:lEvent=3;break;
//////			}
//////			break;
//////		}
//////#else
//////	switch(pulseNum)
//////	{
//////	case 0://3ns
//////		//kkk=
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=1;break;  //25M
//////		case 2:lEvent=2;break;  //50M
//////		case 4:lEvent=3;break;  //100M
//////		case 8:lEvent=5;break;  //200M
//////		case 16:lEvent=8;break;  //400M
//////		case 80:lEvent=50;break;
//////		default:lEvent=5;break;
//////		}
//////		//lEvent=1;
//////		break;
//////	case 1://5ns
//////		//lEvent=2;
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=4;break;  //25M
//////		case 2:lEvent=6;break;  //50M
//////		case 4:lEvent=7;break;  //100M
//////		case 8:lEvent=8;break;  //200M
//////		case 16:lEvent=8;break;  //400M
//////		case 80:lEvent=50;break; //2G
//////		default:lEvent=10;break;
//////		}
//////		break;
//////	case 2://10ns
//////		//lEvent=4;
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=5;break;  //25M
//////		case 2:lEvent=7;break;  //50M
//////		case 4:lEvent=8;break;  //100M
//////		case 8:lEvent=9;break;  //200M
//////		case 16:lEvent=15;break;  //400M
//////		case 80:lEvent=75;break; //2G
//////		default:lEvent=10;break;
//////		}
//////		break;
//////	case 3://20ns
//////		//lEvent=25;
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=6;break;  //25M
//////		case 2:lEvent=7;break;  //50M
//////		case 4:lEvent=8;break;  //100M
//////		case 8:lEvent=15;break;  //200M
//////		case 16:lEvent=30;break;  //400M
//////		case 80:lEvent=150;break; //2G
//////		default:lEvent=15;break;
//////		}
//////		break;
//////	case 13://30ns
//////		//lEvent=25;
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=8;break;  //25M
//////		case 2:lEvent=10;break;  //50M
//////		case 4:lEvent=20;break;  //100M
//////		case 8:lEvent=35;break;  //200M
//////		case 16:lEvent=50;break;  //400M
//////		case 80:lEvent=250;break; //2G
//////		default:lEvent=50;break;
//////		}
//////		break;
//////	case 4://50ns
//////		//lEvent=25;
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=12;break;  //25M
//////		case 2:lEvent=18;break;  //50M
//////		case 4:lEvent=30;break;  //100M
//////		case 8:lEvent=40;break;  //200M
//////		case 16:lEvent=70;break;  //400M
//////		case 80:lEvent=350;break; //2G
//////		default:lEvent=100;break;
//////		}
//////		break;
//////	case 5://100ns
//////		//lEvent=35;
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=36;break;  //25M
//////		case 2:lEvent=40;break;  //50M
//////		case 4:lEvent=70;break;  //100M
//////		case 8:lEvent=120;break;  //200M
//////		case 16:lEvent=240;break;  //400M
//////		case 80:lEvent=700;break; //2G
//////		default:lEvent=30;break;
//////		}
//////		break;
//////	case 6://200ns
//////		//lEvent=50;
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=40;break;  //25M
//////		case 2:lEvent=60;break;  //50M
//////		case 4:lEvent=80;break;  //100M
//////		case 8:lEvent=140;break;  //200M
//////		case 16:lEvent=280;break;  //400M
//////		case 80:lEvent=1000;break; //2G
//////		default:lEvent=50;break;
//////		}
//////		break;
//////	case 14://300ns
//////		//lEvent=50;
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=44;break;  //25M
//////		case 2:lEvent=80;break;  //50M
//////		case 4:lEvent=140;break;  //100M
//////		case 8:lEvent=170;break;  //200M
//////		case 16:lEvent=300;break;  //400M
//////		case 80:lEvent=1000;break; //2G
//////		default:lEvent=50;break;
//////		}
//////		break;
//////	case 15://400ns
//////		//lEvent=50;
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=48;break;  //25M
//////		case 2:lEvent=90;break;  //50M
//////		case 4:lEvent=150;break;  //100M
//////		case 8:lEvent=180;break;  //200M
//////		case 16:lEvent=310;break;  //400M
//////		case 80:lEvent=1050;break; //2G
//////		default:lEvent=100;break;
//////		}
//////		break;
//////	case 7://500ns
//////		//lEvent=55;
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=70;break;  //25M
//////		case 2:lEvent=100;break;  //50M
//////		case 4:lEvent=160;break;  //100M
//////		case 8:lEvent=180;break;  //200M
//////		case 16:lEvent=320;break;  //400M
//////		case 80:lEvent=1100;break; //2G
//////		default:lEvent=100;break;
//////		}
//////		break;
//////	case 8://1us
//////		//lEvent=60;
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=104;break;  //25M
//////		case 2:lEvent=140;break;  //50M
//////		case 4:lEvent=200;break;  //100M
//////		case 8:lEvent=240;break;  //200M
//////		case 16:lEvent=380;break;  //400M
//////		case 80:lEvent=1400;break; //2G
//////		default:lEvent=120;break;
//////		}
//////		break;
//////	case 9://2us
//////		//lEvent=75;
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=118;break;  //25M
//////		case 2:lEvent=200;break;  //50M
//////		case 4:lEvent=240;break;  //100M
//////		case 8:lEvent=280;break;  //200M
//////		case 16:lEvent=420;break;  //400M
//////		case 80:lEvent=1600;break; //2G
//////		default:lEvent=160;break;
//////		}
//////		break;
//////	case 10://5us
//////		//lEvent=100;
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=200;break;  //25M
//////		case 2:lEvent=240;break;  //50M
//////		case 4:lEvent=280;break;  //100M
//////		case 8:lEvent=320;break;  //200M
//////		case 16:lEvent=500;break;  //400M
//////		case 80:lEvent=2000;break; //2G
//////		default:lEvent=120;break;
//////		}
//////		break;
//////	case 11://10us
//////		//lEvent=200;
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=280;break;  //25M
//////		case 2:lEvent=350;break;  //50M
//////		case 4:lEvent=400;break;  //100M
//////		case 8:lEvent=500;break;  //200M
//////		case 16:lEvent=600;break;  //400M
//////		case 80:lEvent=3000;break; //2G
//////		default:lEvent=200;break;
//////		}
//////		break;
//////	case 12://20us
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=440;break;  //25M
//////		case 2:lEvent=450;break;  //50M
//////		case 4:lEvent=500;break;  //100M
//////		case 8:lEvent=550;break;  //200M
//////		case 16:lEvent=700;break;  //400M
//////		case 80:lEvent=3500;break; //2G
//////		default:lEvent=200;break;
//////		}
//////		break;
//////	default:
//////		//lEvent=200;
//////		switch(Freaq_num)
//////		{
//////		case 1:lEvent=1;break;  //25M
//////		case 2:lEvent=1;break;  //50M
//////		case 4:lEvent=1;break;  //100M
//////		case 8:lEvent=2;break;  //200M
//////		case 16:lEvent=3;break;  //400M
//////		case 80:lEvent=15;break; //2G
//////		default:lEvent=3;break;
//////		}
//////		break;
//////	}
//////#endif
//////	return lEvent;
//////}
////////******************************************************************//
////////     事件分析
////////     L_event:分析事件步进，跟脉宽和采样分辨率有关系
////////     wavelength:曲线波长
////////     input_data[]：分析的原始数据
////////     paramLen:原始数据长度
////////     thresholdUpSet:短时傅里叶变化阈值上限
////////     thresholdDownSet:短时傅里叶变化阈值下限
////////     dB_Loss:衰减门限
////////     dB_reflex:反射门限
////////     dB_End:末端判断门限
////////******************************************************************//
///////***********************************************************************/
/////////pulseWidth：脉宽
/////////wavelength:波长值，0:1310,1:1550
/////////input_data[]:采样数据
/////////paramLen：采样数据长度
////////double thresholdUpSet:傅里叶变化阈值上限。默认为2.08
////////double thresholdDownSet傅里叶变化阈值下限.默认为2.08
/////////dB_Loss:衰减判断门限
/////////dB_reflex：反射判断门限
/////////dB_End：末端判断门限默认为3
/////////Return_loss_Tybe：典型散射系数
//////// Sample_freaq:采样频率
///////**********************************************************************/
//////Gabor_Result gabor_generate(int pulsewidth,int wavelength,WORD *input_data,int paramLen,double thresholdUpSet,double thresholdDownSet,float dB_Loss,float dB_reflex,float dB_End,float Sample_freaq,float Index_N,int link_point_number)
//////{
//////	int input_length=paramLen;
//////	int length_real=0;//剔除最小值之后的真实长度
//////	int length_real_Zero=0;
//////	int line_n=20;//直线拟合的抽样长度
//////	double ratio=0.001;//短时傅里叶变化系数0.001-1之间 
//////
//////	////double thresholdUp=thresholdUpSet;//发生概率，阈值上限
//////	////double thresholdDown=thresholdDownSet;//发生概率，阈值下限
//////
//////	////int N_event=3;//事件长度点数 
//////	int i=0;//循环点数
//////	int j=0;//循环点数
//////	int k=0;//循环点数 
//////	int l=0;//循环点数
//////	char Char_type=0;
//////	float float_type=0;
//////	float int_type=0;
//////	int gabor_length=10;
//////	////int maxCn_mark=10;//曲线尾段事件位置
//////	////double min_db=2;//最小检测DB衰减值
//////	////int part_sub_table=0;//分段事件分析时下限
//////	////int part_up_table=0;//分段事件分析时上限
//////	////int input_data_part_max_sub=0;//分段事件分析时最大值的下标
//////	////int input_data_part_min_sub=0;
//////	////double part_ref_reflect=0;//分段事件分析时反射情况的参考值
//////	////double part_std=0;//分段事件分析时分段的标准差
//////	////double part_mean=0;//分段事件分析时分段的平均值
//////	////double input_data_part_min=0;//分段事件分析时最小值
//////	////double input_data_part_max=0;//分段事件分析时最大值
//////	////double gabor_result_sum= 0;//Gabor_result之和
//////	////double gabor_result_mean=0;//Gabor_result平均值
//////	////double std_end=0;//尾端的RMS值
//////
//////
//////	//int input_data_buff[128000];
//////	int* input_data_buff=new int[input_length];//短时傅里叶变化结果Cn
//////	memset(input_data_buff,0,input_length*sizeof(int));
//////
//////	//double line_fit_factor[2][100];
//////
//////	//double gaborResultTemp[2000];
//////	//memset(gaborResultTemp,0,sizeof(gaborResultTemp));
//////	Gabor_Result sGabor_Result;//结构体存贮结果
//////	//memset(line_fit_factor,0,sizeof(line_fit_factor));
//////
//////	int return_flag=0;
//////	int pulseNum=11;
//////	int L_event=0;
//////	switch(pulsewidth)
//////	{
//////	case 3:
//////		pulseNum=0;
//////		break;
//////	case 5:
//////		pulseNum=1;
//////		break;
//////	case 10:
//////		pulseNum=2;
//////		break;
//////	case 20:
//////		pulseNum=3;
//////		break;
//////	case 50:
//////		pulseNum=4;
//////		break;
//////	case 100:
//////		pulseNum=5;
//////		break;
//////	case 200:
//////		pulseNum=6;
//////		break;
//////	case 500:
//////		pulseNum=7;	
//////		break;
//////	case 1000:
//////		pulseNum=8;
//////		break;
//////	case 2000:
//////		pulseNum=9;
//////		break;
//////	case 5000:
//////		pulseNum=10;
//////		break;
//////	case 10000:
//////		pulseNum=11;
//////		break;
//////	case 20000:
//////		pulseNum=12;
//////		break;
//////	case 30:
//////		pulseNum=13;
//////		break;
//////	case 300:
//////		pulseNum=14;
//////		break;
//////	case 400:
//////		pulseNum=15;
//////		break;
//////
//////	default:pulseNum=12;break;
//////	}
//////	L_event=lEventGenerate(pulseNum,wavelength,Sample_freaq);
//////
//////	int step_event=L_event*2;
//////
//////	if(pulsewidth>=2000)/////////////////////////////////////////20130615
//////	{
//////	//	step_event=2*pulsewidth/25*(Sample_freaq/25)*11/10;
//////	//	L_event=step_event/2;
//////	}
//////	//step_event=900;
//////
//////	//光在光纤中传播的速度
//////	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
//////	//两个数据之间的时间间隔：
//////	double Sample_time=Sample_freaq;//放大了10^6倍
//////	Sample_time=1/Sample_time;
//////	//测量距离计算
//////	double Measure_distacne = Light_fiber_speed*Sample_time*paramLen;
//////
//////
//////	//int L_event=0;
//////	//switch(pulse_no)
//////
//////	//switch(wavelength)//根据功率等级设置阈值上下限
//////	//{
//////	//case 0:
//////	//	{
//////	//		thresholdUp=2.08;//发生概率，阈值上限
//////	//		thresholdDown=2.08;//发生概率，阈值下限
//////	//	}
//////	//	break;
//////	//default:
//////	//	{
//////	//		thresholdUp=2.08;//发生概率，阈值上限
//////	//		thresholdDown=2.08;//发生概率，阈值下限
//////	//	}
//////	//	break;
//////	//}
//////	//末端判断
//////
//////	long Sond_data_Sum=0;
//////	int More_than_flag_count=0;
//////	int Less_than_flag_count=0;
//////	int data_buff=0;
//////	int count_number=0;
//////	float percentage_flag=0;
//////	char end_ok_flag=0;
//////	int end_ok_count=0;
//////	long Avg_data=0;
//////	int data_length=0;
//////	if(input_length<3000)data_length=101;
//////	else data_length=501;
//////	if(input_length>501)
//////	{
//////		for(i=input_length-1;i>input_length-data_length;i--)
//////		{
//////			Sond_data_Sum=Sond_data_Sum+(65535-input_data[i]);
//////		}
//////		Sond_data_Sum=Sond_data_Sum/(data_length-1); //求噪声平均值
//////		if(Sond_data_Sum<=500)Sond_data_Sum;
//////	}
//////
//////	////////////20150808 正向查找光纤长度
//////	for(i=L_event;i<input_length-2;i++)
//////	{
//////	  if(65535-input_data[i]<=3*Sond_data_Sum/2)
//////	  {
//////		  
//////		  Less_than_flag_count++;
//////		  if(Less_than_flag_count>=2)More_than_flag_count=0;
//////		  if(Less_than_flag_count>=6)
//////		  {
//////			  //末端找到
//////			  length_real_Zero=i;
//////			  break;
//////		 
//////		  }
//////	  }
//////	  else 
//////	  {
//////		  More_than_flag_count++;
//////		  if(More_than_flag_count>=2)Less_than_flag_count=0;
//////	  }
//////	}
//////	if(length_real_Zero==0)length_real_Zero=input_length;
//////	//if(Sond_data_Sum>=5000)Sond_data_Sum=3000;//对噪声的最大平均值做限制
//////	if(Sond_data_Sum>=4000)Sond_data_Sum=2000;//对噪声的最大平均值做限制20131217
//////	count_number=3*L_event/2;//L_event/2,20121108
//////	if(count_number<40)count_number=40;
//////	for(i=input_length-1;i>0;)//末端寻找
//////	{
//////		if(i>count_number)
//////		{
//////
//////			//if(count_number<10)count_number=10;
//////			More_than_flag_count=0;
//////			Less_than_flag_count=0;
//////			Avg_data=0;
//////			for(j=i;j>i-count_number;j--)
//////			{
//////				data_buff=65535-input_data[j];
//////				Avg_data=Avg_data+data_buff;
//////				if(data_buff>(2*Sond_data_Sum+1000))More_than_flag_count++;
//////				else Less_than_flag_count++;
//////			}
//////			Avg_data=Avg_data/count_number;
//////
//////			percentage_flag=More_than_flag_count;
//////			percentage_flag=percentage_flag/count_number;
//////			if(percentage_flag>=0.7 && Avg_data>=2*Sond_data_Sum)
//////			{
//////				if(end_ok_flag==0)
//////					length_real=j+count_number*(percentage_flag);
//////				end_ok_flag=1;
//////				end_ok_count++;
//////				if(end_ok_count>=20)break;
//////				//break;
//////			}
//////			else 
//////			{
//////				i=i-count_number/2;
//////				end_ok_flag=0;
//////				end_ok_count=0;
//////			}
//////
//////		}
//////		else 
//////		{
//////			length_real=input_length-1;
//////			break;
//////		}
//////
//////	}
//////	if(length_real_Zero<=length_real)length_real=length_real_Zero+L_event/2;//20150808
//////	if(length_real>=input_length-step_event)length_real=input_length-step_event-2;
//////  if(pulsewidth>=10000&&Sample_freaq==25)
//////	length_real=length_real_Zero+step_event;
////// // length_real=length_real_Zero;
////////length_real=input_length-step_event-2;
//////	//length_real=input_length-L_event;
//////	//细化末端,选取末端的前后两个波长的数据用于分析
//////	if(length_real>3*step_event&&input_length>length_real-step_event)
//////	{
//////		//int input_data_buff_statick[4000];
//////		//int* input_data_buff_statick=new int[2*step_event+2];//短时傅里叶变化结果Cn
//////		//memset(input_data_buff_statick,0,(2*step_event+2)*sizeof(int));
//////		Avg_data=0;
//////		for(i=length_real-step_event;i<length_real+step_event;i++)
//////		{
//////			Avg_data=Avg_data+(65535-input_data[i]);
//////		}
//////		Avg_data=Avg_data/(2*step_event);
//////		//if(Avg_data<=0)Avg_data=500;
//////		//末端为反射类型的判断,求差值
//////		int MAX_input_data_buff_statick=0;
//////		int Avg_four_data=0;
//////		int MAX_cmaxk=0;
//////		for(i=length_real-step_event;i<length_real+step_event;i++)
//////		{
//////			input_data_buff[i+step_event-length_real]=65535-input_data[i];
//////			input_data_buff[i+step_event-length_real]=input_data_buff[i+step_event-length_real]-Avg_data;
//////			if(MAX_input_data_buff_statick<=input_data_buff[i+step_event-length_real])
//////			{
//////				MAX_input_data_buff_statick=input_data_buff[i+step_event-length_real];
//////				MAX_cmaxk=i;
//////			}
//////
//////		}
//////		int avg1=0;
//////		int avg2=0;
//////		int avg3=0;
//////		int max_avg=0;
//////		int max_avg_mark=0;
//////
//////		int data_Max_j=0;
//////		int max_count_j=0;
//////		for(i=length_real-step_event;i<length_real-step_event+5;i++)
//////		{
//////			avg1=avg1+65535-input_data[i];
//////		}
//////		avg1=avg1/5;
//////		//if(MAX_cmaxk>=length_real-step_event+8)//最大值内置不在末端位置附近
//////		{
//////			for(i=MAX_cmaxk-10;i<MAX_cmaxk+10;i++)
//////			{
//////				data_Max_j=65535-input_data[i]-avg1;
//////				if(data_Max_j>100)
//////				{
//////					max_count_j++;
//////					if(max_count_j>=5)//反射峰判断
//////					{
//////						if((i-4)>step_event)
//////						length_real=i-4;
//////
//////						break;
//////					}
//////				}
//////				else max_count_j=0;
//////			}
//////		}
//////
//////		if(max_count_j<4)//没有反射峰的情况判断，找突变的情况
//////		{
//////			max_count_j=0;
//////
//////			for(i=length_real-step_event;i<length_real-5;i++)
//////			{
//////				input_data_buff[i+step_event-length_real]=input_data[i+1]-input_data[i];
//////			}
//////			for(i=length_real-step_event;i<length_real-step_event/2-5;i++)
//////			{
//////				avg1=avg1+abs(input_data_buff[i+step_event-length_real]);
//////			}
//////			avg1=avg1/(step_event/2-5);
//////			for(i=length_real-step_event;i<length_real;i++)
//////			{
//////				if(input_data_buff[i+step_event-length_real]>avg1/2)
//////				{
//////					max_count_j++;
//////					if(max_count_j>=4)
//////					{
//////						length_real=i-max_count_j;//-step_event/4;
//////						break;
//////					}
//////				}
//////				else max_count_j=0;
//////			}
//////		}
//////		//	delete[] input_data_buff_statick;
//////	}
//////	//////////////////////////20ns以内的数据采用另外一种事件分析算法
//////	Measure_distacne = Light_fiber_speed*Sample_time*length_real;
//////	int Lange_count=0;
//////	j=0;
//////	//int input_data_buff[128000];
//////	//	int* input_data_buff=new int[input_length];//短时傅里叶变化结果Cn
//////	//	memset(input_data_buff,0,input_length*sizeof(int));
//////	int Max_data_true=0;
//////	float kkk=2;////20131219 该系数的大小会影响到盲区事件的判断，同时也会干扰100ns、50ns等反射末端的判断
//////	//if(Measure_distacne<2000)kkk=2;//2km以内采用小脉宽测量时噪声系数不一样///2
//////	//else kkk=3;///3
//////	if(pulsewidth<100)//针对脉宽<100ns的脉宽做特殊处理
//////	{
//////		Measure_distacne = Light_fiber_speed*Sample_time*length_real;
//////		//if(input_length>1001)
//////		{
//////			for(i=5;i<input_length;i++)
//////			{
//////				Sond_data_Sum=Sond_data_Sum+(65535-input_data[i]);
//////				if(Max_data_true<(65535-input_data[i]))
//////					Max_data_true=65535-input_data[i];
//////			}
//////			Sond_data_Sum=Sond_data_Sum/(input_length-5); //求噪声平均值
//////		}
//////		if(Max_data_true<3*Sond_data_Sum)kkk=1.5;
//////		for(i=5;i<input_length-3;i++)
//////		{
//////			input_data_buff[i]=input_data[i];
//////			input_data_buff[i]=(65535-input_data_buff[i])-kkk*Sond_data_Sum;
//////			if(input_data_buff[i]<=0)input_data_buff[i]=0;
//////		}
//////		for(i=5;i<input_length-4;i++)
//////		{
//////			input_data_buff[i]=input_data_buff[i+3]-input_data_buff[i];
//////			if(input_data_buff[i]<300)input_data_buff[i]=0;
//////		}
//////		/*sGabor_Result.Event_type[j]='F';
//////		sGabor_Result.Reflect_Type[j]=FALSE;
//////		sGabor_Result.Event_Array[j++]=4;*/
//////		int nn=0,mm=0,n=0,m=0,h=0;
//////		long Avg_xd_roise=0;
//////		if(Sample_freaq==400)
//////		{
//////			nn=L_event;//*、、*/20
//////			mm=3;
//////		}
//////		else if(Sample_freaq==200)
//////		{
//////			nn=L_event;//10
//////			mm=2;
//////		}
//////		else if(Sample_freaq==100)
//////		{
//////			nn=L_event;//10
//////			mm=2;
//////		}
//////		else if(Sample_freaq==50)
//////		{
//////			nn=L_event;//10
//////			mm=2;
//////		}
//////		else if(Sample_freaq==25)
//////		{
//////			nn=L_event;//10
//////			mm=2;
//////		}
//////		else
//////		{
//////			nn=L_event;//10
//////			mm=3;
//////		}
//////		//int LK=L_event/4;
//////		//if(LK<10)LK=10;
//////		for(i=5;i<input_length-3;i++)
//////	//	for(i=5;i<length_real_Zero;i++)
//////		{
//////			if(input_data_buff[i]>0)
//////			{
//////				Lange_count++;
//////				if(Lange_count>nn)
//////				{
//////
//////
//////					if(j!=0)
//////						if((i+1-Lange_count)<sGabor_Result.Event_Array[j-1]+L_event/4)continue;
//////					sGabor_Result.Event_type[j]='F';
//////					sGabor_Result.Reflect_Type[j]=TRUE;
//////					sGabor_Result.Event_Loss[j]=0;
//////					sGabor_Result.Event_Hight[j]=0;
//////					sGabor_Result.Line_k[j]=0;
//////					sGabor_Result.Total_Loss[j]=0;
//////
//////					sGabor_Result.Event_Array[j++]=i-Lange_count;//i+1-Lange_count  20120704
//////					Lange_count=0;
//////					if(j>=99)break;
//////				}
//////			}
//////			else 
//////			{
//////				if(Lange_count>=mm)
//////				{
//////
//////					if(j!=0)
//////					{
//////						if((i+1-Lange_count)<sGabor_Result.Event_Array[j-1]+L_event/4)
//////						{
//////							Lange_count=0;
//////							continue;
//////						}
//////					}
//////					sGabor_Result.Event_type[j]='F';
//////					sGabor_Result.Reflect_Type[j]=TRUE;
//////					sGabor_Result.Event_Loss[j]=0;
//////					sGabor_Result.Event_Hight[j]=0;
//////					sGabor_Result.Line_k[j]=0;
//////					sGabor_Result.Total_Loss[j]=0;
//////
//////					sGabor_Result.Event_Array[j++]=i-Lange_count;//i+1-Lange_count  20120704
//////					Lange_count=0;
//////					if(j>=99)break;
//////				}
//////				else Lange_count=0;
//////			}
//////
//////
//////		}
//////		if(j<20)//事件太多，判断不够严谨，重新判断，针对每一个事件做平均值分析
//////		{
//////			sGabor_Result.Event_type[j-1]='E';
//////			sGabor_Result.Valid_Num=j;
//////			//if(pulsewidth==3)return_flag=1;  //////20150915
//////		//	return_flag=1;  /////////////////////////////////////20140111,解决50ns，2km+2km时的中间损耗事件出不来的情况
//////			//求回波损耗
//////			//for()
//////			//return sGabor_Result;//element_result[1][1];
//////		}
//////		//if(sGabor_Result.Valid_Num>1)  //20150504
//////		//	length_real=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1];
//////
//////	}
//////	//反射事件的判断
//////	if(return_flag==0)
//////	{
//////		//if(pulsewidth>=10000)L_event=200;
//////		int start_point_1=0;
//////		int end_point_1=start_point_1+L_event;
//////		int ratio_avg_1=0;
//////		int up_start_1=0;
//////		int less_count_time_1=0;
//////		int Lange_count_1=0;
//////		int for_count1=0;
//////		int for_count2=0;
//////
//////		int length_count1=L_event/4;//L_event/4;
//////		int length_count2=L_event/5;//L_event/5;
//////		if(L_event<30)
//////		{
//////			length_count1=6;
//////			length_count2=4;
//////		}
//////
//////      //  length_real=length_real+L_event;
//////		for(i=5;i<(length_real-L_event);)
//////		{
//////
//////			for_count1++;
//////			if(for_count1>=(length_real-L_event))break;
//////			end_point_1=start_point_1+L_event;
//////			if(end_point_1>(length_real-L_event))
//////			{
//////				end_point_1=length_real+L_event;
//////				if(end_point_1>input_length)end_point_1=input_length-L_event-1;
//////			}
//////			ratio_avg_1=0;
//////			for(j=start_point_1;j<(end_point_1-2);j++)
//////			{
//////				input_data_buff[j-start_point_1]=input_data[j+2]-input_data[j];
//////				ratio_avg_1=ratio_avg_1+abs(input_data_buff[j-start_point_1]);
//////			}
//////			if((end_point_1-2)>start_point_1)
//////				ratio_avg_1=ratio_avg_1/(end_point_1-2-start_point_1);
//////			else ratio_avg_1=ratio_avg_1;
//////			j=start_point_1;
//////			for_count2=start_point_1;
//////			while(j<end_point_1-2)//for(j=start_point_1;j<(end_point_1-2);)//
//////			{
//////				for_count2++;
//////				if(for_count2>=(end_point_1-2))break;
//////				Lange_count_1=0;
//////				less_count_time_1=0;
//////				up_start_1=65535-input_data[j];
//////				for(k=j+1;k<(end_point_1-2);k++)
//////				{
//////					if((up_start_1+3*ratio_avg_1)<(65535-input_data[k]))////20131219将系数原来的3改为了2，增强反射事件的判断林敏度
//////					{
//////						if(less_count_time_1)
//////						{
//////
//////							Lange_count_1=0;
//////							less_count_time_1=0;
//////						}
//////						else 
//////						{
//////							//less_count_time=0;
//////							Lange_count_1++;
//////						}
//////
//////					}
//////					else
//////					{
//////						if(Lange_count_1)
//////						{
//////							less_count_time_1=0;
//////							Lange_count_1=0;
//////						}
//////						else less_count_time_1++;
//////					}
//////					if(Lange_count_1>=length_count1)
//////					{
//////						if(sGabor_Result.Valid_Num<99)
//////						{
//////
//////							sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=abs(k-Lange_count_1);
//////							sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=TRUE;
//////							sGabor_Result.Event_type[sGabor_Result.Valid_Num++]='F';
//////							j=k;
//////							break;
//////						}
//////					}
//////				}
//////				if((k==(end_point_1-2))&&(Lange_count_1>=length_count2))
//////				{
//////					if(sGabor_Result.Valid_Num<99)
//////					{
//////						sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=abs(k-Lange_count_1);
//////						sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=TRUE;
//////						sGabor_Result.Event_type[sGabor_Result.Valid_Num++]='F';
//////					}
//////					j=k;
//////					break;
//////				}
//////				j=k;
//////
//////			}
//////			//start_point_1=end_point_1;
//////			i=start_point_1+L_event/2;
//////			start_point_1=i;
//////
//////		}
//////		if(Sample_freaq==25&&pulsewidth<=200)
//////		{
//////			long avg_leven=0;
//////			int nk=0,k=0;
//////			if(pulsewidth<=20)nk=3;
//////			else if(pulsewidth<=50)nk=4;
//////			else if(pulsewidth<=100)nk=3;
//////			else if(pulsewidth<=200)nk=12;
//////			else if(pulsewidth<=500)nk=20;
//////			int tt_step=0;
//////			if(pulsewidth<=100)tt_step=step_event;
//////			else tt_step=L_event;
//////			//length_real=length_real+500;
//////			for(i=5;i<length_real;)
//////			{
//////				for(j=i;j<i+tt_step;j++)
//////				{
//////					if(j>length_real)break;
//////					avg_leven=avg_leven+65535-input_data[j];
//////
//////				}
//////				if(j>i)
//////				{
//////					avg_leven=avg_leven/(j-i);
//////					for(j=i;j<i+tt_step-2;j++)
//////					{
//////						//if((65535-input_data[j])>avg_leven+500)
//////						//  if((65535-input_data[j+1])>avg_leven+500)
//////						//	  if((65535-input_data[j+2])>avg_leven+500)
//////						//		 // if((65535-input_data[j+3])>avg_leven+500)
//////						//	  {
//////						//		  if(sGabor_Result.Valid_Num<99)
//////						//		  {
//////						//			  sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=abs(j);
//////						//			  sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=TRUE;
//////						//			  sGabor_Result.Event_type[sGabor_Result.Valid_Num++]='F';
//////						//			  //i=i+j+3;
//////						//			  j=j+5;
//////						//			  continue;
//////						//		  }
//////						//	  }
//////							  for(k=0;k<nk;k++)
//////							  {
//////								  if((65535-input_data[j+k])>avg_leven+500)continue;
//////								  else break;
//////							  }
//////							  if(k>=nk)
//////							  {
//////								  if(sGabor_Result.Valid_Num<99)
//////								  {
//////									  sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=abs(j);
//////									  sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=TRUE;
//////									  sGabor_Result.Event_type[sGabor_Result.Valid_Num++]='F';
//////									  //i=i+j+3;
//////									  j=j+5;
//////									  continue;
//////								  }
//////							  }
//////					}
//////					i=i+tt_step;
//////					//i=i+j+3;
//////				//	continue;
//////				}
//////				else i++;
//////				
//////				
//////
//////			}
//////		}
//////	}
//////	j=sGabor_Result.Valid_Num;
//////	//增加反射事件    20140520删除
//////	//if(return_flag==0)
//////	//{
//////	//	j=0;
//////	//	for(i=0;i<sGabor_Result.Valid_Num;i++)
//////	//	{
//////	//		if(sGabor_Result.Reflect_Type[i]!=0)
//////	//		{
//////	//			int flag=0;
//////	//			for(k=0;k<j;k++)
//////	//			{
//////	//				if(abs(sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[k]<=L_event))
//////	//				{
//////	//					flag=1;
//////	//					break;
//////	//				}
//////
//////
//////	//			}
//////	//			if(flag==0)
//////	//			{
//////
//////	//				sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////	//				sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
//////	//				j++;
//////	//			}
//////
//////	//		}
//////	//	}
//////	//	sGabor_Result.Valid_Num=j;
//////	//}
//////	//	sGabor_Result.Valid_Num=0;
////////return sGabor_Result;
////////	if(return_flag==0&&pulsewidth>=3)//&&pulsewidth>=20加于20130509  、、、衰减事件，脉宽限制  
//////	if(pulsewidth>=3)// 20150804
//////	{
//////		//if(pulsewidth<=10)L_event=2*L_event;
//////		//L_event=3*L_event;
//////
//////		//L_event=step_event/2;
//////		int roias_count=0;
//////		int start_point =L_event;
//////		int end_point =length_real;
//////		int gabor_length=0;
//////		int buff_lenght=L_event+3;
//////
//////		int Large_count_time=0;
//////		int small_count_time=0;
//////
//////		float avg_buff=0;
//////		int No_count=0;
//////		No_count=6;//L_event/10;
//////		//if(No_count<=10)No_count=10;
//////
//////		//double* Gabor_buff=new double[buff_lenght];
//////		//memset(Gabor_buff,0,buff_lenght*sizeof(double));
//////
//////		//int* Gabor_buff=new int[buff_lenght+5];
//////		//memset(Gabor_buff,0,(buff_lenght+5)*sizeof(int));
//////
//////		//int Gabor_buff[10000];
//////
//////		gabor_length=2*(end_point-start_point)/L_event;
//////		int* result_loss=new int[100];//短时傅里叶变化结果Cn
//////		memset(result_loss,0,100*sizeof(int));
//////		int* result_loss2=new int[100];//短时傅里叶变化结果Cn
//////		memset(result_loss2,0,100*sizeof(int));
//////		//int result_loss[200];
//////		//int result_loss2[200];
//////		int result_loss_number=0;
//////		int result_loss_number2=0;
//////		for(i=0;i<gabor_length-1;i++)
//////		{
//////
//////
//////			//for(j=i*L_event;j<(i+1)*L_event+3;j++)//求出平均值
//////			//{
//////			//	avg_buff=avg_buff+65535-input_data[j];
//////			//}
//////			//avg_buff=avg_buff/(L_event+3);
//////			for(j=0;j<L_event;j++)
//////			{
//////				if(i*L_event/2+j+5>length_real)break;
//////				input_data_buff[j]=input_data[i*L_event/2+j+5]-input_data[i*L_event/2+j];///////i*L_event/2+j+5
//////				avg_buff=avg_buff+abs(input_data_buff[j]);
//////				//if(Gabor_buff[j]<10)Gabor_buff[j]=0;
//////			}
//////			if(j!=0)
//////				avg_buff=avg_buff/j;
//////			//	if(wavelength==1310)avg_buff=10;
//////			//	else avg_buff=8;
//////			//avg_buff=10;
//////			for(j=0;j<L_event;j++)
//////			{
//////				if(input_data_buff[j]>=avg_buff/4)
//////				{
//////					Large_count_time++;
//////					roias_count=0;
//////					if(Large_count_time>=No_count)
//////					{
//////						int cccc=0;
//////						int cccc_flag=0;
//////						if(result_loss_number<100)
//////						{
//////
//////							for(k=0;k<result_loss_number;k++)
//////							{
//////								cccc=abs(i*L_event/2+j-Large_count_time-result_loss[k]);
//////								if(cccc<L_event)cccc_flag =1;
//////
//////							}
//////							if(cccc_flag==0)
//////							{
//////								if((i*L_event/2+j-Large_count_time)>L_event/4)///////20131223  step_event/4
//////								{
//////
//////									if(abs(link_point_number-(i*L_event/2+j-Large_count_time))>=L_event/2)
//////										if(result_loss_number<99)
//////											result_loss[result_loss_number++]=i*L_event/2+j-Large_count_time;
//////									Large_count_time=0;
//////									break;
//////								}
//////
//////							}
//////						}
//////
//////						Large_count_time=0;
//////						break;
//////					}
//////
//////				}
//////				else 
//////				{
//////					roias_count++;
//////
//////					if(Large_count_time>=No_count)
//////					{
//////						int cccc=0;
//////						int cccc_flag=0;
//////						if(result_loss_number<100)
//////						{
//////
//////							for(k=0;k<result_loss_number;k++)
//////							{
//////								cccc=abs(i*L_event/2+j-Large_count_time-result_loss[k]);
//////								if(cccc<L_event)cccc_flag =1;
//////
//////							}
//////							if(cccc_flag==0)
//////							{
//////								if((i*L_event/2+j-Large_count_time)>L_event/4)///////20131223  step_event/4
//////								{
//////
//////									if(abs(link_point_number-(i*L_event/2+j-Large_count_time))>=L_event/2)
//////										if(result_loss_number<99)
//////											result_loss[result_loss_number++]=i*L_event/2+j-Large_count_time;
//////									Large_count_time=0;
//////									break;
//////								}
//////
//////							}
//////						}
//////						if(roias_count>=5)
//////						{
//////
//////							Large_count_time=0;
//////							break;
//////						}
//////					}
//////					Large_count_time=0;
//////				}
//////
//////			}
//////		}
//////		//针对衰减事件变步进做第二次查找，然后两次查找的结果进行综合取舍20130628
//////		{
//////			int L_event_buff=2*L_event/3;;
//////			int step_event_buff=2*L_event_buff;
//////			for(i=0;i<gabor_length-1;i++)
//////			{
//////
//////
//////				//for(j=i*L_event;j<(i+1)*L_event+3;j++)//求出平均值
//////				//{
//////				//	avg_buff=avg_buff+65535-input_data[j];
//////				//}
//////				//avg_buff=avg_buff/(L_event+3);
//////				for(j=0;j<L_event_buff;j++)
//////				{
//////					if(i*L_event/2+j+5>length_real)break;
//////					input_data_buff[j]=input_data[i*L_event_buff/2+j+5]-input_data[i*L_event_buff/2+j];///////i*L_event/2+j+5
//////					avg_buff=avg_buff+abs(input_data_buff[j]);
//////					//if(Gabor_buff[j]<10)Gabor_buff[j]=0;
//////				}
//////				if(j!=0)
//////					avg_buff=avg_buff/j;
//////				//	if(wavelength==1310)avg_buff=10;
//////				//	else avg_buff=8;
//////				//avg_buff=10;
//////				for(j=0;j<L_event_buff;j++)
//////				{
//////					if(input_data_buff[j]>=avg_buff/4)
//////					{
//////						Large_count_time++;
//////						roias_count=0;
//////						if(Large_count_time>=No_count)
//////						{
//////							int cccc=0;
//////							int cccc_flag=0;
//////							if(result_loss_number<100)
//////							{
//////
//////								for(k=0;k<result_loss_number;k++)
//////								{
//////									cccc=abs(i*L_event_buff/2+j-Large_count_time-result_loss2[k]);
//////									if(cccc<L_event_buff)cccc_flag =1;
//////
//////								}
//////								if(cccc_flag==0)
//////								{
//////									if((i*L_event_buff/2+j-Large_count_time)>step_event_buff/4)
//////									{
//////
//////										if(abs(link_point_number-(i*L_event_buff/2+j-Large_count_time))>=L_event_buff/2)
//////											if(result_loss_number2<99)
//////												result_loss2[result_loss_number2++]=i*L_event_buff/2+j-Large_count_time;
//////										Large_count_time=0;
//////										break;
//////									}
//////
//////								}
//////							}
//////
//////							Large_count_time=0;
//////							break;
//////						}
//////
//////					}
//////					else 
//////					{
//////						roias_count++;
//////
//////						if(Large_count_time>=No_count)
//////						{
//////							int cccc=0;
//////							int cccc_flag=0;
//////							if(result_loss_number<100)
//////							{
//////
//////								for(k=0;k<result_loss_number;k++)
//////								{
//////									cccc=abs(i*L_event_buff/2+j-Large_count_time-result_loss2[k]);
//////									if(cccc<L_event_buff)cccc_flag =1;
//////
//////								}
//////								if(cccc_flag==0)
//////								{
//////									if((i*L_event_buff/2+j-Large_count_time)>step_event_buff/4)
//////									{
//////
//////										if(abs(link_point_number-(i*L_event_buff/2+j-Large_count_time))>=L_event_buff/2)
//////											if(result_loss_number2<99)
//////												result_loss2[result_loss_number2++]=i*L_event_buff/2+j-Large_count_time;
//////										Large_count_time=0;
//////										break;
//////									}
//////
//////								}
//////							}
//////							if(roias_count>=5)
//////							{
//////
//////								Large_count_time=0;
//////								break;
//////							}
//////						}
//////						Large_count_time=0;
//////					}
//////
//////				}
//////			}
//////		}
//////		//对两次分析出来的衰减事件进行排序
//////		{
//////			int result_loss_data_buff=0;
//////			for(i=0;i<result_loss_number;i++)
//////			{
//////				for(j=i+1;j<result_loss_number;j++)
//////				{
//////					if(result_loss[j]<result_loss[i])
//////					{
//////						result_loss_data_buff=result_loss[i];
//////						result_loss[i]=result_loss[j];
//////						result_loss[j]=result_loss_data_buff;
//////					}
//////				}
//////			}
//////			for(i=0;i<result_loss_number2;i++)
//////			{
//////				for(j=i+1;j<result_loss_number2;j++)
//////				{
//////					if(result_loss2[j]<result_loss2[i])
//////					{
//////						result_loss_data_buff=result_loss2[i];
//////						result_loss2[i]=result_loss2[j];
//////						result_loss2[j]=result_loss_data_buff;
//////					}
//////				}
//////			}
//////
//////		}
//////		//对两次分析出来的衰减事件进行整合取舍
//////		/*{
//////		for(i=0;i<result_loss_number;i++)
//////		{
//////		for(j=0;j<result_loss_number2;j++)
//////		{
//////		if(r)
//////		}
//////		}
//////		}*/
//////
//////		//delete [] Gabor_buff;
//////		//	j=0;
//////		int flag=0;
//////		for(i=0;i<result_loss_number;i++)
//////		{
//////			flag=0;
//////			if(sGabor_Result.Valid_Num<100)
//////			{
//////				for(k=0;k<sGabor_Result.Valid_Num;k++)
//////				{
//////					if(abs(sGabor_Result.Event_Array[k]-result_loss[i])<step_event)
//////					{
//////						flag=1;break;
//////					}
//////				}
//////				if(flag==0)
//////				{
//////					if(sGabor_Result.Valid_Num<99)
//////					{
//////
//////						sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=result_loss[i];
//////						sGabor_Result.Event_Loss[sGabor_Result.Valid_Num]=0;
//////						sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=0;
//////						sGabor_Result.Event_Hight[sGabor_Result.Valid_Num]=0;
//////						sGabor_Result.Total_Loss[sGabor_Result.Valid_Num]=0;
//////						sGabor_Result.Line_k[sGabor_Result.Valid_Num]=0;
//////						sGabor_Result.Event_type[sGabor_Result.Valid_Num]='F';
//////						sGabor_Result.Valid_Num++;
//////					}
//////				}
//////			}
//////
//////
//////		}
//////		flag=0;
//////		for(i=0;i<result_loss_number2;i++)
//////		{
//////			flag=0;
//////			if(sGabor_Result.Valid_Num<100)
//////			{
//////				for(k=0;k<sGabor_Result.Valid_Num;k++)
//////				{
//////					if(abs(sGabor_Result.Event_Array[k]-result_loss2[i])<step_event/2)
//////					{
//////						flag=1;break;
//////					}
//////				}
//////				if(flag==0)
//////				{
//////					if(sGabor_Result.Valid_Num<99)
//////					{
//////
//////						sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=result_loss2[i];
//////						sGabor_Result.Event_Loss[sGabor_Result.Valid_Num]=0;
//////						sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=0;
//////						sGabor_Result.Event_Hight[sGabor_Result.Valid_Num]=0;
//////						sGabor_Result.Total_Loss[sGabor_Result.Valid_Num]=0;
//////						sGabor_Result.Line_k[sGabor_Result.Valid_Num]=0;
//////						sGabor_Result.Event_type[sGabor_Result.Valid_Num]='F';
//////						sGabor_Result.Valid_Num++;
//////					}
//////				}
//////			}
//////
//////
//////		}
//////		delete [] result_loss;
//////		delete [] result_loss2;
//////
//////	}
//////
//////	j=sGabor_Result.Valid_Num;
////// //sGabor_Result.Reflect_Type[1]=1;
//////	i=0;
//////	k=0;
//////	//对事件进行排序
//////	for(i=0;i<sGabor_Result.Valid_Num;i++)
//////	{
//////		for(j=i+1;j<sGabor_Result.Valid_Num;j++)
//////		{
//////			if(sGabor_Result.Event_Array[i]>sGabor_Result.Event_Array[j])
//////			{
//////				data_buff=sGabor_Result.Event_Array[i];
//////				sGabor_Result.Event_Array[i]=sGabor_Result.Event_Array[j];
//////				sGabor_Result.Event_Array[j]=data_buff;
//////
//////				data_buff=sGabor_Result.Reflect_Type[i];
//////				sGabor_Result.Reflect_Type[i]=sGabor_Result.Reflect_Type[j];
//////				sGabor_Result.Reflect_Type[j]=data_buff;
//////
//////				Char_type=sGabor_Result.Event_type[i];
//////				sGabor_Result.Event_type[i]=sGabor_Result.Event_type[j];
//////				sGabor_Result.Event_type[j]=Char_type;
//////
//////				float_type=sGabor_Result.Event_Loss[i];
//////				sGabor_Result.Event_Loss[i]=sGabor_Result.Event_Loss[j];
//////				sGabor_Result.Event_Loss[j]=float_type;
//////
//////				float_type=sGabor_Result.Line_k[i];
//////				sGabor_Result.Line_k[i]=sGabor_Result.Line_k[j];
//////				sGabor_Result.Line_k[j]=float_type;
//////
//////				float_type=sGabor_Result.Event_Hight[i];
//////				sGabor_Result.Event_Hight[i]=sGabor_Result.Event_Hight[j];
//////				sGabor_Result.Event_Hight[j]=float_type;
//////
//////
//////			}
//////		}
//////	}
//////	j=sGabor_Result.Valid_Num;
//////
//////	i=0;
//////	k=0;
//////	if(sGabor_Result.Valid_Num)
//////	{
//////
//////		if(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]>=length_real)
//////		{
//////			sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]=length_real;
//////		}
//////		else if(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+step_event<=length_real)
//////		{
//////			sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=length_real;
//////		}
//////		//else if(sGabor_Result.Valid_Num==1)sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=step_event;//20130710
//////	}
//////	else 
//////	{
//////
//////	}
//////	//对事件进行位置校准
//////	//if(return_flag==0)
//////
//////	if(pulsewidth>=3)
//////	{
//////
//////		if(sGabor_Result.Valid_Num)
//////		{
//////			//int* input_data_buff_statick=new int[2*step_event+2];
//////			//memset(input_data_buff_statick,0,(2*step_event+2)*sizeof(int));
//////			int avg1=0;
//////			int max_count_j=0;
//////			int max_count=0;
//////			for(i=0;i<sGabor_Result.Valid_Num;i++)
//////			{
//////				if(sGabor_Result.Reflect_Type[i]==0&&pulsewidth<=10000)//非反射事件位置校准
//////				{
//////
//////					if(sGabor_Result.Event_Array[i]>L_event/2)
//////					{
//////
//////						if(i==sGabor_Result.Valid_Num-1)break;
//////						for(k=sGabor_Result.Event_Array[i]-L_event/2;k<sGabor_Result.Event_Array[i]+L_event/2-1;k++)
//////						{
//////							input_data_buff[k+L_event/2-sGabor_Result.Event_Array[i]]=input_data[k+1]-input_data[k];
//////							avg1=avg1+input_data_buff[k+L_event-sGabor_Result.Event_Array[i]];
//////						}
//////						avg1=avg1/(L_event-1);
//////						max_count_j=0;
//////
//////						for(k=sGabor_Result.Event_Array[i]-L_event/2;k<sGabor_Result.Event_Array[i]+L_event/2-1;k++)
//////						{
//////							if(input_data_buff[k+L_event/2-sGabor_Result.Event_Array[i]]>avg1/2)
//////							{
//////								max_count_j++;
//////								if(max_count_j>=L_event/8)
//////								{
//////									sGabor_Result.Event_Array[i]=k-max_count_j;
//////									break;
//////								}
//////							}
//////							else max_count_j=0;
//////						}
//////					}
//////					/*if(k==sGabor_Result.Event_Array[i]+L_event/2-1)
//////					sGabor_Result.Event_Array[i]=sGabor_Result.Event_Array[i]+k/2;*/
//////				}
//////				else //if(length_real>sGabor_Result.Event_Array[i]+L_event/8)//反射事件位置校准
//////				{
//////					if(sGabor_Result.Event_Array[i]<10)continue;
//////					int min_data_buff=65535;
//////					int min_data_number=0;
//////					int data_buff_statick=0;
//////					int max_data_reflex=0;
//////					int max_data_reflex_mark_cn=0;
//////					float radio_avg=0;
//////					float data_avg=0;
//////					int mmm=0;
//////					k=L_event/4;
//////					if(k<6)k=6;
//////					mmm=sGabor_Result.Event_Array[i]+k;
//////					if(mmm>length_real)mmm=length_real;
//////					if(sGabor_Result.Event_Array[i]>=length_real)
//////					{
//////						continue;
//////					}
//////					for(j=sGabor_Result.Event_Array[i];j<mmm;j++)
//////					{
//////						data_buff_statick=65535-input_data[j];
//////						if(max_data_reflex<data_buff_statick)
//////						{
//////							max_data_reflex = data_buff_statick;
//////							max_data_reflex_mark_cn=j;
//////						}
//////					}
//////
//////					//if(max_data_reflex_mark_cn=0)
//////					mmm=sGabor_Result.Event_Array[i]-k;
//////					if(mmm<1)mmm=1;
//////					for(j=max_data_reflex_mark_cn;j>mmm;j--)
//////					{
//////						data_buff_statick=65535-input_data[j];
//////						if(min_data_buff>data_buff_statick)
//////						{
//////							min_data_buff = data_buff_statick;
//////							min_data_number=j;
//////						}
//////
//////					}
//////
//////					/*for(j=sGabor_Result.Event_Array[i];j>abs(sGabor_Result.Event_Array[i]-k);j--)
//////					{
//////					data_buff_statick=65535-input_data[j];
//////					if(min_data_buff>data_buff_statick)
//////					{
//////					min_data_buff = data_buff_statick;
//////					min_data_number=j;
//////					}
//////
//////					}
//////					for(j=sGabor_Result.Event_Array[i];j<sGabor_Result.Event_Array[i]+L_event/2;j++)
//////					{
//////					data_buff_statick=65535-input_data[j];
//////					if(max_data_reflex<data_buff_statick)
//////					{
//////					max_data_reflex = data_buff_statick;
//////					max_data_reflex_mark_cn=j;
//////					}
//////					}*/
//////					//求噪声平均值
//////
//////					//int mark_start_cn=0
//////					mmm=min_data_number-10;
//////					if(mmm<1)mmm=1;
//////					for(j=mmm;j<min_data_number;j++)
//////					{
//////						data_buff_statick=input_data[j]-input_data[j-1];
//////						radio_avg=radio_avg+abs(data_buff_statick);
//////						data_avg=data_avg+(65535-input_data[j]);
//////					}
//////					if(min_data_number>mmm)
//////					{
//////						radio_avg=radio_avg/(min_data_number-mmm);
//////						data_avg=data_avg/(min_data_number-mmm);
//////						data_avg=data_avg+2*radio_avg;
//////					}
//////					else 
//////					{
//////						data_avg=0;
//////					}
//////
//////					max_count_j=0;
//////					//找反射峰起始点
//////					for(j=min_data_number;j<max_data_reflex_mark_cn;j++)
//////					{
//////						data_buff_statick=65535-input_data[j];
//////						if(data_buff_statick>=data_avg)max_count_j++;
//////						else max_count_j=0;
//////					}
//////					sGabor_Result.Event_Array[i]=j-max_count_j-1;
//////					if((j-max_count_j-1)<0)sGabor_Result.Event_Array[i]=0;
//////					//sGabor_Result.Event_Array[i]=min_data_number+
//////
//////				}
//////
//////			}
//////			//delete[] input_data_buff_statick;
//////		}
//////	}
//////
//////	//if(sGabor_Result.Valid_Num)
//////	//{
//////	//	j=1;
//////	//	sGabor_Result.Event_Array[0]=sGabor_Result.Event_Array[0];
//////	//	for(i=1;i<sGabor_Result.Valid_Num;i++)
//////	//	{
//////	//		
//////	//		if(sGabor_Result.Reflect_Type[i])
//////	//		{
//////	//			sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////	//			sGabor_Result.Event_Loss[j]=sGabor_Result.Event_Loss[i];
//////	//			sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
//////	//			sGabor_Result.Event_Hight[j]=sGabor_Result.Event_Hight[i];
//////	//			sGabor_Result.Total_Loss[j]=sGabor_Result.Total_Loss[i];
//////	//			sGabor_Result.Line_k[j]=sGabor_Result.Line_k[i];
//////	//			j++;
//////	//		}
//////	//		else
//////	//		{
//////	//			if(sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[i-1]>step_event/2)
//////	//			{
//////	//				sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////	//				sGabor_Result.Event_Loss[j]=sGabor_Result.Event_Loss[i];
//////	//				sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
//////	//				sGabor_Result.Event_Hight[j]=sGabor_Result.Event_Hight[i];
//////	//				sGabor_Result.Total_Loss[j]=sGabor_Result.Total_Loss[i];
//////	//				sGabor_Result.Line_k[j]=sGabor_Result.Line_k[i];
//////	//				j++;
//////	//			}
//////	//		}
//////	//	}
//////	//}
//////
//////	//sGabor_Result.Valid_Num=j;
//////
//////	int up_limit=0;
//////	int low_limit=0;
//////	double line_a=0;
//////	double line_b=0;
//////	double line_c=0;
//////	double line_d=0;
//////
//////
//////	if(step_event<10)step_event=10;
//////	float* sum_k=new float[2000];//短时傅里叶变化结果Cn
//////	memset(sum_k,0,2000*sizeof(float));
//////	//double sum_k[20];
//////	double dB_k_k_1=0;
//////	int Event_start_mark_cn=0;
//////	int Start_event_mark_cn=0;
//////	j=sGabor_Result.Valid_Num;
//////	//	if(j<100)
//////	{
//////		////////////////寻找开始点，去除第一个反射峰
//////		float avg_descore=0;
//////		float data_statick=0;
//////		int less_time=0;
//////		int less_fault_time=0;
//////		int max_mark_cn=0;
//////		int down_flag_time=0;
//////		int up_flag_time=0;
//////		int two_up_mark_cn=0;
//////		int min_data=0;
//////		int min_data_no=0;
//////		int up_time=0;
//////
//////		int first_pulse=0;
//////		int num_count=step_event+3;
//////		if(pulsewidth<200)num_count=step_event+3;
//////		//if(sGabor_Result.Event_Array[1]==0||sGabor_Result.Valid_Num==0)sGabor_Result.Event_Array[1]=2*step_event;//20131218
//////		//else
//////		//{
//////		//	//if(num_count>sGabor_Result.Event_Array[1])num_count=4*step_event+3;
//////		//	//if(num_count>sGabor_Result.Event_Array[1])num_count=3*step_event+3;
//////		//	if(sGabor_Result.Event_Array[1]<=4*L_event/3)num_count=3*L_event/2;
//////		//	else
//////		//	{
//////		//		if(num_count>sGabor_Result.Event_Array[1])num_count=2*step_event+3;
//////		//		if(num_count>sGabor_Result.Event_Array[1])num_count=3*step_event/2+3;
//////		//		if(num_count>sGabor_Result.Event_Array[1])num_count=step_event+3;
//////		//		if(num_count>sGabor_Result.Event_Array[1])num_count=3*step_event/4+3;
//////		//		if(num_count>sGabor_Result.Event_Array[1])num_count=step_event/2+3;
//////		//	}
//////		//	//if(num_count>sGabor_Result.Event_Array[1])num_count=step_event+3;
//////		//}
//////
//////
//////
//////
//////		float max_reflex=0;
//////
//////		int Start_event_time=0;
//////		unsigned long kkkkk=L_event/4;
//////		if(kkkkk<20)kkkkk=20;
//////		int tho_a=kkkkk,tho_b=5,tho_c=10;
//////		if(pulsewidth==3&&Sample_freaq>=400)//短距处理
//////		{
//////			tho_a=2;
//////			tho_b=2;
//////			tho_c=3;
//////		}
//////		for(i=tho_a;i<num_count;i++)
//////		{
//////
//////			input_data_buff[i]=input_data[i+3]-input_data[i];//(input_data[i+7]+input_data[i+6]+input_data[i+5]-(input_data[i+2]+input_data[i+1]+input_data[i]))/3;
//////
//////			if(max_reflex<=(65535-input_data[i]))//查找最高峰
//////			{
//////				if(first_pulse==0)
//////				{
//////					max_reflex=65535-input_data[i];
//////					max_mark_cn=i;
//////					down_flag_time=0;
//////				}
//////				else
//////				{
//////					up_flag_time++;
//////					if(up_flag_time>=tho_b)
//////					{
//////						two_up_mark_cn=i-tho_b;
//////						num_count=two_up_mark_cn;break;
//////					}
//////				}
//////			}
//////			else 
//////			{
//////				if(max_reflex>(65535-input_data[i]+20))//添加与20131219，消除起始峰的封顶毛刺误判断
//////				{
//////					if(input_data[i-1]<input_data[i])
//////						down_flag_time++;
//////				}
//////				//down_flag_time++;
//////				if(down_flag_time>=tho_c)
//////					first_pulse=1;
//////				up_flag_time=0;
//////			}
//////
//////
//////			//if(down_flag_time>=5)break;
//////		}
//////		min_data=65535;
//////		for(i=max_mark_cn;i<num_count;i++)
//////		{
//////			if(min_data>=(65535-input_data[i]))//查找最高峰
//////			{
//////				min_data=65535-input_data[i];
//////				min_data_no=i;
//////				down_flag_time=0;
//////			}
//////			//down_flag_time++;
//////			//if(down_flag_time>=5)break;
//////		}
//////
//////		avg_descore=0;
//////
//////		for(i=max_mark_cn;i<num_count;i++)//寻找最高峰后的自然平滑衰减开始区
//////		{
//////			avg_descore=avg_descore+abs(input_data_buff[i]);
//////			input_data_buff[i]=input_data[i];
//////		}
//////		if(num_count!=max_mark_cn)
//////			avg_descore=avg_descore/(num_count-max_mark_cn);
//////		else avg_descore=abs(input_data_buff[i]);
//////		up_time=L_event/16;
//////		if(up_time<=tho_b)up_time=tho_b;
//////		if(max_mark_cn<L_event)
//////		{
//////
//////		for(i=num_count;i>=max_mark_cn+3;i--)
//////		{
//////			//data_statick=(input_data_buff[i]);
//////			///*if(data_statick<=10)less_time++;                  //2013.04.21
//////			//else if(data_statick>=avg_descore)less_time++;*/
//////			//if(data_statick>avg_descore)less_time++;
//////			//else
//////			//{
//////			//	less_fault_time++;
//////			//	if(less_fault_time>=2)
//////			//	less_time=0;
//////			//}
//////			//if(less_time>=5)
//////			//{
//////			//	Event_start_mark_cn=i+5;//+step_event;
//////			//	Start_event_mark_cn=Event_start_mark_cn;
//////			//	break;
//////			//}
//////			///////////////////////20131217
//////			if(input_data[i]>input_data[i-1]+tho_b)
//////			{
//////				if(input_data[i]>input_data[i-2]+tho_b)
//////					if(input_data[i]>input_data[i-3]+tho_b)
//////						less_time++;
//////					else less_time=0;
//////				else less_time=0;
//////			}
//////			else less_time=0;
//////			if(less_time>=up_time)
//////			{
//////				Event_start_mark_cn=i+up_time;//+step_event;
//////				Start_event_mark_cn=Event_start_mark_cn;
//////				break;
//////			}
//////			//////////////////////////////20131217
//////
//////		}
//////
//////		}
//////
//////		//for(i=num_count;i!=max_mark_cn;i--)
//////		//{
//////		//	if(abs(num_count-max_mark_cn)<10)/////////////2013.04.16
//////		//	{
//////		//		Start_event_mark_cn=max_mark_cn+1;
//////		//		Event_start_mark_cn=Start_event_mark_cn;
//////		//		break;
//////		//	}
//////		//	data_statick=(input_data_buff[i]);
//////		//	if(data_statick>avg_descore)Start_event_time++;
//////		//	else Start_event_time=0;
//////		//	if(Start_event_time>10)
//////		//	{
//////		//		Start_event_mark_cn=i+Start_event_time;
//////		//		Event_start_mark_cn=Start_event_mark_cn;
//////		//		break;
//////		//	}
//////		//}
//////		if(Event_start_mark_cn==0)/////////////////////////////20140111
//////		{
//////			Event_start_mark_cn=max_mark_cn;//two_up_mark_cn;/////////////////修改为20130628
//////			Start_event_mark_cn=Event_start_mark_cn;
//////			//if(Event_start_mark_cn==0)
//////
//////		}
//////		if(Event_start_mark_cn==0)//20130617
//////		{
//////			Event_start_mark_cn=step_event;/////////////////
//////			Start_event_mark_cn=Event_start_mark_cn;
//////			//if(Event_start_mark_cn==0)
//////
//////		}
//////		if(Start_event_mark_cn<L_event/2)
//////		{
//////			Start_event_mark_cn=pulsewidth/40*(Sample_freaq/25);
//////		}
//////		if(pulsewidth<=200)
//////		{
//////			int point_p=0;
//////			if(sGabor_Result.Event_Array[0]-Event_start_mark_cn>2*step_event)
//////				point_p=3*step_event/2;
//////			else if(sGabor_Result.Event_Array[0]-Event_start_mark_cn>step_event)
//////				point_p=step_event;
//////			else point_p=step_event/2;//sGabor_Result.Event_Array[1]-Event_start_mark_cn-step_event/2;
//////			if(Event_start_mark_cn+point_p<sGabor_Result.Event_Array[0])
//////			{
//////				float kkk=0;
//////				float mmm=0;
//////				less_time=0;
//////				int large_time=0;
//////				for(i=Event_start_mark_cn;i<Event_start_mark_cn+point_p/2;i++)
//////				{
//////					input_data_buff[i]=input_data[i+point_p/2]-input_data[i];
//////					kkk=kkk+abs(input_data_buff[i]);
//////				}
//////				kkk=kkk/point_p/2;
//////				for(i=Event_start_mark_cn+point_p/2;i>Event_start_mark_cn;i--)
//////				{
//////					mmm=input_data_buff[i];
//////					if(mmm>kkk+2*avg_descore)
//////						large_time++;
//////					else 
//////					{
//////						less_time++;
//////						if(less_time>=2)
//////						{
//////							large_time=0;
//////							less_time=0;
//////						}
//////					}
//////					if(large_time>=8)
//////					{
//////						Event_start_mark_cn=i+large_time+less_time;
//////						Start_event_mark_cn=Event_start_mark_cn;
//////						break;
//////					}
//////				}
//////			}
//////		}
//////		/////20140111,当第二个反射峰很近时，起始事件适当与第二个反射峰拉开距离
//////		if(two_up_mark_cn!=0)
//////		{
//////			if((Start_event_mark_cn+L_event/4)>=two_up_mark_cn)
//////			{
//////
//////				Start_event_mark_cn=two_up_mark_cn-(two_up_mark_cn-max_mark_cn)/2;
//////			}
//////		}
//////		/*for(i=num_count;i!=max_mark_cn;i--)
//////		{
//////		data_statick=(input_data_buff[i]);
//////		if(data_statick>avg_descore)Start_event_time++;
//////		else Start_event_time=0;
//////		if(Start_event_time>20)
//////		{
//////		Start_event_mark_cn=i+Start_event_time;
//////		Event_start_mark_cn=Start_event_mark_cn;
//////		break;
//////		}
//////		}*/
//////
//////		k=1;
//////		for(i=1;i<sGabor_Result.Valid_Num;i++)
//////		{
//////			if(abs(sGabor_Result.Event_Array[i]-Event_start_mark_cn)>step_event/4||sGabor_Result.Reflect_Type[i]==1)
//////			{
//////				sGabor_Result.Event_Array[k]=sGabor_Result.Event_Array[i];
//////				sGabor_Result.Event_Loss[k]=sGabor_Result.Event_Loss[i];
//////				sGabor_Result.Reflect_Type[k]=sGabor_Result.Reflect_Type[i];
//////				sGabor_Result.Event_Hight[k]=sGabor_Result.Event_Hight[i];
//////				sGabor_Result.Total_Loss[k]=sGabor_Result.Total_Loss[i];
//////				sGabor_Result.Line_k[k]=sGabor_Result.Line_k[i];
//////				k++;
//////			}
//////		}
//////		sGabor_Result.Valid_Num=k;
//////		K_Line_count(L_event,wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		//}
//////	}
//////
//////	//损耗计算,两点法计算
//////	double dB_Hight=0;
//////	double dB_Low=0;
//////	double dB_k_line=0;
//////	int max_data_no=0;
//////	int min_data_no=0;
//////	float max_data=0;
//////	float min_data=0;
//////	double Reflex_avg_dB=0;
//////
//////	if(sGabor_Result.Valid_Num>1)
//////	{
//////		if(sGabor_Result.Valid_Num>=100)sGabor_Result.Valid_Num=99;
//////		for(i=0;i<sGabor_Result.Valid_Num;i++)
//////		{
//////			if(sGabor_Result.Reflect_Type[i])//反射事件
//////			{
//////				//算反射高度
//////				if(i==0)
//////				{
//////					sGabor_Result.Reflect_Type[i]=1;
//////					continue;
//////				}
//////				up_limit=sGabor_Result.Event_Array[i]-step_event/4;
//////				if(up_limit<=3)up_limit=3;
//////				low_limit=sGabor_Result.Event_Array[i]+step_event/2;
//////				max_data=0;
//////				min_data=65535;
//////				for(k=up_limit;k<low_limit;k++)
//////				{
//////					if(max_data<65535-input_data[k])
//////					{
//////						max_data=65535-input_data[k];
//////						max_data_no=k;
//////					}
//////					if(min_data>65535-input_data[k])
//////					{
//////						min_data=65535-input_data[k];
//////						min_data_no=k;
//////					}
//////				}
//////				if(min_data_no<max_data_no)
//////				{
//////					//max_data=0;
//////					min_data=65535;
//////					for(k=up_limit;k<max_data_no;k++)
//////					{
//////						if(min_data>65535-input_data[k])
//////						{
//////							min_data=65535-input_data[k];
//////							min_data_no=k;
//////						}
//////					}
//////				}
//////				if(min_data_no>50)//对最小值做平均处理，消除噪声影响
//////				{
//////					Reflex_avg_dB=0;
//////					for(k=0;k<10;k++)
//////					{
//////						if(min_data_no<k)break;
//////						Reflex_avg_dB=Reflex_avg_dB+65535-input_data[min_data_no-k];
//////					}
//////					Reflex_avg_dB=Reflex_avg_dB/10;
//////					min_data=Reflex_avg_dB;
//////				}
//////
//////				sGabor_Result.Event_Hight[i]=(max_data-min_data)/1000;
//////				//前一个事件也为反射事件，判断两个反射事件的距离是否满足1个波长的距离，如果满足就计算损耗，不满足就
//////				//不计算损耗
//////				if(sGabor_Result.Reflect_Type[i-1]||i==1)
//////				{
//////					if((sGabor_Result.Event_Array[i-1]+step_event)>sGabor_Result.Event_Array[i])
//////					{
//////						sGabor_Result.Event_Loss[i]=0;
//////						//continue;
//////					}
//////				}
//////				//算回波
//////			}
//////			//else//衰减事件  插入损耗计算
//////			{
//////				if(i==sGabor_Result.Valid_Num-1)
//////				{
//////					sGabor_Result.Event_Loss[i]=0;
//////					break;
//////				}
//////				if(sGabor_Result.Line_k[i]>0)dB_k_line=sGabor_Result.Line_k[i];
//////				else if(sGabor_Result.Line_k[i+1]>0)
//////				{
//////					dB_k_line=sGabor_Result.Line_k[i+1];
//////				}
//////				else
//////				{
//////					if(wavelength==1310)dB_k_line=Avg_loss_1310;//1310
//////					else if(wavelength==1490) dB_k_line=Avg_loss_1490;//1550
//////					else if(wavelength==1550) dB_k_line=Avg_loss_1550;//1550
//////					else if(wavelength==1625) dB_k_line=Avg_loss_1625;//1550
//////					else if(wavelength==1300) dB_k_line=Avg_loss_1300;//1550
//////					else if(wavelength==850) dB_k_line=Avg_loss_850;//1550
//////
//////				}
//////				if(i!=0)///?
//////				{
//////
//////					int avg_up=0,avg_low=0;
//////					up_limit=sGabor_Result.Event_Array[i]-step_event/8;
//////					if(up_limit<=3)up_limit=3;
//////					avg_up=input_data[up_limit-3]+input_data[up_limit-2]+input_data[up_limit-1]+input_data[up_limit]+input_data[up_limit+1]+input_data[up_limit+2]+input_data[up_limit+3];
//////					avg_up=avg_up/7;
//////					low_limit=sGabor_Result.Event_Array[i]+step_event;
//////					if(low_limit<=3)low_limit=3;
//////					avg_low=input_data[low_limit-3]+input_data[low_limit-2]+input_data[low_limit-1]+input_data[low_limit]+input_data[low_limit+1]+input_data[low_limit+2]+input_data[low_limit+3];
//////					avg_low=avg_low/7;
//////					dB_Hight=avg_up -avg_low ;
//////					dB_Hight=dB_Hight/1000+1.125*step_event*(Sample_time*Light_fiber_speed)/2000*dB_k_line;
//////					sGabor_Result.Event_Loss[i]=-(dB_Hight);
//////					//if((sGabor_Result.Event_Loss[i])<=0.005)sGabor_Result.Event_Loss[i]=0;
//////					if(sGabor_Result.Reflect_Type[i])
//////					{
//////						//if(sGabor_Result.Event_Loss[i]<=0.005)sGabor_Result.Event_Loss[i]=0;
//////					}
//////					;//算插入损耗	
//////				}
//////				else
//////				{
//////					sGabor_Result.Event_Loss[i]=0;
//////				}
//////
//////			} 
//////
//////		}
//////	}
//////
//////	//利用损耗重新定位衰减事件
//////
//////	if(return_flag==0)
//////	{
//////		int loss_max_cm=0;
//////		float max_loss=0;
//////		float loss_buff=0;
//////		int avg_up=0,avg_low=0;
//////		////删除与20140521，加上时偶尔会出现时间出不来的情况
//////		for(i=0;i<sGabor_Result.Valid_Num-1;i++)
//////		{
//////
//////			loss_max_cm=sGabor_Result.Event_Array[i];
//////			if(sGabor_Result.Line_k[i]>0)dB_k_line=sGabor_Result.Line_k[i];
//////			else if(sGabor_Result.Line_k[i+1]>0)
//////			{
//////				dB_k_line=sGabor_Result.Line_k[i+1];
//////			}
//////			else
//////			{
//////				if(wavelength==1310)dB_k_line=Avg_loss_1310;//1310
//////				else if(wavelength==1490) dB_k_line=Avg_loss_1490;//1550
//////				else if(wavelength==1550) dB_k_line=Avg_loss_1550;//1550
//////				else if(wavelength==1625) dB_k_line=Avg_loss_1625;//1550
//////				else if(wavelength==1300) dB_k_line=Avg_loss_1300;//1550
//////				else if(wavelength==850) dB_k_line=Avg_loss_850;//1550
//////			}
//////
//////			if(sGabor_Result.Reflect_Type[i]==0&&pulsewidth<=20000)/////////////////////
//////			{
//////				for(k=sGabor_Result.Event_Array[i]-L_event/4;k<sGabor_Result.Event_Array[i]+2*L_event;k=k+4)
//////				{
//////
//////					up_limit=k-L_event/4;
//////					if(up_limit<=3)up_limit=3;
//////					avg_up=input_data[up_limit-3]+input_data[up_limit-2]+input_data[up_limit-1]+input_data[up_limit]+input_data[up_limit+1]+input_data[up_limit+2]+input_data[up_limit+3];
//////					avg_up=avg_up/7;
//////					if(pulsewidth>=5000)
//////						low_limit=k+L_event;
//////					else low_limit=k+L_event;
//////					if(low_limit<=3)low_limit=3;
//////					avg_low=input_data[low_limit-3]+input_data[low_limit-2]+input_data[low_limit-1]+input_data[low_limit]+input_data[low_limit+1]+input_data[low_limit+2]+input_data[low_limit+3];
//////					avg_low=avg_low/7;
//////					dB_Hight=avg_up -avg_low ;
//////					dB_Hight=dB_Hight/1000+1.25*L_event*(Sample_time*Light_fiber_speed)/2000*dB_k_line;
//////					loss_buff=-(dB_Hight);
//////					if(loss_buff>max_loss)
//////					{
//////						max_loss=loss_buff;
//////						loss_max_cm=k;
//////
//////					}
//////
//////				}
//////			}
//////			if(loss_max_cm!=sGabor_Result.Event_Array[i])
//////			{
//////				sGabor_Result.Event_Array[i]=loss_max_cm;//-L_event/4;
//////				sGabor_Result.Event_Loss[i]=max_loss;
//////			}
//////
//////		}
//////		//	sGabor_Result=K_Line_count(L_event,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);
//////		Acount_Loss(wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		//对数据进行重新取舍
//////		//事件排序
//////
//////		for(i=0;i<sGabor_Result.Valid_Num;i++)
//////		{
//////			for(j=i+1;j<sGabor_Result.Valid_Num;j++)
//////			{
//////				if(sGabor_Result.Event_Array[i]>sGabor_Result.Event_Array[j])
//////				{
//////					data_buff=sGabor_Result.Event_Array[i];
//////					sGabor_Result.Event_Array[i]=sGabor_Result.Event_Array[j];
//////					sGabor_Result.Event_Array[j]=data_buff;
//////
//////					data_buff=sGabor_Result.Reflect_Type[i];
//////					sGabor_Result.Reflect_Type[i]=sGabor_Result.Reflect_Type[j];
//////					sGabor_Result.Reflect_Type[j]=data_buff;
//////
//////					Char_type=sGabor_Result.Event_type[i];
//////					sGabor_Result.Event_type[i]=sGabor_Result.Event_type[j];
//////					sGabor_Result.Event_type[j]=Char_type;
//////
//////					float_type=sGabor_Result.Event_Loss[i];
//////					sGabor_Result.Event_Loss[i]=sGabor_Result.Event_Loss[j];
//////					sGabor_Result.Event_Loss[j]=float_type;
//////
//////					float_type=sGabor_Result.Line_k[i];
//////					sGabor_Result.Line_k[i]=sGabor_Result.Line_k[j];
//////					sGabor_Result.Line_k[j]=float_type;
//////
//////					float_type=sGabor_Result.Event_Hight[i];
//////					sGabor_Result.Event_Hight[i]=sGabor_Result.Event_Hight[j];
//////					sGabor_Result.Event_Hight[j]=float_type;
//////
//////
//////				}
//////			}
//////		}
//////		//sGabor_Result=Acount_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);
//////		///
//////		j=1;
//////		for(i=1;i<sGabor_Result.Valid_Num;i++)
//////		{
//////			if(sGabor_Result.Reflect_Type[i]==1)
//////			{
//////				sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////				sGabor_Result.Reflect_Type[j]=1;
//////				sGabor_Result.Event_Loss[j]=sGabor_Result.Event_Loss[i];
//////				sGabor_Result.Event_Hight[j]=sGabor_Result.Event_Hight[i];
//////				j++;
//////			}
//////			else
//////			{
//////				if(fabs(sGabor_Result.Event_Loss[i])>=dB_Loss)//损耗过滤判断
//////				{
//////					if(sGabor_Result.Reflect_Type[j-1]==1)/////
//////					{
//////						if(sGabor_Result.Event_Array[i]-step_event/4>=sGabor_Result.Event_Array[j-1])
//////						{
//////							sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////							sGabor_Result.Reflect_Type[j]=0;
//////							sGabor_Result.Event_Loss[j]=sGabor_Result.Event_Loss[i];
//////							j++;
//////						}
//////					}
//////					else
//////					{
//////						if(sGabor_Result.Event_Array[i]-step_event/4>=sGabor_Result.Event_Array[j-1])
//////						{
//////							sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////							sGabor_Result.Reflect_Type[j]=0;
//////							sGabor_Result.Event_Loss[j]=sGabor_Result.Event_Loss[i];
//////							j++;
//////						}
//////						else
//////						{
//////							//if(sGabor_Result.Event_Loss[i]>sGabor_Result.Event_Loss[j-1])
//////							{
//////								/*sGabor_Result.Event_Array[j-1]=sGabor_Result.Event_Array[i];///20131218
//////								sGabor_Result.Reflect_Type[j-1]=0;
//////								sGabor_Result.Event_Loss[j-1]=sGabor_Result.Event_Loss[i];*/
//////							}
//////
//////						}
//////					}
//////				}
//////			}
//////		}
//////		sGabor_Result.Valid_Num=j;
//////		//非反射事件位置再一次校准
//////		
//////		int start_jz_mark=0;
//////		int end_jz_mark=0;
//////		//int* input_data_buff_statick=new int[2*step_event+2];
//////		//memset(input_data_buff_statick,0,(2*step_event+2)*sizeof(int));
//////		int avg_statick=0;
//////		int large_count=0;
//////		int loss_fault=0;
//////		for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////		{
//////			if(sGabor_Result.Reflect_Type[i]==0&&pulsewidth>=3)//非反射事件
//////			{
//////				start_jz_mark=sGabor_Result.Event_Array[i]-step_event/2;
//////				end_jz_mark=sGabor_Result.Event_Array[i]+2*step_event;
//////				//	if(start_jz_mark<sGabor_Result.Event_Array[i-1])continue;
//////				//	if(end_jz_mark>sGabor_Result.Event_Array[i+1])continue;
//////				if(start_jz_mark<=0)continue;
//////				for(j=start_jz_mark;j<end_jz_mark-10;j++)
//////				{
//////					input_data_buff[j-start_jz_mark]=input_data[j+10]-input_data[j];
//////					avg_statick=avg_statick+input_data_buff[j-start_jz_mark];
//////
//////				}
//////				if(j<=start_jz_mark)continue;
//////				avg_statick=avg_statick/(j-start_jz_mark);
//////				for(j=start_jz_mark;j<end_jz_mark-4;j++)
//////				{
//////					if(sGabor_Result.Event_Loss[i]<1)loss_fault=4*avg_statick/3;
//////					else loss_fault=avg_statick;
//////					if(input_data_buff[j-start_jz_mark]>loss_fault)
//////						large_count++;
//////					else large_count=0;
//////					if(large_count>=10)
//////					{
//////						sGabor_Result.Event_Array[i]=j-large_count;
//////						break;
//////					}
//////
//////				}
//////
//////			}
//////		}
//////		//delete[] input_data_buff;
//////		//delete[] input_data_buff_statick;
//////	}
//////
//////
//////
//////
//////	//int Last_reflex_event=0;
//////	//j=1;
//////	//for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////	//{
//////	//	if(sGabor_Result.Reflect_Type[i]==1)
//////	//	{
//////	//		Last_reflex_event=i;
//////	//		sGabor_Result.Reflect_Type[j]=1;
//////	//		sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////	//		j++;
//////	//	}
//////	//	else
//////	//	{
//////	//		if((sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[Last_reflex_event])>step_event)
//////	//		{
//////	//			sGabor_Result.Reflect_Type[j]=0;
//////	//			sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////	//			j++;
//////	//		}
//////	//	}
//////	//}
//////
//////	//sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1];
//////	//sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1];
//////	//j++;
//////	//sGabor_Result.Valid_Num=j;
//////	//去除插入损耗小于0的衰减事件,去除回波损耗>=52的反射事件
//////	int nnn=sGabor_Result.Valid_Num;
//////	k=1;
////////	
//////	Acount_Loss(wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
////////	return sGabor_Result;
//////	//	sGabor_Result=Acount_return_loss(wavelength,pulseWidth,input_data,sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////	for(i=1;i<nnn-1;i++)
//////	{
//////		if(sGabor_Result.Reflect_Type[i]==0)// 衰减事件
//////		{
//////			if(sGabor_Result.Event_Array[i]>Event_start_mark_cn+2*L_event)//20131217
//////			{
//////				sGabor_Result.Event_Array[k]=sGabor_Result.Event_Array[i];
//////				sGabor_Result.Event_Loss[k]=sGabor_Result.Event_Loss[i];
//////				sGabor_Result.Reflect_Type[k]=sGabor_Result.Reflect_Type[i];
//////				sGabor_Result.Event_Hight[k]=sGabor_Result.Event_Hight[i];
//////				sGabor_Result.Total_Loss[k]=sGabor_Result.Total_Loss[i];
//////				sGabor_Result.Line_k[k]=sGabor_Result.Line_k[i];
//////				k++;
//////			}
//////		}
//////		else //反射事件
//////		{
//////			if(sGabor_Result.Event_Array[i]<Event_start_mark_cn+L_event)
//////			{
//////				if(sGabor_Result.Event_Hight[i]>1)
//////				{
//////					sGabor_Result.Event_Array[k]=sGabor_Result.Event_Array[i];
//////					sGabor_Result.Event_Loss[k]=sGabor_Result.Event_Loss[i];
//////					sGabor_Result.Reflect_Type[k]=sGabor_Result.Reflect_Type[i];
//////					sGabor_Result.Event_Hight[k]=sGabor_Result.Event_Hight[i];
//////					sGabor_Result.Total_Loss[k]=sGabor_Result.Total_Loss[i];
//////					sGabor_Result.Line_k[k]=sGabor_Result.Line_k[i];
//////					k++;
//////				}
//////			}
//////			else
//////			{
//////				sGabor_Result.Event_Array[k]=sGabor_Result.Event_Array[i];
//////				sGabor_Result.Event_Loss[k]=sGabor_Result.Event_Loss[i];
//////				sGabor_Result.Reflect_Type[k]=sGabor_Result.Reflect_Type[i];
//////				sGabor_Result.Event_Hight[k]=sGabor_Result.Event_Hight[i];
//////				sGabor_Result.Total_Loss[k]=sGabor_Result.Total_Loss[i];
//////				sGabor_Result.Line_k[k]=sGabor_Result.Line_k[i];
//////				k++;
//////			}
//////
//////		}
//////
//////	}
//////	//末端事件直接加载
//////	if(sGabor_Result.Event_Array[nnn-1]>sGabor_Result.Event_Array[0]+step_event/4)
//////	{
//////
//////		sGabor_Result.Event_Array[k]=sGabor_Result.Event_Array[nnn-1];
//////		sGabor_Result.Event_Loss[k]=sGabor_Result.Event_Loss[nnn-1];
//////		sGabor_Result.Reflect_Type[k]=sGabor_Result.Reflect_Type[nnn-1];
//////		sGabor_Result.Event_Hight[k]=sGabor_Result.Event_Hight[nnn-1];
//////		sGabor_Result.Total_Loss[k]=sGabor_Result.Total_Loss[nnn-1];
//////		sGabor_Result.Line_k[k]=sGabor_Result.Line_k[nnn-1];
//////		k++;
//////	}
//////
//////	sGabor_Result.Valid_Num=k;
//////	
//////	//光纤末端事件加入和事件起始端加入
//////	if(length_real>sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1])
//////		if(length_real-sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]>step_event/2)
//////		{
//////			//加载末端，判断末端事件类型  20140111
//////			float end_event_avg_head=0,end_event_avg_end=0;
//////			float menxian=0;
//////			ratio=0;
//////			sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=length_real;
//////			if(length_real>12&&length_real<input_length-12)
//////			{
//////				for(i=0;i<10;i++)
//////				{
//////					end_event_avg_head=end_event_avg_head+65535-input_data[length_real-2-i];
//////					end_event_avg_end=end_event_avg_end+65535-input_data[length_real+2+i];
//////					input_data_buff[length_real-2-i]=abs(input_data[length_real-2-i]-input_data[length_real-1-i]);
//////					ratio=ratio+input_data_buff[length_real-2-i];
//////				}
//////				ratio=ratio/10;
//////				end_event_avg_head=end_event_avg_head/10;
//////				end_event_avg_end=end_event_avg_end/10;
//////				if(end_event_avg_end>end_event_avg_head+2*ratio)sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]=1;
//////				else sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]=0;
//////			}
//////			
//////		}
//////	sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=Start_event_mark_cn;
//////
//////	//事件排序
//////	//char Char_type=0;
//////	for(i=0;i<sGabor_Result.Valid_Num;i++)
//////	{
//////		for(j=i+1;j<sGabor_Result.Valid_Num;j++)
//////		{
//////			if(sGabor_Result.Event_Array[i]>sGabor_Result.Event_Array[j])
//////			{
//////				data_buff=sGabor_Result.Event_Array[i];
//////				sGabor_Result.Event_Array[i]=sGabor_Result.Event_Array[j];
//////				sGabor_Result.Event_Array[j]=data_buff;
//////
//////				data_buff=sGabor_Result.Reflect_Type[i];
//////				sGabor_Result.Reflect_Type[i]=sGabor_Result.Reflect_Type[j];
//////				sGabor_Result.Reflect_Type[j]=data_buff;
//////
//////				Char_type=sGabor_Result.Event_type[i];
//////				sGabor_Result.Event_type[i]=sGabor_Result.Event_type[j];
//////				sGabor_Result.Event_type[j]=Char_type;
//////
//////
//////			}
//////		}
//////	}
//////
//////
//////
//////	j=0;
//////	for(i=0;i<sGabor_Result.Valid_Num;i++)
//////	{
//////		if(sGabor_Result.Event_Array[i]>=Start_event_mark_cn)
//////		{
//////			if(j)
//////			{
//////				if(sGabor_Result.Reflect_Type[i])
//////				{
//////					sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////					sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
//////					sGabor_Result.Event_type[j++]=sGabor_Result.Event_type[i];
//////				}
//////				else
//////				{
//////					if((sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[j-1])>L_event/2)
//////					{
//////						sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////						sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
//////						sGabor_Result.Event_type[j++]=sGabor_Result.Event_type[i];
//////					}
//////				}
//////			}
//////			else
//////			{
//////
//////				sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////				sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
//////				sGabor_Result.Event_type[j++]=sGabor_Result.Event_type[i];
//////			}
//////
//////		}
//////	}
//////	sGabor_Result.Valid_Num=j;
//////	//对紧随起始端的事件进行位置校准///////20140111取消
//////	//if(return_flag==0)
//////	//{
//////	//	int L_end_point=0;
//////	//	max_data=0;
//////	//	if(sGabor_Result.Valid_Num>2)
//////	//	{
//////	//		if(sGabor_Result.Reflect_Type[1]==1)//其事件必须为反射事件
//////	//		{
//////	//			if((sGabor_Result.Event_Array[1]-sGabor_Result.Event_Array[0])<step_event)//与起始端的距离必须在一个波长之内
//////	//			{
//////	//				L_end_point=sGabor_Result.Event_Array[1]+step_event;
//////	//				if(L_end_point>sGabor_Result.Event_Array[2])L_end_point=sGabor_Result.Event_Array[2];
//////	//				for(i=sGabor_Result.Event_Array[1];i<L_end_point;i++)
//////	//				{
//////	//					data_buff=65535-input_data[i];//input_data[i+1]-input_data[i];
//////	//					if(max_data<data_buff)
//////	//					{
//////	//						max_data=data_buff;
//////	//						max_data_no=i;
//////	//					}
//////	//				}
//////	//				j=max_data_no;
//////	//				max_data=0;
//////	//				L_end_point=j-step_event/16;
//////	//				if((step_event/16)<6)L_end_point=j-6;
//////	//				if(L_end_point<=sGabor_Result.Event_Array[0])L_end_point=sGabor_Result.Event_Array[0];
//////
//////	//				for(i=j;i>L_end_point;i--)//反修正
//////	//				{
//////	//					data_buff=abs(input_data[i]-input_data[i+1]);
//////	//					if(max_data<=data_buff)
//////	//					{
//////	//						max_data=data_buff;
//////	//						max_data_no=i;
//////	//					}
//////	//				}
//////	//				sGabor_Result.Event_Array[1]=max_data_no;
//////	//			}
//////	//		}
//////	//	}
//////	//}
//////
//////	//////////////////////20130617
//////	j=0;
//////	for(i=0;i<sGabor_Result.Valid_Num;i++)
//////	{
//////		if(sGabor_Result.Event_Array[i]>=Start_event_mark_cn)
//////		{
//////			if(j)
//////			{
//////				if(i==sGabor_Result.Valid_Num-1)/////对末端反射事件做保护，以免前面的非反射事件干扰
//////				{
//////					if(sGabor_Result.Reflect_Type[i]==1)
//////					{
//////						sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////						sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
//////						sGabor_Result.Event_type[j++]=sGabor_Result.Event_type[i];
//////					}
//////					else 
//////					{
//////						if((sGabor_Result.Event_Array[i]-length_real)<L_event)
//////						{
//////							sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////							sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
//////							sGabor_Result.Event_type[j++]=sGabor_Result.Event_type[i];
//////						}
//////					}
//////				}
//////				else if(sGabor_Result.Reflect_Type[i])
//////				{
//////					if((sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[j-1])>L_event/4)//20130617
//////					{
//////						sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////						sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
//////						sGabor_Result.Event_type[j++]=sGabor_Result.Event_type[i];
//////					}
//////
//////				}
//////				else
//////				{
//////					if((sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[j-1])>L_event/2)
//////					{
//////						sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////						sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
//////						sGabor_Result.Event_type[j++]=sGabor_Result.Event_type[i];
//////					}
//////				}
//////			}
//////			
//////			else
//////			{
//////
//////				sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////				sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
//////				sGabor_Result.Event_type[j++]=sGabor_Result.Event_type[i];
//////			}
//////
//////		}
//////	}
//////	sGabor_Result.Valid_Num=j;
//////
//////	//*********************************对衰减事件进行位置校准********************/20131212
//////	{
//////		long step_cc=2*L_event;
//////		long start_i=0,end_i=0;
//////		long km=0,kn=0,nn=0;
//////		float avg_niose=0;
//////		//	float step_noise[10000];
//////		float* step_noise=new float[3*step_cc];//短时傅里叶变化结果Cn
//////		memset(step_noise,0,step_cc*sizeof(float));
//////
//////		for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////		{
//////			if(sGabor_Result.Reflect_Type[i])continue;
//////			start_i=sGabor_Result.Event_Array[i]-step_cc;
//////			end_i=sGabor_Result.Event_Array[i]+step_cc+3;
//////			if(start_i<sGabor_Result.Event_Array[i-1])continue;
//////			if(end_i>sGabor_Result.Event_Array[i+1])continue;
//////			for(j=start_i;j<end_i;j++)
//////			{
//////				step_noise[j-start_i]=input_data[j+3]-input_data[j];
//////				avg_niose=avg_niose+fabs(step_noise[j-start_i]);
//////
//////			}
//////			if(end_i<=start_i==0)continue;
//////			avg_niose=avg_niose/(end_i-start_i);
//////			for(nn=3;nn>0;nn--)
//////			{
//////				for(j=0;j<end_i-start_i;j++)
//////				{
//////					if(step_noise[j]<nn*avg_niose/2)
//////					{
//////						km++;
//////						if(km>=2)kn=0;
//////						continue;
//////					}
//////					else
//////					{
//////						km=0;
//////						kn++;
//////						if(kn>=10)
//////						{
//////							sGabor_Result.Event_Array[i]=start_i+j-10;
//////							break;
//////						}
//////					}
//////				}
//////				if(j<end_i-start_i)
//////				{
//////					break;
//////				}
//////			}	
//////
//////		}
//////		delete[] step_noise;
//////		//求出段噪声平均值
//////	}
//////   //对末端为衰减的做定位判断 20150504
//////	if(sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]==0&&sGabor_Result.Valid_Num>=2)
//////	{
//////		float max_kkk=0;
//////		int max_mark=0;
//////		int satrt_point=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-step_event/2;
//////		int end_point= sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+step_event/4;
//////        max_mark=end_point;
//////		for(i=satrt_point;i<end_point-1;i++)
//////		{
//////
//////			sum_k[i-satrt_point]=input_data[end_point]-(input_data[i]+input_data[i+1]+input_data[i+2])/3;
//////			if(sum_k[i-satrt_point]<=0)sum_k[i-satrt_point]=0;
//////			else
//////			{
//////				sum_k[i-satrt_point]=sum_k[i-satrt_point]/(end_point+satrt_point-i);
//////			}
//////		}
//////		for(i=0;i<(end_point-satrt_point);i++)
//////		{
//////			if(max_kkk<=sum_k[i])
//////			{
//////				max_kkk=sum_k[i];
//////				max_mark=i;
//////			}
//////		}
//////		sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]=satrt_point+max_mark;
//////	}
//////
//////	/////////////////////////对过滤后的事件进行计算
//////	sGabor_Result.Line_k[0]=0;
//////
//////	K_Line_count(L_event,wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////	Acount_Loss(wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////
//////
//////
//////	if(sGabor_Result.Valid_Num!=0)
//////	{
//////		if(sGabor_Result.Event_Array[0]<step_event/5)
//////		{
//////
//////			if(sGabor_Result.Event_Array[1]<step_event/2)
//////			{
//////
//////				if((sGabor_Result.Event_Array[1]-sGabor_Result.Event_Array[0])<step_event/4)//step_event*2/3
//////				{
//////
//////					for(j=0;j<sGabor_Result.Valid_Num;j++)
//////					{
//////						sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[j+1];
//////						sGabor_Result.Event_Loss[j]=sGabor_Result.Event_Loss[j+1];
//////						sGabor_Result.Total_Loss[j]=sGabor_Result.Total_Loss[j+1];
//////						sGabor_Result.Event_type[j]=sGabor_Result.Event_type[j+1];
//////						sGabor_Result.Event_Hight[j]=sGabor_Result.Event_Hight[j+1];
//////						sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[j+1];
//////					}
//////					sGabor_Result.Valid_Num=sGabor_Result.Valid_Num-1;
//////				}
//////			}
//////		}
//////	}
//////
//////
//////	if(sGabor_Result.Valid_Num!=0)
//////		sGabor_Result.Event_type[sGabor_Result.Valid_Num-1]='E';
//////	else sGabor_Result.Event_type[0]='E';
//////	sGabor_Result.Event_type[0]='S';
//////	if(sGabor_Result.Valid_Num<99)sGabor_Result.Event_Array[99]=length_real;
//////
//////	delete[] input_data_buff;
//////	delete[] sum_k;
//////	return sGabor_Result;//element_result[1][1];
//////}
//////
//////Gabor_Result gabor_arithmetic(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,double thresholdUpSet,double thresholdDownSet,float dB_Loss,float dB_reflex,float dB_End,float Return_loss_Tybe,float Sample_freaq,float Index_N,int link_point_number)
//////{
//////	float dB_Reflex_loss=0;
//////
//////	if(dB_Loss==0)dB_Loss=0.08;
//////	dB_Reflex_loss=dB_Loss;
//////	if(dB_Reflex_loss<0.1)dB_Reflex_loss=0.1;
//////	if(dB_reflex==0)dB_reflex=0.1;
//////	if(pulseWidth<=20)//对于10ns以内的反射事件做抬高门限处理。2013.04.21
//////	{
//////		if(dB_reflex<=1)dB_reflex=1;
//////		dB_Reflex_loss=0.5;
//////	}
//////    else if(dB_reflex<0.08)dB_reflex=0.08;
//////	int pulseNum=12;
//////	int i=0;
//////	int j=0;
//////	switch(pulseWidth)
//////	{
//////	case 3:
//////		pulseNum=0;
//////		break;
//////	case 5:
//////		pulseNum=1;
//////		break;
//////	case 10:
//////		pulseNum=2;
//////		break;
//////	case 20:
//////		pulseNum=3;
//////		break;
//////	case 50:
//////		pulseNum=4;
//////		break;
//////	case 100:
//////		pulseNum=5;
//////		break;
//////	case 200:
//////		pulseNum=6;
//////		break;
//////	case 500:
//////		pulseNum=7;	
//////		break;
//////	case 1000:
//////		pulseNum=8;
//////		break;
//////	case 2000:
//////		pulseNum=9;
//////		break;
//////	case 5000:
//////		pulseNum=10;
//////		break;
//////	case 10000:
//////		pulseNum=11;
//////		break;
//////	case 20000:
//////		pulseNum=12;
//////		break;
//////	case 30:
//////		pulseNum=13;
//////		break;
//////	case 300:
//////		pulseNum=14;
//////		break;
//////	case 400:
//////		pulseNum=15;
//////		break;
//////	default:pulseNum=12;break;
//////	}
//////
//////
//////
//////	int kk=0;
//////	int delete_data_buff[100];
//////
//////
//////	int lEvent=0;
////////	int imin,imax=0;
//////	int lEventTest=0;
//////	int lEventMax=0;
//////	int lEventMin=0;
//////	int lEventMean=0;
//////	int lEventPartMin=65535;
//////	int lEventPartMinSign=0;
//////	int k=0;
//////	double sumTotalLoss=0;
//////	lEvent=lEventGenerate(pulseNum,wavelength,Sample_freaq);
//////
//////
//////	Gabor_Result sGabor_Result;//
//////
//////	//if(pulseWidth==5)
//////#if FB_OTDR
//////	if(thresholdUpSet==5&&pulseWidth<=5)
//////	{
//////		sGabor_Result=Search_fiber_end_function(wavelength,pulseWidth,input_data,paramLen,Sample_freaq,thresholdUpSet);
//////		K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		Acount_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////		Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		K_Line_limite(wavelength,&sGabor_Result);
////////int kk=0;
//////	//	kk=0;
//////		for(i=1;i<sGabor_Result.Valid_Num;i++)
//////		{
//////			if(sGabor_Result.Event_Hight[i]>=70)delete_data_buff[kk++]=i;
//////
//////		}
//////		for(i=0;i<kk;i++)
//////		{
//////			deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////		}
//////
//////
//////		K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		Acount_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////		Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		K_Line_limite(wavelength,&sGabor_Result);
//////
//////		return sGabor_Result;
//////
//////	}
//////#endif
//////	sGabor_Result=gabor_generate(pulseWidth,wavelength,input_data,paramLen,thresholdUpSet,thresholdDownSet,dB_Loss,dB_reflex,dB_End,Sample_freaq,Index_N,link_point_number);
//////	
////////	return sGabor_Result;//光在光纤中传播的速度
//////	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
//////	//两个数据之间的时间间隔：
//////	double Sample_time=Sample_freaq;//放大了10^6倍
//////	Sample_time=1/Sample_time;
//////
//////	double return_loss=0;
//////
//////	//int pulse_statick=pulseWidth;
//////	//if(pulse_statick<1000)pulse_statick=1000;
//////	//else pulse_statick=pulseWidth;
//////
//////	sumTotalLoss=0;
//////	//***************************************************************//
//////	//**********************加入门限值判断***************************//
//////	float float_data=0;
//////	int event_num=sGabor_Result.Valid_Num;
////////	int kk=0;
////////	int delete_data_buff[100];
//////	int m=0,n=0,delete_flag=0;
//////	
//////
//////	K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////	//sGabor_Result.Event_Array[0]=46;
//////	Acount_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////	//sGabor_Result=Acount_return_loss(wavelength,pulseWidth,input_data,sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////	Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////	K_Line_limite(wavelength,&sGabor_Result);
//////
//////	for(i=1;i<event_num-1;i++)//去除门限之内的事件
//////	{
//////		if(sGabor_Result.Reflect_Type[i]==1)//反射事件
//////		{
//////			//			sGabor_Result.Event_Hight[i]=Return_loss_Tybe+10*log10(pulseWidth/1000.0)+2*sGabor_Result.Event_Hight[i];
//////			float_data=sGabor_Result.Event_Hight[i];
//////
//////			//float_data=sGabor_Result.Event_Hight[i];
//////			if(float_data<fabs(dB_reflex))
//////			{
//////				//sGabor_Result=deleteEvent(i-kk,wavelength,pulsewidthbox,data_from_file,sGabor_Result);
//////				if(sGabor_Result.Event_Loss[i]<dB_Reflex_loss)
//////				{
//////
//////					delete_data_buff[kk]=i;
//////					kk++;
//////
//////				}
//////
//////			}
//////			//else if(fabs(sGabor_Result.Event_Loss[i])<fabs(dB_Loss))
//////			//{
//////			//	//sGabor_Result=deleteEvent(i-kk,wavelength,pulsewidthbox,data_from_file,sGabor_Result);
//////			//	delete_data_buff[kk]=i;
//////			//	kk++;
//////			//}
//////		}
//////		else
//////		{
//////			if(fabs(sGabor_Result.Event_Loss[i])<=fabs(dB_Loss)||sGabor_Result.Event_Loss[i]<=0)
//////			{
//////				//sGabor_Result=deleteEvent(i-kk,wavelength,pulsewidthbox,data_from_file,sGabor_Result);
//////				delete_data_buff[kk]=i;
//////				kk++;
//////			}
//////			else if(i>1)
//////			{
//////				for(m=0;m<i-1;m++)
//////				{
//////					delete_flag=0;
//////					for(n=0;n<kk;n++)//
//////					{
//////						if(m==delete_data_buff[n])//如果已经列入删除表格，就不做计算，否则要做距离是否满足的判断20130617
//////						{
//////							delete_flag=1;
//////							break;
//////						}
//////					}
//////					if(delete_flag==0)//如果该事件的剧距离离前面保留事件非常近，做事件删除处理。20130617
//////					{
//////						if(abs(sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[m])<lEvent)
//////						{
//////							delete_data_buff[kk]=i;
//////							kk++;
//////						}
//////					}
//////				}
//////
//////			}
//////		}
//////	}
//////	for(i=0;i<kk;i++)
//////	{
//////		delete_data_buff[kk+1]=0;//当中间变量使用
//////		for(j=0;j<kk-i-1;j++)
//////		{
//////			if (delete_data_buff[j]>delete_data_buff[j+1])
//////			{
//////				delete_data_buff[kk+1]=delete_data_buff[j];
//////				delete_data_buff[j]=delete_data_buff[j+1];
//////				delete_data_buff[j+1]=delete_data_buff[kk+1];
//////
//////			}
//////		}
//////	}
//////	for(i=0;i<kk;i++)
//////	{
//////		deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////	}
//////
//////	//删除拼接点位置事件
//////	if(link_point_number>1000)
//////	{
//////
//////		int min_data_link=128000;
//////		int min_data_link_number=0;
//////		int min_data_buff=0;
//////
//////
//////		int for_number=sGabor_Result.Valid_Num;
//////		kk=0;
//////		for(i=0;i<for_number;i++)
//////		{
//////			min_data_buff=abs(sGabor_Result.Event_Array[i]-link_point_number);
//////			if(min_data_buff<2*lEvent)
//////			{
//////				if(sGabor_Result.Reflect_Type[i]==1)
//////				{
//////					if(min_data_buff<lEvent/2)
//////					{
//////						delete_data_buff[kk]=i;
//////						kk++;
//////					}
//////				}
//////				else
//////				{
//////					if(link_point_number<sGabor_Result.Event_Array[i])
//////					{
//////						if(min_data_buff<2*lEvent&&fabs(sGabor_Result.Event_Loss[i])<=0.02)
//////						{
//////							delete_data_buff[kk]=i;
//////							kk++;
//////						}
//////					}
//////					else
//////					{
//////						if(min_data_buff<lEvent)
//////						{
//////							delete_data_buff[kk]=i;
//////							kk++;
//////						}
//////					}
//////				}
//////			}
//////			//if(sGabor_Result.Reflect_Type[i])
//////		}
//////		for(i=0;i<kk;i++)
//////		{
//////			delete_data_buff[kk+1]=0;//当中间变量使用
//////			for(j=0;j<kk-i-1;j++)
//////			{
//////				if (delete_data_buff[j]>delete_data_buff[j+1])
//////				{
//////					delete_data_buff[kk+1]=delete_data_buff[j];
//////					delete_data_buff[j]=delete_data_buff[j+1];
//////					delete_data_buff[j+1]=delete_data_buff[kk+1];
//////
//////				}
//////			}
//////		}
//////		for(i=0;i<kk;i++)
//////		{
//////			delete_data_buff[kk+1]=0;//当中间变量使用
//////			for(j=0;j<kk-i-1;j++)
//////			{
//////				if (delete_data_buff[j]>delete_data_buff[j+1])
//////				{
//////					delete_data_buff[kk+1]=delete_data_buff[j];
//////					delete_data_buff[j]=delete_data_buff[j+1];
//////					delete_data_buff[j+1]=delete_data_buff[kk+1];
//////
//////				}
//////			}
//////		}
//////		for(i=0;i<kk;i++)
//////		{
//////			deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////		}
//////
//////
//////	}
//////	k=1;
//////	for(i=1;i<sGabor_Result.Valid_Num;i++)
//////	{
//////		if(sGabor_Result.Event_Array[i]>=sGabor_Result.Event_Array[i-1]+1)
//////		{
//////			sGabor_Result.Event_Array[k]=sGabor_Result.Event_Array[i];
//////			sGabor_Result.Event_Loss[k]=sGabor_Result.Event_Loss[i];
//////			sGabor_Result.Total_Loss[k]=sGabor_Result.Total_Loss[i];
//////			sGabor_Result.Event_type[k]=sGabor_Result.Event_type[i];
//////			sGabor_Result.Event_Hight[k]=sGabor_Result.Event_Hight[i];
//////			sGabor_Result.Reflect_Type[k]=sGabor_Result.Reflect_Type[i];
//////			k++;
//////		}
//////	}
//////	sGabor_Result.Valid_Num=k;
//////	//杂波判断
//////	//
//////	if(sGabor_Result.Valid_Num>=3&&pulseWidth>=3)
//////	{
//////
//////		int step_cc=lEvent;
//////		//	step_cc=pulseWidth/25*(Sample_freaq/25)/3;
//////		if(step_cc<=16)step_cc=16;
//////		int data_fork=0;
//////		int count_time=0;
//////		int fault_time=0;
//////		int I_for_time=sGabor_Result.Valid_Num-1;
//////		int max_fork=0;
//////		if(paramLen<3000)kk=200;
//////		else kk=500;
//////		int radio=0;
//////        int end_radio=0;
//////
//////		//int* data_Loss_buff=new int[4*lEvent];
//////		//memset(data_Loss_buff,0,4*lEvent*sizeof(int));
//////		int data_Loss_buff;
//////		float data_loss_avg=0;
//////		int mm=0,nn=0,jj=0;
//////
//////		int up_time=0;
//////		int up_flag=0;
//////
//////
//////		for(i=paramLen-3;i>paramLen-3-kk;i--)
//////		{
//////			radio=radio+(65535-input_data[i]);
//////		}
//////		radio=radio/kk;
//////		if(radio<1000)radio=1000; 
//////		if(radio>3000)radio=2000;/////////////20140111
//////		//增加事件点前驱背景噪声的阈值加载判断
//////		float radio_event=0;
//////		int mmnn=0;
//////
//////		end_radio=radio;
//////		for(i=I_for_time;i!=0;i--)
//////		{
//////			if(sGabor_Result.Reflect_Type[i])//反射事件，峰的宽度要达到半个步进
//////			{
//////				radio_event=0;
//////				mmnn=0;
//////				//增加事件点前驱背景噪声的阈值加载判断
//////				if(pulseWidth>=20)
//////				{
//////					if(sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[i-1]>20)
//////					{
//////						for(mmnn=sGabor_Result.Event_Array[i]-10;mmnn<sGabor_Result.Event_Array[i]-2;mmnn++)
//////						{
//////							radio_event=radio_event+abs((input_data[mmnn]-input_data[mmnn-1]));
//////						}
//////						radio_event=radio_event/8;
//////					}
//////				}
//////
//////				data_fork=0;
//////				count_time=0;
//////				for(j=sGabor_Result.Event_Array[i]-5;j<(sGabor_Result.Event_Array[i]-1);j++)
//////				{
//////
//////					if(65535-input_data[j]>0)
//////					{
//////						count_time++;
//////						data_fork=data_fork+(65535-input_data[j]);
//////					}
//////				}
//////				if(count_time!=0)data_fork=data_fork/count_time;
//////				else data_fork=65535-input_data[sGabor_Result.Event_Array[i]-1];
//////				count_time=0;
//////				if(data_fork<=radio)data_fork=radio+500;
//////				//if(data_fork>=2*radio+500)continue;
//////				up_flag=0;
//////				up_time=0;
//////				for(j=sGabor_Result.Event_Array[i]+2;j<(sGabor_Result.Event_Array[i]+2*step_cc);j++)
//////				{
//////					if(j>=paramLen-100)break;
//////					if(data_fork+2*radio_event<65535-input_data[j])
//////					{
//////						up_flag++;
//////						up_time=0;
//////						count_time++;
//////						if(count_time>=step_cc/8+1)continue;
//////					}
//////					else 
//////					{
//////						if(up_flag>=step_cc/8)
//////						{
//////
//////							up_time++;
//////							if(up_time>=5)
//////								//count_time=0;
//////								break;
//////						}
//////					}
//////
//////				}
//////				/*if(count_time<step_cc/8)
//////				{
//////				sGabor_Result=deleteEvent(i,wavelength,pulseWidth,input_data,sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////				}*/
//////				if(count_time<step_cc/8)////////////////20130718防止为接头反射非常小，但衰减比较大，免删除
//////				{
//////
//////					if(wavelength==1310)data_loss_avg=Avg_loss_1310;
//////					else if(wavelength==1490)data_loss_avg=Avg_loss_1490;
//////					else if(wavelength==1550)data_loss_avg=Avg_loss_1550;
//////					else if(wavelength==1625)data_loss_avg=Avg_loss_1625;
//////					else if(wavelength==1300)data_loss_avg=Avg_loss_1300;
//////					else if(wavelength==850)data_loss_avg=Avg_loss_850;
//////					else data_loss_avg=Avg_loss_1550;
//////					data_loss_avg=data_loss_avg*step_cc*(Sample_time*Light_fiber_speed)/2000;
//////					if(sGabor_Result.Event_Loss[i]<data_loss_avg)
//////					{
//////						if(sGabor_Result.Reflect_Type[i]==1&&i==sGabor_Result.Valid_Num-1)continue;
//////						deleteEvent_New(i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////					}
//////				}
//////
//////
//////			}
//////			else//衰减事件
//////			{
//////				data_fork=0;
//////				count_time=0;
//////				if(sGabor_Result.Event_Array[i]<2*lEvent)//sGabor_Result.Event_Array[0]+
//////				{
//////					deleteEvent_New(i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////					continue;
//////				}
//////				for(j=sGabor_Result.Event_Array[i]-5;j<(sGabor_Result.Event_Array[i]-1);j++)
//////				{
//////
//////					if(65535-input_data[j]>0)
//////					{
//////						count_time++;
//////						data_fork=data_fork+(65535-input_data[j]);
//////					}
//////				}
//////				if(count_time!=0)data_fork=data_fork/count_time;
//////				else data_fork=65535-input_data[sGabor_Result.Event_Array[i]-1];
//////				count_time=0;
//////				//if(data_fork<=radio)data_fork=radio+500;
//////				if(data_fork<=2*radio+500)
//////				{
//////					deleteEvent_New(i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////					continue;
//////				}
//////				for(j=sGabor_Result.Event_Array[i]+2;j<(sGabor_Result.Event_Array[i]+step_cc);j++)
//////				{
//////					if(data_fork>65535-input_data[j])
//////					{
//////						fault_time=0;
//////						count_time++;
//////						if(count_time>=step_cc/4+1)break;
//////					}
//////					else 
//////					{
//////						fault_time++;
//////						if(fault_time>=3)
//////							count_time=0;
//////						//break;
//////					}
//////
//////				}
//////				if(count_time<step_cc/4)
//////				{
//////				//	deleteEvent_New(i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////					continue;
//////				}
//////				//如果衰减事件的前端曲线比较光滑，衰减事件有效，否则衰减事件无效
//////				//取半个步进，                                                    //20130421
//////				if(i>1)
//////				{
//////					if(sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[i-1]<3*lEvent)
//////					{
//////						if(sGabor_Result.Event_Hight[i-1]<35&&(sGabor_Result.Event_Hight[i-1]!=0))
//////
//////						{
//////							if((65535-input_data[sGabor_Result.Event_Array[i]]-2*end_radio)<1000)
//////							{
//////								deleteEvent_New(i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////							    continue;
//////							}
//////						}
//////						
//////						
//////					}
//////					else
//////					{
//////						mm=sGabor_Result.Event_Array[i]-2*lEvent;
//////						nn=sGabor_Result.Event_Array[i]-lEvent;
//////						data_Loss_buff=0;
//////						if(mm<=0||nn<=0)continue;
//////						for(jj=mm;jj<nn;jj++)
//////						{
//////							data_Loss_buff=data_Loss_buff+abs(input_data[jj]-input_data[jj+lEvent/2]);
//////						}
//////						data_Loss_buff=data_Loss_buff/lEvent;
//////						if(pulseWidth==100) ///////////////20150728
//////						{
//////							if(data_Loss_buff>300*1.5&&sGabor_Result.Event_Loss[i]<0.1)
//////							{
//////								deleteEvent_New(i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////								continue;
//////							}
//////							else if(data_Loss_buff>500*1.5&&sGabor_Result.Event_Loss[i]<0.3)
//////							{
//////								deleteEvent_New(i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////								continue;
//////							}
//////						}
//////						else
//////						{
//////							if(data_Loss_buff>300&&sGabor_Result.Event_Loss[i]<0.1)
//////							{
//////								deleteEvent_New(i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////								continue;
//////							}
//////							else if(data_Loss_buff>500&&sGabor_Result.Event_Loss[i]<0.4)
//////							{
//////								deleteEvent_New(i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////								continue;
//////							}
//////						}
//////
//////
//////					}
//////				}
//////
//////
//////
//////			}
//////
//////		}
//////		//delete[] data_Loss_buff;
//////	}
//////	///////鬼影判断，以及消除鬼影
//////	if(sGabor_Result.Valid_Num>2)
//////	{
//////		//首先判断距离是否有成倍数关系，对成倍数的关系的点做标记
//////		//噪声幅度计算
//////		if(paramLen>2000)kk=300;
//////		else kk=200;
//////		int noise=0;
//////		int noise_s=0;
//////		int sample_point =0;
//////		int freaq_num=Sample_freaq/25;
//////		switch(freaq_num)
//////		{
//////		case 1:sample_point=2;break;
//////		case 2:sample_point=4;break;
//////		case 4:sample_point=4;break;
//////		case 8:sample_point=4;break;
//////		case 16:sample_point=4;break;
//////		default:sample_point=3;break;
//////		}
//////
//////		for(i=0;i<kk;i++)
//////		{
//////			noise=noise+abs(input_data[paramLen-i-1]-input_data[paramLen-i-2]);
//////			noise_s=noise_s+(65535-input_data[paramLen-i-1]);
//////		}
//////		noise=noise/kk;//噪声区噪声高度
//////		noise_s=noise_s/kk;
//////		if(noise_s<=1000)noise_s=1500;
//////		else if(noise_s>3000)noise_s=2000;//////20140108  3000
//////		int flag_point[100];
////////		int flex_flag[100];
//////		int flex_flag_point=0;
//////		int data_fork=0;
//////		if(sGabor_Result.Valid_Num==3)
//////		{
//////			data_fork=65535-(input_data[sGabor_Result.Event_Array[2]-4]+input_data[sGabor_Result.Event_Array[2]-3]+input_data[sGabor_Result.Event_Array[2]-2]+input_data[sGabor_Result.Event_Array[2]-1])/4;
//////			if((2*noise+2*noise_s)>(data_fork))//事件点信号幅度接近噪声区
//////			{
//////				flag_point[0]=abs(sGabor_Result.Event_Array[2]-2*sGabor_Result.Event_Array[1]);
//////				if(flag_point[0]<=sample_point)//判断最后一个事件是否为鬼影，4个采样点之内认为为鬼影
//////				{
//////					deleteEvent_New(2,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////
//////				}
//////			}
//////
//////		}
//////		else//
//////		{
//////			////
//////
//////			int k1=0,k2=0,k3=0;
//////			for(i=1;i<sGabor_Result.Valid_Num;i++)//找起始反射点
//////			{
//////				if(sGabor_Result.Event_Hight[i]!=0)
//////				{
//////					k1=i;
//////					break;
//////				}
//////			}
//////			k3=sGabor_Result.Valid_Num-1;
//////			for(i=sGabor_Result.Valid_Num-2;i>0;i--)//找最后两个反射事件
//////			{
//////				if(sGabor_Result.Event_Hight[i]!=0)
//////				{
//////					//if(k3==0)k3=i;
//////					//else 
//////					{
//////						k2=i;break;
//////					}
//////				}
//////			}
//////			if(k2==k1){k2=0;}
//////			if(k3!=k1)//最少有两个反射事件
//////			{
//////				if(k2==0)
//////				{
//////					data_fork=65535-(input_data[sGabor_Result.Event_Array[k3]-4]+input_data[sGabor_Result.Event_Array[k3]-3]+input_data[sGabor_Result.Event_Array[k3]-2]+input_data[sGabor_Result.Event_Array[k3]-1])/4;
//////					if((2*noise+noise_s)>(data_fork))//事件点信号幅度接近噪声区
//////					{
//////						flag_point[0]=abs(sGabor_Result.Event_Array[k3]-2*sGabor_Result.Event_Array[k1]);
//////						if(flag_point[0]<=sample_point)//判断最后一个事件是否为鬼影，4个采样点之内认为为鬼影
//////						{
//////							deleteEvent_New(k3,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////
//////						}
//////					}
//////				}
//////				else
//////				{
//////					flag_point[0]=sGabor_Result.Event_Array[k1];
//////					flag_point[1]=abs(sGabor_Result.Event_Array[k2]-sGabor_Result.Event_Array[k1]);
//////					flag_point[2]=abs(sGabor_Result.Event_Array[k3]-sGabor_Result.Event_Array[k2]);
//////					if(abs(flag_point[2]-flag_point[0])<=sample_point)//最后一个反射事件满足鬼影条件
//////					{
//////						data_fork=65535-(input_data[sGabor_Result.Event_Array[k3]-4]+input_data[sGabor_Result.Event_Array[k3]-3]+input_data[sGabor_Result.Event_Array[k3]-2]+input_data[sGabor_Result.Event_Array[k3]-1])/4;
//////						if((2*noise+noise_s)>(data_fork))
//////						{
//////							deleteEvent_New(k3,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////							if(abs(flag_point[1]-flag_point[0])<=sample_point)
//////							{
//////								data_fork=65535-(input_data[sGabor_Result.Event_Array[k2]-4]+input_data[sGabor_Result.Event_Array[k2]-3]+input_data[sGabor_Result.Event_Array[k2]-2]+input_data[sGabor_Result.Event_Array[k2]-1])/4;
//////								if((2*noise+noise_s)>(data_fork))
//////									deleteEvent_New(k2,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////							}
//////
//////						}
//////
//////					}
//////					else
//////					{
//////						flag_point[2]=abs(sGabor_Result.Event_Array[k3]-sGabor_Result.Event_Array[k1]);
//////						if(abs(flag_point[2]-flag_point[0])<=sample_point)//最后一个反射事件满足鬼影条件
//////						{
//////
//////							data_fork=65535-(input_data[sGabor_Result.Event_Array[k3]-4]+input_data[sGabor_Result.Event_Array[k3]-3]+input_data[sGabor_Result.Event_Array[k3]-2]+input_data[sGabor_Result.Event_Array[k3]-1])/4;
//////							if((2*noise+noise_s)>(data_fork))
//////								deleteEvent_New(k3,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////						}
//////						else
//////						{
//////							if(abs(flag_point[1]-flag_point[0])<=sample_point)
//////							{
//////								data_fork=65535-(input_data[sGabor_Result.Event_Array[k2]-4]+input_data[sGabor_Result.Event_Array[k2]-3]+input_data[sGabor_Result.Event_Array[k2]-2]+input_data[sGabor_Result.Event_Array[k2]-1])/4;
//////								if((2*noise+noise_s)>(data_fork))
//////									deleteEvent_New(k2,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////							}
//////						}
//////					}
//////				}
//////			}
//////		}
//////		if(pulseWidth>=3&&pulseWidth<1000)
//////		{
//////			//计算事件的前段信号噪声，判断事件是否是在噪声中，如果是在噪声中，就做鬼影处理
//////			int ii=0,jj=0,kk=0;
//////			int avg_roise_event=0,avg_roise_h=0;
//////			int CC=0;
//////			CC=sGabor_Result.Valid_Num;
//////			for(j=2;j<CC;j++)
//////			{
//////
//////				ii=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1];
//////				jj=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2];
//////				if((ii-jj)>=100)kk=50;
//////				else kk=20;
//////				if(kk<=(ii-jj))
//////				{
//////					for(i=0;i<kk;i++)
//////					{
//////						avg_roise_event=avg_roise_event+(65535-input_data[ii-i]);//信号高度
//////						avg_roise_h=avg_roise_h+abs(input_data[ii-i]-input_data[ii-i-2]);
//////					}
//////					avg_roise_event=avg_roise_event/kk;
//////					avg_roise_h=avg_roise_h/kk;
//////					if(avg_roise_h<500)avg_roise_h=500;
//////					if(avg_roise_event<(noise_s+2*avg_roise_h))//噪声区中的事件
//////					{
//////						//sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]=0;
//////						//sGabor_Result=deleteEvent(sGabor_Result.Valid_Num-1,wavelength,pulseWidth,input_data,sGabor_Result,Index_N,Sample_freaq);
//////						/*for(i=0;i<sGabor_Result.Valid_Num-1;i++)
//////						{
//////						if(sGabor_Result.Event_Array[j])
//////						}*/
//////						if(abs(ii-2*jj)<5*sample_point)deleteEvent_New(sGabor_Result.Valid_Num-1,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////
//////					}
//////				}
//////			}
//////
//////		}
//////
//////	}
//////	Acount_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////
//////	//反射峰下降沿上的事件判断
//////
//////
//////	//对末端判断是否是由于大的反射峰的下降而造成的误判
//////	{
//////
//////
//////		float loss_dB_statick=0;
//////		float noise_buff=0;
//////		float Event_buff=0;
//////		int m=0;
//////		int Length_step=0;
//////		if(pulseWidth<=200)Length_step=14*lEvent;
//////		else Length_step=10*lEvent;
//////		if(sGabor_Result.Valid_Num>2)
//////		{
//////			if(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]>3*lEvent)
//////			{
//////				if(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2]>2*lEvent)
//////				{
//////					if(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2]<5*lEvent)
//////					{
//////						//loss_dB_statick=(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]]-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-2*lEvent])/1000;
//////						loss_dB_statick=(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-2*lEvent]+
//////							input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-2*lEvent+1]+input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-2*lEvent+2]+
//////							input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-2*lEvent-1]+input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-2*lEvent]-2)/5;
//////						loss_dB_statick=(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]]-loss_dB_statick)/1000;
//////						if(loss_dB_statick>2)///////////////////////////////////////删除于20131219
//////						{
//////							//如果后面的反射峰比前面的反射峰高度要大很多，就保留后面的反射峰
//////							//if(sGabor_Result.Event_Hight[sGabor_Result.Valid_Num-1]<sGabor_Result.Event_Hight[sGabor_Result.Valid_Num-2]+2)
//////							//	sGabor_Result=deleteEvent(sGabor_Result.Valid_Num-1,wavelength,pulseWidth,input_data,sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////						}
//////						else
//////						{
//////							noise_buff=0;
//////							for(m=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-1;m>sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-lEvent/4;m--)
//////							{
//////								noise_buff=noise_buff+abs(input_data[m]-input_data[m-1]);
//////							}
//////							noise_buff=noise_buff/(lEvent/4-1);
//////							//	if(noise_buff>100)sGabor_Result=deleteEvent(sGabor_Result.Valid_Num-1,wavelength,pulseWidth,input_data,sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////						}
//////						if(sGabor_Result.Valid_Num)
//////							sGabor_Result.Event_type[sGabor_Result.Valid_Num-1]='E';
//////					}
//////					else if(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2]<Length_step)
//////					{
//////						if(sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]==0)
//////						{
//////							for(m=paramLen-1;m>paramLen-501;m--)
//////							{
//////								noise_buff=noise_buff+(65535-input_data[m]);
//////							}
//////							noise_buff=noise_buff/500;
//////							Event_buff=(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]]+input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-1]+input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+1])/3;
//////							Event_buff=65535-Event_buff;
//////
//////							if(Event_buff<3*noise_buff)
//////								deleteEvent_New(sGabor_Result.Valid_Num-1,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////							else
//////							{
//////								noise_buff=0;
//////								for(m=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-1;m>sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-lEvent/4;m--)
//////								{
//////									noise_buff=noise_buff+abs(input_data[m]-input_data[m-1]);
//////								}
//////								noise_buff=noise_buff/(lEvent/4-1);
//////								if(noise_buff>100)deleteEvent_New(sGabor_Result.Valid_Num-1,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////							}
//////						}
//////						else //反射事件，求反射事件前的噪声，如果反射事件的高度，低于反射事件前的噪声的两倍，就认为是噪声干扰
//////						{
//////							noise_buff=0;
//////							for(i=0;i<5;i++)
//////								noise_buff=noise_buff+abs(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-1-i]-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-3-i]);
//////							noise_buff=noise_buff/5000;
//////							if(sGabor_Result.Event_Hight[sGabor_Result.Valid_Num-1]<2*noise_buff)
//////								deleteEvent_New(sGabor_Result.Valid_Num-1,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////
//////						}
//////					}
//////				}
//////				else//衰减事件距离过短
//////				{
//////					if(sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]==0)
//////						deleteEvent_New(sGabor_Result.Valid_Num-1,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////					else if(pulseWidth>=100)
//////					{
//////						if(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2]<=lEvent)
//////						{
//////							if(sGabor_Result.Event_Hight[sGabor_Result.Valid_Num-1]<0.5)
//////								deleteEvent_New(sGabor_Result.Valid_Num-1,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////						}
//////							
//////					}
//////				}
//////			}
//////			if(pulseWidth>=1000)//消除反射峰后的误判断的衰减事件
//////			{
//////				j=0;
//////				int KK=sGabor_Result.Valid_Num;
//////				for(i=1;i<KK;i++)
//////				{
//////					if(sGabor_Result.Reflect_Type[i]==0)
//////					{
//////						if(sGabor_Result.Reflect_Type[i-1])
//////						{
//////							if(i==1)
//////							{
//////								if(sGabor_Result.Event_Array[i]<2*lEvent)
//////								{
//////
//////									delete_data_buff[j]=i;
//////									j++;
//////								}
//////							}
//////							else if(sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[i-1]<2*lEvent)
//////							{
//////
//////								delete_data_buff[j]=i;
//////								j++;
//////							}
//////						}
//////					}
//////				}
//////				kk=j;
//////				for(i=0;i<kk;i++)
//////				{
//////					delete_data_buff[kk+1]=0;//当中间变量使用
//////					for(j=0;j<kk-i-1;j++)
//////					{
//////						if (delete_data_buff[j]>delete_data_buff[j+1])
//////						{
//////							delete_data_buff[kk+1]=delete_data_buff[j];
//////							delete_data_buff[j]=delete_data_buff[j+1];
//////							delete_data_buff[j+1]=delete_data_buff[kk+1];
//////
//////						}
//////					}
//////				}
//////				kk=j;
//////				for(i=0;i<kk;i++)
//////				{
//////					delete_data_buff[kk+1]=0;//当中间变量使用
//////					for(j=0;j<kk-i-1;j++)
//////					{
//////						if (delete_data_buff[j]>delete_data_buff[j+1])
//////						{
//////							delete_data_buff[kk+1]=delete_data_buff[j];
//////							delete_data_buff[j]=delete_data_buff[j+1];
//////							delete_data_buff[j+1]=delete_data_buff[kk+1];
//////
//////						}
//////					}
//////				}
//////				for(i=0;i<j;i++)
//////				{
//////					deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////				}
//////			}
//////		}
//////	}
//////	if(sGabor_Result.Valid_Num>=3)
//////		if(sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]!=0&&sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-2]!=0)
//////		{
//////			if(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2]<lEvent/4)
//////				deleteEvent_New(sGabor_Result.Valid_Num-1,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);	
//////		}
//////		/////////////////////////////////////////////////////////////
//////		//对最后一个事件进行噪声分析，看其是否处于噪声中，如处于噪声中，需要做鬼影判断。
//////
//////		/////////////////////////////////////////////////////////////////////
//////
//////
//////		//////////////////////////////事件过滤
//////		float_data=0;
//////		event_num=sGabor_Result.Valid_Num;
//////		kk=0;
//////		m=0;n=0;delete_flag=0;
//////
//////		for(i=1;i<event_num-1;i++)//去除门限之内的事件
//////		{
//////			if(sGabor_Result.Reflect_Type[i]==1)//反射事件
//////			{
//////				//			sGabor_Result.Event_Hight[i]=Return_loss_Tybe+10*log10(pulseWidth/1000.0)+2*sGabor_Result.Event_Hight[i];
//////				float_data=sGabor_Result.Event_Hight[i];
//////
//////				//float_data=sGabor_Result.Event_Hight[i];
//////				if(float_data<fabs(dB_reflex))
//////				{
//////					//sGabor_Result=deleteEvent(i-kk,wavelength,pulsewidthbox,data_from_file,sGabor_Result);
//////					if(sGabor_Result.Event_Loss[i]<dB_Reflex_loss)
//////					{
//////
//////						delete_data_buff[kk]=i;
//////						kk++;
//////
//////					}
//////
//////				}
//////
//////			}
//////			else
//////			{
//////				if(fabs(sGabor_Result.Event_Loss[i])<=fabs(dB_Loss)||sGabor_Result.Event_Loss[i]<=0)
//////				{
//////					//sGabor_Result=deleteEvent(i-kk,wavelength,pulsewidthbox,data_from_file,sGabor_Result);
//////					delete_data_buff[kk]=i;
//////					kk++;
//////				}
//////
//////				else if(i>1)
//////				{
//////					for(m=0;m<i-1;m++)
//////					{
//////						delete_flag=0;
//////						for(n=0;n<kk;n++)//
//////						{
//////							if(m==delete_data_buff[n])//如果已经列入删除表格，就不做计算，否则要做距离是否满足的判断20130617
//////							{
//////								delete_flag=1;
//////								break;
//////							}
//////						}
//////						if(delete_flag==0)//如果该事件的剧距离离前面保留事件非常近，做事件删除处理。20130617
//////						{
//////							if(abs(sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[m])<lEvent)
//////							{
//////								delete_data_buff[kk]=i;
//////								kk++;
//////							}
//////						}
//////					}
//////
//////				}
//////			}
//////		}
//////		for(i=0;i<kk;i++)
//////		{
//////			delete_data_buff[kk+1]=0;//当中间变量使用
//////			for(j=0;j<kk-i-1;j++)
//////			{
//////				if (delete_data_buff[j]>delete_data_buff[j+1])
//////				{
//////					delete_data_buff[kk+1]=delete_data_buff[j];
//////					delete_data_buff[j]=delete_data_buff[j+1];
//////					delete_data_buff[j+1]=delete_data_buff[kk+1];
//////
//////				}
//////			}
//////		}
//////		for(i=0;i<kk;i++)
//////		{
//////			deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////		}
//////
//////		K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////
//////		if(sGabor_Result.Valid_Num)
//////			sGabor_Result.Event_type[sGabor_Result.Valid_Num-1]='E';
//////
//////		K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		//sGabor_Result.Event_Array[0]=46;
//////		Acount_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////		Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		K_Line_limite(wavelength,&sGabor_Result);
//////		//末端衰减事件的判断
//////		if(sGabor_Result.Valid_Num>2)
//////		{
//////			int last_reflex_num=0;
//////			//寻找最后一个反射事件
//////			for(i=sGabor_Result.Valid_Num-1;i>0;i--)
//////			{
//////				if(sGabor_Result.Reflect_Type[i]!=0)break;
//////			}
//////			last_reflex_num=i;
//////			float Loss_buff_avg=0;
//////			float Avg_lEvent_loss=0;
//////			for(i=0;;i++)
//////			{
//////				if(sGabor_Result.Valid_Num>2)
//////				{
//////					if(last_reflex_num==sGabor_Result.Valid_Num-1)break;
//////					if(sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]==0)
//////					{
//////						if((sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]<sGabor_Result.Event_Array[last_reflex_num]+10*lEvent))
//////						{
//////							Loss_buff_avg=0;
//////							for(j=0;j<5;j++)
//////							{
//////								Loss_buff_avg=Loss_buff_avg+(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-j]-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-lEvent-j]);
//////							}
//////							Loss_buff_avg=Loss_buff_avg/5000;
//////							if(wavelength==1310)Avg_lEvent_loss=Avg_loss_1310*lEvent*(Sample_time*Light_fiber_speed)/2000;
//////							else if (wavelength==1490)Avg_lEvent_loss=Avg_loss_1490*lEvent*(Sample_time*Light_fiber_speed)/2000;
//////							else if (wavelength==1550)Avg_lEvent_loss=Avg_loss_1550*lEvent*(Sample_time*Light_fiber_speed)/2000;
//////							else if(wavelength==1625)Avg_lEvent_loss=Avg_loss_1625*lEvent*(Sample_time*Light_fiber_speed)/2000;
//////							else if(wavelength==1300)Avg_lEvent_loss=Avg_loss_1300*lEvent*(Sample_time*Light_fiber_speed)/2000;
//////							else if(wavelength==850)Avg_lEvent_loss=Avg_loss_850*lEvent*(Sample_time*Light_fiber_speed)/2000;
//////							else Avg_lEvent_loss=Avg_loss_1550*lEvent*(Sample_time*Light_fiber_speed)/2000;
//////							if(Loss_buff_avg>=2*Avg_lEvent_loss)
//////								deleteEvent_New(sGabor_Result.Valid_Num-1,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////							else break;
//////						}
//////						else break;
//////					}
//////					else break;
//////				}
//////				else break;
//////			}
//////
//////
//////
//////		}
//////
//////		K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		//sGabor_Result.Event_Array[0]=46;
//////		float Return_loss_Tybe_status=0;
//////		if(wavelength==1310)Return_loss_Tybe_status=Return_loss_1310_tybe;
//////		else if(wavelength==1490)Return_loss_Tybe_status=Return_loss_1490_tybe;
//////		else if(wavelength==1550)Return_loss_Tybe_status=Return_loss_1550_tybe;
//////		else if(wavelength==1625)Return_loss_Tybe_status=Return_loss_1625_tybe;
//////		else if(wavelength==1300)Return_loss_Tybe_status=Return_loss_1300_tybe;
//////		else if(wavelength==850)Return_loss_Tybe_status=Return_loss_850_tybe;
//////		else Return_loss_Tybe_status=Return_loss_1550_tybe;
//////		Acount_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		//sGabor_Result=Acount_return_loss(wavelength,pulseWidth,input_data,sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe_status);
//////		//sGabor_Result=Acount_Total_Loss(wavelength,pulseWidth,input_data,sGabor_Result,Index_N,Sample_freaq);
//////		//sGabor_Result=K_Line_limite(wavelength,sGabor_Result);
//////		if(pulseWidth<=50)
//////		{
//////			float dB_mxz=0;
//////			if(pulseWidth==3)dB_mxz=2;
//////			else if(pulseWidth==5)dB_mxz=0;
//////			else if(pulseWidth==10)dB_mxz=1.5;
//////			else if(pulseWidth==20)dB_mxz=1;
//////			else if(pulseWidth==30)dB_mxz=1;
//////			else if(pulseWidth==50)dB_mxz=0.4;
//////			else if(pulseWidth==100)dB_mxz=0.2;
//////			else if(pulseWidth==200)dB_mxz=0.2;
//////			else dB_mxz=dB_Reflex_loss;
//////			kk=0;
//////			for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////			{
//////				if(sGabor_Result.Reflect_Type[i]!=0)
//////				{
//////					if(sGabor_Result.Event_Hight[i]<=dB_mxz)
//////					{
//////						delete_data_buff[kk++]=i;
//////						;
//////					}
//////				}
//////			}
//////			for(i=0;i<kk;i++)
//////			{
//////				delete_data_buff[kk+1]=0;//当中间变量使用
//////				for(j=0;j<kk-i-1;j++)
//////				{
//////					if (delete_data_buff[j]>delete_data_buff[j+1])
//////					{
//////						delete_data_buff[kk+1]=delete_data_buff[j];
//////						delete_data_buff[j]=delete_data_buff[j+1];
//////						delete_data_buff[j+1]=delete_data_buff[kk+1];
//////
//////					}
//////				}
//////			}
//////			for(i=0;i<kk;i++)
//////			{
//////				deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////			}
//////		}
//////		////////////////////////////////////////////////////////添加与20131219，用于消除反射峰后的衰减事件的误判断，典型例子，1550，100ns，5km情况
//////		////float max_fulse=0;
//////		////long max_fulse_cm=0;
//////		////if(sGabor_Result.Valid_Num>2)
//////		////{
//////		////	j=sGabor_Result.Valid_Num;
//////		////	for(i=j-1;i!=0;i--)
//////		////	{
//////		////		if(sGabor_Result.Reflect_Type[i]==0)
//////		////		{
//////		////			for(k=i-1;k!=0;k--)
//////		////			{
//////		////				if(sGabor_Result.Reflect_Type[k])
//////		////					break;
//////		////			}
//////		////			if(k==0)break;
//////		////			else
//////		////			{
//////		////				for(n=sGabor_Result.Event_Array[i];n>sGabor_Result.Event_Array[i-1]-lEvent/4;n--)
//////		////				{
//////		////					if(max_fulse<(65536-input_data[n]))
//////		////					{
//////		////						max_fulse=65536-input_data[n];
//////		////						max_fulse_cm=n;
//////		////					}
//////		////				}
//////		////				if(input_data[sGabor_Result.Event_Array[i]-3]-input_data[max_fulse_cm]>400)
//////		////					if(input_data[sGabor_Result.Event_Array[i]-4]-input_data[max_fulse_cm-1]>400)
//////		////						if(input_data[sGabor_Result.Event_Array[i]-5]-input_data[max_fulse_cm-2]>400)
//////		////							deleteEvent_New(i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////		////			}
//////		////		}
//////		////	}
//////
//////		////}
//////		if(sGabor_Result.Valid_Num>=3)//////20140111,用于消除起始峰后的可能引起的第一个误判断的非反射事件
//////		{
//////			float avg_loss=0;
//////			if(sGabor_Result.Reflect_Type[1]==0)
//////			{
//////				if(sGabor_Result.Event_Array[1]-sGabor_Result.Event_Array[0]<2*sGabor_Result.Event_Array[0])
//////				{
//////					avg_loss=input_data[sGabor_Result.Event_Array[1]]-input_data[sGabor_Result.Event_Array[0]];
//////					avg_loss=avg_loss/((sGabor_Result.Event_Array[1]-sGabor_Result.Event_Array[0])*(Sample_time*Light_fiber_speed)/2);
//////					if(avg_loss>0.5)
//////					{
//////						if(sGabor_Result.Event_Loss[1]<0.3)
//////							deleteEvent_New(1,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////					}
//////				}
//////			}
//////		}
//////		////鬼影判断
//////		//if(sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]==1)
//////		//{
//////		//	K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		//	Acount_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		//	Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////		//	Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		//	K_Line_limite(wavelength,&sGabor_Result);
//////		//	float end_radio=0;
//////		//	int doint=2;
//////		//	for(i=paramLen-3;i>paramLen-203;i--)
//////		//	{
//////		//		if(i<0)break;
//////		//		end_radio=end_radio+65535-input_data[i];
//////		//	}
//////		//	end_radio=end_radio/200;
//////		//	if(end_radio<=1500)end_radio=1500;
//////		//	if((65535-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-1])<2*end_radio)
//////		//	{
//////		//		if(sGabor_Result.Line_k[2]==0)
//////		//		{
//////		//			doint=3;
//////		//			for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////		//			{
//////		//				if(sGabor_Result.Reflect_Type[i]==1)
//////		//				{
//////		//					if(sGabor_Result.Event_Array[i]*2>=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-doint&&sGabor_Result.Event_Array[i]*2<=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+doint)
//////		//					{
//////		//						//符合鬼影条件
//////		//						sGabor_Result.Valid_Num=i+1;
//////		//						break;
//////		//					}
//////		//				}
//////		//			}
//////		//		}
//////		//	}
//////
//////
//////		//}
//////		///////////////////////////////////////////////////
//////		//FB-OTDR的小脉宽判断
//////#if 0
//////		{
//////
//////		float f_data_buff=0;
//////		float avg_noise=0;
//////		int up_count=0;
//////		float db_refex_thoed=0,db_refex_thoed_ff;
//////		int step_ccc=0,step_ddd=0;
//////		if(pulseWidth<=10)
//////		{
//////			db_refex_thoed_ff=500;
//////			step_ccc=3;
//////		}
//////		else if(pulseWidth<=20)
//////		{
//////			db_refex_thoed_ff=1000;
//////			step_ccc=6;
//////		}
//////		else if(pulseWidth<=100)
//////		{
//////			db_refex_thoed_ff=100;
//////			step_ccc=12;
//////		}
//////		else if(pulseWidth<=500)
//////		{
//////			db_refex_thoed_ff=100;
//////			step_ccc=10;
//////		}
//////		else if(pulseWidth<=2000)
//////		{
//////			db_refex_thoed_ff=100;
//////			step_ccc=30;
//////		}
//////		else 
//////		{
//////			db_refex_thoed_ff=100;
//////			step_ccc=50;
//////		}
//////		step_ddd=10;
//////		if(Sample_freaq>400)step_ddd=40;
//////		if(pulseWidth<=5000&&sGabor_Result.Valid_Num>2)
//////		{
//////		    ////对每一个反射事件做伪判断
//////
//////			kk=0;
//////			for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////			{
//////				if(sGabor_Result.Reflect_Type[i]!=0)
//////				{
//////					avg_noise=0;
//////					for(j=0;j<5;j++)
//////					{
//////						avg_noise=avg_noise+abs(input_data[sGabor_Result.Event_Array[i]-j]-input_data[sGabor_Result.Event_Array[i]-j-1]);
//////					}
//////					avg_noise=avg_noise/5;
//////					db_refex_thoed=db_refex_thoed_ff+3*avg_noise;
//////					for(j=1;;)
//////					{
//////						if((sGabor_Result.Event_Array[i]+j)>paramLen-2)break;
//////					   f_data_buff=input_data[sGabor_Result.Event_Array[i]-2]-input_data[sGabor_Result.Event_Array[i]+j];
//////						if(f_data_buff>db_refex_thoed)
//////						{
//////							up_count++;
//////						}
//////						else up_count=0;
//////						if(up_count>=step_ccc)break;
//////						if(j>=step_ddd&&up_count==0)
//////						{
//////							if(sGabor_Result.Event_Loss[i]>0)
//////							delete_data_buff[kk++]=i;
//////							j=0;
//////							break;
//////						}
//////						j++;
//////					}
//////				}
//////				
//////			}
//////			for(i=0;i<kk;i++)
//////			{
//////				deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////			}
//////			
//////
//////		}
//////		if(pulseWidth<=1000&&sGabor_Result.Valid_Num>1)//&&sGabor_Result.Valid_Num==2)
//////		{
//////			//for(k=0;k<sGabor_Result.Valid_Num;k++)
//////			kk=0;
//////            avg_noise=0;
//////			for(j=0;j<5;j++)
//////			{
//////				avg_noise=avg_noise+abs(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-j]-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-j-1]);
//////			}
//////			avg_noise=avg_noise/5;
//////			if((65535-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]])>=10000)avg_noise=100;
//////			db_refex_thoed=db_refex_thoed_ff+avg_noise;
//////			for(j=1;;)
//////			{
//////				if((sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+j)>paramLen)break;
//////				f_data_buff=input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]]-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+j];
//////				if(f_data_buff>db_refex_thoed)
//////				{
//////					up_count++;
//////				}
//////				else up_count=0;
//////				if(up_count>=step_ccc)break;
//////				if(j>=step_ddd)
//////				{
//////					if(up_count<step_ccc)
//////					{
//////						if(sGabor_Result.Event_Hight[sGabor_Result.Valid_Num-1]<(db_refex_thoed/1000))
//////						{
//////							delete_data_buff[kk++]=i;
//////						}
//////					}
//////					
//////					break;
//////				}
//////				j++;
//////			}
//////			if(kk)//末端不满足反射条件，判断其是否为非反射
//////			{
//////
//////				for(j=1;;)
//////				{
//////					if((sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+j)>paramLen)break;
//////					f_data_buff=input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+j]-(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]]+input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-1]+input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+1])/3;
//////					if(f_data_buff>500)
//////					{
//////						up_count++;
//////					}
//////					else up_count=0;
//////					if(up_count>=step_ccc)break;
//////					if(j>=step_ccc&&up_count==0)
//////					{
//////						kk=2;
//////						break;
//////					}
//////					j++;
//////				}
//////				if(kk==2)
//////				{
//////					sGabor_Result.Valid_Num--;
//////				}
//////
//////			}
//////		}
//////
//////
//////		//全部为非反射事件
//////		if(pulseWidth<=50&&sGabor_Result.Valid_Num>1)
//////		{
//////			float avg_noise=0;
//////			float loss_up=0,loss_down=0;
//////			for(i=1;i<sGabor_Result.Valid_Num;i++)
//////				if(sGabor_Result.Reflect_Type[i]!=0)break;
//////			if(i==sGabor_Result.Valid_Num)
//////			{
//////				kk=0;
//////				for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////				{
//////					//求事件点附近的噪声
//////					for(j=sGabor_Result.Event_Array[i]-10;j<sGabor_Result.Event_Array[i]+10;j++)
//////					{
//////						avg_noise=avg_noise+abs(input_data[j+2]-input_data[j]);
//////					}
//////					avg_noise=avg_noise/19;
//////					for(j=sGabor_Result.Event_Array[i]-10;j<sGabor_Result.Event_Array[i];j++)
//////					{
//////						loss_up=loss_up+input_data[j];
//////					}
//////					loss_up=65535-loss_up/10;
//////					for(j=sGabor_Result.Event_Array[i];j<sGabor_Result.Event_Array[i]+10;j++)
//////					{
//////						loss_down=loss_down+input_data[j];
//////					}
//////					loss_down=65535-loss_down/10;
//////					if((loss_up-loss_down)<=5*avg_noise)
//////					{
//////						delete_data_buff[kk++]=i;
//////						continue;
//////					}
//////
//////				}
//////				for(i=0;i<kk;i++)
//////				{
//////					deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////				}
//////			}
//////		}
//////
//////
//////		if(pulseWidth<=50&&sGabor_Result.Valid_Num==2)
//////		{
//////			kk=0;
//////
//////			for(j=1;;)
//////			{
//////				if((sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+j)>paramLen)break;
//////				f_data_buff=input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]]-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+j];
//////				
//////				if(f_data_buff>db_refex_thoed)
//////				{
//////					up_count++;
//////				}
//////				else up_count=0;
//////				if(up_count>=step_ccc)break;
//////				if(j>=10&&up_count==0)
//////				{
//////					delete_data_buff[kk++]=i;
//////					break;
//////				}
//////				j++;
//////			}
//////			if(kk)//末端不满足反射条件，判断其是否为非反射
//////			{
//////
//////				for(j=1;;)
//////				{
//////					if((sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+j)>paramLen)break;
//////					f_data_buff=input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+j]-(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]]+input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-1]+input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+1])/3;
//////					if(f_data_buff>1000)
//////					{
//////						up_count++;
//////					}
//////					else up_count=0;
//////					if(up_count>=step_ccc)break;
//////					if(j>=step_ccc&&up_count==0)
//////					{
//////						kk=2;
//////						break;
//////					}
//////					j++;
//////				}
//////				if(kk==2)
//////				{
//////					sGabor_Result.Valid_Num--;
//////				}
//////
//////			}
//////		}
//////		}
//////#endif
////////		sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=120;
////////		sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=6;
////////sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=19;
///////////////////////////////////////////////////////////////////////
//////	//if(sGabor_Result.Valid_Num==1&&sGabor_Result.Event_Array[0]>lEvent&&sGabor_Result.Reflect_Type[0]==TRUE)
//////	/*{
//////		sGabor_Result.Valid_Num++;
//////		sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=sGabor_Result.Event_Array[0];
//////		sGabor_Result.Event_Array[0]=lEvent;
//////		sGabor_Result.Event_type[sGabor_Result.Valid_Num-1]='E';
//////		sGabor_Result.Event_type[0]='S';
//////		sGabor_Result.Reflect_Type[1]=TRUE;
//////		sGabor_Result.Reflect_Type[0]=0;
//////	}*/
//////	/*sGabor_Result=K_Line_count(L_event,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);
//////	sGabor_Result=Acount_Total_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);*/
//////	//if(pulseNum<=50&&sGabor_Result.Valid_Num>=2)//////判断是否是空测
//////	//{
//////	//	if(sGabor_Result.Event_Array[0]>=2*lEvent&&sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]!=TRUE)//起始事件过大，空测拖尾现象
//////	//	{
//////	//		if(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]<=35*lEvent)
//////	//		{
//////	//			sGabor_Result.Valid_Num=1;
//////	//		}
//////	//	}
//////	//	else if(sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]==TRUE)
//////	//	{
//////	//		if(sGabor_Result.Event_Array[0]>=4*lEvent)sGabor_Result.Valid_Num=1;
//////	//	}
//////	//}
//////		//////////////////////////////////////////////////////////////////////////////////////////////////////////////		
//////
//////	//	sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=24759;
//////		//		sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=120;
////////		sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=6;
////////sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=19;
//////
//////
////////反射事件定位是否处于峰上的判断
//////		if(sGabor_Result.Valid_Num>1&&pulseWidth>=20)
//////		{
//////
//////			float min_data=65535,avg_data=0;
//////			int min_data_mark=0,avg_data_mark=0;
//////			for(i=1;i<sGabor_Result.Valid_Num;i++)
//////			{
//////				if(sGabor_Result.Reflect_Type!=0)
//////				{
//////
//////					/*if(sGabor_Result.Event_Array[i]>=5)
//////					{
//////						avg_data=input_data[sGabor_Result.Event_Array[i]-5]+input_data[sGabor_Result.Event_Array[i]-4];
//////						avg_data=avg_data+input_data[sGabor_Result.Event_Array[i]-3];
//////						avg_data=avg_data+input_data[sGabor_Result.Event_Array[i]-2];
//////						avg_data=avg_data+input_data[sGabor_Result.Event_Array[i]-1];
//////						avg_data=avg_data/5;
//////						avg_data=65535-avg_data;
//////						avg_data_mark=sGabor_Result.Event_Array[i];
//////						for(j=sGabor_Result.Event_Array[i]+1;j>sGabor_Result.Event_Array[i]-5;j--)
//////						{
//////							min_data=65535-input_data[j];
//////							if(avg_data>=min_data)
//////							{
//////								//min_data=65535-input_data[j];
//////								//min_data_mark=j;
//////								avg_data_mark=j;
//////								break;
//////							}
//////						}
//////						//if(min_data_mark<sGabor_Result.Event_Array[i])sGabor_Result.Event_Array[i]=avg_data_mark-1;
//////						sGabor_Result.Event_Array[i]=avg_data_mark-1;
//////					 }*/
//////					if(sGabor_Result.Event_Array[i]>=5)
//////					{
//////						avg_data=65535-input_data[sGabor_Result.Event_Array[i]];
//////						avg_data_mark=sGabor_Result.Event_Array[i];
//////						for(j=sGabor_Result.Event_Array[i];j>sGabor_Result.Event_Array[i]-5;j--)
//////						{
//////							min_data=65535-input_data[j];
//////							if(min_data<avg_data-200)
//////							{
//////								avg_data=min_data;
//////								avg_data_mark=j;
//////							}
//////							else if(min_data>65535-input_data[j+1]+10)
//////							{
//////								break;
//////							}
//////						}
//////					}
//////					if(min_data_mark<=sGabor_Result.Event_Array[i])sGabor_Result.Event_Array[i]=avg_data_mark-1;
//////				//	sGabor_Result.Event_Array[i]=avg_data_mark-1;
//////
//////				}
//////			}
//////
//////		}
//////		K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		Acount_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////		Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		K_Line_limite(wavelength,&sGabor_Result);
//////		//三个事件点的鬼影判断
//////		if(sGabor_Result.Valid_Num==3)
//////		{
//////			float end_radio=0;
//////			int doint=2;
//////			for(i=paramLen-3;i>paramLen-203;i--)
//////			{
//////				if(i<0)break;
//////				end_radio=end_radio+65535-input_data[i];
//////			}
//////			end_radio=end_radio/200;
//////			if(end_radio<=1500)end_radio=1500;
//////			if(sGabor_Result.Reflect_Type[1]!=0&&sGabor_Result.Reflect_Type[2]!=0)
//////			{
//////				if((65535-input_data[sGabor_Result.Event_Array[2]])<3000)doint=3;
//////				if(2*sGabor_Result.Event_Array[1]>=sGabor_Result.Event_Array[2]-doint&&2*sGabor_Result.Event_Array[1]<=sGabor_Result.Event_Array[2]+doint)
//////				{
//////					if(sGabor_Result.Line_k[2]==0)
//////					{
//////						if(input_data[sGabor_Result.Event_Array[2]-5]-input_data[sGabor_Result.Event_Array[1]-5]>2000)
//////						{
//////							sGabor_Result.Valid_Num=2;
//////						    sGabor_Result.Event_type[1]='E';
//////						}
//////					}
//////					
//////				}
//////			}
//////		}
//////		//鬼影判断
//////		if(sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]==1&&sGabor_Result.Valid_Num>=3)
//////		{
//////			K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////			Acount_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////			Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////			Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////			K_Line_limite(wavelength,&sGabor_Result);
//////			float end_radio=0;
//////			long avg_single=0;
//////			int mm_rn=0;
//////			int doint=3;
//////			float dB_loss_F1_F2,distance_F1_F2=0;
//////			float Light_fiber_speed=300/Index_N;
//////			float K1_K2_lamda=0;
//////			float KK1=0;
//////			float single_head_radio=0;
//////			float F1_F2_LOSS=0;
//////			switch(wavelength)
//////			{
//////			case 850:
//////				K1_K2_lamda=Avg_loss_850;
//////				break;
//////			case 1300:
//////				K1_K2_lamda=Avg_loss_1300;
//////				break;
//////			case 1310:
//////				K1_K2_lamda=Avg_loss_1310;
//////				break;
//////			case 1490:
//////				K1_K2_lamda=Avg_loss_1490;
//////				break;
//////			case 1550:
//////				K1_K2_lamda=Avg_loss_1550;
//////				break;
//////			case 1625:
//////				K1_K2_lamda=Avg_loss_1625;
//////				break;
//////			}
//////			for(i=paramLen-3;i>paramLen-203;i--)
//////			{
//////				if(i<0)break;
//////				end_radio=end_radio+65535-input_data[i];
//////			}
//////			end_radio=end_radio/200;
//////			if(end_radio<=1500)end_radio=1500;
//////			for(i=0;i<20;i++)
//////			{
//////			  single_head_radio=single_head_radio+abs(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-i]-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-i-1]);
//////			}
//////			single_head_radio=single_head_radio/20;
//////			if(pulseWidth<20)mm_rn=20;
//////			else mm_rn=30;
//////			for(i=0;i<mm_rn;i++)
//////			{
//////				if(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-i>=0)
//////				avg_single=avg_single+input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-i];
//////			}
//////			avg_single=avg_single/mm_rn;
//////			avg_single=65535-avg_single;
//////			dB_loss_F1_F2=input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-2]-input_data[sGabor_Result.Event_Array[1]-2];
//////			F1_F2_LOSS=dB_loss_F1_F2;
//////			distance_F1_F2=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-sGabor_Result.Event_Array[1];
//////			//distance_F1_F2=
//////			dB_loss_F1_F2=dB_loss_F1_F2/(distance_F1_F2*(Sample_time*Light_fiber_speed)/2);
//////			if(dB_loss_F1_F2>10*K1_K2_lamda)KK1=3.5;
//////			else if(dB_loss_F1_F2>8*K1_K2_lamda)KK1=3;
//////			else if(dB_loss_F1_F2>6*K1_K2_lamda)KK1=2.5;
//////			else KK1=2;
//////			if(avg_single<KK1*end_radio+single_head_radio)/////////20150804
//////			{
//////				//斜率计算
//////
//////				
//////				if(dB_loss_F1_F2>=3*K1_K2_lamda)
//////				{
//////					doint=2*lEvent/5;
//////					if(doint<=3)doint=3;
//////					for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////					{
//////						if(sGabor_Result.Reflect_Type[i]==1)
//////						{
//////							//if(sGabor_Result.Event_Array[i]*2<=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-doint)
//////							if((2*sGabor_Result.Event_Array[i]>=(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-doint))&&(2*sGabor_Result.Event_Array[i]<=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+doint))
//////							{
//////								//符合鬼影条件
//////								sGabor_Result.Valid_Num=i+1;
//////								break;
//////							}
//////						}
//////					}
//////				}
//////			}
//////
//////
//////		}
//////		
//////#if 1
//////		/////////////////////////////////////////////////
//////		//末端误判判断
//////		{
//////			if(sGabor_Result.Valid_Num>3&&pulseWidth>=100)
//////			{
//////				K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////				kk=0;
//////				for(i=sGabor_Result.Valid_Num-1;i>0;i--)
//////				{
//////					if(sGabor_Result.Reflect_Type[i]!=0)
//////					{
//////						if(i!=sGabor_Result.Valid_Num-1)
//////						{
//////							for(j=i;j<sGabor_Result.Valid_Num-1;j++)
//////							{
//////								if((65535-input_data[sGabor_Result.Event_Array[j]])>(65535-input_data[sGabor_Result.Event_Array[i]]))
//////								{
//////									delete_data_buff[kk++]=j;
//////									continue;
//////								}
//////								if(sGabor_Result.Line_k[j]>0.7)
//////								{
//////									delete_data_buff[kk++]=j;
//////								}
//////							}
//////
//////						}
//////						break;
//////					}
//////
//////				}
//////				for(i=0;i<kk;i++)
//////				{
//////					delete_data_buff[kk+1]=0;//当中间变量使用
//////					for(j=0;j<kk-i-1;j++)
//////					{
//////						if (delete_data_buff[j]>delete_data_buff[j+1])
//////						{
//////							delete_data_buff[kk+1]=delete_data_buff[j];
//////							delete_data_buff[j]=delete_data_buff[j+1];
//////							delete_data_buff[j+1]=delete_data_buff[kk+1];
//////
//////						}
//////					}
//////				}
//////				for(i=0;i<kk;i++)
//////				{
//////					deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////					//deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////				}
//////			}
//////			else if(sGabor_Result.Valid_Num>2&&pulseWidth>=3)
//////			{
//////
//////				kk=0;
//////				int rn=0;
//////				K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////				for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////				{
//////					if(sGabor_Result.Reflect_Type[i]==1)rn=i;
//////					else if(sGabor_Result.Reflect_Type[i]==0)
//////					{
//////						if(rn==0)continue;
//////						if(65535-input_data[sGabor_Result.Event_Array[i]]>=65535-input_data[sGabor_Result.Event_Array[rn]])
//////							delete_data_buff[kk++]=i;
//////
//////					}
//////				}
//////				for(i=0;i<kk;i++)
//////				{
//////					delete_data_buff[kk+1]=0;//当中间变量使用
//////					for(j=0;j<kk-i-1;j++)
//////					{
//////						if (delete_data_buff[j]>delete_data_buff[j+1])
//////						{
//////							delete_data_buff[kk+1]=delete_data_buff[j];
//////							delete_data_buff[j]=delete_data_buff[j+1];
//////							delete_data_buff[j+1]=delete_data_buff[kk+1];
//////
//////						}
//////					}
//////				}
//////				for(i=0;i<kk;i++)
//////				{
//////					deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////				}
//////			}
//////		}
//////#endif
//////#if 0
//////		//反射杂波事件过滤
//////		if(pulseWidth>=5&&pulseWidth<=10)
//////		{
//////			float fiber_end_radio=0;
//////			kk=0;
//////			unsigned char delete_enable=0;
//////			for(i=paramLen-1;i>paramLen-21;i--)
//////			{
//////				fiber_end_radio=fiber_end_radio+65535-input_data[i];
//////			}
//////			fiber_end_radio=fiber_end_radio/20;
//////			for(i=1;i<sGabor_Result.Valid_Num;i++)
//////			{
//////				delete_enable=0;
//////				if(sGabor_Result.Reflect_Type[i]==1)
//////				{
//////					
//////					if(input_data[i+1]-input_data[i+2]<300)
//////						delete_enable=1;
//////					else if(input_data[i+2]-input_data[i+3]<300)
//////						delete_enable=1;
//////					else if(input_data[i+3]-input_data[i+4]<300)
//////						delete_enable=1;
//////					else if(input_data[i+4]-input_data[i+5]<300)
//////						delete_enable=1;
//////
//////					if(65535-input_data[sGabor_Result.Event_Array[i]+4]<2*fiber_end_radio+1000)
//////					{
//////						delete_enable=1;
//////					}
//////					else if(65535-input_data[sGabor_Result.Event_Array[i]+5]<2*fiber_end_radio+1000)
//////					{
//////						delete_enable=1;
//////					}
//////					else if(65535-input_data[sGabor_Result.Event_Array[i]+6]<2*fiber_end_radio+1000)
//////					{
//////						delete_enable=1;
//////					}
//////					else if(65535-input_data[sGabor_Result.Event_Array[i]+7]<2*fiber_end_radio+1000)
//////					{
//////						delete_enable=1;
//////					}
//////					else if(65535-input_data[sGabor_Result.Event_Array[i]+8]<2*fiber_end_radio+1000)
//////					{
//////						delete_enable=1;
//////					}
//////					if(delete_enable==1)delete_data_buff[kk++]=i;
//////				}
//////			}
//////			for(i=0;i<kk;i++)
//////			{
//////				deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////			}
//////		}
//////#endif
//////		//非反射事件杂波过滤
//////#if 1
//////kk=0;
//////int up_time=0,down_time=0;
//////int point_number=0;
////////unsigned char delete_flag=0;
//////int* Parameter_data_buff=new int[paramLen];
//////memset(Parameter_data_buff,0,paramLen*sizeof(int));
////////int Parameter_data_buff[120000];
//////for(i=0;i<paramLen-10;i++)
//////{
//////	Parameter_data_buff[i]=input_data[i+3]-input_data[i];
//////	if(Parameter_data_buff[i]<1)Parameter_data_buff[i]=0;
//////}
//////for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////{
//////	if(sGabor_Result.Reflect_Type[i]==0)
//////	{
//////		delete_flag=1;
//////		down_time=0;
//////		up_time=0;
//////		point_number=lEvent/4;
//////		if(point_number<12)point_number=12;
//////		for(j=sGabor_Result.Event_Array[i];j<sGabor_Result.Event_Array[i]+point_number;j++)
//////		{
//////			if(Parameter_data_buff[j]>0)
//////			{
//////				down_time++;
//////				up_time=0;
//////				if(down_time>=4)
//////				{
//////					delete_flag=0;
//////					break;
//////				}
//////			}
//////			else 
//////			{
//////				up_time++;
//////				if(up_time>=2)
//////				down_time=0;
//////			}
//////		}
//////		if(delete_flag==1)
//////		{
//////			if(sGabor_Result.Event_Loss[i]<=2*dB_Loss)
//////			delete_data_buff[kk++]=i;
//////		}
//////	}
//////}
//////for(i=0;i<kk;i++)
//////{
//////	delete_data_buff[kk+1]=0;//当中间变量使用
//////	for(j=0;j<kk-i-1;j++)
//////	{
//////		if (delete_data_buff[j]>delete_data_buff[j+1])
//////		{
//////			delete_data_buff[kk+1]=delete_data_buff[j];
//////			delete_data_buff[j]=delete_data_buff[j+1];
//////			delete_data_buff[j+1]=delete_data_buff[kk+1];
//////
//////		}
//////	}
//////}
//////for(i=0;i<kk;i++)
//////{
//////	deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////}
//////delete[] Parameter_data_buff;
//////
//////#endif
//////		//sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1];
//////		//sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]=12478;
//////		
//////		//sGabor_Result.Valid_Num=sGabor_Result.Valid_Num++;
//////if(pulseWidth>=10)
//////{
//////
//////	kk=0;
//////	for(i=2;i<sGabor_Result.Valid_Num;i++)
//////	{
//////		if(sGabor_Result.Reflect_Type[i]==1&&sGabor_Result.Reflect_Type[i-1]==1)
//////		{
//////			if(sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[i-1]<5)
//////				delete_data_buff[kk++]=i;
//////		}
//////	}
//////	for(i=0;i<kk;i++)
//////	{
//////		delete_data_buff[kk+1]=0;//当中间变量使用
//////		for(j=0;j<kk-i-1;j++)
//////		{
//////			if (delete_data_buff[j]>delete_data_buff[j+1])
//////			{
//////				delete_data_buff[kk+1]=delete_data_buff[j];
//////				delete_data_buff[j]=delete_data_buff[j+1];
//////				delete_data_buff[j+1]=delete_data_buff[kk+1];
//////
//////			}
//////		}
//////	}
//////
//////	for(i=0;i<kk;i++)
//////	{
//////		deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////	}
//////
//////}
////////sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=5621;
//////#if 0
//////if(sGabor_Result.Valid_Num>2)
//////{
//////	int data_max=0,data_min=0,data_buff=0;
//////	int data_max_mark=0,data_min_mark=0;
//////	for(i=1;i<sGabor_Result.Valid_Num;i++)
//////	{
//////		data_max=0;
//////		data_min=65535;
//////		if(sGabor_Result.Reflect_Type[i])
//////		{
//////			for(j=sGabor_Result.Event_Array[i]-5;j<sGabor_Result.Event_Array[i]+5;j++)
//////			{
//////				data_buff=65535-input_data[j];
//////				if(data_buff>data_max)
//////				{
//////					data_max=data_buff;
//////					data_max_mark=j;
//////				}
//////				
//////			}
//////			for(j=sGabor_Result.Event_Array[i]-5;j<data_max_mark;j++)
//////			{
//////				if(data_buff<=data_min)
//////				{
//////					data_min=data_buff;
//////					data_min_mark=j;
//////				}
//////			}
//////			sGabor_Result.Event_Array[i]=data_min_mark;
//////		}
//////	}
//////}
//////#endif
//////
//////if(sGabor_Result.Valid_Num>2&&pulseWidth>=100)
//////{
//////	int data_max=0,data_min=0,data_buff=0;
//////	int data_max_mark=0,data_min_mark=0;
//////	//int data_result_buff[20];
//////
//////
//////	if(sGabor_Result.Valid_Num>2&&pulseWidth>=100)
//////	{
//////		int data_max=0,data_min=0,data_buff=0;
//////		int data_max_mark=0,data_min_mark=0;
////////修改反射事件的误判断
//////		for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////		{
//////			data_max=0;
//////			data_min=65535;
//////			if(sGabor_Result.Reflect_Type[i]==0)
//////			{
//////				for(j=sGabor_Result.Event_Array[i]-5;j<=sGabor_Result.Event_Array[i]+5;j++)
//////				{
//////					data_buff=65535-input_data[j];
//////					if(data_buff>data_max)
//////					{
//////						data_max=data_buff;
//////						data_max_mark=j;
//////					}
//////					if(data_buff<data_min)
//////					{
//////						data_min=data_buff;
//////						data_min_mark=j;
//////					}
//////					if(data_min_mark!=0&&data_max_mark!=0)
//////					{
//////						if(data_min_mark<data_max_mark)
//////						{
//////							if(data_min_mark<sGabor_Result.Event_Array[i]&&data_max_mark>sGabor_Result.Event_Array[i])
//////							{
//////								if((data_max-data_min)>100)
//////								{
//////									sGabor_Result.Reflect_Type[i]=1;
//////								sGabor_Result.Event_Array[i]=data_min_mark;
//////								}
//////							}
//////						}
//////					}
//////				}
//////			}
//////		}
//////		//int data_result_buff[20];
//////		for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////		{
//////			data_max=0;
//////			data_min=65535;
//////			if(sGabor_Result.Reflect_Type[i])
//////			{
//////				data_min_mark=sGabor_Result.Event_Array[i];
//////				for(j=sGabor_Result.Event_Array[i]-3;j<sGabor_Result.Event_Array[i]+5;j++)
//////				{
//////					data_buff=65535-input_data[j];
//////					if(data_buff>data_max)
//////					{
//////						data_max=data_buff;
//////						data_max_mark=j;
//////					}
//////
//////				}
//////				for(j=sGabor_Result.Event_Array[i]-3;j<data_max_mark;j++)
//////				{
//////					data_buff=65535-input_data[j];
//////					if(data_buff<=data_min)
//////					{
//////						data_min=data_buff;
//////						data_min_mark=j;
//////					}
//////				}
//////				sGabor_Result.Event_Array[i]=data_min_mark;
//////			}
//////		}
//////	}
//////	//调整反射事件，利用最大值，倒过来看反弹数据
//////	for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////	{
//////		data_max=0;
//////		data_min=65535;
//////		if(sGabor_Result.Reflect_Type[i])
//////		{
//////			for(j=sGabor_Result.Event_Array[i]-5;j<sGabor_Result.Event_Array[i]+5;j++)
//////			{
//////				data_buff=65535-input_data[j];
//////				if(data_buff>data_max)
//////				{
//////					data_max=data_buff;
//////					data_max_mark=j;
//////				}
//////
//////			}
//////			for(j=data_max_mark;j>sGabor_Result.Event_Array[i]-5;j--)
//////			{
//////				data_buff=input_data[j]-input_data[j-1];
//////				if(data_buff>=0)
//////				{
//////					data_min=data_buff;
//////					data_min_mark=j;
//////					sGabor_Result.Event_Array[i]=data_min_mark;
//////					break;
//////				}
//////			}
//////			
//////		}
//////	}
//////
//////
////////调整反射事件,定位到最小值
//////		//for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////		//{
//////		//	data_max=0;
//////		//	data_min=65535;
//////		//	if(sGabor_Result.Reflect_Type[i])
//////		//	{
//////		//		for(j=sGabor_Result.Event_Array[i]-3;j<sGabor_Result.Event_Array[i]+5;j++)
//////		//		{
//////		//			data_buff=65535-input_data[j];
//////		//			if(data_buff>data_max)
//////		//			{
//////		//				data_max=data_buff;
//////		//				data_max_mark=j;
//////		//			}
//////
//////		//		}
//////		//		for(j=sGabor_Result.Event_Array[i]-3;j<data_max_mark;j++)
//////		//		{
//////		//			data_buff=65535-input_data[j];
//////		//			if(data_buff<=data_min)
//////		//			{
//////		//				data_min=data_buff;
//////		//				data_min_mark=j;
//////		//			}
//////		//		}
//////		//		sGabor_Result.Event_Array[i]=data_min_mark;
//////		//	}
//////		//}
//////
//////	//非反射事件调整
//////	for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////	{
//////		if(sGabor_Result.Reflect_Type[i]==0)
//////		{
//////			data_min_mark=sGabor_Result.Event_Array[i];
//////			for(j=sGabor_Result.Event_Array[i];j<sGabor_Result.Event_Array[i]+6;j++)
//////			{
//////				if(input_data[j]>=input_data[j+1])
//////				{
//////					//if()
//////					data_min_mark=j;
//////				}
//////		//		else break;
//////			}
//////			if(data_min_mark!=0)sGabor_Result.Event_Array[i]=data_min_mark;
//////			else sGabor_Result.Event_Array[i]=j;
//////		}
//////	}
//////}
//////#if 1  //对于过滤鬼影后出现的反射峰后面的再一个反射事件的误判断
//////if(sGabor_Result.Valid_Num>2)
//////{
//////	int max_data=0;
//////	int min_data=0;
//////	int max_mark=0;
//////	int min_mark=0;
//////	int reflex_hight=0;
//////	int width_pulse=0;
//////	float K1=0;
//////	if(sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]==1&&sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-2]==1)
//////	{
//////		//求出第一个反射峰的高度和宽度：
//////		for(i=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2];i<sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2]+2*lEvent;i++)
//////		{
//////			if(max_data<=65535-input_data[i])
//////			{
//////				max_data=65535-input_data[i];
//////				max_mark=i;
//////			}
//////		}
//////		reflex_hight=max_data-(65535-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2]-1]);
//////		for(i=max_mark;i<max_mark+2*lEvent;i++)
//////		{
//////			if(65535-input_data[i]<=65535-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2]-1])
//////			{
//////				width_pulse=i-sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2];
//////				break;
//////			}
//////		}
//////		if(width_pulse==0)width_pulse=i-sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2];
//////		if(width_pulse<=0)width_pulse=2*lEvent;
//////		if(reflex_hight>=10000)K1=2.2*width_pulse/lEvent;
//////		else if(reflex_hight>=8000)K1=2*width_pulse/lEvent;
//////		else if(reflex_hight>=5000)K1=1.5*width_pulse/lEvent;
//////		
//////		if(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2]<=K1*lEvent)
//////		{
//////			if(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+lEvent/8]-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]]>0)
//////				if(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+lEvent/8+1]-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]]>0)
//////					if(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+lEvent/8+2]-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]]>0)
//////					{
//////						//if(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2]]-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-]]>1000)
//////						if(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]]-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2]]>1000)
//////						sGabor_Result.Valid_Num--;
//////						else if(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2]<1.5*width_pulse)
//////						{
//////							if(input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]]-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+lEvent/4]<=500)
//////							{
//////								sGabor_Result.Valid_Num--;
//////							}
//////						}
//////						
//////					}
//////		}
//////	}
//////}
////////if(pulseWidth<=10)
////////for(i=1;i<sGabor_Result.Valid_Num;i++)
////////{
////////	if(sGabor_Result.Event_Hight[i]>=70)delete_data_buff[kk++]=i;
////////
////////}
////////for(i=0;i<kk;i++)
////////{
////////	deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
////////}
//////       // sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=6568;
//////#if 1
//////if(sGabor_Result.Valid_Num>1)//////对反射事件进行校准移位
//////{
//////	unsigned long min_reflex=65535;
//////	unsigned long max_reflex=0;
//////	unsigned long max_mark_c=0;
//////	unsigned long min_mark_c=0;
//////	unsigned long noise_reflex=0;
//////	unsigned long reflex_hight=0;
//////	sGabor_Result.Event_type[sGabor_Result.Valid_Num-1]='E';
//////
//////	for(i=1;i<sGabor_Result.Valid_Num;i++)
//////	{
//////		if(sGabor_Result.Reflect_Type[i])
//////		{
//////			//求出反射峰高度
//////			for(j=0;j<lEvent/3;j++)
//////			{
//////				if(max_reflex<65535-input_data[sGabor_Result.Event_Array[i]+j])
//////				{
//////					max_reflex=65535-input_data[sGabor_Result.Event_Array[i]+j];
//////					max_mark_c=sGabor_Result.Event_Array[i]+j;
//////				}
//////				if(min_reflex>65535-input_data[sGabor_Result.Event_Array[i]+j])
//////				{
//////					min_reflex=65535-input_data[sGabor_Result.Event_Array[i]+j];
//////					min_mark_c=sGabor_Result.Event_Array[i]+j;
//////				}
//////			}
//////			reflex_hight=max_reflex-(65535-(input_data[min_mark_c]+input_data[min_mark_c-1]+input_data[min_mark_c-2])/3);
//////			//找出高于事件点1/6反射峰高度的点
//////			for(j=sGabor_Result.Event_Array[i]+1;j<max_mark_c;j++)
//////			{
//////
//////				if(input_data[sGabor_Result.Event_Array[i]]-input_data[j-1]>reflex_hight/6)
//////					if(input_data[sGabor_Result.Event_Array[i]]-input_data[j]>reflex_hight/6)
//////						if(input_data[sGabor_Result.Event_Array[i]]-input_data[j+1]>reflex_hight/6)
//////					{
//////						if(sGabor_Result.Event_Array[i]+j<min_mark_c)
//////						{
//////							sGabor_Result.Event_Array[i]=min_mark_c;
//////						}
//////						else
//////						{
//////							sGabor_Result.Event_Array[i]=j-2;
//////							break;
//////						}
//////					}
//////			}
//////		}
//////		
//////	}
//////
//////}
//////#endif
//////
//////#if 1
//////unsigned long Noise_aaa=0;
//////unsigned int mm=0;
//////unsigned long Noise_end=0;
//////unsigned int length_step=0;
//////kk=0;
//////for(i=paramLen-1;i>paramLen-200;i--)
//////{
//////	Noise_end=Noise_end+(65535-input_data[i]);
//////}
//////Noise_end=Noise_end/200;
//////if(Noise_end>=4000)Noise_end=3000;
//////if(Noise_end<1000)Noise_end=1000;
//////kk=0;
//////if(sGabor_Result.Valid_Num>=2)
//////{
//////	for(i=sGabor_Result.Valid_Num-1;i>0;i--)
//////	{
//////		if(sGabor_Result.Reflect_Type[i])
//////		{
//////			if(sGabor_Result.Event_Hight[i]>68)
//////			{
//////				Noise_aaa=0;
//////				length_step=lEvent/10;
//////				if(length_step<=3)length_step=3;
//////				for(mm=0;mm<5;mm++)
//////				{
//////					Noise_aaa=Noise_aaa+abs(input_data[sGabor_Result.Event_Array[i]-mm]-input_data[sGabor_Result.Event_Array[i]-mm-length_step]);
//////				}
//////				Noise_aaa=Noise_aaa/5;
//////				
//////				if(Noise_aaa>=100)
//////				{
//////					if((65535-(input_data[sGabor_Result.Event_Array[i]]+input_data[sGabor_Result.Event_Array[i]-1])/2)<2*Noise_end)
//////						delete_data_buff[kk++]=i;
//////					else
//////					{
//////						if(Noise_end>=400&&Noise_aaa>=Noise_end/2)
//////							delete_data_buff[kk++]=i;
//////					}
//////				}
//////			}
//////		}
//////		else
//////		{
//////			Noise_aaa=0;
//////			length_step=lEvent/10;
//////			if(length_step<=3)length_step=3;
//////			for(mm=0;mm<5;mm++)
//////			{
//////				Noise_aaa=Noise_aaa+abs(input_data[sGabor_Result.Event_Array[i]-mm]-input_data[sGabor_Result.Event_Array[i]-mm-length_step]);
//////			}
//////			Noise_aaa=Noise_aaa/5;
//////			if(Noise_aaa>=150)
//////			{
//////				if((sGabor_Result.Event_Loss[i]*1000)<=Noise_aaa)//点损耗小于噪声振幅
//////				delete_data_buff[kk++]=i;
//////			}
//////			
//////		}
//////
//////	}
//////	for(i=0;i<kk;i++)
//////	{
//////		delete_data_buff[kk+1]=0;//当中间变量使用
//////		for(j=0;j<kk-i-1;j++)
//////		{
//////			if (delete_data_buff[j]>delete_data_buff[j+1])
//////			{
//////				delete_data_buff[kk+1]=delete_data_buff[j];
//////				delete_data_buff[j]=delete_data_buff[j+1];
//////				delete_data_buff[j+1]=delete_data_buff[kk+1];
//////
//////			}
//////		}
//////	}
//////	for(i=0;i<kk;i++)
//////	{
//////		deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////	}
//////}
//////
//////#endif
//////
////////衰减事件位置校准
//////#if 0
//////int input_data_buff[10000];
////////int* input_data_buff=new int[lEvent];//短时傅里叶变化结果Cn
////////memset(input_data_buff,0,lEvent*sizeof(int));
//////int start_point =0;
//////int end_point =0;
//////int time_cc=0;
//////for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////{
//////	if(sGabor_Result.Reflect_Type[i]==0)
//////	{
//////		start_point =sGabor_Result.Event_Array[i]-lEvent/6;
//////		end_point=sGabor_Result.Event_Array[i]+lEvent/2;
//////		for(j=start_point;j<end_point;j++)
//////		{
//////			input_data_buff[j-start_point]=input_data[j+1]-input_data[j];
//////			Noise_aaa=Noise_aaa+abs(input_data_buff[j-start_point]);
//////
//////		}
//////		Noise_aaa=Noise_aaa/(end_point-start_point);
//////		time_cc=0;
//////		for(j=start_point;j<end_point;j++)
//////		{
//////			if(input_data_buff[j-start_point]>2*Noise_aaa)time_cc++;
//////			else time_cc=0;
//////			if(time_cc>=3)
//////			{
//////				sGabor_Result.Event_Array[i]=j-time_cc;
//////			}
//////		}
//////	}
//////}
////////delete[] input_data_buff;
//////#endif
//////
//////#endif
//////
//////
/////////////对末端是非反射事件做判断
//////if(sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]==0&&sGabor_Result.Valid_Num>2)
//////{
//////	int max_mark_c=0;
//////	int max_data_buf=0;
//////	int Hight_reflex=0;
//////	int width_pulse_buf=0;
//////	for(i=sGabor_Result.Valid_Num-1;i>0;i--)//找出最后一个反射点
//////	{
//////		if(sGabor_Result.Reflect_Type[i])
//////		{
//////			mm=i;
//////			break;
//////		}
//////	}
//////	//求出反射宽度
//////	for(i=sGabor_Result.Event_Array[mm];i<sGabor_Result.Event_Array[mm]+2*lEvent;i++)
//////	{
//////		if(max_data_buf<=65535-input_data[i])
//////		{
//////			max_data_buf=65535-input_data[i];
//////			max_mark_c=i;
//////		}
//////	}
//////	Hight_reflex=max_data_buf-(65535-input_data[sGabor_Result.Event_Array[mm]-1]);
//////	for(i=max_mark_c;i<max_mark_c+10*lEvent;i++)
//////	{
//////		if(65535-input_data[i]<65535-input_data[sGabor_Result.Event_Array[mm]-1])
//////			if(65535-input_data[i+1]<65535-input_data[sGabor_Result.Event_Array[mm]-1])
//////			{
//////				width_pulse_buf=i-sGabor_Result.Event_Array[mm];
//////				break;
//////			}
//////	}
//////	if(pulseWidth<=20)//20ns以内
//////	{
//////		if(Hight_reflex>=10000)
//////		{
//////			if(width_pulse_buf>=4*lEvent)
//////			{
//////				sGabor_Result.Valid_Num=mm+1;
//////				sGabor_Result.Event_type[mm]='E';
//////			}
//////			
//////		}
//////	}
//////
//////}
////////sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=Search_long_fiber_end(wavelength,pulseWidth,input_data,paramLen,Sample_freaq);
////////sGabor_Result.Valid_Num=1;
//////
////////sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=22151;
//////if(sGabor_Result.Event_Array[0]==0)sGabor_Result.Event_Array[0]=lEvent/2;
////////sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=5438;
//////		K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		Acount_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////		Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////		K_Line_limite(wavelength,&sGabor_Result);
//////		/*if(pulseWidth>=20)
//////		sGabor_Result=Find_event_end_function(wavelength,pulseWidth,input_data,sGabor_Result,Index_N,Sample_freaq);*/
//////if(pulseWidth<=20)
//////{
//////	kk=0;
//////   for(i=1;i<sGabor_Result.Valid_Num;i++)
//////   {
//////	   if(sGabor_Result.Event_Hight[i]>=70)delete_data_buff[kk++]=i;
//////
//////   }
//////   for(i=0;i<kk;i++)
//////   {
//////	   delete_data_buff[kk+1]=0;//当中间变量使用
//////	   for(j=0;j<kk-i-1;j++)
//////	   {
//////		   if (delete_data_buff[j]>delete_data_buff[j+1])
//////		   {
//////			   delete_data_buff[kk+1]=delete_data_buff[j];
//////			   delete_data_buff[j]=delete_data_buff[j+1];
//////			   delete_data_buff[j+1]=delete_data_buff[kk+1];
//////
//////		   }
//////	   }
//////	}
//////
//////   for(i=0;i<kk;i++)
//////   {
//////	   deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////   }
//////}
//////if(Sample_freaq==2050||Sample_freaq==400)
//////{
//////	float length_distance=0;
//////	K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////	Acount_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////	Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////	Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////	K_Line_limite(wavelength,&sGabor_Result);
//////	
//////	if(pulseWidth<=50&&wavelength!=850)
//////	{
//////		for(mm=0;mm<20;mm++)
//////		{
//////		   kk=0;
//////			if(sGabor_Result.Valid_Num>=3)
//////			{
//////				for(i=1;i<sGabor_Result.Valid_Num;i++)
//////					if(sGabor_Result.Event_Hight[i]>=70)delete_data_buff[kk++]=i;
//////
//////				for(i=0;i<kk;i++)
//////				{
//////					deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////				}
//////			}
//////			K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////			Acount_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////			Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////			Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////			K_Line_limite(wavelength,&sGabor_Result);
//////			kk=0;
//////			if(sGabor_Result.Valid_Num>=3)
//////			{
//////				for(i=1;i<sGabor_Result.Valid_Num;i++)
//////				{
//////					if(sGabor_Result.Reflect_Type[i]==0)
//////					{
//////						if(sGabor_Result.Reflect_Type[i-1]==1)
//////						{
//////							if(sGabor_Result.Line_k[i]>5)delete_data_buff[kk++]=i;
//////							else 
//////							{
//////								if(sGabor_Result.Line_k[i]>1)
//////								{
//////									length_distance=sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[i-1];
//////									length_distance=length_distance*0.005*(82/(Sample_freaq/25));
//////									if(length_distance<(5*pulseWidth/10))delete_data_buff[kk++]=i;
//////								/*	else 
//////									{
//////										if(sGabor_Result.Reflect_Type[i-1]==1&&i==(sGabor_Result.Valid_Num-1))
//////										{
//////											if(length_distance<(14*pulseWidth/10))delete_data_buff[kk++]=i;
//////										}
//////									}*/
//////								}
//////							}
//////						//	break;
//////						}
//////					}
//////				}
//////				for(i=0;i<kk;i++)
//////				{
//////					deleteEvent_New(delete_data_buff[i]-i,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////				}
//////				K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////				Acount_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////				Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////				Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////				K_Line_limite(wavelength,&sGabor_Result);
//////				if(kk==0)break;
//////			}
//////		}
//////	}
//////}
//////if(pulseWidth>=200&&sGabor_Result.Valid_Num<=1)sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=sGabor_Result.Event_Array[99];
//////
//////   sGabor_Result.Event_type[sGabor_Result.Valid_Num-1]='E';
//////
//////   K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////   Acount_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////   Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
//////   Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////   K_Line_limite(wavelength,&sGabor_Result);
//////  return sGabor_Result;
//////}
//////
//////
////////******************************************************************//
////////     添加事件
////////     insertNum:所要插入的事件点的数据点编号
////////     wavelength:曲线波长
////////     pulsewidth：曲线脉宽
////////     input_data[]：分析的原始数据
////////     Return_loss_Tybe:典型散射系数
////////     paramLen:原始数据长度
////////******************************************************************//
////////******************************************************************//
////////     添加事件
////////     insertNum:所要插入的事件点的数据点编号
////////     wavelength:曲线波长
////////     pulsewidth：曲线脉宽
////////     input_data[]：分析的原始数据
////////     Return_loss_Tybe:典型散射系数
////////     paramLen:原始数据长度
////////******************************************************************//
//////Gabor_Result insertEvent(int insertNum,int wavelength,int pulsewidth,WORD input_data[],int paramLen,Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe)
///////*insertPosition插入物理位置
//////sGaborResult事件分析结果
//////insertNum插入序号
//////*/
//////{
//////
//////	int i=0;
//////	int k=0;
//////	int insertIndex=0;
//////	i=sGabor_Result.Valid_Num;
//////	if(insertNum>=paramLen)return sGabor_Result;
//////
//////	int pulseNum=11;
//////	int L_event=0;
//////	switch(pulsewidth)
//////	{
//////	case 3:
//////		pulseNum=0;
//////		break;
//////	case 5:
//////		pulseNum=1;
//////		break;
//////	case 10:
//////		pulseNum=2;
//////		break;
//////	case 20:
//////		pulseNum=3;
//////		break;
//////	case 50:
//////		pulseNum=4;
//////		break;
//////	case 100:
//////		pulseNum=5;
//////		break;
//////	case 200:
//////		pulseNum=6;
//////		break;
//////	case 500:
//////		pulseNum=7;	
//////		break;
//////	case 1000:
//////		pulseNum=8;
//////		break;
//////	case 2000:
//////		pulseNum=9;
//////		break;
//////	case 5000:
//////		pulseNum=10;
//////		break;
//////	case 10000:
//////		pulseNum=11;
//////		break;
//////	case 20000:
//////		pulseNum=12;
//////		break;
//////	case 30:
//////		pulseNum=13;
//////		break;
//////	case 300:
//////		pulseNum=14;
//////		break;
//////	case 400:
//////		pulseNum=15;
//////		break;
//////	default:pulseNum=12;break;
//////	}
//////	L_event=lEventGenerate(pulseNum,wavelength,Sample_freaq);
//////	//////////////////////////////////////////////
//////	//插入点判断，判断其是否已经存在事件，如果已经存在事件就禁止插入
//////	int j=0;
//////	int flag=1;
//////	if(sGabor_Result.Valid_Num>0)
//////	{
//////		if(insertNum>sGabor_Result.Event_Array[i-1])
//////		{
//////
//////			if((insertNum-sGabor_Result.Event_Array[i-1])>L_event)
//////			{
//////
//////				flag=0;
//////			}
//////			else flag=1;
//////
//////
//////		}
//////		else
//////		{
//////			if(i>1)
//////			{
//////				for(j=0;j<i;j++)
//////				{
//////					if(insertNum<sGabor_Result.Event_Array[0])
//////					{
//////						if((insertNum+L_event)<sGabor_Result.Event_Array[0])
//////						{
//////
//////							flag=0;
//////							break;
//////
//////						}
//////						else 
//////						{
//////							flag=1;
//////							break;
//////						}
//////					}
//////					if(insertNum>sGabor_Result.Event_Array[j]&&insertNum<sGabor_Result.Event_Array[j+1])
//////					{
//////						int k=0;
//////						if((insertNum-sGabor_Result.Event_Array[j])>L_event&&(sGabor_Result.Event_Array[j+1]-insertNum)>L_event)
//////						{
//////							flag=0;
//////							break;
//////						}
//////						else
//////						{
//////							flag=1;
//////							break;
//////						}
//////					}
//////				}
//////
//////			}
//////			else
//////			{
//////				if((insertNum+L_event)<sGabor_Result.Event_Array[0])
//////				{
//////					flag=0;
//////
//////				}
//////
//////			}
//////		}
//////	}
//////	else flag=0;
//////	if(insertNum<=sGabor_Result.Event_Array[0]+L_event/2)flag=1;
//////
//////
//////	if(flag)return sGabor_Result;
//////
//////
//////
//////	int step_event=2*L_event;
//////	float dB_k_k_1=0;
//////	//	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
//////	//两个数据之间的时间间隔：
//////	//	double Sample_time=Sample_freaq;//放大了10^6倍
//////	//	Sample_time=1/Sample_time;
//////
//////
//////
//////
//////	float return_loss=0;
//////
//////	////////////////////////////////////////////
//////	int* input_data_buff=new int[paramLen];//短时傅里叶变化结果Cn
//////	memset(input_data_buff,0,paramLen*sizeof(int));
//////
//////	if(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]<insertNum)//尾端插入事件
//////	{
//////		//if(insertNum>=paramLen)return sGabor_Result;//插入的事件点超过了所有的数据
//////		sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=insertNum;
//////		//判断插入事件类型
//////		int up_limit=0;
//////		int low_limit=0;
//////		double line_a=0;
//////		double line_b=0;
//////		double line_c=0;
//////		double line_d=0;
//////		int insertMaxIndex=0;
//////		int insertMinIndex=0;
//////		double insertMax=0;
//////		double insertMin=65535;
//////		double input_data_buff_statick=0;
//////		low_limit=insertNum-L_event/4;
//////		up_limit=insertNum+L_event/2;
//////		if(low_limit<4) low_limit=4;
//////
//////
//////
//////
//////
//////
//////		// 阮志光版本
//////		//寻找插入点后面的趋势
//////		for(k=low_limit;k<up_limit;k++)
//////		{
//////			input_data_buff_statick=65535-input_data[k];
//////			if(input_data_buff_statick<insertMin)
//////			{
//////				insertMin=input_data_buff_statick;
//////				insertMinIndex=k;
//////			}
//////			if(input_data_buff_statick>insertMax)
//////			{
//////				insertMax=input_data_buff_statick;
//////				insertMaxIndex=k;
//////			}
//////		}
//////		if(insertMinIndex<=insertNum&&insertMaxIndex>=insertNum)//反射事件
//////		{
//////			sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]=1;
//////
//////		}
//////		else if(insertMinIndex<=insertNum&&insertMaxIndex<insertNum)
//////		{
//////			if(insertMinIndex<insertMaxIndex)//衰减事件
//////			{
//////				sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]=0;
//////			}
//////			else if(insertMaxIndex<insertMinIndex)//反射事件
//////			{
//////				sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]=1;
//////			}
//////		}
//////		else if(insertMinIndex>insertNum&&insertMaxIndex>insertNum)
//////		{
//////			if(insertMin<=insertMaxIndex)//衰减事件
//////			{
//////				sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]=1;
//////			}
//////			else 
//////			{
//////				sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]=0;
//////			}
//////		}
//////		sGabor_Result.Event_type[sGabor_Result.Valid_Num-1]='A';
//////
//////	}
//////	else// 中间插入事件
//////	{
//////		int Insert_event_no=0;
//////		for(i=0;i<sGabor_Result.Valid_Num;i++)
//////		{
//////			if(insertNum<sGabor_Result.Event_Array[i])
//////			{
//////				Insert_event_no=i;
//////
//////				for(j=sGabor_Result.Valid_Num;j>Insert_event_no-1;j--)
//////				{
//////					sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[j-1];
//////					sGabor_Result.Total_Loss[j]=sGabor_Result.Total_Loss[j-1];
//////					sGabor_Result.Event_Hight[j]=sGabor_Result.Event_Hight[j-1];
//////					sGabor_Result.Event_Loss[j]=sGabor_Result.Event_Loss[j-1];
//////					sGabor_Result.Event_type[j]=sGabor_Result.Event_type[j-1];
//////					sGabor_Result.Line_k[j]=sGabor_Result.Line_k[j-1];
//////					sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[j-1];
//////
//////				}
//////				sGabor_Result.Event_Array[i]=insertNum;
//////				sGabor_Result.Total_Loss[i]=0;
//////				sGabor_Result.Event_Hight[i]=0;
//////				sGabor_Result.Event_Loss[i]=0;
//////				sGabor_Result.Event_type[i]='A';
//////				sGabor_Result.Line_k[i]=0;
//////				break;
//////			}
//////		}
//////		sGabor_Result.Valid_Num++;
//////
//////		//判断插入事件类型
//////		int up_limit=0;
//////		int low_limit=0;
//////		double line_a=0;
//////		double line_b=0;
//////		double line_c=0;
//////		double line_d=0;
//////		int insertMaxIndex=0;
//////		int insertMinIndex=0;
//////		double insertMax=0;
//////		double insertMin=65535;
//////		double input_data_buff_statick=0;
//////		low_limit=insertNum-L_event/4;
//////		up_limit=insertNum+L_event/2;
//////		if(low_limit<4) low_limit=4;
//////
//////
//////
//////
//////
//////
//////		// 阮志光版本
//////		//寻找插入点后面的趋势
//////		for(k=low_limit;k<up_limit;k++)
//////		{
//////			input_data_buff_statick=65535-input_data[k];
//////			if(input_data_buff_statick<insertMin)
//////			{
//////				insertMin=input_data_buff_statick;
//////				insertMinIndex=k;
//////			}
//////			if(input_data_buff_statick>insertMax)
//////			{
//////				insertMax=input_data_buff_statick;
//////				insertMaxIndex=k;
//////			}
//////		}
//////		if(insertMinIndex<=insertNum&&insertMaxIndex>=insertNum)//反射事件
//////		{
//////			//sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]=1;
//////			sGabor_Result.Reflect_Type[Insert_event_no]=1;
//////
//////		}
//////		else if(insertMinIndex<=insertNum&&insertMaxIndex<insertNum)
//////		{
//////			if(insertMinIndex<insertMaxIndex)//衰减事件
//////			{
//////				sGabor_Result.Reflect_Type[Insert_event_no]=0;
//////			}
//////			else if(insertMaxIndex<insertMinIndex)//反射事件
//////			{
//////				sGabor_Result.Reflect_Type[Insert_event_no]=1;
//////			}
//////		}
//////		else if(insertMinIndex>insertNum&&insertMaxIndex>insertNum)
//////		{
//////			if(insertMin<=insertMaxIndex)//衰减事件
//////			{
//////				sGabor_Result.Reflect_Type[Insert_event_no]=1;
//////			}
//////			else 
//////			{
//////				sGabor_Result.Reflect_Type[Insert_event_no]=0;
//////			}
//////		}
//////
//////
//////
//////
//////	}
//////
//////
//////	//sGabor_Result=K_Line_count(L_event,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);////////////////////
//////	//sGabor_Result=K_Line_count(lEvent,wavelength,pulseWidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
//////	K_Line_count(L_event,wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);//wcq
//////	sGabor_Result.Event_Loss[sGabor_Result.Valid_Num-1]=0;
//////	//sGabor_Result=Acount_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);
//////	//sGabor_Result=Acount_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
//////	Acount_Loss(wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);//wcq
//////	//sGabor_Result=Acount_return_loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);//改为下面的wcq
//////	Acount_return_loss(wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);//wcq
//////	//sGabor_Result=Acount_Total_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
//////	Acount_Total_Loss(wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////	//sGabor_Result=K_Line_limite(wavelength,sGabor_Result);//改为下面的wcq
//////	K_Line_limite(wavelength,&sGabor_Result);
//////	return sGabor_Result;
//////}
//////
////////******************************************************************//
////////     删除事件
////////     deleteNum:所删除事件点序号
////////     wavelength:曲线波长
////////     pulsewidth：曲线脉宽
////////     input_data[]：分析的原始数据
////////******************************************************************//
//////Gabor_Result deleteEvent(int deleteNum,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe)
//////{
//////	int i=0;
//////	i=sGabor_Result.Valid_Num;
//////	int pulseNum=0;
//////	int L_event=200;
//////	switch(pulsewidth)
//////	{
//////	case 3:
//////		pulseNum=0;
//////		break;
//////	case 5:
//////		pulseNum=1;
//////		break;
//////	case 10:
//////		pulseNum=2;
//////		break;
//////	case 20:
//////		pulseNum=3;
//////		break;
//////	case 50:
//////		pulseNum=4;
//////		break;
//////	case 100:
//////		pulseNum=5;
//////		break;
//////	case 200:
//////		pulseNum=6;
//////		break;
//////	case 500:
//////		pulseNum=7;	
//////		break;
//////	case 1000:
//////		pulseNum=8;
//////		break;
//////	case 2000:
//////		pulseNum=9;
//////		break;
//////	case 5000:
//////		pulseNum=10;
//////		break;
//////	case 10000:
//////		pulseNum=11;
//////		break;
//////	case 20000:
//////		pulseNum=12;
//////		break;
//////	case 30:
//////		pulseNum=13;
//////		break;
//////	case 300:
//////		pulseNum=14;
//////		break;
//////	case 400:
//////		pulseNum=15;
//////		break;
//////	default:pulseNum=12;break;
//////	}
//////	L_event=lEventGenerate(pulseNum,wavelength,Sample_freaq);
//////
//////
//////
//////
//////	//先求各段光纤的斜率：只要计算删除点所在点的下一个点的特性
//////	//	int up_limit,low_limit;
//////	int step_event=L_event*2;
//////	if(step_event<20)step_event=20;
//////	//float* sum_k=new float[2000];//短时傅里叶变化结果Cn
//////	//memset(sum_k,0,2000*sizeof(float));
//////	//double sum_k[20];
//////	double dB_k_k_1=0;
//////
//////	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
//////	//两个数据之间的时间间隔：
//////	double Sample_time=Sample_freaq;//放大了10^6倍
//////	Sample_time=1/Sample_time;
//////	//测量距离计算
//////	int Event_start_mark_cn=sGabor_Result.Event_Array[0];
//////
//////
//////	int j=0,k=0;
//////	j=sGabor_Result.Valid_Num;
//////	k=0;
//////	if(deleteNum==0||deleteNum>=sGabor_Result.Valid_Num)return sGabor_Result;
//////	for(i=0;i<j;i++)
//////	{
//////		if(i==deleteNum)
//////			continue;
//////		else
//////		{
//////			sGabor_Result.Event_Array[k]=sGabor_Result.Event_Array[i];
//////			sGabor_Result.Event_Loss[k]=sGabor_Result.Event_Loss[i];
//////			sGabor_Result.Total_Loss[k]=sGabor_Result.Total_Loss[i];
//////			sGabor_Result.Event_type[k]=sGabor_Result.Event_type[i];
//////			sGabor_Result.Event_Hight[k]=sGabor_Result.Event_Hight[i];
//////			sGabor_Result.Reflect_Type[k]=sGabor_Result.Reflect_Type[i];
//////			k++;
//////
//////		}
//////	}
//////	sGabor_Result.Valid_Num=k;
//////	//if(sGabor_Result.Valid_Num)sGabor_Result.Valid_Num--;
//////	sGabor_Result.Line_k[0]=0;
//////
//////	//sGabor_Result=K_Line_count(L_event,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);////////////////////
//////	//sGabor_Result=K_Line_count(L_event,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
//////	K_Line_count(L_event,wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);//wcq
//////	//sGabor_Result=Acount_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);
//////	//sGabor_Result=Acount_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
//////	Acount_Loss(wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);//wcq
//////	sGabor_Result.Event_Loss[sGabor_Result.Valid_Num-1]=0;
//////	//sGabor_Result=Acount_return_loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);//改为下面的wcq
//////	Acount_return_loss(wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);//wcq
//////	//sGabor_Result=Acount_Total_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
//////	Acount_Total_Loss(wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
//////	//sGabor_Result=K_Line_limite(wavelength,sGabor_Result);//改为下面的wcq
//////	K_Line_limite(wavelength,&sGabor_Result);
//////
//////	return sGabor_Result;
//////}
//////
//////void deleteEvent_New(int deleteNum,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe)
//////{
//////	int i=0;
//////	i=sGabor_Result->Valid_Num;
//////	int pulseNum=0;
//////	int L_event=200;
//////	switch(pulsewidth)
//////	{
//////	case 3:
//////		pulseNum=0;
//////		break;
//////	case 5:
//////		pulseNum=1;
//////		break;
//////	case 10:
//////		pulseNum=2;
//////		break;
//////	case 20:
//////		pulseNum=3;
//////		break;
//////	case 50:
//////		pulseNum=4;
//////		break;
//////	case 100:
//////		pulseNum=5;
//////		break;
//////	case 200:
//////		pulseNum=6;
//////		break;
//////	case 500:
//////		pulseNum=7;	
//////		break;
//////	case 1000:
//////		pulseNum=8;
//////		break;
//////	case 2000:
//////		pulseNum=9;
//////		break;
//////	case 5000:
//////		pulseNum=10;
//////		break;
//////	case 10000:
//////		pulseNum=11;
//////		break;
//////	case 20000:
//////		pulseNum=12;
//////		break;
//////	case 30:
//////		pulseNum=13;
//////		break;
//////	case 300:
//////		pulseNum=14;
//////		break;
//////	case 400:
//////		pulseNum=15;
//////		break;
//////	default:pulseNum=12;break;
//////	}
//////	L_event=lEventGenerate(pulseNum,wavelength,Sample_freaq);
//////
//////
//////
//////
//////	//先求各段光纤的斜率：只要计算删除点所在点的下一个点的特性
//////	//	int up_limit,low_limit;
//////	int step_event=L_event*2;
//////	if(step_event<20)step_event=20;
//////	//float* sum_k=new float[2000];//短时傅里叶变化结果Cn
//////	//memset(sum_k,0,2000*sizeof(float));
//////	//double sum_k[20];
//////	double dB_k_k_1=0;
//////
//////	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
//////	//两个数据之间的时间间隔：
//////	double Sample_time=Sample_freaq;//放大了10^6倍
//////	Sample_time=1/Sample_time;
//////	//测量距离计算
//////	int Event_start_mark_cn=sGabor_Result->Event_Array[0];
//////
//////
//////	int j=0,k=0;
//////	j=sGabor_Result->Valid_Num;
//////	k=0;
//////	if(deleteNum==0)//||deleteNum>=sGabor_Result->Valid_Num)
//////	{
//////		//return sGabor_Result;
//////		return ;
//////	}
//////	for(i=0;i<j;i++)
//////	{
//////		if(i==deleteNum)
//////			continue;
//////		else
//////		{
//////			sGabor_Result->Event_Array[k]=sGabor_Result->Event_Array[i];
//////			sGabor_Result->Event_Loss[k]=sGabor_Result->Event_Loss[i];
//////			sGabor_Result->Total_Loss[k]=sGabor_Result->Total_Loss[i];
//////			sGabor_Result->Event_type[k]=sGabor_Result->Event_type[i];
//////			sGabor_Result->Event_Hight[k]=sGabor_Result->Event_Hight[i];
//////			sGabor_Result->Reflect_Type[k]=sGabor_Result->Reflect_Type[i];
//////			k++;
//////
//////		}
//////	}
//////	sGabor_Result->Valid_Num=k;
//////	//if(sGabor_Result->Valid_Num)sGabor_Result->Valid_Num--;
//////	sGabor_Result->Line_k[0]=0;
//////
//////	//sGabor_Result=K_Line_count(L_event,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);////////////////////
//////	//sGabor_Result=K_Line_count(L_event,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
//////	K_Line_count(L_event,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//wcq
//////	//sGabor_Result=Acount_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);
//////	//sGabor_Result=Acount_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
//////	Acount_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//wcq
//////	sGabor_Result->Event_Loss[sGabor_Result->Valid_Num-1]=0;
//////	//sGabor_Result=Acount_return_loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);//改为下面的wcq
//////	Acount_return_loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);//wcq
//////	//sGabor_Result=Acount_Total_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
//////	Acount_Total_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);
//////	//sGabor_Result=K_Line_limite(wavelength,sGabor_Result);//改为下面的wcq
//////	K_Line_limite(wavelength,sGabor_Result);
//////
//////	//return sGabor_Result;
//////}
//////
////////用于光纤光栅的事件分析，将每一个事件的位置定位为顶峰
//////Gabor_Result Optical_grating(int wavelength,int pulsewidth,WORD input_data[],INT paramLen,Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float dB_reflex)
//////{
//////	int Event_start=sGabor_Result.Event_Array[0];
//////	int Event_end=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1];
//////	int i=0,j=0;
////////	int Event_Array[200]; 
//////	int step_point=20;
//////	int up_time=0,down_time=0;
//////	int data_buff=0;
//////	long sum_data=0;
//////	int data_max=0;
//////	int data_min=0;
//////	int data_max_no=0,data_min_no=0;
//////	int data_avg=0;
//////	int* input_data_buff=new int[paramLen];//短时傅里叶变化结果Cn
//////	memset(input_data_buff,0,paramLen*sizeof(int));
//////	int DB_reflex_door=dB_reflex*1000;
//////
//////	for(i=Event_start;i<Event_end;)//找到所有的上升沿
//////	{
//////		//取一段，求平均值
//////		sum_data=0;
//////		data_min=65535;
//////		data_min_no=i;
//////		data_max=0;
//////		data_max_no=i;
//////		//求段和
//////		for(j=i;j<i+step_point;j++)
//////		{
//////			data_buff=65535-input_data[j];
//////			sum_data=sum_data+data_buff;
//////			if(data_max<=data_buff)
//////			{
//////				data_max=data_buff;
//////				data_max_no=j;
//////			}
//////			if(data_min>=data_buff)
//////			{
//////				data_min=data_buff;
//////				data_min_no=j;
//////			}
//////		}
//////		//求段平均值
//////		data_avg=sum_data/step_point;
//////		//求段高于平均值+阈值的位置
//////		for(j=i;j<i+step_point;j++)
//////		{
//////			data_buff=65535-input_data[j];
//////			if(data_buff>data_avg+DB_reflex_door)
//////			{
//////				input_data_buff[j]=data_buff;
//////			}
//////			else input_data_buff[j]=0;
//////		}
//////		i=i+step_point;
//////	}
//////
//////
//////	sGabor_Result.Valid_Num=1;
//////	for(i=Event_start;i<Event_end;i++)
//////	{
//////		if(input_data_buff[i]!=0)
//////		{
//////			up_time++;
//////			if(up_time==5)
//////			{
//////				if(sGabor_Result.Valid_Num<99)
//////				{
//////					if(i-5>=Event_start+step_point/2)
//////						sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=i-5;
//////				}
//////
//////			}
//////		}
//////		if(input_data_buff[i]==0)
//////		{
//////			down_time++;
//////			if(up_time)
//////			{
//////				if(down_time>=3)up_time=0;
//////			}
//////			else 
//////			{
//////				down_time=0;
//////				up_time=0;
//////			}
//////		}
//////	}
//////	//将事件下标移到反射峰最高点
//////	for(i=0;i<sGabor_Result.Valid_Num;i++)
//////	{
//////		/*data_max=0;
//////		data_max_no=0;
//////		for(j=sGabor_Result.Event_Array[i];j<sGabor_Result.Event_Array[i]+step_point;j++)
//////		{
//////		if(data_max<input_data_buff[j])
//////		{
//////		data_max=input_data_buff[j];
//////		data_max_no=j;
//////		}
//////		}
//////		sGabor_Result.Event_Array[i]=data_max_no;*/
//////		sGabor_Result.Event_type[i]='F';
//////		sGabor_Result.Reflect_Type[i]=1;
//////		sGabor_Result.Total_Loss[i]=0;
//////		sGabor_Result.Event_Loss[i]=0;
//////		sGabor_Result.Event_Hight[i]=0;
//////	}
//////	sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=Event_end;
//////	sGabor_Result.Event_type[sGabor_Result.Valid_Num]='F';
//////	sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=1;
//////	sGabor_Result.Total_Loss[sGabor_Result.Valid_Num]=0;
//////	sGabor_Result.Event_Loss[sGabor_Result.Valid_Num]=0;
//////	sGabor_Result.Event_Hight[sGabor_Result.Valid_Num++]=0;
//////	delete[]input_data_buff;
//////	return sGabor_Result;
//////
//////}
//////
//////void Acount_Loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq)
//////{
//////	int i=0,k=0;
//////	int up_limit=0,low_limit=0;
//////	//float dB_k_line=0,Reflex_avg_dB=0,dB_Hight=0;
//////
//////	double dB_Hight=0;
//////	double dB_Low=0;
//////	double dB_k_line=0;
//////	int max_data_no=0;
//////	int min_data_no=0;
//////	float max_data=0;
//////	float min_data=0;
//////	double Reflex_avg_dB=0;
//////
//////
//////	int step_event=0;
//////
//////	int pulseNum=0;
//////	int L_event=200;
//////	switch(pulsewidth)
//////	{
//////	case 3:
//////		pulseNum=0;
//////		break;
//////	case 5:
//////		pulseNum=1;
//////		break;
//////	case 10:
//////		pulseNum=2;
//////		break;
//////	case 20:
//////		pulseNum=3;
//////		break;
//////	case 50:
//////		pulseNum=4;
//////		break;
//////	case 100:
//////		pulseNum=5;
//////		break;
//////	case 200:
//////		pulseNum=6;
//////		break;
//////	case 500:
//////		pulseNum=7;	
//////		break;
//////	case 1000:
//////		pulseNum=8;
//////		break;
//////	case 2000:
//////		pulseNum=9;
//////		break;
//////	case 5000:
//////		pulseNum=10;
//////		break;
//////	case 10000:
//////		pulseNum=11;
//////		break;
//////	case 20000:
//////		pulseNum=12;
//////		break;
//////	case 30:
//////		pulseNum=13;
//////		break;
//////	case 300:
//////		pulseNum=14;
//////		break;
//////	case 400:
//////		pulseNum=15;
//////		break;
//////	default:pulseNum=12;break;
//////	}
//////	L_event=lEventGenerate(pulseNum,wavelength,Sample_freaq);
//////	step_event=L_event*2;
//////	if(step_event<=20)step_event=20;
//////
//////
//////	if(pulsewidth>=2000)/////////////////////////////////////////20130615
//////		//step_event=2*pulsewidth/40*(Sample_freaq/25);
//////		step_event=L_event*3;
//////
//////	//光在光纤中传播的速度
//////	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
//////	//两个数据之间的时间间隔：
//////	double Sample_time=Sample_freaq;//放大了10^6倍
//////	Sample_time=1/Sample_time;
//////	//测量距离计算
//////	//  double Measure_distacne = Light_fiber_speed*Sample_time*paramLen;
//////
//////
//////	if(sGabor_Result->Valid_Num>1)
//////	{
//////		for(i=0;i<sGabor_Result->Valid_Num;i++)
//////		{
//////			if(sGabor_Result->Reflect_Type[i])//反射事件
//////			{
//////				//算反射高度
//////				if(i==0)
//////				{
//////					sGabor_Result->Reflect_Type[i]=1;
//////					continue;
//////				}
//////				if((step_event/15)>4)
//////					up_limit=sGabor_Result->Event_Array[i]-step_event/15;
//////				else up_limit=sGabor_Result->Event_Array[i]-4;
//////
//////				if(up_limit<sGabor_Result->Event_Array[i-1])up_limit=sGabor_Result->Event_Array[i-1];//sGabor_Result->Event_Array[i]+2;
//////				//if(up_limit<=0)up_limit=3;
//////				low_limit=sGabor_Result->Event_Array[i]+step_event/2;
//////				if(i<sGabor_Result->Valid_Num-1)
//////				{
//////					if(low_limit>sGabor_Result->Event_Array[i+1]&&(sGabor_Result->Event_Array[i+1]-sGabor_Result->Event_Array[i])>20)
//////						low_limit=sGabor_Result->Event_Array[i+1]-step_event/10;
//////					if(low_limit<sGabor_Result->Event_Array[i]+5)low_limit=sGabor_Result->Event_Array[i+1]-2;
//////				}
//////
//////				max_data=0;
//////				min_data=65535;
//////				for(k=up_limit;k<low_limit;k++)
//////				{
//////					if((max_data)<65535-input_data[k])
//////					{
//////						max_data=65535-input_data[k];
//////						max_data_no=k;
//////					}
//////					if((min_data)>65535-input_data[k])
//////					{
//////						min_data=65535-input_data[k];
//////						min_data_no=k;
//////					}
//////				}
//////				if(min_data_no>max_data_no)
//////				{
//////					//max_data=0;
//////					min_data=65535;
//////					for(k=up_limit;k<max_data_no;k++)
//////					{
//////						if(min_data>(65535-input_data[k]))
//////						{
//////							min_data=65535-input_data[k];
//////							min_data_no=k;
//////						}
//////					}
//////				}
//////				if(min_data_no>50)//对最小值做平均处理，消除噪声影响
//////				{
//////					Reflex_avg_dB=0;
//////					for(k=0;k<5;k++)
//////					{
//////						if(min_data_no-k>=0)
//////							Reflex_avg_dB=Reflex_avg_dB+65535-input_data[min_data_no-k];
//////					}
//////					Reflex_avg_dB=Reflex_avg_dB/5;
//////					min_data=Reflex_avg_dB;
//////				}
//////
//////				sGabor_Result->Event_Hight[i]=(max_data-min_data)/1000.0;
//////
//////				//前一个事件也为反射事件，判断两个反射事件的距离是否满足1个波长的距离，如果满足就计算损耗，不满足就
//////				//不计算损耗
//////				if(sGabor_Result->Reflect_Type[i-1]||i==1)
//////				{
//////					if((sGabor_Result->Event_Array[i-1]+3*step_event/2)>sGabor_Result->Event_Array[i])
//////					{
//////						sGabor_Result->Event_Loss[i]=0;
//////						//		continue;
//////					}
//////				}
//////				//算回波损耗
//////
//////
//////
//////			}
//////			//else//衰减事件  插入损耗计算/////////该段代码决定最终损耗的准确性
//////			{
//////				/*if(i==sGabor_Result->Valid_Num-1)
//////				{
//////				sGabor_Result->Event_Loss[i]=0;
//////				break;
//////				}*/
//////				/*if(sGabor_Result->Line_k[i]>0)dB_k_line=sGabor_Result->Line_k[i];
//////				else if(sGabor_Result->Line_k[i+1]>0)
//////				{
//////				dB_k_line=sGabor_Result->Line_k[i+1];
//////				}
//////				else*/
//////				{
//////					if(wavelength==1310)dB_k_line=Avg_loss_1310;//1310
//////					else if(wavelength==1490)dB_k_line=Avg_loss_1490;//1550
//////					else if(wavelength==1550)dB_k_line=Avg_loss_1550;//1550
//////					else if(wavelength==1625)dB_k_line=Avg_loss_1625;//1550
//////					else if(wavelength==1300)dB_k_line=Avg_loss_1300;//1550
//////					else if(wavelength==850)dB_k_line=Avg_loss_850;//1550
//////					else dB_k_line=0.186;//1550
//////				}
//////				if(i!=0)
//////				{
//////
//////					int avg_up=0,avg_low=0;
//////					up_limit=sGabor_Result->Event_Array[i]-step_event/8;
//////					if(up_limit<=3)up_limit=3;
//////					avg_up=input_data[up_limit-3]+input_data[up_limit-2]+input_data[up_limit-1]+input_data[up_limit]+input_data[up_limit+1]+input_data[up_limit+2]+input_data[up_limit+3];
//////					avg_up=avg_up/7;
//////					low_limit=sGabor_Result->Event_Array[i]+step_event;
//////					if(i<sGabor_Result->Valid_Num-1)
//////					{
//////						if(low_limit>sGabor_Result->Event_Array[i+1])
//////						{
//////							low_limit=sGabor_Result->Event_Array[i+1]-10;
//////							//sGabor_Result->Event_Loss[i]=0;
//////							//continue;
//////						}
//////					}
//////					if(low_limit<=3)low_limit=3;
//////
//////					avg_low=input_data[low_limit-3]+input_data[low_limit-2]+input_data[low_limit-1]+input_data[low_limit]+input_data[low_limit+1]+input_data[low_limit+2]+input_data[low_limit+3];
//////					avg_low=avg_low/7;
//////					dB_Hight=avg_up -avg_low ;
//////					//if(sGabor_Result->Reflect_Type[i]==0)/////////////////////////20130617
//////					dB_Hight=dB_Hight/1000+(low_limit-up_limit)*(Sample_time*Light_fiber_speed)/2000*dB_k_line;
//////					//else dB_Hight=dB_Hight/1000;
//////					sGabor_Result->Event_Loss[i]=-(dB_Hight);
//////					if(fabs(sGabor_Result->Event_Loss[i])<=0.005)
//////						sGabor_Result->Event_Loss[i]=0;
//////					if(sGabor_Result->Reflect_Type[i])
//////					{
//////						if(fabs(sGabor_Result->Event_Loss[i])<=0.005)sGabor_Result->Event_Loss[i]=0;
//////					}
//////					;//算插入损耗	
//////				}
//////				else
//////				{
//////					sGabor_Result->Event_Loss[i]=0;
//////				}
//////
//////			} 
//////
//////		}
//////	}
//////	if(sGabor_Result->Valid_Num)sGabor_Result->Event_Loss[sGabor_Result->Valid_Num-1]=0;
//////	//return sGabor_Result;
//////}
//////void Acount_return_loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe)
//////{
//////	int i=0;
//////	float return_tybe=0;
//////	float return_loss=0;
//////	float Pulse_width_status=0;
//////	if(pulsewidth==3)Pulse_width_status=5;
//////	else if(pulsewidth==5)Pulse_width_status=7.5;
//////	else Pulse_width_status=pulsewidth;
//////	for(i=0;i<sGabor_Result->Valid_Num;i++)
//////	{
//////		if(i>0)
//////		{
//////			//sumTotalLoss=sumTotalLoss+sGabor_Result->Line_k[i]/1000*(sGabor_Result->Event_Array[i]-sGabor_Result->Event_Array[i-1])+sGabor_Result->Event_Loss[i];
//////			//sGabor_Result->Total_Loss[i]=sumTotalLoss;
//////			if(sGabor_Result->Reflect_Type[i])//如果为反射事件，求回波损耗
//////			{
//////
//////				if(wavelength==1310)return_tybe=Return_loss_1310_tybe;
//////				else if(wavelength==1490)return_tybe=Return_loss_1490_tybe;
//////				else if(wavelength==1550)return_tybe=Return_loss_1550_tybe;
//////				else if(wavelength==1625)return_tybe=Return_loss_1625_tybe;
//////				else if(wavelength==1300)return_tybe=Return_loss_1300_tybe;
//////				else if(wavelength==850)return_tybe=Return_loss_850_tybe;
//////
//////				return_loss=sGabor_Result->Event_Hight[i]/5;
//////				return_loss=pow(10,return_loss)-1;
//////				sGabor_Result->Event_Hight[i]=(10*log10(Pulse_width_status/1000000000.0));
//////				//if(wavelength==1550)
//////				//sGabor_Result->Event_Hight[i]=sGabor_Result->Event_Hight[i]+10*log10(return_loss)+(-70-Return_loss_Tybe);//-(sGabor_Result->Event_Hight[i]+10*log10(return_loss))+(Return_loss_Tybe)+70;//
//////				//else sGabor_Result->Event_Hight[i]=sGabor_Result->Event_Hight[i]+10*log10(return_loss)+10.5;
//////				if(return_loss>0)
//////					sGabor_Result->Event_Hight[i]=-(sGabor_Result->Event_Hight[i]+10*log10(return_loss))-(return_tybe+Return_loss_Tybe);
//////				else sGabor_Result->Event_Hight[i]=70;
//////				if((sGabor_Result->Event_Hight[i])<=12.0)sGabor_Result->Event_Hight[i]=0;
//////				else if((sGabor_Result->Event_Hight[i])>=70.0)sGabor_Result->Event_Hight[i]=70;
//////			}
//////
//////			else sGabor_Result->Event_Hight[i]=0;
//////			//sGabor_Result->Event_Hight[i]=2*sGabor_Result->Event_Hight[i];
//////		}
//////	}
//////	//return sGabor_Result;
//////
//////}
//////void Acount_Total_Loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq)
//////{
//////	float start_loss_dB=0;
//////	int Event_start_mark_cn=sGabor_Result->Event_Array[0];
//////
//////	//光在光纤中传播的速度
//////	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
//////	//两个数据之间的时间间隔：
//////	double Sample_time=Sample_freaq;//放大了10^6倍
//////	Sample_time=1/Sample_time;
//////
//////	int i=0,j=0;
//////	/////////////////////////////////////////////////////////////////////////////////
//////	//	int pulseNum=0;
//////	//	switch(pulsewidth)
//////	//	{
//////	//	case 3:
//////	//		pulseNum=0;
//////	//		break;
//////	//	case 5:
//////	//		pulseNum=1;
//////	//		break;
//////	//	case 10:
//////	//		pulseNum=2;
//////	//		break;
//////	//	case 20:
//////	//		pulseNum=3;
//////	//		break;
//////	//	case 50:
//////	//		pulseNum=4;
//////	//		break;
//////	//	case 100:
//////	//		pulseNum=5;
//////	//		break;
//////	//	case 200:
//////	//		pulseNum=6;
//////	//		break;
//////	//	case 500:
//////	//		pulseNum=7;	
//////	//		break;
//////	//	case 1000:
//////	//		pulseNum=8;
//////	//		break;
//////	//	case 2000:
//////	//		pulseNum=9;
//////	//		break;
//////	//	case 5000:
//////	//		pulseNum=10;
//////	//		break;
//////	//	case 10000:
//////	//		pulseNum=11;
//////	//		break;
//////	//	case 20000:
//////	//		pulseNum=12;
//////	//		break;
//////	//	default:pulseNum=12;break;
//////	//	}
//////	//	//查找计算损耗的最佳起始点。
//////	//	int step_L=0;
//////	//	int Start_point=0,End_point=0;
//////	//	float avg_roias=0;
//////	//	int up_time=0,fault_time=0;
//////	//	int data1=0,data2=0;
//////	//	int count_success_time=0;
//////	//
//////	//	step_L=2*lEventGenerate(pulseNum, wavelength,Sample_freaq);
//////	//	if(sGabor_Result->Event_Array[0]<step_L)Start_point=step_L;
//////	//	else Start_point=sGabor_Result->Event_Array[0];
//////	//	if((sGabor_Result->Event_Array[1]-Start_point)<4*step_L)
//////	//	{
//////	//		End_point=sGabor_Result->Event_Array[1]-step_L/4;
//////	//	}
//////	//	else End_point=Start_point+4*step_L;
//////	//	for(i=Start_point;i<End_point;i++)
//////	//	{
//////	//		//求出段噪声。
//////	//		avg_roias=avg_roias+abs(input_data[i]-input_data[i+1]);
//////	//
//////	//	}
//////	//	avg_roias=2*avg_roias/(End_point-Start_point);
//////	//	if(avg_roias<100)avg_roias=100;
//////	//	if((End_point-Start_point)>20)
//////	//	{
//////	//		for(i=End_point;i>Start_point;i--)
//////	//		{
//////	//			fault_time=0;
//////	//			up_time=0;
//////	//			count_success_time=0;
//////	//			for(j=i;j>Start_point;j--)
//////	//			{
//////	//				data1=input_data[i];
//////	//				data2=input_data[j];
//////	//				if((data1-data2)>avg_roias)
//////	//				{
//////	//					up_time++;
//////	//					fault_time=0;
//////	//					if(up_time>=10)
//////	//					{
//////	//						//Start_point=i;
//////	//						count_success_time++;
//////	//						if(count_success_time>=5)
//////	//						{
//////	//							Start_point=i;
//////	//							break;
//////	//						}
//////	//						
//////	//					}
//////	//					continue;
//////	//				}
//////	//				else
//////	//				{
//////	//					fault_time++;
//////	//					
//////	//					if(fault_time>=3)
//////	//					{
//////	//						count_success_time=0;
//////	//						break;
//////	//					}
//////	//					
//////	//				}
//////	//			}
//////	//			if(j<=Start_point)Start_point=i;
//////	//		}
//////	//	}
//////	//	sGabor_Result->Event_Array[0]=Start_point;
//////	//
//////	///////////////////////////////////////////////////////////////////////////////////
//////	if(sGabor_Result->Valid_Num==2)
//////	{
//////		if(sGabor_Result->Line_k[1]==0)
//////		{
//////			sGabor_Result->Total_Loss[i]=0;
//////		}
//////		else
//////		{
//////			sGabor_Result->Total_Loss[1]=sGabor_Result->Line_k[1]*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000+0.02;
//////		}
//////	}
//////	else if(sGabor_Result->Valid_Num>2)
//////	{
//////		if(sGabor_Result->Line_k[1]!=0)
//////		{
//////			start_loss_dB=sGabor_Result->Line_k[1]*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
//////		}
//////		else if(sGabor_Result->Line_k[2]!=0)
//////		{
//////			start_loss_dB=sGabor_Result->Line_k[2]*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
//////		}
//////		else 
//////		{
//////			if(wavelength==1310)
//////			{
//////				start_loss_dB=Avg_loss_1310*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
//////			}
//////			else if(wavelength==1490)
//////			{
//////				start_loss_dB=Avg_loss_1490*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
//////			}
//////			else if(wavelength==1550)
//////			{
//////				start_loss_dB=Avg_loss_1550*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
//////			}
//////			else if(wavelength==1625)
//////			{
//////				start_loss_dB=Avg_loss_1625*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
//////			}
//////			else if(wavelength==1300)
//////			{
//////				start_loss_dB=Avg_loss_1300*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
//////			}
//////			else if(wavelength==850)
//////			{
//////				start_loss_dB=Avg_loss_850*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
//////			}
//////		}
//////		start_loss_dB=start_loss_dB+0.02;
//////		sGabor_Result->Total_Loss[1]=start_loss_dB;
//////		for(i=2;i<sGabor_Result->Valid_Num;i++)
//////		{
//////			if(sGabor_Result->Event_Array[i]>=15&&pulsewidth>10&&sGabor_Result->Event_Array[1]>=10)
//////			{
//////				sGabor_Result->Total_Loss[i]=(input_data[sGabor_Result->Event_Array[i]-15]+input_data[sGabor_Result->Event_Array[i]-14]+input_data[sGabor_Result->Event_Array[i]-13]+input_data[sGabor_Result->Event_Array[i]-12]+input_data[sGabor_Result->Event_Array[i]-11])/5
//////					-(input_data[sGabor_Result->Event_Array[1]-6]+input_data[sGabor_Result->Event_Array[1]-7]+input_data[sGabor_Result->Event_Array[1]-8]+input_data[sGabor_Result->Event_Array[1]-9]+input_data[sGabor_Result->Event_Array[1]-10])/5;
//////				sGabor_Result->Total_Loss[i]=(sGabor_Result->Total_Loss[i])/1000+start_loss_dB;//-sGabor_Result->Event_Loss[0];///-sGabor_Result->Event_Loss[0]20130617
//////				if(sGabor_Result->Total_Loss[i]<=0.1)sGabor_Result->Total_Loss[i]=0;
//////				if(i>0)
//////				{
//////
//////					for(j=0;j<i;j++)//如果后面的总损耗计算结果比前面的总损耗结果还要小，说明错误，记为0
//////					{
//////						if(sGabor_Result->Total_Loss[i]<sGabor_Result->Total_Loss[j])
//////							sGabor_Result->Total_Loss[i]=0;
//////					}
//////				}
//////
//////
//////			}
//////			else
//////			{
//////				sGabor_Result->Total_Loss[i]=0;
//////			}
//////
//////		}
//////	}
//////	//return sGabor_Result;
//////}
//////Gabor_Result Find_event_end_function(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq)
//////{
//////	int i=0,j=0,m=0,n=0;
//////	float *  data_buff=new float[20000];//[20000];
//////	memset(data_buff,0,20000*sizeof(float));
//////
////////	int* input_data_buff=new int[paramLen];//短时傅里叶变化结果Cn
////////	memset(input_data_buff,0,paramLen*sizeof(int));
//////
//////	int pulseNum=0;
//////
//////	switch(pulsewidth)
//////	{
//////	case 3:
//////		pulseNum=0;
//////		break;
//////	case 5:
//////		pulseNum=1;
//////		break;
//////	case 10:
//////		pulseNum=2;
//////		break;
//////	case 20:
//////		pulseNum=3;
//////		break;
//////	case 50:
//////		pulseNum=4;
//////		break;
//////	case 100:
//////		pulseNum=5;
//////		break;
//////	case 200:
//////		pulseNum=6;
//////		break;
//////	case 500:
//////		pulseNum=7;	
//////		break;
//////	case 1000:
//////		pulseNum=8;
//////		break;
//////	case 2000:
//////		pulseNum=9;
//////		break;
//////	case 5000:
//////		pulseNum=10;
//////		break;
//////	case 10000:
//////		pulseNum=11;
//////		break;
//////	case 20000:
//////		pulseNum=12;
//////		break;
//////	case 30:
//////		pulseNum=13;
//////		break;
//////	case 300:
//////		pulseNum=14;
//////		break;
//////	case 400:
//////		pulseNum=15;
//////		break;
//////	default:pulseNum=12;break;
//////	}
//////	int Pulse_step_point=(pulsewidth/40)*(Sample_freaq/25);
//////	if(Pulse_step_point<=20)Pulse_step_point=20;
//////	//Pulse_step_point=lEventGenerate(pulseNum,wavelength,Sample_freaq);
//////
//////
//////	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
//////	//两个数据之间的时间间隔：
//////	double Sample_time=Sample_freaq;//放大了10^6倍
//////	Sample_time=1/Sample_time;
//////
//////
//////
//////	float Single_point_distance=0;
//////	Single_point_distance=(Sample_time*Light_fiber_speed)/2;
//////
//////	int Event_finish[100];
//////
////////	int delete_buff[100];
//////	int delete_buff_point=0;
//////	int Event_start_point=0,Event_end_point=0;
//////
//////	int max_point=0;
//////	int MAX_value=0;
//////	float Avg_set_point_value=0;
//////	float Avg_K_line=0;
//////	int up_time=0,low_time=0;
//////	for(i=0;i<100;i++)
//////		Event_finish[i]=0;
//////	for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////	{
//////		//if(sGabor_Result.Reflect_Type[i]!=0)//反射事件
//////		{
//////
//////
//////			//找最高峰
//////			MAX_value=0;
//////			m=sGabor_Result.Event_Array[i]+Pulse_step_point;
//////			if(m>sGabor_Result.Event_Array[i+1])m=sGabor_Result.Event_Array[i+1];
//////			for(j=sGabor_Result.Event_Array[i]-Pulse_step_point/10;j<m;j++)
//////			{
//////				if(MAX_value<=(65535-input_data[j]))
//////				{
//////					MAX_value=65535-input_data[j];
//////					max_point=j;
//////				}
//////
//////			}
//////			//找到最高峰后，将最高峰作为结束点，开始从后往前找，找突变点。
//////
//////			Event_end_point=4*Pulse_step_point+max_point;
//////			if(Event_end_point>sGabor_Result.Event_Array[i+1])
//////				Event_end_point=3*Pulse_step_point+max_point;
//////			if(Event_end_point>sGabor_Result.Event_Array[i+1])
//////				Event_end_point=2*Pulse_step_point+max_point;
//////			if(Event_end_point>sGabor_Result.Event_Array[i+1])
//////				Event_end_point=Pulse_step_point+max_point;
//////			if(Event_end_point>sGabor_Result.Event_Array[i+1])
//////			{
//////
//////				Event_end_point=Pulse_step_point/2+max_point;
//////
//////			}
//////			if(Event_end_point>sGabor_Result.Event_Array[i+1])
//////			{
//////				continue;
//////			}
//////			Event_start_point=max_point;
//////			Avg_set_point_value=65535-(input_data[Event_end_point]+input_data[Event_end_point-1]
//////			+input_data[Event_end_point-2]+input_data[Event_end_point-3]+input_data[Event_end_point-4])/5;
//////			for(j=Event_end_point-(Event_end_point-Event_start_point)/4;j>Event_start_point;j--)
//////			{
//////				data_buff[j-Event_start_point]=(65535-(input_data[j]+input_data[j-1]+input_data[j+1])/3-Avg_set_point_value)/((Event_end_point-2-j)*Single_point_distance);
//////
//////			}
//////			Avg_K_line=0;
//////			for(j=Event_end_point-(Event_end_point-Event_start_point)/4;j>Event_end_point-3*(Event_end_point-Event_start_point)/8;j--)
//////			{
//////				Avg_K_line=Avg_K_line+data_buff[j-Event_start_point];
//////			}
//////			Avg_K_line=Avg_K_line/((Event_end_point-Event_start_point)/8);
//////			up_time=0;low_time=0;
//////			for(j=Event_end_point-(Event_end_point-Event_start_point)/4;j>Event_start_point;j--)
//////			{
//////				if(data_buff[j-Event_start_point]>1.1*Avg_K_line)
//////				{
//////					up_time++;
//////					if(Pulse_step_point/8>5)
//////					{
//////
//////						if(up_time>=Pulse_step_point/8)
//////						{
//////							// sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=j;
//////							Event_finish[i]=j-up_time;
//////							if(Event_finish[i]-sGabor_Result.Event_Array[i]<Pulse_step_point)
//////								Event_finish[i]=sGabor_Result.Event_Array[i]+6*Pulse_step_point/5;
//////							// return sGabor_Result;
//////							break;
//////						}
//////
//////					}
//////					else
//////					{
//////						if(up_time>=5)
//////						{
//////							// sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=j;
//////							Event_finish[i]=j-up_time;
//////							if(Event_finish[i]-sGabor_Result.Event_Array[i]<Pulse_step_point)
//////								Event_finish[i]=sGabor_Result.Event_Array[i]+6*Pulse_step_point/5;
//////							// return sGabor_Result;
//////							break;
//////						}
//////					}
//////				}
//////				else
//////				{
//////
//////					low_time++;
//////					if(low_time>=3)up_time=0;
//////				}
//////			}
//////			if(Event_finish[i]==0)
//////				Event_finish[i]=sGabor_Result.Event_Array[i]+Pulse_step_point;
//////
//////		}
//////
//////	}
//////	/*for(i=1;i<sGabor_Result.Valid_Num-1;i++)
//////	{
//////	sGabor_Result.Event_Loss[i]=((65535-input_data[sGabor_Result.Event_Array[i]-10])-(65535-input_data[Event_finish[i]]));
//////	sGabor_Result.Event_Loss[i]=sGabor_Result.Event_Loss[i]/1000;
//////	}*/
//////	n=sGabor_Result.Valid_Num-1;
//////	for(i=1;i<n;i++)
//////	{
//////		if(Event_finish[i]!=0)
//////		{
//////			sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=Event_finish[i];
//////			sGabor_Result.Event_Loss[sGabor_Result.Valid_Num]=0;
//////			sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=0;
//////			sGabor_Result.Line_k[sGabor_Result.Valid_Num]=0;
//////			sGabor_Result.Total_Loss[sGabor_Result.Valid_Num]=0;
//////			sGabor_Result.Event_type[sGabor_Result.Valid_Num++]='T';
//////		}
//////
//////
//////		//else sGabor_Result=deleteEvent(i,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq,-70);
//////	}
//////	delete[] data_buff;
//////	return sGabor_Result;
//////}
////////******************************************************************//
////////     删除事件
////////     deleteNum:所删除事件点序号
////////     wavelength:曲线波长
////////     pulsewidth：曲线脉宽
////////     input_data[]：分析的原始数据
////////******************************************************************//
////////******************************************************************//
////////     删除事件
////////     deleteNum:所删除事件点序号
////////     wavelength:曲线波长
////////     pulsewidth：曲线脉宽
////////     input_data[]：分析的原始数据
////////******************************************************************//
//////
////////Gabor_Result DeleteGhosting(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,float dB_Loss,float dB_reflex,float dB_End,float Sample_freaq)
////////{
////////	int Erro_point=0;//判断时允许的误差
////////	int i=0,j=0,k=0;
////////
////////
////////}
//////
//////
//////
//////
////////Gabor_Result smooth(int N,WORD input_data[],INT paramLen)
////////{
////////	int i=0,j=0;
////////	long sum=0;
////////	unsigned int M=paramLen;
////////	for (i = 0;i<M;i++)
////////	{
////////		sum = 0;
////////		if(i==M)
////////			data_from_file[i] = input_data[i];
////////		else if(i<N/2)
////////		{
////////			for (j = 0;j<(2*i-1);j++)
////////				sum = sum + input_data[j];
////////			data_from_file[i]=sum/(2*i-1);
////////		}
////////		else if((M-i)<(N/2-1))
////////		{
////////			for (j =0;j<(2*(M-i)+1);j++)
////////				sum = sum + input_data[M+1-j];
////////			data_from_file[i]=sum/(2*(M-i)+1);
////////		}
////////		else
////////		{
////////			for (j=0;j<N;j++)
////////				sum = sum + input_data[i-(N+1)/2+j]; 
////////			data_from_file[i] = sum/N;
////////		}
////////	}
////////return sGabor_Result;
////////
////////}
//////
//////
//////
//////////*****************************************************************************************/
///////*****************************************************************************
//////wavelength:波长
//////pulseWidth：脉宽
//////input_data[]：母线+实时测试曲线
//////paramLen  数据总长
//////dB_Loss   损耗阈值
//////dB_reflex 反射阈值
//////Sample_freaq 采样频率
//////Index_N    群折射率
//////start_point：监控起始点
//////end_point：  监控结束点
//////
//////返回：事件列表
//////
//////*********************************************************************/
//////
//////Gabor_Result The_monitoring_mode(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,float dB_Loss,float dB_reflex,float Sample_freaq,float Index_N,int start_point,int end_point)
//////{
//////#define deBug_enable 0
//////	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
//////	//两个数据之间的时间间隔：
//////	double Sample_time=Sample_freaq;//放大了10^6倍
//////	Sample_time=1/Sample_time;
//////	//测量距离计算
//////	double Measure_distacne = Light_fiber_speed*Sample_time*paramLen/2;
//////
//////	int i=0,j=0,k=0;
//////
//////	int L_event=0;
//////	int step_event;
//////	int pulseNum;
//////	switch(pulseWidth)
//////	{
//////	case 3:
//////		pulseNum=0;
//////		break;
//////	case 5:
//////		pulseNum=1;
//////		break;
//////	case 10:
//////		pulseNum=2;
//////		break;
//////	case 20:
//////		pulseNum=3;
//////		break;
//////	case 50:
//////		pulseNum=4;
//////		break;
//////	case 100:
//////		pulseNum=5;
//////		break;
//////	case 200:
//////		pulseNum=6;
//////		break;
//////	case 500:
//////		pulseNum=7;	
//////		break;
//////	case 1000:
//////		pulseNum=8;
//////		break;
//////	case 2000:
//////		pulseNum=9;
//////		break;
//////	case 5000:
//////		pulseNum=10;
//////		break;
//////	case 10000:
//////		pulseNum=11;
//////		break;
//////	case 20000:
//////		pulseNum=12;
//////		break;
//////	case 30:
//////		pulseNum=13;
//////		break;
//////	case 300:
//////		pulseNum=14;
//////		break;
//////	case 400:
//////		pulseNum=15;
//////		break;
//////
//////	default:pulseNum=12;break;
//////	}
//////	L_event=lEventGenerate(pulseNum,wavelength,Sample_freaq);
//////	if(pulseWidth>=500)/////////////////////////////////////////20130615
//////		step_event=2*pulseWidth*Sample_freaq/25000;
//////
//////	int pulse_step_point=0;//一个脉宽的采样点数
//////	int data_length=paramLen/2;
//////	int* Parameter_data_buff=new int[data_length];//短时傅里叶变化结果Cn
//////	memset(Parameter_data_buff,0,data_length*sizeof(int));
//////	int* Testing_data_buff=new int[data_length];
//////	memset(Testing_data_buff,0,data_length*sizeof(int));
//////	
//////	int* data_near=new int[data_length];
//////	memset(data_near,0,data_length*sizeof(int));
//////
//////	pulse_step_point=2*pulseWidth/25*(Sample_freaq/25);
//////	//pulse_step_point=100;
//////
//////    Gabor_Result sGabor_Result;
//////	for(i=0;i<data_length;i++)//分离数据，参考数据和原始数据分离
//////	{
//////		Parameter_data_buff[i]=65535-input_data[i];
//////		Testing_data_buff[i]=65535-input_data[i+data_length];
//////	}
//////   sGabor_Result.Valid_Num=0;
//////   sGabor_Result.Event_Array[0];
//////	//////寻找监控起始点,以最高点为监控起始点
//////	int max_data=0;
//////	int max_data_number=5;
//////	int min_data=65535;
//////	int min_data_number=5;
//////	for(i=5;i<3*pulse_step_point;i++)
//////	{
//////		if(max_data<=Parameter_data_buff[i])
//////		{
//////			max_data=Parameter_data_buff[i];
//////			max_data_number=i;
//////		}
//////	}
//////	/////寻找监控结束点
//////
//////	//计算参数曲线的监控点与测量曲线的监控点的差值
//////	if(start_point==0)start_point=max_data_number;
//////	float D_value_dB=Parameter_data_buff[start_point]-Testing_data_buff[start_point];
//////	D_value_dB=0;
//////	for(i=0;i<10;i++)
//////	{
//////		D_value_dB=D_value_dB+(Parameter_data_buff[start_point+i]-Testing_data_buff[start_point+i]);
//////	}
//////	D_value_dB=D_value_dB/10;
//////	//平移测量曲线
//////	for(i=0;i<data_length;i++)
//////	{
//////		Testing_data_buff[i]=Testing_data_buff[i]+D_value_dB;
//////	}
//////
//////	//查找故障点
//////	int up_time=0,down_time=0,D_value_dB_point=0;
//////	float Loss_accout=0;
//////	float AVG_loss=0;
//////	sGabor_Result.Valid_Num=0;
//////    Loss_accout=0;
//////	if(dB_Loss<=0.3)dB_Loss=0.3;
//////	for(i=start_point;i<end_point;i++)
//////	{
//////		
//////		
//////		D_value_dB_point=(Parameter_data_buff[i]-Testing_data_buff[i])/1000;
//////		if(D_value_dB_point>=(dB_Loss+Loss_accout))//测试曲线比参考曲线低
//////		{
//////			down_time++;
//////			up_time=0;
//////			if(down_time>=pulse_step_point/2)
//////			{
//////				sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=i-down_time;
//////				AVG_loss=0;
//////				for(j=i-up_time;j<i;j++)//算平均损耗
//////				{
//////					AVG_loss=AVG_loss+(Parameter_data_buff[j]-Parameter_data_buff[j]-Testing_data_buff[j]);
//////				}
//////				if(up_time!=0)
//////				AVG_loss=AVG_loss/up_time/1000;
//////				sGabor_Result.Event_Loss[sGabor_Result.Valid_Num++]=AVG_loss;
//////				i=i+pulse_step_point/2;
//////
//////				down_time=0;
//////				up_time=0;
//////				if(sGabor_Result.Valid_Num>=99)break;
//////				for(k=0;k<sGabor_Result.Valid_Num;k++)
//////				{
//////					Loss_accout=Loss_accout+sGabor_Result.Event_Loss[k];
//////				}
//////#if deBug_enable
//////				break;
//////#else 
//////				continue;
//////#endif
//////				
//////			}
//////		}
//////		else//测量曲线比参考曲线高
//////		{
//////			up_time++;
//////			if(up_time>=2)down_time=0;
//////		}
//////	}
//////	////查找是否为反射峰后边沿，如果为后延，就将其移动到前边沿
//////	//{
//////	//	for(i=0;i<paramLen-1;i++)
//////	//	{
//////	//		data_near[i]=Testing_data_buff[i+1]-Testing_data_buff[i];
//////	//		if(data_near[i]<100)data_near[i]=0;
//////	//	}
//////	//	
//////	//	for(i=0;i<sGabor_Result.Valid_Num;i++)
//////	//	{
//////	//		max_data=0;
//////	//		max_data_number=0;
//////	//		min_data=65535;
//////	//		min_data_number=0;
//////	//		for(j=0;j<4*L_event;j++)
//////	//		{
//////	//			if(sGabor_Result.Event_Array[i]-j>0)
//////	//			{
//////	//				if(max_data<=(65535-input_data[sGabor_Result.Event_Array[i]-j]))
//////	//				{
//////	//					max_data=65535-input_data[sGabor_Result.Event_Array[i]-j];
//////	//					max_data_number=input_data[sGabor_Result.Event_Array[i]-j];
//////	//				}
//////	//				if(min_data>=(65535-input_data[sGabor_Result.Event_Array[i]-j]))
//////	//				{
//////	//					min_data=65535-input_data[sGabor_Result.Event_Array[i]-j];
//////	//					min_data_number=input_data[sGabor_Result.Event_Array[i]-j];
//////	//				}
//////
//////	//			}
//////	//		}
//////	//		if(sGabor_Result.Event_Array[i]>4*L_event)
//////	//		{
//////	//			for(j=sGabor_Result.Event_Array[i]-4*L_event;j<sGabor_Result.Event_Array[i];j++)
//////	//			{
//////	//				if(data_near[j]>0)
//////	//				{
//////	//					if(data_near[j+1]>0)
//////	//						if(data_near[j+2]>0)
//////	//							if(data_near[j+3]>0)
//////	//								if(data_near[j+4]>0)
//////	//								{
//////	//									if(j<max_data_number)
//////	//									{
//////	//										if(j+L_event>max_data_number)
//////	//											sGabor_Result.Event_Array[i]=j;
//////	//										break;
//////	//									}
//////	//								}
//////	//				}
//////	//			}
//////	//		}
//////	//	}
//////	//	
//////	//}
//////#if deBug_enable
//////	sGabor_Result.Event_Array[2]=end_point;
//////	sGabor_Result.Event_Array[1]=sGabor_Result.Event_Array[0];
//////	sGabor_Result.Event_Loss[1]=sGabor_Result.Event_Loss[0];
//////	sGabor_Result.Event_Array[0]=start_point;
//////	sGabor_Result.Valid_Num=3;
//////#else 
//////	for(i=0;i<sGabor_Result.Valid_Num;i++)
//////	{
//////		sGabor_Result.Event_Array[i+1]=sGabor_Result.Event_Array[i];
//////		sGabor_Result.Event_Loss[i+1]=sGabor_Result.Event_Loss[i];
//////	}
//////	sGabor_Result.Valid_Num=sGabor_Result.Valid_Num+2;
//////	sGabor_Result.Event_Array[0]=start_point;
//////	sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]=end_point;
//////#endif
//////	/*if()
//////	sGabor_Result.Valid_Num=1;
//////	for(i=1;i<sGabor_Result.Valid_Num;i++)
//////	{
//////		sGabor_Result.Event_Array[i]=sGabor_Result.Event_Array[i-1];
//////	}
//////	sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=end_point;
//////	sGabor_Result.Event_Array[0]=start_point;*/
//////	//sGabor_Result.Valid_Num=3;
//////	delete[] Parameter_data_buff;
//////	delete[] Testing_data_buff;
//////return sGabor_Result;
//////
//////}
//////
//////
//////
//////Gabor_Result Search_fiber_end_function(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,float Sample_freaq,float thresholdUpSet )
//////{
//////	int i,j,k;
//////	unsigned char  delete_flag[100];
//////	int L_event=0;
//////	int max_event=0;
//////	int max_event_mark=0;
//////	float fiber_end_radio=0;
//////	float Upset_value=30;
//////	int* Count_data_buff=new int[paramLen];
//////	memset(Count_data_buff,0,paramLen*sizeof(int));
//////	//int Count_data_buff[10000];
//////    int Event_step_length=0;
//////	if(pulseWidth==3)Event_step_length=4;
//////	else if(pulseWidth==5)Event_step_length=6;
//////	else Event_step_length=4*pulseWidth/5;
//////
//////	int data_buff_d=0;
//////
//////    Gabor_Result sGabor_Result;
//////
//////    sGabor_Result.Valid_Num=0;
//////	for(i=0;i<100;i++)delete_flag[i]=0;
//////
//////    if(paramLen<201)
//////	{
//////		sGabor_Result.Valid_Num=0;
//////		return sGabor_Result;
//////	}
//////
//////	for(i=0;i<paramLen-1;i++)
//////	{
//////		Count_data_buff[i]=input_data[i]-input_data[i+1];
//////	}
//////    for(i=paramLen-1;i>paramLen-51;i--)
//////	{
//////		fiber_end_radio=fiber_end_radio+(65536-input_data[i]);
//////	}
//////	fiber_end_radio=fiber_end_radio/50;
//////	for(i=0;i<paramLen-5;i++)
//////	{
//////		if(Count_data_buff[i]>Upset_value)
//////		{
//////			if(Count_data_buff[i+1]>Upset_value)
//////				if(Count_data_buff[i+2]>Upset_value)
//////					if(Count_data_buff[i+3]>Upset_value)
//////						if(Count_data_buff[i+4]>-400)
//////					    {
//////						if(65535-input_data[i+4]>2*fiber_end_radio+1000)
//////							if(65535-input_data[i+5]>2*fiber_end_radio+1000)
//////								//if(65535-input_data[i+6]>2*fiber_end_radio+1000)
//////								{
//////									max_event=0;
//////									max_event_mark=0;
//////									for(j=0;j<6;j++)
//////									{
//////										if(max_event<65535-input_data[i+j])
//////										{
//////											max_event=65535-input_data[i+j];
//////											max_event_mark=i+j;
//////										}
//////									}
//////									data_buff_d=(max_event-(65535-input_data[i]));
//////									if(data_buff_d>=300&&i>=6)//要求反射峰的高度要大于1dB
//////									{
//////										sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=i;
//////										sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=1;
//////										sGabor_Result.Event_Hight[sGabor_Result.Valid_Num]=data_buff_d/1000;
//////										sGabor_Result.Event_Loss[sGabor_Result.Valid_Num]=0;
//////										sGabor_Result.Line_k[sGabor_Result.Valid_Num]=0;
//////										sGabor_Result.Event_type[sGabor_Result.Valid_Num]='F';
//////										i=i+Event_step_length;
//////										sGabor_Result.Valid_Num++;
//////									}
//////									
//////								}
//////						
//////					}
//////		}
//////	}
//////
//////	//算法二
//////	{
//////
//////	}
//////	//鬼影判断
//////	if(sGabor_Result.Valid_Num>=3)
//////	{
//////		float doint1,doint2,doint3,doint4;
//////		float data_max1=0,data_max2=0;
//////		int data_max_mark1=0,data_max_mark2=0;
//////		int Reflex_width1=0,Reflex_width2=0;
//////		float data_distance=0;
//////		for(i=sGabor_Result.Valid_Num-2;i>0;i--)
//////		{
//////			data_distance=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-2*sGabor_Result.Event_Array[i];
//////			
//////			if(data_distance<=20&&data_distance>=0)
//////			{
//////				doint1=0;
//////				doint2=0;
//////				doint3=0;
//////				doint4=0;
//////
//////				doint1=65535-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]];
//////				doint3=65535-input_data[sGabor_Result.Event_Array[i]];
//////				for(j=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1];j<sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+3*L_event;j++)
//////				{
//////					if(j>paramLen-3)break;
//////					if(data_max1<=65535-input_data[j])
//////					{
//////						data_max1=65535-input_data[j];
//////						data_max_mark1=j;
//////					}
//////				}
//////				for(j=data_max_mark1;j<data_max_mark1+10*L_event;j++)
//////				{
//////					if(j>paramLen-3)break;
//////					if(65535-input_data[j]<=doint1)
//////					{
//////						if(65535-input_data[j+1]<=doint1)
//////						{
//////							break;
//////						}
//////					}
//////				}
//////				Reflex_width1=j-sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1];
//////
//////				for(j=sGabor_Result.Event_Array[i];j<sGabor_Result.Event_Array[i]+3*L_event;j++)
//////				{
//////					if(j>paramLen-3)break;
//////					if(data_max2<=65535-input_data[j])
//////					{
//////						data_max2=65535-input_data[j];
//////						data_max_mark2=j;
//////					}
//////				}
//////				for(j=data_max_mark2;j<data_max_mark2+10*L_event;j++)
//////				{
//////					if(j>paramLen-3)break;
//////					if(65535-input_data[j]<=doint2)
//////					{
//////						if(65535-input_data[j+1]<=doint2)
//////						{
//////							break;
//////						}
//////					}
//////				}
//////				Reflex_width2=j-sGabor_Result.Event_Array[i];
//////				if(Reflex_width2>=2*Reflex_width1)//前面的反射峰宽度是后面的反射峰宽度的两倍以上，就认为后面的反射峰为前面反射峰的鬼影
//////				{
//////					if(Reflex_width1<=4*L_event)
//////					sGabor_Result.Valid_Num=i+1;break;
//////				}
//////			}
//////		}
//////		//求出每个峰的凸起高度
//////		//{
//////		//	float data_min=0;
//////		//	int data_min_mark=0;
//////		//	for(i=1;i<=sGabor_Result.Valid_Num-1;i++)
//////		//	{
//////		//		data_max1=0;
//////		//		data_min=65536;
//////		//		for(j=sGabor_Result.Event_Array[i];j<sGabor_Result.Event_Array[i]+20;j++)
//////		//		{
//////		//			if(j<=sGabor_Result.Valid_Num-2)
//////		//				if(j>sGabor_Result.Event_Array[j+1])break;
//////		//			if(data_max1<65535-input_data[j])
//////		//			{
//////		//				data_max1=65535-input_data[j];
//////		//				data_max1=(65535-input_data[j]+65535-input_data[j+1])/2;
//////		//				data_max_mark1=j;
//////		//			}
//////		//			if(data_min>65535-input_data[j])
//////		//			{
//////		//				if(j>data_max_mark1)break;
//////		//				data_min=65535-input_data[j];
//////		//				data_min=((65535-input_data[j])+(65535-input_data[j-1]))/2;
//////		//				data_min_mark=j;
//////		//			}
//////		//		}
//////		//		sGabor_Result.Event_Hight[i]=(data_max1-data_min)/1000;
//////		//		
//////		//	}
//////		//}
//////		for(i=1;i<=sGabor_Result.Valid_Num-1;i++)
//////		{
//////			//if(sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[i-1]<=24）//小于6米
//////			//	if(sGabor_Result.Event_Hight[i]<0.8)
//////			delete_flag[i]=0;
//////			if(sGabor_Result.Event_Hight[i]<3.0)//反射峰高度小于3dB
//////			{
//////				if(sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[i-1]<=24)//小于6米
//////				{
//////					delete_flag[i]=1;
//////				}
//////			}
//////		}
//////		j=0;
//////		for(i=0;i<sGabor_Result.Valid_Num;i++)
//////		{
//////			if(delete_flag[i]==0)
//////			{
//////				sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
//////				sGabor_Result.Event_Hight[j]=sGabor_Result.Event_Hight[i];
//////				sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
//////				j++;
//////			}
//////		}
//////		sGabor_Result.Valid_Num=j;
//////
//////	}
//////
//////   delete[] Count_data_buff;
//////   if(sGabor_Result.Valid_Num>0)
//////   {
//////	   if(sGabor_Result.Valid_Num==1)
//////	   {
//////
//////		   sGabor_Result.Event_Array[1]=sGabor_Result.Event_Array[0];
//////		   sGabor_Result.Event_Array[0]=3;
//////		   sGabor_Result.Valid_Num++;
//////	   }
//////   sGabor_Result.Event_type[sGabor_Result.Valid_Num-1]='E';
//////   }
//////
//////   {
//////	   float data_min=0;
//////	   int data_min_mark=0;
//////	   for(i=1;i<sGabor_Result.Valid_Num;i++)
//////	   {
//////		   data_min=65535;
//////		   data_min_mark=sGabor_Result.Event_Array[i];
//////		   for(j=sGabor_Result.Event_Array[i]-3;j<sGabor_Result.Event_Array[i]+2;j++)
//////		   {
//////			   if(data_min>=65535-input_data[j])
//////			   {
//////				   data_min=65535-input_data[j];
//////				   data_min_mark=j;
//////			   }
//////			   
//////		   }
//////		   sGabor_Result.Event_Array[i]=data_min_mark;
//////	   }
//////   }
//////   return sGabor_Result;
//////}
//////
//////
//////
//////
//////int Search_long_fiber_end(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,float Sample_freaq)
//////{
//////	int i=0,j=0;
//////	int End_nois_Max=0;//末端的噪声最高值
//////	long Avg_End_noise = 0 ;//末端噪声的平均水平
//////	int return_point_number=paramLen;
//////	int count1=0,count2=0;
//////	int pulse_step=0;
//////	int Step_start_point=0;
//////	if(pulseWidth==10000)pulse_step=250;
//////	else if(pulseWidth==20000)pulse_step=500;
//////	else pulse_step=250;
//////	if(pulseWidth>=10000&&Sample_freaq==25&&paramLen>=25000)
//////	{
//////	  for(i=paramLen-1;i>paramLen-501;i--)
//////	  {
//////		  if(End_nois_Max<65535-input_data[i])
//////		  {
//////			  End_nois_Max=65535-input_data[i];
//////			  Avg_End_noise=Avg_End_noise+65535-input_data[i];
//////		  }
//////	  }
//////	  Avg_End_noise=Avg_End_noise/500;
//////	  if(End_nois_Max<3000)End_nois_Max=3000;
//////	  if(Avg_End_noise<500)Avg_End_noise=End_nois_Max/2;
//////	  for(i=paramLen;i>20000;i--)
//////	  {
//////		  if((65535-input_data[i])>=Avg_End_noise)
//////		  {
//////			  count1++;
//////			  count2=0;
//////			  if(count1==1)Step_start_point=i;
//////			  if(count1>=3*pulse_step/2)
//////			  {
//////				  return_point_number=Step_start_point;
//////			  }
//////		  }
//////		  else
//////		  {
//////			  count2++;
//////			  if(count2>=3)count1=0;
//////		  }
//////	  }
//////	}
//////	/*for(i=return_point_number;i<paramLen;i++)
//////	{
//////		//input_data[i]=65535-(65535-input_data[i])/2;
//////		input_data[i]=(input_data[i]+input_data[i+1])/2;
//////		if(65535-input_data[i]>End_nois_Max)input_data[i]=65535;//65535-(65535-input_data[i])/2;
//////		else input_data[i]=65535-(65535-input_data[i])/2;;
//////	}*/
//////	return return_point_number;
//////
//////}


