#pragma once

#pragma region 头文件引用

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容

// Windows 头文件: 
#include <windows.h>

//音乐头文件
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")

// C 运行时头文件
#include <iostream>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <ctime>
#include <vector>
#include <math.h>
#include <cstdio>
#include <stdlib.h>

// 资源头文件
#include "resource.h"
#pragma comment(lib, "Msimg32.lib")			//图象处理的函数接口，例如：透明色的位图的绘制TransparentBlt函数

#include "Tools.h"
#include "Card.h"
#include "Pokemon.h"

using namespace std;
#pragma endregion


#pragma region 宏定义

#define WINDOW_TITLEBARHEIGHT	32			//标题栏高度
#define WINDOW_WIDTH			1024		//游戏窗口宽度
#define WINDOW_HEIGHT			768			//游戏窗口高度


#define TIMER_GAMETIMER 1					//主计时器
#define TIMER_GAMETIMER_ELAPSE 30			//刷新帧率
#define MAX_LOADSTRING 100					//最大字符

#define STAGE_STARTMENU			0			//开始界面的ID
#define STAGE_POKEMON_CHOOSE	1			//选择精灵界面ID
#define STAGE_HELP				2			//帮助界面ID
#define STAGE_ROUTE_CHOOSE		3			//路线选择界面ID
#define STAGE_CARD_CHOOSE		4			//卡牌选择界面ID
#define STAGE_BATTLE			5			//对战界面ID
#define STAGE_BOSS				6			//BOSS对战界面ID
#define STAGE_STOP				7			//暂停界面ID
#define STAGE_WIN				8			//游戏胜利界面ID
#define STAGE_LOSE				9			//游戏失败界面ID

#define BUTTON_STARTGAME			1001			//开始游戏的按钮ID
#define BUTTON_HELP					1002			//帮助界面的按钮ID
#define BUTTON_RETURN				1003			//返回的按钮ID
#define BUTTON_POKEMON_1			1004			//第一个宝可梦对应按钮
#define BUTTON_POKEMON_2			1005			//第二个宝可梦对应按钮
#define BUTTON_POKEMON_3			1006			//第三个宝可梦对应按钮
#define BUTTON_POKEMON_4			1007			//第四个宝可梦对应按钮
#define BUTTON_POKEMON_NEXT			1008			//宝可梦切换下一个按钮
#define BUTTON_POKEMON_BEFORE		1009			//宝可梦切换上一个按钮
#define BUTTON_BATTLE_ROUTE			1010			//对战路径的按钮
#define BUTTON_SHOP_ROUTE			1011			//商店路径的按钮
#define BUTTON_HOSPITAL_ROUTE		1012			//医院路径的按钮
#define BUTTON_BOSS_ROUTE			1013			//BOSS路径的按钮
#define BUTTON_SKIP_CARD_CHOOSE		1014			//跳过卡牌选择的按钮
#define BUTTON_CARD_CHOOSE_1		1015			//选择卡牌1的按钮
#define BUTTON_CARD_CHOOSE_2		1016			//选择卡牌2的按钮
#define BUTTON_CARD_CHOOSE_3		1017			//选择卡牌3的按钮
#define BUTTON_CARD_CHOOSE_4		1018			//选择卡牌4的按钮
#define BUTTON_CARD_CHOOSE_5		1019			//选择卡牌5的按钮
#define BUTTON_CARD_CHOOSE_6		1020			//选择卡牌6的按钮
#define BUTTON_CARD_CHOOSE_7		1021			//选择卡牌7的按钮
#define BUTTON_CARD_CHOOSE_8		1022			//选择卡牌8的按钮
#define BUTTON_CARD_CHOOSE_9		1023			//选择卡牌9的按钮
#define BUTTON_CARD_CHOOSE_10		1024			//选择卡牌10的按钮
#define BUTTON_CARD_CHOOSE_11		1025			//选择卡牌11的按钮
#define BUTTON_CARD_CHOOSE_12		1026			//选择卡牌12的按钮
#define BUTTON_RETURN_GAME			1027			//返回游戏的按钮ID
#define BUTTON_MENU					1028			//返回大厅的按钮ID
#define BUTTON_REGAME				1029			//重新游戏的按钮ID
#define BUTTON_STOP					1030			//暂停的按钮ID
#define BUTTON_REGAME_END			1031			//结束后重新游戏的按钮ID
#define BUTTON_MENU_END				1032			//结束后返回大厅的按钮ID
#define BUTTON_CARD_1				1033			//卡牌1的按钮
#define BUTTON_CARD_2				1034			//卡牌2的按钮
#define BUTTON_CARD_3				1035			//卡牌3的按钮
#define BUTTON_CARD_4				1036			//卡牌4的按钮
#define BUTTON_END_ROUND			1037			//结束回合按钮
#define BUTTON_NEXT_HELP_PAGE		1038			//下一张帮助界面按钮
#define BUTTON_LAST_HELP_PAGE		1039			//上一张帮助界面按钮
#pragma endregion


#pragma region 全局变量声明
extern HINSTANCE hInst;                         // 当前实例
extern WCHAR szTitle[MAX_LOADSTRING];           // 标题栏文本
extern WCHAR szWindowClass[MAX_LOADSTRING];     // 主窗口类名

extern HBITMAP bmp_num;							//数字的图片
extern HBITMAP bmp_info_1;						//精灵1信息的图片
extern HBITMAP bmp_info_2;						//精灵2信息的图片
extern HBITMAP bmp_info_3;						//精灵3信息的图片
extern HBITMAP bmp_info_4;						//精灵4信息的图片
extern HBITMAP bmp_slash;						//斜杠的图片
extern HBITMAP bmp_lose;						//失败的图片
extern HBITMAP bmp_win;							//胜利的图片
extern HBITMAP bmp_consumed_energy;				//将要消耗的能量的图片
extern HBITMAP bmp_energy;						//能量的图片
extern HBITMAP bmp_lack_energy;					//缺少能量的图片
extern HBITMAP bmp_draw_cards;					//抽卡区的图片
extern HBITMAP bmp_discarded_cards;				//弃牌区的图片
extern HBITMAP bmp_attack;						//攻击的图片
extern HBITMAP bmp_affect;						//效果的图片
extern HBITMAP bmp_defense;						//防御的图片
extern HBITMAP bmp_power;						//力量的图片
extern HBITMAP bmp_speed;						//敏捷的图片
extern HBITMAP bmp_title;						//标题图片
extern HBITMAP bmp_battle_bg;					//对战背景图片
extern HBITMAP bmp_help_bg;						//帮助图片
extern HBITMAP bmp_button_start;				//开始按钮图片
extern HBITMAP bmp_button_help;					//帮助按钮图片
extern HBITMAP bmp_button_return;				//返回按钮图片
extern HBITMAP bmp_button_return_game;			//返回游戏按钮图片
extern HBITMAP bmp_button_menu;					//返回大厅按钮图片
extern HBITMAP bmp_button_stop;					//暂停按钮图片
extern HBITMAP bmp_button_regame;				//重新游戏按钮图片
extern HBITMAP bmp_button_end_round;			//结束回合按钮图片
extern HBITMAP bmp_button_skip_card_choose;		//跳过卡牌选择按钮图片
extern HBITMAP bmp_button_next_help_page;		//下一张帮助界面
extern HBITMAP bmp_button_last_help_page;		//上一张帮助界面
extern HBITMAP bmp_pikachu;						//精灵一图片
extern HBITMAP bmp_pokemon_2;					//精灵二图片
extern HBITMAP bmp_pokemon_3;					//精灵三图片
extern HBITMAP bmp_pokemon_4;					//精灵四图片
extern HBITMAP bmp_pokeback_1;					//精灵一背影图片
extern HBITMAP bmp_pokeback_2;					//精灵二背影图片
extern HBITMAP bmp_pokeback_3;					//精灵三背影图片
extern HBITMAP bmp_pokeback_4;					//精灵四背影图片
extern HBITMAP bmp_rival_1;						//对手一精灵图片
extern HBITMAP bmp_rival_2;						//对手二精灵图片
extern HBITMAP bmp_rival_3;						//对手三精灵图片
extern HBITMAP bmp_rival_4;						//对手四精灵图片
extern HBITMAP bmp_rival_5;						//对手五精灵图片
extern HBITMAP bmp_boss;						//BOSS精灵图片
extern HBITMAP bmp_choose_bg;					//精灵选择界面背景图片
extern HBITMAP bmp_route_choose_bg;				//路线选择界面背景图片
extern HBITMAP bmp_card_choose_bg;				//卡牌选择界面背景图片
extern HBITMAP bmp_nothing;						//空白图片
extern HBITMAP bmp_boss_route;					//BOSS路线图片
extern HBITMAP bmp_battle_route;				//对战路线图片
extern HBITMAP bmp_hospital_route;				//商店路线图片
extern HBITMAP bmp_shop_route;					//医院路线图片
extern HBITMAP bmp_left_route;					//左路线图片
extern HBITMAP bmp_mid_route;					//中间路线图片
extern HBITMAP bmp_right_route;					//右路线图片
extern HBITMAP bmp_mid_card;					//中间卡牌图片
extern HBITMAP bmp_left_card;					//左边卡牌图片
extern HBITMAP bmp_right_card;					//右边卡牌图片
extern HBITMAP bmp_card_select;					//选中卡片图片
extern HBITMAP bmp_attack_act;					//攻击动画图片
extern HBITMAP bmp_defend_act;					//防御动画图片
extern HBITMAP bmp_card_1;						//卡牌一图片
extern HBITMAP bmp_card_2;						//卡牌二图片
extern HBITMAP bmp_card_3;						//卡牌三图片
extern HBITMAP bmp_card_4;						//卡牌四图片
extern HBITMAP bmp_card_5;						//卡牌五图片
extern HBITMAP bmp_card_6;						//卡牌六图片
extern HBITMAP bmp_card_7;						//卡牌七图片
extern HBITMAP bmp_card_8;						//卡牌八图片
extern HBITMAP bmp_card_9;						//卡牌九图片
extern HBITMAP bmp_card_10;						//卡牌十图片
extern HBITMAP bmp_card_11;						//卡牌十一图片
extern HBITMAP bmp_card_12;						//卡牌十二图片
extern HBITMAP bmp_help_1;						//帮助界面1图片
extern HBITMAP bmp_help_2;						//帮助界面2图片
extern HBITMAP bmp_help_3;						//帮助界面3图片
extern HBITMAP bmp_help_4;						//帮助界面4图片
extern HBITMAP bmp_help_5;						//帮助界面5图片
extern HBITMAP bmp_help_6;						//帮助界面6图片
extern HBITMAP bmp_card_wound;					//伤口卡牌图片
extern HBITMAP bmp_databox_me;					//对战中，我宝可梦的数据条图片
extern HBITMAP bmp_databox_rival;				//对战中，敌人宝可梦的数据条图片
extern HBITMAP bmp_hp_line;						//宝可梦血量条图片
extern HBITMAP bmp_hand_card_1;				//手牌一图片
extern HBITMAP bmp_hand_card_2;				//手牌二图片
extern HBITMAP bmp_hand_card_3;				//手牌三图片
extern HBITMAP bmp_hand_card_4;				//手牌四图片

extern int consumed_energy;
extern int round_num;
extern int stop_stage;
extern int mouseX;
extern int mouseY;
extern int pokemon_select;
extern int card_select;
extern int help_page;
extern int route_num;						//当前路线数
extern int left_route;
extern int mid_route;
extern int right_route;
extern int right_card;						//右边的卡牌
extern int mid_card;
extern int left_card;
extern bool mouseDown;
extern bool keyUpDown;
extern bool keyDownDown;
extern bool keyLeftDown;
extern bool keyRightDown;
extern bool keyWDown;
extern bool keySDown;
extern bool keyADown;
extern bool keyDDown;
extern bool keyESC;

extern int attack_on;		//1为敌人，2为我
extern int defend_on;		//1为敌人，2为我
extern int attack_frame_id;
extern int defend_frame_id;
extern int FRAMES_ATTACK[];
extern int FRAMES_ATTACK_COUNT;
extern int FRAMES_DEFEND[];
extern int FRAMES_DEFEND_COUNT;

extern Stage* currentStage; //当前场景
extern Me* MyPokemon;				//我当前的宝可梦
extern Rival* RivalPokemon;			//对手的宝可梦

extern vector<Button*> buttons;
extern vector<Stage*> stages;
extern vector<Card*> cards;						//拥有的所有牌
extern vector<Card*> hand_cards;				//手牌
extern vector<Card*> discarded_cards;			//弃牌区
extern vector<Card*> draw_cards;				//抽牌区
extern vector<Pokemon*> pokemons;
#pragma endregion


#pragma region 游戏函数声明

void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam);
void DetectMouse(HWND hWnd, WPARAM wParam, LPARAM lParam);
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam);
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam);
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);
void Paint(HWND hWnd);
void DeleteData(HWND hWnd);
void DetectGameState(HWND hWnd);
void StartBattle(HWND hWnd);
void EndRound(HWND hWnd, int roundnum);

#pragma endregion

