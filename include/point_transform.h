/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_transform.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:39 by dbasting          #+#    #+#             */
/*   Updated: 2024/02/06 11:49:40 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_TRANSFORM_H
# define POINT_TRANSFORM_H

typedef struct s_point	t_point;
typedef struct s_upoint	t_upoint;
typedef struct s_dpoint	t_dpoint;

typedef t_point			t_vector;
typedef t_upoint		t_uvector;
typedef t_dpoint		t_dvector;

static inline t_dvector	dvc_rotate(t_dvector dvc, double rad)
{
	double const	cosine = cos(rad);
	double const	sine = sin(rad);

	return ((t_dvector){
		cosine * dvc.x - sine * dvc.y,
		sine * dvc.x + cosine * dvc.y
	});
}

#endif // POINT_TRANSFORM_H
