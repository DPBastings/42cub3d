/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_status.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 12:11:12 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/28 18:24:21 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_game.h"

#include "MLX42.h"

static inline void	_capture_mouse(mlx_t *mlx);
static inline void	_release_mouse(mlx_t *mlx);

void	game_pause(t_game *self)
{
	self->status = CBD_GAME_PAUSED;
	screen_overlay_pause(&self->screen.overlay);
	_release_mouse(self->mlx);
}

void	game_unpause(t_game *self)
{
	self->status = CBD_GAME_RUNS;
	screen_overlay_unpause(&self->screen.overlay);
	_capture_mouse(self->mlx);
}

void	game_pause_toggle(t_game *self)
{
	if (self->status == CBD_GAME_RUNS)
		game_pause(self);
	else if (self->status == CBD_GAME_PAUSED)
		game_unpause(self);
}

static inline void	_capture_mouse(mlx_t *mlx)
{
	mlx_set_mouse_pos(mlx, mlx->width / 2, mlx->height / 2);
	mlx_set_cursor_mode(mlx, MLX_MOUSE_HIDDEN);
}

static inline void	_release_mouse(mlx_t *mlx)
{
	mlx_set_cursor_mode(mlx, MLX_MOUSE_NORMAL);
}
