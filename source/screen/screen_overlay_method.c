/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_overlay_method.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:33:43 by dbasting          #+#    #+#             */
/*   Updated: 2024/02/20 14:33:43 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_screen.h"

#include "MLX42_ext.h"

void	screen_overlay_pause(t_screen_overlay *self)
{
	mlx_image_fill(self->bg, CBD_SCREEN_OVERLAY_PAUSE_CLR);
	self->icons[SCREEN_OVERLAY_ICON_PAUSE]->instances[0].enabled = true;
	self->icons[SCREEN_OVERLAY_ICON_CROSSHAIR]->instances[0].enabled = false;
}

void	screen_overlay_unpause(t_screen_overlay *self)
{
	mlx_image_fill(self->bg, 0x00000000);
	self->icons[SCREEN_OVERLAY_ICON_PAUSE]->instances[0].enabled = false;
	self->icons[SCREEN_OVERLAY_ICON_CROSSHAIR]->instances[0].enabled = true;
}
