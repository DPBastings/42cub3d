/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_screen.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 15:38:40 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/16 14:24:49 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_SCREEN_H
# define CBD_SCREEN_H

# include "cbd.h"
# include "cbd_minimap.h"

# include "MLX42.h"

# define CBD_VIEW_WIDTH_DFL		1920 // == SCREEN_WIDTH_DFL
# define CBD_VIEW_HEIGHT_DFL	1200 // == SCREEN_HEIGHT_DFL

# define CBD_MINIMAP_HOFFSET	16
# define CBD_MINIMAP_VOFFSET	16

struct s_screen_data
{
	t_assets const *const	assets;
	t_rc const *const		rc;
	t_map const *const		map;
};

struct s_view
{
	mlx_image_t	*scene;
	mlx_image_t	*ceiling;
	mlx_image_t	*floor;
	uint32_t	horizon;
};

void	view_init(t_view *self, t_assets const *assets, mlx_t *mlx);
void	view_draw(t_view *self, t_point pt, mlx_t *mlx);
void	view_render(t_view *self, struct s_screen_data data);
void	view_render_scene(t_view *self, struct s_screen_data data);
void	view_deinit(t_view *self, mlx_t *mlx);

/**
 * @brief	Screen object.
 * @param view		Image showing the world view.
 * @param minimap	A minimap of the level.
 */
struct s_screen
{
	t_view		view;
	t_minimap	minimap;
};

void	screen_init(t_screen *self, struct s_screen_data data, mlx_t *mlx);
void	screen_draw(t_screen *self, mlx_t *mlx);
void	screen_render(t_screen *self, struct s_screen_data data);
void	screen_deinit(t_screen *self, mlx_t *mlx);

#endif // CBD_SCREEN_H
