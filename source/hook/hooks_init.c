/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 18:53:44 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/16 16:33:45 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_hook.h"
#include "cbd_game.h"

#include "cbd_player.h"

#include "debug.h"

void	hooks_init(t_game *game)
{
	mlx_key_hook(game->mlx, hook_key_esc, game->mlx);
	mlx_close_hook(game->mlx, hook_close, game->mlx);
	mlx_cursor_hook(game->mlx, hook_cursor_turn, game);
	mlx_scroll_hook(game->mlx, hook_scroll_zoom, game);
	mlx_loop_hook(game->mlx, hook_controls, game);
	mlx_loop_hook(game->mlx, hook_render, game);
}
