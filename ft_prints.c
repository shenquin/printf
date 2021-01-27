/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:44:08 by shenquin          #+#    #+#             */
/*   Updated: 2020/12/01 11:44:10 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prints1(t_flag flag, char *str)
{
	int i;

	i = -1;
	if (flag.acc == -1 ||
		(flag.width > ft_len(str) && flag.acc >= ft_len(str)))
		ft_putstr(str);
	if (flag.acc < ft_len(str) && flag.acc != -1)
	{
		ft_putnstr(str, flag.acc);
		while (++i < flag.width - flag.acc)
			ft_putchar(' ');
	}
	else
	{
		while (++i < flag.width - ft_len(str))
			ft_putchar(' ');
	}
}

void	ft_prints2(t_flag flag, char *str)
{
	int i;

	i = -1;
	if (flag.acc < ft_len(str) && flag.acc != -1)
	{
		while (++i < flag.width - flag.acc)
			ft_putchar(' ');
		ft_putnstr(str, flag.acc);
	}
	else
	{
		while (++i < flag.width - ft_len(str))
			ft_putchar(' ');
	}
	if ((flag.acc == -1) ||
		(flag.width > ft_len(str) && flag.acc >= ft_len(str)))
		ft_putstr(str);
}

t_flag	ft_prints(t_flag flag, va_list argp)
{
	char	*str;

	str = va_arg(argp, void *);
	if (!str)
		str = "(null)";
	if (flag.minus == 1 && str)
		ft_prints1(flag, str);
	if (flag.minus == 0 && str)
		ft_prints2(flag, str);
	if (flag.acc >= ft_len(str) && flag.width <= ft_len(str))
		ft_putstr(str);
	flag = ft_len_s(flag, str);
	return (flag);
}
