/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_fps.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/10 19:24:59 by tim           #+#    #+#                 */
/*   Updated: 2024/03/11 12:55:57 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_game.h"
#include "../../lib/libft/include/libft.h"
#include <stdlib.h>
#include "cbd_error.h"


/// @brief Simple FPS counter re-drawing every half a second.
/// @param param 
void hook_fps(void *param)
{
	t_game 	*game = param;
	double 	fps;
	char 	*fps_toa;
	
	game->frame_timer += game->mlx->delta_time;
	if (game->frame_timer >= .5)
	{
		if (game->fps_counter)
			mlx_delete_image(game->mlx, game->fps_counter);
		fps = (game->mlx->delta_time / 1000);
		fps_toa = ft_itoa((int)1/fps);
		if (!fps_toa)
			return ;
		game->fps_counter = mlx_put_string(game->mlx, fps_toa, 1400, 0);
		free(fps_toa);
		game->frame_timer = 0;
	}
}