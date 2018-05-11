/*
** EPITECH PROJECT, 2017
** cc
** File description:
** cc
*/

#include "my_hunter.h"

void usage(char **av)
{
	if (av[1][0] == '-' && av[1][1] == 'h') {
		my_putstr("\nCode Lyoko Hunter Game, version 1.1 by !doia.\n");
		my_putstr("Odd needs to kill the Mantas, help him aiming!\n");
		my_putstr("Press P or ESCP to pause the game, ");
		my_putstr("then space to remuse it.\n");
		my_putstr("Press ESCP to quit the game after a Game Over, ");
		my_putstr("and let X.A.N.A and his Mantas win the game.\n");
		my_putstr("Press R to restart the game after a Game Over, ");
		my_putstr("Odd needs you!\n\n");
	}
}

void update(Entities **elem, sfRenderWindow *window)
{
	if ((*elem)->clockk->seconds - (*elem)->clockk->sec_temp > 0.076) {
		move_rect(elem);
		move_sprite(elem);
		return_sprite(elem);
		text_lives(elem, window);
		text_score(elem, window);
	}
	if ((*elem)->clockk->seconds - (*elem)->clockk->sec_temp > 0.08) {
		move_rect_death(elem);
		(*elem)->clockk->sec_temp = (*elem)->clockk->seconds;
	}
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, (*elem)->sprimage, NULL);
	sfRenderWindow_drawSprite(window, (*elem)->hand->sprite, NULL);
	sfRenderWindow_drawSprite(window, (*elem)->duck->sprite, NULL);
	sfRenderWindow_drawSprite(window, (*elem)->death->sprit, NULL);
	sfRenderWindow_drawText(window, (*elem)->text->lives, NULL);
	sfRenderWindow_drawText(window, (*elem)->text->score, NULL);
	sfRenderWindow_drawSprite(window, (*elem)->mouse->sprite, NULL);
}

void always_update(sfRenderWindow *window, Entities **e)
{
	(*e)->clockk->time = sfClock_getElapsedTime((*e)->clockk->clock);
	(*e)->clockk->seconds = (*e)->clockk->time.microseconds / 1000000.0;
	mouse_position(e, window);
	hand_position(e);
}

void destroy(sfMusic *music, sfRenderWindow *window, Entities **e)
{
	sfRenderWindow_destroy(window);
	sfMusic_destroy(music);
	sfMusic_destroy((*e)->death->music);
	free((*e)->mouse);
	free((*e)->hand);
	free((*e)->clockk);
	free((*e)->duck);
	free((*e)->lives);
	free((*e)->death);
	free((*e)->text);
}

int main(int ac, char **av)
{
	sfRenderWindow *window;
	sfEvent event;
	Entities *e;
	sfMusic *music;

	if (ac >= 2)
		usage(av);
	window = create_window();
	malloc_one(&e, window);
	music = create_music();
	while (sfRenderWindow_isOpen(window)) {
		game(&e, window);
		while (sfRenderWindow_pollEvent(window, &event))
			analyse_events(window, event, &e);
		sfRenderWindow_display(window);
	}
	destroy(music, window, &e);
	return (0);
}
