/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 00:20:20 by minsunki          #+#    #+#             */
/*   Updated: 2021/04/03 17:37:37 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_char(int c, t_cvd *cvd)
{
	int		ret;

	ret = cvd->width;
	if (cvd->flag & e_lalign)
		ft_putchar_fd(c, 1);
	while (--cvd->width)
		ft_putchar_fd((cvd->flag & e_zfill ? '0' : ' '), 1);
	if (!(cvd->flag & e_lalign))
		ft_putchar_fd(c, 1);
	return (ret ? ret : 1);
}
