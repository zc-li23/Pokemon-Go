#include "Pokemon_Go.h"
//进入战斗添加抽牌区函数
void StartBattle(HWND hWnd)
{
	for (int i = 0; i < cards.size(); i++)
		draw_cards.push_back(cards[i]);
	MyPokemon->energy = MyPokemon->full_energy;
	if (MyPokemon->total_heart == 50) MyPokemon->power = 5;
	if (MyPokemon->total_heart == 60) MyPokemon->speed = 5;
	RivalAction(hWnd, 0, RivalPokemon->intention);
	DrawCards(hWnd,4);
	return;
}

//从抽牌区抽牌函数
void DrawCards(HWND hWnd,int num)
{
	for (int i = 1; i <= num; i++)
	{
		if (draw_cards.size() <= 0)
			UpdateCards(hWnd);
		int temp = rand() % draw_cards.size();
		if (draw_cards[temp] != NULL)
		{
			hand_cards.push_back(draw_cards[temp]);
			draw_cards.erase(draw_cards.begin() + temp);
		}
	}
	RefreshCards(hWnd);
	return;
}

//将弃牌区的卡牌放入抽牌区的函数
void UpdateCards(HWND hWnd)
{
	for (int i = 0; i < discarded_cards.size(); i++)
		draw_cards.push_back(discarded_cards[i]);
	if (!discarded_cards.empty()) discarded_cards.clear();
	return;
}

//对手行动函数
void RivalAction(HWND hWnd, int roundnum, int intention)
{
	if (RivalPokemon->id == 1)
	{
		if (roundnum != 0)
		{
			if (intention == ATTACK)
			{
				attack_on = 1;
				attack_frame_id = 0;
				if (MyPokemon->defense == 0)
				{
					MyPokemon->heart -= RivalPokemon->intention_num + RivalPokemon->power;
					PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_ASYNC);
				}
				else
				{
					if (RivalPokemon->intention_num + RivalPokemon->power <= MyPokemon->defense)
					{
						MyPokemon->defense -= RivalPokemon->intention_num + RivalPokemon->power;
						PlaySound(MAKEINTRESOURCE(IDR_HIT_DEFENSE), NULL, SND_RESOURCE | SND_ASYNC);
					}
					else
					{
						MyPokemon->heart -= (RivalPokemon->intention_num + RivalPokemon->power - MyPokemon->defense);
						PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_ASYNC);
						MyPokemon->defense = 0;
					}
				}
			}
			else if (intention == DEFEND)
			{
				defend_on = 2;
				defend_frame_id = 0;
				RivalPokemon->defense += RivalPokemon->intention_num + RivalPokemon->speed;
				PlaySound(MAKEINTRESOURCE(IDR_DEFEND), NULL, SND_RESOURCE | SND_ASYNC);
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
				attack_on = 1;
				attack_frame_id = 0;
				if (MyPokemon->defense == 0)
				{
					MyPokemon->heart -= RivalPokemon->intention_num + RivalPokemon->power;
					PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_ASYNC);
				}
				else
				{
					if (RivalPokemon->intention_num + RivalPokemon->power <= MyPokemon->defense)
					{
						MyPokemon->defense -= RivalPokemon->intention_num + RivalPokemon->power;
						PlaySound(MAKEINTRESOURCE(IDR_HIT_DEFENSE), NULL, SND_RESOURCE | SND_ASYNC);
					}
					else
					{
						MyPokemon->heart -= (RivalPokemon->intention_num + RivalPokemon->power - MyPokemon->defense);
						PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_ASYNC);
						MyPokemon->defense = 0;
					}
				}
			}
			else if (intention == DEFEND)
			{
				defend_on = 2;
				defend_frame_id = 0;
				RivalPokemon->defense += RivalPokemon->intention_num + RivalPokemon->speed;
				PlaySound(MAKEINTRESOURCE(IDR_DEFEND), NULL, SND_RESOURCE | SND_ASYNC);
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
				attack_on = 1;
				attack_frame_id = 0;
				if (MyPokemon->defense == 0)
				{
					MyPokemon->heart -= RivalPokemon->intention_num + RivalPokemon->power;
					PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_ASYNC);
				}
				else
				{
					if (RivalPokemon->intention_num + RivalPokemon->power <= MyPokemon->defense)
					{
						MyPokemon->defense -= RivalPokemon->intention_num + RivalPokemon->power;
						PlaySound(MAKEINTRESOURCE(IDR_HIT_DEFENSE), NULL, SND_RESOURCE | SND_ASYNC);
					}
					else
					{
						MyPokemon->heart -= (RivalPokemon->intention_num + RivalPokemon->power - MyPokemon->defense);
						PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_ASYNC);
						MyPokemon->defense = 0;
					}
				}
			}
			else if (intention == DEFEND)
			{
				defend_on = 2;
				defend_frame_id = 0;
				RivalPokemon->defense += RivalPokemon->intention_num + RivalPokemon->speed;
				PlaySound(MAKEINTRESOURCE(IDR_DEFEND), NULL, SND_RESOURCE | SND_ASYNC);
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
				attack_on = 1;
				attack_frame_id = 0;
				if (MyPokemon->defense == 0)
				{
					MyPokemon->heart -= RivalPokemon->intention_num + RivalPokemon->power;
					PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_ASYNC);
				}
				else
				{
					if (RivalPokemon->intention_num + RivalPokemon->power <= MyPokemon->defense)
					{
						MyPokemon->defense -= RivalPokemon->intention_num + RivalPokemon->power;
						PlaySound(MAKEINTRESOURCE(IDR_HIT_DEFENSE), NULL, SND_RESOURCE | SND_ASYNC);
					}
					else
					{
						MyPokemon->heart -= (RivalPokemon->intention_num + RivalPokemon->power - MyPokemon->defense);
						PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_ASYNC);
						MyPokemon->defense = 0;
					}
				}
			}
			else if (intention == DEFEND)
			{
				defend_on = 2;
				defend_frame_id = 0;
				RivalPokemon->defense += RivalPokemon->intention_num + RivalPokemon->speed;
				PlaySound(MAKEINTRESOURCE(IDR_DEFEND), NULL, SND_RESOURCE | SND_ASYNC);
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
				attack_on = 1;
				attack_frame_id = 0;
				if (MyPokemon->defense == 0)
				{
					MyPokemon->heart -= RivalPokemon->intention_num + RivalPokemon->power;
					PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_ASYNC);
				}
				else
				{
					if (RivalPokemon->intention_num + RivalPokemon->power <= MyPokemon->defense)
					{
						MyPokemon->defense -= RivalPokemon->intention_num + RivalPokemon->power;
						PlaySound(MAKEINTRESOURCE(IDR_HIT_DEFENSE), NULL, SND_RESOURCE | SND_ASYNC);
					}
					else
					{
						MyPokemon->heart -= (RivalPokemon->intention_num + RivalPokemon->power - MyPokemon->defense);
						PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_ASYNC);
						MyPokemon->defense = 0;
					}
				}
			}
			else if (intention == DEFEND)
			{
				defend_on = 2;
				defend_frame_id = 0;
				RivalPokemon->defense += RivalPokemon->intention_num + RivalPokemon->speed;
				PlaySound(MAKEINTRESOURCE(IDR_DEFEND), NULL, SND_RESOURCE | SND_ASYNC);
			}
			else if (intention == AFFECT)
			{
				PlaySound(MAKEINTRESOURCE(IDR_AFFECT_DOWN), NULL, SND_RESOURCE | SND_SYNC);
				discarded_cards.push_back(CreateCard(WOUND));
				discarded_cards.push_back(CreateCard(WOUND));
				discarded_cards.push_back(CreateCard(WOUND));
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
				attack_on = 1;
				attack_frame_id = 0;
				if (MyPokemon->defense == 0)
				{
					MyPokemon->heart -= RivalPokemon->intention_num + RivalPokemon->power;
					PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_ASYNC);
				}
				else
				{
					if (RivalPokemon->intention_num + RivalPokemon->power <= MyPokemon->defense)
					{
						MyPokemon->defense -= RivalPokemon->intention_num + RivalPokemon->power;
						PlaySound(MAKEINTRESOURCE(IDR_HIT_DEFENSE), NULL, SND_RESOURCE | SND_ASYNC);
					}
					else
					{
						MyPokemon->heart -= (RivalPokemon->intention_num + RivalPokemon->power - MyPokemon->defense);
						PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_ASYNC);
						MyPokemon->defense = 0;
					}
				}
			}
			else if (intention == DEFEND)
			{
				defend_on = 2;
				defend_frame_id = 0;
				RivalPokemon->defense += RivalPokemon->intention_num + RivalPokemon->speed;
				PlaySound(MAKEINTRESOURCE(IDR_DEFEND), NULL, SND_RESOURCE | SND_ASYNC);
			}
			else if (intention == AFFECT)
			{
				PlaySound(MAKEINTRESOURCE(IDR_AFFECT_DOWN), NULL, SND_RESOURCE | SND_SYNC);
				RivalPokemon->power += 10;
				RivalPokemon->speed += 10;
				discarded_cards.push_back(CreateCard(WOUND));
				discarded_cards.push_back(CreateCard(WOUND));
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

//出牌函数
void PlayCard(HWND hWnd, int num)
{
	if (hand_cards[num - 1]->expend <= MyPokemon->energy)
	{
		consumed_energy = 0;
		card_select = 0;
		MyPokemon->energy -= hand_cards[num - 1]->expend;
		if (hand_cards[num - 1]->harm != 0)
		{
			attack_on = 2;
			attack_frame_id = 0;
			if (RivalPokemon->defense == 0)
			{
				RivalPokemon->heart -= hand_cards[num - 1]->harm + MyPokemon->power;
				PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_ASYNC);
			}
			else
			{
				if (hand_cards[num - 1]->harm + MyPokemon->power <= RivalPokemon->defense)
				{
					RivalPokemon->defense -= (hand_cards[num - 1]->harm + MyPokemon->power);
					PlaySound(MAKEINTRESOURCE(IDR_HIT_DEFENSE), NULL, SND_RESOURCE | SND_ASYNC);
				}
				else
				{
					RivalPokemon->heart -= (hand_cards[num - 1]->harm + MyPokemon->power - RivalPokemon->defense);
					RivalPokemon->defense = 0;
					PlaySound(MAKEINTRESOURCE(IDR_ATTACK), NULL, SND_RESOURCE | SND_ASYNC);
				}
			}
		}
		if (hand_cards[num - 1]->defend != 0)
		{
			defend_on = 1;
			defend_frame_id = 0;
			MyPokemon->defense += hand_cards[num - 1]->defend + MyPokemon->speed;
			PlaySound(MAKEINTRESOURCE(IDR_DEFEND), NULL, SND_RESOURCE | SND_ASYNC);
		}
		hand_cards[num - 1]->affect(hWnd);
		for (int i = 0; i < buttons.size(); i++)
		{
			if (buttons[i] != nullptr)
			{
				int id = buttons[i]->buttonID;
				if (id == BUTTON_CARD_1 + num - 1)
				{
					delete buttons[i];
					buttons[i] = nullptr;  // 避免悬挂指针  
					buttons.erase(buttons.begin() + i);
				}
			}
		}
		if (hand_cards[num - 1]->way == 0) discarded_cards.push_back(hand_cards[num - 1]);
		hand_cards.erase(hand_cards.begin() + num - 1);
		RefreshCards(hWnd);
	}
	return;
}

//战斗结束后清空三个区域的函数
void DeleteCard(HWND hWnd)
{
	if (!hand_cards.empty()) hand_cards.clear();
	if (!draw_cards.empty()) draw_cards.clear();
	if (!discarded_cards.empty()) discarded_cards.clear();
	return;
}

//刷新卡牌显示
void RefreshCards(HWND hWnd)
{
	for (int i = 1; i <= min(4, hand_cards.size()); i++)
	{
		if (i == 1)
		{
			bmp_hand_card_1 = hand_cards[i - 1]->img;
		}
		else if (i == 2)
		{
			bmp_hand_card_2 = hand_cards[i - 1]->img;
		}
		else if (i == 3)
		{
			bmp_hand_card_3 = hand_cards[i - 1]->img;
		}
		else if (i == 4)
		{
			bmp_hand_card_4 = hand_cards[i - 1]->img;
		}
	}
	for (int i = 0; i < buttons.size(); i++)
	{
		if (buttons[i] != nullptr)
		{
			int id = buttons[i]->buttonID;
			if (id == BUTTON_CARD_1 || id == BUTTON_CARD_2 || id == BUTTON_CARD_3 || id == BUTTON_CARD_4)
			{
				delete buttons[i];
				buttons[i] = nullptr;  // 避免悬挂指针  
				buttons.erase(buttons.begin() + i);
				i--;
			}
		}
	}
	if (hand_cards.size() >= 1) Button* handcard1Button = CreateButton(BUTTON_CARD_1, bmp_hand_card_1, 200, 300, 100, 470);
	if (hand_cards.size() >= 2) Button* handcard2Button = CreateButton(BUTTON_CARD_2, bmp_hand_card_2, 200, 300, 300, 470);
	if (hand_cards.size() >= 3) Button* handcard3Button = CreateButton(BUTTON_CARD_3, bmp_hand_card_3, 200, 300, 500, 470);
	if (hand_cards.size() >= 4) Button* handcard4Button = CreateButton(BUTTON_CARD_4, bmp_hand_card_4, 200, 300, 700, 470);
	if (currentStage->stageID == STAGE_BATTLE)InitStage(hWnd, STAGE_BATTLE);
	if (currentStage->stageID == STAGE_BOSS)InitStage(hWnd, STAGE_BOSS);
	return;
}

//结束回合函数
void EndRound(HWND hWnd, int roundnum)
{
	attack_on = 0;
	defend_on = 0;
	attack_frame_id = 0;
	defend_frame_id = 0;
	RivalPokemon->defense = 0;
	for (int i = 0; i < hand_cards.size(); i++)
	{
		discarded_cards.push_back(hand_cards[i]);
	}
	if (!hand_cards.empty()) hand_cards.clear();
	MyPokemon->energy = MyPokemon->full_energy;
	RivalAction(hWnd, round_num,RivalPokemon->intention);
	MyPokemon->defense = 0;
	if(MyPokemon->heart > 0 && RivalPokemon->heart > 0) DrawCards(hWnd,3);
	round_num++;
	return;
}
