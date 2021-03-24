/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:25:59 by minsunki          #+#    #+#             */
/*   Updated: 2021/03/24 14:30:00 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrn_fd(char *s, int fd, size_t len)
{
	size_t	slen;

	if (!s || fd < 0)
		return ;
	slen = ft_strlen(s);
	len = (slen < len ? slen : len);
	write(fd, s, len);
}
