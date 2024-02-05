/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_view.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/05 17:32:02 by dbasting      #+#    #+#                 */
/*   Updated: 2024/02/05 17:33:00 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_VIEW_H
# define CBD_VIEW_H

struct s_view
{
	mlx_image_t	*ceiling;
	mlx_image_t	*floor;
	mlx_image_t	*scene;
}

#endif // CBD_VIEW_H