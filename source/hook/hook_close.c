/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook_close.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 20:10:49 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/16 16:34:07 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_hook.h"

void	hook_close(void *param)
{
	mlx_t *const	mlx = param;

	mlx_close_window(mlx);
}
