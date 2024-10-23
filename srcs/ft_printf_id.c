/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:08:26 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/23 20:42:23 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
-1

1  < 0 no

result = 1 - 0
10 > 5 et 5 > 0
return result -> 5


//-10.5

// 10 
*/
static unsigned int	ft_spaces(char *str, t_printf_params *params)
{
	unsigned int	result;

	if (params->nb_before_dot < params->nb_after_dot)
		return (0);
	result = params->nb_before_dot - params->nb_after_dot;
	if (!params->minus)
		result++;
	if ((params->space || params->plus) && result > 1)
		result--;
	if ((params->nb_before_dot > params->nb_after_dot
			&& params->nb_after_dot > 0)
		|| params->nb_before_dot == params->nb_after_dot)
		return (result);
	
	return (result - ft_strlen(str));
}

static int	ft_putnnbr(char *str, int len)
{
	int	count;

	count = 0;
	while (len-- > 0)
		count += ft_putchar('0');
	while (*str)
		count += ft_putchar(*str++);
	return (count);
}

int	ft_printf_id(t_printf_params *params, int n)
{
	int				size;
	unsigned int	spaces;
	char			*nbr;

	size = 0;
	nbr = ft_itoa(n);
	spaces = ft_spaces(nbr, params);
	if ((int) spaces < 0)
		spaces = 0;
	while (!params->minus && --spaces > 0)
		size += ft_putchar(' ');
	if (params->space && !params->plus)
		size += ft_putchar(' ');
	else if (params->plus)
		size += ft_putchar('+');
	size += ft_putnnbr(nbr, params->nb_after_dot - ft_strlen(nbr));
	while (spaces-- > 0)
		size += ft_putchar(' ');
	free(nbr);
	return (size);
}
