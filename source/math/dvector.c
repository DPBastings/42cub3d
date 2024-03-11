/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dvector.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/19 15:18:04 by dbasting      #+#    #+#                 */
/*   Updated: 2024/03/11 16:01:55 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include <math.h>


/// @brief compute vector according to scaling factor
/// @param dvc 
/// @param factor 
/// @return 
t_dvector	dvc_scale(t_dvector dvc, double factor)
{
	return ((t_dvector){dvc.x * factor, dvc.y * factor});
}

/// @brief computes hypothenuse distance of vec dvc, attemptend with
/// fast inverse sqrt, but method is deprecated since 1999 (Diff cpu architechture)
/// @param dvc 
/// @return 
double	dvc_len(t_dvector dvc)
{
	return (sqrt(dvc.x * dvc.x + dvc.y * dvc.y));
}