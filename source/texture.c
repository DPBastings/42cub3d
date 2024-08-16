/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:32:48 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/16 19:22:29 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_error.h"

#include <stdlib.h>
#include "MLX42.h"

#include <stdio.h>

void	texture_load(t_texture *txr)
{
	char *const	path = txr->path;
	
	txr->data = mlx_load_png(path);
	if (txr->data == NULL)
		cbd_terminate(CBD_EGENERIC);
	free(path);
}

void	texture_deinit(t_texture *txr)
{
	mlx_delete_texture(txr->data);
}
