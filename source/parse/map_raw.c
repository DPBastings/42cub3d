/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_raw.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 13:47:12 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/29 14:16:58 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_parse.h"
#include "cbd_error.h"

#include "ft_stdio.h"
#include "ft_string.h"
#include <stdlib.h>

#define REALLOC_SIZE	16

static char	*ft_getline_skip_empty(t_fd fd);
static void	map_raw_realloc(t_map_raw *self, int *capacity);

void	map_raw_read(t_map_raw *self, t_fd fd)
{
	char	*ln;
	int		capacity;

	capacity = REALLOC_SIZE;
	self->contents = malloc(sizeof(char *) * capacity);
	if (self->contents == NULL)
		cbd_terminate(CBD_EGENERIC);
	self->y_size = 0;
	ln = ft_getline_skip_empty(fd);
	while (ln)
	{
		if (self->y_size >= capacity)
			map_raw_realloc(self, &capacity);
		self->contents[self->y_size++] = ln;
		ln = ft_getline(fd);
	}
}

void	map_raw_deinit(t_map_raw *self)
{
	int	i;

	i = 0;
	while (i < self->y_size)
		free(self->contents[i++]);
	free(self->contents);
}

static char	*ft_getline_skip_empty(t_fd fd)
{
	char		*ln;
	char const	*wd;

	ln = ft_getline(fd);
	while (ln)
	{
		wd = ln;
		parse_skip_ws(&wd);
		if (*wd)
			break ;
		free(ln);
		ln = ft_getline(fd);
	}
	return (ln);
}

static void	map_raw_realloc(t_map_raw *self, int *capacity)
{
	char	**new_contents;

	new_contents = malloc(sizeof(char *) * (*capacity + REALLOC_SIZE));
	if (new_contents == NULL)
		cbd_terminate(CBD_EGENERIC);
	ft_memcpy(new_contents, self->contents, *capacity * sizeof(char *));
	free(self->contents);
	self->contents = new_contents;
	*capacity += REALLOC_SIZE;
}
