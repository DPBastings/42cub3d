/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_game.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:35:54 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 14:57:50 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_GAME_H
# define CBD_GAME_H

# include "cbd.h"
# include "cbd_assets.h"
# include "cbd_map.h"
# include "cbd_screen.h"

# include "MLX42.h"

/**
 * @brief	Game object.
 * 			Contains all data pertaining to the cub3d program.
 * @param assets	Assets object.
 * @param map		Map object.
 * @param screen	Screen object.
 * @param mlx		The MLX42 instance handle.
 */
struct s_game
{
	t_assets	assets;
	t_map		map;
	t_screen	screen;
	mlx_t		*mlx;
}; // struct s_game

void	game_init(t_game *self, char const *path);
void	game_read(t_game *self, t_fd fd);
void	game_run(t_game *self);
void	game_deinit(t_game *self);

#endif // CBD_GAME_H
