/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:36:11 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/27 14:36:12 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "MLX42.h"
# include "point.h"

void	mlx_image_fill(mlx_image_t *img, uint32_t colour);
void	mlx_put_line(mlx_image_t *img, t_point a, t_point b, uint32_t colour);
void	mlx_put_pixel_safe(mlx_image_t *img, int32_t x, int32_t y, uint32_t cl);

#endif // MLX_UTILS_H
