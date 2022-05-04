/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:35:11 by lsuau             #+#    #+#             */
/*   Updated: 2021/11/16 14:28:43 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkstr(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd')
		return (1);
	if (c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_parse(va_list args, char c)
{
	int	nc;

	nc = 0;
	if (c == 'c')
		nc = ft_pchar(args);
	if (c == 's')
		nc = ft_pstr(args);
	if (c == 'p')
		nc = ft_pvoid(args);
	if (c == 'd' || c == 'i')
		nc = ft_pnbr(args);
	if (c == 'u')
		nc = ft_punbr(args);
	if (c == 'x')
		nc = ft_phexa(args, 0);
	if (c == 'X')
		nc = ft_phexa(args, 1);
	if (c == '%')
		nc = write(1, "%", 1);
	return (nc);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		x;
	int		nbchar;

	va_start(args, str);
	x = 0;
	nbchar = 0;
	while (str[x])
	{
		if (str[x] == '%')
		{
			x++;
			nbchar += ft_parse(args, str[x]);
			x += ft_checkstr(str[x]);
		}
		else
		{
			nbchar++;
			write(1, str + x, 1);
			x++;
		}
	}
	return (nbchar);
}
