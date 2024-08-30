/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:35:14 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/29 16:39:35 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_map.h"
#include "cbd_error.h"
#include "cbd_object.h"
#include "cbd_parse.h"
#include <stdlib.h>

void	map_read(t_map *self, t_fd fd)
{
	t_map_raw	rmap;
	t_mchk		check;

	self->void_ = (t_object){OBJ_VOID, NULL};
	map_raw_read(&rmap, fd);
	mchk_init(&check);
	parse_map(&check, self, &rmap);
	map_check(self);
	if (!mchk_done(&check))
		cbd_terminate(CBD_EMAPMISSINGSTART);
	map_raw_deinit(&rmap);
}

void	map_deinit(t_map *self)
{
	t_point	pt;

	if (!self || !self->objects)
		return ;
	pt.y = 0;
	while (pt.y < self->y_size)
	{
		pt.x = 0;
		while (pt.x < self->x_size)
		{
			if (&self->objects[pt.y][pt.x])
				object_deinit(&self->objects[pt.y][pt.x]);
			pt.x++;
		}
		if (self->objects[pt.y])
		{
			free(self->objects[pt.y]);
			self->objects[pt.y] = NULL;
		}
		pt.y++;
	}
	free(self->objects);
	self->objects = NULL;
}
