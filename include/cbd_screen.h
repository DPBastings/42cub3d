/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_screen.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 15:38:40 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/21 18:52:11 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_SCREEN_H
# define CBD_SCREEN_H

# include "cbd.h"
# include "cbd_minimap.h"

# include "MLX42.h"

# define CBD_WALL_H_DFL			CBD_SCREEN_H_DFL
# define CBD_VIEW_ZOOM_FACTOR	1.05

# define CBD_MINIMAP_HOFFSET	16
# define CBD_MINIMAP_VOFFSET	16

# define CBD_SCREEN_OVERLAY_PAUSE_CLR	0x161616A0

typedef struct s_screen_overlay	t_screen_overlay;

/**
 * @brief	Bundles several resources used in rendering the screen.
*/
typedef struct s_screen_data
{
	t_assets const *const	assets;
	t_rc const *const		rc;
	t_map const *const		map;
}				t_screen_data;

/**
 * @brief	Scene view object.
 * @param scene			Image showing walls.
 * @param ceiling		Image showing the ceiling backdrop.
 * @param floor			Image showing the floor backdrop.
 * @param horizon		Y coordinate of the horizon.
 * @param wall_height	Base height of a wall.
 */
struct s_view
{
	mlx_image_t	*scene;
	mlx_image_t	*ceiling;
	mlx_image_t	*floor;
	uint32_t	*px_buffer;
	uint32_t	horizon;
	uint32_t	fog_constant;
	double		max_distance;
	double		wall_height;
};

void	view_init(t_view *self, t_assets const *assets, mlx_t *mlx);
void	view_draw(t_view *self, t_point pt, mlx_t *mlx);
void	view_render(t_game *game, t_view *self, struct s_screen_data data);
void	view_render_scene(t_game *game, t_view *self, struct s_screen_data data);
void	view_deinit(t_view *self, mlx_t *mlx);
void 	fps_counter_render(t_game *game);

typedef enum e_screen_overlay_icon
{
	SCREEN_OVERLAY_ICON_PAUSE = 0,
	SCREEN_OVERLAY_ICON_CROSSHAIR,
	N_SCREEN_OVERLAY_ICON,
}	t_screen_overlay_icon;

/**
 * @brief	Screen overlay object.
 * @param bg	Image displaying the overlay's background.
 * @param icons	Images displaying overlain icons.
*/
struct s_screen_overlay
{
	mlx_image_t	*bg;
	mlx_image_t	*icons[N_SCREEN_OVERLAY_ICON];
};

void	screen_overlay_init(t_screen_overlay *self, t_assets const *assets,
			mlx_t *mlx);
void	screen_overlay_deinit(t_screen_overlay *self, mlx_t *mlx);
void	screen_overlay_draw(t_screen_overlay *self, mlx_t *mlx);
void	screen_overlay_pause(t_screen_overlay *self);
void	screen_overlay_unpause(t_screen_overlay *self);

/**
 * @brief	Screen object.
 * @param view		Image showing the world view.
 * @param minimap	A minimap of the level.
 * @param overlay	Screen overlay.
 */
struct s_screen
{
	t_view				view;
	t_minimap			minimap;
	t_screen_overlay	overlay;
};

void	screen_init(t_screen *screen, struct s_screen_data data, mlx_t *mlx);
void	screen_draw(t_screen *self, mlx_t *mlx);
void	screen_render(t_game *self, struct s_screen_data data);
void	screen_deinit(t_screen *self, mlx_t *mlx);

#endif // CBD_SCREEN_H
