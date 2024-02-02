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

void	mlx_image_fill(mlx_image_t *img, uint32_t colour)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			mlx_put_pixel(img, x, y, colour);
			++y;
		}
		++x;
	}
}
