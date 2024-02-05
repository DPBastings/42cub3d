/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:33:14 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 12:58:50 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <math.h>

typedef struct s_point	t_point;
typedef struct s_upoint	t_upoint;
typedef struct s_dpoint	t_dpoint;

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

#endif // POINT_H
