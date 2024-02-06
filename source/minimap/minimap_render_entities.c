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
#include "MLX42_ext.h"

static void	render_player(t_minimap *self, t_player const *player);
static void	render(t_minimap *self, t_point pt, uint32_t cl, uint32_t size);

void	minimap_render_entities(t_minimap *self, t_map const *map)
{
	render_player(self, &map->player);
}

static void	render_player(t_minimap *self, t_player const *player)
{
	render(self, (t_point){CBD_MINIMAP_CTR_X, CBD_MINIMAP_CTR_Y},
		0x007799FF, CBD_MINIMAP_PLAYER_PX);
	render(self, (t_point){
		CBD_MINIMAP_CTR_X + 60 * player->delta_m.x,
		CBD_MINIMAP_CTR_Y + 60 * player->delta_m.y},
		0x00BBBBFF, CBD_MINIMAP_ARROW_PX);
}

static void	render(t_minimap *self, t_point pt, uint32_t cl, uint32_t size)
{
	int const	half = size / 2;
	t_point		cursor;

	cursor.x = -half;
	while (cursor.x < half)
	{
		cursor.y = -half;
		while (cursor.y < half)
		{
			mlx_put_pixel_safe(self->img, pt.x + cursor.x, pt.y + cursor.y, cl);
			++cursor.y;
		}
		++cursor.x;
	}
}
