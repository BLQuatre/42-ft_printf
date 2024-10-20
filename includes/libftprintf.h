/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:20:13 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/20 03:47:20 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdarg.h>

typedef struct s_printf_params
{
	int minus;
	int zero;
	int nb_before_dot;
	int dot; // dot value is after the point (%.10s -> dot = 10)
	unsigned int nb_after_dot;
	int hashtag;
	int space;
	int plus;
}	t_printf_params;

int		ft_printf(const char *str, ...) __attribute__((format(printf, 1, 2)));
int		ft_printf_d(t_printf_params printf_params, int value);
void	ft_puthex(int n, int lower);

#endif