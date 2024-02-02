/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_update.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 15:15:10 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/02 17:12:45 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_minimap.h"
#include "cbd_game.h"
#include "cbd_player.h"
#include "cbd_map.h"
#include "cbd_object.h"
#include "ft_string.h"

static void	update_player(t_minimap *self, t_player const *player);
static void	update_objects(t_minimap *self, t_map const *map);
static void	draw_item(t_minimap *self, t_dpoint pt, uint32_t colour, int size);

void	minimap_update(t_minimap *self, t_map const *map)
{
	ft_memset(self->img->pixels, 0xFF, self->img->width * self->img->height);
	update_objects(self, map);
	update_player(self, &map->player);
}

static void	update_objects(t_minimap *self, t_map const *map)
{
	t_point	pt;

	pt.y = 0;
	while (pt.y < map->y_size)
	{
		pt.x = 0;
		while (pt.x < map->x_size)
		{
			if (map->objects[pt.y][pt.x].type == OBJ_WALL)
				draw_item(self, dpoint_from_point(pt), 0x000000FF, CBD_MINIMAP_GRIDSIZE);
			++pt.x;
		}
		++pt.y;
	}
}

static void	update_player(t_minimap *self, t_player const *player)
{
	draw_item(self, player->pos, 0x008888FF, CBD_MINIMAP_PLAYERSIZE);
	draw_item(self,
		(t_dpoint){
		player->pos.x + 2 * player->delta.x,
		player->pos.y + 2 * player->delta.y},
		0x00BBBBFF, CBD_MINIMAP_ARROWSIZE);
}

static void	draw_item(t_minimap *self, t_dpoint pt, uint32_t colour, int size)
{
	t_point	cursor;

	cursor.x = 0;
	while (cursor.x < size)
	{
		cursor.y = 0;
		while (cursor.y < size)
		{
			mlx_put_pixel(self->img,
				(pt.x * CBD_MINIMAP_GRIDSIZE) + cursor.x,
				(pt.y * CBD_MINIMAP_GRIDSIZE) + cursor.y,
				colour);
			++cursor.y;
		}
		++cursor.x;
	}
}