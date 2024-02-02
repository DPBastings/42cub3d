/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_minimap.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/01 23:45:11 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/02 17:28:21 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_MINIMAP_H
# define CBD_MINIMAP_H

# include "cbd.h"

# include "point.h"
# include "MLX42.h"

# define CBD_MINIMAP_HEIGHT		240
# define CBD_MINIMAP_WIDTH		360
# define CBD_MINIMAP_GRIDSIZE	12
# define CBD_MINIMAP_PLAYERSIZE	6
# define CBD_MINIMAP_ARROWSIZE	3

typedef struct s_minimap	t_minimap;

struct s_minimap
{
	mlx_image_t	*img;
	t_dpoint	view_offset;
};

void	minimap_init(t_minimap *self, mlx_t *mlx);
void	minimap_draw(t_minimap *self, t_point pos, mlx_t *mlx);
void	minimap_update(t_minimap *self, t_map const *map);
void 	minimap_update_view(t_minimap *self, t_map const *map);
void	minimap_deinit(t_minimap *self, mlx_t *mlx);

#endif // CBD_MINIMAP_H
