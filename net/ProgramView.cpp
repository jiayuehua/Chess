// ProgramView.cpp : implementation of the CProgramView class
//

#include "stdafx.h"
#include "Program.h"
#include "NetControl.h"
#include "ProgramDoc.h"
#include "ProgramView.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern NetControl netcontrol;
extern CProgramApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CProgramView

IMPLEMENT_DYNCREATE(CProgramView, CView)

BEGIN_MESSAGE_MAP(CProgramView, CView)
	//{{AFX_MSG_MAP(CProgramView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgramView construction/destruction

CProgramView::CProgramView()
{
	// TODO: add construction code here
	netcontrol.OnSorc();
	netcontrol.talk=&talk;
	talk.DoModal();
//	CMainFrame *pFrame;
//	pFrame=(CMainFrame*)(theApp.m_pMainWnd);
}


CProgramView::~CProgramView()
{
}

BOOL CProgramView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CProgramView drawing

void CProgramView::OnDraw(CDC* pDC)
{

	CProgramDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CProgramView diagnostics

#ifdef _DEBUG
void CProgramView::AssertValid() const
{
	CView::AssertValid();
}

void CProgramView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CProgramDoc* CProgramView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CProgramDoc)));
	return (CProgramDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CProgramView message handlers
