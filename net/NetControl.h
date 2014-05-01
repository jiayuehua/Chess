// NetControl.h: interface for the NetControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETCONTROL_H__5FDC8688_52D4_4F84_B4B5_C4B081ABE48D__INCLUDED_)
#define AFX_NETCONTROL_H__5FDC8688_52D4_4F84_B4B5_C4B081ABE48D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Net.h"
class CChat;
class NetControl  
{
public:
	CChat *talk; 
	void SendMsg(CNet *pSend, char const *pMsg);
	void OnSorc();
	void OnSet();
	void OnOpen();
	void FetchMsg(CNet *pRequest);
	CNet* ConnectServer();
	NetControl();
	virtual ~NetControl();
	UINT m_Port;//�˿�
	CString m_PassWord;
	LPCTSTR m_Server;//����������
	CPtrList m_pList;    //������Ϊ�ͻ���������Socket����  
	CNet *m_pSocket;//��������
	CNet *m_pListening;//����Socket
private:
	bool m_Isserver;
};

#endif // !defined(AFX_NETCONTROL_H__5FDC8688_52D4_4F84_B4B5_C4B081ABE48D__INCLUDED_)