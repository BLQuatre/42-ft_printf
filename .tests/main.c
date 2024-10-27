/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:25:24 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/27 20:56:24 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdio.h>
#include <assert.h>
#include <limits.h>

void test_id(char *to_parse, int value)
{
	char *to_parse_joined = ft_strjoin("~", ft_strjoin(to_parse, "~\n"));
	int i1 = printf(to_parse_joined, value);
	int i2 = ft_printf(to_parse_joined, value);
	printf("\n\nTest: %s\n", to_parse);
	if (i1 == i2)
		printf("\n✅ Expected: %d | Got: %d\n\n", i1, i2);
	else
		printf("\n❌ Expected: %d | Got: %d\n\n", i1, i2);
}

int main()
{
	char *to_parse = "^.^/%+18.2d^.^/";
	char *to_parse_joined = ft_strjoin("~", ft_strjoin(to_parse, "~\n"));
	int i1 = printf(to_parse_joined, 0);
	int i2 = ft_printf(to_parse_joined, 0);
	printf("\n\nTest: %s\n", to_parse);
	if (i1 == i2)
		printf("\n✅ Expected: %d | Got: %d\n\n", i1, i2);
	else
		printf("\n❌ Expected: %d | Got: %d\n\n", i1, i2);
	test_id("%08.5i", 34);
	test_id("%08.3i", -8473);
}
