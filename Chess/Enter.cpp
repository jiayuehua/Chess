// Enter.cpp : implementation file
//

#include "stdafx.h"
#include "Program.h"
#include "Enter.h"
#include "Managers.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


extern	Managers	manager;
/////////////////////////////////////////////////////////////////////////////
// CEnter dialog


CEnter::CEnter(CWnd* pParent /*=NULL*/)
	: CDialog(CEnter::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEnter)
	//}}AFX_DATA_INIT
	control=false;
}


void CEnter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnter)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEnter, CDialog)
	//{{AFX_MSG_MAP(CEnter)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnter message handlers

void CEnter::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	manager.Game_Type=false;
	control=true;
}

void CEnter::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	manager.Game_Type=true;
	control=true;
}


void CEnter::OnOK() 
{
	// TODO: Add extra validation here
	if(control==false)
	{
		MessageBox("请选择一种游戏方式");
		return;
	}
		CDialog::OnOK();
	
}

void CEnter::OnCancel() 
{
	// TODO: Add extra cleanup here
	exit(0);
	CDialog::OnCancel();
}
