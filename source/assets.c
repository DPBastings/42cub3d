/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assets.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:35:03 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/29 16:11:38 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_error.h"
#include "cbd_parse.h"

#include "ft_ctype.h"
#include "ft_stdio.h"
#include <stdbool.h>
#include <stdlib.h>

static void	load_static_textures(t_texture textures[N_TEXTURE]);
static void	load_dynamic_textures(t_texture textures[N_TEXTURE]);

static char const *const	g_txr_paths[N_STATIC_TEXTURE] = {
	"./assets/textures/pause.png",
	"./assets/textures/crosshair.png",
};

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
	load_dynamic_textures(assets->textures);
	load_static_textures(assets->textures);
}

void	assets_deinit(t_assets *assets)
{
	size_t	i;

	i = 0;
	while (i < N_TEXTURE)
		texture_deinit(&assets->textures[i++]);
}

static void	load_dynamic_textures(t_texture textures[N_TEXTURE])
{
	size_t	i;

	i = 0;
	while (i < N_DYNAMIC_TEXTURE)
		texture_load(NULL, &textures[i++]);
}

static void	load_static_textures(t_texture textures[N_TEXTURE])
{
	size_t	i;

	i = 0;
	while (i < N_STATIC_TEXTURE)
	{
		textures[i + N_DYNAMIC_TEXTURE].data = mlx_load_png(g_txr_paths[i]);
		if (textures[i + N_DYNAMIC_TEXTURE].data == NULL)
			cbd_mlx_terminate(NULL, CBD_EGENERIC);
		++i;
	}
}
