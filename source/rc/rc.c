/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:31:18 by dbasting          #+#    #+#             */
/*   Updated: 2024/02/03 17:31:19 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_rc.h"

#include <stdlib.h>

void	rc_init(t_rc *self, size_t size)
{
	self->size = size;
	self->rays = malloc(self->size * sizeof(t_ray));
	if (self->rays == NULL)
		cbd_terminate(CBD_EGENERIC);
}

void	rc_deinit(t_rc *self)
{
	free(self->rays);
}
