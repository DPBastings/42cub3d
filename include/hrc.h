/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hrc.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/29 17:12:11 by tim           #+#    #+#                 */
/*   Updated: 2024/08/28 19:00:43 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HRC_H
# define HRC_H

# include "cbd.h"
# include "cbd_game.h"
# include "libft.h"
# include "cbd_screen.h"
# include "cbd_rc.h"
# include "point.h"
# include "MLX42_ext.h"
# include "cbd_error.h"
# include <stdlib.h>

void			hrc_init(t_game *self);
void			hrc_cast(t_game *self);
void			compute_ray_direction(t_hrc_data *data,
					t_player player, t_camera cam);
void			compute_step(t_hrc_data *data, t_player player);
void			update_txr_coord(t_hrc *hrc, t_hrc_data *data);
t_texture		*texture_init(char *path);

/** 
 * @brief horizontal raycaster data for floor and ceilling.
 * @param raydir_left ray direction for leftmost ray.
 * @param raydir_right	ray direction for rightmost ray.
 * @param pos_y current y postion compared to the center of the screen.
 * @param cam_pos_y vertical position of the camera.
 * @param floor_step real world step vector to add 
 * for each x parallel to cam plane.
 * @param floor_coord real world leftmost column cordinate.
 * @param cell vector to store integer part of floor cordinate.
 * @param texture_coord vector to store fractonial part of floor cordinate.
 */
typedef struct s_hrc_data
{
	bool		is_floor;
	t_dvector	raydir_0;
	t_dvector	raydir_1;
	int			pos_y;
	int			cam_pos_y;
	double		row_distance;
	t_dvector	floor_step;
	t_dvector	floor_coord;
	t_point		cell;
	t_point		texture_coord;
}				t_hrc_data;

typedef struct s_hrc
{
	t_hrc_data	*data;
	t_texture	*floor;
	t_texture	*ceilling;
}				t_hrc;

#endif