/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:25:24 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/25 01:58:31 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdio.h>
#include <assert.h>
#include <limits.h>

int main()
{
	//char *null = NULL;
	char *to_parse = " %.5u ";
	char *to_parse_joined = ft_strjoin("~", ft_strjoin(to_parse, "~\n"));
	unsigned int value = 2;

	int i1 = printf(to_parse_joined, value);
	int i2 = ft_printf(to_parse_joined, value);

	if (i1 == i2)
		printf("\n✅ Expected: %d | Got: %d\n\n", i1, i2);
	else
		printf("\n❌ Expected: %d | Got: %d\n\n", i1, i2);
}

// - [OUTPUT] ft_printf("%.5u", 2)
// - [OUTPUT] ft_printf("%.3u", 0)
// - [OUTPUT] ft_printf("%8.5u", 34)
// - [OUTPUT] ft_printf("%8.5u", 0)
// - [OUTPUT] ft_printf("%3.7u", 3267)
// - [OUTPUT] ft_printf("%-8.5u", 34)
// - [OUTPUT] ft_printf("%-8.5u", 0)
// - [OUTPUT] ft_printf("%-3.7u", 3267)
// - [OUTPUT] ft_printf("%08.5u", 34)
// - [OUTPUT] ft_printf("%08.5u", 0)
// - [OUTPUT] ft_printf("%08.3u", 8375)
// - [OUTPUT] ft_printf("%03.7u", 3267)
// - [OUTPUT] ft_printf("%.0u", 0)
// - [OUTPUT] ft_printf("%.u", 0)
// - [OUTPUT] ft_printf("%5.0u", 0)
// - [OUTPUT] ft_printf("%5.u", 0)
// - [OUTPUT] ft_printf("%-5.0u", 0)
