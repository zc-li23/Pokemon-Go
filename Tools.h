#pragma once
//��ť��
class Button
{
public:
	int buttonID;	//��ť���
	bool visible;	//��ť�Ƿ�ɼ�
	HBITMAP img;	//ͼƬ
	int x;			//����x
	int y;			//����y
	int width;		//���
	int height;		//�߶�

	Button(int buttonID, HBITMAP img, int width, int height, int x, int y) :
		buttonID(buttonID), img(img), width(width), height(height), x(x), y(y), visible(false) {};
	~Button() {};

	static Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y);//������ť����
	void Button_Affect(HWND hWnd, WPARAM wParam, LPARAM lParam, int i, bool& have_found);	//���°�ť����
};

//������
class Stage
{
public:
	int stageID;		//�������
	HBITMAP bg;			//����ͼƬ
	int timeCountDown;	//��Ϸʱ�䵹��ʱ
	bool timerOn;		//��ʱ���Ƿ����У���Ϸ�Ƿ���ͣ��

	static void InitStage(HWND hWnd, int stageID);//��ʼ����Ϸ��������
};

#define SHOP		0		//�̵�
#define BATTLE		1		//ս��
#define HOSPITAL	2		//ҽԺ
#define BOSS		3		//BOSSս

//·����
class Route
{
public:
	int num;
	int type;

	static void RouteChoose(HWND hWnd);//·��ѡ����
	static void RefreshRoute(HWND hWnd);//ˢ����·�ߺ���
};
