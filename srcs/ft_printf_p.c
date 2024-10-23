/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:21:17 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/23 20:57:08 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static unsigned long long	ft_spaces(char *str, t_printf_params *params)
{
	unsigned long long	result;

	//printf("Char: ~%s~\n", str);

	result = 0;
	if (params->nb_after_dot > params->nb_before_dot)
		return (result);
	
	result = params->nb_before_dot - params->nb_after_dot + 1;
	//printf("Start result: ~%lld~\n", result);
	if (result > 1)
		result -= 2;
	//printf("Mid result: ~%lld~\n", result);
	if ((params->nb_before_dot > params->nb_after_dot
			&& params->nb_after_dot > 0)
		|| params->nb_before_dot == params->nb_after_dot)
		return (result);
	//printf("End: ~%lld~\n", result - ft_strlen(str));
	result -= ft_strlen(str);
	return (1);
}

static int	ft_puthexstr(char *str, int len)
{
	int	count;
	//printf("len: %d!", len);

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
	//printf("len: %lld!", n);
	hex = ft_ptr_to_hex(n);
	spaces = ft_spaces(hex, params);
	//printf("Spaces: %lld\n", spaces);
	while (!params->minus && --spaces > 0)
		size += ft_putchar(' ');
	if (n == 0)
		size += ft_putstr("(nil)");
	else
	{
		size += ft_putstr("0x");
		//printf("hex %s~\n", hex);
		size += ft_puthexstr(hex, params->nb_after_dot - ft_strlen(hex));
	}
	while (spaces-- > 0)
		size += ft_putchar(' ');
	free(hex);
	return (size);
}
