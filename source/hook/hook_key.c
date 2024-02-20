/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:49:30 by dbasting          #+#    #+#             */
/*   Updated: 2024/02/20 11:49:30 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_hook.h"
#include "cbd_game.h"

void	hook_key(mlx_key_data_t keydata, void *param)
{
	t_game *const	game = param;

	if (keydata.key == MLX_KEY_P && keydata.action == MLX_RELEASE)
		game_pause_toggle(game);
	else if (keydata.key == MLX_KEY_ESCAPE)
		hook_close(game->mlx);
}
