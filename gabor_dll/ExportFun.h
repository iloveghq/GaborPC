//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//===================================================
//需要导出的函数,另外拿出来 20160425
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern "C" _declspec(dllexport) Gabor_Result deleteEvent(int deleteNum,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe);
//extern "C" _declspec(dllexport) Gabor_Result deleteEvent(int deleteNum,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result,float Index_N,float Sample_freaq);
extern "C" _declspec(dllexport) Gabor_Result insertEvent(int insertNum,int wavelength,int pulsewidthbox,WORD input_data[],int paramLen,Gabor_Result sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe);
extern "C" _declspec(dllexport) Gabor_Result gabor_arithmetic(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,double thresholdUpSet,double thresholdDownSet,float dB_Loss,float dB_reflex,float dB_End,float Return_loss_Tybe,float Sample_freaq,float Index_N,int link_point_number);
extern "C" _declspec(dllexport) LPCTSTR Version_number();
//extern "C" _declspec(dllexport) Gabor_Result gabor_arithmetic(int pulswith,int power,WORD input_data[],INT paramLen);//原来的cwcq2012.06.07
//2012.06.29前的
////extern "C" _declspec(dllexport) Gabor_Result gabor_arithmetic(int pulseWidth,int wavelength,WORD input_data[],INT paramLen,double thresholdUpSet,double thresholdDownSet,float fBend,float fReflect,float fFiberEnd,float fScatterCoeff,int fSampleFreaq);
////extern "C" _declspec(dllexport) Gabor_Result insertEvent(int insertNum,int wavelength,int pulsewidth,WORD input_data[],int paramLen,Gabor_Result sGabor_Result,float Return_loss_Tybe);
////extern "C" _declspec(dllexport) Gabor_Result deleteEvent(int deleteNum,int wavelength,int pulsewidth,WORD input_data[],Gabor_Result sGabor_Result);

extern "C" _declspec(dllexport) Gabor_Result The_monitoring_mode(int wavelength,int pulseWidth,WORD input_data[],INT paramLen,float dB_Loss,float dB_reflex,float Sample_freaq,float Index_N,int start_point,int end_point);
extern "C" _declspec(dllexport)  int Event_Array_End_function(int number);
extern "C" _declspec(dllexport) void Deadzoon_function(int wavelength,int pulsewidth,WORD input_data[],int paramLen,Gabor_Result& sGabor_Result,float Index_N,float Sample_freaq,float Return_loss_Tybe);
extern "C" _declspec(dllexport) void Acount_Total_Loss(int wavelength,int pulsewidth,WORD input_data[],Gabor_Result* sGabor_Result,float Index_N,float Sample_freaq);//2016.04.25



