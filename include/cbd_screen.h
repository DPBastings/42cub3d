/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbd_screen.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:38:40 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/30 15:38:45 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_SCREEN_H
# define CBD_SCREEN_H

# include "MLX42.h"

/**
 * @brief	Screen object.
 * 			Contains the graphical representation of the game interface.
 * @param view	Image depicting the world view.
 */
struct s_screen
{
	mlx_image_t	*view;
};

void	screen_init(t_screen *self, mlx_t *mlx);
void	screen_draw(t_screen *self, mlx_t *mlx);
void	screen_deinit(t_screen *self, mlx_t *mlx);

#endif // CBD_SCREEN_H
