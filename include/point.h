/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:33:14 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/19 15:21:57 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <math.h>

typedef struct s_point	t_point;
typedef struct s_upoint	t_upoint;
typedef struct s_dpoint	t_dpoint;

typedef t_point			t_vector;
typedef t_upoint		t_uvector;
typedef t_dpoint		t_dvector;

/**
 * @brief	Integer point.
 * @param x	X coordinate.
 * @param y	Y coordinate.
 */
struct s_point
{
	int	x;
	int	y;
};

/**
 * @brief	Unsigned point.
 * @param x	X coordinate.
 * @param y	Y coordinate.
 */
struct s_upoint
{
	unsigned int	x;
	unsigned int	y;
};

/**
 * @brief	Double point.
 * @param x	X coordinate.
 * @param y	Y coordinate.
 */
struct s_dpoint
{
	double	x;
	double	y;
};

double		dvc_len(t_dvector dvc);
t_dvector	dvc_scale(t_dvector dvc, double factor);

static inline t_dvector	dvc_add(t_dvector a, t_dvector b)
{
	return ((t_dvector){a.x + b.x, a.y + b.y});
}

static inline t_dvector	dvc_mult(t_dvector a, t_dvector b)
{
	return ((t_dvector){a.x * b.x, a.y * b.y});
}

static inline t_dvector	dvc_rotate(t_dvector dvc, double rad)
{
	double const	cosine = cos(rad);
	double const	sine = sin(rad);

	return ((t_dvector){
		cosine * dvc.x - sine * dvc.y,
		sine * dvc.x + cosine * dvc.y
	});
}

static inline t_dpoint	dpoint_from_point(t_point pt)
{
	return ((t_dpoint){pt.x, pt.y});
}

static inline t_point	point_from_dpoint(t_dpoint dpt)
{
	return ((t_point){dpt.x, dpt.y});
}

#endif // POINT_H
