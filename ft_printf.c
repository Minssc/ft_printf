/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:14:36 by minsunki          #+#    #+#             */
/*   Updated: 2021/03/24 17:03:59 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		pproc(const char *fmt, const char *arg)
{
	
}

int				ft_printf(const char *format, ...)
{
	va_list		vargs;
	char		*cp;
	
	va_start(vargs, format);
	while (1)
	{
		if (cp = ft_strchr(format, '%'))
		{
			ft_putstrn_fd(format, 0, cp - format);
			format = cp + 1;
		}
		else
			break;
		ft_putstr_fd(format, 0);
	}
	va_end(vargs);
}
