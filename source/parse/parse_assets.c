/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_assets.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 16:43:04 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 18:13:51 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_parse.h"
#include "cbd_assets.h"
#include "cbd_error.h"
#include "cbd_parse.h"
#include "utils.h"

#include "ft_string.h"
#include "MLX42.h"

static t_string const	g_headers[N_ACHKFLAG] = {
{HDR_CEILING, 1},
{HDR_FLOOR, 1},
{HDR_NORTH_WALL, 2},
{HDR_EAST_WALL, 2},
{HDR_SOUTH_WALL, 2},
{HDR_WEST_WALL, 2},
};

static void			parse_asset(t_achk *chk, t_assets *ats, char const **str);
static t_achkflag	parse_header(char const **str);
static void			parse_value(t_achkflag i, t_assets *assets, char const **s);

void	parse_assets(t_achk *check, t_assets *assets, char const *str)
{
	while (*str)
	{
		parse_skip_ws(&str);
		parse_asset(check, assets, &str);
	}
}

static void	parse_asset(t_achk *check, t_assets *assets, char const **str)
{
	t_achkflag	i;

	while (**str)
	{
		i = parse_header(str);
		if (check->flags[i] == true)
			cbd_terminate(CBD_EASSDOUBLE);
		check->flags[i] = true;
		parse_value(i, assets, str);
		parse_skip_ws(str);
	}
}

static t_achkflag	parse_header(char const **str)
{
	t_achkflag	i;

	parse_skip_ws(str);
	i = 0;
	while (i < N_ACHKFLAG)
	{
		if (ft_strncmp(*str, g_headers[i].data, g_headers[i].len) == 0)
		{
			*str += g_headers[i].len;
			return (i);
		}
		++i;
	}
	cbd_terminate(CBD_EASSINV);
	return (-1);
}

// O, how I long for the switch...
static void	parse_value(t_achkflag i, t_assets *assets, char const **str)
{
	parse_skip_ws(str);
	if (i == CEILING_RGB)
		assets->ceiling_rgba = parse_rgb(str);
	else if (i == FLOOR_RGB)
		assets->floor_rgba = parse_rgb(str);
	else if (i == NORTH_TXR)
		assets->textures[NORTH_WALL].path = parse_path(str);
	else if (i == EAST_TXR)
		assets->textures[EAST_WALL].path = parse_path(str);
	else if (i == SOUTH_TXR)
		assets->textures[SOUTH_WALL].path = parse_path(str);
	else if (i == WEST_TXR)
		assets->textures[WEST_WALL].path = parse_path(str);
}
