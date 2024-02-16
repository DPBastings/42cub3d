/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_hook.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 19:03:07 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/16 16:31:15 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_HOOK_H
# define CBD_HOOK_H

# include "cbd.h"

# include "MLX42.h"

typedef void	(*t_hookf)(void *);

void	hooks_init(t_game *game);

void	hook_close(void *param);
void	hook_controls(void *param);
void	hook_render(void *param);

void	hook_cursor_turn(double xpos, double ypos, void *param);
void	hook_key_esc(mlx_key_data_t keydata, void *param);
void	hook_scroll_zoom(double xdelta, double ydelta, void *param);

#endif // CBD_HOOK_H
