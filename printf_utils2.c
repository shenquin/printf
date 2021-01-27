/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:44:52 by shenquin          #+#    #+#             */
/*   Updated: 2020/12/01 11:44:54 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbr(long long nb, int acc, int len, t_flag flag)
{
	long int	nbr;
	long int	mod;
	long int	div;

	nbr = nb;
	if (acc == -1 && flag.width)
		acc = nbr >= 0 ? flag.width : flag.width - 1;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
		len--;
	}
	if (flag.acc != -1 ||
		(flag.acc == -1 && flag.width > ft_lgth(nb) && flag.zero))
		while (acc > len)
		{
			ft_putchar('0');
			acc--;
		}
	mod = nbr % 10;
	div = nbr / 10;
	if (div)
		ft_putnbr(div, acc, len, flag);
	ft_putchar(mod + 48);
}

int			ft_16(unsigned long int nb)
{
	if (nb > 15)
		return (1 + ft_16(nb / 16));
	return (1);
}

void		ft_putnbr_base(unsigned long nbr, char *base, int len, t_flag flag)
{
	long long int	div;
	long long int	mod;

	if (flag.acc != -1)
		while (flag.acc > len)
		{
			ft_putchar('0');
			flag.acc--;
		}
	if (flag.acc == -1 && flag.width >= ft_16(nbr) && flag.zero)
		while (flag.width > len)
		{
			ft_putchar('0');
			flag.width--;
		}
	mod = nbr % 16;
	div = nbr / 16;
	if (div)
		ft_putnbr_base(div, base, len, flag);
	ft_putchar(base[mod]);
}

t_flag		ft_verif(t_flag flag)
{
	if (flag.width < 0)
	{
		flag.width *= -1;
		flag.minus = 1;
		flag.zero = 0;
	}
	if (flag.acc < 0)
		flag.acc = -1;
	return (flag);
}

t_flag		ft_len_s(t_flag flag, char *str)
{
	if (flag.acc == -1 && flag.width > 0 && str)
		flag.len += flag.width > ft_len(str) ? flag.width : ft_len(str);
	if (flag.width == 0 && flag.acc != -1 && str)
		flag.len += flag.acc > ft_len(str) ? ft_len(str) : flag.acc;
	if (flag.acc != -1 && flag.width > 0 && str)
	{
		if (flag.acc > flag.width && flag.acc >= ft_len(str))
			flag.len += flag.width < ft_len(str) ?
			ft_len(str) : flag.width;
		else if (flag.acc > flag.width && flag.acc < ft_len(str))
			flag.len += flag.width < ft_len(str) ?
			flag.acc : flag.width;
		else
			flag.len += flag.width;
	}
	if (flag.width == 0 && flag.acc == -1 && str)
		flag.len += ft_len(str);
	if (!str)
		flag.len += flag.width;
	return (flag);
}
