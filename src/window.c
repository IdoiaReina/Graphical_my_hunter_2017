/*
** EPITECH PROJECT, 2017
** window
** File description:
** window
*/

#include "my_hunter.h"

sfRenderWindow *create_window(void)
{
	sfRenderWindow	*win;
	sfVideoMode	video_mode;
	char *n = "My_hunter";

	video_mode.width = 1920;
	video_mode.height = 1080;
	video_mode.bitsPerPixel = 72;
	win = sfRenderWindow_create(video_mode, n, sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(win, 120);
	return (win);
}
