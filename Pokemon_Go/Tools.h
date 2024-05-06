#pragma once
//按钮类
class Button
{
public:
	int buttonID;	//按钮编号
	bool visible;	//按钮是否可见
	HBITMAP img;	//图片
	int x;			//坐标x
	int y;			//坐标y
	int width;		//宽度
	int height;		//高度

	Button(int buttonID, HBITMAP img, int width, int height, int x, int y) :
		buttonID(buttonID), img(img), width(width), height(height), x(x), y(y), visible(false) {};
	~Button() {};

	
};

//场景类
class Stage
{
public:
	int stageID;		//场景编号
	HBITMAP bg;			//背景图片
	int timeCountDown;	//游戏时间倒计时
	bool timerOn;		//计时器是否运行（游戏是否被暂停）

};

#define SHOP		0		//商店
#define BATTLE		1		//战斗
#define HOSPITAL	2		//医院
#define BOSS		3		//BOSS战

//路线类
class Route
{
	int num;
	int type;
};
