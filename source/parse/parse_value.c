/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_value.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:35:34 by dbasting      #+#    #+#                 */
/*   Updated: 2024/08/29 14:49:41 by tim           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cbd_parse.h"
#include "cbd_error.h"

#include "ft_ctype.h"
#include "ft_stdlib.h"
#include "ft_string.h"

static inline t_channel	parse_channel(char const **str);

t_rgba	parse_rgb(char const **str)
{
	t_channel	rgb[4];

	rgb[3] = parse_channel(str);
	if (*(*str)++ != ',')
		cbd_terminate(CBD_EASSINV);
	rgb[2] = parse_channel(str);
	if (*(*str)++ != ',')
		cbd_terminate(CBD_EASSINV);
	rgb[1] = parse_channel(str);
	rgb[0] = 255;
	return (*(t_rgba *)rgb);
}

static inline t_channel	parse_channel(char const **str)
{
	char	buf[4];
	size_t	i;
	int		result;

	i = 0;
	while (ft_isdigit((*str)[i]) && i < 3)
	{
		buf[i] = (*str)[i];
		++i;
	}
	buf[i] = '\0';
	*str += i;
	result = ft_atoi(buf);
	if (result > 255)
		cbd_terminate(CBD_EASSINV);
	return ((t_channel)result);
}

char	*parse_path(char const **str)
{
	size_t const	len = ft_wordlen(*str);
	char *const		sstr = ft_substr(*str, 0, len);

	if (sstr == NULL)
		cbd_terminate(CBD_EGENERIC);
	*str += len;
	return (sstr);
}
