#pragma once
#define ATTACK		1	//����
#define SKILL		2	//����
#define ABILITY		3	//����

#define WOUND				0		//�˿�
#define NORMAL_ATTACK		1		//ײ��
#define NORMAL_DEFEND		2		//����
#define VOLT_ATTACK			3		//ʮ�����
#define DRAGON_DANCE		4		//��֮��
#define MYSTIC_DEFEND		5		//�����ػ�
#define CHANGE_COURT		6		//��������
#define BIG_BANG			7		//��ը
#define EQUAL_LIFE			8		//ͬ��
#define SHADOW_AVATAR		9		//Ӱ�ӷ���
#define DRAGON_ATTACK		10		//�����㾦
#define LIGHTNING_FLASH		11		//���һ��
#define ROOT_FLUCTUATION	12		//��Դ����


class Card		//����
{
public:
	HBITMAP img;
	int harm = 0;			//�˺�
	int defend = 0;			//����
	bool way = 0;			//���Ʒ�ʽ:0Ϊ���գ�1Ϊ����
	int expend = 0;			//�ķ�����
	int card_ID = 0;		//����ID


	void affect(HWND hWnd);		//����Ч��
};