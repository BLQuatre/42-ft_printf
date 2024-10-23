/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:08:26 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/24 00:33:56 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static long	ft_spaces_x(char *str, t_printf_params *params)
{
	long	result;

	
	if (params->nb_after_dot > params->nb_before_dot)
		return (0);
	result = params->nb_before_dot - params->nb_after_dot;
	if (params->hashtag && result >= 2)
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
	int					size;
	long				spaces;
	char				*hex;

	size = 0;
	hex = ft_int_to_hex(n, upper);
	// printf("STR: ~%s~\n", hex);
	// printf("Strlen: ~%ld~\n", ft_strlen(hex));
	// printf("Nb bef: ~%d~\n", params->nb_before_dot);
	// printf("Dot ?: ~%s~\n", params->dot ? "Yes" : "No");
	// printf("Zero ?: ~%s~\n", params->zero ? "Yes" : "No");
	// printf("Nb aft: ~%d~\n", params->nb_after_dot);

	spaces = ft_spaces_x(hex, params);
	// printf("Spaces: ~%lu~\n", spaces);
	while (!params->minus && spaces-- > 0)
		size += ft_putchar(' ');
	if (params->hashtag)
	{
		if (upper)
			size += ft_putstr("0X");
		else
			size += ft_putstr("0x");
	}
	size += ft_puthexstr(hex, params->nb_after_dot - ft_strlen(hex));
	while (spaces-- > 0)
		size += ft_putchar(' ');
	free(hex);
	return (size);
}
