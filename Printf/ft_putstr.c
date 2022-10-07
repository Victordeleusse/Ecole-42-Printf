/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:05:19 by vde-leus          #+#    #+#             */
/*   Updated: 2022/10/07 12:13:33 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr(char *str)
{
	int	i;
	int	len;

	if (str == NULL)
	{	
		ft_putchar('\0');
		return (0);
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	len = ft_strlen(str);
	return (len);
}

// int	main(void)
// {
// 	char	test[] = "Hello world !";
// 	size_t		len;

// 	len = ft_putstr(test);
// 	printf("\n%d", len);
// 	return (0);
// }