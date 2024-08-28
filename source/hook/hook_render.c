/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 15:35:15 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/28 19:02:04 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_hook.h"
#include "cbd_game.h"
#include "hrc.h"

void	hook_render(void *param)
{
	t_game	*game;

	game = param;
	rc_cast(&game->rc, &game->map);
	screen_render(game, (struct s_screen_data){
		&game->assets, &game->rc, &game->map, &game->screen.view
	});
}
