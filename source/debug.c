/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/28 23:04:39 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 17:49:33 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "cbd_game.h"
#include "cbd_object.h"

#include <stdio.h>

void	game_print(t_game const *game)
{
	assets_print(&game->assets, false);
	map_print(&game->map);
}

void	assets_print(t_assets const *assets, bool loaded)
{
	printf("floor: %u\nceiling: %u\n", assets->floor_rgba, assets->ceiling_rgba);
	if (loaded)
		for (size_t i = 0; i < N_TEXTURE; ++i)
			printf("texture: %p\n", assets->textures[i].data);
	else
		for (size_t i = 0; i < N_TEXTURE; ++i)
			printf("texture: %s\n", assets->textures[i].path);
}

void	map_print(t_map const *map)
{
	printf("player at x = %lf; y = %lf\n", map->player.pos.x, map->player.pos.y);
	printf("map:\n");
	for (int y = 0; y < map->y_size; ++y) {
		for (int x = 0; x < map->x_size; ++x)
			printf("%u", map->objects[y][x].type);
		printf("\n");
	}
}
