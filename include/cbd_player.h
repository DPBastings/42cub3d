/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_player.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:38:50 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 17:35:03 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_PLAYER_H
# define CBD_PLAYER_H

# include "cbd.h"
# include "point.h"

typedef enum e_direction
{
	DIR_NORTH = 0,
	DIR_EAST,
	DIR_SOUTH,
	DIR_WEST,
	N_DIRECTION,
}	t_direction;

struct s_player
{
	t_dpoint	pos;
	double		view_x;
	double		view_z;
}; // struct s_player

void	player_init(t_player *self, t_point pt, t_direction direction);

#endif // CBD_PLAYER_H
