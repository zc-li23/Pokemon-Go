#include "Pokemon_Go.h"
Button* Button::CreateButton(int buttonID, HBITMAP img, int width, int height, int x, int y)
{
	Button* button = new Button(buttonID, img, width, height, x, y);
	buttons.push_back(button);
	return button;
}


void Button::Button_Affect(HWND hWnd, WPARAM wParam, LPARAM lParam,int i,bool& have_found)
{
	switch (this->buttonID)
	{
	case BUTTON_HELP:
	{
		PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
		Stage::InitStage(hWnd, STAGE_HELP);
		have_found = true;
		break;
	}
	case BUTTON_RETURN:
	{
		PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
		Stage::InitStage(hWnd, STAGE_STARTMENU);
		have_found = true;
		break;
	}
	case BUTTON_MENU:
	{
		PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
		Stage::InitStage(hWnd, STAGE_STARTMENU);
		have_found = true;
		break;
	}
	case BUTTON_MENU_END:
	{
		PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
		Stage::InitStage(hWnd, STAGE_STARTMENU);
		have_found = true;
		break;
	}
	case BUTTON_STOP:
	{
		PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
		stop_stage = currentStage->stageID;
		Stage::InitStage(hWnd, STAGE_STOP);
		have_found = true;
		break;
	}
	case BUTTON_RETURN_GAME:
	{
		PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
		if (stop_stage == STAGE_BATTLE) Stage::InitStage(hWnd, STAGE_BATTLE);
		if (stop_stage == STAGE_BOSS) Stage::InitStage(hWnd, STAGE_BOSS);
		have_found = true;
		break;
	}
	case BUTTON_REGAME:
	{
		PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
		DeleteData(hWnd);
		MyPokemon->heart = MyPokemon->total_heart;
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		//添加卡牌
		cards.push_back(Card::CreateCard(NORMAL_ATTACK));
		cards.push_back(Card::CreateCard(NORMAL_ATTACK));
		cards.push_back(Card::CreateCard(NORMAL_DEFEND));
		cards.push_back(Card::CreateCard(NORMAL_DEFEND));
		cards.push_back(Card::CreateCard(NORMAL_ATTACK));
		cards.push_back(Card::CreateCard(NORMAL_DEFEND));
		cards.push_back(Card::CreateCard(NORMAL_DEFEND));
		cards.push_back(Card::CreateCard(VOLT_ATTACK));
		have_found = true;
		break;
	}
	case BUTTON_REGAME_END:
	{
		PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
		DeleteData(hWnd);
		MyPokemon->heart = MyPokemon->total_heart;
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		//添加卡牌
		cards.push_back(Card::CreateCard(NORMAL_ATTACK));
		cards.push_back(Card::CreateCard(NORMAL_ATTACK));
		cards.push_back(Card::CreateCard(NORMAL_DEFEND));
		cards.push_back(Card::CreateCard(NORMAL_DEFEND));
		cards.push_back(Card::CreateCard(NORMAL_ATTACK));
		cards.push_back(Card::CreateCard(NORMAL_DEFEND));
		cards.push_back(Card::CreateCard(NORMAL_DEFEND));
		cards.push_back(Card::CreateCard(VOLT_ATTACK));
		have_found = true;
		break;
	}
	case BUTTON_STARTGAME:
	{
		Stage::InitStage(hWnd, STAGE_POKEMON_CHOOSE);
		//添加卡牌
		cards.push_back(Card::CreateCard(NORMAL_ATTACK));
		cards.push_back(Card::CreateCard(NORMAL_ATTACK));
		cards.push_back(Card::CreateCard(NORMAL_DEFEND));
		cards.push_back(Card::CreateCard(NORMAL_DEFEND));
		cards.push_back(Card::CreateCard(NORMAL_ATTACK));
		cards.push_back(Card::CreateCard(NORMAL_DEFEND));
		cards.push_back(Card::CreateCard(NORMAL_DEFEND));
		cards.push_back(Card::CreateCard(VOLT_ATTACK));
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
		Stage::InitStage(hWnd, STAGE_POKEMON_CHOOSE);
		have_found = true;
		break;
	}
	case BUTTON_POKEMON_BEFORE:
	{
		pokemon_select = (pokemon_select + 3) % 4;
		Stage::InitStage(hWnd, STAGE_POKEMON_CHOOSE);
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
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
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
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
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
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
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
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
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
		Route::RefreshRoute(hWnd);
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		have_found = true;
		break;
	}
	case BUTTON_SHOP_ROUTE:
	{
		PlaySound(MAKEINTRESOURCE(IDR_WIN_BATTLE), NULL, SND_RESOURCE | SND_ASYNC);
		delete buttons[i];
		buttons.erase(buttons.begin() + i);
		Route::RefreshRoute(hWnd);
		Stage::InitStage(hWnd, STAGE_CARD_CHOOSE);
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
		Rival::CreateRival(hWnd, 0);
		Route::RefreshRoute(hWnd);
		Stage::InitStage(hWnd, STAGE_BATTLE);
		have_found = true;
		break;
	}
	case BUTTON_BOSS_ROUTE:
	{
		PlaySound(MAKEINTRESOURCE(IDR_BATTLE), NULL, SND_RESOURCE | SND_ASYNC);
		round_num = 1;
		delete buttons[i];
		buttons.erase(buttons.begin() + i);
		Rival::CreateRival(hWnd, 1);
		StartBattle(hWnd);
		Stage::InitStage(hWnd, STAGE_BOSS);
		have_found = true;
		break;
	}
	case BUTTON_SKIP_CARD_CHOOSE:
	{
		PlaySound(MAKEINTRESOURCE(IDR_TOUCH), NULL, SND_RESOURCE | SND_ASYNC);
		Card::DeleteCardChoose(hWnd);
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		have_found = true;
		break;
	}
	case BUTTON_CARD_CHOOSE_1:
	{
		PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
		Card::DeleteCardChoose(hWnd);
		cards.push_back(Card::CreateCard(1));
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		have_found = true;
		break;
	}
	case BUTTON_CARD_CHOOSE_2:
	{
		PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
		Card::DeleteCardChoose(hWnd);
		cards.push_back(Card::CreateCard(2));
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		have_found = true;
		break;
	}
	case BUTTON_CARD_CHOOSE_3:
	{
		PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
		Card::DeleteCardChoose(hWnd);
		cards.push_back(Card::CreateCard(3));
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		have_found = true;
		break;
	}
	case BUTTON_CARD_CHOOSE_4:
	{
		PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
		Card::DeleteCardChoose(hWnd);
		cards.push_back(Card::CreateCard(4));
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		have_found = true;
		break;
	}
	case BUTTON_CARD_CHOOSE_5:
	{
		PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
		Card::DeleteCardChoose(hWnd);
		cards.push_back(Card::CreateCard(5));
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		have_found = true;
		break;
	}
	case BUTTON_CARD_CHOOSE_6:
	{
		PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
		Card::DeleteCardChoose(hWnd);
		cards.push_back(Card::CreateCard(6));
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		have_found = true;
		break;
	}
	case BUTTON_CARD_CHOOSE_7:
	{
		PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
		Card::DeleteCardChoose(hWnd);
		cards.push_back(Card::CreateCard(7));
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		have_found = true;
		break;
	}
	case BUTTON_CARD_CHOOSE_8:
	{
		PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
		Card::DeleteCardChoose(hWnd);
		cards.push_back(Card::CreateCard(8));
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		have_found = true;
		break;
	}
	case BUTTON_CARD_CHOOSE_9:
	{
		PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
		Card::DeleteCardChoose(hWnd);
		cards.push_back(Card::CreateCard(9));
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		have_found = true;
		break;
	}
	case BUTTON_CARD_CHOOSE_10:
	{
		PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
		Card::DeleteCardChoose(hWnd);
		cards.push_back(Card::CreateCard(10));
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		have_found = true;
		break;
	}
	case BUTTON_CARD_CHOOSE_11:
	{
		PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
		Card::DeleteCardChoose(hWnd);
		cards.push_back(Card::CreateCard(11));
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		have_found = true;
		break;
	}
	case BUTTON_CARD_CHOOSE_12:
	{
		PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_ASYNC);
		Card::DeleteCardChoose(hWnd);
		cards.push_back(Card::CreateCard(12));
		Stage::InitStage(hWnd, STAGE_ROUTE_CHOOSE);
		have_found = true;
		break;
	}
	case BUTTON_CARD_1:
	{
		Card::PlayCard(hWnd, 1);
		have_found = true;
		break;
	}
	case BUTTON_CARD_2:
	{
		Card::PlayCard(hWnd, 2);
		have_found = true;
		break;
	}
	case BUTTON_CARD_3:
	{
		Card::PlayCard(hWnd, 3);
		have_found = true;
		break;
	}
	case BUTTON_CARD_4:
	{
		Card::PlayCard(hWnd, 4);
		have_found = true;
		break;
	}
	case BUTTON_END_ROUND:
	{
		PlaySound(MAKEINTRESOURCE(IDR_CHOOSE_POKEMON), NULL, SND_RESOURCE | SND_SYNC);
		EndRound(hWnd, round_num);
		have_found = true;
		break;
	}
	default:break;
	}
}


void Stage::InitStage(HWND hWnd, int stageID)
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
		Route::RouteChoose(hWnd);
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
		Card::CardChoose(hWnd);
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


void Route::RouteChoose(HWND hWnd)
{
	if (route_num == 0)
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
		Button* left_routeButton = Button::CreateButton(left_route, bmp_left_route, 200, 200, 150, 250);
		Button* mid_routeButton = Button::CreateButton(mid_route, bmp_mid_route, 200, 200, 400, 250);
		Button* right_routeButton = Button::CreateButton(right_route, bmp_right_route, 200, 200, 650, 250);
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
			Button* left_routeButton = Button::CreateButton(left_route, bmp_left_route, 200, 200, 150, 250);
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
			Button* mid_routeButton = Button::CreateButton(mid_route, bmp_mid_route, 200, 200, 400, 250);
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
			Button* right_routeButton = Button::CreateButton(right_route, bmp_right_route, 200, 200, 650, 250);
		}
	}
	else if (route_num == 10)
	{
		if (left_route == 0)
		{
			Button* left_routeButton = Button::CreateButton(BUTTON_BOSS_ROUTE, bmp_boss_route, 200, 200, 150, 250);
		}
		else if (mid_route == 0)
		{
			Button* mid_routeButton = Button::CreateButton(BUTTON_BOSS_ROUTE, bmp_boss_route, 200, 200, 400, 250);
		}
		else if (right_route == 0)
		{
			Button* right_routeButton = Button::CreateButton(BUTTON_BOSS_ROUTE, bmp_boss_route, 200, 200, 650, 250);
		}
	}
	return;
}


void Route::RefreshRoute(HWND hWnd)
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
