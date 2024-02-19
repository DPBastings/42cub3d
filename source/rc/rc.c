/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rc.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/03 17:31:18 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/19 15:57:30 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_rc.h"
#include "cbd_error.h"

#include <stdlib.h>

void	rc_init(t_rc *self, t_dvector direction)
{
	camera_init(&self->camera, direction);
	self->data = malloc(CBD_RC_RES * sizeof(t_rc_result));
	if (self->data == NULL)
		cbd_terminate(CBD_EGENERIC);
}

void	rc_deinit(t_rc *self)
{
	free(self->data);
}
