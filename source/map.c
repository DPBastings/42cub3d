/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:35:14 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 18:08:09 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_map.h"
#include "cbd_error.h"
#include "cbd_parse.h"

#include "ft_stdio.h"
#include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>

#include "debug.h"

#define REALLOC_SIZE	16

static char	*find_map_start(t_fd);
static void	map_alloc(t_map *map, t_fd fd);
static void	map_realloc(t_map *map, int *capacity);

void	map_read(t_map *map, t_fd fd)
{
	map_alloc(map, fd);
	map_check(map);
	map_print(map);
}

void	map_deinit(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->y_size)
		free(map->contents[y++]);
	free(map->contents);
}

static void	map_alloc(t_map *map, t_fd fd)
{
	char	*ln;
	int		capacity;

	capacity = REALLOC_SIZE;
	map->contents = malloc(sizeof(char *) * capacity);
	if (map->contents == NULL)
		cbd_terminate(CBD_EGENERIC);
	map->y_size = 0;
	ln = find_map_start(fd);
	while (ln)
	{
		if (map->y_size >= capacity)
			map_realloc(map, &capacity);
		map->contents[map->y_size++] = ln;
		ln = ft_getline(fd);
	}
}

static void	map_realloc(t_map *map, int *capacity)
{
	char	**new_contents;

	new_contents = malloc(sizeof(char *) * (*capacity + REALLOC_SIZE));
	if (new_contents == NULL)
		cbd_terminate(CBD_EGENERIC);
	ft_memcpy(new_contents, map->contents, *capacity * sizeof(char *));
	free(map->contents);
	map->contents = new_contents;
	*capacity += REALLOC_SIZE;
}

static char	*find_map_start(t_fd fd)
{
	char		*ln;
	char const	*wd;

	ln = ft_getline(fd);
	while (ln)
	{
		wd = ln;
		parse_skip_ws(&wd);
		if (*wd)
			break ;
		free(ln);
		ln = ft_getline(fd);
	}
	return (ln);
}
