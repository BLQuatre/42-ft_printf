/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 01:34:31 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/21 02:20:39 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_putint(int value)
{
	size_t	size;

	if (value < 10)
	{
		ft_putchar_fd(48 + value, 0);
		return (1);
	}
	size = ft_putint(value / 10);
	ft_putchar_fd(48 + value % 10, 0);
	return (size + 1);
}

/*
Avec %d:
-> 0 possible pour mettre full 0
-> - possible (pareil qur 0)
-> .nb = afficher nb premier chiffre du nombres (marche pas)
-> # marche po pas de parse 
-> ' ' (space) same behaviour que sans espace pour au debut (only debut not after)
-> + only start -> pas aftet (comme space) -> add plus if number is positive
*/

int main(void)
{
	printf("Test 1: ~%.2s~", "Coucou"); printf(" - %s\n", "%.2s");
	// printf("Test 2: ~%+ 23.2d~\n", 4234); printf(" - %s\n", "%.2s"); // flag ' ' is ignored when flag '+' is present
	printf("Test 3: ~% 4.2d~", 4234); printf(" - %s\n", "% 4.2d"); // space plus number only print ONE space before number
	//printf("Test 4: ~%4 .2d~", 4234); printf(" - %s\n", "%.2s"); // MARCHE PO
	printf("Test 5: ~%+-23.2d~", 4234); printf(" - %s\n", "%+-23.2d"); // plus add plus to number and minus add width
	printf("Test 6: ~%- 23.2d~", 4234); printf(" - %s\n", "%- 23.2d"); // plus add plus to number and minus add width
	printf("Test 6.2: ~% -23.2d~", 4234); printf(" - %s\n", "% -23.2d"); // plus add plus to number and minus add width
	// printf("Test 6.5: ~% 23.2d~", 4234); printf(" - %s\n", "% 23.2d"); // plus add plus to number and minus add width
	// printf("Test 6.7: ~% 23.8d~", 4234); printf(" - %s\n", "% 23.8d"); // plus add plus to number and minus add width
	// printf("Test 7: ~%+-23d~", 4234); printf(" - %s\n", "%+-23d"); // plus add plus to number and minus add width
	printf("Test 8: ~%+23d~", 4234); printf(" - %s\n", "%+23d"); // plus add plus to number and minus add width
	printf("Test 8.2: ~%0+23d~", 4234); printf(" - %s\n", "%0+23d"); // plus add plus to number and minus add width
	printf("Test 8.5: ~%+023d~", 4234); printf(" - %s\n", "%+023d"); // plus add plus to number and minus add width
	printf("Test 8.7: ~%+023.10d~", 4234); printf(" - %s\n", "%+023.10d"); // plus add plus to number and minus add width
	printf("Test 8.8: ~%0+23.10d~", 4234); printf(" - %s\n", "%0+23.10d"); // plus add plus to number and minus add width
	printf("Test 8.9: ~%+23.5d~", 4234); printf(" - %s\n", "%0+23.10d"); // plus add plus to number and minus add width
	printf("Test 9: ~%+d~", 4234); printf(" - %s\n", "%+d"); // plus add plus to number and minus add width
	// printf("Test 8: ~%0-23.2d~", 4234); printf(" - %s\n", "%.2s"); // zero add a lot a zero to the second int // flag '0' is ignored when flag '-' is present
	printf("Test 10: ~%0.d~", 4234); printf(" - %s\n", "%0.d");
	printf("Test 11: ~%+-23.2d~", 4234); printf(" - %s\n", "%+-23.2d");
	printf("Test 12: ~%6.4d~", 4234); printf(" - %s\n", "%6.4d");
	printf("Test 13: ~%4.6d~", 4234); printf(" - %s\n", "%4.6d");
	printf("Test 14: ~%25.10d~", 4234); printf(" - %s\n", "%25.10d");
}
