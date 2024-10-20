/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 01:26:48 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/21 01:31:27 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/libftprintf.h"
#include <stdio.h>
#include <assert.h>

int	vout(int max, ...)
{
	va_list	arg_ptr;
	va_list	args_copy;
	int		args;
	char	*day;

	va_start(arg_ptr, max); /* second arg = max arg so if % + value add one */
	va_copy(args_copy, arg_ptr); /* copy args into another valist */
	args = 0;
	while (args < max)
	{
		day = va_arg(arg_ptr, char *); /* char * corresponding to type */
		printf("Day1: %s\n", day); /* each time call va_arg -> go next */
		day = va_arg(arg_ptr, char *); /* char * corresponding to type */
		printf("Day2: %s\n", day);
		args += 2;
	}
	va_end(arg_ptr);
	args = 0;
	while (args < max)
	{
		day = va_arg(args_copy, char *);
		printf("Day: %s\n", day);
		args++;
	}
	va_end(args_copy); /* end of list - cant be used again, end = free */
}

int	main(void)
{
	vout(4, "Sat", "Sun", "re", "eee");
	printf("\n");
	vout(3, "Mon", "Tues", "Wed");
}
