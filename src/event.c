/*
** EPITECH PROJECT, 2017
** event
** File description:
** event
*/

#include "my_hunter.h"

void key_pressed(sfRenderWindow *window, sfEvent event, Entities **e)
{
	if (event.key.code == sfKeyP)
		(*e)->pause = 1;
	if (event.key.code == sfKeyEscape) {
		if ((*e)->lives->over != 1)
			(*e)->pause = 1;
		else
			sfRenderWindow_close(window);
	}
	if (event.key.code == sfKeySpace) {
		sfRenderWindow_setMouseCursorVisible(window, sfFalse);
		(*e)->pause = 0;
	}
	if (event.key.code == sfKeyR) {
		other_inits(e, window);
		sfSprite_setPosition((*e)->duck->sprite, (*e)->duck->position);
	}
}

void analyse_events(sfRenderWindow *window, sfEvent event, Entities **e)
{
	if (event.type == sfEvtKeyPressed)
		key_pressed(window, event, e);
	if (event.type == sfEvtMouseButtonPressed) {
		if (event.mouseButton.button == sfMouseLeft) {
			if ((*e)->pause != 1 && (*e)->lives->over != 1) {
				sfMusic_play((*e)->death->music);
				kill_duck(e);
			}
		}
	}
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(window);
}
