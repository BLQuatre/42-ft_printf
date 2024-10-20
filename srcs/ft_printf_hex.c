/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:12:50 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/18 22:46:45 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(int n, int lower)
{
	int		i;
	int		z;
	char	hex_array[100];

	i = 1;
	while (n != 0)
	{
		z = n % 16;
		if (z >= 10)
		{
			if (lower)
				z += 87;
			else
				z += 55;
		}
		else
			z += 48;
		hex_array[i++] = z;
		n /= 16;
	}
	while (i-- > 0)
		ft_putchar_fd(hex_array[i], 0);
}
