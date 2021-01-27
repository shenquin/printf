/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:43:51 by shenquin          #+#    #+#             */
/*   Updated: 2021/01/27 12:45:36 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printp2(t_flag flag, int i, unsigned long int nb)
{
	while (++i < flag.width - ft_16(nb) - 2)
		ft_putchar(' ');
	write(1, "0x", 2);
}

void	ft_printp1(t_flag flag, int i, unsigned long int nb, char *base)
{
	if (flag.width - 1 < ft_16(nb))
	{
		write(1, "0x", 2);
		ft_putnbr_base(nb, base, ft_16(nb), flag);
	}
	if (flag.width > ft_16(nb) && flag.minus == 0)
	{
		ft_printp2(flag, i, nb);
		ft_putnbr_base(nb, base, ft_16(nb), flag);
	}
	else if (flag.minus == 1 && flag.width > ft_16(nb))
	{
		write(1, "0x", 2);
		ft_putnbr_base(nb, base, ft_16(nb), flag);
		while (++i < flag.width - ft_16(nb) - 2)
			ft_putchar(' ');
	}
}

t_flag	ft_printp(t_flag flag, va_list args)
{
	int					i;
	unsigned long int	nb;
	char				*base;

	i = -1;
	base = "0123456789abcdef";
	nb = va_arg(args, long);
	if (nb == 0 && flag.acc == 0)
	{
		if (flag.width > 2)
		{
			while (++i < flag.width - 2)
			{
				ft_putchar(' ');
				flag.len++;
			}
		}
		ft_putstr("0x");
		flag.len += 2;
		return (flag);
	}
	ft_printp1(flag, i, nb, base);
	flag.len += flag.width > ft_16(nb) ? flag.width : ft_16(nb) + 2;
	flag.len += flag.width == ft_16(nb) + 1 ? 1 : 0;
	return (flag);
}
