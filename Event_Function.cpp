#include "Pokemon_Go.h"

//键盘按下函数
void KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_UP:
		keyUpDown = true;
		break;
	case VK_DOWN:
		keyDownDown = true;
		break;
	case VK_LEFT:
		keyLeftDown = true;
		break;
	case VK_RIGHT:
		keyRightDown = true;
		break;
	case VK_ESCAPE:
		if (currentStage->stageID == STAGE_BATTLE || currentStage->stageID == STAGE_BOSS)
		{
			stop_stage = currentStage->stageID;
			Stage::InitStage(hWnd, STAGE_STOP);
		}
		break;
	default:
		break;
	}
}

//键盘松开函数
void KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_UP:
		keyUpDown = false;
		break;
	case VK_DOWN:
		keyDownDown = false;
		break;
	case VK_LEFT:
		keyLeftDown = false;
		break;
	case VK_RIGHT:
		keyRightDown = false;
		break;
	default:
		break;
	}
}

//鼠标左键按下函数
void LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = true;
	bool have_found = false;
	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->visible && have_found == false)
		{
			if (button->x <= mouseX
				&& button->x + button->width >= mouseX
				&& button->y <= mouseY
				&& button->y + button->height >= mouseY)
			{
				button->Button_Affect(hWnd, wParam, lParam, i, have_found);
			}
		}
	}
}

//鼠标左键松开函数
void LButtonUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = false;
}

//鼠标移动函数
void MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	mouseDown = false;
}

// 初始化游戏窗体函数
void InitGame(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	srand((unsigned)time(NULL));
	//加载图像资源
	bmp_title = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_TITLE));
	bmp_button_start = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_START_BUTTON));
	bmp_button_return = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_RETURN));
	bmp_button_help = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HELP));
	bmp_pikachu = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_PIKACHU));
	bmp_pokemon_2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_POKEMON_2));
	bmp_pokemon_3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_POKEMON_3));
	bmp_pokemon_4 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_POKEMON_4));
	bmp_choose_bg = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CHOOSE_BG));
	bmp_battle_bg = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BATTLE_BG));
	bmp_help_bg = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HELP_BG));
	bmp_route_choose_bg = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_ROUTE_CHOOSE_BG));
	bmp_card_choose_bg = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_CHOOSE_BG));
	bmp_nothing = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NOTHING));
	bmp_boss_route = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BOSS_ROUTE));
	bmp_shop_route = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SHOP_ROUTE));
	bmp_battle_route = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BATTLE_ROUTE));
	bmp_hospital_route = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HOSPITAL_ROUTE));
	bmp_pokeback_1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_POKEBACK_1));
	bmp_pokeback_2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_POKEBACK_2));
	bmp_pokeback_3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_POKEBACK_3));
	bmp_pokeback_4 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_POKEBACK_4));
	bmp_rival_1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_RIVAL_1));
	bmp_rival_2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_RIVAL_2));
	bmp_rival_3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_RIVAL_3));
	bmp_rival_4 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_RIVAL_4));
	bmp_rival_5 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_RIVAL_5));
	bmp_boss = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BOSS));
	bmp_button_skip_card_choose = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SKIP_CARD_CHOOSE));
	bmp_card_1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_1));
	bmp_card_2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_2));
	bmp_card_3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_3));
	bmp_card_4 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_4));
	bmp_card_5 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_5));
	bmp_card_6 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_6));
	bmp_card_7 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_7));
	bmp_card_8 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_8));
	bmp_card_9 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_9));
	bmp_card_10 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_10));
	bmp_card_11 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_11));
	bmp_card_12 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_12));
	bmp_info_1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_INFO_1));
	bmp_info_2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_INFO_2));
	bmp_info_3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_INFO_3));
	bmp_info_4 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_INFO_4));
	bmp_card_wound = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_WOUND));
	bmp_button_stop = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_STOP));
	bmp_button_menu = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_MENU));
	bmp_button_regame = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_REGAME));
	bmp_button_end_round = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_END_ROUND));
	bmp_button_return_game = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_RETURN_GAME));
	bmp_databox_me = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_DATABOX_ME));
	bmp_databox_rival = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_DATABOX_RIVAL));
	bmp_hp_line = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HP_LINE));
	bmp_num = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NUM));
	bmp_slash = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SLASH));
	bmp_lose = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_LOSE));
	bmp_win = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_WIN));
	bmp_attack = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_ATTACK));
	bmp_defense = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_DEFENSE));
	bmp_speed = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SPEED));
	bmp_power = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_POWER));
	bmp_affect = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_AFFECT));
	bmp_energy = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_ENERGY));
	bmp_draw_cards = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_DRAW_CARDS));
	bmp_discarded_cards = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_DISCARDED_CARDS));
	bmp_help_1 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HELP_1));
	bmp_help_2 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HELP_2));
	bmp_help_3 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HELP_3));
	bmp_help_4 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HELP_4));
	bmp_help_5 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HELP_5));
	bmp_help_6 = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HELP_6));
	bmp_button_next_help_page = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NEXT_HELP_PAGE));
	bmp_button_last_help_page = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_LAST_HELP_PAGE));


	//添加按钮
	Button* startButton = Button::CreateButton(BUTTON_STARTGAME, bmp_button_start, 250, 90, 160, 550);
	Button* helpButton = Button::CreateButton(BUTTON_HELP, bmp_button_help, 120, 120, 904, 0);
	Button* returnButton = Button::CreateButton(BUTTON_RETURN, bmp_button_return, 120, 120, 0, 0);
	Button* regameButton = Button::CreateButton(BUTTON_REGAME, bmp_button_regame, 250, 90, 500, 170);
	Button* returngameButton = Button::CreateButton(BUTTON_RETURN_GAME, bmp_button_return_game, 250, 90, 500, 320);
	Button* menuButton = Button::CreateButton(BUTTON_MENU, bmp_button_menu, 250, 90, 500, 470);
	Button* stopButton = Button::CreateButton(BUTTON_STOP, bmp_button_stop, 100, 100, 450, 0);
	Button* pokemonButton_1 = Button::CreateButton(BUTTON_POKEMON_1, bmp_pikachu, 500, 500, 20, 200);
	Button* pokemonButton_2 = Button::CreateButton(BUTTON_POKEMON_2, bmp_pokemon_2, 500, 500, 0, 200);
	Button* pokemonButton_3 = Button::CreateButton(BUTTON_POKEMON_4, bmp_pokemon_4, 500, 500, 0, 200);
	Button* pokemonButton_4 = Button::CreateButton(BUTTON_POKEMON_3, bmp_pokemon_3, 500, 500, 0, 200);
	Button* pokemonButton_change_next = Button::CreateButton(BUTTON_POKEMON_NEXT, bmp_nothing, 120, 120, 904, 0);
	Button* pokemonButton_change_before = Button::CreateButton(BUTTON_POKEMON_BEFORE, bmp_nothing, 120, 120, 0, 0);
	Button* skipcardButton = Button::CreateButton(BUTTON_SKIP_CARD_CHOOSE, bmp_button_skip_card_choose, 250, 90, 680, 625);
	Button* endmenuButton = Button::CreateButton(BUTTON_MENU_END, bmp_button_menu, 250, 90, 370, 450);
	Button* endregameButton = Button::CreateButton(BUTTON_REGAME_END, bmp_button_regame, 250, 90, 370, 570);
	Button* endroundButton = Button::CreateButton(BUTTON_END_ROUND, bmp_button_end_round, 212, 76, 680, 400);
	Button* lasthelppageButton = Button::CreateButton(BUTTON_LAST_HELP_PAGE, bmp_button_last_help_page, 200, 200, 0, 550);
	Button* nexthelppageButton = Button::CreateButton(BUTTON_NEXT_HELP_PAGE, bmp_button_next_help_page, 200, 200, 800, 550);


	//初始化开始场景
	Stage::InitStage(hWnd, STAGE_STARTMENU);

	//初始化主计时器
	SetTimer(hWnd, TIMER_GAMETIMER, TIMER_GAMETIMER_ELAPSE, NULL);
}

//定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	DetectGameState(hWnd);
	//刷新显示
	InvalidateRect(hWnd, NULL, FALSE);
}
