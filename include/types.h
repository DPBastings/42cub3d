/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   types.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:36:20 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 17:00:29 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdint.h>

typedef int			t_fd;
typedef uint32_t	t_rgba;
typedef uint8_t		t_channel;

typedef enum e_compass_direction
{
	DIR_EAST = 0,
	DIR_SOUTH,
	DIR_WEST,
	DIR_NORTH,
	N_COMPASS,
}	t_compass_direction;

#endif // TYPES_H
