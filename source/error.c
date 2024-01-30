/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:32:26 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/27 14:32:34 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_error.h"

#include "ft_stdio.h"
#include <stdio.h>
#include <stdlib.h>

static char const *const	g_cbd_errlist[N_ERRNO] = {
	"Everything went better than expected.",
	"Something went wrong",
	"Usage: cub3d <map>.",
	"Invalid map file extension (expecting `.cub`).",
	"Invalid asset specification: unrecognized asset.",
	"Invalid asset specification: multiple indication of asset(s).",
	"Invalid map layout: unrecognized object.",
	"Invalid map layout: faulty wall enclosure.",
	"Invalid map layout: missing start position indicator.",
	"Invalid map layout: multiple start position indicators.",
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
