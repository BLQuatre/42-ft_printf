/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:13:06 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/21 01:47:41 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/libftprintf.h"
#include <stdio.h>
#include <assert.h>

int	ft_is_parsed_char(char c)
{
	char	*str;

	str = "cspdiuxX%";
	while (*str)
	{
		if (c == *str++)
			return (1);
	}
	return (0);
}

int	ft_is_print_flag(char c)
{
	char	*str;

	str = "-0.# +";
	while (*str)
	{
		if (ft_isdigit(c) || c == *str++)
			return (1);
	}
	return (0);
}

char	*ft_get_printf_params_str(char *str)
{
	int	i;

	i = 1;
	while (str[i] && ft_is_print_flag(str[i]))
		i++;
	if (!ft_is_parsed_char(str[i]))
		return (NULL);
	return (ft_substr(str, 0, i + 1));
}

void	ft_save_flag(t_printf_params **printf_params, char c)
{
	if (c == '-')
		(*printf_params)->minus = 1;
	else if (c == '0')
		(*printf_params)->zero = 1;
	else if (c == '.')
		(*printf_params)->dot = 1;
	else if (c == '#')
		(*printf_params)->hashtag = 1;
	else if (c == ' ')
		(*printf_params)->space = 1;
	else if (c == '+')
		(*printf_params)->plus = 1;
}

t_printf_params	*ft_get_printf_params(char *str)
{
	t_printf_params	*params;

	params = (t_printf_params *) malloc(sizeof(t_printf_params));
	if (!params)
		return (NULL);
	while (*str)
	{
		if (ft_isdigit(*str) && !(params->dot) && !(params->nb_before_dot))
			params->nb_before_dot = ft_atoi(str);
		else if (ft_isdigit(*str) && params->dot && !(params->nb_after_dot))
			params->nb_after_dot = ft_atoi(str);
		ft_save_flag(&params, *str);
		str++;
	}
	return (params);
}

// [ ] Testing for %s
/*
int main () 
{
	int count = 0;

	char *test = "%10.2s~\n";
	char *to_parse = "Coucou les amis";
	size_t size_o = printf(test, to_parse);

	printf("Size O: ~%zu~\n", size_o);

	int i = 0;
	while (test[i]) {
		if (test[i] == '%')
		{

			char *flags_str = ft_get_printf_params_str(test + i);
			if (flags_str)
			{
				t_printf_params *printf_params = ft_get_printf_params(flags_str);

				printf("--------------\n");
				printf("Flags: ~%s~\n", flags_str);
				printf("Minus: ~%d~\n", printf_params->minus);
				//printf("Zero: ~%d~\n", printf_params->zero);
				printf("Dot: ~%d~\n", printf_params->dot);
				//printf("Hashtag: ~%d~\n", printf_params->hashtag);
				//printf("Space: ~%d~\n", printf_params->space);
				//printf("Plus: ~%d~\n", printf_params->plus);
				printf("Int before: ~%d~\n", printf_params->nb_before_dot);
				printf("Int after: ~%d~\n", printf_params->nb_after_dot);
				printf("Char : ~%c~\n", flags_str[ft_strlen(flags_str) - 1]);

				printf("--- Test ---\n");
				
				size_t size = ft_printf_s(printf_params, to_parse);
				printf("~\n");
				printf("Size: ~%zu~\n", size);
				printf("------\n");

				i += ft_strlen(flags_str);
				count += size;
				//ft_putstr_fd("~var~", 0);
			}
		}
		//ft_putchar_fd(test[i], 0);
		i++;
		count++;
	}

	printf("MY BUFF SIZE ? ~%d~\n", count);
}
*/

// TODO: FIX HEX
/*
int main () 
{
	int count = 0;

	char *test = "%23.45x~\n";
	int to_parse = 42;
	size_t size_o = printf(test, to_parse);

	printf("Size O: ~%zu~\n", size_o);
	
	int i = 0;
	while (test[i]) {
		if (test[i] == '%')
		{

			char *flags_str = ft_get_printf_params_str(test + i);
			if (flags_str)
			{
				t_printf_params *printf_params = ft_get_printf_params(flags_str);

				printf("--------------\n");
				printf("Flags: ~%s~\n", flags_str);
				printf("Minus: ~%d~\n", printf_params->minus);
				printf("Zero: ~%d~\n", printf_params->zero);
				printf("Dot: ~%d~\n", printf_params->dot);
				printf("Hashtag: ~%d~\n", printf_params->hashtag);
				//printf("Space: ~%d~\n", printf_params->space);
				//printf("Plus: ~%d~\n", printf_params->plus);
				printf("Int before: ~%d~\n", printf_params->nb_before_dot);
				printf("Int after: ~%d~\n", printf_params->nb_after_dot);
				printf("Char : ~%c~\n", flags_str[ft_strlen(flags_str) - 1]);

				printf("--- Test ---\n");
				
				size_t size = ft_printf_x(printf_params, to_parse);
				printf("~\n");
				printf("Size: ~%zu~\n", size);
				printf("------\n");

				i += ft_strlen(flags_str);
				count += size;
				//ft_putstr_fd("~var~", 0);
			}
		}
		//ft_putchar_fd(test[i], 0);
		i++;
		count++;
	}

	printf("MY BUFF SIZE ? ~%d~\n", count);
}
*/
