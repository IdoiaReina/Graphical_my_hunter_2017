/*
** EPITECH PROJECT, 2017
** duck
** File description:
** duck
*/

#include "my_hunter.h"

void speed(Entities **elem)
{
	(*elem)->duck->speed = (*elem)->duck->speed + 5;
}

void missed(Entities **elem)
{
	(*elem)->lives->life = (*elem)->lives->life - 1;
	if ((*elem)->lives->life == 0) {
		(*elem)->lives->over = 1;
	}
}

void after_killed(Entities **e)
{
	origin(e);
	(*e)->score = (*e)->score + 1;
	speed(e);
	display_death(e);
}

void kill_duck(Entities **e)
{
	(*e)->miss = 1;
	if ((*e)->duck->side == 1) {
		if (MPX >= DPX && MPX <= DPX + 285) {
			if (MPY >= DPY + 60 && MPY <= DPY + 146) {
				after_killed(e);
				return_sprite(e);
				(*e)->miss = 0;
			}
		}
	}
	if ((*e)->duck->side == 0) {
		if (MPX >= DPX - 285 && MPX <= DPX) {
			if (MPY >= DPY + 60 && MPY <= DPY + 146) {
				after_killed(e);
				(*e)->miss = 0;
			}
		}
	}
	if ((*e)->miss != 0)
		missed(e);
}
