/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_update_viewport.c                          :+:    :+:            */
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

void	minimap_update_viewport(t_minimap *self, t_map const *map)
{
	self->viewport = (t_dpoint){
		map->player.pos.x - CBD_MINIMAP_W_M / 2,
		map->player.pos.y - CBD_MINIMAP_H_M / 2};
	/*if (self->viewport.x < 0)
		self->viewport.x = 0;
	else if (self->viewport.x > self->viewport_max.x)
		self->viewport.x = self->viewport_max.x;\
	if (self->viewport.y < 0)
		self->viewport.y = 0;
	else if (self->viewport.y > self->viewport_max.y)
		self->viewport.y = self->viewport_max.y;*/
}
