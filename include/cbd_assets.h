#ifndef CBD_ASSETS_H
# define CBD_ASSETS_H

# include "cbd.h"

# include "MLX42.h"
# include "types.h"

# include <stdint.h>

/**
 * @brief	Texture object.
 * 			Contains either a MLX library texture or a (dynamically allocated)
 * 			string indicating the path to a PNG file from which that texture is
 * 			to be loaded.
 */ 
typedef union u_texture {
	mlx_texture_t	*data;
	char			*path;
}	t_texture;

void	texture_load(t_texture *txr);
void	texture_destroy(t_texture *txr);

/**
 * @brief	Assets object.
 * 			Contains level-specific assets and asset-like data.
 * @param ceiling_rgba	Colour of the ceiling.
 * @param floor_rgba	Colour of the floor.
 * @param north_txr		Texture for north-facing walls.
 * @param east_txr		Texture for east-facing walls.
 * @param south_txr		Texture for south-facing walls.
 * @param west_txr		Texture for west-facing walls.
 */
struct s_assets
{
	t_rgba		ceiling_rgba;
	t_rgba		floor_rgba;
	t_texture	north_txr;
	t_texture	east_txr;
	t_texture	south_txr;
	t_texture	west_txr;
}; // struct s_assets

void	assets_destroy(t_assets *assets);

#endif // CBD_ASSETS_H
