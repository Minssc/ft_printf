/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 00:20:20 by minsunki          #+#    #+#             */
/*   Updated: 2021/04/12 19:11:33 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_print_char(int c, t_cvd *cvd)
{
	int		ret;

	ret = cvd->width;
	if (cvd->flag & e_lalign)
		ft_putchar_fd(c, 1);
	while (--cvd->width > 0)
		ft_putchar_fd(' ', 1);
	if (!(cvd->flag & e_lalign))
		ft_putchar_fd(c, 1);
	return (ret ? ret : 1);
}
