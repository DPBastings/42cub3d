#ifndef CBD_H
# define CBD_H

# include "types.h"

# define FILE_EXT		".cub"
# define FILE_EXT_LEN	4

typedef struct s_assets	t_assets;
typedef struct s_game	t_game;
typedef struct s_map	t_map;

void	load(t_game *game, char const* path);
void	load_assets(t_assets *assets, t_fd fd);
void	load_map(t_map *map, t_fd fd);

#endif // CBD_H
