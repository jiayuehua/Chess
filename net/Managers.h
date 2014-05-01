// Managers.h: interface for the Managers class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANAGERS_H__653B297F_ACBA_4A5F_8280_99B83D57EA8A__INCLUDED_)
#define AFX_MANAGERS_H__653B297F_ACBA_4A5F_8280_99B83D57EA8A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Card.h"
class Managers  
{
public:
	bool DoMsg(int num,int action);
	void GameStart();//��Ϸ��ʼ�������ơ�
	bool MainComputer;//����������������true ������Ϊfalse;
	Managers();
	virtual ~Managers();
	Card PlayCards[3][20];//���20����
	int PlayerAc;//��̨�����ϵ����
	int PlayerMain;//����
	Card OutCards[20];//�ߵ��ƣ�һ��Ҳ����20����
	int OutPlayer;//���Ƶ����
	Card Sendleft[3];//��¼ʣ�µ�3����
	int Game_State;
	// -2��Ϸû��ʼ
	// -1��Ϸ׼���У�ѡ����
	// 0-2 ��Ϸ��ҳ���
	// 3-5 ��Ӧ0-2���ʤ��
	int Power;//���㵱ǰ��Ϸ���ũ��ʤ����ÿ�˵õķ�
private:
	int PlayerMaininfo;//��¼�м������ѡ��������� �������������Ϸ����
	void SortCard(Card ca[]);
	void CardsInfo(Card ca[],int &num,int &min,int &type);
	void Updata();
	void SendCard();
	bool CheckCard(int pl);
	Card PreOut[20];
};

#endif // !defined(AFX_MANAGERS_H__653B297F_ACBA_4A5F_8280_99B83D57EA8A__INCLUDED_)