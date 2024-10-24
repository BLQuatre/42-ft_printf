/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:25:24 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/24 22:53:33 by cauvray          ###   ########.fr       */
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
	char *to_parse = " %8.3i "; // -
	char *to_parse_joined = ft_strjoin("~", ft_strjoin(to_parse, "~\n"));
	int value = -8473;

	int i1 = printf(to_parse_joined, value);
	int i2 = ft_printf(to_parse_joined, value);

	if (i1 == i2)
		printf("\n✅ Expected: %d | Got: %d\n\n", i1, i2);
	else
		printf("\n❌ Expected: %d | Got: %d\n\n", i1, i2);
}
