/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:36:49 by lsuau             #+#    #+#             */
/*   Updated: 2021/11/16 14:04:31 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long int nb, int *nc)
{
	long int	nbw;

	if (nb >= 0 && nb < 10)
	{
		nbw = nb + '0';
		*nc += write(1, &nbw, 1);
	}
	else if (nb < 0)
	{
		*nc += write(1, "-", 1);
		ft_putnbr(nb * (-1), nc);
	}
	else
	{
		ft_putnbr(nb / 10, nc);
		ft_putnbr(nb % 10, nc);
	}
}

void	ft_putunbr(unsigned int nb, int *nc)
{
	unsigned int	nbw;

	if (nb >= 0 && nb < 10)
	{
		nbw = nb + '0';
		*nc += write(1, &nbw, 1);
	}
	else
	{
		ft_putnbr(nb / 10, nc);
		ft_putnbr(nb % 10, nc);
	}
}

int	ft_pnbr(va_list args)
{
	int	nb;
	int	nc;

	nc = 0;
	nb = va_arg(args, int);
	ft_putnbr(nb, &nc);
	return (nc);
}

int	ft_punbr(va_list args)
{
	unsigned int	nb;
	int				nc;

	nc = 0;
	nb = va_arg(args, unsigned int);
	ft_putunbr(nb, &nc);
	return (nc);
}
