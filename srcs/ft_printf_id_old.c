/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_id_old.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:08:26 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/24 22:36:17 by cauvray          ###   ########.fr       */
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
static long	ft_spaces_id(char *str, t_printf_params *params)
{
	if (*str == '-' && params->zero && !params->dot && params->nb_before_dot < params->nb_after_dot) // manque un truc avec dot
		return (params->nb_after_dot - ft_strlen(str) + 1);
		

	long	result;
	if (DEBUG) printf("[DEBUG] ft_spaces_id 0\n");
	if (params->nb_before_dot < params->nb_after_dot && !params->zero)
		return (0);
	if (DEBUG) printf("[DEBUG] ft_spaces_id 0.1\n");
	if (params->nb_before_dot > params->nb_after_dot && !params->zero && params->nb_after_dot < (int) ft_strlen(str))
		return (params->nb_before_dot - ft_strlen(str));
	if (DEBUG) printf("[DEBUG] ft_spaces_id 0.2\n");
	if (params->dot && params->nb_before_dot == 0 && params->nb_after_dot > (int) ft_strlen(str) && *str == '-')
		return (params->nb_after_dot - ft_strlen(str) + 1);
	result = params->nb_after_dot - ft_strlen(str);
	if (DEBUG) printf("[DEBUG] ft_spaces_id 0.5: %ld\n", result);
	if (*str == '-' && params->dot)
	{
		result--;
		if (DEBUG) printf("[DEBUG] Removing minus from resulr\n");
	}
	if (params->space || params->plus)
	{
		if (DEBUG) printf("[DEBUG] Removing space or plus from result\n");
		result--;
	}
	if (DEBUG) printf("[DEBUG] ft_spaces_id 1: %ld\n", result);
	if (params->nb_before_dot < params->nb_after_dot)
		return (result);

	result = params->nb_before_dot - params->nb_after_dot;
	if (DEBUG) printf("[DEBUG] ft_spaces_id 2: %ld\n", result);
	if (params->space || params->plus || (*str == '-' && params->dot))
		result--;
	if (DEBUG) printf("[DEBUG] ft_spaces_id 3: %ld\n", result);
	if ((params->nb_before_dot > params->nb_after_dot
			&& params->nb_after_dot > 0)
		|| params->nb_before_dot == params->nb_after_dot)
	{
		if (DEBUG) printf("[DEBUG] ft_spaces_id 4: %ld\n", result);
		return (result);
	}
	if (params->dot && params->nb_after_dot == 0)
		result++;
	if (DEBUG) printf("[DEBUG] ft_spaces_id 5: %ld\n", result - ft_strlen(str));
	return (result - ft_strlen(str));
}

static int	ft_putnnbr(char *str, long *len, int remove_len)
{
	int	count;
	count = 0;

	if (*str == '-')
		count += ft_putchar(*str++);
	if (len)
	{
		if (remove_len)
			*(len) -= ft_strlen(str);
		while ((*len)-- > 0)
			count += ft_putchar('0');
	}
	while (*str)
		count += ft_putchar(*str++);
	return (count);
}

int	ft_printf_id(t_printf_params *params, int n)
{
	int				size;
	long			spaces;
	char			*nbr;

	size = 0;
	nbr = ft_itoa(n);
	if (DEBUG) printf("[DEBUG] Current Str: |%s|\n", nbr);
	if (DEBUG) printf("[DEBUG] Str Length : |%ld|\n", ft_strlen(nbr));
	if (DEBUG) printf("[DEBUG] Has Minus  : %s\n", params->minus ? "Yes" : "No");
	if (DEBUG) printf("[DEBUG] Has Space  : %s\n", params->space ? "Yes" : "No");
	if (DEBUG) printf("[DEBUG] Has Plus   : %s\n", params->plus ? "Yes" : "No");
	if (DEBUG) printf("[DEBUG] Has Zero   : %s\n", params->zero ? "Yes" : "No");
	if (DEBUG) printf("[DEBUG] Nbr before : |%d|\n", params->nb_before_dot);
	if (DEBUG) printf("[DEBUG] Has Dot    : %s\n", params->dot ? "Yes" : "No");
	if (DEBUG) printf("[DEBUG] Nbr after  : |%d|\n", params->nb_after_dot);
	spaces = ft_spaces_id(nbr, params);
	if (DEBUG) printf("[DEBUG] Spaces     : |%ld|\n", spaces);
	while (!params->minus && (!params->zero || params->dot) && spaces-- > 0)
		size += ft_putchar(' ');
	if (params->space && !params->plus && n >= 0)
		size += ft_putchar(' ');
	else if (params->plus && n >= 0)
		size += ft_putchar('+');
	if (params->zero && spaces > 0 && (params->nb_after_dot > 0 || !params->dot))
		size += ft_putnnbr(nbr, &spaces, 0);
	else if (params->dot && params->nb_after_dot > 0)
		size += ft_putnnbr(nbr, (long *) &(params->nb_after_dot), 1);
	else if (!params->dot || (params->dot && params->nb_after_dot > 0))
		size += ft_putnnbr(nbr, 0, 0);
	while (spaces-- > 0)
		size += ft_putchar(' ');
	free(nbr);
	return (size);
}
