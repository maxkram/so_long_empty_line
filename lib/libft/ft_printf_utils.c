/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:45:10 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/18 14:43:46 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putchar_i(char c, int *i)
{
	write(1, &c, 1);
	*i += 1;
}

void	ft_puthex(unsigned long long nb, int *i, char *base)
{
	if (nb >= 16)
		ft_puthex(nb / 16, i, base);
	ft_putchar_i(base[nb % 16], i);
}

void	ft_putint(unsigned int nb, int *i)
{
	if (nb >= 10)
		ft_putint(nb / 10, i);
	ft_putchar_i(nb % 10 + '0', i);
}

void	ft_putstr_i(char *str, int *i)
{
	int	count;

	if (!str)
	{
		ft_putstr_i("(null)", i);
		return ;
	}
	count = 0;
	while (str[count] != '\0')
	{
		ft_putchar_i(str[count], i);
		count++;
	}
}

void	ft_putnbr_i(int nb, int *i)
{
	if (nb == -2147483648)
	{
		ft_putstr_i("-2147483648", i);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar_i('-', i);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_i(nb / 10, i);
	ft_putchar_i(nb % 10 + '0', i);
}
