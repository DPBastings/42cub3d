/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_render_objects.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 15:15:10 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 16:28:54 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_minimap.h"
#include "cbd_player.h"
#include "cbd_map.h"
#include "cbd_object.h"
#include "MLX42_ext.h"

static void	render_walls(t_minimap *self, t_map const *map);

void	minimap_render_objects(t_minimap *self, t_map const *map)
{
	render_walls(self, map);
}

static void	render_walls(t_minimap *self, t_map const *map)
{
	t_point			cursor;
	t_object const	*obj;	

	cursor.y = 0;
	while (cursor.y < CBD_MINIMAP_H_PX)
	{
		cursor.x = 0;
		while (cursor.x < CBD_MINIMAP_W_PX)
		{
			obj = map_caccessd(map, minimap_px_to_pos(self, cursor));
			if (obj->type == OBJ_WALL)
				mlx_put_pixel(self->img, cursor.x, cursor.y,
					CBD_MINIMAP_CLR_WALL);
			else if (obj->type == OBJ_EMPTY)
				mlx_put_pixel(self->img, cursor.x, cursor.y,
					CBD_MINIMAP_CLR_EMPTY);
			++cursor.x;
		}
		++cursor.y;
	}
}
