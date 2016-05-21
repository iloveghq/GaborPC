#include "StdAfx.h"
#include "SpinUtil.h"
#include <math.h>

CSpinUtil::CSpinUtil(void)
{
}

CSpinUtil::~CSpinUtil(void)
{
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Parameter: UINT nEditID
// Parameter: INT nPrecision:
// Comment(2015-6-3):
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// Access:    public 
// Returns:   void
// Parameter: UINT nEditID
// Parameter: INT nAdd:1��ʾ+1(�ϰ�),-1��ʾ����1(�°�)
// Parameter: INT nPrecisionС���������Ϊ0��ʾ������1����ʾ���磺0.1; 2��ʾ����:0.2....
// Comment(2015-6-3):���ڵ��spin���޸�edit�ı�
////////////////////////////////////////////////////////////////////////////////
void CSpinUtil::ChangeText( UINT nEditID,INT nAdd,  INT nPrecision /*= 0*/ )
{
	FLOAT fDelta = pow(10.0, -nPrecision);
	CString temp;
	m_pDlg->GetDlgItemText(nEditID, temp);
	if (0 == nPrecision)//����
	{
		INT nCur = 0;
		if (_T("") != temp)
		{
			nCur = _ttoi(temp);
		}//eif
		nCur += -nAdd * fDelta;
		temp.Format(_T("%d"), nCur);
		m_pDlg->SetDlgItemText(nEditID, temp);
	}
	else
	{
		FLOAT fCur = 0;
		if (_T("") != temp)
		{
			fCur = _tstof(temp);
		}//eif
		fCur += -nAdd * fDelta;
		CString strFormat;
		strFormat.Format(_T("%%.%df"), nPrecision);
		temp.Format(strFormat, fCur);
		m_pDlg->SetDlgItemText(nEditID, temp);
	}//eif
}