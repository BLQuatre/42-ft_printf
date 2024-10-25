/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:08:26 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/25 02:04:20 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

	// long long result;
	// if (params->nb_after_dot > params->nb_before_dot && params->zero && params->dot)
	// 	return (params->nb_after_dot - ft_strlen(str));
	// if (DEBUG) printf("[DEBUG] ft_spaces_id 1\n");

	// result = 0;
	// if (DEBUG) printf("[DEBUG] ft_spaces_id 1: %lld\n", result);

	// if (params->nb_before_dot <= params->nb_after_dot)
	// 	return (0);
	// if (DEBUG) printf("[DEBUG] ft_spaces_id 1: %lld\n", result);
	
	// result = params->nb_before_dot - ft_strlen(str);
	// if (DEBUG) printf("[DEBUG] ft_spaces_id 1: %lld\n", result);

	// if (params->dot && params->nb_after_dot > (int) ft_strlen(str))
	// 	result = params->nb_before_dot - params->nb_after_dot;
	// if (DEBUG) printf("[DEBUG] ft_spaces_id 1: %lld\n", result);

	// if (*str == '0' && params->dot && params->nb_after_dot == 0)
	// 	result++;
	// if (DEBUG) printf("[DEBUG] ft_spaces_id 1: %lld\n", result);
	
	// if (result > 0)
	// 	return (result);
	// return (0);

static long long ft_spaces_u(char *str, t_printf_params *params)
{
	long long result;
	result = 0;
	if (params->zero && !params->dot
		&& params->nb_before_dot > params->nb_after_dot)
		return (params->nb_before_dot - ft_strlen(str));
	if (params->nb_before_dot <= params->nb_after_dot)
		return (0);
	result = params->nb_before_dot - ft_strlen(str);
	if (params->dot && params->nb_after_dot > (int) ft_strlen(str))
		result = params->nb_before_dot - params->nb_after_dot;
	if (params->dot && (int)(params->nb_before_dot
			- ft_strlen(str)) > params->nb_after_dot)
		result--;
	if (*str == '0' && params->dot && params->nb_after_dot == 0)
		result++;
	if (result > 0)
		return (result);
	return (0);
}

unsigned int	ft_printf_u(t_printf_params *params, unsigned int n)
{
	unsigned int	size;
	long long		spaces;
	char			*nbr;

	size = 0;
	nbr = ft_uitoa(n);
	if (DEBUG) printf("[DEBUG] Current Str: |%s|\n", nbr);
	if (DEBUG) printf("[DEBUG] Str Length : |%ld|\n", ft_strlen(nbr));
	if (DEBUG) printf("[DEBUG] Has Minus  : %s\n", params->minus ? "Yes" : "No");
	if (DEBUG) printf("[DEBUG] Has Space  : %s\n", params->space ? "Yes" : "No");
	if (DEBUG) printf("[DEBUG] Has Plus   : %s\n", params->plus ? "Yes" : "No");
	if (DEBUG) printf("[DEBUG] Has Zero   : %s\n", params->zero ? "Yes" : "No");
	if (DEBUG) printf("[DEBUG] Nbr before : |%d|\n", params->nb_before_dot);
	if (DEBUG) printf("[DEBUG] Has Dot    : %s\n", params->dot ? "Yes" : "No");
	if (DEBUG) printf("[DEBUG] Nbr after  : |%d|\n", params->nb_after_dot);
	spaces = ft_spaces_u(nbr, params);
	if (DEBUG) printf("[DEBUG] Spaces     : |%lld|\n", spaces);
	while (!params->minus && (!params->zero || params->dot) && spaces-- > 0)
		size += ft_putchar(' ');
	if (params->zero && spaces > 0
		&& (!params->dot || params->nb_after_dot == 0
		|| params->nb_after_dot > params->nb_before_dot))
		size += ft_putnnbr(nbr, &spaces, 0);
	else if (params->dot && params->nb_after_dot > 0)
		size += ft_putnnbr(nbr, (long long *) &(params->nb_after_dot), 1);
	else if (n != 0 || (n == 0 && !params->dot))
		size += ft_putnnbr(nbr, 0, 0);
	while (spaces-- > 0)
		size += ft_putchar(' ');
	free(nbr);
	return (size);
}
