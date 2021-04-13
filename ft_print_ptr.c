/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 21:09:33 by minsunki          #+#    #+#             */
/*   Updated: 2021/04/13 15:34:10 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_width(unsigned long long ptr)
{
	int		ret;

	ret = 0;
	while (ptr)
	{
		ret++;
		ptr /= 16;
	}
	return (ret ? ret : 1);
}

static int	putptr(unsigned long long ptr)
{
	int		ret;

	ret = 0;
	if (ptr >= 16)
		ret += putptr(ptr / 16);
	ft_putc("0123456789abcdef"[ptr % 16]);
	return (1 + ret);
}

int			ft_print_ptr(unsigned long long ptr, t_cvd *cvd)
{
	const int	nw = get_width(ptr);
	int			wid;
	int			owid;
	int			pw;

	wid = ft_max(ft_max(cvd->pwidth + 2, cvd->width), nw + 2);
	pw = 2 + nw;
	if (!(cvd->flag & e_lalign) && (cvd->flag & e_zfill))
		pw = wid;
	if ((cvd->flag & e_prec) && (cvd->pwidth >= 0))
		pw = ft_max(cvd->pwidth, nw) + 2;
	if (!ptr && (cvd->flag & e_prec) && !cvd->pwidth)
	{
		wid = ft_max(2, cvd->width);
		pw = 2;
	}
	owid = wid;
	if (!(cvd->flag & e_lalign))
		wid -= ft_pad(' ', wid - pw);
	wid -= ft_nputs("0x", 2);
	wid -= ft_pad('0', pw - nw - 2);
	if (pw != 2)
		wid -= putptr(ptr);
	wid -= ft_pad(' ', wid);
	return (owid);
}
