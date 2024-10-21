/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:25:24 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/21 18:26:36 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdio.h>
#include <assert.h>

int main()
{
	int i1 = ft_printf("~ %s %s %s %s %s ~", " - ", "", "4", "", "2 ");
	printf("\n");
	int i2 = printf("~ %s %s %s %s %s ~", " - ", "", "4", "", "2 ");

	printf("\n\n~%d~\n\n~~%d~\n\n", i1, i2);
	char *s1 = NULL;
	int i3 = ft_printf("~ %23.7s ~", s1);
	printf("\n");
	int i4 = printf("~ %23.7s ~", s1);
	printf("\n\n~%d~\n\n~~%d~\n\n", i3, i4);
	//printf("\n\n~%d~\n\n", i4);
}
