/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbd_error.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbasting <dbasting@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:35:50 by dbasting          #+#    #+#             */
/*   Updated: 2024/01/27 14:35:51 by dbasting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CBD_ERROR_H
# define CBD_ERROR_H

typedef enum e_errno
{
	CBD_SUCCESS = 0,
	CBD_EGENERIC,
	CBD_EARGC,
	CBD_EFILEEXT,
	CBD_EASSINV,
	CBD_EASSDOUBLE,
	CBD_EMAPINVOBJ,
	CBD_EMAPWALL,
	CBD_EMAPMISSINGSTART,
	CBD_EMAPDOUBLESTART,
	N_ERRNO,
}	t_errno;

void	cbd_strerror(t_errno err);
void	cbd_terminate(t_errno err);

#endif // CBD_ERROR_H
