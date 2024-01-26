#include "cbd_error.h"

#include "ft_stdio.h"
#include <stdio.h>
#include <stdlib.h>

static char const *g_cbd_errlist[N_ERRNO] = {
	"Everything went better than expected.",
	"Something went wrong",
	"Usage: cub3d <map>.",
	"Invalid map file extension (expecting `.cub`).",
	"Invalid asset specification: unrecognized asset.",
	"Invalid asset specification: multiple indication of asset(s).",
	"Invalid map layout: unrecognized object.",
	"Invalid map layout: it isn't enclosed in walls.",
	"Invalid map layout: there's no start.",
	"Invalid map layout: there's more than one start.",
};

void	cbd_strerror(t_errno errno)
{
	if (errno == CBD_EGENERIC)
		perror(g_cbd_errlist[CBD_EGENERIC]);
	else
		ft_dprintf(2, "%s\n", g_cbd_errlist[errno]);
}

void	cbd_terminate(t_errno errno)
{
	cbd_strerror(errno);
	exit(EXIT_FAILURE);
}
