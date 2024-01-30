/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:53:37 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/30 11:53:37 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_parse.h"
#include "cbd_map.h"
#include "cbd_player.h"
#include "cbd_object.h"

static char const	g_object_tokens[N_OBJECT_TYPE] = {
	CHAR_VOID, CHAR_EMPTY, CHAR_WALL,
};

static char const	g_player_tokens[N_DIRECTION] = {
	CHAR_EAST, CHAR_NORTH, CHAR_WEST, CHAR_SOUTH,
};

int	parse_object(t_mchk *check, t_map *map, char const **rmap, t_point pt)
{
	t_object_type	type;

	(void) check;
	type = 0;
	while (type < N_OBJECT_TYPE)
	{
		if (rmap[pt.y][pt.x] == g_object_tokens[type])
		{
			object_init(&map->objects[pt.y][pt.x], type);
			return (0);
		}
		++type;
	}
	return (1);
}

int	parse_player(t_mchk *check, t_map *map, char const **rmap, t_point pt)
{
	t_direction	dir;

	dir = 0;
	while (dir < N_DIRECTION)
	{
		if (rmap[pt.y][pt.x] == g_player_tokens[dir])
		{
			if (check->has_player)
				cbd_terminate(CBD_EMAPDOUBLESTART);
			check->has_player = true;
			player_init(&map->player, pt, dir);
			object_init(&map->objects[pt.y][pt.x], OBJ_EMPTY);
			return (0);
		}
		++dir;
	}
	return (1);
}
