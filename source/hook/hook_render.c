/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 15:35:15 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/02 16:08:28 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_hook.h"
#include "cbd_game.h"

void	hook_render(void *param)
{
	t_game *const	game = param;

	minimap_update(&game->screen.minimap, &game->map);
}