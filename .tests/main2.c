/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:25:24 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/22 16:31:32 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdio.h>
#include <assert.h>
#include <limits.h>

int main()
{
	ft_printf(" %-1i ", 10);
	ft_printf(" %.11i ", LONG_MIN);


	// int i1 = ft_printf("~%10.5i~\n", 42);
	// int i2 = printf("~%10.5i~\n", 42);

	// printf("~%d~\n~%d~\n", i1, i2);
}
