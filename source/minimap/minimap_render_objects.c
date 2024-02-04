/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_render_objects.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 15:15:10 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/02 17:12:45 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_minimap.h"
#include "cbd_player.h"
#include "cbd_map.h"
#include "cbd_object.h"
#include "mlx_utils.h"

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
			obj = map_caccessd(map, (t_dpoint){
				self->viewport.x + (double)cursor.x / CBD_MINIMAP_PXPM,
				self->viewport.y + (double)cursor.y / CBD_MINIMAP_PXPM});
			if (obj->type == OBJ_WALL)
				mlx_put_pixel(self->img, cursor.x, cursor.y, 0x000000FF);
			else if (obj->type == OBJ_VOID)
				mlx_put_pixel(self->img, cursor.x, cursor.y, 0x0A0A0AFF);
			++cursor.x;
		}
		++cursor.y;
	}
}
