/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 21:08:26 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/20 23:27:14 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	ft_spaces(char *str, int nb_bef, int nb_aft)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (str_len > nb_aft)
		str_len = nb_aft;
	if (nb_bef > str_len)
		return (nb_bef - str_len);
	else
		return (0);
}

size_t	ft_putnstr(char *str, size_t len)
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
	spaces = ft_spaces(str, params->nb_before_dot, params->nb_after_dot);
	size += spaces;
	if (!params->minus)
	{
		while (spaces-- > 0)
			ft_putchar_fd(' ', 0);
	}
	if (params->dot)
		size += ft_putnstr(str, params->nb_after_dot);
	while (spaces-- > 0)
		ft_putchar_fd(' ', 0);
	return (size);
}
