// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Program.h"

#include "ProgramDoc.h"
#include "ProgramView.h"

#include "Net.h"
#include "MainFrm.h"
#include "NetControl.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern NetControl netcontrol;
/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_NETCON, OnNetcon)
	ON_COMMAND(ID_KKNDORC, OnKkndorc)
	ON_COMMAND(ID_TALK, OnTalk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	WORD   wVersionRequested;
	WSADATA   wsaData;   
	int   err;   
	wVersionRequested   =   MAKEWORD(   2,   2   );
	err=WSAStartup(   wVersionRequested,   &wsaData   ); 
	if(err!=0)
	{
		MessageBox("ÍøÂçÓÐ¹ÊÕÏ£¬Çë¼ì²éÍøÂçÇé¿ö!");
			return;
	}

	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers




void CMainFrame::OnNetcon() 
{
	// TODO: Add your command handler code here
	netcontrol.OnSorc();
}



void CMainFrame::OnKkndorc() 
{
	// TODO: Add your command handler code here
	netcontrol.SendMsg(netcontrol.m_pSocket,"kknd");	
}

void CMainFrame::OnTalk() 
{
	
	CProgramView *k;
	k=(CProgramView*)GetActiveView();
	talk=&(k->talk);
	netcontrol.talk=talk;
	talk->DoModal();
}
