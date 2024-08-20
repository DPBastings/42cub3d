/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/28 23:08:19 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/20 13:40:09 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>



typedef struct s_string
{
	char const	*data;
	size_t		len;
}	t_string;

#endif // UTILS_H
