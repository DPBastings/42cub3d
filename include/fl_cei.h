/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fl_cei.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tim <tim@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/29 17:12:11 by tim           #+#    #+#                 */
/*   Updated: 2024/03/29 18:06:33 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FL_CEI_H
# define FL_CEI_H

# include "cbd.h"
# include "cbd_game.h"
# include "libft.h"
# include "cbd_screen.h"
# include "cbd_rc.h"
# include "point.h"
# include "MLX42_ext.h"
# include <stdlib.h>

void	init_flcei(t_game *self);
void	rc_flcei(t_game *self);

#endif