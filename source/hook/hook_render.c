/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 15:35:15 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 17:54:36 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_hook.h"
#include "cbd_game.h"

void	hook_render(void *param)
{
	t_game *const	game = param;

	//rc_cast(&game->rc, &game->map);
	screen_render(&game->screen, (struct s_screen_data){
		&game->assets, &game->rc, &game->map
	});
}
