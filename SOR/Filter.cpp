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
	//m_paramInfo.m_ENVELOPE_REC_COEFF= ENVELOPE_REC_COEFF;//ENVELOPE_REC_COEFF 	(99.0f)
	m_paramInfo.m_ALPHA_COEFF_SMOOTH = FILTER_ALPHA_COEFF_SMOOTH;//	  (0.98f)
	m_paramInfo.m_ALPHA_COEFF_RISE = FILTER_ALPHA_COEFF_RISE;//       (0.0f)
	m_paramInfo.m_ALPHA_COEFF_DOWN = FILTER_ALPHA_COEFF_DOWN;//       (0.9f)
	m_paramInfo.m_ALPHA_COEFF_MDY = FILTER_ALPHA_COEFF_MDY;//        (0.4f)
	m_paramInfo.m_ALPHA_COEFF_DIF = FILTER_ALPHA_COEFF_DIF;//        (0.98f)
	m_paramInfo.m_DIF_DEGREE_MULTI = FILTER_DIF_DEGREE_MULTI;//       (5.0f)
	m_paramInfo.m_LOW_NOISE_THD = FILTER_LOW_NOISE_THD;//          (0.003f)
	m_paramInfo.m_nFILST_REF_LENGTH = FILTER_FILST_REF_LENGTH;//       (30)
	m_paramInfo.m_nREVB_DOWN_LENGTH = FILTER_REVB_DOWN_LENGTH;//       (1000)
	m_paramInfo.m_nREVB_RISE_LENGTH = FILTER_REVB_RISE_LENGTH;//       (500)
}

CFilter::~CFilter(void)
{
}




int MedianFilter(int *pswData, int swLen)
{
	int swCnt, swCntI, swCntJ;
	int swMedIndex;
	int swIndex;

	int  swMax;
	int *pswX;

	swMedIndex = (int)((swLen-1)/2);

	/* 拷贝数据到排序内存中 */
	pswX = (int*)malloc(swLen*sizeof(int));

	for (swCnt=0; swCnt<swLen; swCnt++)
	{
		pswX[swCnt] = pswData[swCnt];
	}

	/* 采用冒泡排序选出第indexH大的值 */
	for (swCntI=0; swCntI<swMedIndex; swCntI++)
	{
		swIndex = swLen-1;
		swMax    = pswX[swIndex];
		
		for (swCntJ=swLen-2; swCntJ>=swCntI; swCntJ--)
		{
			if (pswX[swCntJ]>swMax)
			{
				swMax   = pswX[swCntJ];
				swIndex = swCntJ;
			}
		}
		pswX[swIndex] = pswX[swCntI];
		pswX[swCntI]  = swMax;
	}

	free(pswX);

	return swMax;
}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Parameter: INT * pswDataIn
// Parameter: INT nLen
// Parameter: INT * pswDataOut
// Comment(2015-9-17):
////////////////////////////////////////////////////////////////////////////////
void CFilter::Filter( INT* pswDataIn, INT nLen, INT* pswDataOut)
{
	float fAlphaDif = m_paramInfo.m_ALPHA_COEFF_DIF;
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

	memset(pfBufEnv, 0, swLen*4);//wcq
	memset(pfBufAmp, 0, swLen*4);//wcq
	memset(pswFlagIndex, 0, swLen*4);//wcq

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

	//FILE *fp_in=fopen("data_in.dat","wb");
	//fwrite(pswDataIn, sizeof(int), nLen, fp_in);
	//fclose(fp_in);

	int swWinLen  = 11;
	int swHalfLen = (int)((swWinLen-1)/2);

	for (swCnt =0;swCnt<swWinLen;swCnt++)
	{
		pfBufEnv[swCnt] = pswDataIn[swCnt];
	}
	
	for (;swCnt<swLen-swHalfLen;swCnt++)
	{
		pfBufEnv[swCnt] = (float)MedianFilter(&(pswDataIn[swCnt-swHalfLen]), swWinLen);
	}

	for (;swCnt<swLen;swCnt++)
	{
		pfBufEnv[swCnt] = pswDataIn[swCnt];
	}

#if 0
	// 滤波
	fDif      = 0;
	fAlpha    = 0;
	fAlphaNew = 0;
	swFlagCnt = 0;
	pfBufEnv[0] = pswDataIn[0];

	for (swCnt =1; swCnt<m_paramInfo.m_nFILST_REF_LENGTH; swCnt++){
		pfBufEnv[swCnt] = pswDataIn[swCnt];
		fDif = fAlphaDif * fDif + (1-fAlphaDif) * abs(pswDataIn[swCnt]-pswDataIn[swCnt-1]);
	}

	for(swCnt =m_paramInfo.m_nFILST_REF_LENGTH;swCnt<swLen;swCnt++){

		if (pswDataIn[swCnt] >= pswDataIn[swCnt-1])
		{	
			if((pswDataIn[swCnt]-pfBufEnv[swCnt-1]) > m_paramInfo.m_DIF_DEGREE_MULTI*fDif)
			{
				int i;
				int flag = 1;
				for (i=0; (i<m_paramInfo.m_nREVB_RISE_LENGTH)&&(swCnt-i>0); i++)
				{
					if((pswDataIn[swCnt]-pfBufEnv[swCnt-i]) < m_paramInfo.m_DIF_DEGREE_MULTI*fDif)
					{
						flag = 0;
						break;
					}
				}
				if (1==flag)
				{
					fAlphaNew = m_paramInfo.m_ALPHA_COEFF_RISE;
					fAlpha = fAlpha *0.00 + fAlphaNew *(1-0.00);
					pswFlagIndex[swFlagCnt++] = swCnt;
				}
				else
				{
					fAlphaNew = m_paramInfo.m_ALPHA_COEFF_SMOOTH;	
					fAlpha = fAlpha *0.98 + fAlphaNew *(1-0.98);	
				}
			}
			else
			{
				fAlphaNew = m_paramInfo.m_ALPHA_COEFF_SMOOTH;	
				fAlpha = fAlpha *0.98 + fAlphaNew *(1-0.98);	
			}
		}
		else
		{
			int flag = 1;
			int i;
			for (i=swCnt+1; ((i<swCnt+m_paramInfo.m_nREVB_DOWN_LENGTH)&&(i<swLen)); i++)
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
				if ((pswDataIn[swCnt]-pfBufEnv[swCnt-1])<-m_paramInfo.m_DIF_DEGREE_MULTI*fDif)
				{
					fAlphaNew = m_paramInfo.m_ALPHA_COEFF_DOWN;
					fAlpha = fAlpha *0.00 + fAlphaNew *(1-0.0);
				}
				else
				{
					fAlphaNew = m_paramInfo.m_ALPHA_COEFF_SMOOTH;	
					fAlpha = fAlpha *0.9 + fAlphaNew *(1-0.9);	
				}
			}
		}

		fDif = fAlphaDif * fDif + (1-fAlphaDif) * abs(pswDataIn[swCnt]-pswDataIn[swCnt-1]);
		pfBufEnv[swCnt]= pfBufEnv[swCnt-1] * fAlpha + pswDataIn[swCnt] * (1-fAlpha);

		if (fDif < pfBufEnv[swCnt]*m_paramInfo.m_LOW_NOISE_THD)
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
			pfBufEnv[swCnt+1] = pfBufEnv[swCnt]*m_paramInfo.m_ALPHA_COEFF_MDY + pswDataIn[swCnt+1]*(1-m_paramInfo.m_ALPHA_COEFF_MDY);
			swCnt++;
		}
	}
#endif


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
	delete[] pswFlagIndex;
}

////////// Comment(2015-08-04):
////////////////////////////////////////////////////////////////////////////////////////
////////void CFilter::Filter( INT* pswDataIn, INT nLen, INT* pswDataOut)
////////{
////////	float fAlphaDif = FILTER_ALPHA_COEFF_DIF;
////////	float fDif = 0, fAlpha = 0;
////////	int swLen ,swCnt,swMax;// , *pswDataIn=NULL, *pswDataOut=NULL;
////////	int swFlagCnt, swIndex, *pswFlagIndex=NULL;
////////	float *pfBufEnv=NULL,*pfBufAmp=NULL;
////////	//	float fAlphaDif = FILTER_ALPHA_COEFF_DIF;
////////	float fAlphaNew = 0;
////////	int swInitValue, swDifValue;
////////	float fRec = ENVELOPE_REC_COEFF;
////////	////float fAlp = FILTER_ALPHA_COEFF;
////////	swLen = nLen;
////////	pfBufEnv = (float  *) malloc(swLen *sizeof(float )); 
////////	pfBufAmp = (float  *) malloc(swLen *sizeof(float )); 
////////	pswFlagIndex = (int *) malloc(swLen *sizeof(int)); 
////////
////////	//float *pfBufEnv=NULL;
////////	//float fAlphaDif = FILTER_ALPHA_COEFF_DIF;
////////	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////
////////	swInitValue = pswDataIn[0];
////////
////////	// 幅值颠倒 
////////	swMax =  pswDataIn[0];
////////	for(swCnt =1;swCnt<swLen;swCnt++){
////////		if(swMax<pswDataIn[swCnt]){
////////			swMax = pswDataIn[swCnt];
////////		}
////////	}
////////	for(swCnt =0;swCnt<swLen;swCnt++){
////////		pswDataIn[swCnt] = swMax -pswDataIn[swCnt];
////////	}
////////
////////	//FILE *fp_in=fopen("data_in.dat","wb");
////////	//fwrite(pswDataIn, sizeof(int), nLen, fp_in);
////////	//fclose(fp_in);
////////
////////	int swWinLen  = 11;
////////	int swHalfLen = (int)((swWinLen-1)/2);
////////
////////	for (swCnt =0;swCnt<swWinLen;swCnt++)
////////	{
////////		pfBufEnv[swCnt] = pswDataIn[swCnt];
////////	}
////////
////////	for (;swCnt<swLen-swHalfLen;swCnt++)
////////	{
////////		pfBufEnv[swCnt] = (float)MedianFilter(&(pswDataIn[swCnt-swHalfLen]), swWinLen);
////////	}
////////
////////	for (;swCnt<swLen;swCnt++)
////////	{
////////		pfBufEnv[swCnt] = pswDataIn[swCnt];
////////	}
////////
////////#if 0
////////	// 滤波
////////	fDif      = 0;
////////	fAlpha    = 0;
////////	fAlphaNew = 0;
////////	swFlagCnt = 0;
////////	pfBufEnv[0] = pswDataIn[0];
////////
////////	for (swCnt =1; swCnt<FILTER_FILST_REF_LENGTH; swCnt++){
////////		pfBufEnv[swCnt] = pswDataIn[swCnt];
////////		fDif = fAlphaDif * fDif + (1-fAlphaDif) * abs(pswDataIn[swCnt]-pswDataIn[swCnt-1]);
////////	}
////////
////////	for(swCnt =FILTER_FILST_REF_LENGTH;swCnt<swLen;swCnt++){
////////
////////		if (pswDataIn[swCnt] >= pswDataIn[swCnt-1])
////////		{	
////////			if((pswDataIn[swCnt]-pfBufEnv[swCnt-1]) > FILTER_DIF_DEGREE_MULTI*fDif)
////////			{
////////				int i;
////////				int flag = 1;
////////				for (i=0; (i<FILTER_REVB_RISE_LENGTH)&&(swCnt-i>0); i++)
////////				{
////////					if((pswDataIn[swCnt]-pfBufEnv[swCnt-i]) < FILTER_DIF_DEGREE_MULTI*fDif)
////////					{
////////						flag = 0;
////////						break;
////////					}
////////				}
////////				if (1==flag)
////////				{
////////					fAlphaNew = FILTER_ALPHA_COEFF_RISE;
////////					fAlpha = fAlpha *0.00 + fAlphaNew *(1-0.00);
////////					pswFlagIndex[swFlagCnt++] = swCnt;
////////				}
////////				else
////////				{
////////					fAlphaNew = FILTER_ALPHA_COEFF_SMOOTH;	
////////					fAlpha = fAlpha *0.98 + fAlphaNew *(1-0.98);	
////////				}
////////			}
////////			else
////////			{
////////				fAlphaNew = FILTER_ALPHA_COEFF_SMOOTH;	
////////				fAlpha = fAlpha *0.98 + fAlphaNew *(1-0.98);	
////////			}
////////		}
////////		else
////////		{
////////			int flag = 1;
////////			int i;
////////			for (i=swCnt+1; ((i<swCnt+FILTER_REVB_DOWN_LENGTH)&&(i<swLen)); i++)
////////			{
////////				if (pswDataIn[i]>pswDataIn[swCnt])
////////				{
////////					flag = 0;
////////					break;
////////				}
////////			}
////////
////////			if (1==flag)
////////			{
////////				fAlphaNew = 0;
////////				fAlpha = fAlpha *0.00 + fAlphaNew *(1-0.00);
////////			}
////////			else
////////			{
////////				if ((pswDataIn[swCnt]-pfBufEnv[swCnt-1])<-FILTER_DIF_DEGREE_MULTI*fDif)
////////				{
////////					fAlphaNew = FILTER_ALPHA_COEFF_DOWN;
////////					fAlpha = fAlpha *0.00 + fAlphaNew *(1-0.0);
////////				}
////////				else
////////				{
////////					fAlphaNew = FILTER_ALPHA_COEFF_SMOOTH;	
////////					fAlpha = fAlpha *0.9 + fAlphaNew *(1-0.9);	
////////				}
////////			}
////////		}
////////
////////		fDif = fAlphaDif * fDif + (1-fAlphaDif) * abs(pswDataIn[swCnt]-pswDataIn[swCnt-1]);
////////		pfBufEnv[swCnt]= pfBufEnv[swCnt-1] * fAlpha + pswDataIn[swCnt] * (1-fAlpha);
////////
////////		if (fDif < pfBufEnv[swCnt]*FILTER_LOW_NOISE_THD)
////////		{
////////			pfBufEnv[swCnt] = pswDataIn[swCnt];
////////		}
////////	}
////////
////////	for (swIndex = 0; swIndex < swFlagCnt; swIndex++)
////////	{
////////		swCnt = pswFlagIndex[swIndex];
////////
////////		while ((pfBufEnv[swCnt+1]<pswDataIn[swCnt+1]) && (swCnt<(swLen-1)))
////////		{
////////			swCnt++;
////////		}
////////
////////		while ((pfBufEnv[swCnt+1]>pswDataIn[swCnt+1]) && (swCnt<(swLen-1)))
////////		{
////////			pfBufEnv[swCnt+1] = pfBufEnv[swCnt]*FILTER_ALPHA_COEFF_MDY + pswDataIn[swCnt+1]*(1-FILTER_ALPHA_COEFF_MDY);
////////			swCnt++;
////////		}
////////	}
////////#endif
////////
////////
////////	// 输出
////////	for(swCnt =0;swCnt<swLen;swCnt++){
////////		pswDataOut[swCnt]= (int)(pfBufEnv[swCnt]);
////////	}
////////
////////	// 幅值颠倒 
////////	swMax =  pswDataOut[0];
////////	for(swCnt =1;swCnt<swLen;swCnt++){
////////		if(swMax<pswDataOut[swCnt]){
////////			swMax = pswDataOut[swCnt];
////////		}
////////	}
////////	for(swCnt =0;swCnt<swLen;swCnt++){
////////		pswDataOut[swCnt] = swMax -pswDataOut[swCnt];
////////	}
////////
////////	swDifValue = swInitValue - pswDataOut[0];
////////	for(swCnt =0;swCnt<swLen;swCnt++){
////////		pswDataOut[swCnt] = pswDataOut[swCnt] + swDifValue;
////////	}
////////	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////	delete[] pfBufEnv;
////////	delete[] pfBufAmp;
////////	delete[] pswFlagIndex;
////////}
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