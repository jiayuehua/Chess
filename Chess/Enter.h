#if !defined(AFX_ENTER_H__D14A90A6_E0BC_48B5_9580_890B47AE8B90__INCLUDED_)
#define AFX_ENTER_H__D14A90A6_E0BC_48B5_9580_890B47AE8B90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Enter.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEnter dialog

class CEnter : public CDialog
{
// Construction
public:
	CEnter(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEnter)
	enum { IDD = IDD_DIALOG1 };
	//}}AFX_DATA
	bool control;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnter)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEnter)
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENTER_H__D14A90A6_E0BC_48B5_9580_890B47AE8B90__INCLUDED_)
