/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:14:36 by minsunki          #+#    #+#             */
/*   Updated: 2021/03/24 13:47:40 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		args_parser(const char *fmt)
{
	
}

int				ft_printf(const char *format, ...)
{
	va_list		vargs;
	
	va_start(vargs, format);
	while (*format)
	{
		if (*format == '%')
			
		format++;
	}
	va_end(vargs);
}
