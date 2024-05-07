#include "Pokemon_Go.h"

Card* Card::CreateCard(int ID)
{
	Card* card = new Card();
	
	switch (ID)
	{
	case WOUND:
	{
		card->img = bmp_card_wound;
		card->card_ID = 0;
		card->expend = 99;
		card->way = 0;
		break;
	}
	case NORMAL_ATTACK:
	{
		card->img = bmp_card_1;
		card->card_ID = 1;
		card->harm = 6;
		card->expend = 1;
		card->way = 0;
		break;
	}
	case NORMAL_DEFEND:
	{
		card->img = bmp_card_2;
		card->card_ID = 2;
		card->expend = 1;
		card->defend = 6;
		card->way = 0;
		break;
	}
	case VOLT_ATTACK:
	{
		card->img = bmp_card_3;
		card->card_ID = 3;
		card->expend = 2;
		card->harm = 10;
		card->way = 0;
		break;
	}
	case DRAGON_DANCE:
	{
		card->img = bmp_card_4;
		card->card_ID = 4;
		card->expend = 3;
		card->harm = 0;
		card->way = 1;
		break;
	}
	case MYSTIC_DEFEND:
	{
		card->img = bmp_card_5;
		card->card_ID = 5;
		card->expend = 2;
		card->defend = 14;
		card->way = 0;
		break;
	}
	case CHANGE_COURT:
	{
		card->img = bmp_card_6;
		card->card_ID = 6;
		card->expend = 3;
		card->way = 0;
		break;
	}
	case BIG_BANG:
	{
		card->img = bmp_card_7;
		card->card_ID = 7;
		card->expend = 2;
		card->way = 1;
		card->harm = 30;
		break;
	}
	case EQUAL_LIFE:
	{
		card->img = bmp_card_8;
		card->card_ID = 8;
		card->expend = 3;
		card->way = 1;
		card->harm = 0;
		break;
	}
	case SHADOW_AVATAR:
	{
		card->img = bmp_card_9;
		card->card_ID = 9;
		card->expend = 1;
		card->way = 0;
		card->harm = 0;
		break;
	}
	case DRAGON_ATTACK:
	{
		card->img = bmp_card_10;
		card->card_ID = 10;
		card->expend = 3;
		card->way = 0;
		card->harm = 32;
		break;
	}
	case LIGHTNING_FLASH:
	{
		card->img = bmp_card_11;
		card->card_ID = 11;
		card->expend = 0;
		card->way = 0;
		card->harm = 0;
		break;
	}
	case ROOT_FLUCTUATION:
	{
		card->img = bmp_card_12;
		card->card_ID = 12;
		card->expend = 2;
		card->way = 0;
		card->harm = 6;
		break;
	}
	default:break;
	}
	return card;
}


void Card::affect(HWND hWnd)
{
	switch(card_ID)
	{
	case 0:break;
	case 1:break;
	case 2:break;
	case 3: 
	{
		MyPokemon->speed += 2;
		break;
	}
	case 4:
	{
		PlaySound(MAKEINTRESOURCE(IDR_AFFECT_UP), NULL, SND_RESOURCE | SND_ASYNC);
		MyPokemon->power+=10;
		break;
	}
	case 5:
	{
		MyPokemon->speed += 2;
		break;
	}
	case 6:
	{
		PlaySound(MAKEINTRESOURCE(IDR_AFFECT_UP), NULL, SND_RESOURCE | SND_ASYNC);
		swap(MyPokemon->speed,RivalPokemon->speed);
		swap(MyPokemon->power, RivalPokemon->power);
		break;
	}
	case 7:
	{
		MyPokemon->heart -= 8;
		break;
	}
	case 8:
	{
		PlaySound(MAKEINTRESOURCE(IDR_AFFECT_DOWN), NULL, SND_RESOURCE | SND_ASYNC);
		if (MyPokemon->heart >= RivalPokemon->total_heart) RivalPokemon->heart = RivalPokemon->total_heart;
		else RivalPokemon->heart = MyPokemon->heart;
		break;
	}
	case 9:
	{
		PlaySound(MAKEINTRESOURCE(IDR_AFFECT_UP), NULL, SND_RESOURCE | SND_ASYNC);
		MyPokemon->speed += 3;
		Card::DrawCards(hWnd,1);
		break;
	}
	case 10:break;
	case 11:
	{
		PlaySound(MAKEINTRESOURCE(IDR_AFFECT_UP), NULL, SND_RESOURCE | SND_ASYNC);
		MyPokemon->energy += 1;
		MyPokemon->power += 1;
		break;
	}
	case 12:
	{
		MyPokemon->power *= 2;
		break;
	}

	default:break;
	}
	return;
}


void Card::CardChoose(HWND hWnd)
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
	Button* left_cardchooseButton = Button::CreateButton(left_card, bmp_left_card, 200, 300, 150, 150);
	Button* mid_cardchooseButton = Button::CreateButton(mid_card, bmp_mid_card, 200, 300, 400, 150);
	Button* right_cardchooseButton = Button::CreateButton(right_card, bmp_right_card, 200, 300, 650, 150);
	return;
}


void Card::DrawCards(HWND hWnd, int num)
{
	for (int i = 1; i <= num; i++)
	{
		if (draw_cards.size() <= 0)
			Card::UpdateCards(hWnd);
		int temp = rand() % draw_cards.size();
		if (draw_cards[temp] != NULL)
		{
			hand_cards.push_back(draw_cards[temp]);
			draw_cards.erase(draw_cards.begin() + temp);
		}
	}
	Card::RefreshCards(hWnd);
	return;
}


void Card::DeleteCard(HWND hWnd)
{
	if (!hand_cards.empty()) hand_cards.clear();
	if (!draw_cards.empty()) draw_cards.clear();
	if (!discarded_cards.empty()) discarded_cards.clear();
	return;
}


void Card::PlayCard(HWND hWnd, int num)
{
	if (hand_cards[num - 1]->expend <= MyPokemon->energy)
	{
		MyPokemon->energy -= hand_cards[num - 1]->expend;
		if (hand_cards[num - 1]->harm != 0)
		{
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
					buttons[i] = nullptr;  // ±‹√‚–¸π“÷∏’Î  
					buttons.erase(buttons.begin() + i);
				}
			}
		}
		if (hand_cards[num - 1]->way == 0) discarded_cards.push_back(hand_cards[num - 1]);
		hand_cards.erase(hand_cards.begin() + num - 1);
		Card::RefreshCards(hWnd);
	}
	return;
}


void Card::RefreshCards(HWND hWnd)
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
				buttons[i] = nullptr;  // ±‹√‚–¸π“÷∏’Î  
				buttons.erase(buttons.begin() + i);
				i--;
			}
		}
	}
	if (hand_cards.size() >= 1) Button* handcard1Button = Button::CreateButton(BUTTON_CARD_1, bmp_hand_card_1, 200, 300, 100, 470);
	if (hand_cards.size() >= 2) Button* handcard2Button = Button::CreateButton(BUTTON_CARD_2, bmp_hand_card_2, 200, 300, 300, 470);
	if (hand_cards.size() >= 3) Button* handcard3Button = Button::CreateButton(BUTTON_CARD_3, bmp_hand_card_3, 200, 300, 500, 470);
	if (hand_cards.size() >= 4) Button* handcard4Button = Button::CreateButton(BUTTON_CARD_4, bmp_hand_card_4, 200, 300, 700, 470);
	if (currentStage->stageID == STAGE_BATTLE)Stage::InitStage(hWnd, STAGE_BATTLE);
	if (currentStage->stageID == STAGE_BOSS)Stage::InitStage(hWnd, STAGE_BOSS);
	return;
}


void Card::UpdateCards(HWND hWnd)
{
	for (int i = 0; i < discarded_cards.size(); i++)
		draw_cards.push_back(discarded_cards[i]);
	if (!discarded_cards.empty()) discarded_cards.clear();
	return;
}


void Card::DeleteCardChoose(HWND hWnd)
{
	for (int i = 0; i < buttons.size(); i++)
	{
		if (buttons[i] != nullptr)
		{
			int id = buttons[i]->buttonID;
			if (id == BUTTON_CARD_CHOOSE_1 || id == BUTTON_CARD_CHOOSE_2 || id == BUTTON_CARD_CHOOSE_3
				|| id == BUTTON_CARD_CHOOSE_4 || id == BUTTON_CARD_CHOOSE_5 || id == BUTTON_CARD_CHOOSE_6
				|| id == BUTTON_CARD_CHOOSE_7 || id == BUTTON_CARD_CHOOSE_8 || id == BUTTON_CARD_CHOOSE_9
				|| id == BUTTON_CARD_CHOOSE_10 || id == BUTTON_CARD_CHOOSE_11 || id == BUTTON_CARD_CHOOSE_12)
			{
				delete buttons[i];
				buttons[i] = nullptr;  // ±‹√‚–¸π“÷∏’Î  
				buttons.erase(buttons.begin() + i);
				i--;
			}
		}
	}
}
