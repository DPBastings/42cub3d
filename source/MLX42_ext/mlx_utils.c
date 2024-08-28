/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 23:02:07 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/28 18:02:22 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42_ext.h"
#include "cbd.h"

void	mlx_image_fill(mlx_image_t *img, uint32_t cl)
{
	uint32_t	x;
	uint32_t	y;

	x = -1;
	while (++x < img->width)
	{
		y = -1;
		while (++y < img->height)
			mlx_put_pixel(img, x, y, cl);
	}
}

void	mlx_put_pixel_safe(mlx_image_t *img, int32_t x, int32_t y, uint32_t cl)
{
	if (x >= 0 && y >= 0
		&& (uint32_t)x < img->width
		&& (uint32_t)y < img->height)
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

static uint32_t	fog_px(void)
{
	uint8_t const	px[4] = {
		255, FOG_B,
		FOG_G, FOG_R};

	return (*((uint32_t *)px));
}

/**
*@brief Reads the texture and adds a fog percentage to it using ray
*distance and a look up table.
*@param fog fog amount between 0 and 1.0
*@param range (set to 16) The amount of subdivision to map to the fog amount: 
*gives fog * range + 2 -> mapping the table to [2, range + 1]
*/
uint32_t	mlx_texture_read_fog(mlx_texture_t const *txr,
								int32_t x, int32_t y, float fog)
{
	size_t const	i = (y * txr->width + x) * 4;
	int				cl_percent;
	uint8_t			px[4];

	if (fog >= 1.0)
		return (fog_px());
	cl_percent = (int)(fog * 16) + 2;
	px[0] = txr->pixels[i + 3];
	px[1] = (uint8_t)(txr->pixels[i + 2] / cl_percent + (FOG_B * fog));
	px[2] = (uint8_t)(txr->pixels[i + 1] / cl_percent + (FOG_G * fog));
	px[3] = (uint8_t)(txr->pixels[i] / cl_percent + (FOG_R * fog));
	return (*((uint32_t *)px));
}
