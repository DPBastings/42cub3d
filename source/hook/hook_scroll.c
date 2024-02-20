/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_scroll.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/16 16:28:48 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/19 18:02:47 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_rc.h"
#include "cbd_game.h"

static inline void	_zoom_in(t_camera *camera, t_view *view);
static inline void	_zoom_out(t_camera *camera, t_view *view);

void	hook_scroll(double xdelta, double ydelta, void *param)
{
	t_game *const	game = param;

	(void) xdelta;
	if (ydelta > 0)
		_zoom_in(&game->rc.camera, &game->screen.view);
	else
		_zoom_out(&game->rc.camera, &game->screen.view);
}

static inline void	_zoom_in(t_camera *camera, t_view *view)
{
	if (camera_zoom_in(camera) == 0)
		view->wall_height *= CBD_VIEW_ZOOM_FACTOR;
}

static inline void	_zoom_out(t_camera *camera, t_view *view)
{
	if (camera_zoom_out(camera) == 0)
		view->wall_height /= CBD_VIEW_ZOOM_FACTOR;
}
