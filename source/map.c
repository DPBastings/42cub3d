/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:14 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/27 14:35:15 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd.h"

#include <stddef.h>
#include <stdlib.h>

#define	REALLOC_SIZE	16

static void	map_realloc(t_map *map, size_t size);

void	map_read(t_map *map, int fd)
{
	size_t	capacity;

	capacity = REALLOC_SIZE;
	map->contents = malloc(sizeof(char *) * capacity);
	if (map->contents == NULL)
		cbd_terminate(CBD_EGENERIC);
	map->y_max = 0;
	map->contents[y_max] = ft_getline(fd);
}

void	map_deinit(t_map *map)
{
	(void) map;
}
