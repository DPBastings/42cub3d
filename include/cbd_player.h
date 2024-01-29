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

struct s_player
{
	t_dpoint	pos;
	double		view_x;
	double		view_z;
};

void	player_init(t_player *player, t_point pt, t_startpos orientation);

#endif // CBD_PLAYER_H