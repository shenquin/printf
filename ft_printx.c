/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:44:25 by shenquin          #+#    #+#             */
/*   Updated: 2020/12/01 11:44:27 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_printx1(t_flag flag, long nb, int k, char *base)
{
	int i;

	i = -1;
	if (flag.acc == -1 ||
	(flag.width >= ft_16(nb) && flag.acc >= ft_16(nb)))
		ft_putnbr_base(nb, base, ft_16(nb), flag);
	if (flag.acc < ft_16(nb) && flag.acc != -1)
	{
		ft_putnbr_base(nb, base, ft_16(nb), flag);
		while (++i < flag.width - ft_16(nb))
			ft_putchar(' ');
	}
	else
		while (++i < flag.width - k)
			ft_putchar(' ');
}

static void			ft_printx2(t_flag flag, long nb, int k, char *base)
{
	int i;

	i = -1;
	if (flag.acc < ft_16(nb) && flag.acc != -1)
	{
		while (++i < flag.width - ft_16(nb))
			ft_putchar(' ');
		ft_putnbr_base(nb, base, ft_16(nb), flag);
	}
	else
		while (++i < flag.width - k)
			ft_putchar(' ');
	if ((flag.acc == -1) ||
		(flag.width >= ft_16(nb) && flag.acc >= ft_16(nb)))
		ft_putnbr_base(nb, base, ft_16(nb), flag);
}

static void			ft_printx3(t_flag flag, long nb, int k, char *base)
{
	int i;

	i = -1;
	if (flag.acc < ft_16(nb) && flag.acc != -1)
	{
		while (++i < flag.width - ft_16(nb))
			ft_putchar(' ');
		ft_putnbr_base(nb, base, ft_16(nb), flag);
	}
	else if (flag.acc != -1)
		while (++i < flag.width - k)
			ft_putchar(' ');
	else if (flag.width > flag.acc && flag.acc != -1)
		while (++i < flag.width - k - 1)
			ft_putchar(' ');
	if ((flag.acc == -1) ||
		(flag.width >= ft_16(nb) && flag.acc >= ft_16(nb)))
		ft_putnbr_base(nb, base, ft_16(nb), flag);
}

static	void		ft_padding(t_flag flag)
{
	int i;

	i = -1;
	while (++i < flag.width)
		ft_putchar(' ');
}

t_flag				ft_printx(t_flag flag, va_list args, char c)
{
	long	nb;
	int		k;
	char	*base;

	base = c == 120 ? "0123456789abcdef" : "0123456789ABCDEF";
	nb = va_arg(args, unsigned int);
	k = flag.acc >= ft_16(nb) ? flag.acc : ft_16(nb);
	if (nb == 0 && flag.acc == 0)
	{
		ft_padding(flag);
		flag.len += flag.width;
		return (flag);
	}
	if (flag.minus == 1)
		ft_printx1(flag, nb, k, base);
	if (flag.minus == 0 && flag.zero == 0)
		ft_printx2(flag, nb, k, base);
	if (flag.minus == 0 && flag.zero == 1)
		ft_printx3(flag, nb, k, base);
	if (flag.acc >= ft_16(nb) && flag.width < ft_16(nb))
		ft_putnbr_base(nb, base, ft_16(nb), flag);
	flag.len += k > flag.width ? k : flag.width;
	return (flag);
}
