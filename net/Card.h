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
	int Num;//������Ŀ 2-10 J=11 Q=12 K=13 A=1 Jok(С)=14 Jok(��)=15 ����15��ʾ���Ʋ�����
	int Pow;//�Ƶ�ʵ�ʴ�С�����綷������2�ͱ�A��
			//3-10 J Q K  A  2  JoС Jo��
			//0-7  8 9 10 11 12 13   14
	int Type;//�Ƶ����� ����=0 ����=1 ÷��=2 ����=3
	bool Click;//�����ѡ�ֵ��ƽ���true��û��ѡ����false
};

#endif // !defined(AFX_CARD_H__C1686A48_DB45_43BA_BB18_B43B868BAE6C__INCLUDED_)
