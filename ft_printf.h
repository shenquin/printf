/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:43:38 by shenquin          #+#    #+#             */
/*   Updated: 2020/12/01 11:43:43 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

typedef struct	s_flag
{
	int	minus;
	int	zero;
	int	width;
	int	acc;
	int	i;
	int	len;
}				t_flag;

int				ft_printf(const char *s, ...);
t_flag			ft_parsing(const char *s, t_flag flag, va_list args);
t_flag			ft_set_truct(void);
t_flag			ft_update_flag(char *s, t_flag flag, va_list args);
t_flag			ft_prints(t_flag flag, va_list args);
t_flag			ft_printc(t_flag flag, va_list args);
t_flag			ft_printd(t_flag flag, va_list args);
t_flag			ft_len_s(t_flag flag, char *str);
t_flag			ft_printx(t_flag flag, va_list args, char c);
t_flag			ft_printu(t_flag flag, va_list args);
t_flag			ft_printp(t_flag flag, va_list args);
t_flag			ft_printpercent(t_flag flag);
t_flag			ft_verif(t_flag flag);
int				ft_16(unsigned long int nb);
void			ft_putnbr_base(unsigned long nb,
				char *base, int len, t_flag flag);
void			ft_putnbr(long long nb, int prec, int len, t_flag flag);
int				ft_len(char *s);
int				ft_atoi(char *s);
int				ft_isdigit(char c);
int				ft_lgth(long int nb);
void			ft_putchar(char c);
void			ft_putstr(char *s);
void			ft_putnstr(char *s, int n);

#endif
