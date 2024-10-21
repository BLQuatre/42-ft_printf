/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:12:50 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/21 17:30:55 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

static int	ft_get_hex_size(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static void	ft_strinvert(char *str)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}
}

char	*ft_int_to_hex(unsigned int n, int upper)
{
	char	*hex_array;
	int		i;
	char	*hex;

	hex_array = "0123456789abcdef";
	hex = (char *) malloc(ft_get_hex_size(n) + 1);
	if (!hex)
		return (NULL);
	i = 0;
	if (n == 0)
		hex[i++] = '0';
	while (n > 0)
	{
		hex[i++] = hex_array[n % 16];
		n /= 16;
	}
	hex[i] = 0;
	ft_strinvert(hex);
	if (upper)
	{
		i++;
		while (i-- > 0)
			hex[i] = ft_toupper(hex[i]);
	}
	return (hex);
}
