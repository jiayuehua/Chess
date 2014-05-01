// NetControl.cpp: implementation of the NetControl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Program.h"
#include "NetControl.h"
#include "ProgramDoc.h"
#include "ProgramView.h"
#include "Managers.h"
#include "Server.h"
#include "Getin.h"
#include "Net.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
extern Managers manager;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
NetControl::NetControl()
{
	m_Ready[0]=false;
	m_Ready[1]=false;
	m_pSocket=NULL;
	m_Server="";
	m_Port=100;
	m_pListening=NULL;
}
NetControl::~NetControl()
{
	if(m_pSocket)
	delete m_pSocket;
	delete m_pListening;
}
void NetControl::FetchMsg(CNet *pRequest)
{
	char Msg[10000],tempMsg[1000];
	int ByteCount;
	int End=0;
	CStringArray *temp=new CStringArray;
	strcpy(Msg,"");
	do
	{
		strcpy(tempMsg,"");
		ByteCount=pRequest->Receive(tempMsg,1000);
		if(ByteCount>1000||ByteCount<=0)
		{
			MessageBox(GetActiveWindow(),"接受网络信息发生错误","警告信息",MB_OK);
			return ;
        }
		else if(ByteCount<1000&&ByteCount>0)
		{
			End=1;
		}
		tempMsg[ByteCount]=0;
		strcat(Msg,tempMsg);
	}while(End==0);
/*	MessageBox(GetActiveWindow(),pMsg,"网络信息",MB_OK);
	if(m_Isserver)
		SendMsg(pRequest,"收到，谢谢！");*/
	CString pMsg=Msg;
	
	if(!strncmp(Msg,"2007",4))
	{
		int k=Msg[4]-100;
		manager.PlayerAc=(k+1)%2;
		m_pView->PlayerName[k].Format("%s",pMsg.Right(pMsg.GetLength()-5));
		char st[100];
		sprintf(st,"2006%c%s",manager.PlayerAc+100,m_pView->PlayerName[manager.PlayerAc]);
		SendMsg(st);
	}
	else if(!strncmp(Msg,"2006",4))
	{
		m_pView->PlayerName[Msg[4]-100].Format("%s",pMsg.Right(pMsg.GetLength()-5));
	}
	else if(!strcmp(Msg,"2005"))
	{
		m_Ready[1]=true;
		if(m_Ready[1] && m_Ready[0])
		{
			manager.GameStart();
			m_pView->PrintAll();
		}
	}
	else if(!strncmp(Msg,"2008",4))
	{
		int x,y;
		x=Msg[4]-100;
		y=Msg[5]-100;
		if(Msg[6]-100==1)
		{
			if(manager.map[x][y]==manager.Game_State+1)
			{
				manager.PointCh=manager.Search(x,y);
				return;
			}
			else
			{
				manager.Moveto(manager.PointCh,x,y,true);
				manager.Updata();
				m_pView->PrintAll();
				return;
			}
		}
		else if(Msg[6]-100==2)
		{
			manager.Game_State=(manager.Game_State+1)%2;
			manager.Game_State+=2;
			MessageBox(GetActiveWindow(),"你的对手认输了","恭喜",ID_OK);
			m_Ready[0]=false;
			m_Ready[1]=false;
		}
		else if(Msg[6]-100==3)
		{
			int k;
			k=MessageBox(GetActiveWindow(),"对方要求和棋，您是否接受","和棋",MB_OKCANCEL);
			if(k==1)
			{
				SendAction(0,0,4);				
				m_Ready[0]=false;
				m_Ready[1]=false;
				manager.Game_State=5;
			}
			else
				SendAction(0,0,5);
		}
		else if(Msg[6]-100==4)
		{
			MessageBox(GetActiveWindow(),"对方接受了和棋","和棋",MB_OK);
			manager.Game_State=5;
			m_Ready[0]=false;
			m_Ready[1]=false;
		}
		else if(Msg[6]-100==5)
		{
			MessageBox(GetActiveWindow(),"对方不愿意和棋","和棋",MB_OK);
		}
	}

}

void NetControl::OnSet()
{
	m_pListening=new CNet(this);
	if(m_pListening->Create(m_Port))
	{
		if(!m_pListening->Listen())
		{
			MessageBox(GetActiveWindow(),"端口设置错误!","网络信息",MB_OK);
		}
	}
}

void NetControl::SendMsg(const char *pMsg)
{
	m_pSocket->Send(pMsg,strlen(pMsg));
}

void NetControl::OnSorc()
{
	int k;
	
	k=MessageBox(GetActiveWindow(),"你是否建立主机？（主机/客户机 Y/N）","建立主机",MB_OKCANCEL);
	if(k==1)
	{
		CServer ser1;
		ser1.DoModal();
		m_Port=atoi(ser1.m_Port);
		OnSet();
		m_Isserver=true;
		manager.PlayerAc=0;
	}
	else
	{
		CGetin dlg1;
		if(dlg1.DoModal()==IDOK)
		{
			CString *p=new(CString);
			*p=dlg1.m_IP;
			m_Server=*p;
			m_Port=atoi(dlg1.m_Port);
			OnOpen();
			m_Isserver=false;
		}
		manager.PlayerAc=1;
	}
}

CNet* NetControl::ConnectServer()
{
	CNet *pSocket=new CNet(this);
	if(!(pSocket->Create()))
	{
		delete pSocket;
		MessageBox(GetActiveWindow(),"创建Socket失败","警告信息",MB_OK);
        return NULL;
	}
	//连接到服务器
	if(!pSocket->Connect(m_Server,m_Port))
	{
		delete pSocket;
		MessageBox(GetActiveWindow(),"请求连接到服务器失败","警告信息",MB_OK);
        return NULL;
	}
	return pSocket;
}

void NetControl::OnOpen()
{
	if(m_pSocket)
	{
		MessageBox(GetActiveWindow(),"已经连接到服务器,请关闭连接再试一次!","警告信息",MB_OK);
		return;
	}
	if(!(m_pSocket=ConnectServer()))
	{
		m_pSocket=NULL;
		return;
	}
}



void NetControl::SendAction(int x, int y, int action)
{
	char st[10]="2008";
	st[4]=x+100;
	st[5]=y+100;
	st[6]=action+100;
	st[7]='\0';
	SendMsg(st);
}

NetControl::NetControl(CProgramView *p)
{
	m_Ready[0]=false;
	m_Ready[1]=false;
	m_pView=p;
	m_pSocket=NULL;
	m_Server="";
	m_Port=100;
	m_pListening=NULL;
}
