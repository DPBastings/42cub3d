/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:08 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/27 14:35:09 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_game.h"
#include "cbd_hook.h"
#include "cbd_error.h"
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
	self->mlx = mlx_init(VIEW_WIDTH_DFL, VIEW_HEIGHT_DFL, TITLE, false);
	if (self->mlx == NULL)
		cbd_terminate(CBD_EGENERIC);
	hooks_init(self);
	screen_init(&self->screen, self->mlx);
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
