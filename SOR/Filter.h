#pragma once
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//===========================================================
//滤波算法 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//#define FILTER_ALPHA_COEFF_SMOOTH	  (0.98f)
	//#define FILTER_ALPHA_COEFF_RISE       (0.0f)
	//#define FILTER_ALPHA_COEFF_DOWN       (0.9f)
	//#define FILTER_ALPHA_COEFF_MDY        (0.4f)
	//#define FILTER_ALPHA_COEFF_DIF        (0.98f)
	//#define FILTER_DIF_DEGREE_MULTI       (5.0f)
	//#define FILTER_FILST_REF_LENGTH       (30)
	//#define FILTER_REVB_DOWN_LENGTH       (1000)
//#define FILTER_REVB_RISE_LENGTH       (500)
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

class CFilter
{
public:
	CFilter(void);
	~CFilter(void);
	void Filter(INT* pIn, INT nLen, INT* pOut);//
public:
	struct ParamInfo//wcq2012.02.21
	{//主要记录下上次测试时的一些参数
		ParamInfo()
		{
		}
		FLOAT m_ALPHA_COEFF_SMOOTH;//	  (0.98f)
		FLOAT m_ALPHA_COEFF_RISE;//       (0.0f)
		FLOAT m_ALPHA_COEFF_DOWN;//       (0.9f)
		FLOAT m_ALPHA_COEFF_MDY;//        (0.4f)
		FLOAT m_ALPHA_COEFF_DIF;//        (0.98f)
		FLOAT m_DIF_DEGREE_MULTI;//       (5.0f)
		FLOAT m_LOW_NOISE_THD;//    (0.003f)
		INT m_nFILST_REF_LENGTH;//       (30)
		INT m_nREVB_DOWN_LENGTH;//       (1000)
		INT m_nREVB_RISE_LENGTH;//       (500)
	}m_paramInfo;
};
