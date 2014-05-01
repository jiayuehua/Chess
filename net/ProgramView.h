// ProgramView.h : interface of the CProgramView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROGRAMVIEW_H__22F10A72_B1F1_4B65_B90D_0E71881531E7__INCLUDED_)
#define AFX_PROGRAMVIEW_H__22F10A72_B1F1_4B65_B90D_0E71881531E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Chat.h"

class CProgramView : public CView
{
protected: // create from serialization only
	CProgramView();
	DECLARE_DYNCREATE(CProgramView)

// Attributes
public:
	CProgramDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgramView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CProgramView();
	CChat talk;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CProgramView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ProgramView.cpp
inline CProgramDoc* CProgramView::GetDocument()
   { return (CProgramDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRAMVIEW_H__22F10A72_B1F1_4B65_B90D_0E71881531E7__INCLUDED_)
