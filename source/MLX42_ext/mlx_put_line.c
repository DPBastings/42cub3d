/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:42:46 by dbasting          #+#    #+#             */
/*   Updated: 2024/02/06 09:42:47 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42_ext.h"

static inline t_vector	_get_delta(t_point a, t_point b);
static inline t_vector	_get_slope(t_point a, t_point b);

#include <stdio.h>

void	mlx_put_line(mlx_image_t *img, t_point a, t_point b, uint32_t colour)
{
	t_vector const	delta = _get_delta(a, b);
	t_vector const	slope = _get_slope(a, b);
	int				error;

	error = delta.x + delta.y;
	while (a.x != b.x || a.y != b.y)
	{
		mlx_put_pixel_safe(img, a.x, a.y, colour);
		if (error * 2 >= delta.y)
		{
			if (a.x == b.x)
				break ;
			error += delta.y;
			a.x += slope.x;
		}
		if (error * 2 <= delta.x)
		{
			if (a.y == b.y)
				break ;
			error += delta.x;
			a.y += slope.y;
		}
	}
	mlx_put_pixel_safe(img, a.x, a.y, colour);
}

static inline int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static inline t_vector	_get_delta(t_point a, t_point b)
{
	return ((t_vector){ft_abs(b.x - a.x), -ft_abs(b.y - a.y)});
}

static inline t_vector	_get_slope(t_point a, t_point b)
{
	t_vector	slope;

	if (a.x < b.x)
		slope.x = 1;
	else
		slope.x = -1;
	if (a.y < b.y)
		slope.y = 1;
	else
		slope.y = -1;
	return (slope);
}
