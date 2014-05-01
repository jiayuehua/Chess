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
	void GameStart();//游戏初始化，发牌。
	bool MainComputer;//主机，是主机则是true 不是则为false;
	Managers();
	virtual ~Managers();
	Card PlayCards[3][20];//最多20张牌
	int PlayerAc;//这台机器上的玩家
	int PlayerMain;//地主
	Card OutCards[20];//走的牌，一次也最多出20张牌
	int OutPlayer;//走牌的玩家
	Card Sendleft[3];//记录剩下的3张牌
	int Game_State;
	// -2游戏没开始
	// -1游戏准备中，选地主
	// 0-2 游戏玩家出牌
	// 3-5 对应0-2玩家胜利
	int Power;//计算当前游戏如果农民胜利则每人得的分
private:
	int PlayerMaininfo;//记录有几个玩家选择放弃地主 如果都放弃则游戏结束
	void SortCard(Card ca[]);
	void CardsInfo(Card ca[],int &num,int &min,int &type);
	void Updata();
	void SendCard();
	bool CheckCard(int pl);
	Card PreOut[20];
};

#endif // !defined(AFX_MANAGERS_H__653B297F_ACBA_4A5F_8280_99B83D57EA8A__INCLUDED_)