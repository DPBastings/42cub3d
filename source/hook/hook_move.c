/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_move.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 17:35:45 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/19 17:38:16 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_game.h"
#include "cbd_hook.h"
#include "cbd_player.h"

#include "MLX42.h"

static const t_player_stepf	g_stepfs[N_DIRECTION] = {
	player_step_forward, player_step_left,
	player_step_backward, player_step_right,
};

void	hook_move(t_direction dir, t_game *game)
{
	g_stepfs[dir](&game->map.player, &game->map);
}
