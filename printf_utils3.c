/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shenquin <shenquin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:44:58 by shenquin          #+#    #+#             */
/*   Updated: 2020/12/01 11:45:00 by shenquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(char *str)
{
	int				i;
	unsigned long	result;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (result > LONG_MAX)
		return (0);
	return (result);
}

int	ft_lgth(long int nb)
{
	if (nb < 0)
		return (1 + ft_lgth(nb * (-1)));
	if (nb > 9)
		return (1 + ft_lgth(nb / 10));
	return (1);
}
