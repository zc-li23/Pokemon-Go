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

	
};

//������
class Stage
{
public:
	int stageID;		//�������
	HBITMAP bg;			//����ͼƬ
	int timeCountDown;	//��Ϸʱ�䵹��ʱ
	bool timerOn;		//��ʱ���Ƿ����У���Ϸ�Ƿ���ͣ��

};

#define SHOP		0		//�̵�
#define BATTLE		1		//ս��
#define HOSPITAL	2		//ҽԺ
#define BOSS		3		//BOSSս

//·����
class Route
{
	int num;
	int type;
};
