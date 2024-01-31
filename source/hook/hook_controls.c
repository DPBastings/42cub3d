/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:44:42 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/31 18:44:43 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_game.h"
#include "cbd_hook.h"
#include "cbd_player.h"

#include "MLX42.h"

static int	keys_change_view(t_map *map, mlx_t *mlx);
static int	keys_move(t_map *map, mlx_t *mlx);

void	hook_controls(void *param)
{
	t_game *const	game = param;

	keys_change_view(&game->map, game->mlx);
	keys_move(&game->map, game->mlx);
}

/*static const keys_t	g_keys_view[4] = {
	MLX_KEY_LEFT, MLX_KEY_RIGHT, MLX_KEY_UP, MLX_KEY_DOWN,
};*/

static int	keys_change_view(t_map *map, mlx_t *mlx)
{
	(void) map;
	(void) mlx;
	return (0);
}

static const keys_t	g_keys_move[N_DIRECTION] = {
	MLX_KEY_D, MLX_KEY_W, MLX_KEY_A, MLX_KEY_S,
};

static const player_method_t	g_stepfs[N_DIRECTION] = {
	player_step_right, player_step_forward,
	player_step_left, player_step_backward,
};

static int	keys_move(t_map *map, mlx_t *mlx)
{
	t_direction	dir;
	int			has_moved;

	dir = 0;
	has_moved = 0;
	while (dir < N_DIRECTION)
	{
		if (mlx_is_key_down(mlx, g_keys_move[dir])
			&& player_collide(&map->player, map, dir)->type == OBJ_EMPTY)
		{
			g_stepfs[dir](&map->player);
			has_moved = 1;
		}
		++dir;
	}
	return (has_moved);
}
