/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_rc.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 23:26:32 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 16:39:38 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_RC_H
# define CBD_RC_H

# include "cbd.h"

# include "point.h"
# include "types.h"
# include <stddef.h>
# include <math.h>

# define CBD_RC_FOV_WIDTH_DEG	90
# define CBD_RC_FOV_WIDTH_RAD	1.57

typedef struct s_camera	t_camera;
typedef struct s_ray	t_ray;

struct s_camera
{
	t_vector	direction;
	t_vector	plane;
};

void	camera_init(t_camera *self, t_vector direction, double zoom);

/**
 * @brief	Raycaster object.
 * @param rays	Buffer storing individual rays.
 * @param size	Size of the ray buffer.
 * @param rpr	Angle between two individual rays, in radians.
*/
struct s_rc
{
	t_camera	camera;
	t_ray		*rays;
	size_t		size;
	double		radpr;
};

void	rc_init(t_rc *self, size_t size);
void	rc_deinit(t_rc *self);
void	rc_cast(t_rc *self, t_map const *map);

/**
 * @brief	Ray object.
 * @param angle	The angle at which this ray travels, in radians.
 * @param end	The endpoint of this ray.
*/
struct s_ray
{
	double		angle;
	t_dpoint	end;
};

void	ray_init(t_ray *self, double angle, t_dpoint origin);
void	ray_travel(t_ray *self, t_map const *map);

static inline t_dpoint	get_ray_delta(double angle)
{
	return ((t_dpoint){cos(angle), sin(angle)});
}

#endif // CBD_RC_H
