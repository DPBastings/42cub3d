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

typedef void	(*t_viewf)(t_camera *, t_player *);

static void	_turn_left(t_camera *camera, t_player *player);
static void	_turn_right(t_camera *camera, t_player *player);
static void	_turn_up(t_camera *camera, t_player *player);
static void	_turn_down(t_camera *camera, t_player *player);

static const keys_t		g_keys_view[N_DIRECTION] = {
	MLX_KEY_LEFT, MLX_KEY_RIGHT, MLX_KEY_UP, MLX_KEY_DOWN,
};
static const t_viewf	g_viewfs[N_DIRECTION] = {
	_turn_left, _turn_right, _turn_up, _turn_down,
};

void	hook_view(void *param)
{
	t_game *const	game = param;
	t_direction		dir;

	dir = 0;
	while (dir < N_DIRECTION)
	{
		if (mlx_is_key_down(game->mlx, g_keys_view[dir]))
			g_viewfs[dir](&game->rc.camera, &game->map.player);
		++dir;
	}
}

static void	_turn_left(t_camera *camera, t_player *player)
{
	camera_rotate(camera, -PLAYER_TURN_SPEED);
	player_turn_left(player);
}

static void	_turn_right(t_camera *camera, t_player *player)
{
	camera_rotate(camera, PLAYER_TURN_SPEED);
	player_turn_right(player);
}

static void	_turn_up(t_camera *camera, t_player *player)
{
	(void) camera;
	player_turn_up(player);
}

static void	_turn_down(t_camera *camera, t_player *player)
{
	(void) camera;
	player_turn_down(player);
}
