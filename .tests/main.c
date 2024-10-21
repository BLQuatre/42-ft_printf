/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:13:06 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/21 04:57:48 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/ft_printf.h"
#include <stdio.h>
#include <assert.h>



// [ ] Testing for %s - Fully operational
/*
int main () 
{
	int count = 0;

	char *test = "%s~\n";
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


// [ ] Testing for %x and %X - Fully operational
/*
int main () 
{
	int count = 0;

	char *test = "%#54.34x~\n";
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

// [ ] Testing for %c - Fully operational
/*
int main () 
{
	int count = 0;

	char *test = "%-43c~\n";
	char to_parse = 'c';
	int size_o = printf(test, to_parse);

	printf("Size O: ~%d~\n", size_o);
	
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
				
				size_t size = ft_printf_c(printf_params, to_parse);
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

int main(void)
{
	ft_printf("~%#X~\n", 42);
	//printf("~%3c~%%~\n", 'a');
}