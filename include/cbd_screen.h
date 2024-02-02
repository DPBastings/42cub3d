/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_screen.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 15:38:40 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/02 16:13:04 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_SCREEN_H
# define CBD_SCREEN_H

# include "cbd.h"
# include "cbd_minimap.h"

# include "MLX42.h"

# define CBD_VIEW_WIDTH_DFL		1200
# define CBD_VIEW_HEIGHT_DFL	800

# define CBD_MINIMAP_HOFFSET	16
# define CBD_MINIMAP_VOFFSET	16

/**
 * @brief	Screen object.
 * @param view		Image showing the world view.
 * @param minimap	A minimap of the level.
 */
struct s_screen
{
	mlx_image_t	*view;
	t_minimap	minimap;
};

void	screen_init(t_screen *self, mlx_t *mlx);
void	screen_draw(t_screen *self, mlx_t *mlx);
void	screen_update(t_screen *self, mlx_t *mlx);
void	screen_deinit(t_screen *self, mlx_t *mlx);

#endif // CBD_SCREEN_H
