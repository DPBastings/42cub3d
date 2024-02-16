/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 18:53:44 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/16 14:45:23 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_hook.h"
#include "cbd_game.h"

#include "cbd_player.h"

#include "debug.h"

void	hooks_init(t_game *game)
{
	mlx_loop_hook(game->mlx, hook_controls, game);
	mlx_loop_hook(game->mlx, hook_render, game);
}
