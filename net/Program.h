// Program.h : main header file for the PROGRAM application
//

#if !defined(AFX_PROGRAM_H__FF9459A9_FCF2_46B9_8E9E_659CE1129EB5__INCLUDED_)
#define AFX_PROGRAM_H__FF9459A9_FCF2_46B9_8E9E_659CE1129EB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CProgramApp:
// See Program.cpp for the implementation of this class
//

class CProgramApp : public CWinApp
{
public:
	CProgramApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgramApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CProgramApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRAM_H__FF9459A9_FCF2_46B9_8E9E_659CE1129EB5__INCLUDED_)