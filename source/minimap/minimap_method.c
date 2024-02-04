/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_method.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 15:15:10 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/02 17:12:45 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_minimap.h"

#include "mlx_utils.h"

void	minimap_render(t_minimap *self, t_map const *map)
{
	mlx_image_fill(self->img, 0xEEEEFF88);
	minimap_update_viewport(self, map);
	minimap_render_objects(self, map);
	minimap_render_entities(self, map);
}
