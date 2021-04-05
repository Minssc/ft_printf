/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 21:09:33 by minsunki          #+#    #+#             */
/*   Updated: 2021/04/04 23:19:38 by minsunki         ###   ########.fr       */
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

static void ptos(unsigned long long ptr)
{
	if (ptr >= 16)
		ptos(ptr / 16);
	ft_putchar_fd("0123456789abcdef"[ptr%16], 1);
}

static int padding(char c, int len)
{
	int		ret;

	if (len <= 0)
		return (0);
	ret = len;
	while (len--)
		ft_putchar_fd(c, 1);
	return (ret);
}

int			ft_print_ptr(unsigned long long ptr, t_cvd *cvd)
{
	int		ret;
	int		pwidth;

	pwidth = get_width(ptr) + 2;
	ret = pwidth;
	if (cvd->flag & e_lalign)
	{
		ft_putstr_fd("0x", 1);
		ptos(ptr);
		ret += padding(' ', cvd->width - pwidth);
	}
	else if (cvd->flag & e_zfill)
	{
		ft_putstr_fd("0x", 1);
		ret += padding('0', cvd->width - pwidth);
		ptos(ptr);
	}
	else
	{
		ret += padding(' ', cvd->width - pwidth);
		ft_putstr_fd("0x", 1);
		ptos(ptr);
	}
	return (ret);
}
