/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:01:21 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/30 16:01:22 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd.h"
#include "cbd_error.h"
#include "cbd_screen.h"

void	screen_init(t_screen *self, struct s_screen_data data, mlx_t *mlx)
{
	view_init(&self->view, data.assets, mlx);
	minimap_init(&self->minimap, data.map, mlx);
}

void	screen_deinit(t_screen *self, mlx_t *mlx)
{
	minimap_deinit(&self->minimap, mlx);
	view_deinit(&self->view, mlx);
}

void	screen_draw(t_screen *self, mlx_t *mlx)
{
	view_draw(&self->view, (t_point){0, 0}, mlx);
	minimap_draw(&self->minimap,
		(t_point){CBD_MINIMAP_HOFFSET, CBD_MINIMAP_VOFFSET}, mlx);
}

void	screen_render(t_screen *self, struct s_screen_data data)
{
	view_render(&self->view, data);
	minimap_render(&self->minimap, data.map, data.rc);
}
