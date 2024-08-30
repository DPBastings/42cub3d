/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:35:08 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/30 14:28:32 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_game.h"
#include "cbd_error.h"
#include "cbd_hook.h"
#include "cbd_rc.h"
#include "cbd_screen.h"
#include "types.h"
#include "hrc.h"
#include "ft_string.h"
#include <fcntl.h>
#include <unistd.h>

static t_fd	_open(char const *path);

void	game_init(t_game *self, char const *path)
{
	t_fd const	fd = _open(path);

	if (fd == -1)
		cbd_terminate(CBD_EGENERIC);
	game_read(self, fd);
	close(fd);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	self->mlx = mlx_init(CBD_SCREEN_W_DFL, CBD_SCREEN_H_DFL, TITLE, true);
	if (self->mlx == NULL)
		cbd_terminate(CBD_EGENERIC);
	hooks_init(self);
	screen_init(self, &self->screen, (struct s_screen_data){
		&self->assets, &self->rc, &self->map, &self->screen.view,
		&self->bonus}, self->mlx);
	rc_init(self, &self->rc, self->map.player.delta_o);
	hrc_init(self);
	self->screen.view.fog_constant = (self->map.x_size + self->map.y_size) / 4;
	self->screen.view.max_distance = sqrt((self->map.x_size * self->map.x_size)
			+ (self->map.y_size * self->map.y_size));
	self->status = CBD_GAME_STOPPED;
	self->fps_counter = mlx_new_image(self->mlx,
			CBD_SCREEN_W_DFL / 10, CBD_SCREEN_H_DFL / 10);
	if (!self->fps_counter)
		cbd_mlx_terminate(self, CBD_EGENERIC);
	self->frame_timer = 0;
}

void	game_read(t_game *self, t_fd fd)
{
	self->bonus = true;
	assets_read(&self->assets, fd);
	map_read(&self->map, fd);
}

void	game_run(t_game *self)
{
	screen_draw(&self->screen, self->mlx);
	game_pause(self);
	mlx_loop(self->mlx);
}

void	game_deinit(t_game *self)
{
	rc_deinit(&self->rc);
	hrc_deinit(self->hrc);
	if (self->mlx)
		mlx_close_window(self->mlx);
	screen_deinit(&self->screen, self->mlx);
	if (self->mlx)
		mlx_terminate(self->mlx);
	map_deinit(&self->map);
	assets_deinit(&self->assets);
}

static t_fd	_open(char const *path)
{
	char const *const	ext = ft_strnstr(path, FILE_EXT, -1);

	if (ext == NULL || ext[FILE_EXT_LEN] != '\0')
		cbd_terminate(CBD_EFILEEXT);
	return (open(path, O_RDONLY));
}
