#include <math.h>

#define SAMPLE_ERRO 0
#define Start_Fiber_enable 1

#define FISCAN9 0

#define D26  0

#define DEBUG 0

#define Avg_loss_1310  0.320
#define Avg_loss_1550  0.182
#define Avg_loss_1490  0.192
#define Avg_loss_1625  0.192
#define Avg_loss_1650  0.22
#define Avg_loss_1300  0.6
#define Avg_loss_850  3.0
#define Return_loss_1310_tybe -79
#define Return_loss_1550_tybe -81
#define Return_loss_1490_tybe -80
#define Return_loss_1625_tybe -80.5
#define Return_loss_1650_tybe -80
#define Return_loss_1300_tybe -70.5
#define Return_loss_850_tybe -60.5



LPCTSTR Version_number()
{

	#if SAMPLE_ERRO
	   #if FISCAN9
		return _T("FISCAN9-G160114-TNEW");
	   #else 
	    return _T("G160114-OLD");
	   #endif
	#else
		#if FISCAN9
			return _T("FISCAN9-G160114-TNEW");
		#else 
            #if D26
	          return _T("MINI-D26-G160118");
            #else 
		    return _T("G160407-SNEW-ORL-TOT");
            #endif
		#endif
	#endif

}


int Event_Array_End[100];

int Event_Array_End_function(int number)
{

	return Event_Array_End[number];
}

float PulseWidth_Power_k(int wavelength,int pulsewidth,float Sample_freaq)
{
	//用以计算合适的步进
	float k_tab=0;


	switch(pulsewidth)
	{
	case 3:

		k_tab=1;
		break;
	case 5:

		k_tab=1;
		break;
	case 10:

		k_tab=1;
		break;
	case 20:

		k_tab=1;
		break;
	case 30:

		k_tab=1;
		break;
	case 40:

		k_tab=1;
		break;

	case 50:

		k_tab=1;
		break;

	case 100:

		k_tab=1;
		break;
	case 200:

		k_tab=1;
		break;
	case 300:

		k_tab=1;
		break;
	case 500:

		k_tab=1;
		break;
	case 1000:

		k_tab=1;
		break;
	case 2000:

		k_tab=1;
		break;
	case 5000:

		k_tab=1;
		break;
	case 10000:

		k_tab=1;
		break;
	case 20000:

		k_tab=1;
		break;
	default:

		k_tab=1;
		break;
	}
	return k_tab;
}

int Step_point_count(int pulsewidth,int wavelenght, float Sample_freaq)
{
	int step_point=0;
	float k_tab=0;


#if D26
	switch(pulsewidth)
	{
	case 3:
		step_point=1;
		break;
	case 5:
		step_point=2;
		break;
	case 10:
		step_point=3;
		break;
	case 20:
		step_point=3;
		break;
	case 40:
		step_point=3;
		break;
	case 50:
		step_point=3;
		break;
	case 100:
		step_point=6;
		break;
	case 200:
		step_point=8;
		break;
	case 500:
		step_point=20;
		break;
	case 1000:
		step_point=40;
		break;
	case 2000:
		step_point=100;
		break;
	case 5000:
		step_point=220;//125;
		break;
	case 10000:
		step_point=250;
		break;
	case 20000:
		step_point=500;
		break;
	default:
		step_point=pulsewidth/2.5;
		break;
	}
#else 
	switch(pulsewidth)
	{
	case 3:
		step_point=1;
		break;
	case 5:
		step_point=2;
		break;
	case 10:
		step_point=3;
		break;
	case 20:
		step_point=3;
		break;
	case 40:
		step_point=3;
		break;
	case 50:
		step_point=3;
		break;
	case 100:
		step_point=6;
		break;
	case 200:
		step_point=8;
		break;
	case 500:
		step_point=30;
		break;
	case 1000:
		step_point=40;
		break;
	case 2000:
		step_point=50;
		break;
	case 5000:
		step_point=125;//125;
		break;
	case 10000:
		step_point=250;
		break;
	case 20000:
		step_point=500;
		break;
	default:
		step_point=pulsewidth/2.5;
		break;
	}
#endif
	step_point=step_point*(Sample_freaq/25);
	if(step_point<3)step_point=3;




	k_tab=PulseWidth_Power_k(wavelenght,pulsewidth,Sample_freaq);
	step_point=step_point*(k_tab*100)/100;

#if SAMPLE_ERRO
	if(Sample_freaq==25)
	{
		switch(pulsewidth)
		{
		case 3:
			step_point=20;
			break;
		case 5:
			step_point=20;
			break;
		case 10:
			step_point=20;
			break;
		case 20:
			step_point=20;
			break;
		case 30:
			step_point=35;
			break;
		case 40:
			step_point=40;
			break;
		case 50:
			step_point=40;
			break;
		case 100:
			step_point=44;
			break;
		case 200:
			step_point=48;
			break;
		case 300:
			step_point=66;
			break;
		case 400:
			step_point=70;
			break;
		case 500:
			step_point=80;
			break;
		default:
			break;
		}

	}
#endif


	return step_point;
}

float Avg_loss_wave_lenght_count(int wavelength)
{
	float Avg_loss_wave_lenght=0;
	switch(wavelength)
	{
	case 850:
		Avg_loss_wave_lenght=Avg_loss_850;
		break;
	case 1300:
		Avg_loss_wave_lenght=Avg_loss_1300;
		break;
	case 1310:
		Avg_loss_wave_lenght=Avg_loss_1310;
		break;
	case 1490:
		Avg_loss_wave_lenght=Avg_loss_1490;
		break;
	case 1550:
		Avg_loss_wave_lenght=Avg_loss_1550;
		break;
	case 1625:
		Avg_loss_wave_lenght=Avg_loss_1625;
		break;
	case 1650:
		Avg_loss_wave_lenght=Avg_loss_1650;
		break;
	default:
		Avg_loss_wave_lenght=Avg_loss_1550;
		break;
	}
	return Avg_loss_wave_lenght;
}
int Reflex_Hight_count(int pulsewidth,int wavelength,float Sample_freaq)
{
	int Reflex_Hight=0;



	switch(pulsewidth)
	{
	case 3:
		Reflex_Hight=2500;
		break;
	case 5:
		Reflex_Hight=2000;
		break;
	case 10:
		Reflex_Hight=1800;
		break;
	case 20:
		Reflex_Hight=1700;
		break;
	case 40:
		Reflex_Hight=1600;
		break;
	case 50:
		Reflex_Hight=1000;
		break;
	case 100:
		Reflex_Hight=500;
		break;
	case 200:
		Reflex_Hight=500;
		break;
	case 500:
		Reflex_Hight=500;
		break;
	case 1000:
		Reflex_Hight=200;
		break;
	case 2000:
		Reflex_Hight=100;
		break;
	case 5000:
		Reflex_Hight=100;
		break;
	case 10000:
		Reflex_Hight=50;
		break;
	case 20000:
		Reflex_Hight=50;
		break;
	default:
		Reflex_Hight=1000;
		break;
	}


#if SAMPLE_ERRO
	if(Sample_freaq==25)
	{
		switch(pulsewidth)
		{
		case 3:
			Reflex_Hight=2000;
			break;
		case 5:
			Reflex_Hight=1500;
			break;
		case 10:
			Reflex_Hight=1000;
			break;
		case 20:
			Reflex_Hight=1000;
			break;
		case 40:
			Reflex_Hight=1000;
			break;
		case 50:
			Reflex_Hight=500;
			break;
		case 100:
			Reflex_Hight=500;
			break;
		case 200:
			Reflex_Hight=200;
			break;
		case 500:
			Reflex_Hight=200;
			break;
		default:
			break;
		}
	}
#endif



	if(wavelength==850||wavelength==1300)Reflex_Hight=Reflex_Hight/2;
	return Reflex_Hight;
}
int Double_lenght_erro_function(int pulsewidth,int wavelength,float Sample_freaq)
{
	int point_number=0;
	switch(pulsewidth)
	{
	case 3:
		point_number=2;
		break;
	case 5:
		point_number=2;
		break;
	case 10:
		point_number=2;
		break;
	case 20:
		point_number=2;
		break;
	case 40:
		point_number=2;
		break;
	case 50:
		point_number=4;
		break;
	case 100:
		point_number=4;
		break;
	case 200:
		point_number=2;
		break;
	case 500:
		point_number=2;
		break;
	case 1000:
		point_number=2;
		break;
	case 2000:
		point_number=2;
		break;
	case 5000:
		point_number=3;
		break;
	case 10000:
		point_number=3;
		break;
	case 20000:
		point_number=3;
		break;
	default:
		point_number=3;
		break;
	}
	point_number=point_number*((Sample_freaq/25)/4)+1;
	return point_number;
}


//////Gabor_Result K_Line_count(int puse_point,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
//////Gabor_Result Acount_Loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
//////Gabor_Result Acount_Total_Loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
//////Gabor_Result Optical_grating(int wavelength,int pulsewidth,WORD input_data[],INT paramLen,Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float dB_reflex);
//////Gabor_Result Acount_return_loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe);
//////Gabor_Result Find_Reflex_Event_end_function(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
//Gabor_Result K_Line_count(int puse_point,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
void K_Line_count(int puse_point,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq);
//Gabor_Result Acount_Loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
void Acount_Loss(int wavelength,int pulsewidth,WORD input_data[],INT paramLen,Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq);
//Gabor_Result Acount_Total_Loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
void Acount_Total_Loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq);
Gabor_Result Optical_grating(int wavelength,int pulsewidth,WORD input_data[],INT paramLen,Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float dB_reflex);
//Gabor_Result Acount_return_loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe);
void Acount_return_loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe);
Gabor_Result Find_Reflex_Event_end_function(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
void deleteEvent_New(int deleteNum,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe);
int lEventGenerate(int pulseNum,int wavelength,float Sample_freaq);
//Gabor_Result K_Line_limite(int wavelength,Gabor_Result sGabor_Result);
void K_Line_limite(int wavelength,Gabor_Result* sGabor_Result);
Gabor_Result Search_fiber_end_function(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,float Sample_freaq,float thresholdUpSet );
int Search_long_fiber_end(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,float Sample_freaq);
void K_Line_count(int puse_point,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result *sGabor_Result,float Index_N,float Sample_freaq)
{

	//先求各段光纤的斜率：只要计算删除点所在点的下一个点的特性
	int up_limit,low_limit;
	int step_event=puse_point*2;
	if(Sample_freaq>=400)step_event=step_event/2;
	if(pulsewidth>=2000)/////////////////////////////////////////20130615
		step_event=2*pulsewidth/40*(Sample_freaq/25);
	if(step_event<20)step_event=20;
	float* sum_k=new float[2000];//短时傅里叶变化结果Cn
	memset(sum_k,0,2000*sizeof(float));
	//double sum_k[20];
	double dB_k_k_1=0,dB_k_k_2=0;

	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
	//两个数据之间的时间间隔：
	double Sample_time=Sample_freaq;//放大了10^6倍
	Sample_time=1/Sample_time;
	//测量距离计算
	int Reflex_Event_start_mark_cn=sGabor_Result->Event_Array[0];
	int for_num=0;
	int i=0,j=0,k=0;
	float damage_value=0;
	
	for(i=0;i<sGabor_Result->Valid_Num-1;i++)
	{
		for_num=0;

		low_limit=sGabor_Result->Event_Array[i+1]-10;
		if(low_limit<=0)low_limit=10;
		up_limit=sGabor_Result->Event_Array[i]+(sGabor_Result->Event_Array[i+1]-sGabor_Result->Event_Array[i])/8;
		if(up_limit<=0)break;
		if(up_limit<sGabor_Result->Event_Array[i]+3*step_event/2)up_limit=sGabor_Result->Event_Array[i]+3*step_event/2;//20130625

		low_limit=low_limit-(sGabor_Result->Event_Array[i+1]-sGabor_Result->Event_Array[i])/8;


		if(low_limit<=sGabor_Result->Event_Array[i]+step_event/8)//相邻两个事件的距离太近，不适合算斜率，
		{
			sGabor_Result->Line_k[i+1]=0;
				continue;
		}
		else if(low_limit<up_limit+step_event/4)
		{
			low_limit=sGabor_Result->Event_Array[i];
			up_limit=sGabor_Result->Event_Array[i]-step_event;
			if(up_limit<=0)up_limit=10;
		}
		else
		{
			sGabor_Result->Line_k[i+1]=0;
			for_num=(sGabor_Result->Event_Array[i+1]-sGabor_Result->Event_Array[i])/8;
			//	if(for_num<20)for_num=20;
			//else
			if(for_num>200)for_num=200;
			for(k=4;k<for_num;k++)
			{
				if(up_limit-k<=0)break;
				dB_k_k_1=input_data[up_limit+k];
				dB_k_k_2=input_data[low_limit+k];
				if(low_limit-up_limit>0)
					sum_k[k]=(dB_k_k_2-dB_k_k_1)/((low_limit-up_limit)*(Sample_time*Light_fiber_speed)/2);
				sGabor_Result->Line_k[i+1]=sGabor_Result->Line_k[i+1]+sum_k[k];
			}
			if(k!=5)
				sGabor_Result->Line_k[i+1]=(sGabor_Result->Line_k[i+1]/(k-5));
			else sGabor_Result->Line_k[i+1]=sGabor_Result->Line_k[i+1];
			//if(wavelength==1310)//1310
			//{
			//	if(sGabor_Result->Line_k[i+1]<0.28||sGabor_Result->Line_k[i+1]>0.42)
			//	{
			//		//sGabor_Result->Line_k[i+1]=0;//0;//0.326;
			//		damage_value=(sGabor_Result->Line_k[i+1]-Avg_loss_1310)/10;
			//		if(((low_limit-up_limit)*(Sample_time*Light_fiber_speed)/2)>400)
			//		{
			//			sGabor_Result->Line_k[i+1]=Avg_loss_1310+damage_value;
			//		}
			//		else sGabor_Result->Line_k[i+1]=sGabor_Result->Line_k[i+1];
			//	}

			//}
			//else if(wavelength==1550)//1550
			//{
			//	if(sGabor_Result->Line_k[i+1]<0.12||sGabor_Result->Line_k[i+1]>0.24)//sGabor_Result->Line_k[i+1]=0;//0;//0.184;
			//	{
			//		damage_value=(sGabor_Result->Line_k[i+1]-Avg_loss_1550)/10;
			//		if(((low_limit-up_limit)*(Sample_time*Light_fiber_speed)/2)>400)
			//		{
			//			sGabor_Result->Line_k[i+1]=Avg_loss_1550+damage_value;
			//		}
			//		else sGabor_Result->Line_k[i+1]=sGabor_Result->Line_k[i+1];
			//	}
			//}
			//else if(wavelength==1625)//1625
			//{
			//	if(sGabor_Result->Line_k[i+1]<0.12||sGabor_Result->Line_k[i+1]>0.26)//sGabor_Result->Line_k[i+1]=0;//0;//0.184;
			//	{
			//		damage_value=(sGabor_Result->Line_k[i+1]-Avg_loss_1625)/10;
			//		if(((low_limit-up_limit)*(Sample_time*Light_fiber_speed)/2)>400)
			//		{
			//			sGabor_Result->Line_k[i+1]=Avg_loss_1625+damage_value;
			//		}
			//		else sGabor_Result->Line_k[i+1]=sGabor_Result->Line_k[i+1];
			//	}
			//}

		}

	}
	delete[] sum_k;
	//return sGabor_Result;
}
void K_Line_limite(int wavelength,Gabor_Result* sGabor_Result)
{
	int i=0;
	for(i=0;i<sGabor_Result->Valid_Num;i++)
	{
		if(wavelength==1310)//1310
		{
			if(sGabor_Result->Line_k[i]<0.28||sGabor_Result->Line_k[i]>0.42)
			{
				//sGabor_Result->Line_k[i]=0;//0;//0.326;			
			}

		}
		else if(wavelength==1490)//1490
		{
			if(sGabor_Result->Line_k[i]<0.12||sGabor_Result->Line_k[i]>0.24)
			{
				//sGabor_Result->Line_k[i]=0;//0;//0.326;			
			}
		}
		else if(wavelength==1550)//1550
		{
			if(sGabor_Result->Line_k[i]<0.12||sGabor_Result->Line_k[i]>0.24)
			{
				//sGabor_Result->Line_k[i]=0;//0;//0.326;			
			}
		}
		else if(wavelength==1625)//1625
		{
			if(sGabor_Result->Line_k[i]<0.12||sGabor_Result->Line_k[i]>0.26)
			{
				//sGabor_Result->Line_k[i]=0;//0;//0.326;			
			}
		}
		else if(wavelength==1300)//1625
		{
			if(sGabor_Result->Line_k[i]<0.12||sGabor_Result->Line_k[i]>0.26)
			{
				//sGabor_Result->Line_k[i]=0;//0;//0.326;			
			}
		}
		else if(wavelength==850)//1625
		{
			if(sGabor_Result->Line_k[i]<0.12||sGabor_Result->Line_k[i]>0.26)
			{
				//sGabor_Result->Line_k[i]=0;//0;//0.326;			
			}
		}
		else if(wavelength==1650)//1625
		{
			if(sGabor_Result->Line_k[i]<0.12||sGabor_Result->Line_k[i]>0.26)
			{
				//sGabor_Result->Line_k[i]=0;//0;//0.326;			
			}
		}
		if(sGabor_Result->Line_k[i]<0.1||sGabor_Result->Line_k[i]>5)
		{
			sGabor_Result->Line_k[i]=0;//0;//0.326;			
		}
	}
	//return sGabor_Result;
}

int lEventGenerate(int pulseNum,int wavelength,float Sample_freaq)
{
	float kkk=0;
	int Freaq_num=0;
	Freaq_num=Sample_freaq/25;
	if(Freaq_num<=0)Freaq_num=1;
	int lEvent=200;
	//	Sample_freaq=25;
#if Hight_zone
		switch(pulseNum)
		{
		case 0://3ns
			//kkk=
			switch(Freaq_num)
			{
			case 1:lEvent=8;break;  //25M
			case 2:lEvent=10;break;  //50M
			case 4:lEvent=40;break;  //100M
			case 8:lEvent=45;break;  //200M
			case 16:lEvent=50;break;  //400M
			case 82:lEvent=50;break;
			default:lEvent=5;break;
			}
			//lEvent=1;
			break;
		case 1://5ns
			//lEvent=2;
			switch(Freaq_num)
			{
			case 1:lEvent=8;break;  //25M
			case 2:lEvent=10;break;  //50M
			case 4:lEvent=12;break;  //100M
			case 8:lEvent=16;break;  //200M
			case 16:lEvent=30;break;  //400M
			case 82:lEvent=100;break; //2G
			default:lEvent=10;break;
			}
			break;
		case 2://10ns
			//lEvent=4;
			switch(Freaq_num)
			{
			case 1:lEvent=10;break;  //25M
			case 2:lEvent=14;break;  //50M
			case 4:lEvent=20;break;  //100M
			case 8:lEvent=30;break;  //200M
			case 16:lEvent=100;break;  //400M
			case 82:lEvent=350;break; //2G
			default:lEvent=10;break;
			}
			break;
		case 3://20ns
			//lEvent=25;
			switch(Freaq_num)
			{
			case 1:lEvent=20;break;  //25M
			case 2:lEvent=16;break;  //50M
			case 4:lEvent=30;break;  //100M
			case 8:lEvent=60;break;  //200M
			case 16:lEvent=100;break;  //400M
			case 82:lEvent=800;break; //2G
			default:lEvent=15;break;
			}
			break;
		case 13://30ns
			//lEvent=25;
			switch(Freaq_num)
			{
			case 1:lEvent=16;break;  //25M
			case 2:lEvent=20;break;  //50M
			case 4:lEvent=30;break;  //100M
			case 8:lEvent=50;break;  //200M
			case 16:lEvent=90;break;  //400M
			case 82:lEvent=500;break; //2G
			default:lEvent=50;break;
			}
			break;
		case 4://50ns
			//lEvent=25;
			switch(Freaq_num)
			{
			case 1:lEvent=20;break;  //25M
			case 2:lEvent=20;break;  //50M
			case 4:lEvent=40;break;  //100M
			case 8:lEvent=90;break;  //200M
			case 16:lEvent=80;break;  //400M
			case 82:lEvent=700;break; //2G
			default:lEvent=100;break;
			}
			break;
		case 5://100ns
			//lEvent=35;
			switch(Freaq_num)
			{
			case 1:lEvent=40;break;  //25M
			case 2:lEvent=40;break;  //50M
			case 4:lEvent=50;break;  //100M
			case 8:lEvent=100;break;  //200M
			case 16:lEvent=200;break;  //400M
			case 82:lEvent=800;break; //2G
			default:lEvent=30;break;
			}
			break;
		case 6://200ns
			//lEvent=50;
			switch(Freaq_num)
			{
			case 1:lEvent=50;break;  //25M
			case 2:lEvent=60;break;  //50M
			case 4:lEvent=80;break;  //100M
			case 8:lEvent=220;break;  //200M
			case 16:lEvent=280;break;  //400M
			case 82:lEvent=1000;break; //2G
			default:lEvent=50;break;
			}
			break;
		case 14://300ns
			//lEvent=50;
			switch(Freaq_num)
			{
			case 1:lEvent=44;break;  //25M
			case 2:lEvent=80;break;  //50M
			case 4:lEvent=140;break;  //100M
			case 8:lEvent=170;break;  //200M
			case 16:lEvent=300;break;  //400M
			case 82:lEvent=1000;break; //2G
			default:lEvent=50;break;
			}
			break;
		case 15://400ns
			//lEvent=50;
			switch(Freaq_num)
			{
			case 1:lEvent=48;break;  //25M
			case 2:lEvent=90;break;  //50M
			case 4:lEvent=150;break;  //100M
			case 8:lEvent=180;break;  //200M
			case 16:lEvent=310;break;  //400M
			case 82:lEvent=1100;break; //2G
			default:lEvent=100;break;
			}
			break;
		case 7://500ns
			//lEvent=55;
			switch(Freaq_num)
			{
			case 1:lEvent=70;break;  //25M
			case 2:lEvent=120;break;  //50M
			case 4:lEvent=160;break;  //100M
			case 8:lEvent=180;break;  //200M
			case 16:lEvent=320;break;  //400M
			case 82:lEvent=1200;break; //2G
			default:lEvent=100;break;
			}
			break;
		case 8://1us
			//lEvent=60;
			switch(Freaq_num)
			{
			case 1:lEvent=104;break;  //25M
			case 2:lEvent=140;break;  //50M
			case 4:lEvent=200;break;  //100M
			case 8:lEvent=240;break;  //200M
			case 16:lEvent=380;break;  //400M
			case 82:lEvent=1400;break; //2G
			default:lEvent=120;break;
			}
			break;
		case 9://2us
			//lEvent=75;
			switch(Freaq_num)
			{
			case 1:lEvent=150;break;  //25M
			case 2:lEvent=200;break;  //50M
			case 4:lEvent=240;break;  //100M
			case 8:lEvent=280;break;  //200M
			case 16:lEvent=420;break;  //400M
			case 82:lEvent=1600;break; //2G
			default:lEvent=160;break;
			}
			break;
		case 10://5us
			//lEvent=100;
			switch(Freaq_num)
			{
			case 1:lEvent=220;break;  //25M
			case 2:lEvent=240;break;  //50M
			case 4:lEvent=280;break;  //100M
			case 8:lEvent=320;break;  //200M
			case 16:lEvent=500;break;  //400M
			case 82:lEvent=2000;break; //2G
			default:lEvent=120;break;
			}
			break;
		case 11://10us
			//lEvent=200;
			switch(Freaq_num)
			{
			case 1:lEvent=320;break;  //25M
			case 2:lEvent=350;break;  //50M
			case 4:lEvent=400;break;  //100M
			case 8:lEvent=500;break;  //200M
			case 16:lEvent=600;break;  //400M
			case 82:lEvent=3000;break; //2G
			default:lEvent=200;break;
			}
			break;
		case 12://20us
			switch(Freaq_num)
			{
			case 1:lEvent=300;break;  //25M
			case 2:lEvent=450;break;  //50M
			case 4:lEvent=500;break;  //100M
			case 8:lEvent=550;break;  //200M
			case 16:lEvent=700;break;  //400M
			case 82:lEvent=3500;break; //2G
			default:lEvent=200;break;
			}
			break;
		default:
			//lEvent=200;
			switch(Freaq_num)
			{
			case 1:lEvent=1;break;  //25M
			case 2:lEvent=1;break;  //50M
			case 4:lEvent=1;break;  //100M
			case 8:lEvent=2;break;  //200M
			case 16:lEvent=3;break;  //400M
			case 82:lEvent=15;break; //2G
			default:lEvent=3;break;
			}
			break;
		}
#else
	switch(pulseNum)
	{
	case 0://3ns
		//kkk=
		switch(Freaq_num)
		{
		case 1:lEvent=1;break;  //25M
		case 2:lEvent=2;break;  //50M
		case 4:lEvent=3;break;  //100M
		case 8:lEvent=5;break;  //200M
		case 16:lEvent=8;break;  //400M
		case 80:lEvent=50;break;
		default:lEvent=5;break;
		}
		//lEvent=1;
		break;
	case 1://5ns
		//lEvent=2;
		switch(Freaq_num)
		{
		case 1:lEvent=4;break;  //25M
		case 2:lEvent=6;break;  //50M
		case 4:lEvent=7;break;  //100M
		case 8:lEvent=8;break;  //200M
		case 16:lEvent=8;break;  //400M
		case 80:lEvent=50;break; //2G
		default:lEvent=10;break;
		}
		break;
	case 2://10ns
		//lEvent=4;
		switch(Freaq_num)
		{
		case 1:lEvent=5;break;  //25M
		case 2:lEvent=7;break;  //50M
		case 4:lEvent=8;break;  //100M
		case 8:lEvent=9;break;  //200M
		case 16:lEvent=15;break;  //400M
		case 80:lEvent=75;break; //2G
		default:lEvent=10;break;
		}
		break;
	case 3://20ns
		//lEvent=25;
		switch(Freaq_num)
		{
		case 1:lEvent=6;break;  //25M
		case 2:lEvent=7;break;  //50M
		case 4:lEvent=8;break;  //100M
		case 8:lEvent=15;break;  //200M
		case 16:lEvent=30;break;  //400M
		case 80:lEvent=150;break; //2G
		default:lEvent=15;break;
		}
		break;
	case 13://30ns
		//lEvent=25;
		switch(Freaq_num)
		{
		case 1:lEvent=8;break;  //25M
		case 2:lEvent=10;break;  //50M
		case 4:lEvent=20;break;  //100M
		case 8:lEvent=35;break;  //200M
		case 16:lEvent=50;break;  //400M
		case 80:lEvent=250;break; //2G
		default:lEvent=50;break;
		}
		break;
	case 4://50ns
		//lEvent=25;
		switch(Freaq_num)
		{
		case 1:lEvent=12;break;  //25M
		case 2:lEvent=18;break;  //50M
		case 4:lEvent=30;break;  //100M
		case 8:lEvent=40;break;  //200M
		case 16:lEvent=70;break;  //400M
		case 80:lEvent=350;break; //2G
		default:lEvent=100;break;
		}
		break;
	case 5://100ns
		//lEvent=35;
		switch(Freaq_num)
		{
		case 1:lEvent=36;break;  //25M
		case 2:lEvent=40;break;  //50M
		case 4:lEvent=70;break;  //100M
		case 8:lEvent=120;break;  //200M
		case 16:lEvent=240;break;  //400M
		case 80:lEvent=700;break; //2G
		default:lEvent=30;break;
		}
		break;
	case 6://200ns
		//lEvent=50;
		switch(Freaq_num)
		{
		case 1:lEvent=40;break;  //25M
		case 2:lEvent=60;break;  //50M
		case 4:lEvent=80;break;  //100M
		case 8:lEvent=140;break;  //200M
		case 16:lEvent=280;break;  //400M
		case 80:lEvent=1000;break; //2G
		default:lEvent=50;break;
		}
		break;
	case 14://300ns
		//lEvent=50;
		switch(Freaq_num)
		{
		case 1:lEvent=44;break;  //25M
		case 2:lEvent=80;break;  //50M
		case 4:lEvent=140;break;  //100M
		case 8:lEvent=170;break;  //200M
		case 16:lEvent=300;break;  //400M
		case 80:lEvent=1000;break; //2G
		default:lEvent=50;break;
		}
		break;
	case 15://400ns
		//lEvent=50;
		switch(Freaq_num)
		{
		case 1:lEvent=48;break;  //25M
		case 2:lEvent=90;break;  //50M
		case 4:lEvent=150;break;  //100M
		case 8:lEvent=180;break;  //200M
		case 16:lEvent=310;break;  //400M
		case 80:lEvent=1050;break; //2G
		default:lEvent=100;break;
		}
		break;
	case 7://500ns
		//lEvent=55;
		switch(Freaq_num)
		{
		case 1:lEvent=70;break;  //25M
		case 2:lEvent=100;break;  //50M
		case 4:lEvent=160;break;  //100M
		case 8:lEvent=180;break;  //200M
		case 16:lEvent=320;break;  //400M
		case 80:lEvent=1100;break; //2G
		default:lEvent=100;break;
		}
		break;
	case 8://1us
		//lEvent=60;
		switch(Freaq_num)
		{
		case 1:lEvent=104;break;  //25M
		case 2:lEvent=140;break;  //50M
		case 4:lEvent=200;break;  //100M
		case 8:lEvent=240;break;  //200M
		case 16:lEvent=380;break;  //400M
		case 80:lEvent=1400;break; //2G
		default:lEvent=120;break;
		}
		break;
	case 9://2us
		//lEvent=75;
		switch(Freaq_num)
		{
		case 1:lEvent=118;break;  //25M
		case 2:lEvent=200;break;  //50M
		case 4:lEvent=240;break;  //100M
		case 8:lEvent=280;break;  //200M
		case 16:lEvent=420;break;  //400M
		case 80:lEvent=1600;break; //2G
		default:lEvent=160;break;
		}
		break;
	case 10://5us
		//lEvent=100;
		switch(Freaq_num)
		{
		case 1:lEvent=200;break;  //25M
		case 2:lEvent=240;break;  //50M
		case 4:lEvent=280;break;  //100M
		case 8:lEvent=320;break;  //200M
		case 16:lEvent=500;break;  //400M
		case 80:lEvent=2000;break; //2G
		default:lEvent=120;break;
		}
		break;
	case 11://10us
		//lEvent=200;
		switch(Freaq_num)
		{
		case 1:lEvent=280;break;  //25M
		case 2:lEvent=350;break;  //50M
		case 4:lEvent=400;break;  //100M
		case 8:lEvent=500;break;  //200M
		case 16:lEvent=600;break;  //400M
		case 80:lEvent=3000;break; //2G
		default:lEvent=200;break;
		}
		break;
	case 12://20us
		switch(Freaq_num)
		{
		case 1:lEvent=440;break;  //25M
		case 2:lEvent=450;break;  //50M
		case 4:lEvent=500;break;  //100M
		case 8:lEvent=550;break;  //200M
		case 16:lEvent=700;break;  //400M
		case 80:lEvent=3500;break; //2G
		default:lEvent=200;break;
		}
		break;
	default:
		//lEvent=200;
		switch(Freaq_num)
		{
		case 1:lEvent=1;break;  //25M
		case 2:lEvent=1;break;  //50M
		case 4:lEvent=1;break;  //100M
		case 8:lEvent=2;break;  //200M
		case 16:lEvent=3;break;  //400M
		case 80:lEvent=15;break; //2G
		default:lEvent=3;break;
		}
		break;
	}
#endif
	return lEvent;
}



int Start_point_resarch(int pulsewidth,int wavelength,WORD *input_data,int paramLen,float Sample_freaq,float Index_N)
{
	int input_data_buff[128000];
	int input_length=paramLen;
	int step_point=0;
	int i=0;
	int fiber_end_radio=0; //光纤末端噪声水平
	int fiber_end_lever=0; //光纤末端水平高度 
	int First_Max_data=0,First_Max_mark=0;
	int Start_point_number=0;


	step_point=Step_point_count(pulsewidth,wavelength,Sample_freaq);
	
	for(i=0;i<paramLen;i++)
	{
		input_data_buff[i]=65535-input_data[i];
	}

	for(i=0;i<input_length;i++)
	{
		input_data_buff[i]=65535-input_data[i];
	}
	if(input_length>501)
	{
		for(i=input_length-1;i>input_length-501;i--)
		{
			fiber_end_lever=fiber_end_lever+input_data_buff[i];
			fiber_end_radio=fiber_end_radio+abs(input_data_buff[i]-input_data_buff[i-1]);
		}
		fiber_end_lever=fiber_end_lever/500;
		fiber_end_radio=fiber_end_radio/500;
	}
	//搜索出前40个数据的最大值和下标
	for(i=1;i<40;i++)
	{
		if(First_Max_data<=input_data_buff[i])
		{
			First_Max_data=input_data_buff[i];
			First_Max_mark=i;
		}
	}
	for(i=First_Max_mark;i<3*First_Max_mark;i++)//对于比较平滑的曲线的搜索
	{
		if(abs(input_data_buff[i]-input_data_buff[i+1])<50&&abs(input_data_buff[i+2]-input_data_buff[i+1])<50&&abs(input_data_buff[i+3]-input_data_buff[i+2])<50)
		{
			Start_point_number=i;
		}
	}
	return Start_point_number;

}
void Deadzoon_function(int wavelength,int pulsewidth,WORD input_data[],int paramLen,Gabor_Result& sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe);
//******************************************************************//
//     事件分析
//     L_event:分析事件步进，跟脉宽和采样分辨率有关系
//     wavelength:曲线波长
//     input_data[]：分析的原始数据
//     paramLen:原始数据长度
//     thresholdUpSet:短时傅里叶变化阈值上限
//     thresholdDownSet:短时傅里叶变化阈值下限
//     dB_Loss:衰减门限
//     dB_reflex:反射门限
//     dB_End:末端判断门限
//******************************************************************//
/***********************************************************************/
///pulseWidth：脉宽
///wavelength:波长值，0:1310,1:1550
///input_data[]:采样数据
///paramLen：采样数据长度
//double thresholdUpSet:傅里叶变化阈值上限。默认为2.08
//double thresholdDownSet傅里叶变化阈值下限.默认为2.08
///dB_Loss:衰减判断门限
///dB_reflex：反射判断门限
///dB_End：末端判断门限默认为3
///Return_loss_Tybe：典型散射系数
// Sample_freaq:采样频率
/**********************************************************************/
Gabor_Result gabor_generate(int pulsewidth,int wavelength,WORD *input_data,int paramLen,double thresholdUpSet,double thresholdDownSet,float dB_Loss,float dB_reflex,float dB_End,float Sample_freaq,float Index_N,int link_point_number)
{

	//距离计算公式：L=0.04*point/(sample_freaq/25);

	int input_length=paramLen-1;
	int Start_point=0;
	int length_real=0;//剔除最小值之后的真实长度
	int length_real_Zero=0;
	int length_real_gy=0;

	int fiber_end_radio=0; //光纤末端噪声水平
	int fiber_end_lever=0; //光纤末端水平高度 
    
	int Reflex_Hight_SET=500;
	switch(pulsewidth)
	{
	case 3:
		Reflex_Hight_SET=1000;
		break;
	case 5:
		Reflex_Hight_SET=800;
		break;
	case 10:
		Reflex_Hight_SET=700;
		break;
	case 20:
		Reflex_Hight_SET=600;
		break;
	case 50:
		Reflex_Hight_SET=400;
		break;
	case 100:
		Reflex_Hight_SET=300;
		break;
	case 200:
		Reflex_Hight_SET=300;
		break;
	case 500:
		Reflex_Hight_SET=200;
		break;
	case 1000:
		Reflex_Hight_SET=150;
		break;
	case 2000:
		Reflex_Hight_SET=100;
		break;
	case 5000:
		Reflex_Hight_SET=50;
		break;
	case 10000:
		Reflex_Hight_SET=50;
		break;
	case 20000:
		Reflex_Hight_SET=30;
		break;
	default:
		Reflex_Hight_SET=500;
		break;


	}
	


	//int Reflex_Event_start[100];
	//int Reflex_Event_end[100];    //事件结束位置
	//int Reflex_Max_mark[100];     //每个反射峰的最高点
	//int Loss_max_mark[100];  //每个衰减事件前的最高点
	//int Loss_Event_start[100];
	//int Loss_Event_end[100];
	//int Event_Hight[100];
	//float Event_Loss[100];
	//int Fiber_start_pulse_width=0;//起始峰宽度
	//int input_data_buff[128000];



	//int* input_data_buff=new int[input_length];//短时傅里叶变化结果Cn
	//memset(input_data_buff,0,input_length*sizeof(int));

	//float* sum_k=new float[2000];//短时傅里叶变化结果Cn
	//memset(sum_k,0,2000*sizeof(float));

#if DEBUG

	int Reflex_Event_start[100];
	int Reflex_Event_end[100];    //事件结束位置
	int Reflex_Max_mark[100];     //每个反射峰的最高点
	int Loss_max_mark[100];  //每个衰减事件前的最高点
	int Loss_Event_start[100];
	int Loss_Event_end[100];
	int Event_Hight[100];
	float Event_Loss[100];
	int Fiber_start_pulse_width=0;//起始峰宽度
	int input_data_buff[128000];

#else 
	int* Reflex_Event_start=new int[100];
	memset(Reflex_Event_start,0,100*sizeof(int));

	int* Reflex_Event_end=new int[100];
	memset(Reflex_Event_end,0,100*sizeof(int));

	int* Reflex_Max_mark=new int[100];
	memset(Reflex_Max_mark,0,100*sizeof(int));

	int* Loss_max_mark=new int[100];
	memset(Loss_max_mark,0,100*sizeof(int));

	int* Loss_Event_start=new int[100];
	memset(Loss_Event_start,0,100*sizeof(int));

	int* Loss_Event_end=new int[100];
	memset(Loss_Event_end,0,100*sizeof(int));

	int* Event_Hight=new int[100];
	memset(Event_Hight,0,100*sizeof(int));

	int* Event_Loss=new int[100];
	memset(Event_Loss,0,100*sizeof(int));

	int* input_data_buff=new int[input_length];
	memset(input_data_buff,0,input_length*sizeof(int));

#endif


	Gabor_Result sGabor_Result;//结构体存贮结果
	//memset(line_fit_factor,0,sizeof(line_fit_factor));
	
	int i=0,j=0,n=0,m=0;
	int Reflex_event_count=0;
	int Loss_event_count=0;
	int flag=0,flag2=0;
	int max_data=0;
	int max_data_mark=0;
	int down_start_mark=0;
	int deta_point_to_point=0;
	int First_Max_data=0,First_Max_mark=0;
	int min_data=0,min_data_mark=0;
	int Reflex_Event_start_noise=0;
	int step_point=0;
	float Distance_point_to_point;
	float Avg_loss_wave_lenght=0;
	int event_noise=0;
	int event_avg_lever=0;
	int up_count=0;
	int down_count=0;
	int Reflex_Hight=1000;
	float Natural_loss=0;
	float Point_to_point_loss=0;
	int Double_lenght_erro_point=4;

	Distance_point_to_point=4/(Sample_freaq/25);

	Avg_loss_wave_lenght=Avg_loss_wave_lenght_count(wavelength);
	step_point=Step_point_count(pulsewidth,wavelength,Sample_freaq);
	Reflex_Hight=Reflex_Hight_count(pulsewidth,wavelength,Sample_freaq);

	//TRACE(_T("%d %.2f %s"),a,b,c);

	Point_to_point_loss=Avg_loss_wave_lenght*1000/250/(Sample_freaq/25);
	//求出末端水平高度和末端噪声水平
/*
	for(i=1000;i<input_length;i++)
	{

		input_data[i]=input_data[i]-1000;
	}*/
	for(i=0;i<input_length;i++)
	{
		input_data_buff[i]=65535-input_data[i];
	}
	if(input_length>501)
	{
		for(i=input_length-1;i>input_length-501;i--)
		{
			fiber_end_lever=fiber_end_lever+input_data_buff[i];
			fiber_end_radio=fiber_end_radio+abs(input_data_buff[i]-input_data_buff[i-1]);
		}
		fiber_end_lever=fiber_end_lever/500;
		fiber_end_radio=fiber_end_radio/500;
	}
	if(fiber_end_lever<300)fiber_end_lever=300;
	else if(fiber_end_lever>4000)fiber_end_lever=4000;
	if(fiber_end_radio<200)fiber_end_radio=200;
	//搜索出前40个数据的最大值和下标
	m=3*step_point;
	if(m<50)m=50;
	for(i=1;i<m;i++)
	{
		if(First_Max_data<=input_data_buff[i])
		{
			First_Max_data=input_data_buff[i];
			First_Max_mark=i;
		}
		if(First_Max_mark>step_point/3&&First_Max_mark>3)
		{
			if(input_data_buff[i+1]<input_data_buff[i])
			{
				if(input_data_buff[i+2]<input_data_buff[i+1])
				{
					if(input_data_buff[i+3]<input_data_buff[i+2])
						break;
				}
			}
		}
		if(i>First_Max_mark+3)
		{
			if(First_Max_data>input_data_buff[i]+2000)
				break;
		}
		
	}

	for(i=First_Max_mark;i<First_Max_mark+3*step_point;i++)
	{
		if(First_Max_data-input_data_buff[i]>=200&&First_Max_data-input_data_buff[i+1]>200)
		{
			down_start_mark=i;
			break;
		}
	}
	if(down_start_mark==0)down_start_mark=i;

	
	//找出曲线的起始点
	//Start_point=Start_point_resarch(pulsewidth,wavelength,input_data,paramLen,Sample_freaq,Index_N);

    flag=0;
	int data_sum=0;
	j=0;
	m=10*First_Max_mark;
	if(m<step_point)m=step_point;
	if(m<50)m=50;
	for(i=down_start_mark;i<m;i++)//对于比较平滑的曲线的搜索
	{
		if(i>=input_length)break;
		if((input_data_buff[i+1]-input_data_buff[i]>0)&&(input_data_buff[i+2]-input_data_buff[i+1]>0))
		{
			if((input_data_buff[i+1]-input_data_buff[i]>200&&(input_data_buff[i+2]-input_data_buff[i+1]>100)))//离接头比较近的地方有连接头反射峰
			{
				Start_point=i-1;
				break;
			}
		}
		if(abs(input_data_buff[i]-input_data_buff[i+1])<50&&abs(input_data_buff[i+2]-input_data_buff[i+1])<50&&abs(input_data_buff[i+3]-input_data_buff[i+2])<50)
		{
			if(First_Max_data-input_data_buff[i]>300&&First_Max_data-input_data_buff[i+1]>300)
			{
				if(i<4*step_point)
				{
					down_count=0;
					for(j=i;j<i+3*step_point;j++)
					{
						if(j>input_length-10)break;
						if((input_data_buff[j]-input_data_buff[j+1]>10))
						{
							down_count=0;
							continue;
						}
						else
						{
							down_count++;
						}
						if(down_count>=3)
						{
							Start_point=j;
							flag=1;
							break;
						}

					}
					if(flag)break;
				}
				//if(input_data_buff[i+4]<=input_data_buff[i+3]-5)continue;
				
			  //  flag=1;
			 //   break;

			}
			
		}
	}
	m=0;
	if(flag==0)
	{
		/*data_sum=0;
		for(i=First_Max_mark;i<10*First_Max_mark;i++)
		{
			data_sum=data_sum+input_data_buff[i];
		}
		if((i-First_Max_mark)!=0)
		{

			data_sum=data_sum/(i-First_Max_mark);
		}
		for(i=First_Max_mark;i<10*First_Max_mark;i++)
		{
			if(input_data_buff[i]<=data_sum&&input_data_buff[i+1]<=data_sum)
			{
				Start_point=i;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			Start_point=2*First_Max_mark;
			flag=1;
		}*/
		n=10*First_Max_mark;
		//if(n>4*step_point)n=4*step_point;
		for(i=down_start_mark;i<down_start_mark+step_point;i++)
		{
			if(i>=input_length-12)break;
			if(input_data_buff[i]-input_data_buff[i+10]<100)
			{
				if(input_data_buff[i+1]-input_data_buff[i+11]<100)
				{
					if(input_data_buff[i+2]-input_data_buff[i+12]<100)
					{
						Start_point=i;
						flag=1;
						break;
					}
				}
			}
		}
		if(flag==0)
		{
			data_sum=0;
			for(i=First_Max_mark;i<n;i++)
			{
				data_sum=data_sum+input_data_buff[i];
			}
			if((i-First_Max_mark)!=0)
			{

				data_sum=data_sum/(i-First_Max_mark);
			}
			for(i=First_Max_mark;i<n;i++)
			{
				if(input_data_buff[i]<=data_sum&&input_data_buff[i+1]<=data_sum)
				{
					Start_point=i;
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				Start_point=2*First_Max_mark;
				flag=1;
			}
		}
		
	}
	if(Start_point<j)
	{
		Start_point=j;
	}

    n=0;
	flag=0;
	if(pulsewidth>=1000)
	{
		if(Start_point<=step_point*3/4)Start_point=11*step_point/10;
	}
//	Start_point=step_point;
    //光纤长度查找,从前往后搜索
	length_real=input_length;
	//if(Start_point<step_point/2)Start_point=6*step_point/5;
	for(i=Start_point;i<input_length;i++)
	{
		if(input_data_buff[i]<fiber_end_lever+2*fiber_end_radio)
		{
			down_count++;
		}
		else down_count=0;
		if(down_count>=step_point)
		{
			length_real=i;
			break;
		}
		

	}
//搜索光纤长度，从后往前搜索
	up_count=0;
	for(i=input_length-10;i>Start_point;i--)
	{
		if(i<=0)break;
		if(input_data_buff[i]>2*fiber_end_lever+2*fiber_end_radio)
		{
			up_count++;
		}
		else up_count=0;
		if(up_count>=2*step_point/3)
		{
			length_real=i+step_point;
			break;
			/*if(i>length_real+4*step_point)
			{
				length_real=i;
				break;
			}
			else if(i<length_real)
			{
				if(up_count>2*step_point)
				{
					length_real=i+step_point;
					break;
				}
				
			}*/
			
		}
	}
	up_count=0;
	int noise_start_i=0;

	if(step_point<=8)//低采样率情况下的小脉宽的反射峰分析
	{
		

		for(i=Start_point;i<input_length-10;i++)
		{
			if(input_data_buff[i]<fiber_end_lever+2*fiber_end_radio)
			{
				down_count++;
			}
			else down_count=0;
			if(down_count>=3*step_point)
			{
				length_real=i-down_count;
				break;
			}


		}
		for(i=Start_point;i<input_length-10;i++)
		{
			if(i>=length_real)break;
			event_noise=0;
			event_avg_lever=0;
			flag=0;

			event_noise=0;
			event_avg_lever=0;
            if(Reflex_event_count)
			{
				if(i-Reflex_Event_start[Reflex_event_count-1]>2*step_point)noise_start_i=i;
				else 
				{
					if(Reflex_event_count>=2)
					{
					   if(Reflex_Event_start[Reflex_event_count-1]-Reflex_Event_start[Reflex_event_count-2]>2*step_point)noise_start_i=Reflex_Event_start[Reflex_event_count-1];
					   else noise_start_i=Reflex_Event_start[Reflex_event_count-2];
					}
				}
			}
			for(m=noise_start_i;m>noise_start_i-2*step_point;m--)
			{
				if(m<=0)break;
				event_noise=event_noise+abs(input_data_buff[m]-input_data_buff[m+1]);
				event_avg_lever=event_avg_lever+input_data_buff[m];
			}
			//if(m!=i)
			{
				event_noise=event_noise/(2*step_point);
				event_avg_lever=event_avg_lever/(2*step_point);
			}
			if((input_data_buff[i]<input_data_buff[i+1]))//连续三个点高于某个点，并且高度大于3dB
			{
				max_data=input_data_buff[i+1]-input_data_buff[i];
				max_data_mark=i+1;
				/*if(i==6140)
					max_data_mark=i+1;*/
				if((input_data_buff[i+1]-input_data_buff[i])>event_noise/2)
				{
					if((input_data_buff[i+2]-input_data_buff[i])>event_noise/2)
					{
						if(max_data<(input_data_buff[i+2]-input_data_buff[i]))
						{
							max_data=input_data_buff[i+2]-input_data_buff[i];
							max_data_mark=i+2;
						}
						if((input_data_buff[i+3]-input_data_buff[i])>event_noise/2)
						{
							if(max_data<(input_data_buff[i+3]-input_data_buff[i]))
							{
								max_data=input_data_buff[i+3]-input_data_buff[i];
								max_data_mark=i+3;
							}
							
							if(max_data>=500&&(input_data_buff[max_data_mark]>event_avg_lever+2*event_noise+400)&&max_data>3*event_noise/2)
							{
								if(Reflex_event_count<98)
								{
									
									if(input_data_buff[i]>500&&input_data_buff[max_data_mark]>3000)
									{
										Reflex_Event_start[Reflex_event_count++]=i;
									    Reflex_Max_mark[Reflex_event_count-1]=max_data_mark;

										if(abs(input_data_buff[Reflex_Event_start[Reflex_event_count-1]]-input_data_buff[max_data_mark])<=Reflex_Hight_SET)
										{
											Reflex_Event_start[Reflex_event_count-1]=0;
											Reflex_Max_mark[Reflex_event_count-1]=0;
											Reflex_event_count--;
										}

									}
								}
								i=i+step_point/2;
							}
						}
					}

				}
			}
		}
	}
	else//
	{
		for(i=Start_point;i<input_length-10;i++)
		{
			if(i>=length_real)break;
			if(i<3)continue;
			event_noise=0;
			event_avg_lever=0;
			flag=0;

			event_noise=0;
			event_avg_lever=0;
			if(Reflex_event_count)
			{
				if(i-Reflex_Event_start[Reflex_event_count-1]>2*step_point)noise_start_i=i;
				else 
				{
					if(Reflex_event_count>=2)
					{
						if(Reflex_Event_start[Reflex_event_count-1]-Reflex_Event_start[Reflex_event_count-2]>2*step_point)noise_start_i=Reflex_Event_start[Reflex_event_count-1];
						else noise_start_i=Reflex_Event_start[Reflex_event_count-2];
					}
				}
			}
			for(m=noise_start_i;m>noise_start_i-step_point;m--)
			{
				if(m<=0)break;
				event_noise=event_noise+abs(input_data_buff[m]-input_data_buff[m+1]);
				event_avg_lever=event_avg_lever+input_data_buff[m];
			}
			//if(m!=i)
			{
				event_noise=event_noise/(step_point);
				event_avg_lever=event_avg_lever/(step_point);
				if(event_noise<=0)event_noise=(abs(input_data_buff[i]-input_data_buff[i-1])+abs(input_data_buff[i-1]-input_data_buff[i-2])+abs(input_data_buff[i-2]-input_data_buff[i-3]))/3;
				if(event_avg_lever<=0)event_avg_lever=(input_data_buff[i]+input_data_buff[i-1]+input_data_buff[i-2])/3;
				//if(fiber_end_lever>=2500)fiber_end_lever=2000;
			}
			//else break;
			
			//判断上升沿
			if(i==2689)
				max_data=0;
			if((input_data_buff[i]<input_data_buff[i+1])&&((input_data_buff[i+1]<=input_data_buff[i+2]+50)&&(input_data_buff[i+2]>input_data_buff[i])))//&&(input_data_buff[i+2]<input_data_buff[i+3]))
			{
				max_data=0;
				min_data=65535;
				up_count=0;
				if((i+step_point)>input_length)break;
				for(j=i;j<i+step_point;j++)
				{
					if(j>=input_length-10)break;
					if(max_data<=input_data_buff[j])
					{
						max_data=input_data_buff[j];
						max_data_mark=j;
					}
					if(min_data>input_data_buff[j])
					{
						min_data=input_data_buff[j];
						min_data_mark=j;
					}
				}
				for(j=i;j<i+step_point;j++)
				{
					if(j>input_length-10)break;
					if(input_data_buff[j]>=input_data_buff[i]&&input_data_buff[j]>fiber_end_lever+fiber_end_radio)
					{
						up_count++;
						
						if(up_count>=step_point/4)
						{
							if((max_data-(input_data_buff[min_data_mark]+input_data_buff[min_data_mark+1]+input_data_buff[min_data_mark-1])/3)>=2*event_noise+Reflex_Hight)
							{
								if(max_data>=2*fiber_end_lever+2*fiber_end_radio)//event_noise
								{
									if(Reflex_event_count<98)
									{
										
										if(max_data>=5000+fiber_end_lever+fiber_end_radio)//&&max_data_mark<(j-up_count+step_point/2))
										{
											
											if(input_data_buff[max_data_mark]-input_data_buff[j-up_count]>2*event_noise)
											{
												Reflex_Event_start[Reflex_event_count++]=j-up_count;
												Reflex_Max_mark[Reflex_event_count-1]=max_data_mark;
												if(max_data<event_avg_lever+2*event_noise+Reflex_Hight_SET)
												{
													Reflex_Event_start[Reflex_event_count-1]=0;
													Reflex_Max_mark[Reflex_event_count-1]=0;
													Reflex_event_count--;
												}
												else
												{

													for(n=i;n<max_data_mark+3;n++)
													{
														if(n>=input_length-10)break;
														if(input_data_buff[n]-event_avg_lever>(max_data-event_avg_lever)/8)
															if(input_data_buff[n+1]-event_avg_lever>(max_data-event_avg_lever)/8)
																if(input_data_buff[n+2]-event_avg_lever>(max_data-event_avg_lever)/8)
																{
																	Reflex_Event_start[Reflex_event_count-1]=n-3;
																	if(n>13)
																	{
																		min_data=65535;
																		min_data_mark=n-13;
																		for(m=n-13;m<n-3;m++)
																		{
																			if(m>=input_length-10)break;
																			if(min_data>=(input_data_buff[m]-(max_data-event_avg_lever)/8))//-event_noise/3
																			{
																				if(m<0)break;
																				min_data=input_data_buff[m];
																				min_data_mark=m;
																			}

																		}
																		Reflex_Event_start[Reflex_event_count-1]=j-up_count;//min_data_mark+3;//max_data_mark;//
																		Reflex_Max_mark[Reflex_event_count-1]=max_data_mark;
																		if(abs((input_data_buff[min_data_mark+1]+input_data_buff[min_data_mark]+input_data_buff[min_data_mark-1])/3-input_data_buff[max_data_mark])<=Reflex_Hight_SET)
																		{
																			Reflex_Event_start[Reflex_event_count-1]=0;
																			Reflex_Max_mark[Reflex_event_count-1]=0;
																			Reflex_event_count--;
																		}
																		else 
																			i=max_data_mark+step_point/2;
																		break;
																	}
																}
													}
												
												}
											}
											
										}
										
									}
									//i=i+step_point;
									if(i>=input_length-10)break;
									break;
								}
								
								if(i>=input_length-10)break;
								break;
							}
							else 
							{
								if(up_count>=step_point-1)
								{
									i=j;
									break;
								}
								continue;
							}
							
						}
					}
					else
					{
						up_count=0;
						break;
					}
				}


			}
				

		}
	}
	//对反射事件进行微调整
	if(Reflex_event_count)
	{
		for(i=0;i<Reflex_event_count;i++)
		{
			if(Reflex_Event_start[i]>3)
			{
				for(j=Reflex_Event_start[i];j>Reflex_Event_start[i]-3;j--)
				{
					if(input_data_buff[Reflex_Event_start[i]]>input_data_buff[j-1]+100)
					{
						Reflex_Event_start[i]=j-1;
					}
				}
			}
			
		}
	}
	//对反射事件进行微调整
	if(Reflex_event_count)
	{
		int NN=0,MM=0;
		if(Sample_freaq<=200)
		{
			NN=3;
			MM=4;
		}
		else if(Sample_freaq<=400)
		{
			NN=4;
			MM=5;
		}
		else 
		{
			NN=10;
			MM=8;
		}
		for(i=0;i<Reflex_event_count;i++)
		{
			for(j=Reflex_Event_start[i];j<Reflex_Event_start[i]+2*step_point;j++)
			{
				if(j>=Reflex_Max_mark[i])break;
				if(input_data_buff[j+1]-input_data_buff[j]>0)
				{
					if(input_data_buff[j+2]-input_data_buff[j-1]>0)
					{
						if(input_data_buff[j+NN]-input_data_buff[j]>(input_data_buff[Reflex_Max_mark[i]]-input_data_buff[Reflex_Event_start[i]])/MM)
						{
							Reflex_Event_start[i]=j;
							break;
						}
					}
				}
			}

		}
	}

////////////////短光纤事件分析///////////////////////
#if 1



#endif



////////////////////////////////////////////////////
#if 1
	//对反射事件做鬼影判断
	length_real_Zero=0;
	length_real_gy=0;
	//K_Line_count(2*step_point,wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
	if(Reflex_event_count>=2)
	{
		int ss_start_mark=0;
		int ss_head_mark=0;
		int ss_end_mark=0;
		int STOP_POINT=0;
		float Nuatrue_loss=0;
		
		Double_lenght_erro_point=Double_lenght_erro_function(pulsewidth,wavelength,Sample_freaq);
		//求出每个反射峰的宽度
		for(i=0;i<Reflex_event_count;i++)
		{
			ss_start_mark=Reflex_Max_mark[i];
			ss_head_mark=Reflex_Event_start[i];
			ss_end_mark=ss_start_mark;
			Reflex_Event_end[i]=Reflex_Event_start[i];
			for(j=ss_start_mark;j<input_length-step_point-10;j++)
			{
				//if(j>=input_length-step_point-10)break;
				if(ss_end_mark>=input_length-10)break;
				if((i+1)>=Reflex_event_count)STOP_POINT=input_length-step_point-10;
				else STOP_POINT=Reflex_Event_start[i+1];
				if(ss_end_mark>=STOP_POINT)
				{
					//末端指标已经超过了下一个反射事件的起始峰，就结束
					Reflex_Event_end[i]=ss_end_mark;
					break;

				}
				else
				{
					if(input_data_buff[ss_end_mark]<=input_data_buff[ss_head_mark])
					{
						//找到了小于起始峰的点，结束
						Reflex_Event_end[i]=ss_end_mark;
						break;
					}
					ss_end_mark++;

				}
			}
		}
		for(i=1;i<Reflex_event_count;i++)
		{
			for(j=0;j<i;j++)
			{
				if(Reflex_Event_start[i]>Reflex_Event_start[j])
				{
					Nuatrue_loss=299.782458/Index_N/Sample_freaq/2*(Reflex_Event_start[i]-Reflex_Event_start[j])*Avg_loss_wave_lenght;
					if(Reflex_Event_start[i]<2*Reflex_Event_start[j])
					{
						if((2*Reflex_Event_start[j]-Reflex_Event_start[i])<=4)
						{
							if(Reflex_Event_start[j]<5)break;
							
							if((input_data_buff[Reflex_Event_start[j]-3]+input_data_buff[Reflex_Event_start[j]-5]+input_data_buff[Reflex_Event_start[j]-4])/3-(input_data_buff[Reflex_Event_start[i]-3]+input_data_buff[Reflex_Event_start[i]-4]+input_data_buff[Reflex_Event_start[i]-5])/3>=Nuatrue_loss+3000)
							{

								
								if(i==Reflex_event_count-1)
								{
									length_real_Zero=Reflex_Event_start[j];
									length_real_gy=Reflex_Event_start[i];
									Reflex_event_count=j+1;
								}
								Reflex_Event_start[i]=0;
								Reflex_Event_end[i]=0;;//清楚鬼影
								break;
							}
						}
						else if((2*Reflex_Event_start[j]-Reflex_Event_start[i])<=Double_lenght_erro_point)
						{
							if(input_data_buff[Reflex_Event_start[i]]<2*(fiber_end_lever+fiber_end_radio))
							{
								if(Reflex_Event_start[j]<5)break;
								if((input_data_buff[Reflex_Event_start[j]-3]+input_data_buff[Reflex_Event_start[j]-5]+input_data_buff[Reflex_Event_start[j]-4])/3-(input_data_buff[Reflex_Event_start[i]-3]+input_data_buff[Reflex_Event_start[i]-4]+input_data_buff[Reflex_Event_start[i]-5])/3>=Nuatrue_loss+3000)
								{
									
									if(i==Reflex_event_count-1)
									{
										length_real_Zero=Reflex_Event_start[j];
										length_real_gy=Reflex_Event_start[i];
										Reflex_event_count=j+1;
									}
									Reflex_Event_start[i]=0;
									Reflex_Event_end[i]=0;;//清楚鬼影
									break;
								}
							}
						}
						else if((2*Reflex_Event_start[j]-Reflex_Event_start[i])<=step_point)
						{

							if(2*Reflex_Max_mark[j]-Reflex_Max_mark[i]<=2*Reflex_Event_start[j]-Reflex_Event_start[i])
							{
								if(Reflex_Event_start[j]<5)break;
								if((input_data_buff[Reflex_Event_start[j]-3]+input_data_buff[Reflex_Event_start[j]-5]+input_data_buff[Reflex_Event_start[j]-4])/3-(input_data_buff[Reflex_Event_start[i]-3]+input_data_buff[Reflex_Event_start[i]-4]+input_data_buff[Reflex_Event_start[i]-5])/3>=Nuatrue_loss+3000)
								{
									
									if(i==Reflex_event_count-1)
									{
										length_real_Zero=Reflex_Event_start[j];
										length_real_gy=Reflex_Event_start[i];
										Reflex_event_count=j+1;
									}
									Reflex_Event_start[i]=0;
									Reflex_Event_end[i]=0;;//清楚鬼影
									break;
								}
							}
						}
					}
					else
					{
						if(Reflex_Event_start[i]-2*Reflex_Event_start[j]<Double_lenght_erro_point)
						{
							if(Reflex_Event_start[j]<5)break;
							if((input_data_buff[Reflex_Event_start[j]-3]+input_data_buff[Reflex_Event_start[j]-5]+input_data_buff[Reflex_Event_start[j]-4])/3-(input_data_buff[Reflex_Event_start[i]-3]+input_data_buff[Reflex_Event_start[i]-4]+input_data_buff[Reflex_Event_start[i]-5])/3>=Nuatrue_loss+3000)
							{
								
								if(i==Reflex_event_count-1)
								{
									length_real_Zero=Reflex_Event_start[j];
									length_real_gy=Reflex_Event_start[i];
									Reflex_event_count=j+1;
								}
								Reflex_Event_start[i]=0;
								Reflex_Event_end[i]=0;;//清楚鬼影
								break;
							}
							else
							{
								if(Reflex_Event_end[i]-Reflex_Event_start[i]>0)
								{
									if(Reflex_Event_end[j]-Reflex_Event_start[j]>0)
									{
										if(Reflex_Event_end[i]-Reflex_Event_start[i]<(Reflex_Event_end[j]-Reflex_Event_start[j])/2)//反射峰宽度小于前端1/2距离的一个反射峰宽度的1/2
										{
											
											if(i==Reflex_event_count-1)
											{
												length_real_Zero=Reflex_Event_start[j];
												length_real_gy=Reflex_Event_start[i];
												Reflex_event_count=j+1;
											}
											Reflex_Event_start[i]=0;
											Reflex_Event_end[i];//清楚鬼影
											break;
										}
									}
								}
							}
						}
						else if(Reflex_Event_start[i]-2*Reflex_Event_start[j]<3*Double_lenght_erro_point)
						{
                            if(input_data_buff[Reflex_Event_start[j]]-input_data_buff[Reflex_Event_start[i]]>=Nuatrue_loss+3000)
							{
								if(Reflex_Event_start[j]<3)break;
								if((input_data_buff[Reflex_Event_start[i]-1]+input_data_buff[Reflex_Event_start[i]-2]+input_data_buff[Reflex_Event_start[i]-3])/3<2*(fiber_end_lever+fiber_end_radio))
								{
									if(i==Reflex_event_count-1)
									{
										length_real_Zero=Reflex_Event_start[j];
										length_real_gy=Reflex_Event_start[i];
										Reflex_event_count=j+1;
									}
									Reflex_Event_start[i]=0;
									Reflex_Event_end[i];//清楚鬼影
									break;
								}
							}
						}
					}
				}
			}
		}


	}
#endif
#if 1
	/******************************************************************************************/
	//针对反射峰找反射峰的结束点
	//
	float kkk=0;
	for(i=0;i<Reflex_event_count;i++)
	{


		flag=0;
		event_noise=0;
		for(j=Reflex_Event_start[i]-1;j>Reflex_Event_start[i]-11;j--)
		{
			if(j<=0)break;
			event_noise=event_noise+abs(input_data_buff[j]-input_data_buff[j-1]);
		}
		event_noise=event_noise/10;
		if(event_noise<=5)event_noise=5;
		for(j=Reflex_Max_mark[i];j<Reflex_Max_mark[i]+4*step_point;j++)
		{
			if(j>=input_length-10)break;
			if(j>Reflex_Max_mark[i]&&Reflex_Max_mark[i]>0)
			{
			   kkk=kkk+(input_data_buff[Reflex_Max_mark[i]]-input_data_buff[j])/(j-Reflex_Max_mark[i]);
			}

			if(i<Reflex_event_count-1)
			{
				if(j>=Reflex_Event_start[i+1])
				{
					Reflex_Event_end[i]=j-2;
					flag=1;
					break;
				}
				else
				{
					if(input_data_buff[Reflex_Max_mark[i]]-input_data_buff[j]>200)
					{
						if(input_data_buff[Reflex_Max_mark[i]]-input_data_buff[j+1]>200)
						{
							if((input_data_buff[j+1]>=input_data_buff[j]+event_noise)&&(input_data_buff[j+2]>=input_data_buff[j+1]+event_noise)&&(input_data_buff[j+3]>=input_data_buff[j+2]+event_noise))
							{

								Reflex_Event_end[i]=j;
								flag=1;
								break;
							}
							else
							{
								if(abs(input_data_buff[j+1]-input_data_buff[j])<event_noise&&abs(input_data_buff[j+2]-input_data_buff[j+1])<event_noise&&abs(input_data_buff[j+3]-input_data_buff[j+2])<event_noise&&abs(input_data_buff[j+4]-input_data_buff[j+3])<event_noise)
								{
									if(input_data_buff[j]<input_data_buff[Reflex_Event_start[i]]-20)
									{
										Reflex_Event_end[i]=j+2;
										flag=1;
										break;
									}

								}
							}
						}
					}
				}
			}//最后一个反射事件的末端查找
		}
		if(flag==0)//按常理没找到末端
		{
			if(j>Reflex_Max_mark[i])
			{
				kkk=kkk/(j-Reflex_Max_mark[i]);
				for(m=Reflex_Max_mark[i]+4*step_point;m>Reflex_Max_mark[i]+step_point;m--)
				{
					if(m<=0)break;

					if(m>Reflex_Max_mark[i])
					{
						if((input_data_buff[Reflex_Max_mark[i]]-input_data_buff[m])/(m-Reflex_Max_mark[i])>kkk)
						{
							if((input_data_buff[Reflex_Max_mark[i]]-input_data_buff[m+1])/(m+1-Reflex_Max_mark[i])>kkk)
								if((input_data_buff[Reflex_Max_mark[i]]-input_data_buff[m+2])/(m+2-Reflex_Max_mark[i])>kkk)

								{
									if(input_data_buff[j]<=input_data_buff[Reflex_Event_start[i]])
									{
										Reflex_Event_end[i]=m+2;
										flag=1;
										break;
									}
									
								}
						}
					}

				}
			}

		}
		if(flag==0)
		{
			for(m=Reflex_Max_mark[i];m<Reflex_Max_mark[i]+10*step_point;m++)
			{
				if(i>=Reflex_event_count-1)break;
				if(m>=input_length-10)break;
				if(i<Reflex_event_count-1)
				{
					if(m>=Reflex_Event_start[i+1])
					{
						Reflex_Event_end[i]=m-2;
						flag=1;
						break;
					}
					else
					{
						if(input_data_buff[m]<input_data_buff[Reflex_Event_start[i]])
						{
							if(abs(input_data_buff[m+1]-input_data_buff[m])<20&&abs(input_data_buff[m+2]-input_data_buff[m+1])<20)
							{
								Reflex_Event_end[i]=m+2;
								flag=1;
								break;
							}
						}
					}
				}
				else
				{
					if(input_data_buff[m]<input_data_buff[Reflex_Event_start[i]]&&input_data_buff[m+1]<input_data_buff[Reflex_Event_start[i]])
					{
						Reflex_Event_end[i]=m+2;
						flag=1;
						break;
					}
				}
			}

		}
		if(flag==0)
		{
			Reflex_Event_end[i]=Reflex_Event_start[i]+6*step_point;
			flag=1;
			//break;
		}
		if(step_point>=20)
		{
			if(input_data_buff[Reflex_Max_mark[i]]-input_data_buff[Reflex_Event_start[i]]<5*event_noise)
			{
				if(input_data_buff[Reflex_Max_mark[i]+1]-input_data_buff[Reflex_Event_start[i]+1]<2*event_noise)
				{
					if(i==Reflex_event_count-1)
					{
						//length_real_Zero=Reflex_Event_start[i];
						//length_real_gy=Reflex_Event_start[i];
					}
					Reflex_Event_start[i]=0;
					Reflex_Event_end[i]=0;

				}
				else
				{
					if((Reflex_Event_end[i]-Reflex_Event_start[i])<step_point/2)
					{
						if(i==Reflex_event_count-1)
						{
							//length_real_Zero=Reflex_Event_start[i];
							//length_real_gy=Reflex_Event_start[i];
						}
						Reflex_Event_start[i]=0;
						Reflex_Event_end[i]=0;
					}
				}
			}
		}
	}
#endif
j=0;
for(i=0;i<Reflex_event_count;i++)
{
	if(Reflex_Event_start[i]>0)
	{
		Reflex_Event_start[j]=Reflex_Event_start[i];
		Reflex_Event_end[j]=Reflex_Event_end[i];
		Reflex_Max_mark[j++]=Reflex_Max_mark[i];
	}
	else continue;
}
Reflex_event_count=j;
#if 1

		//*****************************利用反射峰宽度做第二次鬼影判断********************************、
	if(Reflex_event_count>=2)
	{
		
		Double_lenght_erro_point=Double_lenght_erro_function(pulsewidth,wavelength,Sample_freaq);
		if(Sample_freaq==400)Double_lenght_erro_point=20;
		else if(Sample_freaq==200)Double_lenght_erro_point=10;
		else if(Sample_freaq==2050)Double_lenght_erro_point=40;
		if(Double_lenght_erro_point<=5)Double_lenght_erro_point=5;
		for(i=0;i<Reflex_event_count;i++)
		{
			for(j=i+1;j<Reflex_event_count;j++)
			{
				if(Reflex_Event_start[j]>2*Reflex_Event_start[i])
				{
					if(Reflex_Event_start[j]<=2*Reflex_Event_start[i]+Double_lenght_erro_point)
					{
						if(input_data_buff[Reflex_Event_start[i]]>input_data_buff[Reflex_Event_start[j]]+input_data_buff[Reflex_Event_start[j]]/3)
						{
							if(Reflex_Event_end[i]-Reflex_Event_start[i]>=2*(Reflex_Event_end[j]-Reflex_Event_start[j]))
							{
								if(i==Reflex_event_count-1)
								{
									length_real_Zero=Reflex_Event_start[j];
									length_real_gy=Reflex_Event_start[i];
								}
								Reflex_Event_start[j]=0;
								Reflex_Event_end[j]=0;//清楚鬼影
								
								break;
							}
							else//反射峰宽度不满足条件
							{
								event_noise=0;
								event_avg_lever=0;
								for(m=0;m<10;m++)
								{
									if(Reflex_Event_start[j]<(2+m))continue;
									event_noise=event_noise+abs(input_data_buff[Reflex_Event_start[j]-2-m]-input_data_buff[Reflex_Event_start[j]-3-m]);
									event_avg_lever=event_avg_lever+input_data_buff[Reflex_Event_start[j]-2-m];
								}
								event_noise=event_noise/10;
								event_avg_lever=event_avg_lever/10;
								if(event_noise>fiber_end_radio/2&&event_avg_lever<=4*fiber_end_lever)
								{
									if(i==Reflex_event_count-1)
									{
										length_real_Zero=Reflex_Event_start[j];
										length_real_gy=Reflex_Event_start[i];
									}
									Reflex_Event_start[j]=0;
									Reflex_Event_end[j];//清楚鬼影
									
									break;
								}
							}
						}
					}
					else//超过了常规误差点，判断是否在噪声中，
					{
						//首先判断反射峰宽度是否比较小，是前一个反射峰宽度的一半

						if(Reflex_Event_end[i]-Reflex_Event_start[i]>=2*(Reflex_Event_end[j]-Reflex_Event_start[j]))
						{
							event_noise=0;
							event_avg_lever=0;
							for(m=0;m<10;m++)
							{
								if(Reflex_Event_start[j]<(2+m))continue;
								event_noise=event_noise+abs(input_data_buff[Reflex_Event_start[j]-2-m]-input_data_buff[Reflex_Event_start[j]-3-m]);
								event_avg_lever=event_avg_lever+input_data_buff[Reflex_Event_start[j]-2-m];
							}
							event_noise=event_noise/10;
							event_avg_lever=event_avg_lever/10;
							if(event_noise>fiber_end_radio/2&&event_avg_lever<=2*(fiber_end_lever+fiber_end_radio))
							{
								if(i==Reflex_event_count-1)
								{
									length_real_Zero=Reflex_Event_start[j];
									length_real_gy=Reflex_Event_start[i];
								}
								Reflex_Event_start[j]=0;
								Reflex_Event_end[j]=0;//清楚鬼影
								
							}
						}
						else
						{

						}
					}
				}
				else if(Reflex_Event_start[j]<2*Reflex_Event_start[i])//小于两倍长度
				{
					flag=0;
					int reflex_pulse_point1=0,reflex_pulse_point2=0;
					for(m=Reflex_Event_start[i]+3;m<Reflex_Event_end[i];m++)
					{
						if(input_data_buff[m]<input_data_buff[Reflex_Event_start[i]+1]&&input_data_buff[m+1]<=input_data_buff[Reflex_Event_start[i]+1])
						{

							reflex_pulse_point1=m-Reflex_Event_start[i];
							flag=1;
							break;
						}
					}
					if(flag==0)reflex_pulse_point1=Reflex_Event_end[i]-Reflex_Event_start[i];
					flag=0;
					for(m=Reflex_Event_start[j]+3;m<Reflex_Event_end[j];m++)
					{
						if(m>=input_length-10)break;
						if(input_data_buff[m]<=input_data_buff[Reflex_Event_start[j]+1]&&input_data_buff[m+1]<=input_data_buff[Reflex_Event_start[j]+1])
						{

							reflex_pulse_point2=m-Reflex_Event_start[j];
							flag=1;
							break;
						}
					}
					if(flag==0)reflex_pulse_point2=Reflex_Event_end[j]-Reflex_Event_start[j];

						if(reflex_pulse_point1>=reflex_pulse_point2)//*、、*/判断反射峰宽度
						{
							event_noise=0;
							event_avg_lever=0;
							for(m=0;m<10;m++)
							{
								if(Reflex_Event_start[j]<(2+m))continue;
								event_noise=event_noise+abs(input_data_buff[Reflex_Event_start[j]-2-m]-input_data_buff[Reflex_Event_start[j]-3-m]);
								event_avg_lever=event_avg_lever+input_data_buff[Reflex_Event_start[j]-2-m];
							}
							event_noise=event_noise/10;
							event_avg_lever=event_avg_lever/10;
							if(event_noise>fiber_end_radio/2&&event_avg_lever<=2*(fiber_end_lever+fiber_end_radio))
							{
								if(i==Reflex_event_count-1)
								{
									length_real_Zero=Reflex_Event_start[j];
									length_real_gy=Reflex_Event_start[i];
								}
								Reflex_Event_start[j]=0;
								Reflex_Event_end[j]=0;//清楚鬼影
								
							}
						}
				}
			}

			
		}
	}
#endif
	/////////////第三次鬼影判断，专门判断末端针对中间端面的鬼影
#if 1

	if(Reflex_event_count)
	{
		if(input_data_buff[Reflex_Event_start[Reflex_event_count-1]]>2*(fiber_end_lever+fiber_end_radio))
		{

			if(Reflex_Event_start[Reflex_event_count-1]<length_real)
			{
				if(input_data_buff[length_real]<(input_data_buff[Reflex_Event_start[Reflex_event_count-1]]+2000))
					if(length_real<Reflex_Event_end[Reflex_event_count-1]+3*(Reflex_Event_end[Reflex_event_count-1]-Reflex_Event_start[Reflex_event_count-1]))
					{
						length_real=Reflex_Event_start[Reflex_event_count-1];
					}
			}
		}
	}
#endif


//	做二级鬼影判断
	if(Reflex_event_count>=2)
	{
	//	int Evenet_lever_s=0;
	//	int Evenet_noise=0;
		for(i=0;i<Reflex_event_count-1;i++)
		{
			for(j=i+1;j<Reflex_event_count;j++)
			{
				if(Reflex_Event_start[j]>=3*Reflex_Event_start[i])
				{
					if(Reflex_Event_start[j]<2)continue;
					if(Reflex_Event_start[j]<=3*Reflex_Event_start[i]+2*Double_lenght_erro_point)
					{
						if(input_data_buff[Reflex_Event_start[i]]-input_data_buff[Reflex_Event_start[j]]>5000)
						{
							if((input_data_buff[Reflex_Event_start[j]-2]+input_data_buff[Reflex_Event_start[j]-1]+input_data_buff[Reflex_Event_start[j]])/3<5000)//(3*fiber_end_lever+3*fiber_end_radio))
							{
								Reflex_Event_start[j]=0;
								Reflex_Event_end[j]=0;//清楚鬼影
							}
							else if((input_data_buff[Reflex_Event_start[j]-2]+input_data_buff[Reflex_Event_start[j]-1]+input_data_buff[Reflex_Event_start[j]])/3<6000)
							{
								if(abs(input_data_buff[Reflex_Event_start[j]-2]-input_data_buff[Reflex_Event_start[j]-1]+abs(input_data_buff[Reflex_Event_start[j]-1]-input_data_buff[Reflex_Event_start[j]]))>200)
								{
									Reflex_Event_start[j]=0;
									Reflex_Event_end[j]=0;//清楚鬼影
								}
							}
						}
					}
				}
			}
		}

	}


	//搜索数据中所有衰减特性的突变起始点
	//搜索衰减事件

	//for(i=2*Start_point;i<input_length-10;i++)
	//if(step_point<20)step_point=20;
#if 1

	//if(length_real_Zero>0&&length_real_Zero+10*step_point<input_length-10)
	//{
 //      if((input_data_buff[(length_real_Zero+10*step_point)])<=3*(fiber_end_lever+fiber_end_radio))
	//   //if(input_data_buff[length_real_Zero]-input_data_buff[length_real_Zero+10*step_point]<)
	//   {
	//	   length_real=length_real_Zero;
	//   }
	//   else 
	//   {
	//	   if(input_data_buff[Start_point]-input_data_buff[length_real_Zero]<(input_data_buff[length_real_Zero]-input_data_buff[length_real_gy])/2)
	//	   {
	//		   if(input_data_buff[length_real_Zero]-(input_data_buff[(length_real_Zero+10*step_point)])>=3000)
	//			   length_real=length_real_Zero;
	//	   }
	//   }
	//}
	if(length_real_Zero&&length_real_gy)
	{

		length_real=length_real_Zero;
	}
	
	int loss_event_avg_start=0;
	int loss_event_avg_end=0;
	int loss_step_avg=0;
	int lever_count=0;
	float up_pecent=0;
	int max_buff=0;
	float Head_event_loss=0;
	float NN_BUFF=0;
	int SS_POINT=0;
	int down_cn=4;
	int loss_buff=0;
	int I_Jump_step=0;
	if(pulsewidth>=1000)I_Jump_step=2*step_point/2;
	else I_Jump_step=step_point;
	if(Start_point<5)SS_POINT=5;
	else SS_POINT=2*Start_point;
	for(i=SS_POINT;i<length_real-step_point/2;i++)
	{
		
		 loss_event_avg_start=0;
		 loss_event_avg_end=0;
		 loss_step_avg=0;
		 lever_count=0;
		 up_pecent=0;
	     max_buff=0;
		 Head_event_loss=0;
		 down_cn=4;
		 loss_buff=0;
		if(i<=step_point)i=2*step_point;
		if(step_point<5)down_cn=3;
		else down_cn=step_point/4;
		if(pulsewidth>=2000)down_cn=step_point/3;

		if(down_cn<3)down_cn=3;

		if(i>=length_real)break;
		if(i>=input_length-step_point)break;
		event_noise=0;
		event_avg_lever=0;
		flag=0;
		

		event_noise=0;
		event_avg_lever=0;
		for(m=i;m>i-step_point;m--)
		{
			if(m>=input_length-10)break;
			if(m<=0)break;
			event_noise=event_noise+abs(input_data_buff[m]-input_data_buff[m+1]);
			event_avg_lever=event_avg_lever+input_data_buff[m];
		}
		//if(m!=i)
		{
			event_noise=event_noise/step_point;
			event_avg_lever=event_avg_lever/step_point;
		}	
		

		//判断下降沿,下降突变
		//if((input_data_buff[i]>(input_data_buff[i+1]+2*event_noise+2*Point_to_point_loss))&&(input_data_buff[i+1]>(input_data_buff[i+2]+2*event_noise+2*Point_to_point_loss)))
			if(i>=6136)
			down_count=0;
		if(((input_data_buff[i]>(input_data_buff[i+2]+2*event_noise))&&(input_data_buff[i]>(input_data_buff[i+4]+2*event_noise)))&&(input_data_buff[i]>(input_data_buff[i+6]+2*event_noise)))
		{
			down_count=0;
			
			for(j=i;j<i+step_point;j++)
			{
				if(j>=input_length-10)break;
				Natural_loss=(j-i+2)*Point_to_point_loss;
				//if(Natural_loss<10)Natural_loss=10;
			    if(wavelength<1490)NN_BUFF=2*Natural_loss/5;
				else NN_BUFF=6*Natural_loss/5;
				if((input_data_buff[i]>(input_data_buff[j+1]+event_noise+NN_BUFF)))//&&(input_data_buff[i+1]>(input_data_buff[j+2]+event_noise+Natural_loss))&&(input_data_buff[i+2]>(input_data_buff[j+3]+event_noise+Natural_loss)))
				{
					up_count=0;
					down_count++;
					if(down_count>=down_cn)
					{
						flag2=0;
						flag=0;
						//判断是否是反射事件引起的衰减
						if(step_point>=20)
						{
							loss_event_avg_end=(input_data_buff[i+down_cn]+input_data_buff[i-1+down_cn]+input_data_buff[i+1+down_cn])/3;
							loss_event_avg_end=loss_event_avg_end-(input_data_buff[i+step_point/2+down_cn]+input_data_buff[i+step_point/2-1+down_cn]+input_data_buff[i+step_point/2+1+down_cn])/3;


							loss_event_avg_start=(input_data_buff[i-step_point/2+1-down_cn]+input_data_buff[i-step_point/2-1-down_cn]+input_data_buff[i-step_point/2-down_cn])/3;

							loss_event_avg_start=loss_event_avg_start-(input_data_buff[i-down_cn]+input_data_buff[i-1-down_cn]+input_data_buff[i+1-down_cn])/3;
							Natural_loss=Point_to_point_loss*step_point/2;
						}
						else
						{
							loss_event_avg_end=(input_data_buff[i+down_cn]+input_data_buff[i+1+down_cn]+input_data_buff[i-1+down_cn])/3-(input_data_buff[i+10+down_cn]+input_data_buff[i+11+down_cn]+input_data_buff[i+9+down_cn])/3;
							loss_event_avg_start=(input_data_buff[i-9-down_cn]+input_data_buff[i-10-down_cn]+input_data_buff[i-11-down_cn])/3-(input_data_buff[i-down_cn]+input_data_buff[i-1-down_cn]+input_data_buff[i+1-down_cn])/3;
							Natural_loss=Point_to_point_loss*10;
						}
						if(Reflex_event_count==1)
						{
							if(i<Reflex_Event_start[0])//只有一个反射峰，并且在反射峰的前面
							{
								if(i>Start_point+2*step_point)
								{
									if(fiber_end_radio>2*event_noise&&input_data_buff[i]>2*(fiber_end_lever+event_noise))
									{
										if(loss_event_avg_end>loss_event_avg_start+2*event_noise)
										{
											if(Loss_event_count<98&&loss_event_avg_end>20)
											{
												
												Loss_Event_start[Loss_event_count++]=j-down_count;
												i=j+I_Jump_step;
												flag=1;
												break;
											}
										}
										
									}
									
								}
							}
							else
							{
								if(i>Reflex_Event_end[0]&&i<length_real)
								{
									if(fiber_end_radio>2*event_noise&&(input_data_buff[i]>2*(fiber_end_lever+event_noise)))
									{
										if(loss_event_avg_end>(loss_event_avg_start+event_noise+Natural_loss))//&&loss_event_avg_start<20*Natural_loss)
										{
											//if(loss_event_avg_start<30*Natural_loss)
											{
												if(loss_event_avg_start>20)
												{
													if(Loss_event_count<98&&loss_event_avg_end>20)
													{
														Loss_Event_start[Loss_event_count++]=j-down_count;
														i=j+I_Jump_step;
														flag=1;
														break;
													}
												}
											}
											//else
											{

											}
											
											
										}
										
									}
								}
							}
						}
						else if(Reflex_event_count==0)
						{
							if(i>Start_point+2*step_point)
							{
								if(i<length_real)
									if(fiber_end_radio>2*event_noise&&input_data_buff[i]>2*(fiber_end_lever+fiber_end_lever+event_noise))
									{
										if(Loss_event_count<98&&loss_event_avg_end>20)
										{
											Loss_Event_start[Loss_event_count++]=j-down_count;
											i=j+I_Jump_step;
											flag=1;
											break;
										}
									}
							}
						}
						else
						{

							if(i<Reflex_Event_start[0])//小于第一个反射峰的下标
							{
								if(i>Start_point+2*step_point)
								{
									if(fiber_end_radio>2*event_noise&&input_data_buff[i]>2*(fiber_end_lever+fiber_end_lever+event_noise))
									{
										if(loss_event_avg_end>(4*Natural_loss/3+event_noise)&&loss_event_avg_end>loss_event_avg_start)//(loss_event_avg_start+event_noise+Natural_loss))//&&loss_event_avg_start<20*Natural_loss)
										{
											if(Loss_event_count<98&&loss_event_avg_end>20)
											{
												Loss_Event_start[Loss_event_count++]=j-down_count;
												i=j+I_Jump_step;
												flag=1;
												break;
											}
										}
										
										//	break;
									}
								}
							}
							else if(i>Reflex_Event_start[Reflex_event_count-1])//在最后一个反射事件之后
							{
								if(i>Reflex_Event_end[Reflex_event_count-1]&&i<input_length-step_point/2)
								{
									if(input_data_buff[i]>2*fiber_end_lever+fiber_end_radio)
									{
										if(loss_event_avg_end>(loss_event_avg_start+event_noise+Natural_loss)&&loss_event_avg_start<5*Natural_loss)
										{
											if(input_data_buff[i]<=input_data_buff[Reflex_Event_start[Reflex_event_count-1]])
											{
												if(Loss_event_count<98&&loss_event_avg_end>20)
												{
													Loss_Event_start[Loss_event_count++]=j-down_count;
													i=j+I_Jump_step;
													flag=1;
													break;
												}
											//	Loss_Event_start[Loss_event_count++]=i;
												//flag=1;
											}
											
										}
									}
								}
							}
							else
							{
								for(n=0;n<Reflex_event_count;n++)
								{

									if(i>Reflex_Event_end[n])
									{
										if(i<Reflex_Event_start[n+1])//满足前一个反射事件的结束点和下一个反射事件起始点之间
										{
											if(loss_event_avg_end>20)//衰减值要求大于0.02dB
											{
												if(loss_event_avg_end>(loss_event_avg_start+event_noise+Natural_loss))//&&loss_event_avg_start<5*Natural_loss)
												{
													if(Loss_event_count<98&&loss_event_avg_end>20)
													{
														Loss_Event_start[Loss_event_count++]=j-down_count;
														i=j+I_Jump_step;
														flag=1;
													}
													
													break;
												}
												
											}

										}
									}
									/*else
									{
										if(Loss_event_count<98)
										{
											Loss_Event_start[Loss_event_count++]=i-down_cn;
											i=i+step_point/2;
											flag=1;
										}

										break;
									}*/
								}
							}

							
						}
						
							
							i=i+step_point/2;

							break;
						
						
					}
				}
				else 
				{
					up_count++;
					//if(up_count>=2)
					{
						down_count=0;
					}
					break;
				}

			}
			
		}
		//else down_count++;

	}
#endif
//衰减事件位置调整
	n=0;
	m=0;
	down_count=0;
	m=step_point/4;
	if(m<5)m=5;
	for(i=0;i<Loss_event_count;i++)
	{
		down_count=0;
		for(j=Loss_Event_start[i];j>Loss_Event_start[i]-5;j--)
		{
			if(j<=0)break;
			if(input_data_buff[j]-input_data_buff[j+1]>20)
			{
				n++;
				down_count=0;
				//Loss_Event_start[i]=j;
				//break;
			}
			else
			{
				down_count++;
				if(down_count>=2)
				{
					Loss_Event_start[i]=j;
					break;
				}
			}
		}
	}

/************************************************/

/***************************************************/
//寻找衰减事件的结束点

	if(Loss_event_count)
	{
		for(i=0;i<Loss_event_count;i++)
		{
			flag=0;
			for(j=Loss_Event_start[i]+step_point/4;Loss_Event_start[i]+3*step_point/2;j++)
			{
				if(j>=input_length-3*step_point)break;
				if(input_data_buff[j]<input_data_buff[j+1]&&input_data_buff[j]<input_data_buff[j+2]&&input_data_buff[j]<input_data_buff[j+2])
				{
					//碰到3个点的上升，认为衰减位置结束
					if(j>=Loss_Event_start[i]+2*step_point/3)
					{
						Loss_Event_end[i]=j;
						flag=1;
						break;
					}
				}
			}
			if(flag==0)
			{
				Loss_Event_end[i]=j;
				flag=1;
				break;
			}
		}
	}





/******************************************************/
	sGabor_Result.Valid_Num=0;
	sGabor_Result.Event_type[sGabor_Result.Valid_Num]='S';
	sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=1;
	sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=Start_point;//*6/5;

	for(i=0;i<Reflex_event_count;i++)
	{
		if(sGabor_Result.Valid_Num<98)
		{
			if(Reflex_Event_start[i]!=0)
			{
				sGabor_Result.Event_type[sGabor_Result.Valid_Num]='F';
				sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=1;
				sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=Reflex_Event_start[i];
				Event_Array_End[sGabor_Result.Valid_Num++]=Reflex_Event_end[i];

				/*sGabor_Result.Event_type[sGabor_Result.Valid_Num]='E';
				sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=2;
				sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=Reflex_Event_end[i];*/

				//Event_Array_End[sGabor_Result.Valid_Num++]=Reflex_Event_end[i];

		        
			}
		}
        

		
	}
	for(i=0;i<Loss_event_count;i++)
	{
		if(sGabor_Result.Valid_Num<98)
		{
			sGabor_Result.Event_type[sGabor_Result.Valid_Num]='F';
			sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=0;
			sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=Loss_Event_start[i];
			Event_Array_End[sGabor_Result.Valid_Num++]=Loss_Event_end[i];
		}
		else break;
		
		

	}
	//事件排序
	for(i=0;i<sGabor_Result.Valid_Num;i++)
	{
		for(j=0;j<i;j++)
		{
			if(sGabor_Result.Event_Array[j]>sGabor_Result.Event_Array[i])
			{
				sGabor_Result.Event_Array[99]=sGabor_Result.Event_Array[i];
				sGabor_Result.Event_Array[i]=sGabor_Result.Event_Array[j];
				sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[99];

				sGabor_Result.Event_type[99]=sGabor_Result.Event_type[i];
				sGabor_Result.Event_type[i]=sGabor_Result.Event_type[j];
				sGabor_Result.Event_type[j]=sGabor_Result.Event_type[99];
				

				sGabor_Result.Reflect_Type[99]=sGabor_Result.Reflect_Type[i];
				sGabor_Result.Reflect_Type[i]=sGabor_Result.Reflect_Type[j];
				sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[99];


				Event_Array_End[99]=Event_Array_End[i];
				Event_Array_End[i]=Event_Array_End[j];
				Event_Array_End[j]=Event_Array_End[99];
				//Event_Array_End[j]=Event_Array_End[99];

			}
		}
	}


Acount_Loss(wavelength,pulsewidth,input_data,paramLen,&sGabor_Result,Index_N,Sample_freaq);


float Distance_to_head=0;
int HEAD_LOSS=0;
int END_LOSS=0;
if(Reflex_event_count==0&&sGabor_Result.Valid_Num>=2)//没有反射事件，判断是否为空测
{
	HEAD_LOSS=0;
	END_LOSS=0;
	Distance_to_head=0;
	Distance_point_to_point=4/(Sample_freaq/25);
	if(sGabor_Result.Valid_Num==2)
	{
		Distance_to_head=Distance_point_to_point*sGabor_Result.Event_Array[1];
		if(Distance_to_head<Distance_point_to_point*(3*step_point))
		{
			sGabor_Result.Valid_Num=1;
		}
		else
		{
			HEAD_LOSS=input_data_buff[sGabor_Result.Event_Array[1]-step_point]-input_data_buff[sGabor_Result.Event_Array[1]];
			END_LOSS= input_data_buff[sGabor_Result.Event_Array[1]]-input_data_buff[sGabor_Result.Event_Array[1]+step_point];
			if(HEAD_LOSS>=END_LOSS)
			{
				sGabor_Result.Valid_Num=1;
			}
		}
	}
	else
	{
		for(i=sGabor_Result.Valid_Num-1;i>0;i--)
		{
			HEAD_LOSS=(input_data_buff[sGabor_Result.Event_Array[i]-step_point-1]+input_data_buff[sGabor_Result.Event_Array[i]-step_point]+input_data_buff[sGabor_Result.Event_Array[i]-step_point+1])/3;
			HEAD_LOSS=HEAD_LOSS-(input_data_buff[sGabor_Result.Event_Array[i]-1]+input_data_buff[sGabor_Result.Event_Array[i]]+input_data_buff[sGabor_Result.Event_Array[1]+1])/3;
			END_LOSS= (input_data_buff[sGabor_Result.Event_Array[i]+1]+input_data_buff[sGabor_Result.Event_Array[i]-1]+input_data_buff[sGabor_Result.Event_Array[i]])/3;
			END_LOSS=END_LOSS-(input_data_buff[sGabor_Result.Event_Array[i]+step_point-1]+input_data_buff[sGabor_Result.Event_Array[i]+step_point]+input_data_buff[sGabor_Result.Event_Array[i]+step_point+1])/3;
			Natural_loss=Point_to_point_loss*step_point;
			if(END_LOSS>=3000)
			{

					if(HEAD_LOSS>END_LOSS)
					{
						sGabor_Result.Event_Array[i]=0;
					}
			}
			else
			{
				if(HEAD_LOSS>=END_LOSS)
				{
					sGabor_Result.Event_Array[i]=0;
				}
				else
				{
					if(sGabor_Result.Event_Array[i]*Distance_point_to_point<200)
					{
						if(HEAD_LOSS>100&&END_LOSS>200)
						{
							if(HEAD_LOSS>END_LOSS/2)
							{
								sGabor_Result.Event_Array[i]=0;
							}
							else 
							{
								if(HEAD_LOSS>20*Natural_loss)
								{
									sGabor_Result.Event_Array[i]=0;
								}
							}
						}
						else if(HEAD_LOSS<=-20)
						{
							sGabor_Result.Event_Array[i]=0;
						}
					}
					
				}
			}
		}
		

	}
	
}

//删除伪衰减点，

	if(length_real_Zero>0&&Loss_event_count)
	{
		
		for(i=sGabor_Result.Valid_Num-1;i>0;i--)
		{
			if(sGabor_Result.Reflect_Type[i]==0)
			{
				if(sGabor_Result.Event_Array[i]<length_real_gy&&sGabor_Result.Event_Array[i]>length_real_Zero)//
				{
					if(sGabor_Result.Event_Loss[i]<0.5)
					{
						sGabor_Result.Event_Array[i]=0;
					}
					else if(sGabor_Result.Event_Loss[i]>2)
					{
						//sGabor_Result.Event_Array[i]=0;
						length_real=sGabor_Result.Event_Array[i];
						break;
					}
				}
				else
				{
					//sGabor_Result.Event_Array[i]=0;
					if(sGabor_Result.Event_Array[i]>length_real_gy)
						sGabor_Result.Event_Array[i]=0;
					//break;
				}
			}

		}

	}
	j=0;

for(i=0;i<sGabor_Result.Valid_Num;i++)
{

	if(sGabor_Result.Event_Array[i]>0)
	{
		sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
		sGabor_Result.Event_type[j]=sGabor_Result.Event_type[i];
		sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
		sGabor_Result.Event_Loss[j]=sGabor_Result.Event_Loss[i];
		Event_Array_End[j]=Event_Array_End[i];
		j++;


	}
}
//利用损耗特性判断是否是末端反射峰造成的衰减
#if 1
float Float_data_buff=0,Float_data_buff2=0;

if(sGabor_Result.Valid_Num>=2)
{
	for(i=sGabor_Result.Valid_Num-1;i>0;i--)
	{
		if(sGabor_Result.Reflect_Type[i]>0)
		{
			n=i;
			break;
		}
	}
	for(i=n;i<sGabor_Result.Valid_Num;i++)
	{
		if(i==sGabor_Result.Valid_Num-1&&sGabor_Result.Reflect_Type[i]==0)
		{
			data_sum=0;
			Natural_loss=Point_to_point_loss*step_point;
			Natural_loss=Natural_loss/1000;
            if(sGabor_Result.Event_Array[i]-step_point+1<input_length-10)
			{
				data_sum=(input_data_buff[sGabor_Result.Event_Array[i]-step_point]-input_data_buff[sGabor_Result.Event_Array[i]])/1000;

				data_sum=data_sum+(input_data_buff[sGabor_Result.Event_Array[i]-step_point+1]-input_data_buff[sGabor_Result.Event_Array[i]+1]);
				data_sum=data_sum+(input_data_buff[sGabor_Result.Event_Array[i]-step_point+2]-input_data_buff[sGabor_Result.Event_Array[i]+2]);
				Float_data_buff=data_sum;
				Float_data_buff=Float_data_buff/3000;
			}
			

			data_sum=0;

			if(sGabor_Result.Event_Array[i]+step_point-1<input_length-10)
			{
				data_sum=(input_data_buff[sGabor_Result.Event_Array[i]]-input_data_buff[sGabor_Result.Event_Array[i]+step_point])/1000;

				data_sum=data_sum+(input_data_buff[sGabor_Result.Event_Array[i]-1]-input_data_buff[sGabor_Result.Event_Array[i]+step_point-1]);
				data_sum=data_sum+(input_data_buff[sGabor_Result.Event_Array[i]-2]-input_data_buff[sGabor_Result.Event_Array[i]+step_point-2]);
				Float_data_buff2=data_sum;
				Float_data_buff2=Float_data_buff2/3000;

			}
			
			
			if(Float_data_buff>=Float_data_buff2)
			{

				sGabor_Result.Event_Array[i]=0;

			}
		}
		if(sGabor_Result.Reflect_Type[i]==0&&sGabor_Result.Event_Loss[i]>0.4)
		{

			data_sum=0;
			Natural_loss=Point_to_point_loss*step_point;
			Natural_loss=Natural_loss/1000;

			data_sum=(input_data_buff[sGabor_Result.Event_Array[i]-step_point]-input_data_buff[sGabor_Result.Event_Array[i]])/1000;

			if(sGabor_Result.Event_Array[i]-step_point+1<=input_length-10)
			{
				data_sum=data_sum+(input_data_buff[sGabor_Result.Event_Array[i]-step_point+1]-input_data_buff[sGabor_Result.Event_Array[i]+1]);
				data_sum=data_sum+(input_data_buff[sGabor_Result.Event_Array[i]-step_point+2]-input_data_buff[sGabor_Result.Event_Array[i]+2]);
				Float_data_buff=data_sum;
				Float_data_buff=Float_data_buff/3000;
			}
			
			if(Float_data_buff>=sGabor_Result.Event_Loss[i])
			{

				sGabor_Result.Event_Array[i]=0;

			}
			else
			{
				if(Float_data_buff>=20*Natural_loss&&Float_data_buff>0.2)
				{
					sGabor_Result.Event_Array[i]=0;
				}
			}
		}
	}
}

#endif
j=0;

for(i=0;i<sGabor_Result.Valid_Num;i++)
{

	if(sGabor_Result.Event_Array[i]>0)
	{
		sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
		sGabor_Result.Event_type[j]=sGabor_Result.Event_type[i];
		sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
		sGabor_Result.Event_Loss[j]=sGabor_Result.Event_Loss[i];
		Event_Array_End[j]=Event_Array_End[i];
		j++;


	}
}
sGabor_Result.Valid_Num=j;

//判断衰减事件是否是由于反射峰的下降造成的误判断
if(sGabor_Result.Valid_Num>2)
{
	m=sGabor_Result.Event_Array[0];
	n=Start_point;
	for(i=1;i<sGabor_Result.Valid_Num;i++)
	{
		HEAD_LOSS=0;
		END_LOSS=0;
		HEAD_LOSS=(input_data_buff[sGabor_Result.Event_Array[i]-n/2-1]+input_data_buff[sGabor_Result.Event_Array[i]-n/2]+input_data_buff[sGabor_Result.Event_Array[i]-n/2+1])/3;
		HEAD_LOSS=HEAD_LOSS-(input_data_buff[sGabor_Result.Event_Array[i]-1]+input_data_buff[sGabor_Result.Event_Array[i]]+input_data_buff[sGabor_Result.Event_Array[i]+1])/3;
		END_LOSS= (input_data_buff[sGabor_Result.Event_Array[i]+1]+input_data_buff[sGabor_Result.Event_Array[i]-1]+input_data_buff[sGabor_Result.Event_Array[i]])/3;
		END_LOSS=END_LOSS-(input_data_buff[sGabor_Result.Event_Array[i]+n/2-1]+input_data_buff[sGabor_Result.Event_Array[i]+n/2]+input_data_buff[sGabor_Result.Event_Array[i]+n/2+1])/3;
		Natural_loss=Point_to_point_loss*step_point;

		if(sGabor_Result.Reflect_Type[i])
		{
			m=sGabor_Result.Event_Array[i];
		}
		else
		{
			if(i==1)
			{
				if(sGabor_Result.Event_Array[i]<2*m)
				{
					if(END_LOSS>=200)
					{
						if(HEAD_LOSS>END_LOSS)
						{
							sGabor_Result.Event_Array[i]=0;
						}
					}
				}
			}
			else
			{
				if(HEAD_LOSS>2*END_LOSS/3&&END_LOSS>=200)
				{
					sGabor_Result.Event_Array[i]=0;
				}
				else if(sGabor_Result.Event_Array[i]<m+5*Start_point&&m!=sGabor_Result.Event_Array[0])
				{
					if(END_LOSS>100&&HEAD_LOSS>END_LOSS)
					{
						sGabor_Result.Event_Array[i]=0;
					}
					else if(sGabor_Result.Event_Loss[i-1]<-0.09&&HEAD_LOSS>3*Natural_loss/2)
					{
                       sGabor_Result.Event_Array[i]=0;
					}
				}
			}
			if(HEAD_LOSS<-200)
			{
				sGabor_Result.Event_Array[i]=0;
			}
			
		}
	}
	j=0;

	for(i=0;i<sGabor_Result.Valid_Num;i++)
	{

		if(sGabor_Result.Event_Array[i]>0)
		{
			sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
			sGabor_Result.Event_type[j]=sGabor_Result.Event_type[i];
			sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
			sGabor_Result.Event_Loss[j]=sGabor_Result.Event_Loss[i];
			Event_Array_End[j]=Event_Array_End[i];
			j++;


		}
	}
	sGabor_Result.Valid_Num=j;
}



	//
	if(sGabor_Result.Valid_Num<2)
	{
		flag=0;
		for(i=input_length-10;i>2*Start_point;i--)
		{
			if(i<=0)break;
			if(flag)break;
			if(input_data_buff[i]>2*(fiber_end_lever+fiber_end_radio))
			{
				up_count++;
				if(up_count>=step_point/2)
				{
					min_data=65535;
					min_data_mark=i;
					max_data=0;
					max_data_mark=i;
					for(j=i;j>2*step_point;j--)
					{
						if(input_data_buff[j]<=2*(fiber_end_lever+fiber_end_radio))
						{
							
							down_count++;
							if(down_count>=5)
							{
								sGabor_Result.Event_type[sGabor_Result.Valid_Num]='F';
								sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=j;
								sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num++]=1;
								flag=1;
								break;
							}
						}
						else down_count=0;
						if(min_data>=input_data_buff[j])
						{
							min_data=input_data_buff[j];
							min_data_mark=j;
						}
						if(max_data<input_data_buff[j])
						{
							max_data=input_data_buff[j];
							max_data_mark=j;
						}
						if(min_data_mark>max_data_mark)
						{
							min_data=max_data;
							min_data_mark=max_data_mark;
						}
					}
					if(flag==0)//没有找到末端
					{
						if(max_data_mark>=Start_point+Start_point)
						{

							sGabor_Result.Event_type[sGabor_Result.Valid_Num]='F';
							sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=max_data_mark-3;
							sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num++]=1;
					    }
						else
						{
							sGabor_Result.Event_type[sGabor_Result.Valid_Num]='F';
							sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=Start_point+step_point;
							sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num++]=1;
						}
						break;
					}
				}
			}
			else
			{
				up_count=0;
			}
		}
	}
//末端为衰减事件的末端重新查找
	if(sGabor_Result.Valid_Num>=2&&Sample_freaq<=25&&pulsewidth<=100)
	{
	   if(sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]==0)
		   for(i=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1];i<input_length-step_point;i++)
		   {
			   if(input_data_buff[i]>input_data_buff[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]]+1500)
			   {

                  if(input_data_buff[i+1]>input_data_buff[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]]+2000)
				  {
					  if(input_data_buff[i+2]>input_data_buff[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]]+500)
					  {
						  if(input_data_buff[i]>fiber_end_lever+fiber_end_radio)
						  {
							  if(input_data_buff[i+1]>fiber_end_lever+fiber_end_radio)
								  if(input_data_buff[i+2]>fiber_end_lever+fiber_end_radio)
								  {
									  if(sGabor_Result.Valid_Num<98)
									  {

										  sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=i-1;
										  sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=1;
										  sGabor_Result.Event_type[sGabor_Result.Valid_Num++]='E';
										  break;
								      }
								  }
						  }
					  }
				  }
			   }
		   }
	}

	



	//delete[] input_data_buff;
	//delete[] sum_k;
#if DEBUG
	;
#else 
	delete[] Reflex_Event_start;
	delete[] Reflex_Event_end;
	delete[] Reflex_Max_mark;
	delete[] Loss_max_mark;
	delete[] Loss_Event_start;
	delete[] Loss_Event_end;
	delete[] Event_Hight;
	delete[] input_data_buff;
#endif
	return sGabor_Result;//element_result[1][1];
}
Gabor_Result gabor_arithmetic(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,double thresholdUpSet,double thresholdDownSet,float dB_Loss,float dB_reflex,float dB_End,float Return_loss_Tybe,float Sample_freaq,float Index_N,int link_point_number)
{
	float dB_Reflex_loss=0;
	//if(link_point_number==0)link_point_number=1959;
	dB_Reflex_loss=link_point_number*4.04/(Sample_freaq/25)/1000;
	if(dB_Reflex_loss>10)link_point_number=0;
	dB_Reflex_loss=0;
    if(dB_End==0)dB_End=30;
	else if(dB_End<=3)dB_End=3;
	if(dB_Loss==0)
	{
		if(pulseWidth>=1000)dB_Loss=0.05;
		else dB_Loss=0.1;

		if(pulseWidth>=1000)
		{
			switch(wavelength)
			{
			case 1310: 
				dB_Loss=0.1;
				break;
			case 1490:
				dB_Loss=0.06;
				break;
			case 1550:
				dB_Loss=0.05;
				break;
			case 1625:
				dB_Loss=0.06;
			case 1650:
				dB_Loss=0.06;
				break;
			case 850:
				dB_Loss=0.15;
				break;
			case 1300:
				dB_Loss=0.12;
				break;
			default:
				dB_Loss=0.05;
				break;
			}
		}
		else
		{
			switch(wavelength)
			{
			case 1310: 
				dB_Loss=0.12;
				break;
			case 1490:
				dB_Loss=0.08;
				break;
			case 1550:
				dB_Loss=0.08;
				break;
			case 1625:
				dB_Loss=0.08;
			case 1650:
				dB_Loss=0.08;
				break;
			case 850:
				dB_Loss=0.15;
				break;
			case 1300:
				dB_Loss=0.15;
				break;
			default:
				dB_Loss=0.1;
				break;
			}
		}
		
		
	}
	dB_Reflex_loss=dB_Loss;
	if(dB_Reflex_loss<0.1)dB_Reflex_loss=0.1;
	if(dB_reflex==0)dB_reflex=0.1;
	if(pulseWidth<=20)//对于10ns以内的反射事件做抬高门限处理。2013.04.21
	{
		if(dB_reflex<=1)dB_reflex=1;
		dB_Reflex_loss=0.5;
	}
    else if(dB_reflex<0.08)dB_reflex=0.08;
//	int pulseNum=12;
	int i=0;
	int j=0;
	int m=0,n=0;
	//switch(pulseWidth)
	//{
	//case 3:
	//	pulseNum=0;
	//	break;
	//case 5:
	//	pulseNum=1;
	//	break;
	//case 10:
	//	pulseNum=2;
	//	break;
	//case 20:
	//	pulseNum=3;
	//	break;
	//case 50:
	//	pulseNum=4;
	//	break;
	//case 100:
	//	pulseNum=5;
	//	break;
	//case 200:
	//	pulseNum=6;
	//	break;
	//case 500:
	//	pulseNum=7;	
	//	break;
	//case 1000:
	//	pulseNum=8;
	//	break;
	//case 2000:
	//	pulseNum=9;
	//	break;
	//case 5000:
	//	pulseNum=10;
	//	break;
	//case 10000:
	//	pulseNum=11;
	//	break;
	//case 20000:
	//	pulseNum=12;
	//	break;
	//case 30:
	//	pulseNum=13;
	//	break;
	//case 300:
	//	pulseNum=14;
	//	break;
	//case 400:
	//	pulseNum=15;
	//	break;
	//default:pulseNum=12;break;
	//}



	int kk=0;


	int* delete_data_buff=new int[100];
	memset(delete_data_buff,0,100*sizeof(int));

	int lEvent=0;

	int k=0;
	double sumTotalLoss=0;
//	lEvent=lEventGenerate(pulseNum,wavelength,Sample_freaq);
   
	lEvent=Step_point_count(pulseWidth,wavelength,Sample_freaq);

   int fiber_end_lever=0;
   int fiber_end_radio=0;

   int step_point=0;
   int flag=0;


	Gabor_Result sGabor_Result;//


	if(paramLen>501)
	{
		for(i=paramLen-1;i>paramLen-501;i--)
		{
			fiber_end_lever=fiber_end_lever+(65535-input_data[i]);
			fiber_end_radio=fiber_end_radio+abs(input_data[i]-input_data[i-1]);
		}
		fiber_end_lever=fiber_end_lever/500;
		fiber_end_radio=fiber_end_radio/500;
	}

	sGabor_Result=gabor_generate(pulseWidth,wavelength,input_data,paramLen,thresholdUpSet,thresholdDownSet,dB_Loss,dB_reflex,dB_End,Sample_freaq,Index_N,link_point_number);

   sGabor_Result.Event_type[sGabor_Result.Valid_Num-1]='E';

   K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   Acount_Loss(wavelength,pulseWidth,input_data,paramLen,&sGabor_Result,Index_N,Sample_freaq);
  // Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
   Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   K_Line_limite(wavelength,&sGabor_Result);
#if 1
   float  event_noise=0;
   float  event_lever=0;
   for(i=0;i<sGabor_Result.Valid_Num;i++)
   {
	   if(sGabor_Result.Reflect_Type[i]==0)
	   {
		   if(i==sGabor_Result.Valid_Num-1)
		   {
			   //求出事件的前段噪声
			   event_noise=0;
			   for(j=sGabor_Result.Event_Array[i];j>sGabor_Result.Event_Array[i]-10;j--)
			   {
				   if(j<=0)break;

				   event_noise=event_noise+abs(input_data[j]-input_data[j-1]);
				   event_lever=event_lever+65535-input_data[j];
			   }
			   event_noise=event_noise/10/1000;
			   event_lever=event_lever/10;
			   if(event_noise>2*sGabor_Result.Event_Loss[i]/3)
			   {

				   if(event_lever<=fiber_end_lever+fiber_end_radio)
				    sGabor_Result.Event_Array[i]=0;
			   }
		   }
		   else
		   {
			   if(sGabor_Result.Event_Loss[i]<=dB_Loss)
			   {

				   // delete_data_buff[kk++]=i;
				   sGabor_Result.Event_Array[i]=0;

			   }
			   else//判断是否为噪声的误判断
			   {
				   //求出事件的前段噪声
				   event_noise=0;
				   event_lever=0;
				   for(j=sGabor_Result.Event_Array[i];j>sGabor_Result.Event_Array[i]-10;j--)
				   {

					   event_noise=event_noise+abs(input_data[j]-input_data[j-1]);
					   event_lever=event_lever+65535-input_data[j];
				   }
				   event_noise=event_noise/10/1000;
				   event_lever=event_lever/10;
				   if(event_noise>sGabor_Result.Event_Loss[i])
				   {

					   sGabor_Result.Event_Array[i]=0;
				   }
				   else
				   {
					   if(event_lever<fiber_end_lever+fiber_end_radio)
					   {
						   sGabor_Result.Event_Array[i]=0;
					   }
				   }
			   }
		   }
		  
	   }
   }
   j=0;
   for(i=0;i<sGabor_Result.Valid_Num;i++)
   {
	   if(sGabor_Result.Event_Array[i]!=0)
	   {
		   sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
		   Event_Array_End[j]=Event_Array_End[i];
		   sGabor_Result.Event_type[j]=sGabor_Result.Event_type[i];
		   sGabor_Result.Reflect_Type[j++]=sGabor_Result.Reflect_Type[i];
		  
	   }
   }
   sGabor_Result.Valid_Num=j;
   K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   Acount_Loss(wavelength,pulseWidth,input_data,paramLen,&sGabor_Result,Index_N,Sample_freaq);
   // Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
   Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   K_Line_limite(wavelength,&sGabor_Result);
#if D26
   if(pulseWidth>1000)
   for(i=0;i<sGabor_Result.Valid_Num;i++)
   {
	   if(sGabor_Result.Reflect_Type[i]==1&&sGabor_Result.Event_Hight[i]>=3&&sGabor_Result.Event_Loss[i]>1)
	   {
		   flag=i;
	   }
	   else
	   {
		   if(sGabor_Result.Event_Hight[i]>12&&(65535-input_data[sGabor_Result.Event_Array[i]])<5*(fiber_end_lever+fiber_end_radio))
		   {

			   flag=i;
		   }
	   }
	   if(flag)
	   {
		   if(sGabor_Result.Reflect_Type[i]==1&&sGabor_Result.Event_Hight[i]<=3)
		   {
			   event_noise=0;
			   event_lever=0;
			   for(j=sGabor_Result.Event_Array[i];j>sGabor_Result.Event_Array[i]-10;j--)
			   {

				   event_noise=event_noise+abs(input_data[j]-input_data[j-1]);
				   event_lever=event_lever+65535-input_data[j];
			   }
			   event_noise=event_noise/10;
			   if(event_noise>=sGabor_Result.Event_Hight[i]/5&&event_noise>100)
			   {

				   sGabor_Result.Event_Array[i]=0;
			   }
		   }
		   else if(sGabor_Result.Reflect_Type[i]==0)
		   {

			   ;
		   }
	   }
   }


   j=0;
   for(i=0;i<sGabor_Result.Valid_Num;i++)
   {
	   if(sGabor_Result.Event_Array[i]!=0)
	   {
		   sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
		   Event_Array_End[j]=Event_Array_End[i];
		   sGabor_Result.Event_type[j]=sGabor_Result.Event_type[i];
		   sGabor_Result.Reflect_Type[j++]=sGabor_Result.Reflect_Type[i];

	   }
   }
   sGabor_Result.Valid_Num=j;


   K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   Acount_Loss(wavelength,pulseWidth,input_data,paramLen,&sGabor_Result,Index_N,Sample_freaq);
  // Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
   Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   K_Line_limite(wavelength,&sGabor_Result);
#endif
///////////////////////////////////////////////////////

   for(i=0;i<sGabor_Result.Valid_Num-1;i++)
   {
	   if(sGabor_Result.Reflect_Type[i]==0)
	   {
		   if(sGabor_Result.Event_Loss[i]<=dB_Loss)
		   {

			   // delete_data_buff[kk++]=i;
			   sGabor_Result.Event_Array[i]=0;

		   }
	   }
   }
   j=0;
   for(i=0;i<sGabor_Result.Valid_Num;i++)
   {
	   if(sGabor_Result.Event_Array[i]!=0)
	   {
		   sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
		   Event_Array_End[j]=Event_Array_End[i];
		   sGabor_Result.Event_type[j]=sGabor_Result.Event_type[i];
		   sGabor_Result.Reflect_Type[j++]=sGabor_Result.Reflect_Type[i];
	   }
   }

   sGabor_Result.Valid_Num=j;
   K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   Acount_Loss(wavelength,pulseWidth,input_data,paramLen,&sGabor_Result,Index_N,Sample_freaq);
  // Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
   Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   K_Line_limite(wavelength,&sGabor_Result);


  
   step_point=Step_point_count(pulseWidth,wavelength,Sample_freaq);
   for(i=0;i<sGabor_Result.Valid_Num;i++)
   {
	   if(sGabor_Result.Reflect_Type[i])
	   {
		   if(sGabor_Result.Event_Loss[i]<-0.5)
		   {
			   if((i+1)<sGabor_Result.Valid_Num)
			   {
				   if(sGabor_Result.Reflect_Type[i+1]==0)
				   {
					   if(sGabor_Result.Event_Array[i+1]-sGabor_Result.Event_Array[i]<4*step_point)
					   {
						   if(sGabor_Result.Event_Loss[i+1]>0.5)
						   {
							   sGabor_Result.Event_Array[i+1]=0;
						   }
					   }
				   }

			   }
		   }

	   }
   }
   j=0;

   for(i=0;i<sGabor_Result.Valid_Num;i++)
   {
	   if(sGabor_Result.Event_Array[i]!=0)
	   {
		   sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
		   Event_Array_End[j]=Event_Array_End[i];
		   sGabor_Result.Event_type[j]=sGabor_Result.Event_type[i];
		   sGabor_Result.Reflect_Type[j++]=sGabor_Result.Reflect_Type[i];
	   }
   }

   sGabor_Result.Valid_Num=j;
   K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   Acount_Loss(wavelength,pulseWidth,input_data,paramLen,&sGabor_Result,Index_N,Sample_freaq);
   //Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
   Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   K_Line_limite(wavelength,&sGabor_Result);
////////////////////////////////////////////////////////////////////////
j=0;
m=0;
   for(i=1;i<sGabor_Result.Valid_Num;i++)
   {
	   if(sGabor_Result.Reflect_Type[i])
	   {
		   j=i;
	   }
	   else
	   {
		   if(j!=0)
		   {
			   if(sGabor_Result.Event_Loss[j]<0)
			   {
				   if(sGabor_Result.Event_Loss[i]<0.2)
				   {
					   if(sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[j]<sGabor_Result.Event_Array[0]+step_point)
					   {
						   sGabor_Result.Event_Array[i]=0;

					   }
				   }
			   }
			   else
			   {
				   if(sGabor_Result.Event_Loss[i]<0.15)
				   {
					   if(sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[j]<sGabor_Result.Event_Array[0]+step_point/2)
					   {
						   sGabor_Result.Event_Array[i]=0;

					   }
				   }

			   }
		   }
	   }
   }
   
   j=0;
   for(i=0;i<sGabor_Result.Valid_Num;i++)
   {
	   if(sGabor_Result.Event_Array[i]!=0)
	   {
		   sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
		   Event_Array_End[j]=Event_Array_End[i];
		   sGabor_Result.Event_type[j]=sGabor_Result.Event_type[i];
		   sGabor_Result.Reflect_Type[j++]=sGabor_Result.Reflect_Type[i];
	   }
   }

   sGabor_Result.Valid_Num=j;

   K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   Acount_Loss(wavelength,pulseWidth,input_data,paramLen,&sGabor_Result,Index_N,Sample_freaq);
   //Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
   Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   K_Line_limite(wavelength,&sGabor_Result);

   for(i=0;i<sGabor_Result.Valid_Num;i++)
   {
	   if(sGabor_Result.Event_Loss[i]>=dB_End&&sGabor_Result.Event_Array[i]>3*sGabor_Result.Event_Array[0])
	   {

		   sGabor_Result.Valid_Num=i+1;
		   sGabor_Result.Event_type[i]='E';
		   break;
	   }
   }

   K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   Acount_Loss(wavelength,pulseWidth,input_data,paramLen,&sGabor_Result,Index_N,Sample_freaq);
  // Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
   Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   K_Line_limite(wavelength,&sGabor_Result);

   for(i=1;i<sGabor_Result.Valid_Num-1;i++)
   {
	   if(sGabor_Result.Event_Array[i]>=(sGabor_Result.Event_Array[i+1]-3))
	   {
	      if(sGabor_Result.Reflect_Type[i])
		  {
			  //if(sGabor_Result.Reflect_Type[i+1])
			  {
				  sGabor_Result.Event_Array[i+1]=0;
			  }
			 // else
		  }
		  else 
		  {
			  if(sGabor_Result.Reflect_Type[i+1])
			  {

				  sGabor_Result.Event_Array[i]=0;
			  }
			  else
			  {

				  sGabor_Result.Event_Array[i+1]=0;
			  }
		  }
	   }
   }
   j=0;
   for(i=0;i<sGabor_Result.Valid_Num;i++)
   {
	   if(sGabor_Result.Event_Array[i]!=0)
	   {
		   sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
		   Event_Array_End[j]=Event_Array_End[i];
		   sGabor_Result.Event_type[j]=sGabor_Result.Event_type[i];
		   sGabor_Result.Reflect_Type[j++]=sGabor_Result.Reflect_Type[i];
	   }
   }

   sGabor_Result.Valid_Num=j;

   K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   Acount_Loss(wavelength,pulseWidth,input_data,paramLen,&sGabor_Result,Index_N,Sample_freaq);
  // Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
   Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   K_Line_limite(wavelength,&sGabor_Result);

   for(i=0;i<sGabor_Result.Valid_Num;i++)
   {
	  if(sGabor_Result.Event_Loss[i]>=dB_End&&sGabor_Result.Event_Array[i]>3*sGabor_Result.Event_Array[0])
	   {

		   sGabor_Result.Valid_Num=i+1;
		   sGabor_Result.Event_type[i]='E';
		   break;
	   }
   }

   K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   Acount_Loss(wavelength,pulseWidth,input_data,paramLen,&sGabor_Result,Index_N,Sample_freaq);
  // Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
   Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   K_Line_limite(wavelength,&sGabor_Result);
   if(sGabor_Result.Valid_Num>2)
   {
	   if(sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]==0)
	   {
		   if(sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-2]==1)
		   {
			   if(sGabor_Result.Event_Loss[sGabor_Result.Valid_Num-2]<-0.5)
			   {

				   if(pulseWidth<=200)
				   n=20*step_point;
				   else if(pulseWidth<=1000)n=10*step_point;
				   else if(pulseWidth<=5000)n=5*step_point;
				   else n=3*step_point;
				   if(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-sGabor_Result.Event_Array[sGabor_Result.Valid_Num-2]<n)
				   {

					   sGabor_Result.Valid_Num--;
					   sGabor_Result.Event_type[sGabor_Result.Valid_Num-1]='E';
				   }
			   }
		   }
	   }
   }
   K_Line_count(lEvent,wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   Acount_Loss(wavelength,pulseWidth,input_data,paramLen,&sGabor_Result,Index_N,Sample_freaq);
   Acount_return_loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);
   Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
   K_Line_limite(wavelength,&sGabor_Result);
   if(sGabor_Result.Valid_Num)
   {
	   sGabor_Result.Event_Loss[sGabor_Result.Valid_Num-1]=0;
   }
   //反射事件位置校准
   for(i=1;i<sGabor_Result.Valid_Num;i++)
   {
	   n=0;
	   k=50;
	   if(Sample_freaq<=50)
	   {
		   if(pulseWidth<=200)k=200;
		   else if(pulseWidth<=1000) k=100;
		   else k=50;
	   }
	   if(sGabor_Result.Reflect_Type[i]==1)
	   {
		   for(j=sGabor_Result.Event_Array[i]+1;j<sGabor_Result.Event_Array[i]+5;j++)
		   {
			   if(input_data[j]>input_data[j-1])
			   {
				   n=j;
				   continue;
			   }
			   else
			   {
				   if(input_data[j-1]-input_data[j]<k)
				   {
					   n=j;
					   continue;
				   }
				   else break;
			   }
		   }
		   if(n>sGabor_Result.Event_Array[i])
		   {

			   sGabor_Result.Event_Array[i]=n;
		   }
	   }
   }
#endif
////////////////曲线平滑、、、、、、、、、、、、、、、
   if(dB_End==5)
   {
	   for(m=0;m<10;m++)
	   {
		   for(i=sGabor_Result.Event_Array[0];i<sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1];i++)
		   {
			   flag=0;
			   for(j=1;j<sGabor_Result.Valid_Num;j++)
			   {
				   if(i>sGabor_Result.Event_Array[j]&&(i-sGabor_Result.Event_Array[j]<2*step_point))
				   {
					   if(sGabor_Result.Reflect_Type[j]==1)
					   {
						   flag=1;
						   break;
					   }
					   else
					   {
						   if((i-sGabor_Result.Event_Array[j]<step_point))
						   {
							 //  flag=1;
							   break;
						   }
					   }
					  
				   }
				   else if(i<=sGabor_Result.Event_Array[j]&&(sGabor_Result.Event_Array[j]-i<2))
				   {
					   if(sGabor_Result.Reflect_Type[j]==1)
					   flag=1;
					   break;
				   }
			   }
			   if(flag==1)continue;
			   else
			   {
				   input_data[i]=(input_data[i]+input_data[i+1]+input_data[i-1])/3;
			   }
		   }
	   }
   }
#if SAMPLE_ERRO
   ;
#else
	#if Start_Fiber_enable
	   if(link_point_number)
	   {
		   flag=0;
		   if(link_point_number>=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1])
		   {
			   if(link_point_number==sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1])
			   {

				   sGabor_Result.Event_type[sGabor_Result.Valid_Num-1]='S';
				   flag=1;
			   }
			   else
			   {
				   sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=link_point_number;
				   sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=1;
				   sGabor_Result.Event_Loss[sGabor_Result.Valid_Num]=0;
				   sGabor_Result.Event_Hight[sGabor_Result.Valid_Num]=0;
				   sGabor_Result.Event_type[sGabor_Result.Valid_Num]='S';
				   sGabor_Result.Line_k[sGabor_Result.Valid_Num]=sGabor_Result.Line_k[sGabor_Result.Valid_Num-1];
				   sGabor_Result.Total_Loss[sGabor_Result.Valid_Num]=0;
				   flag=1;
				   sGabor_Result.Valid_Num++;
			   }
		   }
		   if(flag==0)
		   {
			   for(i=0;i<sGabor_Result.Valid_Num;i++)
			   {
				   if(sGabor_Result.Event_Array[i]==link_point_number)
				   {
					   sGabor_Result.Event_type[i]='S';
					   flag=1;
					   break;
				   }
			   }
		   }
		   if(flag==0)
		   {
			   for(i=sGabor_Result.Valid_Num;i>0;i--)
			   {
				   if(sGabor_Result.Event_Array[i-1]<link_point_number)
				   {
					   sGabor_Result.Event_Array[i]=link_point_number;
					   sGabor_Result.Reflect_Type[i]=1;
					   sGabor_Result.Event_Loss[i]=0;
					   sGabor_Result.Event_Hight[i]=0;
					   sGabor_Result.Event_type[i]='S';
					   sGabor_Result.Line_k[i]=sGabor_Result.Line_k[i-1];
					   sGabor_Result.Total_Loss[i]=0;
					   flag=2;
					   sGabor_Result.Valid_Num++;
					   break;
					   
				   }
				   else
				   {
					   sGabor_Result.Event_Array[i]=sGabor_Result.Event_Array[i-1];
					   sGabor_Result.Reflect_Type[i]=sGabor_Result.Reflect_Type[i-1];
					   sGabor_Result.Event_Loss[i]=sGabor_Result.Event_Loss[i-1];
					   sGabor_Result.Event_Hight[i]=sGabor_Result.Event_Hight[i-1];
					   sGabor_Result.Event_type[i]=sGabor_Result.Event_type[i-1];
					   sGabor_Result.Line_k[i]=sGabor_Result.Line_k[i-1];
					   sGabor_Result.Total_Loss[i]=sGabor_Result.Total_Loss[i-1];
				   }
			   }
			   if(flag==0)
			   {
				   sGabor_Result.Event_Array[0]=link_point_number;
				   sGabor_Result.Reflect_Type[0]=1;
				   sGabor_Result.Event_Loss[0]=0;
				   sGabor_Result.Event_Hight[0]=0;
				   sGabor_Result.Event_type[0]='S';
				   sGabor_Result.Line_k[0]=sGabor_Result.Line_k[0];
				   sGabor_Result.Total_Loss[0]=0;
				   flag=2;
				   sGabor_Result.Valid_Num++;
			   }
		   }
		   if(flag)
		   {
			   //重新计算总损耗
			   Acount_Total_Loss(wavelength,pulseWidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
			   for(i=0;i<sGabor_Result.Valid_Num;i++)
			   {
				   if(sGabor_Result.Event_Array[i]==link_point_number)
				   {
					   m=i;
				   }
				   if(sGabor_Result.Event_Array[i]>link_point_number)
				   {
					   sGabor_Result.Total_Loss[i]=sGabor_Result.Total_Loss[i]-sGabor_Result.Total_Loss[m];
				   }
			   }
		   }
		   
	   }
	#endif
#endif
/////////////////////////////////////////////

//Deadzoon_function(wavelength,pulseWidth,input_data,paramLen,sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);



   delete[] delete_data_buff;
  
  return sGabor_Result;
}




//******************************************************************//
//     添加事件
//     insertNum:所要插入的事件点的数据点编号
//     wavelength:曲线波长
//     pulsewidth：曲线脉宽
//     input_data[]：分析的原始数据
//     Return_loss_Tybe:典型散射系数
//     paramLen:原始数据长度
//******************************************************************//
//******************************************************************//
//     添加事件
//     insertNum:所要插入的事件点的数据点编号
//     wavelength:曲线波长
//     pulsewidth：曲线脉宽
//     input_data[]：分析的原始数据
//     Return_loss_Tybe:典型散射系数
//     paramLen:原始数据长度
//******************************************************************//
Gabor_Result insertEvent(int insertNum,int wavelength,int pulsewidth,WORD input_data[],int paramLen,Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe)
/*insertPosition插入物理位置
sGaborResult事件分析结果
insertNum插入序号
*/
{

	int i=0;
	int k=0;
	int insertIndex=0;
	i=sGabor_Result.Valid_Num;
	if(insertNum>=paramLen)return sGabor_Result;

	int pulseNum=11;
	int L_event=0;
	switch(pulsewidth)
	{
	case 3:
		pulseNum=0;
		break;
	case 5:
		pulseNum=1;
		break;
	case 10:
		pulseNum=2;
		break;
	case 20:
		pulseNum=3;
		break;
	case 50:
		pulseNum=4;
		break;
	case 100:
		pulseNum=5;
		break;
	case 200:
		pulseNum=6;
		break;
	case 500:
		pulseNum=7;	
		break;
	case 1000:
		pulseNum=8;
		break;
	case 2000:
		pulseNum=9;
		break;
	case 5000:
		pulseNum=10;
		break;
	case 10000:
		pulseNum=11;
		break;
	case 20000:
		pulseNum=12;
		break;
	case 30:
		pulseNum=13;
		break;
	case 300:
		pulseNum=14;
		break;
	case 400:
		pulseNum=15;
		break;
	default:pulseNum=12;break;
	}
	L_event=lEventGenerate(pulseNum,wavelength,Sample_freaq);
	//////////////////////////////////////////////
	//插入点判断，判断其是否已经存在事件，如果已经存在事件就禁止插入
	int j=0;
	int flag=1;
	if(sGabor_Result.Valid_Num>0)
	{
		if(insertNum>sGabor_Result.Event_Array[i-1])
		{

			if((insertNum-sGabor_Result.Event_Array[i-1])>L_event)
			{

				flag=0;
			}
			else flag=1;


		}
		else
		{
			if(i>1)
			{
				for(j=0;j<i;j++)
				{
					if(insertNum<sGabor_Result.Event_Array[0])
					{
						if((insertNum+L_event)<sGabor_Result.Event_Array[0])
						{

							flag=0;
							break;

						}
						else 
						{
							flag=1;
							break;
						}
					}
					if(insertNum>sGabor_Result.Event_Array[j]&&insertNum<sGabor_Result.Event_Array[j+1])
					{
						int k=0;
						if((insertNum-sGabor_Result.Event_Array[j])>L_event&&(sGabor_Result.Event_Array[j+1]-insertNum)>L_event)
						{
							flag=0;
							break;
						}
						else
						{
							flag=1;
							break;
						}
					}
				}

			}
			else
			{
				if((insertNum+L_event)<sGabor_Result.Event_Array[0])
				{
					flag=0;

				}

			}
		}
	}
	else flag=0;
	if(insertNum<=sGabor_Result.Event_Array[0]+L_event/2)flag=1;


	if(flag)return sGabor_Result;



	int step_event=2*L_event;
	float dB_k_k_1=0;
	//	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
	//两个数据之间的时间间隔：
	//	double Sample_time=Sample_freaq;//放大了10^6倍
	//	Sample_time=1/Sample_time;




	float return_loss=0;

	////////////////////////////////////////////
	int* input_data_buff=new int[paramLen];//短时傅里叶变化结果Cn
	memset(input_data_buff,0,paramLen*sizeof(int));

	if(sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]<insertNum)//尾端插入事件
	{
		//if(insertNum>=paramLen)return sGabor_Result;//插入的事件点超过了所有的数据
		sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=insertNum;
		//判断插入事件类型
		int up_limit=0;
		int low_limit=0;
		double line_a=0;
		double line_b=0;
		double line_c=0;
		double line_d=0;
		int insertMaxIndex=0;
		int insertMinIndex=0;
		double insertMax=0;
		double insertMin=65535;
		double input_data_buff_statick=0;
		low_limit=insertNum-L_event/4;
		up_limit=insertNum+L_event/2;
		if(low_limit<4) low_limit=4;






		// 阮志光版本
		//寻找插入点后面的趋势
		for(k=low_limit;k<up_limit;k++)
		{
			input_data_buff_statick=65535-input_data[k];
			if(input_data_buff_statick<insertMin)
			{
				insertMin=input_data_buff_statick;
				insertMinIndex=k;
			}
			if(input_data_buff_statick>insertMax)
			{
				insertMax=input_data_buff_statick;
				insertMaxIndex=k;
			}
		}
		if(insertMinIndex<=insertNum&&insertMaxIndex>=insertNum)//反射事件
		{
			sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]=1;

		}
		else if(insertMinIndex<=insertNum&&insertMaxIndex<insertNum)
		{
			if(insertMinIndex<insertMaxIndex)//衰减事件
			{
				sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]=0;
			}
			else if(insertMaxIndex<insertMinIndex)//反射事件
			{
				sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]=1;
			}
		}
		else if(insertMinIndex>insertNum&&insertMaxIndex>insertNum)
		{
			if(insertMin<=insertMaxIndex)//衰减事件
			{
				sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]=1;
			}
			else 
			{
				sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]=0;
			}
		}
		sGabor_Result.Event_type[sGabor_Result.Valid_Num-1]='A';

	}
	else// 中间插入事件
	{
		int Insert_event_no=0;
		for(i=0;i<sGabor_Result.Valid_Num;i++)
		{
			if(insertNum<sGabor_Result.Event_Array[i])
			{
				Insert_event_no=i;

				for(j=sGabor_Result.Valid_Num;j>Insert_event_no-1;j--)
				{
					sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[j-1];
					sGabor_Result.Total_Loss[j]=sGabor_Result.Total_Loss[j-1];
					sGabor_Result.Event_Hight[j]=sGabor_Result.Event_Hight[j-1];
					sGabor_Result.Event_Loss[j]=sGabor_Result.Event_Loss[j-1];
					sGabor_Result.Event_type[j]=sGabor_Result.Event_type[j-1];
					sGabor_Result.Line_k[j]=sGabor_Result.Line_k[j-1];
					sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[j-1];

				}
				sGabor_Result.Event_Array[i]=insertNum;
				sGabor_Result.Total_Loss[i]=0;
				sGabor_Result.Event_Hight[i]=0;
				sGabor_Result.Event_Loss[i]=0;
				sGabor_Result.Event_type[i]='A';
				sGabor_Result.Line_k[i]=0;
				break;
			}
		}
		sGabor_Result.Valid_Num++;

		//判断插入事件类型
		int up_limit=0;
		int low_limit=0;
		double line_a=0;
		double line_b=0;
		double line_c=0;
		double line_d=0;
		int insertMaxIndex=0;
		int insertMinIndex=0;
		double insertMax=0;
		double insertMin=65535;
		double input_data_buff_statick=0;
		low_limit=insertNum-L_event/4;
		up_limit=insertNum+L_event/2;
		if(low_limit<4) low_limit=4;






		// 阮志光版本
		//寻找插入点后面的趋势
		for(k=low_limit;k<up_limit;k++)
		{
			input_data_buff_statick=65535-input_data[k];
			if(input_data_buff_statick<insertMin)
			{
				insertMin=input_data_buff_statick;
				insertMinIndex=k;
			}
			if(input_data_buff_statick>insertMax)
			{
				insertMax=input_data_buff_statick;
				insertMaxIndex=k;
			}
		}
		if(insertMinIndex<=insertNum&&insertMaxIndex>=insertNum)//反射事件
		{
			//sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num-1]=1;
			sGabor_Result.Reflect_Type[Insert_event_no]=1;

		}
		else if(insertMinIndex<=insertNum&&insertMaxIndex<insertNum)
		{
			if(insertMinIndex<insertMaxIndex)//衰减事件
			{
				sGabor_Result.Reflect_Type[Insert_event_no]=0;
			}
			else if(insertMaxIndex<insertMinIndex)//反射事件
			{
				sGabor_Result.Reflect_Type[Insert_event_no]=1;
			}
		}
		else if(insertMinIndex>insertNum&&insertMaxIndex>insertNum)
		{
			if(insertMin<=insertMaxIndex)//衰减事件
			{
				sGabor_Result.Reflect_Type[Insert_event_no]=1;
			}
			else 
			{
				sGabor_Result.Reflect_Type[Insert_event_no]=0;
			}
		}




	}


	//sGabor_Result=K_Line_count(L_event,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);////////////////////
	//sGabor_Result=K_Line_count(lEvent,wavelength,pulseWidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
	K_Line_count(L_event,wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);//wcq
	sGabor_Result.Event_Loss[sGabor_Result.Valid_Num-1]=0;
	//sGabor_Result=Acount_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);
	//sGabor_Result=Acount_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
	Acount_Loss(wavelength,pulsewidth,input_data,paramLen,&sGabor_Result,Index_N,Sample_freaq);//wcq
	//sGabor_Result=Acount_return_loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);//改为下面的wcq
	Acount_return_loss(wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);//wcq
	//sGabor_Result=Acount_Total_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
	Acount_Total_Loss(wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
	//sGabor_Result=K_Line_limite(wavelength,sGabor_Result);//改为下面的wcq
	K_Line_limite(wavelength,&sGabor_Result);
	return sGabor_Result;
}

//******************************************************************//
//     删除事件
//     deleteNum:所删除事件点序号
//     wavelength:曲线波长
//     pulsewidth：曲线脉宽
//     input_data[]：分析的原始数据
//******************************************************************//
Gabor_Result deleteEvent(int deleteNum,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe)
{
	int i=0;
	i=sGabor_Result.Valid_Num;
	int pulseNum=0;
	int L_event=200;
	switch(pulsewidth)
	{
	case 3:
		pulseNum=0;
		break;
	case 5:
		pulseNum=1;
		break;
	case 10:
		pulseNum=2;
		break;
	case 20:
		pulseNum=3;
		break;
	case 50:
		pulseNum=4;
		break;
	case 100:
		pulseNum=5;
		break;
	case 200:
		pulseNum=6;
		break;
	case 500:
		pulseNum=7;	
		break;
	case 1000:
		pulseNum=8;
		break;
	case 2000:
		pulseNum=9;
		break;
	case 5000:
		pulseNum=10;
		break;
	case 10000:
		pulseNum=11;
		break;
	case 20000:
		pulseNum=12;
		break;
	case 30:
		pulseNum=13;
		break;
	case 300:
		pulseNum=14;
		break;
	case 400:
		pulseNum=15;
		break;
	default:pulseNum=12;break;
	}
	L_event=lEventGenerate(pulseNum,wavelength,Sample_freaq);




	//先求各段光纤的斜率：只要计算删除点所在点的下一个点的特性
	//	int up_limit,low_limit;
	int step_event=L_event*2;
	if(step_event<20)step_event=20;
	//float* sum_k=new float[2000];//短时傅里叶变化结果Cn
	//memset(sum_k,0,2000*sizeof(float));
	//double sum_k[20];
	double dB_k_k_1=0;

	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
	//两个数据之间的时间间隔：
	double Sample_time=Sample_freaq;//放大了10^6倍
	Sample_time=1/Sample_time;
	//测量距离计算
	int Reflex_Event_start_mark_cn=sGabor_Result.Event_Array[0];


	int j=0,k=0;
	j=sGabor_Result.Valid_Num;
	k=0;
	if(deleteNum==0||deleteNum>=sGabor_Result.Valid_Num)return sGabor_Result;
	for(i=0;i<j;i++)
	{
		if(i==deleteNum)
			continue;
		else
		{
			sGabor_Result.Event_Array[k]=sGabor_Result.Event_Array[i];
			sGabor_Result.Event_Loss[k]=sGabor_Result.Event_Loss[i];
			sGabor_Result.Total_Loss[k]=sGabor_Result.Total_Loss[i];
			sGabor_Result.Event_type[k]=sGabor_Result.Event_type[i];
			sGabor_Result.Event_Hight[k]=sGabor_Result.Event_Hight[i];
			sGabor_Result.Reflect_Type[k]=sGabor_Result.Reflect_Type[i];
			k++;

		}
	}
	sGabor_Result.Valid_Num=k;
	//if(sGabor_Result.Valid_Num)sGabor_Result.Valid_Num--;
	sGabor_Result.Line_k[0]=0;

	//sGabor_Result=K_Line_count(L_event,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);////////////////////
	//sGabor_Result=K_Line_count(L_event,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
	K_Line_count(L_event,wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);//wcq
	//sGabor_Result=Acount_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);
	//sGabor_Result=Acount_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
//	Acount_Loss(wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);//wcq
	sGabor_Result.Event_Loss[sGabor_Result.Valid_Num-1]=0;
	//sGabor_Result=Acount_return_loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);//改为下面的wcq
	Acount_return_loss(wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);//wcq
	//sGabor_Result=Acount_Total_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
	Acount_Total_Loss(wavelength,pulsewidth,input_data,&sGabor_Result,Index_N,Sample_freaq);
	//sGabor_Result=K_Line_limite(wavelength,sGabor_Result);//改为下面的wcq
	K_Line_limite(wavelength,&sGabor_Result);

	return sGabor_Result;
}

void deleteEvent_New(int deleteNum,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe)
{
	int i=0;
	i=sGabor_Result->Valid_Num;
	int pulseNum=0;
	int L_event=200;
	switch(pulsewidth)
	{
	case 3:
		pulseNum=0;
		break;
	case 5:
		pulseNum=1;
		break;
	case 10:
		pulseNum=2;
		break;
	case 20:
		pulseNum=3;
		break;
	case 50:
		pulseNum=4;
		break;
	case 100:
		pulseNum=5;
		break;
	case 200:
		pulseNum=6;
		break;
	case 500:
		pulseNum=7;	
		break;
	case 1000:
		pulseNum=8;
		break;
	case 2000:
		pulseNum=9;
		break;
	case 5000:
		pulseNum=10;
		break;
	case 10000:
		pulseNum=11;
		break;
	case 20000:
		pulseNum=12;
		break;
	case 30:
		pulseNum=13;
		break;
	case 300:
		pulseNum=14;
		break;
	case 400:
		pulseNum=15;
		break;
	default:pulseNum=12;break;
	}
	L_event=lEventGenerate(pulseNum,wavelength,Sample_freaq);




	//先求各段光纤的斜率：只要计算删除点所在点的下一个点的特性
	//	int up_limit,low_limit;
	int step_event=L_event*2;
	if(step_event<20)step_event=20;
	//float* sum_k=new float[2000];//短时傅里叶变化结果Cn
	//memset(sum_k,0,2000*sizeof(float));
	//double sum_k[20];
	double dB_k_k_1=0;

	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
	//两个数据之间的时间间隔：
	double Sample_time=Sample_freaq;//放大了10^6倍
	Sample_time=1/Sample_time;
	//测量距离计算
	int Reflex_Event_start_mark_cn=sGabor_Result->Event_Array[0];


	int j=0,k=0;
	j=sGabor_Result->Valid_Num;
	k=0;
	if(deleteNum==0)//||deleteNum>=sGabor_Result->Valid_Num)
	{
		//return sGabor_Result;
		return ;
	}
	for(i=0;i<j;i++)
	{
		if(i==deleteNum)
			continue;
		else
		{
			sGabor_Result->Event_Array[k]=sGabor_Result->Event_Array[i];
			sGabor_Result->Event_Loss[k]=sGabor_Result->Event_Loss[i];
			sGabor_Result->Total_Loss[k]=sGabor_Result->Total_Loss[i];
			sGabor_Result->Event_type[k]=sGabor_Result->Event_type[i];
			sGabor_Result->Event_Hight[k]=sGabor_Result->Event_Hight[i];
			sGabor_Result->Reflect_Type[k]=sGabor_Result->Reflect_Type[i];
			k++;

		}
	}
	sGabor_Result->Valid_Num=k;
	//if(sGabor_Result->Valid_Num)sGabor_Result->Valid_Num--;
	sGabor_Result->Line_k[0]=0;

	//sGabor_Result=K_Line_count(L_event,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);////////////////////
	//sGabor_Result=K_Line_count(L_event,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
	K_Line_count(L_event,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//wcq
	//sGabor_Result=Acount_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);
	//sGabor_Result=Acount_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
//	Acount_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//wcq
	sGabor_Result->Event_Loss[sGabor_Result->Valid_Num-1]=0;
	//sGabor_Result=Acount_return_loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);//改为下面的wcq
	Acount_return_loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq,Return_loss_Tybe);//wcq
	//sGabor_Result=Acount_Total_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);//改为下面的wcq
	Acount_Total_Loss(wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq);
	//sGabor_Result=K_Line_limite(wavelength,sGabor_Result);//改为下面的wcq
	K_Line_limite(wavelength,sGabor_Result);

	//return sGabor_Result;
}

//用于光纤光栅的事件分析，将每一个事件的位置定位为顶峰
Gabor_Result Optical_grating(int wavelength,int pulsewidth,WORD input_data[],INT paramLen,Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float dB_reflex)
{
	int Reflex_Event_start=sGabor_Result.Event_Array[0];
	int Reflex_Event_end=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1];
	int i=0,j=0;
//	int Event_Array[200]; 
	int step_point=20;
	int up_time=0,down_time=0;
	int data_buff=0;
	long sum_data=0;
	int data_max=0;
	int data_min=0;
	int data_max_no=0,data_min_no=0;
	int data_avg=0;
	int* input_data_buff=new int[paramLen];//短时傅里叶变化结果Cn
	memset(input_data_buff,0,paramLen*sizeof(int));
	int DB_reflex_door=dB_reflex*1000;

	for(i=Reflex_Event_start;i<Reflex_Event_end;)//找到所有的上升沿
	{
		//取一段，求平均值
		sum_data=0;
		data_min=65535;
		data_min_no=i;
		data_max=0;
		data_max_no=i;
		//求段和
		for(j=i;j<i+step_point;j++)
		{
			data_buff=65535-input_data[j];
			sum_data=sum_data+data_buff;
			if(data_max<=data_buff)
			{
				data_max=data_buff;
				data_max_no=j;
			}
			if(data_min>=data_buff)
			{
				data_min=data_buff;
				data_min_no=j;
			}
		}
		//求段平均值
		data_avg=sum_data/step_point;
		//求段高于平均值+阈值的位置
		for(j=i;j<i+step_point;j++)
		{
			data_buff=65535-input_data[j];
			if(data_buff>data_avg+DB_reflex_door)
			{
				input_data_buff[j]=data_buff;
			}
			else input_data_buff[j]=0;
		}
		i=i+step_point;
	}


	sGabor_Result.Valid_Num=1;
	for(i=Reflex_Event_start;i<Reflex_Event_end;i++)
	{
		if(input_data_buff[i]!=0)
		{
			up_time++;
			if(up_time==5)
			{
				if(sGabor_Result.Valid_Num<99)
				{
					if(i-5>=Reflex_Event_start+step_point/2)
						sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=i-5;
				}

			}
		}
		if(input_data_buff[i]==0)
		{
			down_time++;
			if(up_time)
			{
				if(down_time>=3)up_time=0;
			}
			else 
			{
				down_time=0;
				up_time=0;
			}
		}
	}
	//将事件下标移到反射峰最高点
	for(i=0;i<sGabor_Result.Valid_Num;i++)
	{
		/*data_max=0;
		data_max_no=0;
		for(j=sGabor_Result.Event_Array[i];j<sGabor_Result.Event_Array[i]+step_point;j++)
		{
		if(data_max<input_data_buff[j])
		{
		data_max=input_data_buff[j];
		data_max_no=j;
		}
		}
		sGabor_Result.Event_Array[i]=data_max_no;*/
		sGabor_Result.Event_type[i]='F';
		sGabor_Result.Reflect_Type[i]=1;
		sGabor_Result.Total_Loss[i]=0;
		sGabor_Result.Event_Loss[i]=0;
		sGabor_Result.Event_Hight[i]=0;
	}
	sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=Reflex_Event_end;
	sGabor_Result.Event_type[sGabor_Result.Valid_Num]='F';
	sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=1;
	sGabor_Result.Total_Loss[sGabor_Result.Valid_Num]=0;
	sGabor_Result.Event_Loss[sGabor_Result.Valid_Num]=0;
	sGabor_Result.Event_Hight[sGabor_Result.Valid_Num++]=0;
	delete[]input_data_buff;
	return sGabor_Result;

}

void Acount_Loss(int wavelength,int pulsewidth,WORD input_data[],INT paramLen,Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq)
{
	int i=0,k=0;
	int flag=0;



	/*for(i=0;i<sGabor_Result->Valid_Num;i++)
	{
		sGabor_Result->Event_Loss[i]=input_data[sGabor_Result->Event_Array_End[i]]-input_data[sGabor_Result->Event_Array[i]];
	}*/
	int up_limit=0,low_limit=0;
	//float dB_k_line=0,Reflex_avg_dB=0,dB_Hight=0;

	double dB_Hight=0;
	double dB_Low=0;
	double dB_k_line=0;
	int max_data_no=0;
	int min_data_no=0;
	float max_data=0;
	float min_data=0;
	double Reflex_avg_dB=0;

    int L_event=200;
	int step_event=0;

	//int pulseNum=0;
	//
	//
	//switch(pulsewidth)
	//{
	//case 3:
	//	pulseNum=0;
	//	break;
	//case 5:
	//	pulseNum=1;
	//	break;
	//case 10:
	//	pulseNum=2;
	//	break;
	//case 20:
	//	pulseNum=3;
	//	break;
	//case 50:
	//	pulseNum=4;
	//	break;
	//case 100:
	//	pulseNum=5;
	//	break;
	//case 200:
	//	pulseNum=6;
	//	break;
	//case 500:
	//	pulseNum=7;	
	//	break;
	//case 1000:
	//	pulseNum=8;
	//	break;
	//case 2000:
	//	pulseNum=9;
	//	break;
	//case 5000:
	//	pulseNum=10;
	//	break;
	//case 10000:
	//	pulseNum=11;
	//	break;
	//case 20000:
	//	pulseNum=12;
	//	break;
	//case 30:
	//	pulseNum=13;
	//	break;
	//case 300:
	//	pulseNum=14;
	//	break;
	//case 400:
	//	pulseNum=15;
	//	break;
	//default:pulseNum=12;break;
	//}
	//L_event=lEventGenerate(pulseNum,wavelength,Sample_freaq);
	//step_event=L_event*2;
	//if(step_event<=20)step_event=20;


	//if(pulsewidth>=2000)/////////////////////////////////////////20130615
	//	//step_event=2*pulsewidth/40*(Sample_freaq/25);
	//	step_event=L_event*3;
	
	L_event=Step_point_count(pulsewidth,wavelength,Sample_freaq);
	//if(Sample_freaq<=50)L_event=2*L_event;
	//if(pulsewidth>=100&&pulsewidth<=500)L_event=L_event*4;
	L_event=2*L_event;
	step_event=3*L_event/2;

	//光在光纤中传播的速度
	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
	//两个数据之间的时间间隔：
	double Sample_time=Sample_freaq;//放大了10^6倍
	Sample_time=1/Sample_time;
	//测量距离计算
	//  double Measure_distacne = Light_fiber_speed*Sample_time*paramLen;


	if(sGabor_Result->Valid_Num>1)
	{
		for(i=0;i<sGabor_Result->Valid_Num;i++)
		{
			if(sGabor_Result->Reflect_Type[i])//反射事件
			{
				//算反射高度
				step_event=7*L_event/2;
				if(input_data[sGabor_Result->Event_Array[i]]>input_data[sGabor_Result->Event_Array[i]+step_event])
				{
					step_event=8*L_event/2;

					if(input_data[sGabor_Result->Event_Array[i]]>input_data[sGabor_Result->Event_Array[i]+step_event])
						step_event=9*L_event/2;
				}
				
				if(i==0)
				{
					sGabor_Result->Reflect_Type[i]=1;
					continue;
				}
				if((step_event/15)>4)
					up_limit=sGabor_Result->Event_Array[i]-step_event/15;
				else up_limit=sGabor_Result->Event_Array[i]-4;

				if(up_limit<sGabor_Result->Event_Array[i-1])up_limit=sGabor_Result->Event_Array[i-1];//sGabor_Result->Event_Array[i]+2;
				//if(up_limit<=0)up_limit=3;
				low_limit=sGabor_Result->Event_Array[i]+step_event/2;
				if(i<sGabor_Result->Valid_Num-1)
				{
					if(low_limit>sGabor_Result->Event_Array[i+1]&&(sGabor_Result->Event_Array[i+1]-sGabor_Result->Event_Array[i])>20)
						low_limit=sGabor_Result->Event_Array[i+1]-step_event/10;
					if(low_limit<sGabor_Result->Event_Array[i]+5)low_limit=sGabor_Result->Event_Array[i+1]-2;
				}

				max_data=0;
				min_data=65535;
				for(k=up_limit;k<low_limit;k++)
				{
					if((max_data)<65535-input_data[k])
					{
						max_data=65535-input_data[k];
						max_data_no=k;
					}
					if((min_data)>65535-input_data[k])
					{
						min_data=65535-input_data[k];
						min_data_no=k;
					}
				}
				if(min_data_no>max_data_no)
				{
					//max_data=0;
					min_data=65535;
					for(k=up_limit;k<max_data_no;k++)
					{
						if(min_data>(65535-input_data[k]))
						{
							min_data=65535-input_data[k];
							min_data_no=k;
						}
					}
				}
				if(min_data_no>50)//对最小值做平均处理，消除噪声影响
				{
					Reflex_avg_dB=0;
					for(k=0;k<5;k++)
					{
						if(min_data_no-k>=0)
							Reflex_avg_dB=Reflex_avg_dB+65535-input_data[min_data_no-k];
					}
					Reflex_avg_dB=Reflex_avg_dB/5;
					min_data=Reflex_avg_dB;
				}

				sGabor_Result->Event_Hight[i]=(max_data-min_data)/1000.0;

				//前一个事件也为反射事件，判断两个反射事件的距离是否满足1个波长的距离，如果满足就计算损耗，不满足就
				//不计算损耗
				if(sGabor_Result->Reflect_Type[i-1]||i==1)
				{
					if((sGabor_Result->Event_Array[i-1]+3*step_event/2)>sGabor_Result->Event_Array[i])
					{
						sGabor_Result->Event_Loss[i]=0;
						//		continue;
					}
				}

				if(sGabor_Result->Event_Hight[i]>=5&&Sample_freaq<=50&&pulsewidth<=500)
				{
					step_event=step_event*5;
					//if(sGabor_Result->Event_Hight[i]>=10)step_event=step_event*5;
			    }
				//算回波损耗



			}
			//else 
			//{
			//	step_event=3*L_event/2;
			//	if(L_event<=8)step_event=5*step_event;
			//	//step_event=Event_Array_End[i]-sGabor_Result->Event_Array[i];
			//}

		
			//else//衰减事件  插入损耗计算/////////该段代码决定最终损耗的准确性
			{
				/*if(i==sGabor_Result->Valid_Num-1)
				{
				sGabor_Result->Event_Loss[i]=0;
				break;
				}*/
				/*if(sGabor_Result->Line_k[i]>0)dB_k_line=sGabor_Result->Line_k[i];
				else if(sGabor_Result->Line_k[i+1]>0)
				{
				dB_k_line=sGabor_Result->Line_k[i+1];
				}
				else*/
				dB_k_line=Avg_loss_wave_lenght_count(wavelength);
				if(i!=0)
				{

					int avg_up=0,avg_low=0;
					float nutrue_loss=0;
					flag=0;
					up_limit=sGabor_Result->Event_Array[i]-step_event/8;
					if(up_limit<=3)up_limit=3;
					avg_up=input_data[up_limit-3]+input_data[up_limit-2]+input_data[up_limit-1]+input_data[up_limit]+input_data[up_limit+1]+input_data[up_limit+2]+input_data[up_limit+3];
					avg_up=avg_up/7;
					low_limit=sGabor_Result->Event_Array[i]+step_event;
					if(i<sGabor_Result->Valid_Num-1)
					{
						if(low_limit>sGabor_Result->Event_Array[i+1])
						{
							low_limit=sGabor_Result->Event_Array[i+1]-10;
							//sGabor_Result->Event_Loss[i]=0;
							//continue;
							flag=1;
						}
					}
					if(low_limit<=3)low_limit=3;

					avg_low=input_data[low_limit-3]+input_data[low_limit-2]+input_data[low_limit-1]+input_data[low_limit]+input_data[low_limit+1]+input_data[low_limit+2]+input_data[low_limit+3];
					avg_low=avg_low/7;
					dB_Hight=avg_up -avg_low ;
					//if(sGabor_Result->Reflect_Type[i]==0)/////////////////////////20130617
					//dB_Hight=dB_Hight/1000+(low_limit-up_limit+3)*(Sample_time*Light_fiber_speed)/2000*dB_k_line;
					//else dB_Hight=dB_Hight/1000;
					dB_Hight=dB_Hight/1000;
					nutrue_loss=(low_limit-up_limit+3)*(Sample_time*Light_fiber_speed)/2000*dB_k_line;
					if(dB_Hight>=0)
					{
						if(sGabor_Result->Reflect_Type[i]!=0)
						{
							dB_Hight=dB_Hight+nutrue_loss;
						}
						else
						{
							dB_Hight=0;
						}

						
					}
					else dB_Hight=dB_Hight+nutrue_loss;
					

				    


					sGabor_Result->Event_Loss[i]=-(dB_Hight);
					if(fabs(sGabor_Result->Event_Loss[i])<=0.005)
						sGabor_Result->Event_Loss[i]=0;
					if(sGabor_Result->Reflect_Type[i])
					{
						if(fabs(sGabor_Result->Event_Loss[i])<=0.005)sGabor_Result->Event_Loss[i]=0;
					}
					if(sGabor_Result->Event_Loss[i]<0)
					{
						if(flag)sGabor_Result->Event_Loss[i]=0;
						else if(sGabor_Result->Event_Loss[i]<-1)sGabor_Result->Event_Loss[i]=0;
					}
					//算插入损耗	
				}
				else
				{
					sGabor_Result->Event_Loss[i]=0;
				}

			} 

		}
	}
	if(sGabor_Result->Valid_Num)sGabor_Result->Event_Loss[sGabor_Result->Valid_Num-1]=0;
	//return sGabor_Result;

}
void Acount_return_loss1(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe)
{
	//int i=0;
	//float return_tybe=0;
	//float return_loss=0;
	//float Pulse_width_status=0;
	//if(pulsewidth==3)Pulse_width_status=5;
	//else if(pulsewidth==5)Pulse_width_status=7.5;
	//else Pulse_width_status=pulsewidth;
	//for(i=0;i<sGabor_Result->Valid_Num;i++)
	//{
	//	if(i>0)
	//	{
	//		//sumTotalLoss=sumTotalLoss+sGabor_Result->Line_k[i]/1000*(sGabor_Result->Event_Array[i]-sGabor_Result->Event_Array[i-1])+sGabor_Result->Event_Loss[i];
	//		//sGabor_Result->Total_Loss[i]=sumTotalLoss;
	//		if(sGabor_Result->Reflect_Type[i])//如果为反射事件，求回波损耗
	//		{

	//			if(wavelength==1310)return_tybe=Return_loss_1310_tybe;
	//			else if(wavelength==1490)return_tybe=Return_loss_1490_tybe;
	//			else if(wavelength==1550)return_tybe=Return_loss_1550_tybe;
	//			else if(wavelength==1625)return_tybe=Return_loss_1625_tybe;
	//			else if(wavelength==1300)return_tybe=Return_loss_1300_tybe;
	//			else if(wavelength==850)return_tybe=Return_loss_850_tybe;

	//			return_loss=sGabor_Result->Event_Hight[i]/5;
	//			return_loss=pow(10,return_loss)-1;
	//			sGabor_Result->Event_Hight[i]=(10*log10(Pulse_width_status/1000000000.0));
	//			//if(wavelength==1550)
	//			//sGabor_Result->Event_Hight[i]=sGabor_Result->Event_Hight[i]+10*log10(return_loss)+(-70-Return_loss_Tybe);//-(sGabor_Result->Event_Hight[i]+10*log10(return_loss))+(Return_loss_Tybe)+70;//
	//			//else sGabor_Result->Event_Hight[i]=sGabor_Result->Event_Hight[i]+10*log10(return_loss)+10.5;
	//			if(return_loss>0)
	//				sGabor_Result->Event_Hight[i]=-(sGabor_Result->Event_Hight[i]+10*log10(return_loss))-(return_tybe+Return_loss_Tybe);
	//			else sGabor_Result->Event_Hight[i]=70;
	//			if((sGabor_Result->Event_Hight[i])<=12.0)sGabor_Result->Event_Hight[i]=0;
	//			else if((sGabor_Result->Event_Hight[i])>=70.0)sGabor_Result->Event_Hight[i]=70;
	//		}

	//		else sGabor_Result->Event_Hight[i]=0;
	//		//sGabor_Result->Event_Hight[i]=2*sGabor_Result->Event_Hight[i];
	//	}
	//}
	////return sGabor_Result;
	int i=0,j=0,m=0,n=0;
	float FHO5000_Hight=0;
	float FTB200_Hight=0;
	float DETA_Higth=0;
	float DETA_dB_k_FHO5000=0;
	float DETA_dB_k_FTB200=0;
	float Wave_return_loss=0;
	float RdB=0;
	float H_k=0;//反射峰饱和修正系数
	int step_point=0;
	step_point=Step_point_count(pulsewidth,wavelength,Sample_freaq);
	//if(Return_loss_Tybe==0)Return_loss_Tybe=52;
	switch(wavelength)
	{
	case 850:
		Wave_return_loss=Return_loss_850_tybe;
		break;
	case 1300:
		Wave_return_loss=Return_loss_1300_tybe;
		break;
	case 1310:
		Wave_return_loss=Return_loss_1310_tybe;
		break;
	case 1490:
		Wave_return_loss=Return_loss_1490_tybe;
		break;
	case 1550:
		Wave_return_loss=Return_loss_1550_tybe;
		break;
	case 1625:
		Wave_return_loss=Return_loss_1625_tybe;
		break;
	case 1650:
		Wave_return_loss=Return_loss_1650_tybe;
		break;
	default:
		Wave_return_loss=Return_loss_1550_tybe;
		break;
	}
#if 0
	if(wavelength>=1490)
	{

		switch(pulsewidth)
		{
		case 3:
			FHO5000_Hight=18.3;
			FTB200_Hight=-15.7;
			break;
		case 5:
			FHO5000_Hight=16.6;
			FTB200_Hight=-15.8;
			break;
		case 10:
			FHO5000_Hight=16.1;
			FTB200_Hight=-17;
			break;
		case 20:
			FHO5000_Hight=14.5;
			FTB200_Hight=-17.8;
			break;
		case 50:
			FHO5000_Hight=12.95;
			FTB200_Hight=-15;
			break;
		case 100:
			FHO5000_Hight=11.45;
			FTB200_Hight=-13.5;
			break;
		case 200:
			FHO5000_Hight=14.80;
			FTB200_Hight=-13.5;
			break;
		case 500:
			FHO5000_Hight=10.53;
			FTB200_Hight=-13.5;
			break;
		case 1000:
			FHO5000_Hight=9.14;
			FTB200_Hight=-13.6;
			break;
		case 2000:
			FHO5000_Hight=5.98;
			FTB200_Hight=-13.6;
			break;
		case 5000:
			FHO5000_Hight=12.78;
			FTB200_Hight=-13.6;
			break;
		case 10000:
			FHO5000_Hight=4.8;
			FTB200_Hight=-18.1;
			break;
		case 20000:
			FHO5000_Hight=4.8;
			FTB200_Hight=-18.4;
			break;
		default:
			FHO5000_Hight=11.45;
			FTB200_Hight=-13.5;
			break;
		}

	}
	else
	{
			switch(pulsewidth)
			{
			case 3:
				FHO5000_Hight=17.2;
				FTB200_Hight=-17.0;
				break;
			case 5:
				FHO5000_Hight=15.35;
				FTB200_Hight=-15.0;
				break;
			case 10:
				FHO5000_Hight=14.44;
				FTB200_Hight=-16.4;
				break;
			case 20:
				FHO5000_Hight=12.91;
				FTB200_Hight=-17.3;
				break;
			case 50:
				FHO5000_Hight=11.95;
				FTB200_Hight=-15;
				break;
			case 100:
				FHO5000_Hight=13.85;
				FTB200_Hight=-14.6;
				break;
			case 200:
				FHO5000_Hight=17.0;
				FTB200_Hight=-14.6;
				break;
			case 500:
				FHO5000_Hight=16.35;
				FTB200_Hight=-15.5;
				break;
			case 1000:
				FHO5000_Hight=15.0;
				FTB200_Hight=-14.6;
				break;
			case 2000:
				FHO5000_Hight=12.04;
				FTB200_Hight=-14.7;
				break;
			case 5000:
				FHO5000_Hight=12.04;
				FTB200_Hight=-14.7;
				break;
			case 10000:
				FHO5000_Hight=12.04;
				FTB200_Hight=-14.7;
				break;
			case 20000:
				FHO5000_Hight=12.04;
				FTB200_Hight=-14.7;
				break;
			default:
				FHO5000_Hight=12.04;
				FTB200_Hight=-14.7;
				break;
		   }
	}
		
		//DETA_dB_k_FHO5000=(52+FTB200_Hight)/FHO5000_Hight;
		DETA_dB_k_FHO5000=(FTB200_Hight+52)/FHO5000_Hight;

	for(i=1;i<sGabor_Result->Valid_Num;i++)
	{
		if(sGabor_Result->Reflect_Type[i]==1)
		{
			//DETA_Higth=(52-sGabor_Result->Event_Hight[i]*DETA_dB_k_FHO5000);
			//sGabor_Result->Event_Hight[i]=-DETA_Higth;

			//DETA_Higth=sGabor_Result->Event_Hight[i]-FHO5000_Hight;
			//if(fabs(FHO5000_Hight/FTB200_Hight)>1)
			//sGabor_Result->Event_Hight[i]=FTB200_Hight-2*DETA_Higth/(FHO5000_Hight/FTB200_Hight);
			//else sGabor_Result->Event_Hight[i]=FTB200_Hight-2*DETA_Higth;
			//if(sGabor_Result->Event_Hight[i]>-13)sGabor_Result->Event_Hight[i]=sGabor_Result->Event_Hight[i]-DETA_Higth;
			////sGabor_Result->Event_Hight[i]=DETA_Higth;

			if(sGabor_Result->Event_Hight[i]>FHO5000_Hight)
			{
			   sGabor_Result->Event_Hight[i]=FTB200_Hight+(sGabor_Result->Event_Hight[i]-FHO5000_Hight)/4;
			}
			else 
			{
				DETA_Higth=sGabor_Result->Event_Hight[i]*DETA_dB_k_FHO5000;//对应到FTB200的反射高度

			  sGabor_Result->Event_Hight[i]=-52+DETA_Higth;
			}
			sGabor_Result->Event_Hight[i]=sGabor_Result->Event_Hight[i]+(Wave_return_loss+Return_loss_Tybe);



		}
	}
#endif
	int max_data=0,max_mark=0,left_data=0,left_mark=0,right_data=0,right_mark=0;
	//step_point=5;
	if(pulsewidth<=20)step_point=step_point/2;
	for(i=1;i<sGabor_Result->Valid_Num;i++)
	{
		if(sGabor_Result->Reflect_Type[i]==1)
		{
			//求出事件盲区
			max_data=65535-input_data[sGabor_Result->Event_Array[i]]+sGabor_Result->Event_Hight[i];
			for(j=sGabor_Result->Event_Array[i];j<sGabor_Result->Event_Array[i]+step_point;j++)
			{
				if(((input_data[sGabor_Result->Event_Array[i]]-input_data[j]))>7000*sGabor_Result->Event_Hight[i]/8)
				{
					left_mark=j;
					break;
				}
				else if(((input_data[sGabor_Result->Event_Array[i]]-input_data[j]))>1000*(sGabor_Result->Event_Hight[i]-0.5))
				{
					left_mark=j;
					break;
				}
			}
			m=0;
			for(j=left_mark;j<left_mark+5*step_point;j++)
			{
				if(65535-input_data[j]>=65535-input_data[sGabor_Result->Event_Array[i]]+sGabor_Result->Event_Hight[i]*1000-100)
					m=1;
				if(m==1)
				{
					if(((input_data[sGabor_Result->Event_Array[i]]-input_data[j]))<3000*sGabor_Result->Event_Hight[i]/4)
					{
						right_mark=j;
						break;
					}
					else if(((input_data[sGabor_Result->Event_Array[i]]-input_data[j]))<1000*(sGabor_Result->Event_Hight[i]-0.5))
					{
						right_mark=j;
						break;
					}
				}
			}
			if(right_mark-left_mark>step_point)
			{
				H_k=(right_mark-left_mark);
				H_k=H_k/step_point;
			}
			else H_k=1;

			RdB=Wave_return_loss+10*log10(float(pulsewidth))+10*log10(pow(10,H_k*sGabor_Result->Event_Hight[i]/5)-1);
			RdB=RdB+18;
			if(RdB>-15)RdB=-15;
			sGabor_Result->Event_Hight[i]=RdB;
		}
	}

}

void Acount_return_loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe)
{

	float Wave_return_loss=0;
	float BZ_Hight=0;
	float Max_Hight=0;
	float Min_Hight=0;

	float BZ_ORL=0;
	float Max_ORL=0;
	float Min_ORL=0;

	float ORL_com=0;
	float AVG_ORL=0;

	int data7788=0;
	int i=0;
	
	switch(wavelength)
	{
	case 850:
		Wave_return_loss=Return_loss_850_tybe;
		break;
	case 1300:
		Wave_return_loss=Return_loss_1300_tybe;
		break;
	case 1310:
		Wave_return_loss=Return_loss_1310_tybe;
		break;
	case 1490:
		Wave_return_loss=Return_loss_1490_tybe;
		break;
	case 1550:
		Wave_return_loss=Return_loss_1550_tybe;
		break;
	case 1625:
		Wave_return_loss=Return_loss_1625_tybe;
		break;
	case 1650:
		Wave_return_loss=Return_loss_1650_tybe;
		break;
	default:
		Wave_return_loss=Return_loss_1550_tybe;
		break;
	}
	if(wavelength>1550)
	{
		switch(pulsewidth)
		{
		case 3:
			BZ_Hight=10.81;
			Max_Hight=20.78;
			Min_Hight=3;

			BZ_ORL=-44.8;
			Max_ORL=-12.9;
			Min_ORL=-60;

			break;
		case 5:
			BZ_Hight=10.4;
			Max_Hight=19.67;
			Min_Hight=3;

			BZ_ORL=-45;
			Max_ORL=-13.6;
			Min_ORL=-60;

			break;
		case 10:
			BZ_Hight=10.52;
			Max_Hight=18.98;
			Min_Hight=3;

			BZ_ORL=-45;
			Max_ORL=-14.1;
			Min_ORL=-57;

			break;
		case 20:
			BZ_Hight=10.12;
			Max_Hight=18.23;
			Min_Hight=3;

			BZ_ORL=-45;
			Max_ORL=-14.1;
			Min_ORL=-55;

			break;
		case 50:
			BZ_Hight=8.4;
			Max_Hight=16.49;
			Min_Hight=1;

			BZ_ORL=-45;
			Max_ORL=-16.5;
			Min_ORL=-55;

			break;
		case 100:
			BZ_Hight=8.1;
			Max_Hight=16.49;
			Min_Hight=0.9;

			BZ_ORL=-42.5;
			Max_ORL=-17;
			Min_ORL=-55;

			break;
		case 200:
			BZ_Hight=7.6;
			Max_Hight=16.47;
			Min_Hight=0.8;

			BZ_ORL=-41.5;
			Max_ORL=-17.1;
			Min_ORL=-55;

			break;
		case 500:
			BZ_Hight=6.9;
			Max_Hight=16.49;
			Min_Hight=0.5;

			BZ_ORL=-41.2;
			Max_ORL=-17.1;
			Min_ORL=-55;

			break;
		case 1000:
			BZ_Hight=5.75;
			Max_Hight=16.32;
			Min_Hight=0.4;

			BZ_ORL=-41.2;
			Max_ORL=-17.1;
			Min_ORL=-55;

			break;
		case 2000:
			BZ_Hight=4.03;
			Max_Hight=14.07;
			Min_Hight=0.3;

			BZ_ORL=-41.2;
			Max_ORL=-17.1;
			Min_ORL=-55;

			break;
		case 5000:
			BZ_Hight=2.64;
			Max_Hight=12.28;
			Min_Hight=0.3;

			BZ_ORL=-41.2;
			Max_ORL=-17.1;
			Min_ORL=-55;

			break;
		case 10000:
			BZ_Hight=1.7;
			Max_Hight=11;
			Min_Hight=0.2;

			BZ_ORL=-41.2;
			Max_ORL=-17.1;
			Min_ORL=-55;

			break;
		default:
			BZ_Hight=0.5;
			Max_Hight=11;
			Min_Hight=0.2;

			BZ_ORL=-48;
			Max_ORL=-17;
			Min_ORL=-55;

			break;

		}
	}
else if(wavelength>=1490)
{
		switch(pulsewidth)
		{
		case 3:
			BZ_Hight=10.15;
			Max_Hight=18.98;
			Min_Hight=3;

			BZ_ORL=-45.4;
			Max_ORL=-14.6;
			Min_ORL=-60;

			break;
		case 5:
			BZ_Hight=10.11;
			Max_Hight=17.99;
			Min_Hight=3;

			BZ_ORL=-45.4;
			Max_ORL=-14.6;
			Min_ORL=-60;

			break;
		case 10:
			BZ_Hight=9.89;
			Max_Hight=17.49;
			Min_Hight=3;

			BZ_ORL=-45.6;
			Max_ORL=-14.6;
			Min_ORL=-57;

			break;
		case 20:
			BZ_Hight=9.66;
			Max_Hight=16.73;
			Min_Hight=3;

			BZ_ORL=-45.6;
			Max_ORL=-14.6;
			Min_ORL=-55;

			break;
		case 50:
			BZ_Hight=8.05;
			Max_Hight=16.47;
			Min_Hight=1;

			BZ_ORL=-45.6;
			Max_ORL=-16.5;
			Min_ORL=-55;

			break;
		case 100:
			BZ_Hight=5.44;
			Max_Hight=16.4;
			Min_Hight=0.9;

			BZ_ORL=-45.8;
			Max_ORL=-15.9;
			Min_ORL=-55;

			break;
		case 200:
			BZ_Hight=5.27;
			Max_Hight=16.44;
			Min_Hight=0.8;

			BZ_ORL=-45.4;
			Max_ORL=-15.9;
			Min_ORL=-55;

			break;
		case 500:
			BZ_Hight=4.42;
			Max_Hight=16.44;
			Min_Hight=0.5;

			BZ_ORL=-45.6;
			Max_ORL=-16;
			Min_ORL=-55;

			break;
		case 1000:
			BZ_Hight=3.42;
			Max_Hight=16.13;
			Min_Hight=0.4;

			BZ_ORL=-45.6;
			Max_ORL=-16;
			Min_ORL=-55;

			break;
		case 2000:
			BZ_Hight=1.79;
			Max_Hight=13.8;
			Min_Hight=0.3;

			BZ_ORL=-45.6;
			Max_ORL=-16;
			Min_ORL=-55;

			break;
		case 5000:
			BZ_Hight=1.16;
			Max_Hight=11.67;
			Min_Hight=0.3;

			BZ_ORL=-45.7;
			Max_ORL=-16.3;
			Min_ORL=-55;

			break;
		case 10000:
			BZ_Hight=0.63;
			Max_Hight=11;
			Min_Hight=0.2;

			BZ_ORL=-46.7;
			Max_ORL=-16.3;
			Min_ORL=-55;

			break;
		default:
			BZ_Hight=0.5;
			Max_Hight=11;
			Min_Hight=0.2;

			BZ_ORL=-48;
			Max_ORL=-17;
			Min_ORL=-55;

			break;
		  
		}
	}
else if(wavelength<=1310)
{
	switch(pulsewidth)
	{
	case 3:
		BZ_Hight=9.73;
		Max_Hight=17.61;
		Min_Hight=3;

		BZ_ORL=-44.3;
		Max_ORL=-14.6;
		Min_ORL=-60;

		break;
	case 5:
		BZ_Hight=9.65;
		Max_Hight=16.61;
		Min_Hight=3;

		BZ_ORL=-44.6;
		Max_ORL=-14.6;
		Min_ORL=-60;

		break;
	case 10:
		BZ_Hight=9.51;
		Max_Hight=16.47;
		Min_Hight=3;

		BZ_ORL=-44.6;
		Max_ORL=-14.6;
		Min_ORL=-57;

		break;
	case 20:
		BZ_Hight=9.26;
		Max_Hight=16.46;
		Min_Hight=3;

		BZ_ORL=-44.6;
		Max_ORL=-14.6;
		Min_ORL=-55;

		break;
	case 50:
		BZ_Hight=7.38;
		Max_Hight=16.48;
		Min_Hight=1;

		BZ_ORL=-44.6;
		Max_ORL=-14.6;
		Min_ORL=-55;

		break;
	case 100:
		BZ_Hight=3.51;
		Max_Hight=17.5;
		Min_Hight=0.9;

		BZ_ORL=-47.6;
		Max_ORL=-14.9;
		Min_ORL=-55;

		break;
	case 200:
		BZ_Hight=3.26;
		Max_Hight=16.55;
		Min_Hight=0.8;

		BZ_ORL=-47.4;
		Max_ORL=-14.9;
		Min_ORL=-55;

		break;
	case 500:
		BZ_Hight=2.48;
		Max_Hight=16.42;
		Min_Hight=0.5;

		BZ_ORL=-47.8;
		Max_ORL=-14.9;
		Min_ORL=-55;

		break;
	case 1000:
		BZ_Hight=1.62;
		Max_Hight=16.21;
		Min_Hight=0.4;

		BZ_ORL=-47.8;
		Max_ORL=-14.9;
		Min_ORL=-55;

		break;
	case 2000:
		BZ_Hight=0.62;
		Max_Hight=13.92;
		Min_Hight=0.3;

		BZ_ORL=-47.9;
		Max_ORL=-15;
		Min_ORL=-55;

		break;
	case 5000:
		BZ_Hight=0.4;
		Max_Hight=13.13;
		Min_Hight=0.3;

		BZ_ORL=-47.9;
		Max_ORL=-15;
		Min_ORL=-55;

		break;
	case 10000:
		BZ_Hight=0.21;
		Max_Hight=9.89;
		Min_Hight=0.2;

		BZ_ORL=-48.8;
		Max_ORL=-15;
		Min_ORL=-55;

		break;
	default:
		BZ_Hight=0.3;
		Max_Hight=9.6;
		Min_Hight=0.2;

		BZ_ORL=-46.6;
		Max_ORL=-15.6;
		Min_ORL=-55;

		break;

	}
}
	
	for(i=1;i<sGabor_Result->Valid_Num;i++)
	{
		if(sGabor_Result->Reflect_Type[i]==1)
		{
			ORL_com=sGabor_Result->Event_Hight[i];
			if(ORL_com<=Min_Hight)
			{
				sGabor_Result->Event_Hight[i]=Min_ORL;
				sGabor_Result->Event_Hight[i]=(int(sGabor_Result->Event_Hight[i]*10))/10-0.0777;

			}
			else if(ORL_com<=BZ_Hight&&ORL_com>=Min_Hight)
			{
				AVG_ORL=(BZ_ORL-Min_ORL)/(BZ_Hight-Min_Hight);
				sGabor_Result->Event_Hight[i]=BZ_ORL-fabs((BZ_Hight-ORL_com)*AVG_ORL);
				data7788=abs(((int(sGabor_Result->Event_Hight[i]*1000))))%100;
				if(data7788==77)
				{
					sGabor_Result->Event_Hight[i]=int(sGabor_Result->Event_Hight[i]*10)/10;
				}
				else if(data7788==88)
				{
					sGabor_Result->Event_Hight[i]=int(sGabor_Result->Event_Hight[i]*10)/10;
				}

			}
			else if(ORL_com>=BZ_Hight&&ORL_com<Max_Hight)
			{
				AVG_ORL=(Max_ORL-BZ_ORL)/(Max_Hight-BZ_Hight);
				sGabor_Result->Event_Hight[i]=BZ_ORL+fabs((ORL_com-BZ_Hight)*AVG_ORL);
				data7788=abs(((int(sGabor_Result->Event_Hight[i]*1000))))%100;
				if(data7788==77)
				{
					sGabor_Result->Event_Hight[i]=int(sGabor_Result->Event_Hight[i]*10)/10;
				}
				else if(data7788==88)
				{
					sGabor_Result->Event_Hight[i]=int(sGabor_Result->Event_Hight[i]*10)/10;
				}
			}
			else 
			{
				sGabor_Result->Event_Hight[i]=Max_ORL+fabs(ORL_com-Max_Hight);
				sGabor_Result->Event_Hight[i]=int(sGabor_Result->Event_Hight[i]*10)/10-0.08888;
			}
			sGabor_Result->Event_Hight[i]=sGabor_Result->Event_Hight[i]+(Return_loss_Tybe-Wave_return_loss);
			if(sGabor_Result->Event_Hight[i]>-14)sGabor_Result->Event_Hight[i]=-14.08888;

		}
	}

}


void Acount_Total_Loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq)
{
	float start_loss_dB=0;
	int Reflex_Event_start_mark_cn=sGabor_Result->Event_Array[0];

	//光在光纤中传播的速度
	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
	//两个数据之间的时间间隔：
	double Sample_time=Sample_freaq;//放大了10^6倍
	Sample_time=1/Sample_time;

	int i=0,j=0;
	/////////////////////////////////////////////////////////////////////////////////
	//	int pulseNum=0;
	//	switch(pulsewidth)
	//	{
	//	case 3:
	//		pulseNum=0;
	//		break;
	//	case 5:
	//		pulseNum=1;
	//		break;
	//	case 10:
	//		pulseNum=2;
	//		break;
	//	case 20:
	//		pulseNum=3;
	//		break;
	//	case 50:
	//		pulseNum=4;
	//		break;
	//	case 100:
	//		pulseNum=5;
	//		break;
	//	case 200:
	//		pulseNum=6;
	//		break;
	//	case 500:
	//		pulseNum=7;	
	//		break;
	//	case 1000:
	//		pulseNum=8;
	//		break;
	//	case 2000:
	//		pulseNum=9;
	//		break;
	//	case 5000:
	//		pulseNum=10;
	//		break;
	//	case 10000:
	//		pulseNum=11;
	//		break;
	//	case 20000:
	//		pulseNum=12;
	//		break;
	//	default:pulseNum=12;break;
	//	}
	//	//查找计算损耗的最佳起始点。
	//	int step_L=0;
	//	int Start_point=0,End_point=0;
	//	float avg_roias=0;
	//	int up_time=0,fault_time=0;
	//	int data1=0,data2=0;
	//	int count_success_time=0;
	//
	//	step_L=2*lEventGenerate(pulseNum, wavelength,Sample_freaq);
	//	if(sGabor_Result->Event_Array[0]<step_L)Start_point=step_L;
	//	else Start_point=sGabor_Result->Event_Array[0];
	//	if((sGabor_Result->Event_Array[1]-Start_point)<4*step_L)
	//	{
	//		End_point=sGabor_Result->Event_Array[1]-step_L/4;
	//	}
	//	else End_point=Start_point+4*step_L;
	//	for(i=Start_point;i<End_point;i++)
	//	{
	//		//求出段噪声。
	//		avg_roias=avg_roias+abs(input_data[i]-input_data[i+1]);
	//
	//	}
	//	avg_roias=2*avg_roias/(End_point-Start_point);
	//	if(avg_roias<100)avg_roias=100;
	//	if((End_point-Start_point)>20)
	//	{
	//		for(i=End_point;i>Start_point;i--)
	//		{
	//			fault_time=0;
	//			up_time=0;
	//			count_success_time=0;
	//			for(j=i;j>Start_point;j--)
	//			{
	//				data1=input_data[i];
	//				data2=input_data[j];
	//				if((data1-data2)>avg_roias)
	//				{
	//					up_time++;
	//					fault_time=0;
	//					if(up_time>=10)
	//					{
	//						//Start_point=i;
	//						count_success_time++;
	//						if(count_success_time>=5)
	//						{
	//							Start_point=i;
	//							break;
	//						}
	//						
	//					}
	//					continue;
	//				}
	//				else
	//				{
	//					fault_time++;
	//					
	//					if(fault_time>=3)
	//					{
	//						count_success_time=0;
	//						break;
	//					}
	//					
	//				}
	//			}
	//			if(j<=Start_point)Start_point=i;
	//		}
	//	}
	//	sGabor_Result->Event_Array[0]=Start_point;
	//
	///////////////////////////////////////////////////////////////////////////////////
	if(sGabor_Result->Valid_Num==2)
	{
		if(sGabor_Result->Line_k[1]==0)
		{
			sGabor_Result->Total_Loss[i]=0;
		}
		else
		{
			sGabor_Result->Total_Loss[1]=sGabor_Result->Line_k[1]*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000+0.02;
		}
	}
	else if(sGabor_Result->Valid_Num>2)
	{
		if(sGabor_Result->Line_k[1]!=0)
		{
			start_loss_dB=sGabor_Result->Line_k[1]*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
		}
		else if(sGabor_Result->Line_k[2]!=0)
		{
			start_loss_dB=sGabor_Result->Line_k[2]*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
		}
		else 
		{
			if(wavelength==1310)
			{
				start_loss_dB=Avg_loss_1310*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
			}
			else if(wavelength==1490)
			{
				start_loss_dB=Avg_loss_1490*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
			}
			else if(wavelength==1550)
			{
				start_loss_dB=Avg_loss_1550*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
			}
			else if(wavelength==1625)
			{
				start_loss_dB=Avg_loss_1625*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
			}
			else if(wavelength==1300)
			{
				start_loss_dB=Avg_loss_1300*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
			}
			else if(wavelength==850)
			{
				start_loss_dB=Avg_loss_850*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
			}
			else if(wavelength==1650)
			{
				start_loss_dB=Avg_loss_1650*sGabor_Result->Event_Array[1]*Sample_time*Light_fiber_speed/2000;
			}
		}
		start_loss_dB=start_loss_dB+0.02;
		sGabor_Result->Total_Loss[1]=start_loss_dB;
		for(i=2;i<sGabor_Result->Valid_Num;i++)
		{
			if(sGabor_Result->Event_Array[i]>=15&&pulsewidth>3&&sGabor_Result->Event_Array[1]>=10)
			{
				sGabor_Result->Total_Loss[i]=(input_data[sGabor_Result->Event_Array[i]-15]+input_data[sGabor_Result->Event_Array[i]-14]+input_data[sGabor_Result->Event_Array[i]-13]+input_data[sGabor_Result->Event_Array[i]-12]+input_data[sGabor_Result->Event_Array[i]-11])/5
					-(input_data[sGabor_Result->Event_Array[1]-6]+input_data[sGabor_Result->Event_Array[1]-7]+input_data[sGabor_Result->Event_Array[1]-8]+input_data[sGabor_Result->Event_Array[1]-9]+input_data[sGabor_Result->Event_Array[1]-10])/5;
				sGabor_Result->Total_Loss[i]=(sGabor_Result->Total_Loss[i])/1000+start_loss_dB;//-sGabor_Result->Event_Loss[0];///-sGabor_Result->Event_Loss[0]20130617
				if(sGabor_Result->Total_Loss[i]<=0.1)sGabor_Result->Total_Loss[i]=0;
				if(i>0)
				{

					for(j=0;j<i;j++)//如果后面的总损耗计算结果比前面的总损耗结果还要小，说明错误，记为0
					{
						if(sGabor_Result->Total_Loss[i]<sGabor_Result->Total_Loss[j])
							sGabor_Result->Total_Loss[i]=0;
					}
				}


			}
			else
			{
				sGabor_Result->Total_Loss[i]=0;
			}

		}
	}
	//return sGabor_Result;
}
Gabor_Result Find_Reflex_Event_end_function(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq)
{
	int i=0,j=0,m=0,n=0;
	float *  data_buff=new float[20000];//[20000];
	memset(data_buff,0,20000*sizeof(float));

//	int* input_data_buff=new int[paramLen];//短时傅里叶变化结果Cn
//	memset(input_data_buff,0,paramLen*sizeof(int));

	int pulseNum=0;

	switch(pulsewidth)
	{
	case 3:
		pulseNum=0;
		break;
	case 5:
		pulseNum=1;
		break;
	case 10:
		pulseNum=2;
		break;
	case 20:
		pulseNum=3;
		break;
	case 50:
		pulseNum=4;
		break;
	case 100:
		pulseNum=5;
		break;
	case 200:
		pulseNum=6;
		break;
	case 500:
		pulseNum=7;	
		break;
	case 1000:
		pulseNum=8;
		break;
	case 2000:
		pulseNum=9;
		break;
	case 5000:
		pulseNum=10;
		break;
	case 10000:
		pulseNum=11;
		break;
	case 20000:
		pulseNum=12;
		break;
	case 30:
		pulseNum=13;
		break;
	case 300:
		pulseNum=14;
		break;
	case 400:
		pulseNum=15;
		break;
	default:pulseNum=12;break;
	}
	int Pulse_step_point=(pulsewidth/40)*(Sample_freaq/25);
	if(Pulse_step_point<=20)Pulse_step_point=20;
	//Pulse_step_point=lEventGenerate(pulseNum,wavelength,Sample_freaq);


	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
	//两个数据之间的时间间隔：
	double Sample_time=Sample_freaq;//放大了10^6倍
	Sample_time=1/Sample_time;



	float Single_point_distance=0;
	Single_point_distance=(Sample_time*Light_fiber_speed)/2;

	int Event_finish[100];

//	int delete_buff[100];
	int delete_buff_point=0;
	int Reflex_Event_start_point=0,Reflex_Event_end_point=0;

	int max_point=0;
	int MAX_value=0;
	float Avg_set_point_value=0;
	float Avg_K_line=0;
	int up_time=0,low_time=0;
	for(i=0;i<100;i++)
		Event_finish[i]=0;
	for(i=1;i<sGabor_Result.Valid_Num-1;i++)
	{
		//if(sGabor_Result.Reflect_Type[i]!=0)//反射事件
		{


			//找最高峰
			MAX_value=0;
			m=sGabor_Result.Event_Array[i]+Pulse_step_point;
			if(m>sGabor_Result.Event_Array[i+1])m=sGabor_Result.Event_Array[i+1];
			for(j=sGabor_Result.Event_Array[i]-Pulse_step_point/10;j<m;j++)
			{
				if(MAX_value<=(65535-input_data[j]))
				{
					MAX_value=65535-input_data[j];
					max_point=j;
				}

			}
			//找到最高峰后，将最高峰作为结束点，开始从后往前找，找突变点。

			Reflex_Event_end_point=4*Pulse_step_point+max_point;
			if(Reflex_Event_end_point>sGabor_Result.Event_Array[i+1])
				Reflex_Event_end_point=3*Pulse_step_point+max_point;
			if(Reflex_Event_end_point>sGabor_Result.Event_Array[i+1])
				Reflex_Event_end_point=2*Pulse_step_point+max_point;
			if(Reflex_Event_end_point>sGabor_Result.Event_Array[i+1])
				Reflex_Event_end_point=Pulse_step_point+max_point;
			if(Reflex_Event_end_point>sGabor_Result.Event_Array[i+1])
			{

				Reflex_Event_end_point=Pulse_step_point/2+max_point;

			}
			if(Reflex_Event_end_point>sGabor_Result.Event_Array[i+1])
			{
				continue;
			}
			Reflex_Event_start_point=max_point;
			Avg_set_point_value=65535-(input_data[Reflex_Event_end_point]+input_data[Reflex_Event_end_point-1]
			+input_data[Reflex_Event_end_point-2]+input_data[Reflex_Event_end_point-3]+input_data[Reflex_Event_end_point-4])/5;
			for(j=Reflex_Event_end_point-(Reflex_Event_end_point-Reflex_Event_start_point)/4;j>Reflex_Event_start_point;j--)
			{
				data_buff[j-Reflex_Event_start_point]=(65535-(input_data[j]+input_data[j-1]+input_data[j+1])/3-Avg_set_point_value)/((Reflex_Event_end_point-2-j)*Single_point_distance);

			}
			Avg_K_line=0;
			for(j=Reflex_Event_end_point-(Reflex_Event_end_point-Reflex_Event_start_point)/4;j>Reflex_Event_end_point-3*(Reflex_Event_end_point-Reflex_Event_start_point)/8;j--)
			{
				Avg_K_line=Avg_K_line+data_buff[j-Reflex_Event_start_point];
			}
			Avg_K_line=Avg_K_line/((Reflex_Event_end_point-Reflex_Event_start_point)/8);
			up_time=0;low_time=0;
			for(j=Reflex_Event_end_point-(Reflex_Event_end_point-Reflex_Event_start_point)/4;j>Reflex_Event_start_point;j--)
			{
				if(data_buff[j-Reflex_Event_start_point]>1.1*Avg_K_line)
				{
					up_time++;
					if(Pulse_step_point/8>5)
					{

						if(up_time>=Pulse_step_point/8)
						{
							// sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=j;
							Event_finish[i]=j-up_time;
							if(Event_finish[i]-sGabor_Result.Event_Array[i]<Pulse_step_point)
								Event_finish[i]=sGabor_Result.Event_Array[i]+6*Pulse_step_point/5;
							// return sGabor_Result;
							break;
						}

					}
					else
					{
						if(up_time>=5)
						{
							// sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=j;
							Event_finish[i]=j-up_time;
							if(Event_finish[i]-sGabor_Result.Event_Array[i]<Pulse_step_point)
								Event_finish[i]=sGabor_Result.Event_Array[i]+6*Pulse_step_point/5;
							// return sGabor_Result;
							break;
						}
					}
				}
				else
				{

					low_time++;
					if(low_time>=3)up_time=0;
				}
			}
			if(Event_finish[i]==0)
				Event_finish[i]=sGabor_Result.Event_Array[i]+Pulse_step_point;

		}

	}
	/*for(i=1;i<sGabor_Result.Valid_Num-1;i++)
	{
	sGabor_Result.Event_Loss[i]=((65535-input_data[sGabor_Result.Event_Array[i]-10])-(65535-input_data[Event_finish[i]]));
	sGabor_Result.Event_Loss[i]=sGabor_Result.Event_Loss[i]/1000;
	}*/
	n=sGabor_Result.Valid_Num-1;
	for(i=1;i<n;i++)
	{
		if(Event_finish[i]!=0)
		{
			sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=Event_finish[i];
			sGabor_Result.Event_Loss[sGabor_Result.Valid_Num]=0;
			sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=0;
			sGabor_Result.Line_k[sGabor_Result.Valid_Num]=0;
			sGabor_Result.Total_Loss[sGabor_Result.Valid_Num]=0;
			sGabor_Result.Event_type[sGabor_Result.Valid_Num++]='T';
		}


		//else sGabor_Result=deleteEvent(i,wavelength,pulsewidth,input_data,sGabor_Result,Index_N,Sample_freaq,-70);
	}
	delete[] data_buff;
	return sGabor_Result;
}
//******************************************************************//
//     删除事件
//     deleteNum:所删除事件点序号
//     wavelength:曲线波长
//     pulsewidth：曲线脉宽
//     input_data[]：分析的原始数据
//******************************************************************//
//******************************************************************//
//     删除事件
//     deleteNum:所删除事件点序号
//     wavelength:曲线波长
//     pulsewidth：曲线脉宽
//     input_data[]：分析的原始数据
//******************************************************************//

//Gabor_Result DeleteGhosting(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,float dB_Loss,float dB_reflex,float dB_End,float Sample_freaq)
//{
//	int Erro_point=0;//判断时允许的误差
//	int i=0,j=0,k=0;
//
//
//}




//Gabor_Result smooth(int N,WORD input_data[],INT paramLen)
//{
//	int i=0,j=0;
//	long sum=0;
//	unsigned int M=paramLen;
//	for (i = 0;i<M;i++)
//	{
//		sum = 0;
//		if(i==M)
//			data_from_file[i] = input_data[i];
//		else if(i<N/2)
//		{
//			for (j = 0;j<(2*i-1);j++)
//				sum = sum + input_data[j];
//			data_from_file[i]=sum/(2*i-1);
//		}
//		else if((M-i)<(N/2-1))
//		{
//			for (j =0;j<(2*(M-i)+1);j++)
//				sum = sum + input_data[M+1-j];
//			data_from_file[i]=sum/(2*(M-i)+1);
//		}
//		else
//		{
//			for (j=0;j<N;j++)
//				sum = sum + input_data[i-(N+1)/2+j]; 
//			data_from_file[i] = sum/N;
//		}
//	}
//return sGabor_Result;
//
//}



////*****************************************************************************************/
/*****************************************************************************
wavelength:波长
pulseWidth：脉宽
input_data[]：母线+实时测试曲线
paramLen  数据总长
dB_Loss   损耗阈值
dB_reflex 反射阈值
Sample_freaq 采样频率
Index_N    群折射率
start_point：监控起始点
end_point：  监控结束点

返回：事件列表

*********************************************************************/

Gabor_Result The_monitoring_mode(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,float dB_Loss,float dB_reflex,float Sample_freaq,float Index_N,int start_point,int end_point)
{
#define deBug_enable 0
	double Light_fiber_speed=300/Index_N;//缩小了10^6倍
	//两个数据之间的时间间隔：
	double Sample_time=Sample_freaq;//放大了10^6倍
	Sample_time=1/Sample_time;
	//测量距离计算
	double Measure_distacne = Light_fiber_speed*Sample_time*paramLen/2;

	int i=0,j=0,k=0;

	int L_event=0;
	int step_event;
	int pulseNum;
	switch(pulseWidth)
	{
	case 3:
		pulseNum=0;
		break;
	case 5:
		pulseNum=1;
		break;
	case 10:
		pulseNum=2;
		break;
	case 20:
		pulseNum=3;
		break;
	case 50:
		pulseNum=4;
		break;
	case 100:
		pulseNum=5;
		break;
	case 200:
		pulseNum=6;
		break;
	case 500:
		pulseNum=7;	
		break;
	case 1000:
		pulseNum=8;
		break;
	case 2000:
		pulseNum=9;
		break;
	case 5000:
		pulseNum=10;
		break;
	case 10000:
		pulseNum=11;
		break;
	case 20000:
		pulseNum=12;
		break;
	case 30:
		pulseNum=13;
		break;
	case 300:
		pulseNum=14;
		break;
	case 400:
		pulseNum=15;
		break;

	default:pulseNum=12;break;
	}
	L_event=lEventGenerate(pulseNum,wavelength,Sample_freaq);
	if(pulseWidth>=500)/////////////////////////////////////////20130615
		step_event=2*pulseWidth*Sample_freaq/25000;

	int pulse_step_point=0;//一个脉宽的采样点数
	int data_length=paramLen/2;
	int* Parameter_data_buff=new int[data_length];//短时傅里叶变化结果Cn
	memset(Parameter_data_buff,0,data_length*sizeof(int));
	int* Testing_data_buff=new int[data_length];
	memset(Testing_data_buff,0,data_length*sizeof(int));
	
	int* data_near=new int[data_length];
	memset(data_near,0,data_length*sizeof(int));

	pulse_step_point=2*pulseWidth/25*(Sample_freaq/25);
	//pulse_step_point=100;

    Gabor_Result sGabor_Result;
	for(i=0;i<data_length;i++)//分离数据，参考数据和原始数据分离
	{
		Parameter_data_buff[i]=65535-input_data[i];
		Testing_data_buff[i]=65535-input_data[i+data_length];
	}
   sGabor_Result.Valid_Num=0;
   sGabor_Result.Event_Array[0];
	//////寻找监控起始点,以最高点为监控起始点
	int max_data=0;
	int max_data_number=5;
	int min_data=65535;
	int min_data_number=5;
	for(i=5;i<3*pulse_step_point;i++)
	{
		if(max_data<=Parameter_data_buff[i])
		{
			max_data=Parameter_data_buff[i];
			max_data_number=i;
		}
	}
	/////寻找监控结束点

	//计算参数曲线的监控点与测量曲线的监控点的差值
	if(start_point==0)start_point=max_data_number;
	float D_value_dB=Parameter_data_buff[start_point]-Testing_data_buff[start_point];
	D_value_dB=0;
	for(i=0;i<10;i++)
	{
		D_value_dB=D_value_dB+(Parameter_data_buff[start_point+i]-Testing_data_buff[start_point+i]);
	}
	D_value_dB=D_value_dB/10;
	//平移测量曲线
	for(i=0;i<data_length;i++)
	{
		Testing_data_buff[i]=Testing_data_buff[i]+D_value_dB;
	}

	//查找故障点
	int up_time=0,down_time=0,D_value_dB_point=0;
	float Loss_accout=0;
	float AVG_loss=0;
	sGabor_Result.Valid_Num=0;
    Loss_accout=0;
	if(dB_Loss<=0.3)dB_Loss=0.3;
	for(i=start_point;i<end_point;i++)
	{
		
		
		D_value_dB_point=(Parameter_data_buff[i]-Testing_data_buff[i])/1000;
		if(D_value_dB_point>=(dB_Loss+Loss_accout))//测试曲线比参考曲线低
		{
			down_time++;
			up_time=0;
			if(down_time>=pulse_step_point/2)
			{
				sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=i-down_time;
				AVG_loss=0;
				for(j=i-up_time;j<i;j++)//算平均损耗
				{
					AVG_loss=AVG_loss+(Parameter_data_buff[j]-Parameter_data_buff[j]-Testing_data_buff[j]);
				}
				if(up_time!=0)
				AVG_loss=AVG_loss/up_time/1000;
				sGabor_Result.Event_Loss[sGabor_Result.Valid_Num++]=AVG_loss;
				i=i+pulse_step_point/2;

				down_time=0;
				up_time=0;
				if(sGabor_Result.Valid_Num>=99)break;
				for(k=0;k<sGabor_Result.Valid_Num;k++)
				{
					Loss_accout=Loss_accout+sGabor_Result.Event_Loss[k];
				}
#if deBug_enable
				break;
#else 
				continue;
#endif
				
			}
		}
		else//测量曲线比参考曲线高
		{
			up_time++;
			if(up_time>=2)down_time=0;
		}
	}
	////查找是否为反射峰后边沿，如果为后延，就将其移动到前边沿
	//{
	//	for(i=0;i<paramLen-1;i++)
	//	{
	//		data_near[i]=Testing_data_buff[i+1]-Testing_data_buff[i];
	//		if(data_near[i]<100)data_near[i]=0;
	//	}
	//	
	//	for(i=0;i<sGabor_Result.Valid_Num;i++)
	//	{
	//		max_data=0;
	//		max_data_number=0;
	//		min_data=65535;
	//		min_data_number=0;
	//		for(j=0;j<4*L_event;j++)
	//		{
	//			if(sGabor_Result.Event_Array[i]-j>0)
	//			{
	//				if(max_data<=(65535-input_data[sGabor_Result.Event_Array[i]-j]))
	//				{
	//					max_data=65535-input_data[sGabor_Result.Event_Array[i]-j];
	//					max_data_number=input_data[sGabor_Result.Event_Array[i]-j];
	//				}
	//				if(min_data>=(65535-input_data[sGabor_Result.Event_Array[i]-j]))
	//				{
	//					min_data=65535-input_data[sGabor_Result.Event_Array[i]-j];
	//					min_data_number=input_data[sGabor_Result.Event_Array[i]-j];
	//				}

	//			}
	//		}
	//		if(sGabor_Result.Event_Array[i]>4*L_event)
	//		{
	//			for(j=sGabor_Result.Event_Array[i]-4*L_event;j<sGabor_Result.Event_Array[i];j++)
	//			{
	//				if(data_near[j]>0)
	//				{
	//					if(data_near[j+1]>0)
	//						if(data_near[j+2]>0)
	//							if(data_near[j+3]>0)
	//								if(data_near[j+4]>0)
	//								{
	//									if(j<max_data_number)
	//									{
	//										if(j+L_event>max_data_number)
	//											sGabor_Result.Event_Array[i]=j;
	//										break;
	//									}
	//								}
	//				}
	//			}
	//		}
	//	}
	//	
	//}
#if deBug_enable
	sGabor_Result.Event_Array[2]=end_point;
	sGabor_Result.Event_Array[1]=sGabor_Result.Event_Array[0];
	sGabor_Result.Event_Loss[1]=sGabor_Result.Event_Loss[0];
	sGabor_Result.Event_Array[0]=start_point;
	sGabor_Result.Valid_Num=3;
#else 
	for(i=0;i<sGabor_Result.Valid_Num;i++)
	{
		sGabor_Result.Event_Array[i+1]=sGabor_Result.Event_Array[i];
		sGabor_Result.Event_Loss[i+1]=sGabor_Result.Event_Loss[i];
	}
	sGabor_Result.Valid_Num=sGabor_Result.Valid_Num+2;
	sGabor_Result.Event_Array[0]=start_point;
	sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]=end_point;
#endif
	/*if()
	sGabor_Result.Valid_Num=1;
	for(i=1;i<sGabor_Result.Valid_Num;i++)
	{
		sGabor_Result.Event_Array[i]=sGabor_Result.Event_Array[i-1];
	}
	sGabor_Result.Event_Array[sGabor_Result.Valid_Num++]=end_point;
	sGabor_Result.Event_Array[0]=start_point;*/
	//sGabor_Result.Valid_Num=3;
	delete[] Parameter_data_buff;
	delete[] Testing_data_buff;
return sGabor_Result;

}



Gabor_Result Search_fiber_end_function(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,float Sample_freaq,float thresholdUpSet )
{
	int i,j,k;
	unsigned char  delete_flag[100];
	int L_event=0;
	int max_event=0;
	int max_event_mark=0;
	float fiber_end_radio=0;
	float Upset_value=30;
	int* Count_data_buff=new int[paramLen];
	memset(Count_data_buff,0,paramLen*sizeof(int));
	//int Count_data_buff[10000];
    int Event_step_length=0;
	if(pulseWidth==3)Event_step_length=4;
	else if(pulseWidth==5)Event_step_length=6;
	else Event_step_length=4*pulseWidth/5;

	int data_buff_d=0;

    Gabor_Result sGabor_Result;

    sGabor_Result.Valid_Num=0;
	for(i=0;i<100;i++)delete_flag[i]=0;

    if(paramLen<201)
	{
		sGabor_Result.Valid_Num=0;
		return sGabor_Result;
	}

	for(i=0;i<paramLen-1;i++)
	{
		Count_data_buff[i]=input_data[i]-input_data[i+1];
	}
    for(i=paramLen-1;i>paramLen-51;i--)
	{
		fiber_end_radio=fiber_end_radio+(65536-input_data[i]);
	}
	fiber_end_radio=fiber_end_radio/50;
	for(i=0;i<paramLen-5;i++)
	{
		if(Count_data_buff[i]>Upset_value)
		{
			if(Count_data_buff[i+1]>Upset_value)
				if(Count_data_buff[i+2]>Upset_value)
					if(Count_data_buff[i+3]>Upset_value)
						if(Count_data_buff[i+4]>-400)
					    {
						if(65535-input_data[i+4]>2*fiber_end_radio+1000)
							if(65535-input_data[i+5]>2*fiber_end_radio+1000)
								//if(65535-input_data[i+6]>2*fiber_end_radio+1000)
								{
									max_event=0;
									max_event_mark=0;
									for(j=0;j<6;j++)
									{
										if(max_event<65535-input_data[i+j])
										{
											max_event=65535-input_data[i+j];
											max_event_mark=i+j;
										}
									}
									data_buff_d=(max_event-(65535-input_data[i]));
									if(data_buff_d>=300&&i>=6)//要求反射峰的高度要大于1dB
									{
										sGabor_Result.Event_Array[sGabor_Result.Valid_Num]=i;
										sGabor_Result.Reflect_Type[sGabor_Result.Valid_Num]=1;
										sGabor_Result.Event_Hight[sGabor_Result.Valid_Num]=data_buff_d/1000;
										sGabor_Result.Event_Loss[sGabor_Result.Valid_Num]=0;
										sGabor_Result.Line_k[sGabor_Result.Valid_Num]=0;
										sGabor_Result.Event_type[sGabor_Result.Valid_Num]='F';
										i=i+Event_step_length;
										sGabor_Result.Valid_Num++;
									}
									
								}
						
					}
		}
	}

	//算法二
	{

	}
	//鬼影判断
	if(sGabor_Result.Valid_Num>=3)
	{
		float doint1,doint2,doint3,doint4;
		float data_max1=0,data_max2=0;
		int data_max_mark1=0,data_max_mark2=0;
		int Reflex_width1=0,Reflex_width2=0;
		float data_distance=0;
		for(i=sGabor_Result.Valid_Num-2;i>0;i--)
		{
			data_distance=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]-2*sGabor_Result.Event_Array[i];
			
			if(data_distance<=20&&data_distance>=0)
			{
				doint1=0;
				doint2=0;
				doint3=0;
				doint4=0;

				doint1=65535-input_data[sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]];
				doint3=65535-input_data[sGabor_Result.Event_Array[i]];
				for(j=sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1];j<sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1]+3*L_event;j++)
				{
					if(j>paramLen-3)break;
					if(data_max1<=65535-input_data[j])
					{
						data_max1=65535-input_data[j];
						data_max_mark1=j;
					}
				}
				for(j=data_max_mark1;j<data_max_mark1+10*L_event;j++)
				{
					if(j>paramLen-3)break;
					if(65535-input_data[j]<=doint1)
					{
						if(65535-input_data[j+1]<=doint1)
						{
							break;
						}
					}
				}
				Reflex_width1=j-sGabor_Result.Event_Array[sGabor_Result.Valid_Num-1];

				for(j=sGabor_Result.Event_Array[i];j<sGabor_Result.Event_Array[i]+3*L_event;j++)
				{
					if(j>paramLen-3)break;
					if(data_max2<=65535-input_data[j])
					{
						data_max2=65535-input_data[j];
						data_max_mark2=j;
					}
				}
				for(j=data_max_mark2;j<data_max_mark2+10*L_event;j++)
				{
					if(j>paramLen-3)break;
					if(65535-input_data[j]<=doint2)
					{
						if(65535-input_data[j+1]<=doint2)
						{
							break;
						}
					}
				}
				Reflex_width2=j-sGabor_Result.Event_Array[i];
				if(Reflex_width2>=2*Reflex_width1)//前面的反射峰宽度是后面的反射峰宽度的两倍以上，就认为后面的反射峰为前面反射峰的鬼影
				{
					if(Reflex_width1<=4*L_event)
					sGabor_Result.Valid_Num=i+1;break;
				}
			}
		}
		//求出每个峰的凸起高度
		//{
		//	float data_min=0;
		//	int data_min_mark=0;
		//	for(i=1;i<=sGabor_Result.Valid_Num-1;i++)
		//	{
		//		data_max1=0;
		//		data_min=65536;
		//		for(j=sGabor_Result.Event_Array[i];j<sGabor_Result.Event_Array[i]+20;j++)
		//		{
		//			if(j<=sGabor_Result.Valid_Num-2)
		//				if(j>sGabor_Result.Event_Array[j+1])break;
		//			if(data_max1<65535-input_data[j])
		//			{
		//				data_max1=65535-input_data[j];
		//				data_max1=(65535-input_data[j]+65535-input_data[j+1])/2;
		//				data_max_mark1=j;
		//			}
		//			if(data_min>65535-input_data[j])
		//			{
		//				if(j>data_max_mark1)break;
		//				data_min=65535-input_data[j];
		//				data_min=((65535-input_data[j])+(65535-input_data[j-1]))/2;
		//				data_min_mark=j;
		//			}
		//		}
		//		sGabor_Result.Event_Hight[i]=(data_max1-data_min)/1000;
		//		
		//	}
		//}
		for(i=1;i<=sGabor_Result.Valid_Num-1;i++)
		{
			//if(sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[i-1]<=24）//小于6米
			//	if(sGabor_Result.Event_Hight[i]<0.8)
			delete_flag[i]=0;
			if(sGabor_Result.Event_Hight[i]<3.0)//反射峰高度小于3dB
			{
				if(sGabor_Result.Event_Array[i]-sGabor_Result.Event_Array[i-1]<=24)//小于6米
				{
					delete_flag[i]=1;
				}
			}
		}
		j=0;
		for(i=0;i<sGabor_Result.Valid_Num;i++)
		{
			if(delete_flag[i]==0)
			{
				sGabor_Result.Event_Array[j]=sGabor_Result.Event_Array[i];
				sGabor_Result.Event_Hight[j]=sGabor_Result.Event_Hight[i];
				sGabor_Result.Reflect_Type[j]=sGabor_Result.Reflect_Type[i];
				j++;
			}
		}
		sGabor_Result.Valid_Num=j;

	}

   delete[] Count_data_buff;
   if(sGabor_Result.Valid_Num>0)
   {
	   if(sGabor_Result.Valid_Num==1)
	   {

		   sGabor_Result.Event_Array[1]=sGabor_Result.Event_Array[0];
		   sGabor_Result.Event_Array[0]=3;
		   sGabor_Result.Valid_Num++;
	   }
   sGabor_Result.Event_type[sGabor_Result.Valid_Num-1]='E';
   }

   {
	   float data_min=0;
	   int data_min_mark=0;
	   for(i=1;i<sGabor_Result.Valid_Num;i++)
	   {
		   data_min=65535;
		   data_min_mark=sGabor_Result.Event_Array[i];
		   for(j=sGabor_Result.Event_Array[i]-3;j<sGabor_Result.Event_Array[i]+2;j++)
		   {
			   if(data_min>=65535-input_data[j])
			   {
				   data_min=65535-input_data[j];
				   data_min_mark=j;
			   }
			   
		   }
		   sGabor_Result.Event_Array[i]=data_min_mark;
	   }
   }
   return sGabor_Result;
}




int Search_long_fiber_end(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,float Sample_freaq)
{
	int i=0,j=0;
	int End_nois_Max=0;//末端的噪声最高值
	long Avg_End_noise = 0 ;//末端噪声的平均水平
	int return_point_number=paramLen;
	int count1=0,count2=0;
	int pulse_step=0;
	int Step_start_point=0;
	if(pulseWidth==10000)pulse_step=250;
	else if(pulseWidth==20000)pulse_step=500;
	else pulse_step=250;
	if(pulseWidth>=10000&&Sample_freaq==25&&paramLen>=25000)
	{
	  for(i=paramLen-1;i>paramLen-501;i--)
	  {
		  if(End_nois_Max<65535-input_data[i])
		  {
			  End_nois_Max=65535-input_data[i];
			  Avg_End_noise=Avg_End_noise+65535-input_data[i];
		  }
	  }
	  Avg_End_noise=Avg_End_noise/500;
	  if(End_nois_Max<3000)End_nois_Max=3000;
	  if(Avg_End_noise<500)Avg_End_noise=End_nois_Max/2;
	  for(i=paramLen;i>20000;i--)
	  {
		  if((65535-input_data[i])>=Avg_End_noise)
		  {
			  count1++;
			  count2=0;
			  if(count1==1)Step_start_point=i;
			  if(count1>=3*pulse_step/2)
			  {
				  return_point_number=Step_start_point;
			  }
		  }
		  else
		  {
			  count2++;
			  if(count2>=3)count1=0;
		  }
	  }
	}
	/*for(i=return_point_number;i<paramLen;i++)
	{
		//input_data[i]=65535-(65535-input_data[i])/2;
		input_data[i]=(input_data[i]+input_data[i+1])/2;
		if(65535-input_data[i]>End_nois_Max)input_data[i]=65535;//65535-(65535-input_data[i])/2;
		else input_data[i]=65535-(65535-input_data[i])/2;;
	}*/
	return return_point_number;

}





void Deadzoon_function(int wavelength,int pulsewidth,WORD input_data[],int paramLen,Gabor_Result& sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe)
{
	//return;
	float Distance_event_to_event=0;
	float Distance_point_to_point=0;
	float Deadzoon_event=0;
	float Deadzoon_attenction=0;
	float Measurement_range=0;
	float Avg_loss_wave_lenght=0;
	int Max_mark=0;
	int Max_data=0;
	int i=0,j=0,m=0;
	int data1=0,data2=0;
	int DD_point=0;
	int noise=0;
	float kkk=0;
	float Float_data_buff=0;
	int Step_point=0;
	int Deadzoon_event_point=0;
	int Deadzoon_attenction_point=0;
	int left_start_event=0,right_end_event=0;
	int left_start_attenction=0,right_end_attenction=0;
	Step_point=Step_point_count(pulsewidth,wavelength,Sample_freaq);
	//Avg_loss_wave_lenght=Avg_loss_wave_lenght_count(wavelength);
	//Avg_loss_wave_lenght=Avg_loss_wave_lenght*1000/(Sample_freaq/25);
	switch(pulsewidth)
	{
	case 3:
		//Deadzoon_event=0.8;
		//Deadzoon_attenction=5;
		switch(wavelength)
		{
		case 850:
			Deadzoon_event=2.5;
			Deadzoon_attenction=14;
			break;
		case 1300:
			Deadzoon_event=2;
			Deadzoon_attenction=12;
			break;
		case 1310:
			Deadzoon_event=0.8;
			Deadzoon_attenction=5;
			break;
		case 1490:
			Deadzoon_event=0.8;
			Deadzoon_attenction=5.5;
			break;
		case 1550:
			Deadzoon_event=0.8;
			Deadzoon_attenction=5;
			break;
		case 1625:
			Deadzoon_event=0.8;
			Deadzoon_attenction=6;
			break;
		case 1650:
			Deadzoon_event=0.9;
			Deadzoon_attenction=6;
			break;
		default:
			Deadzoon_event=0.8;
			Deadzoon_attenction=5;
			break;
		}
		break;
	case 5:
		switch(wavelength)
		{
		case 850:
			Deadzoon_event=4;
			Deadzoon_attenction=20;
			break;
		case 1300:
			Deadzoon_event=3;
			Deadzoon_attenction=15;
			break;
		case 1310:
			Deadzoon_event=1.5;
			Deadzoon_attenction=10;
			break;
		case 1490:
			Deadzoon_event=1.2;
			Deadzoon_attenction=8;
			break;
		case 1550:
			Deadzoon_event=1.2;
			Deadzoon_attenction=8;
			break;
		case 1625:
			Deadzoon_event=1.2;
			Deadzoon_attenction=8;
			break;
		case 1650:
			Deadzoon_event=1.3;
			Deadzoon_attenction=9;
			break;
		default:
			Deadzoon_event=1.2;
			Deadzoon_attenction=8;
			break;
		}
		break;
	case 10:
		switch(wavelength)
		{
		case 850:
			Deadzoon_event=5;
			Deadzoon_attenction=35;
			break;
		case 1300:
			Deadzoon_event=4;
			Deadzoon_attenction=30;
			break;
		case 1310:
			Deadzoon_event=3;
			Deadzoon_attenction=20;
			break;
		case 1490:
			Deadzoon_event=2.8;
			Deadzoon_attenction=18;
			break;
		case 1550:
			Deadzoon_event=2.5;
			Deadzoon_attenction=15;
			break;
		case 1625:
			Deadzoon_event=2.5;
			Deadzoon_attenction=15;
			break;
		case 1650:
			Deadzoon_event=2.8;
			Deadzoon_attenction=18;
			break;
		default:
			Deadzoon_event=2.5;
			Deadzoon_attenction=15;
			break;
		}
		break;
	default:
		Deadzoon_event=2;
		Deadzoon_attenction=14;
		break;

	}

	Distance_point_to_point=299.782458/Index_N/Sample_freaq/2;
	Measurement_range=paramLen*Distance_point_to_point;
	
    Deadzoon_event_point=Deadzoon_event/Distance_point_to_point;//事件盲区的数据点数
	Deadzoon_attenction_point=Deadzoon_attenction/Distance_point_to_point;//衰减事件的数据点数

	if(sGabor_Result.Valid_Num>=3&&pulsewidth<=10&&Measurement_range<6000&&Sample_freaq>=400)
	{
		for(i=1;i<sGabor_Result.Valid_Num-1;i++)
		{
			if(sGabor_Result.Reflect_Type[i]==1)
			{
				Distance_event_to_event=sGabor_Result.Event_Array[i]*Distance_point_to_point;
				if(Distance_event_to_event>200)
				{
					if(sGabor_Result.Event_Array[i+1]*Distance_point_to_point>Distance_event_to_event+30)
					{
						for(j=sGabor_Result.Event_Array[i]-3;j<sGabor_Result.Event_Array[i]+Step_point;j++)//找到反射事件的最高点
						{
                            if(Max_data<65535-input_data[j])
							{
								Max_data=65535-input_data[j];
								Max_mark=j;
							}
						}
						//向左寻找事件盲区的计算点和衰减事件的计算点，起始点保持不变
						for(j=Max_mark;j>sGabor_Result.Event_Array[i]-3;j--)
						{
							if(Max_data-(65535-input_data[j])>=1500)
							{
								left_start_event=j;
								left_start_attenction=sGabor_Result.Event_Array[i];
								break;
							}
						}
						//反射峰整形
						right_end_event=j+Deadzoon_event_point;
						right_end_attenction=left_start_attenction+Deadzoon_attenction_point;
						if(abs(65535-input_data[right_end_event]-Max_data)<1500)//反射事件压缩
						{
							input_data[right_end_event]=input_data[Max_mark]+1600;

							for(m=0;m<3;m++)//平滑3次
							{
								for(j=right_end_event;j>Max_mark;j--)
								{

									input_data[j]=(input_data[j]+input_data[j-1])/2;
								}
							}
						}
						//衰减事件压缩
						if(input_data[right_end_attenction]<input_data[left_start_attenction])
						{
							
							if(sGabor_Result.Event_Loss[i]>0)
							input_data[right_end_attenction]=input_data[left_start_attenction]-sGabor_Result.Event_Loss[i]*1000;
							else input_data[right_end_attenction]=input_data[left_start_attenction]-50;
							//处理反射峰的衰减区
							//for(m=0;m<3;m++)
							{
								/*data1=input_data[right_end_attenction]-input_data[right_end_event];
								data2=input_data[right_end_attenction]-input_data[right_end_event+1];
								kkk=data2;
								kkk=kkk/data1;
								
								for(j=right_end_attenction-1;j>right_end_event;j--)
								{
									input_data[j]=input_data[right_end_attenction]+(input_data[j]-input_data[right_end_attenction])/kkk;
								}*/
								kkk=input_data[right_end_attenction]-input_data[right_end_event];
								kkk=kkk/(right_end_attenction-right_end_event);
								for(j=right_end_attenction-1;j>=right_end_event;j--)
								{
									input_data[j]=input_data[right_end_attenction]-kkk*(right_end_attenction-j);//*(((j-right_end_attenction)/(right_end_attenction-right_end_event))^2);
								}
							}
							for(m=0;m<3;m++)
							{
								for(j=right_end_attenction-1;j>right_end_event;j--)
								{
									input_data[j]=(input_data[j]+input_data[j-1])/2;
								}
							}
							//找出小于衰减盲区末端的点
							noise=0;
							for(m=right_end_attenction;m<right_end_attenction+40*Step_point;m++)
							{
								if((input_data[m]+input_data[m+1])/2>=input_data[right_end_attenction])
								{
									DD_point=m;
									noise=abs(input_data[m]-input_data[m+1]);
									break;
								}
							}
							//if(m>right_end_attenction)
							//noise=noise/(m-right_end_attenction);
							//else noise =10;
							if(DD_point<=0)continue;
							if(noise<10)noise=10;
							kkk=noise;
							for(m=right_end_attenction;m<DD_point;m++)
							{
								if(abs(input_data[m+2]-input_data[m+1])>noise)
								{
									Float_data_buff=input_data[m+2]-input_data[m+1];
									Float_data_buff=Float_data_buff/kkk;
									Float_data_buff=(input_data[m+2]-input_data[m+1])/Float_data_buff;
									if(Float_data_buff<noise/4)
										Float_data_buff=noise/3;
									Float_data_buff=input_data[right_end_attenction]-Float_data_buff;
									input_data[m]=Float_data_buff;//input_data[right_end_attenction]+(input_data[m+2]-input_data[m+1])/((input_data[m+2]-input_data[m+1])/kkk);
									if(input_data[m]==input_data[m-1])
									{
										input_data[m]=input_data[DD_point+DD_point-m];
									}

								}
								else 

									input_data[m]=input_data[DD_point+(m-right_end_attenction)];//-(DD_point-m);
									//input_data[m]=input_data[sGabor_Result.Event_Array[i]-(m-right_end_attenction)];//input_data[right_end_attenction]+(input_data[m+2]-input_data[m+1]);
							}
						}

					}
				}
			}
		}
	}

}