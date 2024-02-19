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

static const keys_t			g_keys_move[N_DIRECTION] = {
	MLX_KEY_W, MLX_KEY_A, MLX_KEY_S, MLX_KEY_D,
};

static const t_player_stepf	g_stepfs[N_DIRECTION] = {
	player_step_forward, player_step_left,
	player_step_backward, player_step_right,
};

void	hook_move(void *param)
{
	t_game *const	game = param;
	t_direction		dir;

	dir = 0;
	while (dir < N_DIRECTION)
	{
		if (mlx_is_key_down(game->mlx, g_keys_move[dir]))
			g_stepfs[dir](&game->map.player, &game->map);
		++dir;
	}
}
