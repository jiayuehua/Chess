// Card.h: interface for the Card class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CARD_H__C1686A48_DB45_43BA_BB18_B43B868BAE6C__INCLUDED_)
#define AFX_CARD_H__C1686A48_DB45_43BA_BB18_B43B868BAE6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Card  
{
public:
	Card();
	virtual ~Card();
	int Num;//牌面数目 2-10 J=11 Q=12 K=13 A=1 Jok(小)=14 Jok(大)=15 大与15表示此牌不存在
	int Pow;//牌的实际大小，比如斗地主中2就比A大
			//3-10 J Q K  A  2  Jo小 Jo大
			//0-7  8 9 10 11 12 13   14
	int Type;//牌的类型 黑桃=0 红桃=1 梅花=2 方块=3
	bool Click;//被玩家选种的牌将是true，没被选种是false
};

#endif // !defined(AFX_CARD_H__C1686A48_DB45_43BA_BB18_B43B868BAE6C__INCLUDED_)
