#pragma once

//��غ궨��
#define ATTACKING	1	//����
#define DEFEND		2	//����
#define AFFECT		3	//Ч��
#define POWER		1	//����
#define SPEED		1	//����

class Pokemon
{
public:
	int total_heart;
	int heart;
	int defense;
	int width;
	int height;
	int x;
	int y;
	int speed;
	int power;
	HBITMAP img;

	Pokemon(int total_heart, int width, int height, int x, int y, HBITMAP img) :
		total_heart(total_heart), heart(total_heart), defense(0), width(width), height(height), x(x),
		y(y), speed(0), power(0),img(img) {};
	~Pokemon() {};

};
class Me :public Pokemon
{
public:
	int energy;
	int full_energy;

	Me(int total_heart, int width, int height, int x, int y, HBITMAP img,int energy):
		Pokemon( total_heart, width, height, x, y, img) , energy(energy), full_energy(energy)
	{}
};

class Rival :public Pokemon
{
public:
	int intention;
	int intention_num;
	int id;//1-5Ϊ������ţ�0ΪBOSS

	Rival(int total_heart, int width, int height, int x, int y, HBITMAP img) :
		Pokemon(total_heart,width,height,x, y, img)
	{}
};