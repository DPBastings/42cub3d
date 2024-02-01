/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbd_minimap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:45:11 by dbasting          #+#    #+#             */
/*   Updated: 2024/02/01 23:45:12 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_MINIMAP_H
# define CBD_MINIMAP_H

# include "cbd.h"

# include "MLX42.h"

# define CBD_MINIMAP_HEIGHT		96
# define CBD_MINIMAP_WIDTH		256
# define CBD_MINIMAP_GRIDSIZE	16

typedef struct s_minimap	t_minimap;

struct s_minimap
{
	mlx_image_t	*img;
};

void	minimap_init(t_minimap *self, mlx_t *mlx);
void	minimap_draw(t_minimap *self, t_map *map, mlx_t *mlx);
void	minimap_update(t_minimap *self, t_map *map, mlx_t *mlx);
void	minimap_deinit(t_minimap *self, mlx_t *mlx);

#endif // CBD_MINIMAP_H
