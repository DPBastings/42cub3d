/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 16:43:20 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 18:18:04 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_map.h"
#include "cbd_player.h"
#include "cbd_screen.h"

static void	render_background(t_view *self);
static void	render_scene(mlx_image_t *scene, struct s_screen_data data);

void	view_render(t_view *self, struct s_screen_data data)
{
	self->horizon = self->scene->height / 2 + data.map->player.view_z * 48;
	render_background(self);
	render_scene(self->scene, data);
}

static void	render_background(t_view *self)
{
	self->ceiling->instances[0].y = self->horizon - CBD_VIEW_HEIGHT_DFL;
	self->scene->instances[0].y = self->horizon - CBD_VIEW_HEIGHT_DFL;
	self->floor->instances[0].y = self->horizon;
}

static void	render_scene(mlx_image_t *scene, struct s_screen_data data)
{
	(void) scene;
	(void) data;
}
