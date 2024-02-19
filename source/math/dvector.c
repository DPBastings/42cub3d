/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dvector.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 15:18:04 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/19 15:20:33 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

#include <math.h>

t_dvector	dvc_scale(t_dvector dvc, double factor)
{
	return ((t_dvector){dvc.x * factor, dvc.y * factor});
}

double	dvc_len(t_dvector dvc)
{
	return (sqrt(dvc.x * dvc.x + dvc.y * dvc.y));
}