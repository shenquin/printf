/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:44:00 by shenquin          #+#    #+#             */
/*   Updated: 2020/12/01 11:44:02 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_printpercent(t_flag flag)
{
	int i;

	i = -1;
	if (flag.width <= 1)
		ft_putchar('%');
	if (flag.minus == 0 && flag.width > 1)
	{
		while (++i < flag.width - 1)
			flag.zero == 0 ? ft_putchar(' ') : ft_putchar('0');
		ft_putchar('%');
	}
	else if (flag.minus == 1 && flag.width > 1)
	{
		ft_putchar('%');
		while (++i < flag.width - 1)
			flag.zero == 0 ? ft_putchar(' ') : ft_putchar('0');
	}
	flag.len += flag.width == 0 ? 1 : flag.width;
	return (flag);
}
