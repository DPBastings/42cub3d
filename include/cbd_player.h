/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_player.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:38:50 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/02 17:25:55 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_PLAYER_H
# define CBD_PLAYER_H

# include "cbd.h"
# include "point.h"

# define PLAYER_STEP_SPEED	0.125
# define PLAYER_TURN_SPEED	0.125
# define PLAYER_HITBOX_SIZE	0.250

typedef enum e_compass_direction
{
	DIR_EAST = 0,
	DIR_SOUTH,
	DIR_WEST,
	DIR_NORTH,
	N_COMPASS,
}	t_compass_direction;

typedef enum e_direction
{
	DIR_FORWARD = 0,
	DIR_BACKWARD,
	DIR_LEFT,
	DIR_RIGHT,
	N_DIRECTION,
}	t_direction;

/**
 * @brief	Player object.
 * @param pos		The player's position.
 * @param view_x	The player's horizontal view angle, in radians.
 * @param view_z	The player's vertical view angle, in radians.
 * @param delta		The distance traveled on the X and Y axes when moving.
 */
struct s_player
{
	t_dpoint	pos;
	double		view_x;
	double		view_z;
	t_dpoint	delta;
}; // struct s_player

typedef void	(*t_player_method)(t_player *);

void		player_init(t_player *self, t_point pt, t_compass_direction cmps);

t_object	*player_collide(t_player const *self, t_map *map, t_direction dir);
void		player_step_forward(t_player *self);
void		player_step_backward(t_player *self);
void		player_step_left(t_player *self);
void		player_step_right(t_player *self);
void		player_turn_left(t_player *self);
void		player_turn_right(t_player *self);
void		player_turn_up(t_player *self);
void		player_turn_down(t_player *self);

static inline t_dpoint	get_delta(double view_x)
{
	return ((t_dpoint){
		cos(view_x) * PLAYER_STEP_SPEED,
		sin(view_x) * PLAYER_STEP_SPEED
	});
}

#endif // CBD_PLAYER_H
