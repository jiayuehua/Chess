// ProgramView.h : interface of the CProgramView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROGRAMVIEW_H__CD9C5222_3904_4524_ACDE_A1C81393936A__INCLUDED_)
#define AFX_PROGRAMVIEW_H__CD9C5222_3904_4524_ACDE_A1C81393936A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Managers.h"
#include "NetControl.h"
#include "WaveSound.h"	// Added by ClassView

#define	ID_OK		100
#define	ID_LOSE		101
#define	ID_PEACE	102

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
	int	num1;
	int	num2;

	CDC	ChessAll;
	CDC	Buffer;

	CBitmap	m_chessbord;
	CBitmap	m_chess;
	CBitmap	m_mask;
	CBitmap	m_choose;

	CBitmap MemBitmap;

	CButton	m_ok;
	CButton m_lose;
	CButton	m_peace;
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
//	WaveSound m_sound;
	NetControl *m_pControl;
	CString PlayerName[2];
	void OnPeace();
	void OnLose();
	void DrawChoose(int x,int y,CDC *pdc);
	void OnOK();
	void PrintState(CDC *padc);
	void PrintAll();
	int SelectNum(int x,int y);
	void DrawChess(Chess ch,CDC *pdc);
	void DrawStar(int x,int y,CDC *pdc);
	void DrawChessbord(CDC *pdc);
	virtual ~CProgramView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CProgramView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
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

#endif // !defined(AFX_PROGRAMVIEW_H__CD9C5222_3904_4524_ACDE_A1C81393936A__INCLUDED_)
