#include "cbd_assets.h"
#include "cbd_error.h"
#include "cbd_parse.h"

#include "ft_string.h"
#include "MLX42.h"

struct s_str
{
	char const*	data;
	size_t		len;
};

static struct s_str const	g_headers[N_ASSET] = {
	{HDR_CEILING, 1},
	{HDR_FLOOR, 1},
	{HDR_NORTH_WALL, 2},
	{HDR_EAST_WALL, 2},
	{HDR_SOUTH_WALL, 2},
	{HDR_WEST_WALL, 2},
};

static t_assetno	parse_header(char const **str);
static void			parse_value(t_assetno i, t_assets *assets, char const **s);

void	parse_asset(t_assets *assets, char const **str, bool check[N_ASSET])
{
	t_assetno	i;

	while (**str)
	{
		i = parse_header(str);
		if (check[i] == true)
			cbd_terminate(CBD_EASSDOUBLE);
		check[i] = true;
		parse_value(i, assets, str);
	}
}

static t_assetno	parse_header(char const **str)
{
	t_assetno	i;

	parse_skip_ws(str);
	i = 0;
	while (i < N_ASSET)
		if (ft_strncmp(*str, g_headers[i].data, g_headers[i].len) == 0) {
			*str += g_headers[i].len - 1;
			return (i);
		}
	cbd_terminate(CBD_EASSINV);
	return (-1);
}

// O, how I long for the switch...
static void	parse_value(t_assetno i, t_assets *assets, char const **str)
{
	if (i == CEILING_RGB)
		assets->ceiling_rgba = parse_rgb(str);
	else if (i == FLOOR_RGB)
		assets->floor_rgba = parse_rgb(str);
	else if (i == NORTH_TXR)
		assets->north_txr.path = parse_path(str);
	else if (i == EAST_TXR)
		assets->east_txr.path = parse_path(str);
	else if (i == SOUTH_TXR)
		assets->south_txr.path = parse_path(str);
	else if (i == WEST_TXR)
		assets->west_txr.path = parse_path(str);
}
