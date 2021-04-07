/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 18:02:34 by minsunki          #+#    #+#             */
/*   Updated: 2021/04/07 15:58:34 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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

static void	print_nbr(long long num, int prec)
{
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		while (prec--)
			ft_putchar_fd('0', 1);
		print_nbr(-num, 0);
	}
	else 
	{
		while (prec--)
			ft_putchar_fd('0', 1);
		if (num >= 10)
			print_nbr(num / 10, 0);
		ft_putchar_fd('0' + num % 10, 1);
	}
}

int			ft_print_dec(int num, t_cvd *cvd)
{
	int		ret;
	int		nw;
	int		pw;

	nw = get_width(num);
	pw = (nw < cvd->pwidth ? cvd->pwidth : nw);
	ret = pw - nw;
	if (cvd->flag & e_lalign)
		print_nbr(num, pw - nw);
	if (pw < cvd->width)
	{
		ret += cvd->width - pw;
		while (cvd->width-- -pw - (num < 0))
			if (cvd->flag & e_lalign || (cvd->flag & e_prec && cvd->pwidth > 0))
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd((cvd->flag & e_zfill && num >= 0 ? '0' : ' '), 1);
	}
	if (!(cvd->flag & e_lalign))
		print_nbr(num, pw - nw);

	return (ret + nw);
}
