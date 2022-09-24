/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:08:32 by vde-leus          #+#    #+#             */
/*   Updated: 2022/09/24 14:49:59 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	char	*str;
	char	**pstr;
	int		r1;
	int		r2;
	int		tab[] = {4, 8, 15, 16, 23, 42};

	str = "Victor de Leusse";
	pstr = &str;
	r1 = printf("Le telephone est charge a hauteur de 42%%.\n");
	r2 = ft_printf("Le telephone est charge a hauteur de 42%%.\n");
	printf("%d : %d\n\n", r1, r2);

	r1 = printf("J'ai %d ans, bientot %u.\n", 27, 28);
	r2 = ft_printf("J'ai %d ans, bientot %u.\n", 27, 28);
	printf("%d : %d\n\n", r1, r2);

	r1 = printf("Mes initiales sont %c et %c.\n", (char) 'V', (int) 76);
	r2 = ft_printf("Mes initiales sont %c et %c.\n", (char) 'V', (int) 76);
	printf("%d : %d\n\n", r1, r2);

	r1 = printf("Je m'appelle %s, et non %s par exemple.\n", "Victor", "Titouan");
	r2 = ft_printf("Je m'appelle %s, et non %s par exemple.\n", "Victor", "Titouan");
	printf("%d : %d\n\n", r1, r2);

	r1 = printf("On apprends mon pseudo a l'adresse %p : %s.\n", pstr, *pstr);
	r2 = ft_printf("On apprends mon pseudo a l'adresse %p : %s.\n", pstr, *pstr);
	printf("%d : %d\n\n", r1, r2);

	r1 = printf("Ma suite de nombres preferee est %d %d %d %d %d %d.\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
	r2 = ft_printf("Ma suite de nombres preferee est %d %d %d %d %d %d.\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
	printf("%d : %d\n\n", r1, r2);

	r1 = printf("En hexadecimal, %d peut s'ecrire %x (ou %X).\n", 42, 42, 42);
	r2 = ft_printf("En hexadecimal, %d peut s'ecrire %x (ou %X).\n", 42, 42, 42);
	printf("%d : %d\n\n", r1, r2);

	r1 = printf("Voici un ph%%%rase completement normale.\n");
	r2 = ft_printf("Voici un ph%%%rase completement normale.\n");
	printf("%d : %d\n\n", r1, r2);

	r1 = printf("Ma date de naissance est le %d%d.\n", 11, 10);
	r2 = ft_printf("Ma date de naissance est le %d%d.\n", 11, 10);
	printf("%d : %d\n\n", r1, r2);

	r1 = printf("Un int c'est %u octets.\n", sizeof(int));
	r2 = ft_printf("Un int c'est %u octets.\n", sizeof(int));
	printf("%d : %d\n\n", r1, r2);

	r1 = printf(".. J'ai hate d'etre a 42.\n");
	r2 = ft_printf(".. J'ai hate d'etre a 42.\n");
	printf("%d : %d\n\n", r1, r2);

	r1 = printf("Les tests sont quasiments finis\n%");
	r2 = ft_printf("Les tests sont quasiments finis\n%");
	printf("%d : %d\n\n", r1, r2);

	r1 = printf("");
	r2 = ft_printf("");
	printf("%d : %d\n\n", r1, r2);

	return (0);
}
