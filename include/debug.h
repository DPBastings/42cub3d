/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:35:34 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 17:49:47 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "cbd.h"

# include <stdbool.h>

void	game_print(t_game const *game);
void	assets_print(t_assets const *assets, bool loaded);
void	player_print(t_player const *player);
void	map_print(t_map const *map);

#endif // DEBUG_H
