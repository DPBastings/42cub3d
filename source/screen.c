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

void	screen_init(t_screen *self, mlx_t *mlx)
{
	self->view = mlx_new_image(mlx, CBD_VIEW_WIDTH_DFL, CBD_VIEW_HEIGHT_DFL);
	if (self->view == NULL)
		cbd_terminate(CBD_EGENERIC);
}

void	screen_deinit(t_screen *self, mlx_t *mlx)
{
	mlx_delete_image(mlx, self->view);
}

void	screen_draw(t_screen *self, mlx_t *mlx)
{
	mlx_image_to_window(mlx, self->view, 0, 0);
}
