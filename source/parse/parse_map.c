/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:39:09 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/30 11:39:10 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_parse.h"
#include "cbd_map.h"
#include "cbd_object.h"

#include "ft_string.h"
#include <stdbool.h>
#include <stdlib.h>

static void	add_trailing_voids(t_map *map, t_point pt);
static int	get_x_size(t_map_raw const *rmap);
static void	map_alloc(t_map *self);
static void	parse_objects(t_mchk *check, t_map *map, char const **rmap);

void	parse_map(t_mchk *check, t_map *map, t_map_raw const *rmap)
{
	map->y_size = rmap->y_size;
	map->x_size = get_x_size(rmap);
	map_alloc(map);
	parse_objects(check, map, (char const **)rmap->contents);
}

static void	add_trailing_voids(t_map *map, t_point from)
{
	while (from.x < map->x_size)
		map->objects[from.y][from.x++] = (t_object){OBJ_VOID, NULL};
}

static int	get_x_size(t_map_raw const *rmap)
{
	int	result;
	int	ln_size;
	int	y;

	result = 0;
	y = 0;
	while (y < rmap->y_size)
	{
		ln_size = ft_strlen(rmap->contents[y]);
		if (rmap->contents[y][ln_size - 1] == '\n')
			--ln_size;
		if (ln_size > result)
			result = ln_size;
		++y;
	}
	return (result);
}

static void	map_alloc(t_map *self)
{
	int	y;

	self->objects = malloc(self->y_size * sizeof(t_object *));
	if (self->objects == NULL)
		cbd_terminate(CBD_EGENERIC);
	y = 0;
	while (y < self->y_size)
	{
		self->objects[y] = malloc(self->x_size * sizeof(t_object));
		if (self->objects[y] == NULL)
			cbd_terminate(CBD_EGENERIC);
		++y;
	}
}

static void	parse_objects(t_mchk *check, t_map *map, char const **rmap)
{
	t_point	pt;

	pt.y = 0;
	while (pt.y < map->y_size)
	{
		pt.x = 0;
		while (rmap[pt.y][pt.x] && rmap[pt.y][pt.x] != '\n')
		{
			if (parse_player(check, map, rmap, pt) == 1)
				if (parse_object(check, map, rmap, pt) == 1)
					cbd_terminate(CBD_EMAPINVOBJ);
			++pt.x;
		}
		add_trailing_voids(map, pt);
		++pt.y;
	}
}
