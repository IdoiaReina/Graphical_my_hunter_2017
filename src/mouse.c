/*
** EPITECH PROJECT, 2017
** mouse
** File description:
** mouse
*/

#include "my_hunter.h"

void mouse(Entities **elem)
{
	sfTexture *text_mouse;
	char *path = "Assets/Pictures/cursor.png";

	text_mouse = sfTexture_createFromFile(path, NULL);
	(*elem)->mouse->sprite = sfSprite_create();
	sfSprite_setTexture((*elem)->mouse->sprite, text_mouse, sfTrue);
	(*elem)->mouse->position.x = 0;
	(*elem)->mouse->position.y = 0;
	sfSprite_setPosition((*elem)->mouse->sprite, (*elem)->mouse->position);
}

void mouse_position(Entities **e, sfRenderWindow *window)
{
	(*e)->mouse->position_mouse = sfMouse_getPositionRenderWindow(window);
	(*e)->mouse->position.x = (*e)->mouse->position_mouse.x - 13;
	(*e)->mouse->position.y = (*e)->mouse->position_mouse.y;
	sfSprite_setPosition((*e)->mouse->sprite, (*e)->mouse->position);
}

void hand(Entities **elem)
{
	sfTexture *text_hand;

	text_hand = sfTexture_createFromFile("Assets/Pictures/hand.png", NULL);
	(*elem)->hand->sprite = sfSprite_create();
	sfSprite_setTexture((*elem)->hand->sprite, text_hand, sfTrue);
	(*elem)->hand->position.x = 0;
	(*elem)->hand->position.y = 0;
	sfSprite_setPosition((*elem)->hand->sprite, (*elem)->hand->position);
}

void hand_position(Entities **elem)
{
	(*elem)->hand->position.x = (*elem)->mouse->position_mouse.x - 150;
	(*elem)->hand->position.y = 875;
	sfSprite_setPosition((*elem)->hand->sprite, (*elem)->hand->position);
}
