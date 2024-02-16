/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:35:08 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/16 14:22:50 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_game.h"
#include "cbd_error.h"
#include "cbd_hook.h"
#include "cbd_rc.h"
#include "cbd_screen.h"
#include "types.h"

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
	self->mlx = mlx_init(1800, 1200, TITLE, false);
	if (self->mlx == NULL)
		cbd_terminate(CBD_EGENERIC);
	hooks_init(self);
	screen_init(&self->screen, (struct s_screen_data){
		&self->assets, &self->rc, &self->map}, self->mlx);
	rc_init(&self->rc, self->map.player.delta_o);
}

void	game_read(t_game *self, t_fd fd)
{
	assets_read(&self->assets, fd);
	map_read(&self->map, fd);
}

void	game_run(t_game *self)
{
	screen_draw(&self->screen, self->mlx);
	mlx_loop(self->mlx);
}

void	game_deinit(t_game *self)
{
	rc_deinit(&self->rc);
	mlx_close_window(self->mlx);
	screen_deinit(&self->screen, self->mlx);
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
