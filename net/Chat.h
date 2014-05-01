#if !defined(AFX_CHAT_H__6BACA3E9_964D_4AB5_A92B_EB92D9F7D68C__INCLUDED_)
#define AFX_CHAT_H__6BACA3E9_964D_4AB5_A92B_EB92D9F7D68C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Chat.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// CChat dialog

class CChat : public CDialog
{
// Construction
public:
	CChat(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChat)
	enum { IDD = IDD_DIALOG3 };
	CString	m_Gets;
	CString	m_Puts;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChat)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChat)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHAT_H__6BACA3E9_964D_4AB5_A92B_EB92D9F7D68C__INCLUDED_)
