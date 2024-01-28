/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbd_game.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:54 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/27 14:35:55 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_GAME_H
# define CBD_GAME_H

# include "cbd.h"
# include "cbd_assets.h"
# include "cbd_map.h"

struct s_game
{
	t_assets	assets;
	t_map		map;
}; // struct s_game

void	game_init(t_game *game, char const *path);
void	game_read(t_game *game, t_fd fd);
void	game_deinit(t_game *game);

#endif // CBD_GAME_H
