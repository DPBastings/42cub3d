/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:45:17 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 18:09:20 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_map.h"
#include "cbd_player.h"
#include "cbd_object.h"
#include "cbd_parse.h"
#include "point.h"

#include <stdbool.h>

static int	find_x_size(t_map const *self);
static void	check_objects(t_map *self, bool *has_player);
static void	check_player(t_map *self, t_point pt, bool *has_player);
static void	check_enclosure(t_map const *self, t_point pt);

void	map_check(t_map *self)
{
	bool	has_player;

	has_player = false;
	self->x_size = find_x_size(self);
	check_objects(self, &has_player);
	if (!has_player)
		cbd_terminate(CBD_EMAPMISSINGSTART);
}

// Do not use map_access() or map_caccess() before this routine has executed!
static int	find_x_size(t_map const *self)
{
	int		result;
	t_point	pt;

	pt.y = 0;
	result = 0;
	while (pt.y < self->y_size)
	{
		pt.x = 0;
		while (self->contents[pt.y][pt.x])
			++pt.x;
		if (pt.x > result)
			result = pt.x;
		++pt.y;
	}
	return (result);
}

static void	check_objects(t_map *self, bool *has_player)
{
	t_point	pt;

	pt.y = 0;
	while (pt.y < self->y_size)
	{
		pt.x = 0;
		while (pt.x < self->x_size)
		{
			check_player(self, pt, has_player);
			check_enclosure(self, pt);
			++pt.x;
		}
		++pt.y;
	}
}

static void	check_player(t_map *self, t_point pt, bool *has_player)
{
	size_t				i;
	t_startpos const	options[4] = {
		CHAR_NORTH, CHAR_EAST, CHAR_SOUTH, CHAR_WEST
	};

	i = 0;
	while (i < 4)
	{
		if (map_caccess(self, pt) == options[i])
		{
			if (*has_player)
				cbd_terminate(CBD_EMAPDOUBLESTART);
			player_init(&self->player, pt, options[i]);
			*map_access(self, pt) = OBJ_EMPTY;
			*has_player = true;
			return ;
		}
		++i;
	}
}

static void	check_enclosure(t_map const *self, t_point pt)
{
	if (map_caccess(self, pt) == OBJ_EMPTY)
	{
		if (map_caccess(self, (t_point){pt.x - 1, pt.y}) == OBJ_VOID
			|| map_caccess(self, (t_point){pt.x + 1, pt.y}) == OBJ_VOID
			|| map_caccess(self, (t_point){pt.x, pt.y - 1}) == OBJ_VOID
			|| map_caccess(self, (t_point){pt.x, pt.y + 1}) == OBJ_VOID)
			cbd_terminate(CBD_EMAPWALL);
	}
}
