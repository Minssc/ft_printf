/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:22:29 by minsunki          #+#    #+#             */
/*   Updated: 2021/04/05 16:11:11 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_width(unsigned int num, int base)
{
	int		ret;

	ret = 0;
	while (num)
	{
		num /= base;
		ret++;
	}
	return (ret);
}

#include <stdio.h>
static int	print_unbr(unsigned int num, t_cvd *cvd)
{
	int				ret;
	unsigned int	base;

	ret = 0;
	base = (cvd->type == 'u' ? 10 : 16);
	while (cvd->pwidth-- > 0)
		ft_putchar_fd('0', 1);
	if (num >= base)
		print_unbr(num / base, cvd);
	if (cvd->type == 'X')
		ft_putchar_fd("0123456789ABCDEF"[num % base], 1);
	else
		ft_putchar_fd("0123456789abcdef"[num % base], 1);
	return (ret);
}

int			ft_print_udec(unsigned int num, t_cvd *cvd)
{
	int		ret;
	int		nw;
	int		pw;
	int		base;

	base = (cvd->type == 'u' ? 10 : 16);
	nw = get_width(num, base);
	pw = (nw < cvd->pwidth ? cvd->pwidth : nw);
	ret = pw - nw;
	if (cvd->flag & e_lalign)
		ret += print_unbr(num, cvd);
	if (pw < cvd->width)
	{
		ret += cvd->width - pw;
		while (cvd->width-- - pw)
			if (cvd->flag & e_lalign || cvd->flag & e_prec)
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd((cvd->flag & e_zfill ? '0' : ' '), 1);
	}
	if (!(cvd->flag & e_lalign))
		ret += print_unbr(num, cvd);
	return (ret + nw);
}
