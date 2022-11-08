/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:18:05 by vde-leus          #+#    #+#             */
/*   Updated: 2022/11/08 13:51:26 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	ft_transfo(va_list arg_ptr, char s)
{
	size_t	taille;

	taille = 0;
	if (s == 'd' || s == 'i')
		taille = ft_putnbr(va_arg(arg_ptr, int));
	if (s == 's')
		taille = ft_putstr(va_arg(arg_ptr, char *));
	if (s == 'c')
		taille = ft_putchar(va_arg(arg_ptr, int));
	if (s == 'p')
		taille = ft_putadress_min_hex(va_arg(arg_ptr, void *));
	if (s == 'x')
		taille = ft_putnbr_hexmin(va_arg(arg_ptr, int));
	if (s == 'X')
		taille = ft_putnbr_hexmaj(va_arg(arg_ptr, int));
	if (s == 'u')
		taille = ft_put_unsnbr(va_arg(arg_ptr, unsigned int));
	if (s == '%')
		taille = ft_putchar('%');
	return (taille);
}


int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(arg_ptr, str);
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 's'
				|| str[i + 1] == 'c' || str[i + 1] == 'p' || str[i + 1] == 'x'
				|| str[i + 1] == 'X' || str[i + 1] == 'i' || str[i + 1] == '%'
				|| str[i + 1] == 'u'))
		{		
			i++;
			count += ft_transfo(arg_ptr, str[i]);
		}	
		else if (str[i] == '%' && str[i + 1] == '\0')
			return (count);
		else
		{
			if (str[i] != '%')
			{	
				ft_putchar(str[i]);
				count += 1;
			}
		}
		i++;
	}
	va_end(arg_ptr);
	return (count);
}
