#include "cbd_parse.h"

#include "ft_ctype.h"

void	parse_skip_ws(char const **str)
{
	while (ft_isspace(**str))
		++*str;
}
