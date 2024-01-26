#include "cbd.h"
#include "cbd_parse.h"

#include "ft_ctype.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include <stdbool.h>
#include <stdlib.h>

static bool	is_done(bool check[N_ASSET]);
static void	scan_line(t_assets *assets, char const *ln, bool check[N_ASSET]);

void	load_assets(t_assets *assets, t_fd fd)
{
	char	*ln;
	bool	check[N_ASSET];

	ft_memset(&check, 0, sizeof(bool[N_ASSET]));
	while (!is_done(check))
	{
		ln = ft_getline(fd);
		scan_line(assets, ln, check);
		free(ln);
	}
}

static bool	is_done(bool check[N_ASSET])
{
	size_t	i;

	i = 0;
	while (i < N_ASSET)
		if (check[i++] == false)
				return (false);
	return (true);
}

static void	scan_line(t_assets *assets, char const *ln, bool check[N_ASSET])
{
	while (*ln)
		parse_asset(assets, &ln, check);
}
