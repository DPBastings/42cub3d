/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assets.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:35:03 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 18:19:29 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_error.h"
#include "cbd_parse.h"

#include "ft_ctype.h"
#include "ft_stdio.h"
#include <stdbool.h>
#include <stdlib.h>

#include "debug.h"

static void	load_textures(t_texture textures[N_TEXTURE]);

void	assets_read(t_assets *assets, t_fd fd)
{
	t_achk	check;
	char	*ln;

	achk_init(&check);
	while (!achk_done(&check))
	{
		ln = ft_getline(fd);
		if (ln == NULL)
			cbd_terminate(CBD_EASSINV);
		parse_assets(&check, assets, ln);
		free(ln);
	}
	assets_print(assets, false);
	load_textures(assets->textures);
	assets_print(assets, true);
}

void	assets_deinit(t_assets *assets)
{
	size_t	i;

	i = 0;
	while (i < N_TEXTURE)
		texture_deinit(&assets->textures[i++]);
}

static void	load_textures(t_texture textures[N_TEXTURE])
{
	size_t	i;

	i = 0;
	while (i < N_TEXTURE)
		texture_load(&textures[i++]);
}
