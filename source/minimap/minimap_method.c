/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_method.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 15:15:10 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 16:31:05 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_minimap.h"
#include "cbd_rc.h"
#include "MLX42_ext.h"

void	minimap_render_fov(t_minimap *self, t_rc const *rc);

void	minimap_render(t_minimap *self, t_map const *map, t_rc const *rc)
{
	mlx_image_fill(self->img, CBD_MINIMAP_CLR_BG);
	minimap_update_viewport(self, map);
	minimap_render_objects(self, map);
	minimap_render_entities(self, map);
	minimap_render_fov(self, rc);
}

void	minimap_render_fov(t_minimap *self, t_rc const *rc)
{
	size_t	i;
	t_point	px;

	i = 0;
	while (i < CBD_RC_RES)
	{
		px = minimap_pos_to_px(self, rc->data[i].end);
		mlx_put_pixel_safe(self->img, px.x, px.y, 0x00AA00FF);
		++i;
	}
}
