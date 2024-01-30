/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:05:00 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/30 11:05:01 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_object.h"

#include <stddef.h>
#include <stdlib.h>

void	object_init(t_object *self, t_object_type type)
{
	self->type = type;
	self->data = NULL;
}

void	object_deinit(t_object *self)
{
	free(self->data);
}
