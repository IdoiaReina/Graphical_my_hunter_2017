/*
** EPITECH PROJECT, 2017
** death
** File description:
** death
*/

#include "my_hunter.h"

void death(Entities **elem)
{
	sfTexture *text_death;

	text_death = sfTexture_createFromFile("Assets/Pictures/Boom.png", NULL);
	(*elem)->death->sprit = sfSprite_create();
	sfSprite_setTexture((*elem)->death->sprit, text_death, sfTrue);
	(*elem)->death->rect.top = 0;
	(*elem)->death->rect.left = 0;
	(*elem)->death->rect.width = 128;
	(*elem)->death->rect.height = 128;
	(*elem)->death->position.x = -128;
	(*elem)->death->position.y = 0;
	sfSprite_setTextureRect((*elem)->death->sprit, (*elem)->death->rect);
	sfSprite_setPosition((*elem)->death->sprit, (*elem)->death->position);
}

void move_rect_death(Entities **e)
{
	if ((*e)->death->rect.left < 384) {
		(*e)->death->rect.left = (*e)->death->rect.left + 128;
	}
	else {
		(*e)->death->rect.left = 0;
		(*e)->death->position.x = -128;
		(*e)->death->position.y = 0;
		sfSprite_setPosition((*e)->death->sprit, (*e)->death->position);
	}
	sfSprite_setTextureRect((*e)->death->sprit, (*e)->death->rect);
}

void display_death(Entities **elem)
{
	(*elem)->death->position.x = (*elem)->mouse->position.x - 64;
	(*elem)->death->position.y = (*elem)->mouse->position.y - 64;
	(*elem)->death->rect.left = 0;
	sfSprite_setPosition((*elem)->death->sprit, (*elem)->death->position);
}
