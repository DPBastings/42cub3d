/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:32:48 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/29 16:37:58 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_error.h"
#include <stdlib.h>
#include "MLX42.h"

void	texture_load(t_game *self, t_texture *txr)
{
	char *const	path = txr->path;

	txr->data = mlx_load_png(path);
	if (txr->data == NULL)
	{
		if (self)
			return (free(path), cbd_mlx_terminate(self, CBD_EGENERIC));
		else
			return (free(path), cbd_terminate(CBD_EGENERIC));
	}
	free(path);
}

void	texture_deinit(t_texture *txr)
{
	if (txr->data)
		mlx_delete_texture(txr->data);
}
