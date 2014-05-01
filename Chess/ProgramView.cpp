// ProgramView.cpp : implementation of the CProgramView class
//

#include "stdafx.h"
#include "Program.h"
#include "Managers.h"
#include "ProgramDoc.h"
#include "ProgramView.h"
#include "Netcontrol.h"
#include "Chess.h"
#include "Enter.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern Managers manager;
/////////////////////////////////////////////////////////////////////////////
// CProgramView

IMPLEMENT_DYNCREATE(CProgramView, CView)

BEGIN_MESSAGE_MAP(CProgramView, CView)
	//{{AFX_MSG_MAP(CProgramView)
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(ID_OK,OnOK)
	ON_BN_CLICKED(ID_LOSE,OnLose)
	ON_BN_CLICKED(ID_PEACE,OnPeace)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProgramView construction/destruction

CProgramView::CProgramView()
{
	// TODO: add construction code here
/*	manager.nChessinfo[0].color=true;
	manager.nChessinfo[0].type=7;
	manager.nChessinfo[0].x=1;
	manager.nChessinfo[0].y=0;
	manager.nChessinfo[1].color=false;;
	manager.nChessinfo[1].type=7;
	manager.nChessinfo[1].x=0;
	manager.nChessinfo[1].y=0;
	manager.nChessinfo[2].color=true;
	manager.nChessinfo[2].type=2;
//	manager.nChessinfo[2].x=0;
//	manager.nChessinfo[2].y=1;
*/
	PlayerName[0].Format("player1");
	PlayerName[1].Format("player2");
	m_pControl= new NetControl(this);
}

CProgramView::~CProgramView()
{
	Buffer.DeleteDC();
	MemBitmap.DeleteObject();
}

BOOL CProgramView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	m_chessbord.LoadBitmap(IDB_CHESSBORD);
	m_chess.LoadBitmap(IDB_CHESS);
	m_mask.LoadBitmap(IDB_MASK);
	m_choose.LoadBitmap(IDB_CHOOSE);
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CProgramView drawing

void CProgramView::OnDraw(CDC* pDC)
{
	CProgramDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	static	bool	st=true;
	if(st)
	{	
		ChessAll.CreateCompatibleDC(pDC);
		Buffer.CreateCompatibleDC(NULL);
		MemBitmap.CreateCompatibleBitmap(pDC,800,600);
		Buffer.SelectObject(&MemBitmap);
		Buffer.FillSolidRect(0,0,800,600,RGB(255,255,255));
		st=false;
	}
	
//	ChessAll.SelectObject(&m_chessbord);
//	pDC->BitBlt(0,0,800,600,&ChessAll,0,0,SRCCOPY);
//	DrawChessbord();
//	DrawChess(manager.nChessinfo[0]);
//	DrawChess(manager.nChessinfo[1]);
//	ChessAll.SelectObject(&m_choose);
//	pDC->BitBlt(110,45,39,39,&ChessAll,0,0,MERGEPAINT);
//	pDC->BitBlt(110,45,39,39,&ChessAll,39,0,SRCAND);
//	pDC->BitBlt(65,45,39,39,&ChessAll,0,0,MERGEPAINT);
//	pDC->BitBlt(65,45,39,39,&ChessAll,39,0,SRCAND);
//	DrawChess(manager.nChessinfo[2]);
	PrintAll();
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

void CProgramView::DrawChessbord(CDC *pdc)
{
//	CDC *pdc=GetDC();
	CPen chessbord1,chessbord2;
	chessbord1.CreatePen(0,1,RGB(0,0,0));
	chessbord2.CreatePen(0,3,RGB(0,0,0));
	int	i;
	int	k;

	for(i=0;i<2;i++)
	{	
		pdc->SelectObject(&chessbord1);

	//画横线
		for(k=1;k<=4;k++)
		{
			pdc->MoveTo(80,65+k*50+i*4*50);
			pdc->LineTo(80+50*8,65+k*50+i*4*50);
		}
		
	//画竖线
		for(k=1;k<=7;k++)
		{	
			pdc->MoveTo(80+50*k,65+i*5*50);
			pdc->LineTo(80+50*k,65+4*50+i*5*50);
		}
	//画宫
		
		pdc->MoveTo(80+50*3,65+i*7*50);
		pdc->LineTo(80+50*5,65+2*50+i*7*50);
		pdc->MoveTo(80+50*3,65+2*50+i*7*50);
		pdc->LineTo(80+5*50,65+i*7*50);

	//画边框
		if(i==1)
			pdc->SelectObject(&chessbord2);
		pdc->MoveTo(80-i*10,65-i*10);
		pdc->LineTo(80-i*10,65+9*50+i*10);
		pdc->MoveTo(80-i*10,65-i*10);
		pdc->LineTo(80+8*50+i*10,65-i*10);
		pdc->MoveTo(80+8*50+i*10,65-i*10);
		pdc->LineTo(80+8*50+i*10,65+9*50+i*10);
		pdc->MoveTo(80+8*50+i*10,65+9*50+i*10);
		pdc->LineTo(80-i*10,65+9*50+i*10);

	//画星星
		pdc->SelectObject(&chessbord2);
		DrawStar(1,2+i*5,pdc);
		DrawStar(7,2+i*5,pdc);
		DrawStar(2,3+i*3,pdc);
		DrawStar(4,3+i*3,pdc);
		DrawStar(6,3+i*3,pdc);
		DrawStar(0,3+i*3,pdc);
		DrawStar(8,3+i*3,pdc);

	}

	ReleaseDC(pdc);
	chessbord1.DeleteObject();
	chessbord2.DeleteObject();
	
}

void CProgramView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CDC	*pdc=GetDC();
	int	mx=point.x;
	int	my=point.y;
	CString	st;
//	st.Format("%d  ,%d  ",mx,my);
//	pdc->TextOut(5,5,st);
	
	if(mx>=65&&my>=50&&mx<=490&&my<=525)
	{
		int k;
		pdc->TextOut(600,400,st);
		k=SelectNum(mx,my);
		if(manager.Game_State==0||manager.Game_State==1)
		{
			if(manager.DoMsg(k%10,k/10,0))
			{
				num2=k;
				PrintAll();	
			}
			else
			{
				num2=100;
				PrintAll();
			}
		}
	}
	ReleaseDC(pdc);
	CView::OnMouseMove(nFlags, point);
}

void CProgramView::DrawStar(int x, int y,CDC *pdc)
{	
	int m;
	int	n;
	if(x>0&&x<8)
	{
		for(m=-1;m<2;)
		{
				for(n=-1;n<2;)
			{
				pdc->MoveTo(80+50*x+m*5,65+50*y+n*5);
				pdc->LineTo(80+50*x+m*15,65+50*y+n*5);
				pdc->MoveTo(80+50*x+m*5,65+50*y+n*5);
				pdc->LineTo(80+50*x+m*5,65+50*y+n*15);
				n+=2;
			}
				m+=2;
		}
	}
	else if(x==0)
	{
		for(m=-1;m<2;)
		{
			pdc->MoveTo(80+5,65+50*y+m*5);
			pdc->LineTo(80+5,65+50*y+m*20);
			pdc->MoveTo(80+5,65+50*y+m*5);
			pdc->LineTo(80+5+15,65+50*y+m*5);
			m+=2;
		}
	}
	else if(x==8)
	{
		for(m=-1;m<2;)
		{
			pdc->MoveTo(80+8*50-5,65+50*y+m*5);
			pdc->LineTo(80+8*50-5,65+50*y+m*20);
			pdc->MoveTo(80+8*50-5,65+50*y+m*5);
			pdc->LineTo(80+8*50-20,65+50*y+m*5);
			m+=2;
		}
	}
}

int CProgramView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
		
	// TODO: Add your specialized creation code here
	CEnter	dlg;
	dlg.DoModal();
	
	int	k;
	if(manager.Game_Type)
	{
		m_pControl->OnSorc();
		if(m_pControl->m_Isserver)
		{
			k=MessageBox("是否选择先手(Y/N)","象棋",MB_OKCANCEL);
			if(k==IDOK)
			{
				manager.PlayerAc=0;
			}
			else if(k==IDCANCEL)
			{
				manager.PlayerAc=1;
			}
		}
		
	}
	m_ok.Create(_T("开始"), WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
		CRect(615,355,715,395), this, ID_OK);
	m_lose.Create(_T("认输"), WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
		CRect(615,305,715,345), this, ID_LOSE);
	m_peace.Create(_T("和棋"), WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
		CRect(615,255,715,295), this, ID_PEACE);
	m_ok.ShowWindow(SW_SHOW);
	m_lose.ShowWindow(SW_SHOW);
	m_peace.ShowWindow(SW_SHOW);
	return 0;
}

void CProgramView::DrawChess(Chess ch,CDC *pdc)
{
	if(!ch.color)
	{
		ChessAll.SelectObject(m_mask);
		pdc->BitBlt(60+ch.x*50,45+ch.y*50,39,39,&ChessAll,(7-ch.type)*39,0,MERGEPAINT);
		ChessAll.SelectObject(m_chess);
		pdc->BitBlt(60+ch.x*50,45+ch.y*50,39,39,&ChessAll,(7-ch.type)*39,0,SRCAND);
	}
	else
	{
		ChessAll.SelectObject(m_mask);
		pdc->BitBlt(60+ch.x*50,45+ch.y*50,39,39,&ChessAll,(7-ch.type)*39,39,MERGEPAINT);
		ChessAll.SelectObject(m_chess);
		pdc->BitBlt(60+ch.x*50,45+ch.y*50,39,39,&ChessAll,(7-ch.type)*39,39,SRCAND);
	}
}

void CProgramView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int	mx=point.x;
	int	my=point.y;

	CDC *pdc=GetDC();
	CString	st;
	int k;
	if(mx>=65&&my>=50&&mx<=490&&my<=525)
	{
		k=SelectNum(mx,my);
		if(manager.DoMsg(k%10,k/10,1))
		{	
			num1=k;
			PrintAll();	
			if(manager.Game_Type)
				m_pControl->SendAction(k%10,k/10);
			if(manager.Game_State>1)
			{
				m_pControl->m_Ready[0]=false;
				m_pControl->m_Ready[1]=false;
			}
		}
		else
		{
			num1=100;
			PrintAll();
		}
		
		st.Format("%d    ,%d    ",num1%10,num1/10);
		pdc->TextOut(600,5,st);
//		else
//			MessageBox("kknd");
	}
//	PrintAll(pdc);
	ReleaseDC(pdc);
	CView::OnLButtonDown(nFlags, point);
}

int CProgramView::SelectNum(int x, int y)
{
	x = (x-60)/50;
	y = (y-45)/50;

	return	y*10+x;
}

void CProgramView::PrintAll()
{
	CDC *pdc=GetDC();
	ChessAll.SelectObject(&m_chessbord);
	Buffer.BitBlt(0,0,800,600,&ChessAll,0,0,SRCCOPY);
	DrawChessbord(&Buffer);
	int	k(0);
	for(;k<=31;k++)
	{	
		if(manager.nChessinfo[k].type<=7)
				DrawChess(manager.nChessinfo[k],&Buffer);
	}
	if(manager.Game_State!=0&&manager.Game_State!=1)
	{
		num1=100;
		num2=100;
	}
	if(num1<100)
	DrawChoose(num1%10,num1/10,&Buffer);

	if(num2<100)
	DrawChoose(num2%10,num2/10,&Buffer);
	PrintState(&Buffer);
	pdc->BitBlt(0,0,800,600,&Buffer,0,0,SRCCOPY);

//	DrawChess(manager.nChessinfo[1]);
//	ChessAll.SelectObject(&m_choose);
//	pDC->BitBlt(110,45,39,39,&ChessAll,0,0,MERGEPAINT);
//	pDC->BitBlt(110,45,39,39,&ChessAll,39,0,SRCAND);
//	pDC->BitBlt(65,45,39,39,&ChessAll,0,0,MERGEPAINT);
//	pDC->BitBlt(65,45,39,39,&ChessAll,39,0,SRCAND);
//	DrawChess(manager.nChessinfo[2]);
}

void CProgramView::PrintState(CDC *pdc)
{
	CString	st;

	pdc->SetBkMode(TRANSPARENT);
	pdc->SetTextColor(RGB(255,0,0));
	pdc->TextOut(260,15,PlayerName[0]);
	pdc->TextOut(260,545,PlayerName[1]);

	pdc->SetTextColor(RGB(0,0,0,));
	if(manager.Game_State==-1)
		st.Format("游戏还没开始  ");
	else if(manager.Game_State==0)
		st.Format("%s走棋  ",PlayerName[0]);
	else if(manager.Game_State==1)
		st.Format("%s走棋  ",PlayerName[1]);
	else if(manager.Game_State==2)
		st.Format("%s胜利  ",PlayerName[0]);
	else if(manager.Game_State==3)
		st.Format("%s胜利  ",PlayerName[1]);

	pdc->TextOut(610,60,st);
	st.ReleaseBuffer();

}


void CProgramView::OnOK()
{
	if(manager.Game_State==0||manager.Game_State==1)
		return;
	CDC	*pdc=GetDC();
	
	if(manager.Game_Type)
	{
		if(m_pControl->m_pSocket==NULL)
			return;
		m_pControl->m_Ready[0]=true;
		if(m_pControl->m_Ready[0] && m_pControl->m_Ready[1])
		{
			manager.GameStart();
			PrintAll();
		}
		m_pControl->SendMsg("2005");
	}
	else if(!manager.Game_Type)
		manager.GameStart();

	PrintAll();
}

void CProgramView::DrawChoose(int x,int y,CDC *pdc)
{
		ChessAll.SelectObject(&m_choose);
		pdc->BitBlt(60+x*50,45+y*50,39,39,&ChessAll,0,0,MERGEPAINT);
		pdc->BitBlt(60+x*50,45+y*50,39,39,&ChessAll,39,0,SRCAND);
}

void CProgramView::OnLose()
{
	int k;
	k=MessageBox("你真的想认输吗？","",MB_OKCANCEL);
	if(k==1)
	{
		manager.Game_State=(manager.Game_State+1)%2;
		manager.Game_State+=2;
		if(!manager.Game_Type)
			return;
		m_pControl->SendAction(0,0,2);
		m_pControl->m_Ready[0]=false;
		m_pControl->m_Ready[1]=false;
	}
}

void CProgramView::OnPeace()
{	
	int k;
	k=MessageBox("你真的想和棋吗？","",MB_OKCANCEL);
	if(k==1)
	{
		if(!manager.Game_Type)
		{
			manager.Game_State=5;
			return;
		}
		else
		{
			m_pControl->SendAction(0,0,3);
		}
	}
}
