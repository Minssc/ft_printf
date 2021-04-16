/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 00:20:20 by minsunki          #+#    #+#             */
/*   Updated: 2021/04/16 16:28:35 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_char(int c, t_cvd *cvd)
{
	int		wid;
	int		owid;

	wid = (cvd->width ? cvd->width : 1);
	owid = wid;
	if (!(cvd->flag & e_lalign))
		wid -= ft_pad((cvd->flag & e_zfill ? '0' : ' '), wid - 1);
	wid -= ft_putc(c);
	wid -= ft_pad(' ', wid);
	return (owid);
}
