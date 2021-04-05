/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:37:54 by minsunki          #+#    #+#             */
/*   Updated: 2021/04/05 16:10:26 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_str(const char *str, t_cvd *cvd)
{
	int		ret;
	int		slen;

	slen = ft_strlen(str);
	slen = (cvd->pwidth < slen ? cvd->pwidth : slen);
	ret = 0;
	if (cvd->flag & e_lalign)
		ret += ft_nputs(str, (cvd->flag & e_prec ? cvd->pwidth : -1));
	if (slen < cvd->width)
	{
		ret += cvd->width - slen;
		while (cvd->width-- - slen)
			ft_putchar_fd(' ', 1);
	}
	if (!(cvd->flag & e_lalign))
		ret += ft_nputs(str, (cvd->flag & e_prec ? cvd->pwidth : -1));
	return (ret);
}
