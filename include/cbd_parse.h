#ifndef CBD_PARSE_H
# define CBD_PARSE_H

# include "cbd.h"

# include "MLX42.h"
# include <stdbool.h>

# define HDR_CEILING	"C"
# define HDR_FLOOR		"F"
# define HDR_NORTH_WALL	"NO"
# define HDR_EAST_WALL	"EA"
# define HDR_SOUTH_WALL	"SO"
# define HDR_WEST_WALL	"WE"
# define HDR_DOOR		"DO"

# define WALL	'1'
# define EMPTY	'0'
# define VOID	' '
# define NORTH	'N'
# define WEST	'W'
# define SOUTH	'S'
# define EAST	'E'
# define DOOR	'D'
# define COIN0	'X'

typedef enum e_assetno
{
	CEILING_RGB,
	FLOOR_RGB,
	NORTH_TXR,
	EAST_TXR,
	SOUTH_TXR,
	WEST_TXR,
	N_ASSET,
}	t_assetno;

void	parse_asset(t_assets *assets, char const **str, bool check[N_ASSET]);
t_rgba	parse_rgb(char const **str);
char	*parse_path(char const **str);

void	parse_skip_ws(char const **str);

#endif // CBD_PARSE_H
