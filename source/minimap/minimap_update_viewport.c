/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap_update_viewport.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 15:15:10 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/16 14:36:39 by dbasting      ########   odam.nl         */
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
}
