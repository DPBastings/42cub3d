/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:32:40 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/27 14:32:43 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd.h"
#include "cbd_game.h"
#include "cbd_error.h"

#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		cbd_terminate(CBD_EARGC);
	game_init(&game, argv[1]);
	game_deinit(&game);
	return (CBD_SUCCESS);
}
