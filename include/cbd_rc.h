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

# define CBD_RC_N_RAY_DFL	1200 // Minimum value of 3

typedef struct s_camera		t_camera;
typedef struct s_ray		t_ray;
typedef struct s_rc_result	t_rc_result;

/**
 * @brief	Camera object.
 * @param direction	Direction vector. Correlates with the player's movement
 * 					angle, albeit that this vector's length will always be 1.
 * @param plane		Camera plane vector.
 * @note	The ratio between the direction vector and the camera plane is
 * 			equivalent to the camera's zoom level. To wit: the greater the
 * 			camera plane's length compared to the direction vector, the
 * 			farther the camera will be zoomed out.
 */
struct s_camera
{
	t_dvector	direction;
	t_dvector	plane;
};

void	camera_init(t_camera *self, t_dvector direction, double zoom);
void	camera_rotate(t_camera *self, double rad);
void	camera_zoom(t_camera *self, double zoom);

/**
 * @brief	Raycaster object.
 * @param camera	Camera object.
 * @param data		Buffer storing the results of the raycaster algorithm.
*/
struct s_rc
{
	t_camera	camera;
	t_rc_result	*data;
};

void	rc_init(t_rc *self, t_dvector direction);
void	rc_deinit(t_rc *self);
void	rc_cast(t_rc *self, t_map const *map);

/**
 * @brief	Raycaster data object.
 * 			Contains data pertaining to the casting of an individual ray.
 * @param distance	Distance traveled by this ray.
 * @param end		Endpoint of this ray.
*/
struct s_rc_result
{
	t_dvector	distance;
	t_dpoint	end;
	double		distanced;
};

/**
 * @brief	Ray object.
 * @param start_x	Start point of this ray on the camera plane.
 * @param dpos		The position of the ray.
 * @param ipos		The position of the ray, rounded down to an integer.
 * @param direction	Direction vector.
 * @param ddelta	Distance this ray must travel before encoutering the next
 * 					integral X or Y gridline, respectively.
 * @param idelta	Distance this ray must travel to enter the next grid slot.
 */
struct s_ray
{
	double		start_x;
	t_dvector	dpos;
	t_vector	ipos;
	t_dvector 	direction;
	t_dvector 	ddelta;
	t_vector	idelta;
};

void	ray_init(t_ray *self, t_camera const *camera, t_dvector pos, size_t i);
void	ray_travel(t_ray *self, t_map const *map);

static inline t_dpoint	get_ray_delta(double angle)
{
	return ((t_dpoint){cos(angle), sin(angle)});
}

#endif // CBD_RC_H
