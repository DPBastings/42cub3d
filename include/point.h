/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:33:14 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 14:43:29 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include <math.h>

typedef struct s_point	t_point;
typedef struct s_dpoint	t_dpoint;

struct s_point
{
	int	x;
	int	y;
};

struct s_dpoint
{
	double	x;
	double	y;
};

#endif // POINT_H
