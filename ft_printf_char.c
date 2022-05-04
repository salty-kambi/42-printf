/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:28:28 by lsuau             #+#    #+#             */
/*   Updated: 2021/11/16 12:19:03 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

int	ft_pchar(va_list args)
{
	unsigned char	c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

int	ft_pstr(va_list args)
{
	char	*s;
	int		x;

	s = va_arg(args, char *);
	if (!s)
		return (write(1, "(null)", 6));
	x = ft_strlen(s);
	return (write(1, s, x));
}
