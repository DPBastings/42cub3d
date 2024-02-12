/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:35:34 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 12:54:29 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "cbd.h"
# include "cbd_rc.h"

# include <stdbool.h>
# include "MLX42.h"

void	game_print(t_game const *game);
void	assets_print(t_assets const *assets, bool loaded);
void	player_print(t_player const *player);
void	map_print(t_map const *map);
void	ray_print(t_ray const *ray);

void	hook_debug(mlx_key_data_t keys, void *param);

#endif // DEBUG_H
