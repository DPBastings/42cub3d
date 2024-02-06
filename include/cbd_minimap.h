/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_minimap.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 23:45:11 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 17:29:57 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_MINIMAP_H
# define CBD_MINIMAP_H

# include "cbd.h"

# include "point.h"
# include "MLX42.h"

# define CBD_MINIMAP_PXPM		12
# define CBD_MINIMAP_W_PX		360
# define CBD_MINIMAP_H_PX		240
# define CBD_MINIMAP_CTR_X		180 // 360 / 2
# define CBD_MINIMAP_CTR_Y		120 // 240 / 2
# define CBD_MINIMAP_W_M		30 // 360 / 12
# define CBD_MINIMAP_H_M		20 // 240 / 12
# define CBD_MINIMAP_PLAYER_PX	9
# define CBD_MINIMAP_ARROW_PX	3

# define CBD_MINIMAP_CLR_EMPTY	0xEEEEEEDD
# define CBD_MINIMAP_CLR_WALL	0x000000DD
# define CBD_MINIMAP_CLR_BG		0x0F0F0FDD

typedef struct s_minimap	t_minimap;

/**
 * @brief	Minimap object.
 * @param img		Image representation.
 * @param viewport	Origin coordinate of the current viewport.
 */
struct s_minimap
{
	mlx_image_t	*img;
	t_dpoint	viewport;
	t_dpoint	viewport_max;
};

void	minimap_init(t_minimap *self, t_map const *map, mlx_t *mlx);
void	minimap_draw(t_minimap *self, t_point pos, mlx_t *mlx);
void	minimap_render(t_minimap *self, t_map const *map, t_rc const *rc);
void	minimap_render_objects(t_minimap *self, t_map const *map);
void	minimap_render_entities(t_minimap *self, t_map const *map);
void	minimap_update_viewport(t_minimap *self, t_map const *map);
void	minimap_deinit(t_minimap *self, mlx_t *mlx);

static inline t_point	minimap_pos_to_px(t_minimap const *self, t_dpoint pos)
{
	return ((t_point){
		pos.x * CBD_MINIMAP_PXPM - self->viewport.x,
		pos.y * CBD_MINIMAP_PXPM - self->viewport.y
	});
}

static inline t_dpoint	minimap_px_to_pos(t_minimap const *self, t_point px)
{
	return ((t_dpoint){
		(double)px.x / CBD_MINIMAP_PXPM + self->viewport.x,
		(double)px.y / CBD_MINIMAP_PXPM + self->viewport.y
	});
}

#endif // CBD_MINIMAP_H
