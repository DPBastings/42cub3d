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
#include "sprite.h"
#include "fl_cei.h"

void	screen_init(t_screen *self, struct s_screen_data data, mlx_t *mlx)
{
	view_init(&self->view, data.assets, mlx);
	minimap_init(&self->minimap, data.map, mlx);
	screen_overlay_init(&self->overlay, data.assets, mlx);
}

void	screen_deinit(t_screen *self, mlx_t *mlx)
{
	screen_overlay_deinit(&self->overlay, mlx);
	minimap_deinit(&self->minimap, mlx);
	view_deinit(&self->view, mlx);
}

void	screen_draw(t_screen *self, mlx_t *mlx)
{
	view_draw(&self->view, (t_point){0, 0}, mlx);
	minimap_draw(&self->minimap,
		(t_point){CBD_MINIMAP_HOFFSET, CBD_MINIMAP_VOFFSET}, mlx);
	screen_overlay_draw(&self->overlay, mlx);
}

void	screen_render(t_game *self, struct s_screen_data data)
{
	t_screen *screen;

	screen = &self->screen;
	view_render(self ,&screen->view, data);
	minimap_render(&screen->minimap, data.map, data.rc);
}
