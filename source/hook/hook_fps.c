/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_fps.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/10 19:24:59 by tim           #+#    #+#                 */
/*   Updated: 2024/08/29 13:55:18 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_game.h"
#include "../../lib/libft/include/libft.h"
#include <stdlib.h>
#include "cbd_error.h"

static char	*get_fps_string(double delta_time)
{
	char	*str;
	char	*fps_counter;

	str = ft_itoa((int)(1 / delta_time));
	if (!str)
		return (NULL);
	fps_counter = ft_strjoin("FPS: ", str);
	if (!fps_counter)
		return (free(str), NULL);
	return (free(str), fps_counter);
}

/// @brief Simple FPS counter re-drawing every half a second.
void	fps_counter_render(t_game *game)
{
	char	*str;

	game->frame_timer += game->mlx->delta_time;
	if (game->frame_timer >= .5)
	{
		if (game->fps_counter)
			mlx_delete_image(game->mlx, game->fps_counter);
		str = get_fps_string(game->mlx->delta_time);
		if (!str)
			return ;
		game->fps_counter = mlx_put_string(game->mlx, str,
				CBD_SCREEN_W_DFL - 75, 0);
		mlx_set_instance_depth(&game->fps_counter->instances[0],
			CBD_Z_SCREEN_OVERLAY_ICON);
		free(str);
		game->frame_timer = 0;
	}
}
