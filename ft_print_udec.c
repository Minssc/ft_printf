/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:22:29 by minsunki          #+#    #+#             */
/*   Updated: 2021/04/13 15:47:39 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_width(unsigned int num, int hex)
{
	const int	base = (hex ? 16 : 10);
	int			ret;

	ret = 0;
	while (num)
	{
		num /= base;
		ret++;
	}
	return (ret ? ret : 1);
}

static int	putunbr(unsigned int num, int hex)
{
	const int	base = (hex ? 16 : 10);
	int			ret;

	ret = 0;
	if (num >= base)
		ret += putunbr(num / base, hex);
	if (hex == 2)
		ft_putc("0123456789ABCDEF"[num % base]);
	else
		ft_putc("0123456789abcdef"[num % base]);
	return (1 + ret);
}

int			ft_print_udec(unsigned int num, t_cvd *cvd)
{
	const int	hex = !(cvd->type == 'u') + (cvd->type == 'X');
	const int	nw = get_width(num, hex);
	int			wid;
	int			owid;
	int			pw;

	wid = ft_max(ft_max(cvd->pwidth, cvd->width), nw);
	owid = wid;
	pw = nw;
	if (!(cvd->flag & e_lalign) && (cvd->flag & e_zfill))
		pw = wid;
	if ((cvd->flag & e_prec) && cvd->pwidth >= 0)
		pw = ft_max(cvd->pwidth, nw);
	if (!(cvd->flag & e_lalign))
		wid -= ft_pad(' ', wid - pw);
	wid -= ft_pad('0', pw - nw);
	if (!num && ((cvd->flag & e_prec) && !cvd->pwidth))
	{
		wid -= (cvd->width ? ft_pad(' ', wid) : 0);
		return (cvd->width);
	}
	wid -= putunbr(num, hex);
	wid -= ft_pad(' ', wid);
	return (owid);
}
