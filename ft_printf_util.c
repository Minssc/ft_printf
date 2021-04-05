/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 00:15:10 by minsunki          #+#    #+#             */
/*   Updated: 2021/04/05 00:17:11 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_nputs(const char *str, size_t len)
{
	size_t	slen;

	if (!str || !len)
		return (0);
	slen = ft_strlen(str);
	write(1, str, (slen < len ? slen : len));
	return (slen < len ? slen : len);
}
