/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 17:28:55 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 17:54:23 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_player.h"

void	player_init(t_player *player, t_point pt, t_startpos orientation)
{
	player->pos.x = pt.x;
	player->pos.y = pt.y;
	(void) orientation;
}
