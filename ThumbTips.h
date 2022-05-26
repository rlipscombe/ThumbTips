// ThumbTips.h : main header file for the ThumbTips application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


// CThumbTipsApp:
// See ThumbTips.cpp for the implementation of this class
//

class CThumbTipsApp : public CWinApp
{
public:
	CThumbTipsApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CThumbTipsApp theApp;