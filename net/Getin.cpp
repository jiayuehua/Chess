// Getin.cpp : implementation file
//

#include "stdafx.h"
#include "Program.h"
#include "Getin.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGetin dialog


CGetin::CGetin(CWnd* pParent /*=NULL*/)
	: CDialog(CGetin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGetin)
	m_ip = _T("127.0.0.1");
	m_Port = _T("100");
	//}}AFX_DATA_INIT
}


void CGetin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGetin)
	DDX_Text(pDX, IDC_IP, m_ip);
	DDX_Text(pDX, IDC_PORT, m_Port);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGetin, CDialog)
	//{{AFX_MSG_MAP(CGetin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGetin message handlers

void CGetin::OnOK() 
{
	CMainFrame *m_pMF=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	UINT k;
	k=atoi(m_Port);
	if(k<1 || k>60000)
	{
		MessageBox("输入端口无效，采用默认端口","错误");
		m_Port="100";
	}
	CDialog::OnOK();
}
