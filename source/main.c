/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:32:40 by dbasting      #+#    #+#                 */
/*   Updated: 2024/05/21 14:15:29 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd.h"
#include "cbd_game.h"
#include "cbd_error.h"

#include <stdlib.h>

#include "cbd_rc.h"

int	main(int argc, char **argv)
{
	t_game	game;
	printf("beep boop shey\n");

	if (argc != 2)
		cbd_terminate(CBD_EARGC);
	game_init(&game, argv[1]);
	game_run(&game);
	game_deinit(&game);
	return (CBD_SUCCESS);
}
