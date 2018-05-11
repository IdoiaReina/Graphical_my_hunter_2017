/*
** EPITECH PROJECT, 2017
** init
** File description:
** init
*/

#include "my_hunter.h"

void malloc_one(Entities **elem, sfRenderWindow *window)
{
	(*elem) = (Entities *)malloc(sizeof(Entities));
	if (elem == NULL)
		exit (1);
	(*elem)->duck = (Duck *)malloc(sizeof(Duck));
	if ((*elem)->duck == NULL)
		exit (1);
	(*elem)->mouse = (Mouse *)malloc(sizeof(Mouse));
	if ((*elem)->mouse == NULL)
		exit (1);
	(*elem)->lives = (Lives *)malloc(sizeof(Lives));
	if ((*elem)->lives == NULL)
		exit (1);
	(*elem)->death = (Death *)malloc(sizeof(Death));
	if ((*elem)->death == NULL)
		exit (1);
	malloc_two(elem);
	other_inits(elem, window);
	init_creations(elem, window);
}

void malloc_two(Entities**elem)
{
	(*elem)->clockk = (Clock *)malloc(sizeof(Clock));
	if ((*elem)->clockk == NULL)
		exit (1);
	(*elem)->hand = (Hand *)malloc(sizeof(Hand));
	if ((*elem)->hand == NULL)
		exit (1);
	(*elem)->text = (Text *)malloc(sizeof(Text));
	if ((*elem)->text == NULL)
		exit (1);
}

void other_inits(Entities **elem, sfRenderWindow *window)
{
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	(*elem)->miss = 1;
	(*elem)->score = 0;
	(*elem)->pause = 0;
	(*elem)->duck->side = 0;
	(*elem)->duck->speed = 10;
	(*elem)->duck->position.x = 0;
	(*elem)->duck->position.y = 0;
	(*elem)->mouse->position.x = 0;
	(*elem)->mouse->position.y = 0;
	(*elem)->hand->position.x = 0;
	(*elem)->hand->position.y = 0;
	(*elem)->text->position_score.x = 10;
	(*elem)->lives->life = 3;
	(*elem)->lives->over = 0;
	(*elem)->clockk->sec_temp = 0;
	create_font(elem);
}

void init_creations(Entities **e, sfRenderWindow *window)
{
	(*e)->clockk->clock = sfClock_create();
	(*e)->sprimage = create_background();
	create_sound_arr(e);
	duck(e);
	origin(e);
	death(e);
	text_lives(e, window);
	text_score(e, window);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	mouse(e);
	mouse_position(e, window);
	hand(e);
	hand_position(e);
}
