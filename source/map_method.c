/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_method.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 16:41:46 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 17:59:24 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_map.h"
#include "cbd_object.h"

#include <stdbool.h>
#include <stddef.h>

static inline bool	is_oob(t_map const *self, t_point pt);

t_object	*map_access(t_map *self, t_point pt)
{
	if (is_oob(self, pt))
		return (NULL);
	return (&self->objects[pt.y][pt.x]);
}

t_object	map_caccess(t_map const *self, t_point pt)
{
	if (is_oob(self, pt))
		return ((t_object){OBJ_VOID, NULL});
	return (self->objects[pt.y][pt.x]);
}

static inline bool	is_oob(t_map const *self, t_point pt)
{
	return (pt.x < 0 || pt.x >= self->x_size
		|| pt.y < 0 || pt.y >= self->y_size);
}
