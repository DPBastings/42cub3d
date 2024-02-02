/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 15:04:28 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/02 16:22:25 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_minimap.h"
#include "cbd_error.h"

void	minimap_init(t_minimap *self, mlx_t *mlx)
{
	self->img = mlx_new_image(mlx, CBD_MINIMAP_WIDTH, CBD_MINIMAP_HEIGHT);
	if (self->img == NULL)
		cbd_terminate(CBD_EGENERIC);
}

void	minimap_draw(t_minimap *self, t_point pos, mlx_t *mlx)
{
	mlx_image_to_window(mlx, self->img, pos.x, pos.y);
}

void	minimap_deinit(t_minimap *self, mlx_t *mlx)
{
	mlx_delete_image(mlx, self->img);
}