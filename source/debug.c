/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/28 23:04:39 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 13:35:08 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "cbd_game.h"
#include "cbd_object.h"
#include "cbd_rc.h"

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

void	player_print(t_player const *player)
{
	t_dpoint const	fwd = {.x = player->pos.x + player->delta_m.x, .y = player->pos.y + player->delta_m.y};
	t_dpoint const	bwd = {.x = player->pos.x - player->delta_m.x, .y = player->pos.y - player->delta_m.y};
	t_dpoint const	lft = {.x = player->pos.x + player->delta_m.y, .y = player->pos.y - player->delta_m.x};
	t_dpoint const	rgt = {.x = player->pos.x - player->delta_m.y, .y = player->pos.y + player->delta_m.x};
	printf("player:\n"
		"pos       = %lf;%lf\n"
		"deltam    = %lf;%lf\n"
		"forward   = %lf;%lf (%u;%u)\n"
		"backward  = %lf;%lf (%u;%u)\n"
		"left      = %lf;%lf (%u;%u)\n"
		"right     = %lf;%lf (%u;%u)\n",
		player->pos.x, player->pos.y,
		player->delta_m.x, player->delta_m.y,
		fwd.x, fwd.y, point_from_dpoint(fwd).x, point_from_dpoint(fwd).y,
		bwd.x, bwd.y, point_from_dpoint(bwd).x, point_from_dpoint(bwd).y,
		lft.x, lft.y, point_from_dpoint(lft).x, point_from_dpoint(lft).y,
		rgt.x, rgt.y, point_from_dpoint(rgt).x, point_from_dpoint(rgt).y);
}

void	map_print(t_map const *map)
{

	printf("map:\n");
	for (int y = 0; y < map->y_size; ++y) {
		for (int x = 0; x < map->x_size; ++x)
			printf("%u", map->objects[y][x].type);
		printf("\n");
	}
}

void	rc_print(t_rc const *rc)
{
	for (size_t i = 0; i < CBD_RC_N_RAY_DFL; ++i)
		printf("%lf;%lf (dist %lf;%lf\n",
			rc->data[i].end.x, rc->data[i].end.y,
			rc->data[i].distance.x, rc->data[i].distance.y);
}

void	hook_debug(mlx_key_data_t keys, void *param)
{
	t_game *const	game = param;

	if (keys.key == MLX_KEY_F3 && keys.action == MLX_RELEASE)
	{
		player_print(&game->map.player);
		rc_print(&game->rc);
	}
}
