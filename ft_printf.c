/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:14:36 by minsunki          #+#    #+#             */
/*   Updated: 2021/03/31 15:30:39 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+' || c == ''')
		return (1);
	return (0);
}

static void		set_flag(t_cvd *cvd, char flag)
{
	if (flag == '#')
		cvd->flag |= 1;
	else if (flag == '0')
		cvd->flag |= 2;
	else if (flag == '-')
		cvd->flag |= 4;
	else if (flag == ' ')
		cvd->flag |= 8;
	else if (flag == ''')
		cvd->flag |= 16;
}

#include <stdio.h>
int				ft_printf(const char *format, ...)
{cat 
	va_list		vargs;
	char		*cvp;
	t_cvd		cvd;
	int			width;
	
	va_start(vargs, format);
	while ((cvp = ft_strchr(format, '%')))
	{
		while (is_flag(*(++cvp)))
			set_flag(&cvd, *cvp);
		width = 0;
		while (ft_isdigit(*cvp))
		{
			width = width * 10 + (*cvp - '0');
			cvp++;
		}
		cvd.width = width;
		
		printf("%s\n",cvp);
		format = cvp + 1;
	}
	va_end(vargs);
	return (0);
}
