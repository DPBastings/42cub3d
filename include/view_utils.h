/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   view_utils.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 15:19:59 by tim           #+#    #+#                 */
/*   Updated: 2024/08/28 17:46:59 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_assets.h"
#include "cbd_screen.h"
#include "cbd_rc.h"

int				_get_height(t_view const *self, double ray_length);
uint32_t		_get_column(t_rc_result const *rc, t_texture const txr);
t_texture_id	_get_txr(t_rc_result *rc);
