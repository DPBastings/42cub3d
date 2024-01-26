#ifndef CBD_GAME_H
# define CBD_GAME_H

# include "cbd.h"
# include "cbd_assets.h"
# include "cbd_map.h"

struct s_game
{
	t_assets	assets;
	t_map		map;
}; // struct s_game

void	game_destroy(t_game *game);

#endif // CBD_GAME_H
