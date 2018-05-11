/*
** EPITECH PROJECT, 2017
** duck
** File description:
** duck
*/

#include "my_hunter.h"

void origin(Entities **elem)
{
	int b = 600;

	srand(time(NULL));
	(*elem)->duck->origin.y = rand() % b;
	(*elem)->duck->origin.x = -285;
	sfSprite_setPosition((*elem)->duck->sprite, (*elem)->duck->origin);
}

void duck(Entities **elem)
{
	sfTexture *text_duck;

	text_duck = sfTexture_createFromFile("Assets/Pictures/test4.png", NULL);
	(*elem)->duck->sprite = sfSprite_create();
	sfSprite_setTexture((*elem)->duck->sprite, text_duck, sfTrue);
	(*elem)->duck->rect.top = 0;
	(*elem)->duck->rect.left = 0;
	(*elem)->duck->rect.width = 285;
	(*elem)->duck->rect.height = 269;
	sfSprite_setTextureRect((*elem)->duck->sprite, (*elem)->duck->rect);
}

void move_rect(Entities **elem)
{
	if ((*elem)->duck->rect.left < 9975)
		(*elem)->duck->rect.left = (*elem)->duck->rect.left + 285;
	else
		(*elem)->duck->rect.left = 0;
	sfSprite_setTextureRect((*elem)->duck->sprite, (*elem)->duck->rect);
}

void return_sprite(Entities **elem)
{
	if ((*elem)->duck->side == 0) {
		(*elem)->duck->scale.x = -1;
		(*elem)->duck->scale.y = 1;
	}
	if ((*elem)->duck->side == 1) {
		(*elem)->duck->scale.x = 1;
		(*elem)->duck->scale.y = 1;
	}
	sfSprite_setScale((*elem)->duck->sprite, (*elem)->duck->scale);
}

void move_sprite(Entities **e)
{
	(*e)->duck->position = sfSprite_getPosition((*e)->duck->sprite);
	if ((*e)->duck->position.x <= -285)
		(*e)->duck->side = 0;
	if ((*e)->duck->position.x >= 2225)
		(*e)->duck->side = 1;
	if ((*e)->duck->side == 0) {
		(*e)->duck->position.x += (*e)->duck->speed;
		return_sprite(e);
	}
	if ((*e)->duck->side == 1) {
		(*e)->duck->position.x -= (*e)->duck->speed;
		return_sprite(e);
	}
	sfSprite_setPosition((*e)->duck->sprite, (*e)->duck->position);
}
