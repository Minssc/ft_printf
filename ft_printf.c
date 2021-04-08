/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:14:36 by minsunki          #+#    #+#             */
/*   Updated: 2021/04/08 20:23:02 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		read_flag_width(char **fstr, t_cvd *cvd, va_list *va)
{
	cvd->flag = 0;
	cvd->width = 0;
	while (**fstr == '-' || **fstr == '0' || (**fstr == '*' && !(cvd->width)))
	{
		if (**fstr == '-')
			cvd->flag |= e_lalign;
		else if (**fstr == '0')
			cvd->flag |= e_zfill; 
		else if (**fstr == '*')
		{
			cvd->width = va_arg(*va, int);
			if (cvd->width < 0)
			{
				cvd->width = -cvd->width;
				cvd->flag |= e_lalign;
			}
		}
		(*fstr)++;
	}
}

static void		read_width_prec(char **fstr, t_cvd *cvd, va_list *va)
{
	cvd->pwidth = 0;
	if (!cvd->width)
		while (ft_isdigit(**fstr))
			cvd->width = cvd->width * 10 + (*(*fstr)++ - '0');
	if (**fstr != '.')
		return ;
	cvd->flag |= e_prec;
	if (*(*fstr + 1) == '*')
	{
		cvd->pwidth = va_arg(*va, int);
		if (cvd->pwidth < 0)
			cvd->pwidth = 0;
		(*fstr) += 2;
		return ;
	}
	while (ft_isdigit(*(++(*fstr))))
		cvd->pwidth= cvd->pwidth* 10 + (**fstr - '0');
}

static int		valid_conv(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
		c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static int		do_print(t_cvd *cvd, va_list *va)
{
	if (cvd->type == 'c')
		return (ft_print_char(va_arg(*va, int), cvd));
	else if (cvd->type == 's')
		return (ft_print_str(va_arg(*va, char *), cvd));
	else if (cvd->type == 'p')
		return (ft_print_ptr(va_arg(*va, unsigned long long), cvd));
	else if (cvd->type == 'd' || cvd->type == 'i')
		return (ft_print_dec(va_arg(*va, int), cvd));
	else if (cvd->type == 'u' || cvd->type == 'x' || cvd->type == 'X')
		return (ft_print_udec(va_arg(*va, int), cvd));
	return (0);
}

int				ft_printf(const char *format, ...)
{ 
	va_list		vargs;
	char		*cvp;
	t_cvd		cvd;
	int			ret;
	
	ret = 0;
	va_start(vargs, format);
	while ((cvp = ft_strchr(format, '%')))
	{
		ret += ft_nputs(format, cvp - format);
//		ft_putstrn_fd((char *)format, 1, cvp - format);
//		ret += (int)(cvp - format);
		//printf("$\n");
		format = cvp++;
		//printf("ostr: %s\n", format);
		read_flag_width(&cvp, &cvd, &vargs);
		read_width_prec(&cvp, &cvd, &vargs);
		cvd.type = *cvp++;
		
		//printf("width: %d\n", cvd.width);
		//printf("precision: %d\n", cvd.precision);
		//printf("string left: %s\n", cvp);
		if (!valid_conv(cvd.type))
			ret += ft_nputs(format, cvp - format);
//			ft_putstrn_fd((char *)format, 0, cvp - format);
		else
			ret += do_print(&cvd, &vargs);
		format = cvp;
	}
	ret += ft_nputs(format, cvp - format);
//	ft_putstr_fd((char *)format, 1);
	va_end(vargs);
	return (ret);
}
