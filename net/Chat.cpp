// Chat.cpp : implementation file
//

#include "stdafx.h"
#include "Program.h"
#include "Chat.h"
#include "NetControl.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern NetControl netcontrol;
/////////////////////////////////////////////////////////////////////////////
// CChat dialog


CChat::CChat(CWnd* pParent /*=NULL*/)
	: CDialog(CChat::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChat)
	m_Gets = _T("");
	m_Puts = _T("");
	//}}AFX_DATA_INIT
}


void CChat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChat)
	DDX_Text(pDX, IDC_EDIT1, m_Gets);
	DDX_Text(pDX, IDC_EDIT2, m_Puts);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChat, CDialog)
	//{{AFX_MSG_MAP(CChat)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChat message handlers

void CChat::OnButton1() 
{
	UpdateData();
	if(m_Puts=="")
	{
		MessageBox("输入消息不能为空","警告");
		return;
	}
	char st[1000]="";
	UpdateData();
	CTime tim=CTime::GetCurrentTime();
	sprintf(st,"%d:%d:%d\r\n%s",tim.GetHour(),tim.GetMinute(),tim.GetSecond(),m_Puts);
	netcontrol.SendMsg(netcontrol.m_pSocket,st);
	CString tem;
	tem.Format("%s",m_Gets);
	if(m_Gets!="")
		m_Gets.Format("%s\r\n发送信息\t%s",st,tem);
	else
		m_Gets.Format("发送信息\t%s",st);
	m_Puts="";
	UpdateData(false);
}
