/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:37:54 by minsunki          #+#    #+#             */
/*   Updated: 2021/04/12 21:43:02 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_print_str(const char *str, t_cvd *cvd)
{
	int		slen;
	int		wid;
	int		owid;
	int		nullp;

	nullp = 0;
	if (!str)
		str = "(null)";
	slen = ft_strlen(str);
	if ((cvd->flag & e_prec) && cvd->pwidth >= 0)
		slen = ft_min(cvd->pwidth, slen);
	wid = ft_max(cvd->width, slen);
	owid = wid;
	if (!(cvd->flag & e_lalign))
		wid -= ft_pad(' ', wid - slen);
	wid -= ft_nputs(str, slen);
	wid -= ft_pad(' ', wid);
	return (owid);
}
