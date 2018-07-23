// Do_Reg.h : main header file for the DO_REG application
//

#if !defined(AFX_DO_REG_H__C6F75689_2372_425A_B925_DC4338DE14CC__INCLUDED_)
#define AFX_DO_REG_H__C6F75689_2372_425A_B925_DC4338DE14CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDo_RegApp:
// See Do_Reg.cpp for the implementation of this class
//

class CDo_RegApp : public CWinApp
{
public:
	CDo_RegApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDo_RegApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDo_RegApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DO_REG_H__C6F75689_2372_425A_B925_DC4338DE14CC__INCLUDED_)
