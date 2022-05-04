/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuau <lsuau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:35:38 by lsuau             #+#    #+#             */
/*   Updated: 2021/11/16 14:30:04 by lsuau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_parse(va_list args, char c);
int		ft_checkstr(char c);
int		ft_pchar(va_list args);
int		ft_pstr(va_list args);
int		ft_pvoid(va_list args);
int		ft_pnbr(va_list args);
int		ft_punbr(va_list args);
int		ft_phexa(va_list args, int n);
int		ft_strlen(char *s);
void	ft_putnbr(long int nb, int *nc);
void	ft_putunbr(unsigned int nb, int *nc);
void	ft_putnbr_base(unsigned long int nb, char *base, int *nc);

#endif