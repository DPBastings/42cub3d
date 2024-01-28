/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:29 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/27 14:35:30 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_parse.h"

#include "ft_ctype.h"

void	parse_skip_ws(char const **str)
{
	while (ft_isspace(**str))
		++*str;
}
