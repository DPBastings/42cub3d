/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbd_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:03:07 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/30 19:03:08 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_HOOK_H
# define CBD_HOOK_H

# include "cbd.h"

# include "MLX42.h"

typedef void	(*t_hookf)(void *);

void	hooks_init(t_game *game);

void	hook_controls(void *param);
void	hook_close(void *param);

#endif // CBD_HOOK_H
