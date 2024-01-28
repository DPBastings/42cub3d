/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:34 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/27 14:35:35 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "cbd.h"

# include <stdbool.h>

void	game_print(t_game *game);
void	assets_print(t_assets *game, bool loaded);
void	map_print(t_map *map);

#endif // DEBUG_H
