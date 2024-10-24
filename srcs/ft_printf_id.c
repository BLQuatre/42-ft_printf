/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:21:01 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/24 22:51:11 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static long	ft_spaces_id(char *str, t_printf_params *params)
{
	long result;

	result = 0;
	if (DEBUG) printf("[DEBUG] ft_spaces_id 1: %ld\n", result);
	if (*str == '-' && params->zero && !params->dot && params->nb_before_dot > params->nb_after_dot)
		return (params->nb_before_dot - ft_strlen(str));
	if (DEBUG) printf("[DEBUG] ft_spaces_id 2: %ld\n", result);
	if (params->nb_before_dot <= params->nb_after_dot)
		return (0);
		
	result = params->nb_before_dot - ft_strlen(str);
	if (DEBUG) printf("[DEBUG] ft_spaces_id 3: %ld\n", result);

	// Ajustement pour les cas où `dot` et `zero` sont présents
	if (params->dot && params->nb_after_dot > (int) ft_strlen(str))
		result = params->nb_before_dot - params->nb_after_dot;
	if (DEBUG) printf("[DEBUG] ft_spaces_id 4: %ld\n", result);

	// Ajustement si un signe ou un espace est requis
	if ((*str == '-' && params->dot) || params->plus || params->space)
		result--;
	if (DEBUG) printf("[DEBUG] ft_spaces_id 5: %ld\n", result);

	if (*str == '0' && params->dot && params->nb_after_dot == 0)
		result++;
	// Assurez-vous que le résultat est au moins 0
	return (result > 0 ? result : 0);
}

static int	ft_putnnbr(char *str, long *len, int remove_len)
{
	int count = 0;

	// Gestion du signe négatif
	if (*str == '-')
		count += ft_putchar(*str++);

	// Remplir avec des zéros si nécessaire
	if (len && remove_len)
		*len -= ft_strlen(str);
	while (len && (*len)-- > 0)
		count += ft_putchar('0');

	// Impression du reste de la chaîne
	while (*str)
		count += ft_putchar(*str++);

	return (count);
}

int	ft_printf_id(t_printf_params *params, int n)
{
	int		size = 0;
	long	spaces;
	char	*nbr;

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

	// Gérer les flags `space` et `plus`
	if (params->space && n >= 0)
		size += ft_putchar(' ');
	else if (params->plus && n >= 0)
		size += ft_putchar('+');

	while (!params->minus && (!params->zero || params->dot) && spaces-- > 0)
		size += ft_putchar(' ');
	

	// Impression du nombre, en prenant en compte les zéros
	if (params->zero && spaces > 0 && (!params->dot || params->nb_after_dot == 0))
		size += ft_putnnbr(nbr, &spaces, 0);
	else if (params->dot && params->nb_after_dot > 0)
		size += ft_putnnbr(nbr, (long *) &(params->nb_after_dot), 1);
	else if (n != 0 || (n == 0 && !params->dot))
		size += ft_putnnbr(nbr, 0, 0);

	while (spaces-- > 0)
		size += ft_putchar(' ');

	free(nbr);
	return (size);
}
