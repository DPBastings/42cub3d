/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_game.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:35:54 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/19 13:01:59 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_GAME_H
# define CBD_GAME_H

# include "cbd.h"
# include "cbd_assets.h"
# include "cbd_map.h"
# include "cbd_screen.h"
# include "cbd_rc.h"
# include "sprite.h"

# include "MLX42.h"

typedef enum e_game_status
{
	CBD_GAME_STOPPED = 0,
	CBD_GAME_RUNS,
	CBD_GAME_PAUSED,
}	t_game_status;

/**
 * @brief	Game object.
 * 			Contains all data pertaining to the cub3d program.
 * @param assets	Assets object.
 * @param map		Map object.
 * @param screen	Screen object.
 * @param rc		Raycaster object.
 * @param status	The game's execution status.
 * @param mlx		The MLX42 instance handle.
 */
struct s_game
{
	t_assets		assets;
	t_map			map;
	t_sprite		*sprites;
	t_texture		*floor;
	t_texture		*ceilling;
	t_screen		screen;
	t_rc			rc;
	t_hrc 			*hrc;
	t_game_status	status;
	mlx_image_t		*fps_counter;
	double			frame_timer;
	mlx_t			*mlx;
}; // struct s_game

void	game_init(t_game *self, char const *path);
void	game_read(t_game *self, t_fd fd);
void	game_deinit(t_game *self);

void	game_run(t_game *self);
void	game_pause(t_game *self);
void	game_pause_toggle(t_game *self);
void	game_unpause(t_game *self);

#endif // CBD_GAME_H
