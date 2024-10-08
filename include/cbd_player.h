/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_player.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:38:50 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/19 15:32:28 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_PLAYER_H
# define CBD_PLAYER_H

# include "cbd.h"
# include "point.h"
# include "types.h"

# define PLAYER_STEP_SPEED	0.03125
# define PLAYER_HTURN_SPEED	0.03125
# define PLAYER_VTURN_SPEED	10		// unsigned
# define PLAYER_HITBOX		6.0

typedef enum e_direction
{
	DIR_FORWARD = 0,
	DIR_LEFT,
	DIR_BACKWARD,
	DIR_RIGHT,
	N_DIRECTION,
}	t_direction;

/**
 * @brief	Player object.
 * @param pos		Player's position.
 * @param delta_o	Orientation vector.
 * @param delta_m	Movement vector.
 * @param view_z	Z axis tilt.
 */
struct s_player
{
	t_dpoint	pos;
	t_dvector	delta_o;
	t_dvector	delta_m;
	int			view_z;
}; // struct s_player

typedef void	(*t_player_turnf)(t_player *);
typedef void	(*t_player_stepf)(t_player *, t_map const *);

void		player_init(t_player *self, t_point pt, t_compass_direction cmps);

t_object	*player_collide(t_player const *self, t_map *map, t_direction dir);
void		player_step_forward(t_player *self, t_map const *map);
void		player_step_backward(t_player *self, t_map const *map);
void		player_step_left(t_player *self, t_map const *map);
void		player_step_right(t_player *self, t_map const *map);
void		player_turn_h(t_player *self, double rad);
void		player_turn_v(t_player *self, double delta);

static inline t_dvector	dvc_from_rad(double rad)
{
	return ((t_dvector){cos(rad), sin(rad)});
}

#endif // CBD_PLAYER_H
