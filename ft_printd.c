/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:43:18 by shenquin          #+#    #+#             */
/*   Updated: 2020/12/01 11:43:31 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printd1(t_flag flag, int len, int nb, int k)
{
	int i;

	i = -1;
	if (flag.acc == -1 ||
	(flag.width > len && flag.acc >= len))
		ft_putnbr(nb, flag.acc, ft_lgth(nb), flag);
	if (flag.acc < len && flag.acc != -1)
	{
		ft_putnbr(nb, flag.acc, ft_lgth(nb), flag);
		while (++i < flag.width - len)
			ft_putchar(' ');
	}
	else if ((nb < 0 && flag.acc == -1) || nb >= 0)
		while (++i < flag.width - k)
			ft_putchar(' ');
	else
		while (++i < flag.width - k - 1)
			ft_putchar(' ');
}

static void	ft_printd2(t_flag flag, int nb, int k)
{
	int i;

	i = -1;
	if (flag.acc < ft_lgth(nb) && flag.acc != -1)
	{
		while (++i < flag.width - ft_lgth(nb))
			ft_putchar(' ');
		ft_putnbr(nb, flag.acc, ft_lgth(nb), flag);
	}
	else if ((nb < 0 && flag.acc == -1) || nb >= 0)
		while (++i < flag.width - k)
			ft_putchar(' ');
	else
		while (++i < flag.width - k - 1)
			ft_putchar(' ');
	if ((flag.acc == -1) ||
		(flag.width > ft_lgth(nb) && flag.acc >= ft_lgth(nb)))
		ft_putnbr(nb, flag.acc, ft_lgth(nb), flag);
}

static void	ft_printd3(t_flag flag, int nb, int k)
{
	int i;

	i = -1;
	if (flag.acc < ft_lgth(nb) && flag.acc != -1)
	{
		while (++i < flag.width - ft_lgth(nb))
			ft_putchar(' ');
		ft_putnbr(nb, flag.acc, ft_lgth(nb), flag);
	}
	else if ((nb < 0 && flag.acc == -1 && flag.zero == 0) ||
		(nb >= 0 && flag.acc != -1))
		while (++i < flag.width - k)
			ft_putchar(' ');
	else if (flag.width > flag.acc && flag.acc != -1)
		while (++i < flag.width - k - 1)
			ft_putchar(' ');
	if ((flag.acc == -1) ||
		(flag.width > ft_lgth(nb) && flag.acc >= ft_lgth(nb)))
		ft_putnbr(nb, flag.acc, ft_lgth(nb), flag);
}

int			ft_pad(t_flag flag, int i)
{
	while (++i < flag.width)
		ft_putchar(' ');
	return (i);
}

t_flag		ft_printd(t_flag flag, va_list args)
{
	int nb;
	int i;
	int k;

	i = -1;
	nb = va_arg(args, int);
	k = flag.acc >= ft_lgth(nb) ? flag.acc : ft_lgth(nb);
	if (nb == 0 && flag.acc == 0)
	{
		ft_pad(flag, i);
		flag.len += flag.width;
		return (flag);
	}
	if (flag.minus == 1)
		ft_printd1(flag, ft_lgth(nb), nb, k);
	if (flag.minus == 0 && flag.zero == 0)
		ft_printd2(flag, nb, k);
	if (flag.minus == 0 && flag.zero == 1)
		ft_printd3(flag, nb, k);
	if (flag.acc >= ft_lgth(nb) && flag.width <= ft_lgth(nb))
		ft_putnbr(nb, flag.acc, ft_lgth(nb), flag);
	flag.len += k > flag.width ? k : flag.width;
	if (flag.acc >= flag.width && nb < 0 && flag.acc >= ft_lgth(nb))
		flag.len++;
	return (flag);
}
