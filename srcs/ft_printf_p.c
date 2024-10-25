/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:21:17 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/25 13:41:32 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static unsigned long long	ft_spaces_p(char *str, t_printf_params *params)
{
	unsigned long long	result;

	result = 0;
	if (params->nb_after_dot > params->nb_before_dot)
		return (result);
	result = params->nb_before_dot - params->nb_after_dot + 1;
	if (result > 1)
		result -= 2;
	if ((params->nb_before_dot > params->nb_after_dot
			&& params->nb_after_dot > 0)
		|| params->nb_before_dot == params->nb_after_dot)
		return (result);
	result -= ft_strlen(str);
	return (1);
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

int	ft_printf_p(t_printf_params *params, unsigned long long n)
{
	int					size;
	unsigned long long	spaces;
	char				*hex;

	size = 0;
	hex = ft_ptr_to_hex(n);
	spaces = ft_spaces_p(hex, params);
	while (!params->minus && --spaces > 0)
		size += ft_putchar(' ');
	if (n == 0)
		size += ft_putstr("(nil)");
	else
	{
		size += ft_putstr("0x");
		size += ft_puthexstr(hex, params->nb_after_dot - ft_strlen(hex));
	}
	while (spaces-- > 0)
		size += ft_putchar(' ');
	free(hex);
	return (size);
}
