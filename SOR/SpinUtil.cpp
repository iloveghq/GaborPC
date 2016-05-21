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
// Parameter: INT nAdd:1表示+1(上按),-1表示减少1(下按)
// Parameter: INT nPrecision小数点个数，为0表示整数，1，表示形如：0.1; 2表示形如:0.2....
// Comment(2015-6-3):用于点击spin后修改edit文本
////////////////////////////////////////////////////////////////////////////////
void CSpinUtil::ChangeText( UINT nEditID,INT nAdd,  INT nPrecision /*= 0*/ )
{
	FLOAT fDelta = pow(10.0, -nPrecision);
	CString temp;
	m_pDlg->GetDlgItemText(nEditID, temp);
	if (0 == nPrecision)//整数
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