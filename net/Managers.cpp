// Managers.cpp: implementation of the Managers class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "program.h"
#include "Managers.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Managers::Managers()
{

}

Managers::~Managers()
{

}

void Managers::GameStart()
{
	int i;
	if(MainComputer)
	{
		Power=10;
		OutCards[0].Num=16;
		PlayerMaininfo=0;
		SendCard();
		for(i=0;i<3;i++)
			SortCard(PlayCards[i]);
		PlayerMain=rand()%3;
		Game_State=-1;
	}
	else
	{
	//	GetCard();
	}
}

bool Managers::CheckCard(int pl)
{
	Card *Ca=PlayCards[pl];//用Ca 指针来代替Player[pl]，使程序简单容易理解
	int i,j;
	int num1,min1,type1;
	int num2,min2,type2;
	j=0;
	for(i=0;i<20 && Ca[i].Num<=15;i++)
		if(Ca[i].Click)
		{	PreOut[j]=Ca[i];
			j++;
		}
	if(j==0)
		return false;
	PreOut[j].Num=16;//表示此后的都没有牌了
	Ca=PreOut;//现在把CA指到这里
	CardsInfo(Ca,num2,min2,type2);
	if(OutCards[0].Num==16)//上次没有人走牌
	{
		if((type2==4 && num2==4)|| type2==5)
			Power*=2;
		return true;
	}
	if(OutPlayer==PlayerAc)//上次走牌的人 OutPlayer就是自己，那么自己可以随便走什么
	{
		if((type2==4 && num2==4)|| type2==5)
			Power*=2;
		return true;
	}
	CardsInfo(OutCards,num1,min1,type1);
	if(type2==0)
		return false;
	else 
	{
		if(type1==5)//双鬼
			return false;
		if(type2==5)
		{
			Power*=2;
			return true;
		}
		if(type1==4 && type2==4)
		{
			if(num2==num1)
			{
				if (min1<min2)
					return true;
				else
					return false;
			}
		}

		if(num2==4 && type2==4)
		{
			Power*=2;
			return true;
		}
		
		if(type1==3 && type2==3)
		{	
			if(num2==num1)
			{
				if(min1<min2)
					return true;
				else 
					return false;
			}
			else
				return false;
		}
		if(type2==type1)
		{
			if(num1==num2)
			{
				if(min1<min2)
					return true;
				else
					return false;
			}
			else
				return false;
		}
				
	}
	return false;
}

void Managers::SendCard()
{
	int i,j,k;
	bool Cards[55]={false};	//对应54张扑克,其中Cards[54]做初始化用 必须为true;
							//其中0-51为4个1-13 52是小王 53是大王
	Cards[54]=true;
	for(j=0;j<17;j++)
		for(i=0;i<3;i++)
		{
			Card &Ca=PlayCards[i][j];
			k=54;//保证必进入While循环进行随机
			while(Cards[k])
				k=rand()%54;
			Cards[k]=true;
			Ca.Click=false;
			if(k==53 || k==52)
			{
				Ca.Num=k-38;
				Ca.Pow=k-38;
				Ca.Type=4;
				Ca.Click=false;
			}
			else
			{
				Ca.Click=false;
				Ca.Num=k%13+1;
				Ca.Type=k/13;
				if(Ca.Num==1 || Ca.Num==2)
					Ca.Pow=Ca.Num+10;
				else
					Ca.Pow=Ca.Num-3;
			}
		}
	for(i=0;i<3;i++)
	{
		for(k=0;k<54;k++)
			if(!Cards[k])
			{
				Card Ca=Sendleft[i];
				if(k==53 || k==52)
				{
					Ca.Num=k-38;
					Ca.Pow=k-38;
					Ca.Type=4;
					Ca.Click=true;
				}
				else
				{
					Ca.Num=k%13+1;
					Ca.Type=k/13;
					Ca.Click=true;
					if(Ca.Num==1 || Ca.Num==2)
						Ca.Pow=Ca.Num+10;
					else
						Ca.Pow=Ca.Num-3;
				}
			}
	}
}
////////////////////////////////////////////////////////////////////////
/*
* 函数名称：DoMSG(	int num		//第几的一张牌
					int action)	//行为
* 函数介绍：消息响应
* 输入参数：action含义 
	 1点牌  3放弃出牌 4出牌（或接受当地主）5 读取OutCards（别人走牌）
* 输出参数：bool
* 返回值  ：true 表示响应成功 false为失败
*/
bool Managers::DoMsg(int num, int action)
{
	if(Game_State==-1 && action==4)
	{
		PlayCards[PlayerAc][17]=Sendleft[0];
		PlayCards[PlayerAc][18]=Sendleft[1];
		PlayCards[PlayerAc][19]=Sendleft[2];
		SortCard(PlayCards[PlayerAc]);
		Game_State=PlayerAc;
		return true;
	}
	if(Game_State==-1 && action==3)
	{
		PlayerMain=(PlayerMain+1)%3;
		PlayerMaininfo++;
		if(PlayerMaininfo==3)
			Game_State=-2;
	}
	if(action==5)
	{
		//Game
		return true;
	}
	else if(action==4)
	{
		if(CheckCard(Game_State))
		{
			Updata();//能出牌当然出牌咯
			return true;
		}
		else
			return false;
	}
	else if(action==3)
	{
		Game_State=(Game_State+1)%3;//直接更改游戏玩家
		return true;
	}
	else if(action==1)//唯一用得到前面1个参数的地方
	{
		Card &Ca=PlayCards[Game_State][num];
		if(Ca.Click)
			Ca.Click=false;
		else
			Ca.Click=true;
	}	

	return false;
}

void Managers::Updata()
{
	Card *Ca=PlayCards[Game_State];
	int i,j;
	for(i=0;i<20 && PreOut[i].Num<=15;i++)
		OutCards[i]=PreOut[i];
	if(i!=20)
		OutCards[i].Num=16;
	j=0;
	for(i=0;i<20 && Ca[i].Num<=15;i++)
		if(!Ca[i].Click)
		{
			Ca[j]=Ca[i];
			j++;
		}
	Ca[j].Num=16;
	OutPlayer=Game_State;
	if(j!=0)
		Game_State=(Game_State+1)%3;
	else
	{
		Game_State+=3;
	}
}
////////////////////////////////////////////////////////////////////////
/*
* 函数名称：CardsInfo(Card ca[],int &num,int &min,int &type)
* 函数介绍：把ca中的牌信息反应出来
* 输入参数：ca[]需要反应的牌信息
* 输出参数：int &num,int &max,int &type
* 返回值  ：num表示有多少张牌,min表示牌中间起左右的大小值中最小的一个
例如3个2带一个8，那么起作用的就是2 min=2，num=3，type表示类型 
1：3带1、2      2：4带2(4带2、两对)             3：连子 
4：全相同       5：双鬼炸弹                     0：错牌！不能走出去的
*/
void Managers::CardsInfo(Card ca[],int &num,int &min,int &type)
{
	int i,k,n;		
	int same[3]={0};
	int nsame[3]={0};

	for(n=0;n<20 && ca[n].Pow<=15;n++);
	type=0;
	num=n;
	if(n>=5)
	{
		for(k=0;k<n-1;k++)
			if(ca[k].Pow!=ca[k+1].Pow-1)
				break;
		if(k==n-1 && ca[k].Pow<12)//牌不能连到2 2的pow就是12
		{
			min=ca[0].Pow;
			type=3;
			return;
		}

		i=-1;
		for(k=0;k<n-1;k++)
		{
			if(i<0 || ca[k].Pow!=same[i])
				i++;
			if(i>2)
				break;
			same[i]=ca[k].Pow;
			nsame[i]++;
		}
		if(i<=2)
		{
			int maxnum=-1;
			for(k=0;k<=2;k++)
				if(nsame[k]>maxnum)
				{
					maxnum=nsame[k];
					i=k;
				}
			if(maxnum==3 && n==5)
			{
				type=1;
				min=same[i];
				return;
			}
			else if(maxnum==4)
			{
				type=2;
				min=same[i];
				return;
			}
		}
	}
	else if (n>2)
	{
		i=-1;
		for(k=0;k<n-1;k++)
		{
			if(i<0 || ca[k].Pow!=same[i])
				i++;
			if(i>2)
				break;
			same[i]=ca[k].Pow;
			nsame[i]++;
		}
		if(i<=2)
		{
			int maxnum=-1;
			for(k=0;k<=2;k++)
				if(nsame[k]>maxnum)
				{
					maxnum=nsame[k];
					i=k;
				}
			if(maxnum==3 && n==4)
			{
				type=1;
				min=same[i];
				return;
			}
			else if(maxnum==3 && n==3)
			{
				type=2;
				min=same[i];
				return;
			}
			else if(maxnum==4 && n==4)
			{
				type=4;
				min=same[i];
				return;
			}
		}
	}
	else if (n==2)
	{
		if(ca[0].Pow==ca[1].Pow)
		{
			type=4;
			min=ca[0].Pow;
		}
		else if(ca[0].Pow==14 && ca[1].Pow==15)
		{
			type=5;
			min=ca[1].Pow;
		}
	}
}

void Managers::SortCard(Card ca[])
{
	int i,j;
	Card temp;
	for(i=0;i<20 && ca[i].Num<=15;i++)
		for(j=i+1;j<20 && ca[j].Num<=15;j++)
			if(ca[i].Pow>ca[j].Pow)
			{
				temp=ca[i];
				ca[i]=ca[j];
				ca[j]=temp;
			}
}
