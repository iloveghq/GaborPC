// gabor_dll_PC.h : gabor_dll_PC DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "../gabor_dll/GaborResult.h"
#include "../gabor_dll/ExportFun.h"


// Cgabor_dll_PCApp
// �йش���ʵ�ֵ���Ϣ������� gabor_dll_PC.cpp
//

class Cgabor_dll_PCApp : public CWinApp
{
public:
	Cgabor_dll_PCApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
