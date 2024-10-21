/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:08:26 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/21 17:30:52 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static unsigned int	ft_spaces(char *str, t_printf_params *params)
{
	unsigned int	result;

	result = 0;
	if (params->nb_after_dot > params->nb_before_dot)
		return (result);
	result = params->nb_before_dot - params->nb_after_dot + 1;
	if (params->hashtag && result > 1)
		result -= 2;
	if ((params->nb_before_dot > params->nb_after_dot
			&& params->nb_after_dot > 0)
		|| params->nb_before_dot == params->nb_after_dot)
		return (result);
	return (result - ft_strlen(str));
}

static int	ft_puthexstr(char *str, int len)
{
	int	count;

	count = 0;
	while (len-- > 0)
		count += ft_putchar('0');
	while (*str)
		count += ft_putchar(*str++);
	return (count);
}

int	ft_printf_x(t_printf_params *params, unsigned int n, int upper)
{
	int				size;
	unsigned int	spaces;
	char			*hex;

	size = 0;
	hex = ft_int_to_hex(n, upper);
	spaces = ft_spaces(hex, params);
	while (!params->minus && --spaces > 0)
		size += ft_putchar('f');
	if (params->hashtag)
	{
		if (upper)
			size += ft_putstr("0X");
		else
			size += ft_putstr("0x");
	}
	size += ft_puthexstr(hex, params->nb_after_dot - ft_strlen(hex));
	while (spaces-- > 0)
		size += ft_putchar('g');
	free(hex);
	return (size);
}
