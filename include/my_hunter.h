/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <SFML/Audio.h>

#define MPX (*e)->mouse->position.x
#define	DPX (*e)->duck->position.x
#define	MPY (*e)->mouse->position.y
#define	DPY (*e)->duck->position.y

#ifndef STRUCT_LIST_
#define STRUCT_LIST_

typedef struct s_Mouse
{
	sfIntRect rect;
	sfSprite *sprite;
	sfVector2i position_mouse;
	sfVector2f position;
}Mouse;

typedef struct s_Hand
{
	sfIntRect rect;
	sfSprite *sprite;
	sfVector2f position;
}Hand;

typedef struct s_Clock
{
	sfClock *clock;
	sfTime time;
	float seconds;
	float sec_temp;
}Clock;

typedef struct s_Lives
{
	sfIntRect rect;
	sfSprite *sprite;
	sfVector2f position;
	int life;
	int over;
}Lives;

typedef struct s_Death
{
	sfIntRect rect;
	sfSprite *sprit;
	sfVector2f position;
	sfVector2f scale;
	sfMusic *music;
}Death;

typedef struct s_Duck
{
	sfIntRect rect;
	sfSprite *sprite;
	sfVector2f position;
	sfVector2f scale;
	sfVector2f origin;
	int side;
	int speed;
}Duck;

typedef struct s_Text
{
	sfFont *font;
	sfText *score;
	sfText *lives;
	sfText *over;
	sfText *over_k;
	sfVector2f position_over_k;
	sfVector2f position_over;
	sfVector2f position_lives;
	sfVector2f position_score;
	sfText *pause;
	sfText *pause_k;
	sfVector2f position_pause_k;
	sfVector2f position_pause;
}Text;

typedef struct s_Entities
{
	struct s_Duck *duck;
	struct s_Mouse *mouse;
	struct s_Lives *lives;
	struct s_Death *death;
	struct s_Clock *clockk;
	struct s_Hand *hand;
	struct s_Text *text;
	sfSprite *sprimage;
	int score;
	int pause;
	int miss;
}Entities;

/*INIT*/
void malloc_one(Entities **elem, sfRenderWindow *window);
void malloc_two(Entities **elem);
void other_inits(Entities **elem, sfRenderWindow *window);
void init_creations(Entities **e, sfRenderWindow *window);

/*Window*/
sfRenderWindow *create_window(void);

/*Events*/
void analyse_events(sfRenderWindow *window, sfEvent event, Entities **elem);
void key_pressed(sfRenderWindow *window, sfEvent event, Entities **e);

/*Background*/
sfSprite *create_background(void);
sfMusic *create_music(void);
void create_sound_arr(Entities **elem);

/*Mouse & Hand*/
void mouse(Entities **elem);
void mouse_position(Entities **e, sfRenderWindow *window);
void hand(Entities **elem);
void hand_position(Entities **elem);

/*Duck2*/
void origin(Entities **elem);
void duck(Entities **elem);
void move_rect(Entities **elem);
void return_sprite(Entities **elem);
void move_sprite(Entities **e);

/*Duck1*/
void speed(Entities **elem);
void missed(Entities **elem);
void after_killed(Entities **e);
void kill_duck(Entities **e);

/*Death*/
void death(Entities **elem);
void move_rect_death(Entities **elem);
void display_death(Entities **elem);

/*Text*/
void text_lives(Entities **elem, sfRenderWindow  *window);
void text_score(Entities **elem, sfRenderWindow  *window);
void create_font(Entities **elem);
void text_pause(Entities **elem, sfRenderWindow *window);
void text_game_over(Entities **elem, sfRenderWindow *window);

/*Main*/
void usage(char **av);
void update(Entities **elem, sfRenderWindow  *window);
void always_update(sfRenderWindow *window, Entities **e);
void my_putstr(char *);

/*Game*/
void during_pause(Entities **e, sfRenderWindow *window);
void during_game_over(Entities **e, sfRenderWindow *window);
void game(Entities **e, sfRenderWindow *window);

#endif
