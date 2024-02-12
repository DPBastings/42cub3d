/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_render_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:08:10 by dbasting          #+#    #+#             */
/*   Updated: 2024/02/06 18:08:11 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_screen.h"
#include "cbd_rc.h"
#include "point.h"

#include "MLX42_ext.h"

#define CBD_BASE_HEIGHT	400

static inline int	_get_height(double ray_length);

void	view_render_scene(t_view *self, struct s_screen_data data)
{
	size_t	i;
	int		height;
	int		y[2];

	mlx_image_fill(self->scene, 0x00000000);
	i = 0;
	while (i < CBD_RC_RES)
	{
		height = _get_height(data.rc->data[i].length);
		y[0] = self->horizon - height / 2;
		y[1] = self->horizon + height / 2;
		mlx_put_line(self->scene, (t_point){i, y[0]}, (t_point){i, y[1]},
			0x300822FF);
		++i;
	}
}

static inline int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static inline int	_get_height(double ray_length)
{
	if (ray_length == 0)
		return (CBD_VIEW_HEIGHT_DFL);
	else
		return (ft_min(CBD_VIEW_HEIGHT_DFL, CBD_BASE_HEIGHT / ray_length));
}
