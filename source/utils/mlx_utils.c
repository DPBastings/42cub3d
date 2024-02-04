/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:02:07 by dbasting          #+#    #+#             */
/*   Updated: 2024/02/02 23:02:08 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	mlx_image_fill(mlx_image_t *img, uint32_t cl)
{
	uint32_t	x;
	uint32_t	y;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			mlx_put_pixel(img, x, y, cl);
			++y;
		}
		++x;
	}
}

void	mlx_put_pixel_safe(mlx_image_t* img, int32_t x, int32_t y, uint32_t cl)
{
	if (x > 0 && y > 0 && (uint32_t)x < img->width && (uint32_t)y < img->height)
		mlx_put_pixel(img, x, y, cl);
}
