/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsunki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:14:45 by minsunki          #+#    #+#             */
/*   Updated: 2021/04/12 20:53:07 by minsunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef enum
{
	e_aform = 0,
	e_zfill = 1,
	e_lalign = 1 << 1,
	e_space = 1 << 2,
	e_sign = 1 << 3,
	e_prec = 1 << 4,
	e_dec = 1 << 5
}	t_flag;

typedef struct	s_cvd
{
	t_flag		flag;
	int			width;
	int			pwidth;
	char		type;
	void		*data;
}				t_cvd;

int				ft_printf(const char *format, ...);
int				ft_print_char(int c, t_cvd *cvd);
int				ft_print_str(const char *str, t_cvd *cvd);
int				ft_print_ptr(unsigned long long ptr, t_cvd *cvd);
int				ft_print_dec(long long num, t_cvd *cvd);
int				ft_print_udec(unsigned int num, t_cvd *cvd);

int				ft_nputs(const char *str, size_t len);
int				ft_putc(const char c);
int				ft_max(const int a, const int b);
int				ft_min(const int a, const int b);
int				ft_pad(char c, int len);

#endif
