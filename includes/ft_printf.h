/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:20:13 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/24 21:51:36 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>

# ifndef DEBUG
#  define DEBUG 0
# endif

typedef struct s_printf_params
{
	char	c;
	int		minus;
	int		zero;
	int		nb_before_dot;
	int		dot;
	int		nb_after_dot;
	int		hashtag;
	int		space;
	int		plus;
}	t_printf_params;

int				ft_printf(const char *str, ...);
				//__attribute__((format(printf, 1, 2)));
size_t			ft_printf_s(t_printf_params *printf_params, char *str);
int				ft_printf_x(t_printf_params *params, unsigned int n, int upper);
size_t			ft_printf_c(t_printf_params *params, char c);
int				ft_printf_id(t_printf_params *params, int n);
unsigned int	ft_printf_u(t_printf_params *params, unsigned int n);
int				ft_printf_p(t_printf_params *params, unsigned long long n);

char			*ft_get_printf_params_str(const char *str);
t_printf_params	*ft_get_printf_params(char *str);

char			*ft_int_to_hex(unsigned long long n, int upper);
char			*ft_ptr_to_hex(unsigned long long n);
size_t			ft_nbrlen(int n);
size_t			ft_unbrlen(unsigned int n);
char			*ft_uitoa(unsigned int n);

int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_putnbr(int n);

#endif