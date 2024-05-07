#include "Pokemon_Go.h"


void Rival::RivalAction(HWND hWnd, int roundnum, int intention)
{
	if (RivalPokemon->id == 1)
	{
		if (roundnum != 0)
		{
			if (intention == ATTACK)
			{
				if (MyPokemon->defense == 0)
				{
					MyPokemon->heart -= RivalPokemon->intention_num + RivalPokemon->power;
					PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_SYNC);
				}
				else
				{
					if (RivalPokemon->intention_num + RivalPokemon->power <= MyPokemon->defense)
					{
						MyPokemon->defense -= RivalPokemon->intention_num + RivalPokemon->power;
						PlaySound(MAKEINTRESOURCE(IDR_HIT_DEFENSE), NULL, SND_RESOURCE | SND_SYNC);
					}
					else
					{
						MyPokemon->heart -= (RivalPokemon->intention_num + RivalPokemon->power - MyPokemon->defense);
						PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_SYNC);
						MyPokemon->defense = 0;
					}
				}
			}
			else if (intention == DEFEND)
			{
				RivalPokemon->defense += RivalPokemon->intention_num + RivalPokemon->speed;
				PlaySound(MAKEINTRESOURCE(IDR_DEFEND), NULL, SND_RESOURCE | SND_SYNC);
			}
			else if (intention == AFFECT)
			{
				PlaySound(MAKEINTRESOURCE(IDR_AFFECT_DOWN), NULL, SND_RESOURCE | SND_SYNC);
				RivalPokemon->power += 10;
			}
		}
		int temp = rand() % 5;
		if (temp <= 2)
		{
			RivalPokemon->intention = ATTACK;
			RivalPokemon->intention_num = rand( ) % 15 + 10;
		}
		else if (temp <= 4)
		{
			RivalPokemon->intention = AFFECT;
		}
	}
	else if (RivalPokemon->id == 4)
	{
		if (roundnum != 0)
		{
			if (intention == ATTACK)
			{
				if (MyPokemon->defense == 0)
				{
					MyPokemon->heart -= RivalPokemon->intention_num + RivalPokemon->power;
					PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_SYNC);
				}
				else
				{
					if (RivalPokemon->intention_num + RivalPokemon->power <= MyPokemon->defense)
					{
						MyPokemon->defense -= RivalPokemon->intention_num + RivalPokemon->power;
						PlaySound(MAKEINTRESOURCE(IDR_HIT_DEFENSE), NULL, SND_RESOURCE | SND_SYNC);
					}
					else
					{
						MyPokemon->heart -= (RivalPokemon->intention_num + RivalPokemon->power - MyPokemon->defense);
						PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_SYNC);
						MyPokemon->defense = 0;
					}
				}
			}
			else if (intention == DEFEND)
			{
				RivalPokemon->defense += RivalPokemon->intention_num + RivalPokemon->speed;
				PlaySound(MAKEINTRESOURCE(IDR_DEFEND), NULL, SND_RESOURCE | SND_SYNC);
			}
			else if (intention == AFFECT)
			{
				PlaySound(MAKEINTRESOURCE(IDR_AFFECT_DOWN), NULL, SND_RESOURCE | SND_SYNC);
				RivalPokemon->speed += 5;
				if (RivalPokemon->heart + 10 <= RivalPokemon->total_heart)
					RivalPokemon->heart += 10;
				else RivalPokemon->heart = RivalPokemon->total_heart;
			}
		}
		if (RivalPokemon->heart <= 30)
		{
			int temp = rand() % 5;
			if (temp <= 2)
			{
				RivalPokemon->intention = ATTACK;
				RivalPokemon->intention_num = rand() % 20 + 10;
			}
			else if (temp <= 4)
			{
				RivalPokemon->intention = DEFEND;
				RivalPokemon->intention_num = rand() % 15 + 5;
			}
		}
		else
		{
			int temp = rand() % 5;
			if (temp <= 0)
			{
				RivalPokemon->intention = ATTACK;
				RivalPokemon->intention_num = rand() % 20 + 1;
			}
			else if (temp <= 2)
			{
				RivalPokemon->intention = DEFEND;
				RivalPokemon->intention_num = rand() % 15 + 5;
			}
			else if (temp <= 4)
			{
				RivalPokemon->intention = AFFECT;
			}
		}
	}
	else if (RivalPokemon->id == 2)
	{
		if (roundnum != 0)
		{
			if (intention == ATTACK)
			{
				if (MyPokemon->defense == 0)
				{
					MyPokemon->heart -= RivalPokemon->intention_num + RivalPokemon->power;
					PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_SYNC);
				}
				else
				{
					if (RivalPokemon->intention_num + RivalPokemon->power <= MyPokemon->defense)
					{
						MyPokemon->defense -= RivalPokemon->intention_num + RivalPokemon->power;
						PlaySound(MAKEINTRESOURCE(IDR_HIT_DEFENSE), NULL, SND_RESOURCE | SND_SYNC);
					}
					else
					{
						MyPokemon->heart -= (RivalPokemon->intention_num + RivalPokemon->power - MyPokemon->defense);
						PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_SYNC);
						MyPokemon->defense = 0;
					}
				}
			}
			else if (intention == DEFEND)
			{
				RivalPokemon->defense += RivalPokemon->intention_num + RivalPokemon->speed;
				PlaySound(MAKEINTRESOURCE(IDR_DEFEND), NULL, SND_RESOURCE | SND_SYNC);
			}
			else if (intention == AFFECT)
			{
				PlaySound(MAKEINTRESOURCE(IDR_AFFECT_DOWN), NULL, SND_RESOURCE | SND_SYNC);
				RivalPokemon->speed += 5;
				RivalPokemon->power += 5;
				if (MyPokemon->speed >= 3) MyPokemon->speed -= 3;
				else MyPokemon->speed = 0;
				if (MyPokemon->power >= 3) MyPokemon->power -= 3;
				else MyPokemon->power = 0;
			}
		}
		int temp = rand() % 6;
		if (temp <= 1)
		{
			RivalPokemon->intention = ATTACK;
			RivalPokemon->intention_num = rand() % 15 + 1;
		}
		else if (temp <= 3)
		{
			RivalPokemon->intention = DEFEND;
			RivalPokemon->intention_num = rand() % 15 + 1;
		}
		else if (temp <= 5)
		{
			RivalPokemon->intention = AFFECT;
		}
	}
	else if (RivalPokemon->id == 5)
	{
		if (roundnum != 0)
		{
			if (intention == ATTACK)
			{
				if (MyPokemon->defense == 0)
				{
					MyPokemon->heart -= RivalPokemon->intention_num + RivalPokemon->power;
					PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_SYNC);
				}
				else
				{
					if (RivalPokemon->intention_num + RivalPokemon->power <= MyPokemon->defense)
					{
						MyPokemon->defense -= RivalPokemon->intention_num + RivalPokemon->power;
						PlaySound(MAKEINTRESOURCE(IDR_HIT_DEFENSE), NULL, SND_RESOURCE | SND_SYNC);
					}
					else
					{
						MyPokemon->heart -= (RivalPokemon->intention_num + RivalPokemon->power - MyPokemon->defense);
						PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_SYNC);
						MyPokemon->defense = 0;
					}
				}
			}
			else if (intention == DEFEND)
			{
				RivalPokemon->defense += RivalPokemon->intention_num + RivalPokemon->speed;
				PlaySound(MAKEINTRESOURCE(IDR_DEFEND), NULL, SND_RESOURCE | SND_SYNC);
			}
			else if (intention == AFFECT)
			{
				PlaySound(MAKEINTRESOURCE(IDR_AFFECT_DOWN), NULL, SND_RESOURCE | SND_SYNC);
				MyPokemon->energy -= 2;
				RivalPokemon->power += 7;
			}
		}
		int temp = rand() % 5;
		if (temp <= 1)
		{
			RivalPokemon->intention = ATTACK;
			RivalPokemon->intention_num = rand() % 15 + 5;
		}
		else if (temp <= 2)
		{
			RivalPokemon->intention = DEFEND;
			RivalPokemon->intention_num = rand() % 15 + 5;
		}
		else if (temp <= 4)
		{
			RivalPokemon->intention = AFFECT;
		}
	}
	else if (RivalPokemon->id == 3)
	{
		if (roundnum != 0)
		{
			if (intention == ATTACK)
			{
				if (MyPokemon->defense == 0)
				{
					MyPokemon->heart -= RivalPokemon->intention_num + RivalPokemon->power;
					PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_SYNC);
				}
				else
				{
					if (RivalPokemon->intention_num + RivalPokemon->power <= MyPokemon->defense)
					{
						MyPokemon->defense -= RivalPokemon->intention_num + RivalPokemon->power;
						PlaySound(MAKEINTRESOURCE(IDR_HIT_DEFENSE), NULL, SND_RESOURCE | SND_SYNC);
					}
					else
					{
						MyPokemon->heart -= (RivalPokemon->intention_num + RivalPokemon->power - MyPokemon->defense);
						PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_SYNC);
						MyPokemon->defense = 0;
					}
				}
			}
			else if (intention == DEFEND)
			{
				RivalPokemon->defense += RivalPokemon->intention_num + RivalPokemon->speed;
				PlaySound(MAKEINTRESOURCE(IDR_DEFEND), NULL, SND_RESOURCE | SND_SYNC);
			}
			else if (intention == AFFECT)
			{
				PlaySound(MAKEINTRESOURCE(IDR_AFFECT_DOWN), NULL, SND_RESOURCE | SND_SYNC);
				discarded_cards.push_back(Card::CreateCard(WOUND));
				discarded_cards.push_back(Card::CreateCard(WOUND));
				discarded_cards.push_back(Card::CreateCard(WOUND));
			}
		}
		if (round_num % 2 ==0)
		{
			RivalPokemon->intention = ATTACK;
			RivalPokemon->intention_num = 12;
		}
		else
		{
			RivalPokemon->intention = AFFECT;
		}
	}
	else if (RivalPokemon->id == 0)
	{
		if (roundnum != 0)
		{
			if (intention == ATTACK)
			{
				if (MyPokemon->defense == 0)
				{
					MyPokemon->heart -= RivalPokemon->intention_num + RivalPokemon->power;
					PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_SYNC);
				}
				else
				{
					if (RivalPokemon->intention_num + RivalPokemon->power <= MyPokemon->defense)
					{
						MyPokemon->defense -= RivalPokemon->intention_num + RivalPokemon->power;
						PlaySound(MAKEINTRESOURCE(IDR_HIT_DEFENSE), NULL, SND_RESOURCE | SND_SYNC);
					}
					else
					{
						MyPokemon->heart -= (RivalPokemon->intention_num + RivalPokemon->power - MyPokemon->defense);
						PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_SYNC);
						MyPokemon->defense = 0;
					}
				}
			}
			else if (intention == DEFEND)
			{
				RivalPokemon->defense += RivalPokemon->intention_num + RivalPokemon->speed;
				PlaySound(MAKEINTRESOURCE(IDR_DEFEND), NULL, SND_RESOURCE | SND_SYNC);
			}
			else if (intention == AFFECT)
			{
				PlaySound(MAKEINTRESOURCE(IDR_AFFECT_DOWN), NULL, SND_RESOURCE | SND_SYNC);
				RivalPokemon->power += 10;
				RivalPokemon->speed += 10;
				discarded_cards.push_back(Card::CreateCard(WOUND));
				discarded_cards.push_back(Card::CreateCard(WOUND));
			}
		}
		int temp = rand() % 6;
		if (temp <= 2)
		{
			RivalPokemon->intention = ATTACK;
			RivalPokemon->intention_num = rand() % 15 + 10;
			if(RivalPokemon->heart <= 30) RivalPokemon->intention_num = rand() % 15 + 15;
		}
		else if (temp <= 4)
		{
			RivalPokemon->intention = DEFEND;
			RivalPokemon->intention_num = rand() % 15 + 10;
			if (RivalPokemon->heart <= 30) RivalPokemon->intention_num = rand() % 15 + 15;
		}
		else if (temp <= 5)
		{
			RivalPokemon->intention = AFFECT;
		}
	}
	return;
}


void Rival::CreateRival(HWND hWnd, bool boss)
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

//进入战斗添加抽牌区函数
void StartBattle(HWND hWnd)
{
	for (int i = 0; i < cards.size(); i++)
		draw_cards.push_back(cards[i]);
	MyPokemon->energy = MyPokemon->full_energy;
	if (MyPokemon->total_heart == 50) MyPokemon->power = 5;
	if (MyPokemon->total_heart == 60) MyPokemon->speed = 5;
	Rival::RivalAction(hWnd, 0, RivalPokemon->intention);
	Card::DrawCards(hWnd,4);
	return;
}

//结束回合函数
void EndRound(HWND hWnd, int roundnum)
{
	RivalPokemon->defense = 0;
	for (int i = 0; i < hand_cards.size(); i++)
	{
		discarded_cards.push_back(hand_cards[i]);
	}
	if (!hand_cards.empty()) hand_cards.clear();
	MyPokemon->energy = MyPokemon->full_energy;
	Rival::RivalAction(hWnd, round_num,RivalPokemon->intention);
	MyPokemon->defense = 0;
	if(MyPokemon->heart > 0 && RivalPokemon->heart > 0) Card::DrawCards(hWnd,3);
	round_num++;
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
	Card::DeleteCard(hWnd);
	return;
}


//检测游戏进程函数
void DetectGameState(HWND hWnd)
{
	if (currentStage->stageID == STAGE_BATTLE && RivalPokemon->heart <= 0)
	{
		PlaySound(MAKEINTRESOURCE(IDR_WIN_BATTLE), NULL, SND_RESOURCE | SND_ASYNC);
		Stage::InitStage(hWnd, STAGE_CARD_CHOOSE);
		RivalPokemon->heart = RivalPokemon->total_heart;
		RivalPokemon->power = 0;
		RivalPokemon->speed = 0;
		MyPokemon->power = 0;
		MyPokemon->speed = 0;
		MyPokemon->defense = 0;
		RivalPokemon->defense = 0;
		Card::DeleteCard(hWnd);
	}
	else if (currentStage->stageID == STAGE_BOSS && RivalPokemon->heart <= 0)
	{
		Stage::InitStage(hWnd, STAGE_WIN);
		RivalPokemon->heart = RivalPokemon->total_heart;
		RivalPokemon->power = 0;
		RivalPokemon->speed = 0;
		MyPokemon->power = 0;
		MyPokemon->speed = 0;
		MyPokemon->defense = 0;
		RivalPokemon->defense = 0;
		Card::DeleteCard(hWnd);
	}
	else if ((currentStage->stageID == STAGE_BATTLE || currentStage->stageID == STAGE_BOSS) && MyPokemon->heart <= 0)
	{
		Stage::InitStage(hWnd, STAGE_LOSE);
		MyPokemon->heart = MyPokemon->total_heart;
		RivalPokemon->power = 0;
		RivalPokemon->speed = 0;
		MyPokemon->power = 0;
		MyPokemon->speed = 0;
		MyPokemon->defense = 0;
		RivalPokemon->defense = 0;
		Card::DeleteCard(hWnd);
	}

	if (MyPokemon->speed >= 100) MyPokemon->speed = 99;
	if (RivalPokemon->speed >= 100) RivalPokemon->speed = 99;
	if (RivalPokemon->power >= 100) RivalPokemon->power = 99;
	if (MyPokemon->power >= 100) MyPokemon->power = 99;
	if (MyPokemon->defense >= 100) MyPokemon->defense = 99;
	if (RivalPokemon->defense >= 100) RivalPokemon->defense = 99;
	return;
}
