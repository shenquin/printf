/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:42:54 by shenquin          #+#    #+#             */
/*   Updated: 2020/12/01 11:43:00 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_printc(t_flag flag, va_list args)
{
	int i;

	i = -1;
	if (flag.width == 1)
		ft_putchar(va_arg(args, int));
	if (flag.minus == 0 && flag.width != 1)
	{
		while (++i < flag.width - 1)
			ft_putchar(' ');
		ft_putchar(va_arg(args, int));
	}
	else if (flag.minus == 1 && flag.width != 1)
	{
		ft_putchar(va_arg(args, int));
		while (++i < flag.width - 1)
			ft_putchar(' ');
	}
	flag.len += flag.width == 0 ? 1 : flag.width;
	return (flag);
}
