/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:05:40 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/21 18:19:14 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_test(t_printf_params *params)
{
	free(params);
	return (0);
}

// ft_check_params(t_printf_params *params)
// {
// 	t_printf_params	*params;
// 	int				print_length;

// 	params = ft_get_printf_params(params_str);
// 	if (!params)
// 		return (ft_test(params));
// }

int	ft_formats(va_list args, char *params_str)
{
	t_printf_params	*params;
	int				print_length;

	params = ft_get_printf_params(params_str);
	if (!params)
		return (ft_test(params));
	print_length = 0;
	if (params->c == 'c')
		print_length += ft_printf_c(params, va_arg(args, int));
	else if (params->c == 's')
		print_length += ft_printf_s(params, va_arg(args, char *));
	//else if (params->c == 'p')
	//	print_length += ft_print_ptr(va_arg(args, unsigned long long));
	//else if (params->c == 'd' || params->c == 'i')
	//	print_length += ft_printnbr(va_arg(args, int));
	//else if (params->c == 'u')
	//	print_length += ft_print_unsigned(va_arg(args, unsigned int));
	//else if (params->c == 'x') // FIXME : BIG VALGRIND
	//	print_length += ft_printf_x(params, va_arg(args, unsigned int), 0);
	//else if (params->c == 'X')
	//	print_length += ft_printf_x(params, va_arg(args, unsigned int), 1);
	else if (params->c == '%')
		print_length += ft_putchar('%');
	free(params);
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;
	char	*params_str;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			params_str = ft_get_printf_params_str(str + i);
			if (params_str)
			{
				print_length += ft_formats(args, params_str);
				i += ft_strlen(params_str);
			}
			free(params_str);
		}
		else
			print_length += ft_putchar(str[i++]);
	}
	va_end(args);
	return (print_length);
}
