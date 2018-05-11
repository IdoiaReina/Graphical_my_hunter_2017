/*
** EPITECH PROJECT, 2017
** beckground
** File description:
** beckground
*/

#include "my_hunter.h"

sfSprite *create_background(void)
{
	sfTexture	*textimage;
	sfSprite	*sprimage;
	char *path = "Assets/Pictures/territoire3.png";

	textimage = sfTexture_createFromFile(path, NULL);
	sprimage = sfSprite_create();
	sfSprite_setTexture(sprimage, textimage, sfTrue);
	return (sprimage);
}

sfMusic *create_music(void)
{
	sfMusic *music;

	music = sfMusic_createFromFile ("Assets/Music/Ice Sector.flac");
	sfMusic_setLoop(music, sfTrue);
	sfMusic_play(music);
	return (music);
}

void create_sound_arr(Entities **elem)
{
	char *path = "Assets/Music/arrow.wav";

	(*elem)->death->music = sfMusic_createFromFile(path);
}
