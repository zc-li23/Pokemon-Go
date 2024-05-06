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
			InitStage(hWnd, STAGE_STOP);
		}
		break;
	default:
		break;
	}
}

//创建按钮函数
Button* CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y)
{
	Button* button = new Button(buttonID, img, width, height, x, y);
	buttons.push_back(button);
	return button;
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
				switch (button->buttonID)
				{
				case BUTTON_HELP:
				{
					PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
					InitStage(hWnd, STAGE_HELP);
					have_found = true;
					break;
				}
				case BUTTON_RETURN:
				{
					PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
					InitStage(hWnd, STAGE_STARTMENU);
					have_found = true;
					break;
				}
				case BUTTON_MENU:
				{
					PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
					InitStage(hWnd, STAGE_STARTMENU);
					have_found = true;
					break;
				}
				case BUTTON_MENU_END:
				{
					PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
					InitStage(hWnd, STAGE_STARTMENU);
					have_found = true;
					break;
				}
				case BUTTON_STOP:
				{
					PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
					stop_stage = currentStage->stageID;
					InitStage(hWnd, STAGE_STOP);
					have_found = true;
					break;
				}
				case BUTTON_RETURN_GAME:
				{
					PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
					if (stop_stage == STAGE_BATTLE) InitStage(hWnd, STAGE_BATTLE);
					if (stop_stage == STAGE_BOSS) InitStage(hWnd, STAGE_BOSS);
					have_found = true;
					break;
				}
				case BUTTON_REGAME:
				{
					PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
					DeleteData(hWnd);
					MyPokemon->heart = MyPokemon->total_heart;
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					//添加卡牌
					cards.push_back(CreateCard(NORMAL_ATTACK));
					cards.push_back(CreateCard(NORMAL_ATTACK));
					cards.push_back(CreateCard(NORMAL_DEFEND));
					cards.push_back(CreateCard(NORMAL_DEFEND));
					cards.push_back(CreateCard(NORMAL_ATTACK));
					cards.push_back(CreateCard(NORMAL_DEFEND));
					cards.push_back(CreateCard(NORMAL_DEFEND));
					cards.push_back(CreateCard(VOLT_ATTACK));
					have_found = true;
					break;
				}
				case BUTTON_REGAME_END:
				{
					PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
					DeleteData(hWnd);
					MyPokemon->heart = MyPokemon->total_heart;
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					//添加卡牌
					cards.push_back(CreateCard(NORMAL_ATTACK));
					cards.push_back(CreateCard(NORMAL_ATTACK));
					cards.push_back(CreateCard(NORMAL_DEFEND));
					cards.push_back(CreateCard(NORMAL_DEFEND));
					cards.push_back(CreateCard(NORMAL_ATTACK));
					cards.push_back(CreateCard(NORMAL_DEFEND));
					cards.push_back(CreateCard(NORMAL_DEFEND));
					cards.push_back(CreateCard(VOLT_ATTACK));
					have_found = true;
					break;
				}
				case BUTTON_STARTGAME:
				{
					InitStage(hWnd, STAGE_POKEMON_CHOOSE);
					//添加卡牌
					cards.push_back(CreateCard(NORMAL_ATTACK));
					cards.push_back(CreateCard(NORMAL_ATTACK));
					cards.push_back(CreateCard(NORMAL_DEFEND));
					cards.push_back(CreateCard(NORMAL_DEFEND));
					cards.push_back(CreateCard(NORMAL_ATTACK));
					cards.push_back(CreateCard(NORMAL_DEFEND));
					cards.push_back(CreateCard(NORMAL_DEFEND));
					cards.push_back(CreateCard(VOLT_ATTACK));
					have_found = true;
					break;
				}
				case BUTTON_NEXT_HELP_PAGE:
				{
					PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
					help_page = (help_page + 1) % 6;
					have_found = true;
					break;
				}
				case BUTTON_LAST_HELP_PAGE:
				{
					PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
					help_page = (help_page + 5) % 6;
					have_found = true;
					break;
				}
				case BUTTON_POKEMON_NEXT:
				{
					pokemon_select = (pokemon_select + 1) % 4;
					InitStage(hWnd, STAGE_POKEMON_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_POKEMON_BEFORE:
				{
					pokemon_select = (pokemon_select + 3) % 4;
					InitStage(hWnd, STAGE_POKEMON_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_POKEMON_1:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					MyPokemon->img = bmp_pokeback_1;
					MyPokemon->full_energy = 4;
					MyPokemon->energy = MyPokemon->full_energy;
					MyPokemon->power = 0;
					MyPokemon->total_heart = 45;
					MyPokemon->defense = 0;
					MyPokemon->heart = MyPokemon->total_heart;
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_POKEMON_2:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					MyPokemon->img = bmp_pokeback_2;
					MyPokemon->full_energy = 3;
					MyPokemon->energy = MyPokemon->full_energy;
					MyPokemon->total_heart = 50;
					MyPokemon->defense = 0;
					MyPokemon->power = 4;
					MyPokemon->heart = MyPokemon->total_heart;
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_POKEMON_3:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					MyPokemon->img = bmp_pokeback_3; 
					MyPokemon->full_energy = 3;
					MyPokemon->energy = MyPokemon->full_energy;
					MyPokemon->power = 0;
					MyPokemon->defense = 0;
					MyPokemon->total_heart = 80;
					MyPokemon->heart = MyPokemon->total_heart;
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_POKEMON_4:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					MyPokemon->img = bmp_pokeback_4;
					MyPokemon->full_energy = 3;
					MyPokemon->energy = MyPokemon->full_energy;
					MyPokemon->power = 0;
					MyPokemon->total_heart = 60;
					MyPokemon->speed = 5;
					MyPokemon->heart = MyPokemon->total_heart;
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_HOSPITAL_ROUTE:
				{
					PlaySound(MAKEINTRESOURCE(IDR_HEAL), NULL, SND_RESOURCE | SND_SYNC);
					delete buttons[i];
					buttons.erase(buttons.begin() + i);
					MyPokemon->heart += 10;
					if (MyPokemon->heart > MyPokemon->total_heart) MyPokemon->heart = MyPokemon->total_heart;
					RefreshRoute(hWnd);
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_SHOP_ROUTE:
				{
					PlaySound(MAKEINTRESOURCE(IDR_WIN_BATTLE), NULL, SND_RESOURCE | SND_ASYNC);
					delete buttons[i];
					buttons.erase(buttons.begin() + i);
					RefreshRoute(hWnd);
					InitStage(hWnd, STAGE_CARD_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_BATTLE_ROUTE:
				{
					PlaySound(MAKEINTRESOURCE(IDR_BATTLE), NULL, SND_RESOURCE | SND_ASYNC);
					round_num = 1;
					delete buttons[i];
					buttons.erase(buttons.begin() + i);
					StartBattle(hWnd);
					CreateRival(hWnd, 0);
					RefreshRoute(hWnd);
					InitStage(hWnd, STAGE_BATTLE);
					have_found = true;
					break;
				}
				case BUTTON_BOSS_ROUTE:
				{
					PlaySound(MAKEINTRESOURCE(IDR_BATTLE), NULL, SND_RESOURCE | SND_ASYNC);
					round_num = 1;
					delete buttons[i];
					buttons.erase(buttons.begin() + i);
					CreateRival(hWnd, 1);
					StartBattle(hWnd);
					InitStage(hWnd, STAGE_BOSS);
					have_found = true;
					break;
				}
				case BUTTON_SKIP_CARD_CHOOSE:
				{
					PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
					DeleteCardChoose(hWnd);
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_CARD_CHOOSE_1:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					DeleteCardChoose(hWnd);
					cards.push_back(CreateCard(1));
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_CARD_CHOOSE_2:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					DeleteCardChoose(hWnd);
					cards.push_back(CreateCard(2));
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_CARD_CHOOSE_3:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					DeleteCardChoose(hWnd);
					cards.push_back(CreateCard(3));
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_CARD_CHOOSE_4:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					DeleteCardChoose(hWnd);
					cards.push_back(CreateCard(4));
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_CARD_CHOOSE_5:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					DeleteCardChoose(hWnd);
					cards.push_back(CreateCard(5));
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_CARD_CHOOSE_6:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					DeleteCardChoose(hWnd);
					cards.push_back(CreateCard(6));
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_CARD_CHOOSE_7:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					DeleteCardChoose(hWnd);
					cards.push_back(CreateCard(7));
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_CARD_CHOOSE_8:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					DeleteCardChoose(hWnd);
					cards.push_back(CreateCard(8));
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_CARD_CHOOSE_9:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					DeleteCardChoose(hWnd);
					cards.push_back(CreateCard(9));
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_CARD_CHOOSE_10:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					DeleteCardChoose(hWnd);
					cards.push_back(CreateCard(10));
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_CARD_CHOOSE_11:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					DeleteCardChoose(hWnd);
					cards.push_back(CreateCard(11));
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_CARD_CHOOSE_12:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
					DeleteCardChoose(hWnd);
					cards.push_back(CreateCard(12));
					InitStage(hWnd, STAGE_ROUTE_CHOOSE);
					have_found = true;
					break;
				}
				case BUTTON_CARD_1:
				{
					PlayCard(hWnd, 1);
					have_found = true;
					break;
				}
				case BUTTON_CARD_2:
				{
					PlayCard(hWnd, 2);
					have_found = true;
					break;
				}
				case BUTTON_CARD_3:
				{
					PlayCard(hWnd, 3);
					have_found = true;
					break;
				}
				case BUTTON_CARD_4:
				{
					PlayCard(hWnd, 4);
					have_found = true;
					break;
				}
				case BUTTON_END_ROUND:
				{
					PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_SYNC);
					EndRound(hWnd,round_num);
					have_found = true;
					break;
				}
				default:break;
				}
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
	DetectMouse(hWnd, wParam, lParam);
}

//初始化游戏场景函数
void InitStage(HWND hWnd, int stageID)
{
	// 初始化场景实例
	if (currentStage != NULL) delete currentStage;
	currentStage = new Stage();
	currentStage->stageID = stageID;

	if (stageID == STAGE_STARTMENU)
	{
		currentStage->timeCountDown = 0;
		currentStage->timerOn = false;

		DeleteData(hWnd); 
		PlaySound(MAKEINTRESOURCE(IDR_BGM), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
		//显示开始界面的按钮
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_STARTGAME)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_HELP)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID == STAGE_HELP)
	{
		help_page = 0;
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];

			if (button->buttonID == BUTTON_RETURN)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_NEXT_HELP_PAGE)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_LAST_HELP_PAGE)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID == STAGE_ROUTE_CHOOSE)
	{
		RouteChoose(hWnd);
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];

			if (button->buttonID == BUTTON_RETURN)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_BATTLE_ROUTE)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_HOSPITAL_ROUTE)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_SHOP_ROUTE)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_BOSS_ROUTE)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID == STAGE_POKEMON_CHOOSE)
	{
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_POKEMON_1 && pokemon_select == 0)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_POKEMON_2 && pokemon_select == 1)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_POKEMON_3 && pokemon_select == 2)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_POKEMON_4 && pokemon_select == 3)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_POKEMON_NEXT)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_POKEMON_BEFORE)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID == STAGE_CARD_CHOOSE)
	{
		CardChoose(hWnd);
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];

			if (button->buttonID == BUTTON_SKIP_CARD_CHOOSE)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_CHOOSE_1)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_CHOOSE_2)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_CHOOSE_3)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_CHOOSE_4)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_CHOOSE_5)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_CHOOSE_6)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_CHOOSE_7)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_CHOOSE_8)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_CHOOSE_9)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_CHOOSE_10)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_CHOOSE_11)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_CHOOSE_12)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID == STAGE_BATTLE)
	{
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_STOP)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_1)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_END_ROUND)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_2)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_3)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_4)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID == STAGE_STOP)
	{
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_REGAME)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_RETURN_GAME)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_MENU)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID == STAGE_BOSS)
	{
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_STOP)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_1)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_END_ROUND)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_2)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_3)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_CARD_4)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
		}
	else if (stageID == STAGE_WIN)
	{
		PlaySound(MAKEINTRESOURCE(IDR_WIN), NULL, SND_RESOURCE | SND_ASYNC);
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_REGAME_END)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_MENU_END)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	else if (stageID == STAGE_LOSE)
	{
		PlaySound(MAKEINTRESOURCE(IDR_LOSE), NULL, SND_RESOURCE | SND_ASYNC);
		for (int i = 0; i < buttons.size(); i++)
		{
			Button* button = buttons[i];
			if (button->buttonID == BUTTON_REGAME_END)
			{
				button->visible = true;
			}
			else if (button->buttonID == BUTTON_MENU_END)
			{
				button->visible = true;
			}
			else
			{
				button->visible = false;
			}
		}
	}
	//刷新显示
	InvalidateRect(hWnd, NULL, FALSE);
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
	bmp_consumed_energy = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CONSUMED_ENERGY));
	bmp_lack_energy = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_LACK_ENERGY));
	bmp_help_bg = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_HELP_BG));
	bmp_route_choose_bg = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_ROUTE_CHOOSE_BG));
	bmp_card_choose_bg = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_CHOOSE_BG));
	bmp_nothing = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_NOTHING));
	bmp_boss_route = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_BOSS_ROUTE));
	bmp_shop_route = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_SHOP_ROUTE));
	bmp_card_select = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_CARD_SELECT));
	bmp_attack_act = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_ATTACK_ACT));
	bmp_defend_act = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance, MAKEINTRESOURCE(IDB_DEFEND_ACT));
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
	Button* startButton = CreateButton(BUTTON_STARTGAME, bmp_button_start, 250, 90, 160, 550);
	Button* helpButton = CreateButton(BUTTON_HELP, bmp_button_help, 120, 120, 904, 0);
	Button* returnButton = CreateButton(BUTTON_RETURN, bmp_button_return, 120, 120, 0, 0);
	Button* regameButton = CreateButton(BUTTON_REGAME, bmp_button_regame, 250, 90, 500, 170);
	Button* returngameButton = CreateButton(BUTTON_RETURN_GAME, bmp_button_return_game, 250, 90, 500, 320);
	Button* menuButton = CreateButton(BUTTON_MENU, bmp_button_menu, 250, 90, 500, 470);
	Button* stopButton = CreateButton(BUTTON_STOP, bmp_button_stop, 100, 100, 450, 0);
	Button* pokemonButton_1 = CreateButton(BUTTON_POKEMON_1, bmp_pikachu, 500, 500, 20, 200);
	Button* pokemonButton_2 = CreateButton(BUTTON_POKEMON_2, bmp_pokemon_2, 500, 500, 0, 200);
	Button* pokemonButton_3 = CreateButton(BUTTON_POKEMON_4, bmp_pokemon_4, 500, 500, 0, 200);
	Button* pokemonButton_4 = CreateButton(BUTTON_POKEMON_3, bmp_pokemon_3, 500, 500, 0, 200);
	Button* pokemonButton_change_next = CreateButton(BUTTON_POKEMON_NEXT, bmp_nothing, 120, 120, 904, 0);
	Button* pokemonButton_change_before = CreateButton(BUTTON_POKEMON_BEFORE, bmp_nothing, 120, 120, 0, 0);
	Button* skipcardButton = CreateButton(BUTTON_SKIP_CARD_CHOOSE, bmp_button_skip_card_choose, 250, 90, 680, 625);
	Button* endmenuButton = CreateButton(BUTTON_MENU_END, bmp_button_menu, 250, 90, 370, 450);
	Button* endregameButton = CreateButton(BUTTON_REGAME_END, bmp_button_regame, 250, 90, 370, 570);
	Button* endroundButton = CreateButton(BUTTON_END_ROUND, bmp_button_end_round, 212, 76, 680, 400);
	Button* lasthelppageButton = CreateButton(BUTTON_LAST_HELP_PAGE, bmp_button_last_help_page, 200, 200, 0, 550);
	Button* nexthelppageButton = CreateButton(BUTTON_NEXT_HELP_PAGE, bmp_button_next_help_page, 200, 200, 800, 550);


	//初始化开始场景
	InitStage(hWnd, STAGE_STARTMENU);

	//初始化主计时器
	SetTimer(hWnd, TIMER_GAMETIMER, TIMER_GAMETIMER_ELAPSE, NULL);
}

//定时器事件处理函数
void TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	DetectGameState(hWnd);
	//刷新显示
	InvalidateRect(hWnd, NULL, FALSE);
	if (attack_on)
	{
		attack_frame_id++;
		if (attack_frame_id >= FRAMES_ATTACK_COUNT)
		{
			attack_on = 0;
			attack_frame_id = 0;
		}
	}
	if (defend_on)
	{
		defend_frame_id++;
		if (defend_frame_id >= FRAMES_DEFEND_COUNT)
		{
			defend_on = 0;
			defend_frame_id = 0;
		}
	}
}

//路线选择函数
void RouteChoose(HWND hWnd)
{
	if (route_num == 0)
	{
		if (left_route == 0)
		{
			int temp = rand()%5;
			if (temp <= 2)
			{
				bmp_left_route = bmp_battle_route;
				left_route = BUTTON_BATTLE_ROUTE;
			}
			else if (temp == 3)
			{
				bmp_left_route = bmp_shop_route;
				left_route = BUTTON_SHOP_ROUTE;
			}
			else
			{
				bmp_left_route = bmp_hospital_route;
				left_route = BUTTON_HOSPITAL_ROUTE;
			}
		}
		if (mid_route == 0)
		{
			int temp = rand() % 5;
			if (temp <= 2)
			{
				bmp_mid_route = bmp_battle_route;
				mid_route = BUTTON_BATTLE_ROUTE;
			}
			else if (temp == 3)
			{
				bmp_mid_route = bmp_shop_route;
				mid_route = BUTTON_SHOP_ROUTE;
			}
			else
			{
				bmp_mid_route = bmp_hospital_route;
				mid_route = BUTTON_HOSPITAL_ROUTE;
			}
		}
		if (right_route == 0)
		{
			int temp = rand() % 5;
			if (temp <= 2)
			{
				bmp_right_route = bmp_battle_route;
				right_route = BUTTON_BATTLE_ROUTE;
			}
			else if (temp == 3)
			{
				bmp_right_route = bmp_shop_route;
				right_route = BUTTON_SHOP_ROUTE;
			}
			else
			{
				bmp_right_route = bmp_hospital_route;
				right_route = BUTTON_HOSPITAL_ROUTE;
			}
		}
		Button* left_routeButton = CreateButton(left_route, bmp_left_route, 200, 200, 150, 250);
		Button* mid_routeButton = CreateButton(mid_route, bmp_mid_route, 200, 200, 400, 250);
		Button* right_routeButton = CreateButton(right_route, bmp_right_route, 200, 200, 650, 250);
	}
	else if (route_num < 10)
	{
		if (left_route == 0)
		{
			int temp = rand() % 5;
			if (temp <= 2)
			{
				bmp_left_route = bmp_battle_route;
				left_route = BUTTON_BATTLE_ROUTE;
			}
			else if (temp == 3)
			{
				bmp_left_route = bmp_shop_route;
				left_route = BUTTON_SHOP_ROUTE;
			}
			else
			{
				bmp_left_route = bmp_hospital_route;
				left_route = BUTTON_HOSPITAL_ROUTE;
			}
			Button* left_routeButton = CreateButton(left_route, bmp_left_route, 200, 200, 150, 250);
		}
		else if (mid_route == 0)
		{
			int temp = rand() % 5;
			if (temp <= 2)
			{
				bmp_mid_route = bmp_battle_route;
				mid_route = BUTTON_BATTLE_ROUTE;
			}
			else if (temp == 3)
			{
				bmp_mid_route = bmp_shop_route;
				mid_route = BUTTON_SHOP_ROUTE;
			}
			else
			{
				bmp_mid_route = bmp_hospital_route;
				mid_route = BUTTON_HOSPITAL_ROUTE;
			}
			Button* mid_routeButton = CreateButton(mid_route, bmp_mid_route, 200, 200, 400, 250);
		}
		else if (right_route == 0)
		{
			int temp = rand() % 5;
			if (temp <= 2)
			{
				bmp_right_route = bmp_battle_route;
				right_route = BUTTON_BATTLE_ROUTE;
			}
			else if (temp == 3)
			{
				bmp_right_route = bmp_shop_route;
				right_route = BUTTON_SHOP_ROUTE;
			}
			else
			{
				bmp_right_route = bmp_hospital_route;
				right_route = BUTTON_HOSPITAL_ROUTE;
			}
		Button* right_routeButton = CreateButton(right_route, bmp_right_route, 200, 200, 650, 250);
		}
	}
	else if(route_num == 10)
	{
		if (left_route == 0)
		{
			Button* left_routeButton = CreateButton(BUTTON_BOSS_ROUTE, bmp_boss_route, 200, 200, 150, 250);
		}
		else if (mid_route == 0)
		{
		Button* mid_routeButton = CreateButton(BUTTON_BOSS_ROUTE, bmp_boss_route, 200, 200, 400, 250);
		}
		else if (right_route == 0)
		{
		Button* right_routeButton = CreateButton(BUTTON_BOSS_ROUTE, bmp_boss_route, 200, 200, 650, 250);
		}
	}
	return;
}

//刷新游戏函数
void DeleteData(HWND hWnd)
{
	route_num = 0;
	pokemon_select = 0;
	bmp_left_route = NULL;
	bmp_mid_route = NULL;
	bmp_right_route = NULL;
	for (int i = 0; i < cards.size(); i++)
	{
		if (cards[i] != nullptr) {
			delete cards[i];
			cards[i] = nullptr;  // 避免悬挂指针  
		}
	}
	if (!cards.empty()) cards.clear();
	for (int i = 0; i < buttons.size(); i++)
	{
		if (buttons[i] != nullptr)
		{
			if (buttons[i]->buttonID == BUTTON_BATTLE_ROUTE || buttons[i]->buttonID == BUTTON_BOSS_ROUTE ||
				buttons[i]->buttonID == BUTTON_HOSPITAL_ROUTE || buttons[i]->buttonID == BUTTON_SHOP_ROUTE)
			{
				delete buttons[i];
				buttons[i] = nullptr;  // 避免悬挂指针  
				buttons.erase(buttons.begin() + i);
				i--;
			}
		}
	}
	left_route = mid_route = right_route = 0;
	DeleteCard(hWnd);
	return;
}

//刷新新路线函数
void RefreshRoute(HWND hWnd)
{
	route_num++;
	if (150 <= mouseX && 350 >= mouseX)
	{
		left_route = 0;
	}
	else if (400 <= mouseX && 600 >= mouseX)
	{
		mid_route = 0;
	}
	else if (650 <= mouseX && 850 >= mouseX)
	{
		right_route = 0;
	}
	return;
}

//创建对手函数
void CreateRival(HWND hWnd,bool boss)
{
	if (boss == 0)
	{
		int temp = rand() % 5;
		if (temp == 0)
		{
			RivalPokemon->total_heart = 60;
			RivalPokemon->heart = RivalPokemon->total_heart;
			RivalPokemon->img = bmp_rival_5;
			RivalPokemon->id = 5;
		}
		else if (temp == 1)
		{
			RivalPokemon->total_heart = 40;
			RivalPokemon->heart = RivalPokemon->total_heart;
			RivalPokemon->img = bmp_rival_1;
			RivalPokemon->id = 1;
		}
		else if (temp == 2)
		{
			RivalPokemon->total_heart = 50;
			RivalPokemon->heart = RivalPokemon->total_heart;
			RivalPokemon->img = bmp_rival_2;
			RivalPokemon->id = 2;
		}
		else if (temp == 3)
		{
			RivalPokemon->total_heart = 70;
			RivalPokemon->heart = RivalPokemon->total_heart;
			RivalPokemon->img = bmp_rival_3;
			RivalPokemon->id = 3;
		}
		else if (temp == 4)
		{
			RivalPokemon->total_heart = 90;
			RivalPokemon->heart = RivalPokemon->total_heart;
			RivalPokemon->img = bmp_rival_4;
			RivalPokemon->id = 4;
		}
	}
	else
	{
		RivalPokemon->total_heart = 90;
		RivalPokemon->heart = RivalPokemon->total_heart;
		RivalPokemon->img = bmp_boss;
		RivalPokemon->id = 0;
	}
	return;
}

//随机卡牌选择函数
void CardChoose(HWND hWnd)
{
	int temp = rand() % 12;
	if (temp == 0)
	{
		bmp_left_card = bmp_card_1;
		left_card = BUTTON_CARD_CHOOSE_1;
	}
	else if (temp == 1)
	{
		bmp_left_card = bmp_card_2;
		left_card = BUTTON_CARD_CHOOSE_2;
	}
	else if (temp == 2)
	{
		bmp_left_card = bmp_card_3;
		left_card = BUTTON_CARD_CHOOSE_3;
	}
	else if (temp == 3)
	{
		bmp_left_card = bmp_card_4;
		left_card = BUTTON_CARD_CHOOSE_4;
	}
	else if (temp == 4)
	{
		bmp_left_card = bmp_card_5;
		left_card = BUTTON_CARD_CHOOSE_5;
	}
	else if (temp == 5)
	{
		bmp_left_card = bmp_card_6;
		left_card = BUTTON_CARD_CHOOSE_6;
	}
	else if (temp == 6)
	{
		bmp_left_card = bmp_card_7;
		left_card = BUTTON_CARD_CHOOSE_7;
	}
	else if (temp == 7)
	{
		bmp_left_card = bmp_card_8;
		left_card = BUTTON_CARD_CHOOSE_8;
	}
	else if (temp == 8)
	{
		bmp_left_card = bmp_card_9;
		left_card = BUTTON_CARD_CHOOSE_9;
	}
	else if (temp == 9)
	{
		bmp_left_card = bmp_card_10;
		left_card = BUTTON_CARD_CHOOSE_10;
	}
	else if (temp == 10)
	{
		bmp_left_card = bmp_card_11;
		left_card = BUTTON_CARD_CHOOSE_11;
	}
	else if (temp == 11)
	{
		bmp_left_card = bmp_card_12;
		left_card = BUTTON_CARD_CHOOSE_12;
	}
	temp = rand() % 12;
	if (temp == 0)
	{
		bmp_mid_card = bmp_card_1;
		mid_card = BUTTON_CARD_CHOOSE_1;
	}
	else if (temp == 1)
	{
		bmp_mid_card = bmp_card_2;
		mid_card = BUTTON_CARD_CHOOSE_2;
	}
	else if (temp == 2)
	{
		bmp_mid_card = bmp_card_3;
		mid_card = BUTTON_CARD_CHOOSE_3;
	}
	else if (temp == 3)
	{
		bmp_mid_card = bmp_card_4;
		mid_card = BUTTON_CARD_CHOOSE_4;
	}
	else if (temp == 4)
	{
		bmp_mid_card = bmp_card_5;
		mid_card = BUTTON_CARD_CHOOSE_5;
	}
	else if (temp == 5)
	{
		bmp_mid_card = bmp_card_6;
		mid_card = BUTTON_CARD_CHOOSE_6;
	}
	else if (temp == 6)
	{
		bmp_mid_card = bmp_card_7;
		mid_card = BUTTON_CARD_CHOOSE_7;
	}
	else if (temp == 7)
	{
		bmp_mid_card = bmp_card_8;
		mid_card = BUTTON_CARD_CHOOSE_8;
	}
	else if (temp == 8)
	{
		bmp_mid_card = bmp_card_9;
		mid_card = BUTTON_CARD_CHOOSE_9;
	}
	else if (temp == 9)
	{
		bmp_mid_card = bmp_card_10;
		mid_card = BUTTON_CARD_CHOOSE_10;
	}
	else if (temp == 10)
	{
		bmp_mid_card = bmp_card_11;
		mid_card = BUTTON_CARD_CHOOSE_11;
	}
	else if (temp == 11)
	{
		bmp_mid_card = bmp_card_12;
		mid_card = BUTTON_CARD_CHOOSE_12;
	}
	temp = rand() % 12;
	if (temp == 0)
	{
		bmp_right_card = bmp_card_1;
		right_card = BUTTON_CARD_CHOOSE_1;
	}
	else if (temp == 1)
	{
		bmp_right_card = bmp_card_2;
		right_card = BUTTON_CARD_CHOOSE_2;
	}
	else if (temp == 2)
	{
		bmp_right_card = bmp_card_3;
		right_card = BUTTON_CARD_CHOOSE_3;
	}
	else if (temp == 3)
	{
		bmp_right_card = bmp_card_4;
		right_card = BUTTON_CARD_CHOOSE_4;
	}
	else if (temp == 4)
	{
		bmp_right_card = bmp_card_5;
		right_card = BUTTON_CARD_CHOOSE_5;
	}
	else if (temp == 5)
	{
		bmp_right_card = bmp_card_6;
		right_card = BUTTON_CARD_CHOOSE_6;
	}
	else if (temp == 6)
	{
		bmp_right_card = bmp_card_7;
		right_card = BUTTON_CARD_CHOOSE_7;
	}
	else if (temp == 7)
	{
		bmp_right_card = bmp_card_8;
		right_card = BUTTON_CARD_CHOOSE_8;
	}
	else if (temp == 8)
	{
		bmp_right_card = bmp_card_9;
		right_card = BUTTON_CARD_CHOOSE_9;
	}
	else if (temp == 9)
	{
		bmp_right_card = bmp_card_10;
		right_card = BUTTON_CARD_CHOOSE_10;
	}
	else if (temp == 10)
	{
		bmp_right_card = bmp_card_11;
		right_card = BUTTON_CARD_CHOOSE_11;
	}
	else if (temp == 11)
	{
		bmp_right_card = bmp_card_12;
		right_card = BUTTON_CARD_CHOOSE_12;
	}
	Button* left_cardchooseButton = CreateButton(left_card, bmp_left_card, 200, 300, 150, 150);
	Button* mid_cardchooseButton = CreateButton(mid_card, bmp_mid_card, 200, 300, 400, 150);
	Button* right_cardchooseButton = CreateButton(right_card, bmp_right_card, 200, 300, 650, 150);
	return;
}

//卡牌选择后的删除函数
void DeleteCardChoose(HWND hWnd)
{
	for (int i = 0; i < buttons.size(); i++)
	{
		if (buttons[i] != nullptr)
		{
			int id = buttons[i]->buttonID;
			if (id== BUTTON_CARD_CHOOSE_1 || id == BUTTON_CARD_CHOOSE_2 || id == BUTTON_CARD_CHOOSE_3
				|| id == BUTTON_CARD_CHOOSE_4 || id == BUTTON_CARD_CHOOSE_5 || id == BUTTON_CARD_CHOOSE_6
				|| id == BUTTON_CARD_CHOOSE_7 || id == BUTTON_CARD_CHOOSE_8 || id == BUTTON_CARD_CHOOSE_9
				|| id == BUTTON_CARD_CHOOSE_10 || id == BUTTON_CARD_CHOOSE_11 || id == BUTTON_CARD_CHOOSE_12)
			{
				delete buttons[i];
				buttons[i] = nullptr;  // 避免悬挂指针  
				buttons.erase(buttons.begin() + i);
				i--;
			}
		}
	}
}

//检测游戏进程函数
void DetectGameState(HWND hWnd)
{
	if (currentStage->stageID == STAGE_BATTLE && RivalPokemon->heart <= 0)
	{
		PlaySound(MAKEINTRESOURCE(IDR_WIN_BATTLE), NULL, SND_RESOURCE | SND_ASYNC);
		InitStage(hWnd, STAGE_CARD_CHOOSE);
		RivalPokemon->heart = RivalPokemon->total_heart;
		RivalPokemon->power = 0;
		RivalPokemon->speed = 0;
		MyPokemon->power = 0;
		MyPokemon->speed = 0;
		MyPokemon->defense = 0;
		RivalPokemon->defense = 0;
		DeleteCard(hWnd);
		attack_on = 0;
		defend_on = 0;
		attack_frame_id = 0;
		defend_frame_id = 0;
	}
	else if (currentStage->stageID == STAGE_BOSS && RivalPokemon->heart <= 0)
	{
		InitStage(hWnd, STAGE_WIN);
		RivalPokemon->heart = RivalPokemon->total_heart;
		RivalPokemon->power = 0;
		RivalPokemon->speed = 0;
		MyPokemon->power = 0;
		MyPokemon->speed = 0;
		MyPokemon->defense = 0;
		RivalPokemon->defense = 0;
		DeleteCard(hWnd);
		attack_on = 0;
		defend_on = 0;
		attack_frame_id = 0;
		defend_frame_id = 0;
	}
	else if ((currentStage->stageID == STAGE_BATTLE || currentStage->stageID == STAGE_BOSS) && MyPokemon->heart <= 0)
	{
		attack_on = 0;
		defend_on = 0;
		attack_frame_id = 0;
		defend_frame_id = 0;
		InitStage(hWnd, STAGE_LOSE);
		MyPokemon->heart = MyPokemon->total_heart;
		RivalPokemon->power = 0;
		RivalPokemon->speed = 0;
		MyPokemon->power = 0;
		MyPokemon->speed = 0;
		MyPokemon->defense = 0;
		RivalPokemon->defense = 0;
		DeleteCard(hWnd);
	}
	
	if (MyPokemon->speed >= 100) MyPokemon->speed = 99;
	if (RivalPokemon->speed >= 100) RivalPokemon->speed = 99;
	if (RivalPokemon->power >= 100) RivalPokemon->power = 99;
	if (MyPokemon->power >= 100) MyPokemon->power = 99;
	if (MyPokemon->defense >= 100) MyPokemon->defense = 99;
	if (RivalPokemon->defense >= 100) RivalPokemon->defense = 99;
	return;
}

//检测鼠标位置函数
void DetectMouse(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	mouseX = LOWORD(lParam);
	mouseY = HIWORD(lParam);
	consumed_energy = 0;
	card_select = 0;
	for (int i = 0; i < buttons.size(); i++)
	{
		Button* button = buttons[i];
		if (button->visible)
		{
			if (button->x <= mouseX
				&& button->x + button->width >= mouseX
				&& button->y <= mouseY
				&& button->y + button->height >= mouseY)
			{
				switch (button->buttonID)
				{
				case BUTTON_CARD_1:
				{
					consumed_energy = hand_cards[0]->expend;
					card_select = 1;
					break;
				}
				case BUTTON_CARD_2:
				{
					consumed_energy = hand_cards[1]->expend;
					card_select = 2;
					break;
				}
				case BUTTON_CARD_3:
				{
					consumed_energy = hand_cards[2]->expend;
					card_select = 3;
					break;
				}
				case BUTTON_CARD_4:
				{
					consumed_energy = hand_cards[3]->expend;
					card_select = 4;
					break;
				}
				}
			}
		}
	}
}