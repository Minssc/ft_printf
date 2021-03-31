/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:14:45 by minsunki          #+#    #+#             */
/*   Updated: 2021/03/31 15:30:43 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef struct	s_cvd
{
	int			flags;
	int			width;
	int			type;
	void		*data;
}				t_cvd;

int				ft_printf(const char *format, ...);

#endif
