/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:18:05 by vde-leus          #+#    #+#             */
/*   Updated: 2022/11/16 15:19:26 by vde-leus         ###   ########.fr       */
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

static int	ft_check(const char c)
{
	if (c == 'd' || c == 's' || c == 'c' || c == 'p' || c == 'x' || c == 'X'
		|| c == 'i' || c == '%' || c == 'u')
		return (1);
	else if (c != '\0')
		return (2);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	int		count;
	int		i;

	if (!str)
		return (-1);
	i = -1;
	count = 0;
	va_start(arg_ptr, str);
	while (str[++i])
	{
		if (str[i] == '%' && ft_check(str[i + 1]) == 1)
			count += ft_transfo(arg_ptr, str[++i]);
		else if (str[i] == '%' && ft_check(str[i + 1]) == 2)
			count += ft_transfo(arg_ptr, str[i]);
		else if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		else
		{
			if (str[i] != '%')
				count += ft_putchar(str[i]);
		}
	}
	va_end(arg_ptr);
	return (count);
}

// int	main(void)
// {
// 	int		original;
// 	int		mine;
// 	char	*str;

// 	str = "Just some text..";

// 	printf("\n\n--- ALL ---\n");
// 	original = printf("-> %c | %s | %p | %d | %i | %u | %x | %X | %% |", str[0], str, str, 42, 42, 42, 42, 42);
// 	printf("\n");
// 	mine = ft_printf("-> %c | %s | %p | %d | %i | %u | %x | %X | %% |", str[0], str, str, 42, 42, 42, 42, 42);
// 	printf("\n");
// 	printf("%d  : %d\n", original, mine);

// 	printf("\n\n--- SAME WITH %%%%%% AT THE END ---\n");
// 	original = printf("-> %c | %s | %p | %d | %i | %u | %x | %X | %% |%%%", str[0], str, str, 42, 42, 42, 42, 42);
// 	printf("\n");
// 	mine = ft_printf("-> %c | %s | %p | %d | %i | %u | %x | %X | %% |%%%", str[0], str, str, 42, 42, 42, 42, 42);
// 	printf("\n");
// 	printf("%d  : %d\n", original, mine);

// 	printf("\n\n--- SAME WITH %%%%%% AT THE END AND SOME TEXT ---\n");
// 	original = printf("-> %c | %s | %p | %d | %i | %u | %x | %X | %% |%%%| texte", str[0], str, str, 42, 42, 42, 42, 42);
// 	printf("\n");
// 	mine = ft_printf("-> %c | %s | %p | %d | %i | %u | %x | %X | %% |%%%| texte", str[0], str, str, 42, 42, 42, 42, 42);
// 	printf("\n");
// 	printf("%d  : %d\n", original, mine);

// 	printf("\n\n--- EMPTY STRING ---\n");
// 	original = printf("");
// 	mine = ft_printf("");
// 	printf("%d  : %d\n", original, mine);

// 	printf("\n\n--- WITH ft_printf(0) ---\n");
// 	original = printf(0);
// 	mine = ft_printf(0);
// 	printf("%d  : %d\n", original, mine);

// 	printf("\n\n--- WITH STR AS ONLY ARGUMENT ---\n");
// 	original = printf(str);
// 	printf("\n");
// 	mine = ft_printf(str);
// 	printf("\n");
// 	printf("%d  : %d\n", original, mine);

// 	printf("\n\n--- WITH NULL AS STRING AND ADRESS ---\n");
// 	original = printf("-> %s | %p", NULL, NULL);
// 	printf("\n");
// 	mine = ft_printf("-> %s | %p", NULL, NULL);
// 	printf("\n");
// 	printf("%d  : %d\n", original, mine);

// 	printf("\n\n--- WITH TAB AND ANTICIPATED END OF STRING ---\n");
// 	original = printf("-> \t|\0\0gloubiboulgah");
// 	printf("\n");
// 	mine = ft_printf("-> \t|\0\0gloubiboulgah");
// 	printf("\n");
// 	printf("%d  : %d\n", original, mine);

// 	printf("\n\n--- WITH NEGATIVE VALUES ---\n");
// 	original = printf("%u | %x | %X | %d | %i | %c | %p", -42, -42, -42, -42, -42, -42, (void *) -42);
// 	printf("\n");
// 	mine = ft_printf("%u | %x | %X | %d | %i | %c | %p", -42, -42, -42, -42, -42, -42, (void *) -42);
// 	printf("\n");
// 	printf("%d  : %d\n", original, mine);

// 	printf("\n\n--- PRINT ADRESS WITH %%x and %%X ---\n");
// 	original = printf("%x | %X | %x | %X", NULL, NULL, &str, &str);
// 	printf("\n");
// 	mine = ft_printf("%x | %X | %x | %X", NULL, NULL, &str, &str);
// 	printf("\n");
// 	printf("%d  : %d\n", original, mine);
// }
