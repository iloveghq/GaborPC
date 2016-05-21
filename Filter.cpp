#include "StdAfx.h"
#include "Filter.h"
#define ENVELOPE_REC_COEFF 	(99.0f)
////#define FILTER_ALPHA_COEFF	(0.98f)
////#define FILTER_ALPHA_COEFF_SMOOTH	  (0.98f)
////#define FILTER_ALPHA_COEFF_RISE       (0.0f)
////#define FILTER_ALPHA_COEFF_DOWN       (0.9f)
////#define FILTER_ALPHA_COEFF_DIF        (0.98f)
////#define FILTER_DIF_DEGREE_MULTI       (5.0f)

#define FILTER_ALPHA_COEFF_SMOOTH	  (0.98f)
#define FILTER_ALPHA_COEFF_RISE       (0.0f)
#define FILTER_ALPHA_COEFF_DOWN       (0.9f)
#define FILTER_ALPHA_COEFF_MDY        (0.4f)
#define FILTER_ALPHA_COEFF_DIF        (0.98f)
#define FILTER_DIF_DEGREE_MULTI       (5.0f)
#define FILTER_LOW_NOISE_THD          (0.003f)
#define FILTER_FILST_REF_LENGTH       (30)
#define FILTER_REVB_DOWN_LENGTH       (1000)
#define FILTER_REVB_RISE_LENGTH       (500)

CFilter::CFilter(void)
{
}

CFilter::~CFilter(void)
{
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Parameter: INT * pswDataIn输入数据
// Parameter: INT nLen数据点个数
// Parameter: INT * pswDataOut输出数据,空间须先分配
// Comment(2015-4-24):
////////////////////////////////////////////////////////////////////////////////
void CFilter::Filter( INT* pswDataIn, INT nLen, INT* pswDataOut)
{
	float fAlphaDif = FILTER_ALPHA_COEFF_DIF;
	float fDif = 0, fAlpha = 0;
	int swLen ,swCnt,swMax;// , *pswDataIn=NULL, *pswDataOut=NULL;
	int swFlagCnt, swIndex, *pswFlagIndex=NULL;
	float *pfBufEnv=NULL,*pfBufAmp=NULL;
//	float fAlphaDif = FILTER_ALPHA_COEFF_DIF;
	float fAlphaNew = 0;
	int swInitValue, swDifValue;
	float fRec = ENVELOPE_REC_COEFF;
	////float fAlp = FILTER_ALPHA_COEFF;
	swLen = nLen;
	pfBufEnv = (float  *) malloc(swLen *sizeof(float )); 
	pfBufAmp = (float  *) malloc(swLen *sizeof(float )); 
	pswFlagIndex = (int *) malloc(swLen *sizeof(int)); 


	//float *pfBufEnv=NULL;
	//float fAlphaDif = FILTER_ALPHA_COEFF_DIF;
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	swInitValue = pswDataIn[0];

	// 幅值颠倒 
	swMax =  pswDataIn[0];
	for(swCnt =1;swCnt<swLen;swCnt++){
		if(swMax<pswDataIn[swCnt]){
			swMax = pswDataIn[swCnt];
		}
	}
	for(swCnt =0;swCnt<swLen;swCnt++){
		pswDataIn[swCnt] = swMax -pswDataIn[swCnt];
	}

	// 滤波
	fDif      = 0;
	fAlpha    = 0;
	fAlphaNew = 0;
	swFlagCnt = 0;
	pfBufEnv[0] = pswDataIn[0];

	for (swCnt =1; swCnt<FILTER_FILST_REF_LENGTH; swCnt++){
		pfBufEnv[swCnt] = pswDataIn[swCnt];
		fDif = fAlphaDif * fDif + (1-fAlphaDif) * abs(pswDataIn[swCnt]-pswDataIn[swCnt-1]);
	}

	for(swCnt =FILTER_FILST_REF_LENGTH;swCnt<swLen;swCnt++){

		if (pswDataIn[swCnt] >= pswDataIn[swCnt-1])
		{	
			if((pswDataIn[swCnt]-pfBufEnv[swCnt-1]) > FILTER_DIF_DEGREE_MULTI*fDif)
			{
				int i;
				int flag = 1;
				for (i=0; (i<FILTER_REVB_RISE_LENGTH)&&(swCnt-i>0); i++)
				{
					if((pswDataIn[swCnt]-pfBufEnv[swCnt-i]) < FILTER_DIF_DEGREE_MULTI*fDif)
					{
						flag = 0;
						break;
					}
				}
				if (1==flag)
				{
					fAlphaNew = FILTER_ALPHA_COEFF_RISE;
					fAlpha = fAlpha *0.00 + fAlphaNew *(1-0.00);
					pswFlagIndex[swFlagCnt++] = swCnt;
				}
				else
				{
					fAlphaNew = FILTER_ALPHA_COEFF_SMOOTH;	
					fAlpha = fAlpha *0.98 + fAlphaNew *(1-0.98);	
				}
			}
			else
			{
				fAlphaNew = FILTER_ALPHA_COEFF_SMOOTH;	
				fAlpha = fAlpha *0.98 + fAlphaNew *(1-0.98);	
			}
		}
		else
		{
			int flag = 1;
			int i;
			for (i=swCnt+1; ((i<swCnt+FILTER_REVB_DOWN_LENGTH)&&(i<swLen)); i++)
			{
				if (pswDataIn[i]>pswDataIn[swCnt])
				{
					flag = 0;
					break;
				}
			}

			if (1==flag)
			{
				fAlphaNew = 0;
				fAlpha = fAlpha *0.00 + fAlphaNew *(1-0.00);
			}
			else
			{
				if ((pswDataIn[swCnt]-pfBufEnv[swCnt-1])<-FILTER_DIF_DEGREE_MULTI*fDif)
				{
					fAlphaNew = FILTER_ALPHA_COEFF_DOWN;
					fAlpha = fAlpha *0.00 + fAlphaNew *(1-0.0);
				}
				else
				{
					fAlphaNew = FILTER_ALPHA_COEFF_SMOOTH;	
					fAlpha = fAlpha *0.9 + fAlphaNew *(1-0.9);	
				}
			}
		}

		fDif = fAlphaDif * fDif + (1-fAlphaDif) * abs(pswDataIn[swCnt]-pswDataIn[swCnt-1]);
		pfBufEnv[swCnt]= pfBufEnv[swCnt-1] * fAlpha + pswDataIn[swCnt] * (1-fAlpha);

		if (fDif < pfBufEnv[swCnt]*FILTER_LOW_NOISE_THD)
		{
			pfBufEnv[swCnt] = pswDataIn[swCnt];
		}
	}

	for (swIndex = 0; swIndex < swFlagCnt; swIndex++)
	{
		swCnt = pswFlagIndex[swIndex];

		while ((pfBufEnv[swCnt+1]<pswDataIn[swCnt+1]) && (swCnt<(swLen-1)))
		{
			swCnt++;
		}

		while ((pfBufEnv[swCnt+1]>pswDataIn[swCnt+1]) && (swCnt<(swLen-1)))
		{
			pfBufEnv[swCnt+1] = pfBufEnv[swCnt]*FILTER_ALPHA_COEFF_MDY + pswDataIn[swCnt+1]*(1-FILTER_ALPHA_COEFF_MDY);
			swCnt++;
		}
	}

	// 输出
	for(swCnt =0;swCnt<swLen;swCnt++){
		pswDataOut[swCnt]= (int)(pfBufEnv[swCnt]);
	}

	// 幅值颠倒 
	swMax =  pswDataOut[0];
	for(swCnt =1;swCnt<swLen;swCnt++){
		if(swMax<pswDataOut[swCnt]){
			swMax = pswDataOut[swCnt];
		}
	}
	for(swCnt =0;swCnt<swLen;swCnt++){
		pswDataOut[swCnt] = swMax -pswDataOut[swCnt];
	}

	swDifValue = swInitValue - pswDataOut[0];
	for(swCnt =0;swCnt<swLen;swCnt++){
		pswDataOut[swCnt] = pswDataOut[swCnt] + swDifValue;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	delete[] pfBufEnv;
	delete[] pfBufAmp;
}
////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////// Access:    public 
////// Returns:   void
////// Parameter: INT * pswDataIn输入数据
////// Parameter: INT nLen数据点个数
////// Parameter: INT * pswDataOut输出数据,空间须先分配
////// Comment(2015-4-7):
////////////////////////////////////////////////////////////////////////////////////
////void CFilter::Filter( INT* pswDataIn, INT nLen, INT* pswDataOut)
////{
////	float fAlphaDif = FILTER_ALPHA_COEFF_DIF;
////	float fDif = 0, fAlpha = 0;
////	int swLen ,swCnt,swMax;// , *pswDataIn=NULL, *pswDataOut=NULL;
////	float *pfBufEnv=NULL,*pfBufSmo=NULL;
////	float fRec = ENVELOPE_REC_COEFF ;
////	float fAlp = FILTER_ALPHA_COEFF;
////	swLen = nLen;
////	pfBufEnv = (float  *) malloc(swLen *sizeof(float )); 
////	pfBufSmo = (float  *) malloc(swLen *sizeof(float )); 
////
////	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////	// 幅值颠倒 
////	swMax =  pswDataIn[0];
////	for(swCnt =1;swCnt<swLen;swCnt++){
////		if(swMax<pswDataIn[swCnt]){
////			swMax = pswDataIn[swCnt];
////		}
////	}
////	for(swCnt =0;swCnt<swLen;swCnt++){
////		pswDataIn[swCnt] = swMax -pswDataIn[swCnt];
////	}
////
////	// 滤波
////	fDif        = 0;
////	fAlpha      = 0;
////	pfBufEnv[0] = 	pswDataIn[0];
////	for(swCnt =1;swCnt<swLen;swCnt++){
////
////		fDif = fAlphaDif * fDif + (1-fAlphaDif) * abs(pswDataIn[swCnt]-pswDataIn[swCnt-1]);
////
////		if((pswDataIn[swCnt]-pfBufEnv[swCnt-1]) > FILTER_DIF_DEGREE_MULTI*fDif){
////			fAlpha = FILTER_ALPHA_COEFF_RISE;
////		}
////		else if ((pswDataIn[swCnt]-pfBufEnv[swCnt-1])<-FILTER_DIF_DEGREE_MULTI*fDif)
////		{
////			fAlpha = FILTER_ALPHA_COEFF_DOWN;
////
////		} 
////		else{
////			fAlpha = FILTER_ALPHA_COEFF_SMOOTH;		
////		}
////
////		pfBufEnv[swCnt]= pfBufEnv[swCnt-1] * fAlpha + pswDataIn[swCnt] * (1-fAlpha);
////	}
////
////	// 输出
////	for(swCnt =0;swCnt<swLen;swCnt++){
////		pswDataOut[swCnt]= (int)(pfBufEnv[swCnt]);
////	}
////
////	// 幅值颠倒 
////	swMax =  pswDataOut[0];
////	for(swCnt =1;swCnt<swLen;swCnt++){
////		if(swMax<pswDataOut[swCnt]){
////			swMax = pswDataOut[swCnt];
////		}
////	}
////	for(swCnt =0;swCnt<swLen;swCnt++){
////		pswDataOut[swCnt] = swMax -pswDataOut[swCnt];
////	}
////	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////	delete[] pfBufEnv;
////	delete[] pfBufSmo;
////}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Parameter: INT * pIn:输入数据
// Parameter: INT nLen:数据点个数
// Parameter: INT * pOut:输出数据,空间须先分配
// Comment(2015-3-31):
////////////////////////////////////////////////////////////////////////////////
////void CFilter::Filter( INT* pswDataIn, INT nLen, INT* pswDataOut)
////{
////	int swLen ,swCnt,swMax;// , *pswDataIn=NULL, *pswDataOut=NULL;
////	float *pfBufEnv=NULL,*pfBufSmo=NULL;
////	float fRec = ENVELOPE_REC_COEFF ;
////	float fAlp = FILTER_ALPHA_COEFF;
////	swLen = nLen;
////	pfBufEnv = (float  *) malloc(swLen *sizeof(float )); 
////	pfBufSmo = (float  *) malloc(swLen *sizeof(float )); 
////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////	// 幅值颠倒 
////
////	swMax =  pswDataIn[0];
////	for(swCnt =1;swCnt<swLen;swCnt++){
////		if(swMax<pswDataIn[swCnt]){
////			swMax = pswDataIn[swCnt];
////		}
////	}
////	for(swCnt =0;swCnt<swLen;swCnt++){
////		pswDataIn[swCnt] = swMax -pswDataIn[swCnt];
////	}
////
////	// 自适应包络
////
////	pfBufEnv[0] = 	pswDataIn[0];
////	for(swCnt =1;swCnt<swLen;swCnt++){
////		if(pswDataIn[swCnt]>pfBufEnv[swCnt-1]){
////			pfBufEnv[swCnt]= pswDataIn[swCnt];
////		}
////		else{
////			pfBufEnv[swCnt]= pfBufEnv[swCnt-1]*fRec/(fRec+1);
////		} 
////	}
////
////	// 滤波
////	pfBufSmo[0] = 	pfBufEnv[0];
////	for(swCnt =1;swCnt<swLen;swCnt++){
////		pfBufSmo[swCnt]= pfBufSmo[swCnt-1]* fAlp + pfBufEnv[swCnt]* (1-fAlp );
////	}
////
////	// 输出
////	for(swCnt =0;swCnt<swLen;swCnt++){
////		pswDataOut[swCnt]= (int)(pfBufSmo[swCnt]);
////	}
////
////	// 幅值颠倒 
////
////	swMax =  pswDataOut[0];
////	for(swCnt =1;swCnt<swLen;swCnt++){
////		if(swMax<pswDataOut[swCnt]){
////			swMax = pswDataOut[swCnt];
////		}
////	}
////	for(swCnt =0;swCnt<swLen;swCnt++){
////		pswDataOut[swCnt] = swMax -pswDataOut[swCnt];
////	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////	delete[] pfBufEnv;
////	delete[] pfBufSmo;
////}