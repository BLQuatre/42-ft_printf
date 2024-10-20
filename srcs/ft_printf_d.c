/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 09:44:08 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/19 18:27:16 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void st_printf_d_params(t_printf_params **printf_params, char c)
{
	if (c == ' ' && )

}

int	ft_printf_d(char *str, int value)
{
	str++;

	t_printf_params *printf_params = (t_printf_params *) malloc(sizeof(t_printf_params));
	if (!printf_params)
		return NULL;
	while (*str != 'd' && *str != '.')
	{
		if (*str == '')
	}

	



	ft_putnbr_fd(value, 0);
}