/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_rc.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/02 23:26:32 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/19 18:02:03 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_RC_H
# define CBD_RC_H

# include "cbd.h"

# include "point.h"
# include "types.h"
# include <stddef.h>
# include <math.h>

# define CBD_RC_RES			1920
	// == SCREEN_WIDTH_DFL
# define CBD_RC_WALL_HEIGHT	780
# define CBD_RC_ZOOM_DFL	1.2
# define CBD_RC_ZOOM_MIN	0.6
# define CBD_RC_ZOOM_MAX	1.5

typedef struct s_camera		t_camera;
typedef struct s_ray		t_ray;
typedef struct s_rc_result	t_rc_result;

typedef enum e_isct
{
	ISCT_V,
	ISCT_H,
}	t_isct;

/**
 * @brief	Camera object.
 * @param direction	Direction vector. Correlates with the player's movement
 * 					angle, albeit that this vector's length will always be 1.
 * @param plane		Camera plane vector.
 * @param zoom		The zoom level.
 * @note	Zoom level is equivalent to the ratio between the camera's direction
 * 			vector and the camera plane. To wit: the greater the camera plane's
 * 			length compared to the direction vector, the farther the camera
 * 			will be zoomed out.
 */
struct s_camera
{
	t_dvector	direction;
	t_dvector	plane;
};

void	camera_init(t_camera *self, t_dvector direction);
void	camera_rotate(t_camera *self, double rad);
void	camera_update(t_camera *self, t_dvector direction);
int		camera_zoom_in(t_camera *self);
int		camera_zoom_out(t_camera *self);

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
 * @brief	Raycaster results object.
 * 			Contains data resulting from the casting of an individual ray.
 * @param end		Endpoint of this ray.
 * @param direction	The direction of the ray.
 * @param length	Distance traveled by this ray.
 * @param isct		The orientation of the edge (horizontal or vertical)
 * 					intersected by this ray.
*/
struct s_rc_result
{
	t_dpoint	end;
	t_dvector	direction;
	double		length;
	t_isct		isct;
};

/**
 * @brief	Ray object.
 * @param pos			Position of the ray.
 * @param pos_grid		Position of the ray, rounded down to an integer; the
 * 						grid slot that the ray is currently in.
 * @param direction		Base direction vector.
 * @param ctr			Tracks the total x and y distance traveled so far.
 * @param delta_edge	The number of steps that need to be taken in order to
 * 						reach the next vertical/horizontal grid edge.
 * @param delta_grid	Grid steps vector: add .x or .y to pos_grid to move into
 * 						the next grid slot.
 */
struct s_ray
{
	t_dpoint	pos;
	t_point		pos_grid;
	t_dvector	direction;
	t_dvector	ctr;
	double		length;
	t_dvector	delta_edge;
	t_vector	delta_grid;
};

void	ray_init(t_ray *self, t_camera const *camera, t_dvector pos, size_t i);
t_isct	dda(t_ray *ray, t_map const *map);

#endif // CBD_RC_H
