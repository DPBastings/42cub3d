/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_screen.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 15:38:40 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 17:13:46 by dbasting      ########   odam.nl         */
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
	uint32_t	horizon;
	t_minimap	minimap;
};

struct s_renderer_data
{
	t_assets const *const	assets;
	t_rc const *const		rc;
	t_map const *const		map;
};

void	screen_init(t_screen *self, t_map const *map, mlx_t *mlx);
void	screen_draw(t_screen *self, mlx_t *mlx);
void	screen_render(t_screen *self, struct s_renderer_data const data);
void	screen_deinit(t_screen *self, mlx_t *mlx);

#endif // CBD_SCREEN_H
