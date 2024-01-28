/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbd_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:36:02 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/27 14:36:02 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_MAP_H
# define CBD_MAP_H

# include "cbd.h"
# include "types.h"

# include <stddef.h>

struct s_map
{
	size_t	x_max;
	size_t	y_max;
	char	**contents;
}; // struct s_map

void	map_read(t_map *map, t_fd fd);
void	map_deinit(t_map *map);

#endif // CBD_MAP_H
