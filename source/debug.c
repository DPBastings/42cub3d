/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:04:39 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/28 23:04:40 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "cbd_game.h"

#include <stdio.h>

void	game_print(t_game *game)
{
	assets_print(&game->assets, false);
	map_print(&game->map);
}

void	assets_print(t_assets *assets, bool loaded)
{
	printf("floor: %u\nceiling: %u\n", assets->floor_rgba, assets->ceiling_rgba);
	if (loaded)
		for (size_t i = 0; i < N_TEXTURE; ++i)
			printf("texture: %p\n", assets->textures[i].data);
	else
		for (size_t i = 0; i < N_TEXTURE; ++i)
			printf("texture: %s\n", assets->textures[i].path);
}

void	map_print(t_map *map)
{
	printf("map: %p\n", map);
}
