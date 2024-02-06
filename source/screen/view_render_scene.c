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

#define CBD_BASE_HEIGHT	200

void	view_render_scene(t_view *self, struct s_screen_data data)
{
	size_t			i;
	int				height;
	int				y[2];

	i = 0;
	while (i < CBD_RC_N_RAY_DFL)
	{
		height = CBD_BASE_HEIGHT / (int)data.rc->data[i].distanced;
		y[0] = self->horizon - (height / 2 + data.rc->data[i].distanced / 2);
		y[1] = self->horizon + (height / 2 + data.rc->data[i].distanced / 2);
		mlx_put_line(self->scene, (t_point){i, y[0]}, (t_point){i, y[1]},
			0x300822FF);
		++i;
	}
}
