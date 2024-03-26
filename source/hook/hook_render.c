/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 15:35:15 by dbasting      #+#    #+#                 */
/*   Updated: 2024/03/26 17:20:17 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_hook.h"
#include "cbd_game.h"

void	hook_render(void *param)
{
	t_game	*game = param;

	rc_cast(&game->rc, &game->map);
	screen_render(game, (struct s_screen_data){
		&game->assets, &game->rc, &game->map
	});
}
