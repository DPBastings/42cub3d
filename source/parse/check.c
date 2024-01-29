/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 16:49:28 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 14:50:15 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_parse.h"

#include "ft_string.h"

void	achk_init(t_achk *check)
{
	ft_memset(&check, 0, sizeof(t_achk));
}

bool	achk_done(t_achk *check)
{
	size_t	i;

	i = 0;
	while (i < N_ACHKFLAG)
		if (check->flags[i++] == false)
			return (false);
	return (true);
}
