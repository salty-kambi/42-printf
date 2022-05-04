/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:11:24 by lsuau             #+#    #+#             */
/*   Updated: 2021/11/16 19:11:19 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned long int nb, char *base, int *nc)
{
	unsigned long long int			leng;

	leng = ft_strlen(base);
	if (nb < 0)
		nb *= -1;
	if (nb >= 0 && nb < leng)
	{
		*nc += write(1, base + nb, 1);
	}
	if (nb >= leng)
	{
		ft_putnbr_base(nb / leng, base, nc);
		ft_putnbr_base(nb % leng, base, nc);
	}
}

int	ft_pvoid(va_list args)
{
	int					nc;
	unsigned long int	adr;

	adr = va_arg(args, unsigned long int);
	nc = write(1, "0x", 2);
	ft_putnbr_base(adr, "0123456789abcdef", &nc);
	return (nc);
}

int	ft_phexa(va_list args, int n)
{
	unsigned int	nb;
	int				nc;

	nb = va_arg(args, unsigned int);
	nc = 0;
	if (n)
		ft_putnbr_base(nb, "0123456789ABCDEF", &nc);
	else
		ft_putnbr_base(nb, "0123456789abcdef", &nc);
	return (nc);
}
