/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:15:02 by vde-leus          #+#    #+#             */
/*   Updated: 2022/10/07 14:15:05 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/* Recuperation de l adresse et conversion en base hexadecimale */

static int	ft_len_nbr_hex(unsigned long nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr = nbr / 16;
		i = i + 1;
	}
	return (i);
}

static char	*ft_putbase_hex_mini(unsigned long adress)
{
	char			*resultat;
	char			*base;
	int				i;

	base = "0123456789abcdef";
	if (adress == 0)
	{	
		resultat = (char *)malloc(sizeof(char));
		*resultat = '\0';
		return (resultat);
	}
	i = ft_len_nbr_hex(adress);
	resultat = (char *)malloc(sizeof(char) * (i + 1));
	if (!resultat)
		return (NULL);
	resultat[i] = '\0';
	i = i - 1;
	while (i >= 0)
	{
		resultat[i] = base[adress % 16];
		adress = adress / 16;
		i--;
	}
	return (resultat);
}

// Recuperation du param d entree en void* et affichage 
// + retour du len (+2 avec le 0x)

size_t	ft_putadress_min_hex(void *entree)
{
	char	*resultat;
	size_t	len;

	resultat = ft_putbase_hex_mini((unsigned long)entree);
	len = ft_strlen(resultat);
	ft_putstr("0x");
	ft_putstr(resultat);
	free(resultat);
	return (len + 2);
}

//0x7ff7bf2b5498
//140702040937624

// int	main(void)
// {
// 	unsigned long	*ptr_i;
// 	unsigned long	i;
// 	size_t			test;

// 	i = 563;
// 	ptr_i = &i;
// 	test = ft_putadress_min_hex(ptr_i);
// 	printf("\nvs. printf :");
// 	printf("%p\n", ptr_i);
// 	printf("%d\n", test);
// 	return (0);
// }