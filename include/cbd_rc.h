/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbd_rc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:26:32 by dbasting          #+#    #+#             */
/*   Updated: 2024/02/02 23:26:33 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_RC_H
# define CBD_RC_H

# include "cbd.h"

# include "point.h"
# include <math.h>

# define CBD_RC_FOV_WIDTH	2.0944 // 120 degrees

typedef struct s_ray	t_ray;

struct s_rc
{
	t_ray	*rays;
	size_t	size;
};

void	rc_init(t_rc *self, size_t size);
void	rc_deinit(t_rc *self);
void	rc_cast(double angle, t_map const *map);

struct s_ray
{
	t_dpoint		delta;
	double			distance;
	t_object const	*object;
};

void	ray_init(t_ray *self, t_dpoint delta);
void	ray_travel(t_ray *self, t_map const *map)

#endif // CBD_RC_H
