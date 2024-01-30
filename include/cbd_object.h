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

/**
 * @brief	Object object.
 * 			Describes an object that is placed in the game level.
 * @param	type	An enumerator denoting the object's type. Note that its
 * 					value is always taken from t_object_type: it is declared as
 * 					an unsigned char to conserve memory.
 * @param	data	Pointer to optional additional data associated with a
 * 					particular object type. Who said polymorphism can't be done
 * 					in C too?
 */
struct s_object
{
	unsigned char	type;
	void			*data;
};

void	object_init(t_object *self, t_object_type type);
void	object_deinit(t_object *self);

#endif // CBD_OBJECT_H
