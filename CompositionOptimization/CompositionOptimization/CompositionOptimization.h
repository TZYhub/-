
// CompositionOptimization.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCompositionOptimizationApp:
// �йش����ʵ�֣������ CompositionOptimization.cpp
//

class CCompositionOptimizationApp : public CWinApp
{
public:
	CCompositionOptimizationApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCompositionOptimizationApp theApp;