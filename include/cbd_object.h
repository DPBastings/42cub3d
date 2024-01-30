/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_object.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 16:58:07 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 17:03:21 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_OBJECT_H
# define CBD_OBJECT_H

# include "cbd.h"

typedef enum e_object_type
{
	OBJ_VOID = 0,
	OBJ_EMPTY,
	OBJ_WALL,
	N_OBJECT_TYPE,
}	t_object_type;

struct s_object
{
	unsigned char	type;
	void			*data;
};

void	object_init(t_object *self, t_object_type type);
void	object_deinit(t_object *self);

#endif // CBD_OBJECT_H
