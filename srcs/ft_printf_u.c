/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:08:26 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/23 20:56:40 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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

unsigned int	ft_printf_u(t_printf_params *params, unsigned int n)
{
	unsigned int	size;
	unsigned int	spaces;
	char			*nbr;

	size = 0;
	nbr = ft_uitoa(n);
	spaces = ft_spaces(nbr, params);
	if ((int) spaces < 0)
		spaces = 0;
	//printf("Spaces: %u\n", spaces);
	while (!params->minus && --spaces > 0)
		size += ft_putchar('0');
	size += ft_putstr(nbr);
	while (spaces-- > 0)
		size += ft_putchar(' ');
	free(nbr);
	return (size);
}
