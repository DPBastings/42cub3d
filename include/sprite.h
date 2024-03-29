/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <tcensier@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/25 12:58:48 by tcensier      #+#    #+#                 */
/*   Updated: 2024/03/27 18:29:57 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "cbd_game.h"
# include "cbd_assets.h"
# include "MLX42_ext.h"
# include "libft.h"

typedef struct	s_sprite
{
	double		x;
	double		y;
	double		v_shrink;
	double		h_shrink;
	double		v_move;
	t_texture	*texture;
	mlx_image_t *img;	
} 				t_sprite;

typedef struct	s_sprite_data
{
	int			n_sprites;
	int			*sprite_order;
	double		*z_buffer;
	double		*sprite_dist;
	t_sprite	*sprites;
}				t_sprite_data;

void			sort_sprites(int *order, double *dist, int n);
void			init_sprites(t_game *self);
void			sprite_draw(t_game *self);
void			sprite_casting(t_game *self);
#endif