#include "Pokemon_Go.h"

Card* CreateCard(int ID)
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
		DrawCards(hWnd,1);
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