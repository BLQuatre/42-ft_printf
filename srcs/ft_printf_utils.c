/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 03:52:29 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/22 10:40:02 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	if (!str)
		return (ft_putstr("(null)"));
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_nbrlen(n));
}
