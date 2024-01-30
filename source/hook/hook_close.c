/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:10:49 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/30 20:10:50 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_hook.h"
#include "cbd_game.h"

void	hook_close(void *param)
{
	t_game *const	game = param;

	mlx_close_window(game->mlx);
}
