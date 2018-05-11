/*
** EPITECH PROJECT, 2017
** main2
** File description:
** main2
*/

#include "my_hunter.h"

void game(Entities **e, sfRenderWindow *window)
{
	always_update(window, e);
	if ((*e)->lives->over != 1 && (*e)->pause != 1)
		update(e, window);
	else if ((*e)->pause == 1)
		during_pause(e, window);
	else
		during_game_over(e, window);
}

void during_pause(Entities **e, sfRenderWindow *window)
{
	sfRenderWindow_setMouseCursorVisible(window, sfTrue);
	sfRenderWindow_drawSprite(window, (*e)->sprimage, NULL);
	text_pause(e, window);
}

void during_game_over(Entities **e, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, (*e)->sprimage, NULL);
	sfRenderWindow_setMouseCursorVisible(window, sfTrue);
	text_game_over(e, window);
}
