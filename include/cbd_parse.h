/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cbd_parse.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <dbasting@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/27 14:36:06 by dbasting      #+#    #+#                 */
/*   Updated: 2024/01/29 17:37:45 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_PARSE_H
# define CBD_PARSE_H

# include "cbd.h"
# include "types.h"

# include "MLX42.h"
# include <stdbool.h>

# define HDR_CEILING	"C"
# define HDR_FLOOR		"F"
# define HDR_NORTH_WALL	"NO"
# define HDR_EAST_WALL	"EA"
# define HDR_SOUTH_WALL	"SO"
# define HDR_WEST_WALL	"WE"
# define HDR_DOOR		"DO"

# define CHAR_WALL	'1'
# define CHAR_EMPTY	'0'
# define CHAR_VOID	' '
//# define CHAR_DOOR	'D'
//# define CHAR_COIN0	'X'

# define CHAR_NORTH	'N'
# define CHAR_WEST	'W'
# define CHAR_SOUTH	'S'
# define CHAR_EAST	'E'

typedef enum e_achkflag
{
	CEILING_RGB,
	FLOOR_RGB,
	NORTH_TXR,
	EAST_TXR,
	SOUTH_TXR,
	WEST_TXR,
	N_ACHKFLAG,
}	t_achkflag;

typedef struct s_achk
{
	bool	flags[N_ACHKFLAG];
}	t_achk;

void	achk_init(t_achk *check);
bool	achk_done(t_achk *check);

void	parse_assets(t_achk *check, t_assets *assets, char const *str);
t_rgba	parse_rgb(char const **str);
char	*parse_path(char const **str);

void	parse_skip_ws(char const **str);

#endif // CBD_PARSE_H
