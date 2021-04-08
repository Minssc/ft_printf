/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:02:34 by minsunki          #+#    #+#             */
/*   Updated: 2021/04/09 01:14:07 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	g_nw;

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
/*
static int print_pad(int num, t_cvd *cvd)
{
	int		ret;
	int		pw;

	ret = 0;
	if ((cvd->flag & e_zfill) && !(cvd->flag & e_prec) && (num < 0))
		return (0);
	pw = cvd->width - (cvd->pwidth < g_nw ? g_nw : cvd->pwidth) - (num < 0);
	while (pw-- > 0)
	{
		if (cvd->flag & e_prec || (num < 0))
			ft_putchar_fd(' ', 1);
		else
			ft_putchar_fd((cvd->flag & e_zfill ? '0' : ' '), 1);
		ret++;
	}
	return (ret);
}
*/
static int putnbr(long long num)
{
	int 	ret;

	ret = 0;
	if (num >= 10)
		ret += putnbr(num / 10);
	ft_putchar_fd('0' + num % 10, 1);
	return (ret + 1);
}
/*
static int	print_nbr(long long num, t_cvd *cvd)
{
	int		ret;
	int		pw;

	ret = 0;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		ret++;
	}

	if ((cvd->flag & e_prec) || (num < 0))
	{
		pw = ft_max(cvd->pwidth - g_nw, cvd->width - g_nw - (num < 0));
		ret += (pw > 0 ? pw : 0);
		while (pw-- > 0)
			ft_putchar_fd('0', 1);
	}
	ret += putnbr(num < 0 ? -num : num);
	return (ret);
}
*/
static int ppad(char c, int len)
{
	int		ret;

	ret = 0;
	while (len-- > 0)
		ret += ft_putc(c);
	return (ret);
}

int			ft_print_dec(long long num, t_cvd *cvd)
{
	int		wid;

	g_nw = get_width(num);
	wid = ft_max(ft_max(cvd->pwidth + (num < 0), cvd->width), g_nw + (num < 0));
	if (cvd->flag & e_lalign)
	{
		if (num < 0)
			wid -= ft_putc('-');
		if (cvd->flag & e_prec)
			wid -= ppad('0', cvd->pwidth - g_nw);
		if (!num && !cvd->pwidth)
		{
			if (cvd->width)
				wid -= ppad(' ', wid);
			return (cvd->width);
		}
		wid -= putnbr(num < 0 ? -num : num);
		wid -= ppad(' ', wid);
	}
	else
	{
		if (cvd->pwidth)
			wid -= ppad(((cvd->flag & e_zfill) && !(cvd->flag & e_prec) && (num > 0) ? '0' : ' '), wid - ft_max(cvd->pwidth, g_nw) - (num < 0));
		if (num < 0)
			wid -= ft_putc('-');
		if (num == 0 && !cvd->pwidth)
		{
			if (cvd->width)
				wid -= ppad(' ', wid);
			return (cvd->width);
		}
		if (cvd->flag & e_zfill)
			wid -= ppad('0', wid - g_nw);
		wid -= putnbr(num < 0 ? -num : num);
	}
	return (ft_max(ft_max(cvd->pwidth + (num < 0), cvd->width), g_nw + (num < 0)));
}
