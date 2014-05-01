// NetControl.cpp: implementation of the NetControl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Program.h"
#include "NetControl.h"
#include "Net.h"
#include "Getin.h"
#include "Server.h"
#include "Getin.h"
#include "Chat.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
NetControl::NetControl()
{
	m_pSocket=NULL;
	m_Server="";
	m_Port=100;
	m_pListening=NULL;
	m_pList.RemoveAll();
	talk=NULL;
}
NetControl::~NetControl()
{
	if(m_pSocket)
	delete m_pSocket;
	delete m_pListening;
}
void NetControl::FetchMsg(CNet *pRequest)
{
	if(m_Isserver)
		m_pSocket=pRequest;
	char pMsg[10000],tempMsg[1000];
	int ByteCount;
	int End=0;
	CStringArray *temp=new CStringArray;
	strcpy(pMsg,"");
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
		strcat(pMsg,tempMsg);
	}while(End==0);
	if (talk!=NULL)
	{
		talk->UpdateData();
		CString tem;
		if(talk->m_Gets!="")
			tem.Format("%s\r\n收到信息%s",pMsg,talk->m_Gets);
		else
			tem.Format("收到信息%s",pMsg);
		talk->m_Gets=tem;
		talk->UpdateData(FALSE);
	}
/*	MessageBox(GetActiveWindow(),pMsg,"网络信息",MB_OK);
	if(m_Isserver)
		SendMsg(pRequest,"收到，谢谢！");*/
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

void NetControl::SendMsg(CNet *pSend, const char *pMsg)
{
	pSend->Send(pMsg,strlen(pMsg));
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
		//manager
	}
	else
	{
		CGetin dlg1;
		if(dlg1.DoModal()==IDOK)
		{
			CString *p=new(CString);
			*p=dlg1.m_ip;
			m_Server=*p;
			m_Port=atoi(dlg1.m_Port);
			OnOpen();
			m_Isserver=false;
		}
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
	
	m_pSocket=new CNet(this);
	if(!(m_pSocket=ConnectServer()))
	{
		m_pSocket=NULL;
		return;
	}
}


