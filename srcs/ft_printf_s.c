/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:08:26 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/22 06:13:02 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_spaces(char *str, int nb_bef, int nb_aft)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (str_len > nb_aft && nb_aft > 0)
		str_len = nb_aft;
	if (nb_bef > str_len)
		return (nb_bef - str_len);
	else
		return (0);
}

static size_t	ft_putnstr(char *str, size_t len)
{
	size_t	count;

	count = 0;
	while (str[count] && count < len)
		ft_putchar_fd(str[count++], 0);
	return (count);
}

size_t	ft_printf_s(t_printf_params *params, char *str)
{
	size_t	size;
	int		spaces;

	size = 0;
	if (!str)
		str = "(null)";
	spaces = ft_spaces(str, params->nb_before_dot, params->nb_after_dot);
	while (!params->minus && spaces-- > 0)
		size += ft_putchar(' ');
	if (params->dot)
		size += ft_putnstr(str, params->nb_after_dot);
	else
		size += ft_putstr(str);
	while (spaces-- > 0)
		size += ft_putchar(' ');
	return (size);
}
