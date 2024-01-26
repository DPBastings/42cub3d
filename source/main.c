#include "cbd.h"
#include "cbd_game.h"
#include "cbd_error.h"

#include <stdlib.h>

int	main(int argc, char** argv)
{
	t_game	game;

	if (argc != 2)
		cbd_terminate(CBD_EARGC);
	load(&game, argv[1]);
	return (CBD_SUCCESS);
}
