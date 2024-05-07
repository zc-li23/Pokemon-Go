#include "Pokemon_Go.h"

//��ͼ����
void Paint(HWND hWnd)
{

	PAINTSTRUCT ps;
	HDC hdc_window = BeginPaint(hWnd, &ps);

	HDC hdc_memBuffer = CreateCompatibleDC(hdc_window);
	HDC hdc_loadBmp = CreateCompatibleDC(hdc_window);

	//��ʼ������
	HBITMAP	blankBmp = CreateCompatibleBitmap(hdc_window, WINDOW_WIDTH, WINDOW_HEIGHT);
	SelectObject(hdc_memBuffer, blankBmp);
	
	//���Ƴ���
	if (currentStage->stageID == STAGE_STARTMENU)
	{
		SelectObject(hdc_loadBmp, bmp_title);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// ��������ʼ���Ƶ�
			1012, 768,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			1042, 768,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
	}
	else if (currentStage->stageID == STAGE_POKEMON_CHOOSE)
	{
		SelectObject(hdc_loadBmp, bmp_choose_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// ��������ʼ���Ƶ�
			1012, 768,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			324, 296,											// λͼ�ϻ��ƿ�ȸ߶�
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
			475, 250,			// ��������ʼ���Ƶ�
			512, 384,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			512, 384,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
	}
	else if (currentStage->stageID == STAGE_ROUTE_CHOOSE)
	{
		SelectObject(hdc_loadBmp, bmp_route_choose_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// ��������ʼ���Ƶ�
			1012, 768,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			720, 540,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
	}
	else if (currentStage->stageID == STAGE_CARD_CHOOSE)
	{
		SelectObject(hdc_loadBmp, bmp_card_choose_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// ��������ʼ���Ƶ�
			1010, 768,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			512, 384,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		); 
	}
	else if (currentStage->stageID == STAGE_HELP)
	{
		SelectObject(hdc_loadBmp, bmp_help_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// ��������ʼ���Ƶ�
			1024, 768,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			512, 384,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		if (help_page == 0)
		{
			SelectObject(hdc_loadBmp, bmp_help_1);
			TransparentBlt(
				hdc_memBuffer,
				100, 100,			// ��������ʼ���Ƶ�
				800, 500,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				1314, 706,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else if (help_page == 1)
		{
			SelectObject(hdc_loadBmp, bmp_help_2);
			TransparentBlt(
				hdc_memBuffer,
				100, 100,			// ��������ʼ���Ƶ�
				800, 500,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				1183, 700,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else if (help_page == 2)
		{
			SelectObject(hdc_loadBmp, bmp_help_3);
			TransparentBlt(
				hdc_memBuffer,
				100, 100,			// ��������ʼ���Ƶ�
				750, 500,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				1070, 695,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else if (help_page == 3)
		{
			SelectObject(hdc_loadBmp, bmp_help_4);
			TransparentBlt(
				hdc_memBuffer,
				50, 50,			// ��������ʼ���Ƶ�
				900, 600,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				1197, 711,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else if (help_page == 4)
		{
			SelectObject(hdc_loadBmp, bmp_help_5);
			TransparentBlt(
				hdc_memBuffer,
				100, 100,			// ��������ʼ���Ƶ�
				850, 500,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				932, 497,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else if (help_page == 5)
		{
			SelectObject(hdc_loadBmp, bmp_help_6);
			TransparentBlt(
				hdc_memBuffer,
				130, 50,			// ��������ʼ���Ƶ�
				750, 600,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				1292, 969,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
	}
	else if (currentStage->stageID == STAGE_STOP)
	{
		SelectObject(hdc_loadBmp, bmp_help_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// ��������ʼ���Ƶ�
			1024, 768,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			512, 384,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
	}
	else if (currentStage->stageID == STAGE_BATTLE)
	{
		SelectObject(hdc_loadBmp, bmp_battle_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// ��������ʼ���Ƶ�
			1012, 768,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			640, 382,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);

		SelectObject(hdc_loadBmp, MyPokemon->img);
		TransparentBlt(
			hdc_memBuffer,
			MyPokemon->x, 300,			// ��������ʼ���Ƶ�
			200, 200,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			MyPokemon->width, MyPokemon->height,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);

		SelectObject(hdc_loadBmp, RivalPokemon->img);
		TransparentBlt(
			hdc_memBuffer,
			RivalPokemon->x, RivalPokemon->y,			// ��������ʼ���Ƶ�
			300, 300,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			RivalPokemon->width, RivalPokemon->height,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);

		//�������ݷ���
		SelectObject(hdc_loadBmp, bmp_databox_me);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// ��������ʼ���Ƶ�
			390, 93,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			260, 62,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_databox_rival);
		TransparentBlt(
			hdc_memBuffer,
			620, 0,			// ��������ʼ���Ƶ�
			390, 93,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			260, 62,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);


		//����Ѫ��
		if ((double)MyPokemon->heart / MyPokemon->total_heart >= 0.66)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				177, 60,			// ��������ʼ���Ƶ�
				(int)(145 * ((double)MyPokemon->heart / MyPokemon->total_heart)), 9,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				2, 0,	// λͼ����ʼ���Ƶ�
				90, 6,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else if ((double)MyPokemon->heart / MyPokemon->total_heart >= 0.33)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				177, 60,			// ��������ʼ���Ƶ�
				(int)(145 * ((double)MyPokemon->heart / MyPokemon->total_heart)), 9,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				2, 6,	// λͼ����ʼ���Ƶ�
				90, 6,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				177, 60,			// ��������ʼ���Ƶ�
				(int)(145 * ((double)MyPokemon->heart / MyPokemon->total_heart)), 9,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				2, 12,	// λͼ����ʼ���Ƶ�
				90, 6,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}

		if ((double)RivalPokemon->heart / RivalPokemon->total_heart >= 0.66)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				824, 60,			// ��������ʼ���Ƶ�
				(int)(145 * ((double)RivalPokemon->heart / RivalPokemon->total_heart)), 9,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				2, 0,	// λͼ����ʼ���Ƶ�
				90, 6,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else if ((double)RivalPokemon->heart / RivalPokemon->total_heart >= 0.33)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				824, 60,			// ��������ʼ���Ƶ�
				(int)(145 * ((double)RivalPokemon->heart / RivalPokemon->total_heart)), 9,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				2, 6,	// λͼ����ʼ���Ƶ�
				90, 6,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				824, 60,			// ��������ʼ���Ƶ�
				(int)(145 * ((double)RivalPokemon->heart / RivalPokemon->total_heart)), 9,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				2, 12,	// λͼ����ʼ���Ƶ�
				90, 6,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}


		//��������
		for (int i = 1; i <= MyPokemon->energy; i++)
		{
			SelectObject(hdc_loadBmp, bmp_energy);
			TransparentBlt(
				hdc_memBuffer,
				i * 80 + 220, 410,			// ��������ʼ���Ƶ�
				64, 64,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				128, 128,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}

		#pragma region ����������������
		SelectObject(hdc_loadBmp, bmp_draw_cards);
		TransparentBlt(
			hdc_memBuffer,
			8, 560,			// ��������ʼ���Ƶ�
			100, 100,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			200, 200,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			10, 650,			// ��������ʼ���Ƶ�
			60, 60,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(draw_cards.size() / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			42, 650,			// ��������ʼ���Ƶ�
			60, 60,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(draw_cards.size() % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_discarded_cards);
		TransparentBlt(
			hdc_memBuffer,
			900, 560,			// ��������ʼ���Ƶ�
			100, 100,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			200, 200,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			902, 650,			// ��������ʼ���Ƶ�
			60, 60,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(discarded_cards.size() / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			934, 650,			// ��������ʼ���Ƶ�
			60, 60,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(discarded_cards.size() % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
#pragma endregion

		#pragma region	��������HP
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			170, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->heart / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			200, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->heart % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_slash);
		TransparentBlt(
			hdc_memBuffer,
			225, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			250, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->total_heart / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			280, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->total_heart % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);

		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			820, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->heart / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			850, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->heart % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_slash);
		TransparentBlt(
			hdc_memBuffer,
			875, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			900, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->total_heart / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			930, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->total_heart % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		#pragma endregion

		#pragma region	��������������
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			65, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->power / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			90, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->power % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_power);
		TransparentBlt(
			hdc_memBuffer,
			83, 50,			// ��������ʼ���Ƶ�
			30, 30,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			56, 56,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			5, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->speed / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			30, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->speed % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_speed);
		TransparentBlt(
			hdc_memBuffer,
			20, 50,			// ��������ʼ���Ƶ�
			35, 28,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			100, 80,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);


		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			715, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->power / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			740, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->power % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_power);
		TransparentBlt(
			hdc_memBuffer,
			733, 50,			// ��������ʼ���Ƶ�
			30, 30,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			56, 56,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			655, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->speed / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			680, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->speed % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_speed);
		TransparentBlt(
			hdc_memBuffer,
			672, 50,			// ��������ʼ���Ƶ�
			35, 28,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			100, 80,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
#pragma endregion

		#pragma region  ���Ƶ�����ͼ
		if (RivalPokemon->intention == ATTACK)
		{
			SelectObject(hdc_loadBmp, bmp_attack);
			TransparentBlt(
				hdc_memBuffer,
				460, 200,			// ��������ʼ���Ƶ�
				80, 80,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				100, 100,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				440, 270,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(RivalPokemon->intention_num / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				480, 270,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(RivalPokemon->intention_num % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else if (RivalPokemon->intention == DEFEND)
		{
			SelectObject(hdc_loadBmp, bmp_defense);
			TransparentBlt(
				hdc_memBuffer,
				460, 200,			// ��������ʼ���Ƶ�
				80, 80,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				440, 270,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(RivalPokemon->intention_num / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				480, 270,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(RivalPokemon->intention_num % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else if (RivalPokemon->intention == AFFECT)
		{
			SelectObject(hdc_loadBmp, bmp_affect);
			TransparentBlt(
				hdc_memBuffer,
				460, 200,			// ��������ʼ���Ƶ�
				80, 80,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				100, 100,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
#pragma endregion

		#pragma region ����˫������
		if (MyPokemon->defense != 0)
		{
			SelectObject(hdc_loadBmp, bmp_defense);
			TransparentBlt(
				hdc_memBuffer,
				8, 360,			// ��������ʼ���Ƶ�
				130, 130,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				26, 400,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(MyPokemon->defense / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				58, 400,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(MyPokemon->defense % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		if (RivalPokemon->defense != 0)
		{
			SelectObject(hdc_loadBmp, bmp_defense);
			TransparentBlt(
				hdc_memBuffer,
				825, 160,			// ��������ʼ���Ƶ�
				130, 130,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				843, 200,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(RivalPokemon->defense / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				875, 200,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(RivalPokemon->defense % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
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
			0, 0,			// ��������ʼ���Ƶ�
			1012, 768,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			640, 382,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);

		SelectObject(hdc_loadBmp, MyPokemon->img);
		TransparentBlt(
			hdc_memBuffer,
			MyPokemon->x, 300,			// ��������ʼ���Ƶ�
			200, 200,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			MyPokemon->width, MyPokemon->height,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);

		SelectObject(hdc_loadBmp, RivalPokemon->img);
		TransparentBlt(
			hdc_memBuffer,
			RivalPokemon->x, RivalPokemon->y,			// ��������ʼ���Ƶ�
			300, 300,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			RivalPokemon->width, RivalPokemon->height,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);

		//�������ݷ���
		SelectObject(hdc_loadBmp, bmp_databox_me);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// ��������ʼ���Ƶ�
			390, 93,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			260, 62,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_databox_rival);
		TransparentBlt(
			hdc_memBuffer,
			620, 0,			// ��������ʼ���Ƶ�
			390, 93,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			260, 62,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);

		//����Ѫ��
		if ((double)MyPokemon->heart / MyPokemon->total_heart >= 0.66)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				177, 60,			// ��������ʼ���Ƶ�
				(int)(145 * ((double)MyPokemon->heart / MyPokemon->total_heart)), 9,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				2, 0,	// λͼ����ʼ���Ƶ�
				90, 6,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else if ((double)MyPokemon->heart / MyPokemon->total_heart >= 0.33)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				177, 60,			// ��������ʼ���Ƶ�
				(int)(145 * ((double)MyPokemon->heart / MyPokemon->total_heart)), 9,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				2, 6,	// λͼ����ʼ���Ƶ�
				90, 6,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				177, 60,			// ��������ʼ���Ƶ�
				(int)(145 * ((double)MyPokemon->heart / MyPokemon->total_heart)), 9,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				2, 12,	// λͼ����ʼ���Ƶ�
				90, 6,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}

		if ((double)RivalPokemon->heart / RivalPokemon->total_heart >= 0.66)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				824, 60,			// ��������ʼ���Ƶ�
				(int)(145 * ((double)RivalPokemon->heart / RivalPokemon->total_heart)), 9,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				2, 0,	// λͼ����ʼ���Ƶ�
				90, 6,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else if ((double)RivalPokemon->heart / RivalPokemon->total_heart >= 0.33)
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				824, 60,			// ��������ʼ���Ƶ�
				(int)(145 * ((double)RivalPokemon->heart / RivalPokemon->total_heart)), 9,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				2, 6,	// λͼ����ʼ���Ƶ�
				90, 6,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else
		{
			SelectObject(hdc_loadBmp, bmp_hp_line);
			TransparentBlt(
				hdc_memBuffer,
				824, 60,			// ��������ʼ���Ƶ�
				(int)(145 * ((double)RivalPokemon->heart / RivalPokemon->total_heart)), 9,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				2, 12,	// λͼ����ʼ���Ƶ�
				90, 6,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		

		//��������
		for (int i = 1; i <= MyPokemon->energy; i++)
		{
			SelectObject(hdc_loadBmp, bmp_energy);
			TransparentBlt(
				hdc_memBuffer,
				i * 80 + 220, 410,			// ��������ʼ���Ƶ�
				64, 64,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				128, 128,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}

		#pragma region ����������������
		SelectObject(hdc_loadBmp, bmp_draw_cards);
		TransparentBlt(
			hdc_memBuffer,
			8, 560,			// ��������ʼ���Ƶ�
			100, 100,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			200, 200,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			10, 650,			// ��������ʼ���Ƶ�
			60, 60,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(draw_cards.size() / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			42, 650,			// ��������ʼ���Ƶ�
			60, 60,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(draw_cards.size() % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_discarded_cards);
		TransparentBlt(
			hdc_memBuffer,
			900, 560,			// ��������ʼ���Ƶ�
			100, 100,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			200, 200,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			902, 650,			// ��������ʼ���Ƶ�
			60, 60,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(discarded_cards.size() / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			934, 650,			// ��������ʼ���Ƶ�
			60, 60,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(discarded_cards.size() % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
#pragma endregion

		#pragma region	��������HP
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			170, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->heart / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			200, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->heart % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_slash);
		TransparentBlt(
			hdc_memBuffer,
			225, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			250, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->total_heart / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			280, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->total_heart % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);

		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			820, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->heart / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			850, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->heart % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_slash);
		TransparentBlt(
			hdc_memBuffer,
			875, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			900, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->total_heart / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			930, 10,			// ��������ʼ���Ƶ�
			45, 45,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->total_heart % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		#pragma endregion

		#pragma region	��������������
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			65, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->power / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			90, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->power % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_power);
		TransparentBlt(
			hdc_memBuffer,
			83, 50,			// ��������ʼ���Ƶ�
			30, 30,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			56, 56,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			5, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->speed / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			30, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(MyPokemon->speed % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_speed);
		TransparentBlt(
			hdc_memBuffer,
			20, 50,			// ��������ʼ���Ƶ�
			35, 28,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			100, 80,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);


		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			715, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->power / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			740, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->power % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_power);
		TransparentBlt(
			hdc_memBuffer,
			733, 50,			// ��������ʼ���Ƶ�
			30, 30,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			56, 56,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			655, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->speed / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_num);
		TransparentBlt(
			hdc_memBuffer,
			680, 10,			// ��������ʼ���Ƶ�
			40, 40,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			(RivalPokemon->speed % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
			50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_speed);
		TransparentBlt(
			hdc_memBuffer,
			672, 50,			// ��������ʼ���Ƶ�
			35, 28,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			100, 80,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
#pragma endregion

		#pragma region  ���Ƶ�����ͼ
		if (RivalPokemon->intention == ATTACK)
		{
			SelectObject(hdc_loadBmp, bmp_attack);
			TransparentBlt(
				hdc_memBuffer,
				460, 200,			// ��������ʼ���Ƶ�
				80, 80,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				100, 100,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				440, 270,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(RivalPokemon->intention_num / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				480, 270,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(RivalPokemon->intention_num % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else if (RivalPokemon->intention == DEFEND)
		{
			SelectObject(hdc_loadBmp, bmp_defense);
			TransparentBlt(
				hdc_memBuffer,
				460, 200,			// ��������ʼ���Ƶ�
				80, 80,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				440, 270,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(RivalPokemon->intention_num / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				480, 270,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(RivalPokemon->intention_num % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		else if (RivalPokemon->intention == AFFECT)
		{
			SelectObject(hdc_loadBmp, bmp_affect);
			TransparentBlt(
				hdc_memBuffer,
				460, 200,			// ��������ʼ���Ƶ�
				80, 80,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				100, 100,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
#pragma endregion

		#pragma region ����˫������
		if (MyPokemon->defense != 0)
		{
			SelectObject(hdc_loadBmp, bmp_defense);
			TransparentBlt(
				hdc_memBuffer,
				8, 360,			// ��������ʼ���Ƶ�
				130, 130,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				26, 400,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(MyPokemon->defense / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				58, 400,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(MyPokemon->defense % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
		}
		if (RivalPokemon->defense != 0)
		{
			SelectObject(hdc_loadBmp, bmp_defense);
			TransparentBlt(
				hdc_memBuffer,
				830, 160,			// ��������ʼ���Ƶ�
				130, 130,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				0, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				848, 200,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(RivalPokemon->defense / 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
				RGB(255, 255, 255)
			);
			SelectObject(hdc_loadBmp, bmp_num);
			TransparentBlt(
				hdc_memBuffer,
				880, 200,			// ��������ʼ���Ƶ�
				60, 60,											// �����ϻ��ƿ�ȸ߶�
				hdc_loadBmp,
				(RivalPokemon->defense % 10) * 50, 0,	// λͼ����ʼ���Ƶ�
				50, 50,											// λͼ�ϻ��ƿ�ȸ߶�
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
			0, 0,			// ��������ʼ���Ƶ�
			1024, 768,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			512, 384,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_win);
		TransparentBlt(
			hdc_memBuffer,
			250, 70,			// ��������ʼ���Ƶ�
			480, 360,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			480, 360,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
	}
	else if (currentStage->stageID == STAGE_LOSE)
	{
		SelectObject(hdc_loadBmp, bmp_help_bg);
		TransparentBlt(
			hdc_memBuffer,
			0, 0,			// ��������ʼ���Ƶ�
			1024, 768,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			512, 384,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
		SelectObject(hdc_loadBmp, bmp_lose);
		TransparentBlt(
			hdc_memBuffer,
			300, 100,			// ��������ʼ���Ƶ�
			400, 400,											// �����ϻ��ƿ�ȸ߶�
			hdc_loadBmp,
			0, 0,	// λͼ����ʼ���Ƶ�
			260, 260,											// λͼ�ϻ��ƿ�ȸ߶�
			RGB(255, 255, 255)
		);
	}

	// ���ư�ť

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
	


	// ������е���Ϣ���Ƶ���Ļ��
	BitBlt(hdc_window, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, hdc_memBuffer, 0, 0, SRCCOPY);


	// ������Դ��ռ���ڴ棨�ǳ���Ҫ��
	DeleteObject(blankBmp);
	DeleteDC(hdc_memBuffer);
	DeleteDC(hdc_loadBmp);


	// ��������
	EndPaint(hWnd, &ps);
}
