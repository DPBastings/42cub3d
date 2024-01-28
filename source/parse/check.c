/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:49:28 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/27 16:49:29 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_parse.h"

#include "ft_string.h"

void	check_init(t_check *check)
{
	ft_memset(&check, 0, sizeof(t_check));
}

bool	check_done(t_check *check)
{
	size_t	i;

	i = 0;
	while (i < N_ASSET)
		if (check->flags[i++] == false)
			return (false);
	return (true);
}
