// gabor_dll.h : gabor_dll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"
#include "GaborResult.h"
#include "ExportFun.h"

// Cgabor_dllApp
// �йش���ʵ�ֵ���Ϣ������� gabor_dll.cpp
//
//MyDLL.h 
//////
//////struct Gabor_Result     //�����ṹ��
//////{
//////	Gabor_Result()
//////	{
//////		memset(Event_Array,0,sizeof(Event_Array));
//////		memset(Event_Loss,0,sizeof(Event_Loss));
//////		memset(Reflect_Type,0,sizeof(Reflect_Type));
//////		memset(Event_Hight,0,sizeof(Event_Hight));
//////		memset(Line_k,0,sizeof(Line_k));
//////		memset(Total_Loss,0,sizeof(Total_Loss));
//////		Trail_End=10;
//////		Valid_Num=0;
//////	}
//////	int Reflect_Type[100];  //�¼�����	//Event Code
//////	int Event_Array[100];  //�¼�λ��  //Event Propagation Time
//////	float  Event_Loss[100];       //���//Event Loss
//////	float Event_Hight[100]; //�¼��㷴��dB
//////	float Line_k[100];//����б��
//////	float  Total_Loss[100];  //����ġ��ۼ����
//////	float  Reflect;   //����
//////	int Valid_Num;    //��Ч����
//////	float Trail_End;//β��λ��
//////	char Event_type[100];// A���û��Լӣ�M:    E:����ĩ�ˣ�F:������в��ң�O:����������Χ�Ĺ���ĩ�� D:
//////};//�ṹ��Ķ����λ������
////////
////////extern "C" _declspec(dllexport) Gabor_Result deleteEvent(int deleteNum,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe);
//////////extern "C" _declspec(dllexport) Gabor_Result deleteEvent(int deleteNum,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
////////extern "C" _declspec(dllexport) Gabor_Result insertEvent(int insertNum,int wavelength,int pulsewidthbox,WORD input_data[],int paramLen,Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe);
////////extern "C" _declspec(dllexport) Gabor_Result gabor_arithmetic(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,double thresholdUpSet,double thresholdDownSet,float dB_Loss,float dB_reflex,float dB_End,float Return_loss_Tybe,float Sample_freaq,float Index_N,int link_point_number);
////////extern "C" _declspec(dllexport) LPCTSTR Version_number();
//////////extern "C" _declspec(dllexport) Gabor_Result gabor_arithmetic(int pulswith,int power,WORD input_data[],INT paramLen);//ԭ����cwcq2012.06.07
//////////2012.06.29ǰ��
////////////extern "C" _declspec(dllexport) Gabor_Result gabor_arithmetic(int pulseWidth,int wavelength,WORD input_data[],INT paramLen,double thresholdUpSet,double thresholdDownSet,float fBend,float fReflect,float fFiberEnd,float fScatterCoeff,int fSampleFreaq);
////////////extern "C" _declspec(dllexport) Gabor_Result insertEvent(int insertNum,int wavelength,int pulsewidth,WORD input_data[],int paramLen,Gabor_Result sGabor_Result,float Return_loss_Tybe);
////////////extern "C" _declspec(dllexport) Gabor_Result deleteEvent(int deleteNum,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result);
////////
////////extern "C" _declspec(dllexport) Gabor_Result The_monitoring_mode(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,float dB_Loss,float dB_reflex,float Sample_freaq,float Index_N,int start_point,int end_point);
////////extern "C" _declspec(dllexport)  int Event_Array_End_function(int number);
////////extern "C" _declspec(dllexport) void Deadzoon_function(int wavelength,int pulsewidth,WORD input_data[],int paramLen,Gabor_Result& sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe);
class Cgabor_dllApp : public CWinApp
{
public:
	Cgabor_dllApp();

// ��д
public:
	virtual BOOL InitInstance();


	DECLARE_MESSAGE_MAP()
};

