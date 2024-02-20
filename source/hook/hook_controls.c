/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:49:45 by dbasting          #+#    #+#             */
/*   Updated: 2024/02/20 12:49:46 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_hook.h"
#include "cbd_game.h"

static const keys_t		g_keys_move[N_DIRECTION] = {
	MLX_KEY_W, MLX_KEY_A, MLX_KEY_S, MLX_KEY_D,
};
static const keys_t		g_keys_view[N_DIRECTION] = {
	MLX_KEY_LEFT, MLX_KEY_RIGHT, MLX_KEY_UP, MLX_KEY_DOWN,
};
static const t_dvector	g_view_delta[N_DIRECTION] = {
	(t_dvector){-PLAYER_HTURN_SPEED, 0.0},
	(t_dvector){PLAYER_HTURN_SPEED, 0.0},
	(t_dvector){0.0, PLAYER_VTURN_SPEED},
	(t_dvector){0.0, -PLAYER_VTURN_SPEED},
};

static inline void	_controls_move(t_game *game);
static inline void	_controls_view(t_game *game);

void	hook_controls(void *param)
{
	t_game *const	game = param;

	if (game->status == CBD_GAME_RUNS)
	{
		_controls_view(game);
		_controls_move(game);
	}
}

static inline void	_controls_move(t_game *game)
{
	t_direction	dir;

	dir = 0;
	while (dir < N_DIRECTION)
	{
		if (mlx_is_key_down(game->mlx, g_keys_move[dir]))
			hook_move(dir, game);
		++dir;
	}
}

static inline void	_controls_view(t_game *game)
{
	t_direction	dir;
	t_dvector	view_delta;

	dir = 0;
	view_delta = (t_dvector){0.0, 0.0};
	while (dir < N_DIRECTION)
	{
		if (mlx_is_key_down(game->mlx, g_keys_view[dir]))
			view_delta = dvc_add(view_delta, g_view_delta[dir]);
		++dir;
	}
	hook_view(view_delta, game);
}

