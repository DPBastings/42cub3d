/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_cursor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 16:28:13 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/26 14:41:03 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_hook.h"
#include "cbd_game.h"
#include "point.h"

#define SENSITIVITY	0.06125

static inline void	_cursor_turn(double xpos, double ypos, t_game *game);

void	hook_cursor(double xpos, double ypos, void *param)
{
	t_game *const	game = param;

	if (game->status == CBD_GAME_RUNS)
		_cursor_turn(xpos, ypos, game);
}

static inline void	_cursor_turn(double xpos, double ypos, t_game *game)
{
	t_dvector const	delta = (t_dvector){
		-(game->mlx->width / 2 - xpos) * SENSITIVITY * PLAYER_HTURN_SPEED,
		(game->mlx->height / 2 - ypos) * SENSITIVITY * PLAYER_VTURN_SPEED,
	};

	hook_view(delta, game);
	mlx_set_mouse_pos(game->mlx, game->mlx->width / 2, game->mlx->height / 2);
}
