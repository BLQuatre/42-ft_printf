/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:25:24 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/24 00:34:59 by cauvray          ###   ########.fr       */
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
	int i1 = printf("~ %-40.0x ~\n", 9);
	int i2 = ft_printf("~ %-40.0x ~\n", 9);

	// ft_printf(" %-1x ", 0);
	// ft_printf(" %01x ", 0);
	// ft_printf(" %04x ", 9);
	// ft_printf(" %01x ", 10);
	// ft_printf(" %03x ", 15);
	// ft_printf(" %04x ", 16);
	// ft_printf(" %05x ", 17);
	// ft_printf(" %01x ", 99);
	// ft_printf(" %01x ", -9);
	// ft_printf(" %010x ", INT_MIN);
	// ft_printf(" %011x ", LONG_MAX);
	// ft_printf(" %012x ", LONG_MIN);
	// ft_printf(" %013x ", UINT_MAX);
	// ft_printf(" %014x ", ULONG_MAX);
	// ft_printf(" %015x ", 9223372036854775807LL);
	// ft_printf(" %09x %010x %011x %012x %013x %014x %015x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);


	if (i1 == i2)
		printf("\n✅ Expected: %d | Got: %d\n", i1, i2);
	else
		printf("\n❌ Expected: %d | Got: %d\n", i1, i2);
}
