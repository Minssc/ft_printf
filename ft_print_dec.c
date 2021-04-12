/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:02:34 by minsunki          #+#    #+#             */
/*   Updated: 2021/04/12 20:54:19 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_width(long long num)
{
	num = (num < 0 ? -num : num);
	if (num < 10)
		return (1);
	else if (num < 100)
		return (2);
	else if (num < 1000)
		return (3);
	else if (num < 10000)
		return (4);
	else if (num < 100000)
		return (5);
	else if (num < 1000000)
		return (6);
	else if (num < 10000000)
		return (7);
	else if (num < 100000000)
		return (8);
	else if (num < 1000000000)
		return (9);
	else
		return (10);
}

static int	putnbr(long long num)
{
	int		ret;

	ret = 0;
	if (num >= 10)
		ret += putnbr(num / 10);
	return (1 + ret);
}

int			ft_print_dec(long long num, t_cvd *cvd)
{
	const int	nw = get_width(num);
	int			wid;
	int			owid;
	int			pw;

	wid = ft_max(ft_max(cvd->pwidth + (num < 0), cvd->width), nw + (num < 0));
	owid = wid;
	pw = nw + (num < 0);
	if (!(cvd->flag & e_lalign) && (cvd->flag & e_zfill))
		pw = wid;
	if ((cvd->flag & e_prec) && cvd->pwidth >= 0)
		pw = ft_max(cvd->pwidth, nw) + (num < 0);
	if (!(cvd->flag & e_lalign))
		wid -= ft_pad(' ', wid - pw);
	if (num < 0)
		wid -= ft_putc('-');
	wid -= ft_pad('0', pw - nw - (num < 0));
	if (!num && ((cvd->flag & e_prec) && !cvd->pwidth))
	{
		wid -= (cvd->width ? ft_pad(' ', wid) : 0);
		return (cvd->width);
	}
	wid -= putnbr(num < 0 ? -num : num);
	wid -= ft_pad(' ', wid);
	return (owid);
}
