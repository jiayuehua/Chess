// Chess.h: interface for the Chess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHESS_H__5F984F9F_C7C5_405D_893D_949250CDC5BC__INCLUDED_)
#define AFX_CHESS_H__5F984F9F_C7C5_405D_893D_949250CDC5BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Chess  
{
public:
	int type;//1兵 2炮 3车 4马 5象 6士 7帅 大于7表示棋子无效
	bool color;//false上面（0号玩家） true下面（1号）
	int x,y;
	Chess();
	virtual ~Chess();

};

#endif // !defined(AFX_CHESS_H__5F984F9F_C7C5_405D_893D_949250CDC5BC__INCLUDED_)
