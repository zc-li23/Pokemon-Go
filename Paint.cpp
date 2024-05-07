#include "Pokemon_Go.h"

//绘图函数
void Paint(HWND hWnd)
{

	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//初始化缓存
	HBITMAP	blankBmp = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, blankBmp);
	
	//绘制场景
	if (currentStage->stageID == STAGE_STARTMENU)
	{
		SelectObject(hdc_loadBmp, bmp_title);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			1012, 768,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			1042, 768,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
	}
	else if (currentStage->stageID == STAGE_POKEMON_CHOOSE)
	{
		SelectObject(hdc_loadBmp, bmp_choose_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			1012, 768,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			324, 296,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		switch (pokemon_select)
		{
		case 0: SelectObject(hdc_loadBmp, bmp_info_1);
			break;
		case 1:SelectObject(hdc_loadBmp, bmp_info_2);
			break;
		case 2:SelectObject(hdc_loadBmp, bmp_info_3);
			break;
		case 3:SelectObject(hdc_loadBmp, bmp_info_4);
			break;
			default:break;
		}
		TransparentBlt(
			hdc_memBuffer,
			475, 250,			// 界面上起始绘制点
			512, 384,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			512, 384,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
	}
	else if (currentStage->stageID == STAGE_ROUTE_CHOOSE)
	{
		SelectObject(hdc_loadBmp, bmp_route_choose_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			1012, 768,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			720, 540,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
	}
	else if (currentStage->stageID == STAGE_CARD_CHOOSE)
	{
		SelectObject(hdc_loadBmp, bmp_card_choose_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			1010, 768,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			512, 384,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		); 
	}
	else if (currentStage->stageID == STAGE_HELP)
	{
		SelectObject(hdc_loadBmp, bmp_help_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			1024, 768,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			512, 384,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		if (help_page == 0)
		{
			SelectObject(hdc_loadBmp, bmp_help_1);
			TransparentBlt(
				hdc_memBuffer,
				100, 100,			// 界面上起始绘制点
				800, 500,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				1314, 706,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else if (help_page == 1)
		{
			SelectObject(hdc_loadBmp, bmp_help_2);
			TransparentBlt(
				hdc_memBuffer,
				100, 100,			// 界面上起始绘制点
				800, 500,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				1183, 700,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else if (help_page == 2)
		{
			SelectObject(hdc_loadBmp, bmp_help_3);
			TransparentBlt(
				hdc_memBuffer,
				100, 100,			// 界面上起始绘制点
				750, 500,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				1070, 695,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else if (help_page == 3)
		{
			SelectObject(hdc_loadBmp, bmp_help_4);
			TransparentBlt(
				hdc_memBuffer,
				50, 50,			// 界面上起始绘制点
				900, 600,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				1197, 711,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else if (help_page == 4)
		{
			SelectObject(hdc_loadBmp, bmp_help_5);
			TransparentBlt(
				hdc_memBuffer,
				100, 100,			// 界面上起始绘制点
				850, 500,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				932, 497,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else if (help_page == 5)
		{
			SelectObject(hdc_loadBmp, bmp_help_6);
			TransparentBlt(
				hdc_memBuffer,
				130, 50,			// 界面上起始绘制点
				750, 600,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				1292, 969,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
	}
	else if (currentStage->stageID == STAGE_STOP)
	{
		SelectObject(hdc_loadBmp, bmp_help_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			1024, 768,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			512, 384,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
	}
	else if (currentStage->stageID == STAGE_BATTLE)
	{
		SelectObject(hdc_loadBmp, bmp_battle_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			1012, 768,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			640, 382,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);

		SelectObject(hdc_loadBmp, MyPokemon->img);
		TransparentBlt(
			hdc_memBuffer,
			MyPokemon->x, 300,			// 界面上起始绘制点
			200, 200,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			MyPokemon->width, MyPokemon->height,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);

		SelectObject(hdc_loadBmp, RivalPokemon->img);
		TransparentBlt(
			hdc_memBuffer,
			RivalPokemon->x, RivalPokemon->y,			// 界面上起始绘制点
			300, 300,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			RivalPokemon->width, RivalPokemon->height,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);

		//绘制数据方格
		SelectObject(hdc_loadBmp, bmp_databox_me);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			390, 93,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			260, 62,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_databox_rival);
		TransparentBlt(
			hdc_memBuffer,
			620, 0,			// 界面上起始绘制点
			390, 93,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			260, 62,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);


		//绘制血量
		if ((double)MyPokemon->heart / MyPokemon->total_heart >= 0.66)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				177, 60,			// 界面上起始绘制点
				(int)(145 * ((double)MyPokemon->heart / MyPokemon->total_heart)), 9,											// 界面上绘制宽度高度
				hdc_loadBmp,
				2, 0,	// 位图上起始绘制点
				90, 6,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else if ((double)MyPokemon->heart / MyPokemon->total_heart >= 0.33)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				177, 60,			// 界面上起始绘制点
				(int)(145 * ((double)MyPokemon->heart / MyPokemon->total_heart)), 9,											// 界面上绘制宽度高度
				hdc_loadBmp,
				2, 6,	// 位图上起始绘制点
				90, 6,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				177, 60,			// 界面上起始绘制点
				(int)(145 * ((double)MyPokemon->heart / MyPokemon->total_heart)), 9,											// 界面上绘制宽度高度
				hdc_loadBmp,
				2, 12,	// 位图上起始绘制点
				90, 6,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}

		if ((double)RivalPokemon->heart / RivalPokemon->total_heart >= 0.66)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				824, 60,			// 界面上起始绘制点
				(int)(145 * ((double)RivalPokemon->heart / RivalPokemon->total_heart)), 9,											// 界面上绘制宽度高度
				hdc_loadBmp,
				2, 0,	// 位图上起始绘制点
				90, 6,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else if ((double)RivalPokemon->heart / RivalPokemon->total_heart >= 0.33)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				824, 60,			// 界面上起始绘制点
				(int)(145 * ((double)RivalPokemon->heart / RivalPokemon->total_heart)), 9,											// 界面上绘制宽度高度
				hdc_loadBmp,
				2, 6,	// 位图上起始绘制点
				90, 6,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				824, 60,			// 界面上起始绘制点
				(int)(145 * ((double)RivalPokemon->heart / RivalPokemon->total_heart)), 9,											// 界面上绘制宽度高度
				hdc_loadBmp,
				2, 12,	// 位图上起始绘制点
				90, 6,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}


		//绘制能量
		for (int i = 1; i <= MyPokemon->energy; i++)
		{
			SelectObject(hdc_loadBmp, bmp_energy);
			TransparentBlt(
				hdc_memBuffer,
				i * 80 + 220, 410,			// 界面上起始绘制点
				64, 64,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				128, 128,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}

		#pragma region 绘制弃牌区抽牌区
		SelectObject(hdc_loadBmp, bmp_draw_cards);
		TransparentBlt(
			hdc_memBuffer,
			8, 560,			// 界面上起始绘制点
			100, 100,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			200, 200,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			10, 650,			// 界面上起始绘制点
			60, 60,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(draw_cards.size() / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			42, 650,			// 界面上起始绘制点
			60, 60,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(draw_cards.size() % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_discarded_cards);
		TransparentBlt(
			hdc_memBuffer,
			900, 560,			// 界面上起始绘制点
			100, 100,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			200, 200,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			902, 650,			// 界面上起始绘制点
			60, 60,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(discarded_cards.size() / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			934, 650,			// 界面上起始绘制点
			60, 60,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(discarded_cards.size() % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
#pragma endregion

		#pragma region	绘制数字HP
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			170, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->heart / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			200, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->heart % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_slash);
		TransparentBlt(
			hdc_memBuffer,
			225, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			250, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->total_heart / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			280, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->total_heart % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);

		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			820, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->heart / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			850, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->heart % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_slash);
		TransparentBlt(
			hdc_memBuffer,
			875, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			900, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->total_heart / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			930, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->total_heart % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		#pragma endregion

		#pragma region	绘制力量与敏捷
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			65, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->power / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			90, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->power % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_power);
		TransparentBlt(
			hdc_memBuffer,
			83, 50,			// 界面上起始绘制点
			30, 30,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			56, 56,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			5, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->speed / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			30, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->speed % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_speed);
		TransparentBlt(
			hdc_memBuffer,
			20, 50,			// 界面上起始绘制点
			35, 28,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			100, 80,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);


		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			715, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->power / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			740, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->power % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_power);
		TransparentBlt(
			hdc_memBuffer,
			733, 50,			// 界面上起始绘制点
			30, 30,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			56, 56,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			655, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->speed / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			680, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->speed % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_speed);
		TransparentBlt(
			hdc_memBuffer,
			672, 50,			// 界面上起始绘制点
			35, 28,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			100, 80,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
#pragma endregion

		#pragma region  绘制敌人意图
		if (RivalPokemon->intention == ATTACK)
		{
			SelectObject(hdc_loadBmp, bmp_attack);
			TransparentBlt(
				hdc_memBuffer,
				460, 200,			// 界面上起始绘制点
				80, 80,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				100, 100,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				440, 270,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(RivalPokemon->intention_num / 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				480, 270,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(RivalPokemon->intention_num % 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else if (RivalPokemon->intention == DEFEND)
		{
			SelectObject(hdc_loadBmp, bmp_defense);
			TransparentBlt(
				hdc_memBuffer,
				460, 200,			// 界面上起始绘制点
				80, 80,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				440, 270,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(RivalPokemon->intention_num / 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				480, 270,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(RivalPokemon->intention_num % 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else if (RivalPokemon->intention == AFFECT)
		{
			SelectObject(hdc_loadBmp, bmp_affect);
			TransparentBlt(
				hdc_memBuffer,
				460, 200,			// 界面上起始绘制点
				80, 80,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				100, 100,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
#pragma endregion

		#pragma region 绘制双方防御
		if (MyPokemon->defense != 0)
		{
			SelectObject(hdc_loadBmp, bmp_defense);
			TransparentBlt(
				hdc_memBuffer,
				8, 360,			// 界面上起始绘制点
				130, 130,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				26, 400,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(MyPokemon->defense / 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				58, 400,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(MyPokemon->defense % 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		if (RivalPokemon->defense != 0)
		{
			SelectObject(hdc_loadBmp, bmp_defense);
			TransparentBlt(
				hdc_memBuffer,
				825, 160,			// 界面上起始绘制点
				130, 130,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				843, 200,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(RivalPokemon->defense / 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				875, 200,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(RivalPokemon->defense % 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
#pragma endregion
	}
	else if (currentStage->stageID == STAGE_BOSS)
	{
		SelectObject(hdc_loadBmp, bmp_battle_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			1012, 768,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			640, 382,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);

		SelectObject(hdc_loadBmp, MyPokemon->img);
		TransparentBlt(
			hdc_memBuffer,
			MyPokemon->x, 300,			// 界面上起始绘制点
			200, 200,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			MyPokemon->width, MyPokemon->height,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);

		SelectObject(hdc_loadBmp, RivalPokemon->img);
		TransparentBlt(
			hdc_memBuffer,
			RivalPokemon->x, RivalPokemon->y,			// 界面上起始绘制点
			300, 300,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			RivalPokemon->width, RivalPokemon->height,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);

		//绘制数据方格
		SelectObject(hdc_loadBmp, bmp_databox_me);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			390, 93,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			260, 62,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_databox_rival);
		TransparentBlt(
			hdc_memBuffer,
			620, 0,			// 界面上起始绘制点
			390, 93,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			260, 62,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);

		//绘制血量
		if ((double)MyPokemon->heart / MyPokemon->total_heart >= 0.66)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				177, 60,			// 界面上起始绘制点
				(int)(145 * ((double)MyPokemon->heart / MyPokemon->total_heart)), 9,											// 界面上绘制宽度高度
				hdc_loadBmp,
				2, 0,	// 位图上起始绘制点
				90, 6,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else if ((double)MyPokemon->heart / MyPokemon->total_heart >= 0.33)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				177, 60,			// 界面上起始绘制点
				(int)(145 * ((double)MyPokemon->heart / MyPokemon->total_heart)), 9,											// 界面上绘制宽度高度
				hdc_loadBmp,
				2, 6,	// 位图上起始绘制点
				90, 6,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				177, 60,			// 界面上起始绘制点
				(int)(145 * ((double)MyPokemon->heart / MyPokemon->total_heart)), 9,											// 界面上绘制宽度高度
				hdc_loadBmp,
				2, 12,	// 位图上起始绘制点
				90, 6,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}

		if ((double)RivalPokemon->heart / RivalPokemon->total_heart >= 0.66)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				824, 60,			// 界面上起始绘制点
				(int)(145 * ((double)RivalPokemon->heart / RivalPokemon->total_heart)), 9,											// 界面上绘制宽度高度
				hdc_loadBmp,
				2, 0,	// 位图上起始绘制点
				90, 6,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else if ((double)RivalPokemon->heart / RivalPokemon->total_heart >= 0.33)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				824, 60,			// 界面上起始绘制点
				(int)(145 * ((double)RivalPokemon->heart / RivalPokemon->total_heart)), 9,											// 界面上绘制宽度高度
				hdc_loadBmp,
				2, 6,	// 位图上起始绘制点
				90, 6,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				824, 60,			// 界面上起始绘制点
				(int)(145 * ((double)RivalPokemon->heart / RivalPokemon->total_heart)), 9,											// 界面上绘制宽度高度
				hdc_loadBmp,
				2, 12,	// 位图上起始绘制点
				90, 6,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		

		//绘制能量
		for (int i = 1; i <= MyPokemon->energy; i++)
		{
			SelectObject(hdc_loadBmp, bmp_energy);
			TransparentBlt(
				hdc_memBuffer,
				i * 80 + 220, 410,			// 界面上起始绘制点
				64, 64,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				128, 128,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}

		#pragma region 绘制弃牌区抽牌区
		SelectObject(hdc_loadBmp, bmp_draw_cards);
		TransparentBlt(
			hdc_memBuffer,
			8, 560,			// 界面上起始绘制点
			100, 100,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			200, 200,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			10, 650,			// 界面上起始绘制点
			60, 60,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(draw_cards.size() / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			42, 650,			// 界面上起始绘制点
			60, 60,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(draw_cards.size() % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_discarded_cards);
		TransparentBlt(
			hdc_memBuffer,
			900, 560,			// 界面上起始绘制点
			100, 100,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			200, 200,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			902, 650,			// 界面上起始绘制点
			60, 60,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(discarded_cards.size() / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			934, 650,			// 界面上起始绘制点
			60, 60,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(discarded_cards.size() % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
#pragma endregion

		#pragma region	绘制数字HP
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			170, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->heart / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			200, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->heart % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_slash);
		TransparentBlt(
			hdc_memBuffer,
			225, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			250, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->total_heart / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			280, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->total_heart % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);

		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			820, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->heart / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			850, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->heart % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_slash);
		TransparentBlt(
			hdc_memBuffer,
			875, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			900, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->total_heart / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			930, 10,			// 界面上起始绘制点
			45, 45,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->total_heart % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		#pragma endregion

		#pragma region	绘制力量与敏捷
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			65, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->power / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			90, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->power % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_power);
		TransparentBlt(
			hdc_memBuffer,
			83, 50,			// 界面上起始绘制点
			30, 30,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			56, 56,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			5, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->speed / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			30, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(MyPokemon->speed % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_speed);
		TransparentBlt(
			hdc_memBuffer,
			20, 50,			// 界面上起始绘制点
			35, 28,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			100, 80,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);


		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			715, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->power / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			740, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->power % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_power);
		TransparentBlt(
			hdc_memBuffer,
			733, 50,			// 界面上起始绘制点
			30, 30,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			56, 56,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			655, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->speed / 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			680, 10,			// 界面上起始绘制点
			40, 40,											// 界面上绘制宽度高度
			hdc_loadBmp,
			(RivalPokemon->speed % 10) * 50, 0,	// 位图上起始绘制点
			50, 50,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_speed);
		TransparentBlt(
			hdc_memBuffer,
			672, 50,			// 界面上起始绘制点
			35, 28,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			100, 80,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
#pragma endregion

		#pragma region  绘制敌人意图
		if (RivalPokemon->intention == ATTACK)
		{
			SelectObject(hdc_loadBmp, bmp_attack);
			TransparentBlt(
				hdc_memBuffer,
				460, 200,			// 界面上起始绘制点
				80, 80,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				100, 100,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				440, 270,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(RivalPokemon->intention_num / 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				480, 270,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(RivalPokemon->intention_num % 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else if (RivalPokemon->intention == DEFEND)
		{
			SelectObject(hdc_loadBmp, bmp_defense);
			TransparentBlt(
				hdc_memBuffer,
				460, 200,			// 界面上起始绘制点
				80, 80,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				440, 270,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(RivalPokemon->intention_num / 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				480, 270,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(RivalPokemon->intention_num % 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		else if (RivalPokemon->intention == AFFECT)
		{
			SelectObject(hdc_loadBmp, bmp_affect);
			TransparentBlt(
				hdc_memBuffer,
				460, 200,			// 界面上起始绘制点
				80, 80,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				100, 100,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
#pragma endregion

		#pragma region 绘制双方防御
		if (MyPokemon->defense != 0)
		{
			SelectObject(hdc_loadBmp, bmp_defense);
			TransparentBlt(
				hdc_memBuffer,
				8, 360,			// 界面上起始绘制点
				130, 130,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				26, 400,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(MyPokemon->defense / 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				58, 400,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(MyPokemon->defense % 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
		if (RivalPokemon->defense != 0)
		{
			SelectObject(hdc_loadBmp, bmp_defense);
			TransparentBlt(
				hdc_memBuffer,
				830, 160,			// 界面上起始绘制点
				130, 130,											// 界面上绘制宽度高度
				hdc_loadBmp,
				0, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				848, 200,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(RivalPokemon->defense / 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				880, 200,			// 界面上起始绘制点
				60, 60,											// 界面上绘制宽度高度
				hdc_loadBmp,
				(RivalPokemon->defense % 10) * 50, 0,	// 位图上起始绘制点
				50, 50,											// 位图上绘制宽度高度
				RGB(255, 255, 255)
			);
		}
#pragma endregion
	}
	else if (currentStage->stageID == STAGE_WIN)
	{
		SelectObject(hdc_loadBmp, bmp_help_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			1024, 768,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			512, 384,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_win);
		TransparentBlt(
			hdc_memBuffer,
			250, 70,			// 界面上起始绘制点
			480, 360,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			480, 360,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
	}
	else if (currentStage->stageID == STAGE_LOSE)
	{
		SelectObject(hdc_loadBmp, bmp_help_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// 界面上起始绘制点
			1024, 768,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			512, 384,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_lose);
		TransparentBlt(
			hdc_memBuffer,
			300, 100,			// 界面上起始绘制点
			400, 400,											// 界面上绘制宽度高度
			hdc_loadBmp,
			0, 0,	// 位图上起始绘制点
			260, 260,											// 位图上绘制宽度高度
			RGB(255, 255, 255)
		);
	}

	// 绘制按钮

	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			SelectObject(hdc_loadBmp, button->img);
			TransparentBlt(
				hdc_memBuffer, button->x, button->y,
				button->width, button->height,
				hdc_loadBmp, 0, 0, button->width, button->height,
				RGB(255, 255, 255)
			);
		}
	}
	


	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);


	// 回收资源所占的内存（非常重要）
	DeleteObject(blankBmp);
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);


	// 结束绘制
	EndPaint(hWnd, &ps);
}
