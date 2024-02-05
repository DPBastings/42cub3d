/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rc.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/03 17:31:18 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 16:34:55 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_rc.h"
#include "cbd_error.h"

#include <stdlib.h>

void	rc_init(t_rc *self, size_t size)
{
	self->size = size;
	self->rays = malloc(self->size * sizeof(t_ray));
	if (self->rays == NULL)
		cbd_terminate(CBD_EGENERIC);
	self->radpr = CBD_RC_FOV_WIDTH_RAD / size;
}

void	rc_deinit(t_rc *self)
{
	free(self->rays);
}
