// gabor_dll_PC.h : gabor_dll_PC DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include "../gabor_dll/GaborResult.h"
#include "../gabor_dll/ExportFun.h"


// Cgabor_dll_PCApp
// 有关此类实现的信息，请参阅 gabor_dll_PC.cpp
//

class Cgabor_dll_PCApp : public CWinApp
{
public:
	Cgabor_dll_PCApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
