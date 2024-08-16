/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 23:02:07 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/16 15:20:18 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42_ext.h"

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

void	mlx_put_pixel_safe(mlx_image_t *img, int32_t x, int32_t y, uint32_t cl)
{
	if (x > 0 && y > 0 && (uint32_t)x < img->width && (uint32_t)y < img->height)
		mlx_put_pixel(img, x, y, cl);
}

uint32_t	mlx_texture_read(mlx_texture_t const *txr, int32_t x, int32_t y)
{
	size_t const	i = (y * txr->width + x) * 4;
	uint8_t const	px[4] = {
		txr->pixels[i + 3], txr->pixels[i + 2],
		txr->pixels[i + 1], txr->pixels[i]
		};

	return (*((uint32_t *)px));
}

uint32_t	mlx_texture_read_fog(mlx_texture_t const *txr, int32_t x, int32_t y, float fog)
{
	size_t const	i = (y * txr->width + x) * 4;
	double cl_percent;

	if (fog <= 0)
		cl_percent = 1.0;
	else
		cl_percent = 1 - fog;
	uint8_t const	px[4] = {
		txr->pixels[i + 3], txr->pixels[i + 2] * cl_percent + (FOG_CL * fog),
		txr->pixels[i + 1] * cl_percent + (FOG_CL * fog), txr->pixels[i] * cl_percent + (FOG_CL * fog)
		};

	return (*((uint32_t *)px));
}