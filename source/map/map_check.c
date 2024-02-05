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

static void	check_objects(t_map *self);
static void	check_enclosure(t_map *self, t_point pt);

void	map_check(t_map *self)
{
	check_objects(self);
}

static void	check_objects(t_map *self)
{
	t_point	pt;

	pt.y = 0;
	while (pt.y < self->y_size)
	{
		pt.x = 0;
		while (pt.x < self->x_size)
		{
			check_enclosure(self, pt);
			++pt.x;
		}
		++pt.y;
	}
}

static void	check_enclosure(t_map *self, t_point pt)
{
	if (map_access(self, pt)->type == OBJ_EMPTY)
	{
		if (map_access(self, (t_point){pt.x - 1, pt.y})->type == OBJ_VOID
			|| map_access(self, (t_point){pt.x + 1, pt.y})->type == OBJ_VOID
			|| map_access(self, (t_point){pt.x, pt.y - 1})->type == OBJ_VOID
			|| map_access(self, (t_point){pt.x, pt.y + 1})->type == OBJ_VOID)
			cbd_terminate(CBD_EMAPWALL);
	}
}
