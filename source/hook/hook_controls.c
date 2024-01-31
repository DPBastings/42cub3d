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

#include "cbd_hook.h"
#include "cbd_player.h"

#include "MLX42.h"

#define N_CONTROL_KEYS	6

typedef void	(*keyf_t)(t_map *, mlx_t *);

void	hook_controls(void *param)
{
	t_game *const	game = param;

	keys_controls(&game->map, game->mlx);
	mouse_controls(&game->map, game->mlx);
}

static const keys_t	g_keys_controls[N_CONTROL_KEYS] = {
	MLX_KEY_D, MLX_KEY_W, MLX_KEY_A, MLX_KEY_S, MLX_KEY_LEFT, MLX_KEY_RIGHT
};

static void	keys_controls(t_map *map, mlx_t *mlx)
{
	size_t	i;

	i = 0;
	while (i < N_CONTROL_KEYS)
		if (mlx_is_key_down(
}
