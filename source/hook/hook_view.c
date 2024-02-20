/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_view.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 18:44:42 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/19 17:44:30 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_game.h"
#include "cbd_hook.h"
#include "cbd_player.h"

#include "MLX42.h"

static void	_turn_h(t_camera *camera, t_player *player, double rad);
static void	_turn_v(t_camera *camera, t_player *player, double delta);

void	hook_view(t_dvector delta, t_game *game)
{
	_turn_h(&game->rc.camera, &game->map.player, delta.x);
	_turn_v(&game->rc.camera, &game->map.player, delta.y);
}

static void	_turn_h(t_camera *camera, t_player *player, double rad)
{
	camera_rotate(camera, rad);
	player_turn_h(player, rad);
}

static void	_turn_v(t_camera *camera, t_player *player, double delta)
{
	(void) camera;
	player_turn_v(player, delta);
}
