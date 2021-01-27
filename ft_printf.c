/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:43:25 by shenquin          #+#    #+#             */
/*   Updated: 2020/12/01 11:43:28 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag		ft_parsing(const char *s, t_flag flag, va_list args)
{
	if (s[flag.i] == '%' && s[flag.i + 1])
		flag = ft_update_flag((char *)s, flag, args);
	if (s[flag.i] == '%')
		flag = ft_printpercent(flag);
	if (s[flag.i] == 'c')
		flag = ft_printc(flag, args);
	if (s[flag.i] == 's')
		flag = ft_prints(flag, args);
	if (s[flag.i] == 'd' || s[flag.i] == 'i')
		flag = ft_printd(flag, args);
	if (s[flag.i] == 'u')
		flag = ft_printu(flag, args);
	if (s[flag.i] == 'x' || s[flag.i] == 'X')
		flag = ft_printx(flag, args, s[flag.i]);
	if (s[flag.i] == 'p')
		flag = ft_printp(flag, args);
	flag.minus = 0;
	flag.zero = 0;
	flag.width = 0;
	flag.acc = -1;
	return (flag);
}

t_flag		ft_update_flag(char *s, t_flag flag, va_list args)
{
	while (s[++flag.i] == '-' || s[flag.i] == '0')
	{
		if (s[flag.i] == '-')
			flag.minus = 1;
		if (s[flag.i] == '0')
			flag.zero = 1;
	}
	if (flag.minus == 1)
		flag.zero = 0;
	flag.width = s[flag.i] == '*' ? va_arg(args, int) : ft_atoi(s + flag.i);
	while ((s[flag.i] >= '0' && s[flag.i] <= '9') || s[flag.i] == '*')
		flag.i++;
	if (s[flag.i] == '.')
		flag.acc = s[flag.i + 1] == '*' ? va_arg(args, int) :
	ft_atoi(s + flag.i + 1);
	flag = ft_verif(flag);
	while (ft_isdigit(s[flag.i]) || s[flag.i] == '*' || s[flag.i] == '.')
		flag.i++;
	return (flag);
}

t_flag		ft_set_struct(void)
{
	t_flag flag;

	flag.minus = 0;
	flag.zero = 0;
	flag.width = 0;
	flag.acc = -1;
	flag.i = 0;
	flag.len = 0;
	return (flag);
}

int			ft_printf(const char *s, ...)
{
	va_list args;
	t_flag	flag;

	va_start(args, s);
	flag = ft_set_struct();
	while (s[flag.i])
	{
		while (s[flag.i] && s[flag.i] != '%')
		{
			ft_putchar(s[flag.i++]);
			flag.len++;
		}
		if (s[flag.i] == '%')
			flag = ft_parsing(s, flag, args);
		if (s[flag.i] == 0)
			break ;
		flag.i++;
	}
	va_end(args);
	return (flag.len);
}
