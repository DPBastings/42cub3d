/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_cast.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:28 by dbasting          #+#    #+#             */
/*   Updated: 2024/02/06 11:49:30 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_CAST_H
# define POINT_CAST_H

typedef struct s_point	t_point;
typedef struct s_upoint	t_upoint;
typedef struct s_dpoint	t_dpoint;

typedef t_point			t_vector;
typedef t_upoint		t_uvector;
typedef t_dpoint		t_dvector;

static inline t_dpoint	dpoint_from_point(t_point pt)
{
	return ((t_dpoint){pt.x, pt.y});
}

static inline t_point	point_from_dpoint(t_dpoint dpt)
{
	return ((t_point){dpt.x, dpt.y});
}

static inline t_point	point_from_dpointr(t_dpoint dpt)
{
	return ((t_point){round(dpt.x), round(dpt.y)});
}

#endif // POINT_CAST_H
