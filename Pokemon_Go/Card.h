#pragma once
#define ATTACK		1	//攻击
#define SKILL		2	//技能
#define ABILITY		3	//能力

#define WOUND				0		//伤口
#define NORMAL_ATTACK		1		//撞击
#define NORMAL_DEFEND		2		//防御
#define VOLT_ATTACK			3		//十万伏特
#define DRAGON_DANCE		4		//龙之舞
#define MYSTIC_DEFEND		5		//神秘守护
#define CHANGE_COURT		6		//交换场地
#define BIG_BANG			7		//大爆炸
#define EQUAL_LIFE			8		//同命
#define SHADOW_AVATAR		9		//影子分身
#define DRAGON_ATTACK		10		//画龙点睛
#define LIGHTNING_FLASH		11		//电光一闪
#define ROOT_FLUCTUATION	12		//根源波动


class Card		//卡牌
{
public:
	HBITMAP img;
	int harm = 0;			//伤害
	int defend = 0;			//防御
	bool way = 0;			//出牌方式:0为回收，1为消耗
	int expend = 0;			//耗费能量
	int card_ID = 0;		//卡牌ID


	void affect(HWND hWnd);		//卡牌效果
};