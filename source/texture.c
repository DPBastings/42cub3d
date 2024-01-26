#include "cbd_assets.h"
#include "cbd_error.h"

#include <stdlib.h>
#include "MLX42.h"

void	texture_load(t_texture *txr)
{
	char *const	path = txr->path;

	txr->data = mlx_load_png(path);
	if (txr->data == NULL)
		cbd_terminate(CBD_EGENERIC);
	free(path);
}

void	texture_destroy(t_texture *txr)
{
	mlx_delete_texture(txr->data);
}
