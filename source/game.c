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
#include "cbd_error.h"
#include "types.h"

#include "ft_string.h"
#include <fcntl.h>
#include <unistd.h>

static t_fd	_open(char const *path);

void	game_init(t_game *game, char const *path)
{
	t_fd const	fd = _open(path);

	if (fd == -1)
		cbd_terminate(CBD_EGENERIC);
	game_read(game, fd);
	close(fd);
}

void	game_read(t_game *game, t_fd fd)
{
	assets_read(&game->assets, fd);
	map_read(&game->map, fd);
}

void	game_deinit(t_game *game)
{
	assets_deinit(&game->assets);
	map_deinit(&game->map);
}

static t_fd	_open(char const *path)
{
	char const *const	ext = ft_strnstr(path, FILE_EXT, -1);

	if (ext == NULL || ext[FILE_EXT_LEN] != '\0')
		cbd_terminate(CBD_EFILEEXT);
	return (open(path, O_RDONLY));
}
