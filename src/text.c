/*
** EPITECH PROJECT, 2017
** text
** File description:
** text
*/

#include "my_hunter.h"

void create_font(Entities **elem)
{
	(*elem)->text->font = sfFont_createFromFile("Assets/Fonts/gun4fc.ttf");
}

void text_lives(Entities **elem, sfRenderWindow *window)
{
	char nb_lives[9] = "Lives : ";

	nb_lives[8] = (*elem)->lives->life + 48;
	nb_lives[9] = '\0';
	(*elem)->text->lives = sfText_create();
	sfText_setFont((*elem)->text->lives, (*elem)->text->font);
	sfText_setString((*elem)->text->lives, nb_lives);
	sfRenderWindow_drawText(window, (*elem)->text->lives, NULL);
	(*elem)->text->position_lives.x = 10;
	(*elem)->text->position_lives.y	= 30;
	sfText_setPosition((*elem)->text->lives, (*elem)->text->position_lives);
}

void text_score(Entities **e, sfRenderWindow *window)
{
	char score[11] = "Score :   ";
	int modulo;

	if ((*e)->score >= 10) {
		modulo = ((*e)->score % 10);
		score[8] = ((*e)->score - modulo) / 10 + 48;
		score[9] = modulo + 48;
	}
	else
		score[8] = (*e)->score + 48;
	(*e)->text->score = sfText_create();
	sfText_setFont((*e)->text->score, (*e)->text->font);
	sfText_setString((*e)->text->score, score);
	sfRenderWindow_drawText(window, (*e)->text->score, NULL);
	(*e)->text->position_score.x = 10;
	(*e)->text->position_score.y = 0;
	sfText_setPosition((*e)->text->score, (*e)->text->position_score);
}

void text_pause(Entities **e, sfRenderWindow *window)
{
	(*e)->text->pause = sfText_create();
	sfText_setFont((*e)->text->pause, (*e)->text->font);
	sfText_setString((*e)->text->pause, "PAUSE");
	(*e)->text->position_pause.x = 780;
	(*e)->text->position_pause.y = 440;
	sfText_setCharacterSize((*e)->text->pause, 100);
	sfText_setPosition((*e)->text->pause, (*e)->text->position_pause);
	sfRenderWindow_drawText(window, (*e)->text->pause, NULL);
	(*e)->text->pause_k = sfText_create();
	sfText_setFont((*e)->text->pause_k, (*e)->text->font);
	sfText_setString((*e)->text->pause_k, "PRESS SPACE TO CONTINUE");
	(*e)->text->position_pause_k.x = 720;
	(*e)->text->position_pause_k.y = 540;
	sfText_setPosition((*e)->text->pause_k, (*e)->text->position_pause_k);
	sfRenderWindow_drawText(window, (*e)->text->pause_k, NULL);
}

void text_game_over(Entities **e, sfRenderWindow *window)
{
	(*e)->text->over = sfText_create();
	sfText_setFont((*e)->text->over, (*e)->text->font);
	sfText_setString((*e)->text->over, "GAME OVER");
	(*e)->text->position_over.x = 642;
	(*e)->text->position_over.y = 440;
	sfText_setCharacterSize((*e)->text->over, 100);
	sfText_setPosition((*e)->text->over, (*e)->text->position_over);
	sfRenderWindow_drawText(window, (*e)->text->over, NULL);
	(*e)->text->over_k = sfText_create();
	sfText_setFont((*e)->text->over_k, (*e)->text->font);
	sfText_setString((*e)->text->over_k, "PRESS R TO RESTART");
	(*e)->text->position_over_k.x = 776;
	(*e)->text->position_over_k.y = 540;
	sfText_setPosition((*e)->text->over_k, (*e)->text->position_over_k);
	sfRenderWindow_drawText(window, (*e)->text->over_k, NULL);
}
