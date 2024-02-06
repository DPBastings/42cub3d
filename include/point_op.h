/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:49:35 by dbasting          #+#    #+#             */
/*   Updated: 2024/02/06 11:49:36 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_OP_H
# define POINT_OP_H

typedef struct s_point	t_point;
typedef struct s_upoint	t_upoint;
typedef struct s_dpoint	t_dpoint;

typedef t_point			t_vector;
typedef t_upoint		t_uvector;
typedef t_dpoint		t_dvector;

static inline t_dvector	dvc_add(t_dvector a, t_dvector b)
{
	return ((t_dvector){a.x + b.x, a.y + b.y});
}

static inline t_dvector	dvc_subt(t_dvector a, t_dvector b)
{
	return ((t_dvector){a.x - b.x, a.y - b.y});
}

static inline t_dvector	dvc_mult(t_dvector a, t_dvector b)
{
	return ((t_dvector){a.x * b.x, a.y * b.y});
}

static inline t_dvector	dvc_div(t_dvector a, t_dvector b)
{
	return ((t_dvector){a.x / b.x, a.y / b.y});
}

#endif // POINT_OP_H
