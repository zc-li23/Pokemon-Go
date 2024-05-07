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

	static Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y);//创建按钮函数
	void Button_Affect(HWND hWnd, WPARAM wParam, LPARAM lParam, int i, bool& have_found);	//按下按钮函数
};

//场景类
class Stage
{
public:
	int stageID;		//场景编号
	HBITMAP bg;			//背景图片
	int timeCountDown;	//游戏时间倒计时
	bool timerOn;		//计时器是否运行（游戏是否被暂停）

	static void InitStage(HWND hWnd, int stageID);//初始化游戏场景函数
};

#define SHOP		0		//商店
#define BATTLE		1		//战斗
#define HOSPITAL	2		//医院
#define BOSS		3		//BOSS战

//路线类
class Route
{
public:
	int num;
	int type;

	static void RouteChoose(HWND hWnd);//路线选择函数
	static void RefreshRoute(HWND hWnd);//刷新新路线函数
};
