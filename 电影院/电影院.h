
// ��ӰԺ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��ӰԺApp: 
// �йش����ʵ�֣������ ��ӰԺ.cpp
//

class C��ӰԺApp : public CWinApp
{
public:
	C��ӰԺApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��ӰԺApp theApp;