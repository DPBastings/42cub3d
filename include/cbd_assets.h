/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbd_assets.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:47 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/27 14:35:47 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_ASSETS_H
# define CBD_ASSETS_H

# include "cbd.h"

# include "MLX42.h"
# include "types.h"

typedef union u_texture	t_texture;

/**
 * @brief	Texture object.
 * 			Contains either a MLX library texture buffer or a (dynamically
 * 			allocated) string indicating the path to a PNG file from which that
 * 			texture is to be loaded.
 */
union u_texture
{
	mlx_texture_t	*data;
	char			*path;
};

void	texture_load(t_texture *txr);
void	texture_deinit(t_texture *txr);

typedef enum e_texture_id
{
	NORTH_WALL = 0,
	EAST_WALL,
	SOUTH_WALL,
	WEST_WALL,
	N_TEXTURE,
}	t_texture_id;

/**
 * @brief	Assets object.
 * 			Contains level-specific assets and asset-like data.
 * @param ceiling_rgba	Colour of the ceiling.
 * @param floor_rgba	Colour of the floor.
 * @param textures		Texture buffers.
 */
struct s_assets
{
	t_rgba		ceiling_rgba;
	t_rgba		floor_rgba;
	t_texture	textures[N_TEXTURE];
}; // struct s_assets

void	assets_read(t_assets *assets, t_fd fd);
void	assets_deinit(t_assets *assets);

#endif // CBD_ASSETS_H
