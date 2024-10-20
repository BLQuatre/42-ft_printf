/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:13:06 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/20 05:00:13 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/libftprintf.h"
#include <stdio.h>
#include <assert.h>

// int vout(int max, ...)
// {
//    va_list arg_ptr;
//    va_list args_copy;
//    int args;
//    char *day;
//    va_start(arg_ptr, max); // second arg is max arg we take - so if % + value add one -> how much we take ?
//    va_copy(args_copy, arg_ptr); // copy args into another valist
//    args = 0;
//    while(args < max)
//    {
//       day = va_arg(arg_ptr, char *); // char * corresponding to type
// 	  printf("Day1: %s\n", day); // each time va_arg goes to the next
//       day = va_arg(arg_ptr, char *); // char * corresponding to type
//       printf("Day2: %s\n", day);
//       args+= 2;
//    }
//    va_end(arg_ptr);

//    args = 0;
//    while(args < max)
//    {
//       day = va_arg(args_copy, char *);
//       printf("Day: %s\n", day);
//       args++;
//    }
//    va_end(args_copy); // meaning end of list - cant be used again -> no - end = free
// }





// int main()
// {

// 	printf("%d", (int) 1e3);
// 	// char *test = "Test %, coucou les %d amis";
// 	// // char *find = NULL;
// 	// printf(test, "Zoulou", 42);

// 	// // int i = 0;

// 	// int test_len = ft_strlen(test);

// 	// va_list args_lst;
// 	// va_start()


// 	// while () 
// 	// {
// 	// 	find = ft_strchr(test, '%');
// 	// 	while (i < find) {
// 	// 		ft_putchar_fd(test[i], 0);
// 	// 		i++;
// 	// 	}

// 	// }





int ft_is_parsed_char(char c)
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

	i = 1; // skipping the %
	while (str[i] && ft_is_print_flag(str[i]))
	{
		i++;
	}
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
	else if (c == '.') // more parsing for number behind
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
	t_printf_params *printf_params;

	printf_params = (t_printf_params *) malloc(sizeof(t_printf_params));
	if (!printf_params)
		return (NULL);
	while (*str)
	{
		// printf("char:~%c~\n", *str);
		if (ft_isdigit(*str) && !(printf_params->dot) && !(printf_params->nb_before_dot))
		{
			// printf("Send str: ~%s~\n", str);
			printf_params->nb_before_dot = ft_atoi(str);
		}
		else if (ft_isdigit(*str) && printf_params->dot && !(printf_params->nb_after_dot))
		{
			// printf("Send str2: ~%s~\n", str);
			printf_params->nb_after_dot = ft_atoi(str);
		}
			
		ft_save_flag(&printf_params, *str);
		str++;
	}
	return (printf_params);
}


// 	// char *find = ft_strchr(test, '%');

// 	// ft_putstr_fd(test, 0);
// 	// ft_putstr_fd(". \n", 0);
// 	// ft_putstr_fd(ft_substr(test, 0, find - test), 0);
// 	// ft_putstr_fd(". \n", 0);
// 	// ft_putstr_fd(ft_substr(find, 0, 2), 0);
// 	// ft_putstr_fd(". \n", 0);
// 	// ft_putstr_fd(find + 2, 0);
// 	// ft_putstr_fd(". \n", 0);









// // // 	vout(4, "Sat", "Sun", "re", "eee");
// // //    printf("\n");
// // //    vout(3, "Mon", "Tues", "Wed");


// // 	printf("%s", ft_strchr("Calaca", 'z')); // print NULL because z not in  char *

// // 	int test = 0xFF;


// // 	//int -> hex; pas possible
// // 	// hex -> int

	


	

size_t ft_putint(int value) {
	size_t	size;

    if ( value < 10 ) {
        ft_putchar_fd(48 + value, 0);
        return (1);
    }
    size = ft_putint( value / 10);
    ft_putchar_fd(48 + value % 10, 0);
    return (size + 1);
}

	
// //     // char *test = "Test %s, coucou les %d amis";

// // 	// char *find = ft_strchr(test, '%');

// // 0x30	// ft_putstr_fd(test, 0);
// // 	// ft_putchar_fd('\n', 0);
// // 	// ft_putstr_fd(ft_substr(find, 0, 2), 0);
// // 	// ft_putchar_fd('\n', 0);
// // 	// ft_putstr_fd(find + 2, 0);
// }

// int myPrintf( const char * format, ... ) {

//     va_list parametersInfos;
//     /* Initialize the va_list structure */
//     va_start( parametersInfos, format );

//     size_t writtenCharacters = 0;
//     char currentChar;

// 	currentChar = *format;
//     while (currentChar != '\0') {
// 		currentChar = *format;
//         format ++;
//         if ( currentChar != '%' ) {
//             putchar( currentChar );
//             writtenCharacters ++;
//             continue;
//         }

//         switch( *format++ ) {
//             case 'd':
//                 {
//                     int integerValue = (int) va_arg( parametersInfos, int);
//                     writtenCharacters += displayInteger( integerValue );
//                 }
//                 break;
//             case 'f':
//                 {
//                     double doubleValue = (double) va_arg( parametersInfos, double );
//                     int leftPart = (int) doubleValue;
//                     writtenCharacters += displayInteger( leftPart );
//                     doubleValue -= leftPart;

//                     putchar( '.' );
//                     writtenCharacters ++;

//                     while( ( doubleValue - (int) doubleValue ) > 10e-6 ) {
//                         doubleValue *= 10;
//                     }
//                     writtenCharacters += displayInteger( (int) doubleValue );
//                 }
//                 break;
//             case 's':
//                 {
//                     const char * string = (const char *) va_arg( parametersInfos, const char * );
//                     while( *string != '\0' ) {
//                         putchar( *string ++ );
//                         writtenCharacters ++;
//                     }
//                 }
//                 break;
//             default:
//                 fprintf( stderr, "Specified format is not supported!" );
//                 abort();
//         }
//     }

//     /* Release va_list resources */
//     va_end( parametersInfos );

//     return writtenCharacters;
// }


int main()
{
	// printf("Print flag ? -> %d\n", ft_is_print_flag(' '));
	// printf("Print flag ? -> %d\n", ft_is_print_flag('-'));
	// printf("Print flag ? -> %d\n", ft_is_print_flag('+'));
	// printf("Print flag ? -> %d\n", ft_is_print_flag('e'));
	// printf("Print flag ? -> %d\n", ft_is_parsed_char('d'));
	// printf("Print flag ? -> %d\n", ft_is_parsed_char('s'));
	// printf("Print flag ? -> %d\n", ft_is_parsed_char('f'));
	// printf("Print flag ? -> %d\n", ft_is_parsed_char('g'));
	// printf("Print flag ? -> %d\n", ft_is_parsed_char('%'));
	// printf("Print flag ? -> %d\n", ft_is_parsed_char('g'));
	// printf("Print flag ? -> %d\n", ft_is_parsed_char('b'));


	// printf("Test 1: ~%.2s~", "Coucou"); printf(" - %s\n", "%.2s");
	// // printf("Test 2: ~%+ 23.2d~\n", 4234); printf(" - %s\n", "%.2s"); // flag ' ' is ignored when flag '+' is present
	// printf("Test 3: ~% 4.2d~", 4234); printf(" - %s\n", "% 4.2d"); // space plus number only print ONE space before number
	// //printf("Test 4: ~%4 .2d~", 4234); printf(" - %s\n", "%.2s"); // MARCHE PO
	// printf("Test 5: ~%+-23.2d~", 4234); printf(" - %s\n", "%+-23.2d"); // plus add plus to number and minus add width
	// printf("Test 6: ~%- 23.2d~", 4234); printf(" - %s\n", "%- 23.2d"); // plus add plus to number and minus add width
	// printf("Test 6.2: ~% -23.2d~", 4234); printf(" - %s\n", "% -23.2d"); // plus add plus to number and minus add width
	// // printf("Test 6.5: ~% 23.2d~", 4234); printf(" - %s\n", "% 23.2d"); // plus add plus to number and minus add width
	// // printf("Test 6.7: ~% 23.8d~", 4234); printf(" - %s\n", "% 23.8d"); // plus add plus to number and minus add width
	// // printf("Test 7: ~%+-23d~", 4234); printf(" - %s\n", "%+-23d"); // plus add plus to number and minus add width
	// printf("Test 8: ~%+23d~", 4234); printf(" - %s\n", "%+23d"); // plus add plus to number and minus add width
	// printf("Test 8.2: ~%0+23d~", 4234); printf(" - %s\n", "%0+23d"); // plus add plus to number and minus add width
	// printf("Test 8.5: ~%+023d~", 4234); printf(" - %s\n", "%+023d"); // plus add plus to number and minus add width
	// printf("Test 8.7: ~%+023.10d~", 4234); printf(" - %s\n", "%+023.10d"); // plus add plus to number and minus add width
	// printf("Test 8.8: ~%0+23.10d~", 4234); printf(" - %s\n", "%0+23.10d"); // plus add plus to number and minus add width
	// printf("Test 8.9: ~%+23.5d~", 4234); printf(" - %s\n", "%0+23.10d"); // plus add plus to number and minus add width
	// printf("Test 9: ~%+d~", 4234); printf(" - %s\n", "%+d"); // plus add plus to number and minus add width
	// // printf("Test 8: ~%0-23.2d~", 4234); printf(" - %s\n", "%.2s"); // zero add a lot a zero to the second int // flag '0' is ignored when flag '-' is present
	// printf("Test 10: ~%0.d~", 4234); printf(" - %s\n", "%0.d");
	// printf("Test 11: ~%+-23.2d~", 4234); printf(" - %s\n", "%+-23.2d");
	// printf("Test 12: ~%6.4d~", 4234); printf(" - %s\n", "%6.4d");
	// printf("Test 13: ~%4.6d~", 4234); printf(" - %s\n", "%4.6d");
	// printf("Test 14: ~%25.10d~", 4234); printf(" - %s\n", "%25.10d");

	// 4234                  

	/**
	 * Avec %d:
	 * -> 0 possible pour mettre full 0
	 * -> - possible (pareil qur 0)
	 * -> .nb = afficher nb premier chiffre du nombres (marche pas)
	 * -> # marche po pas de parse 
	 * -> ' ' (space) same behaviour que sans espace pour au debut (only debut not after)
	 * -> + only start -> pas aftet (comme space) -> add plus if number is positive
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 * 
	 */



	printf("Nb: ~%d~\n", ft_atoi(" +34343e"));




	char *test = "%+0#444.23d % -+h sseeeeeee %--s -------- %  +dee";

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
				printf("Space: ~%d~\n", printf_params->space);
				printf("Plus: ~%d~\n", printf_params->plus);
				printf("Int before: ~%d~\n", printf_params->nb_before_dot);
				printf("Int after: ~%d~\n", printf_params->nb_after_dot);
				


				i += ft_strlen(flags_str);
				//ft_putstr_fd("~var~", 0);
			}
		}
		//ft_putchar_fd(*(test + i), 0);
		i++;
	}
}


// int main() {

// 	// printf("%##0 -+.5sfefsef%+0 -d\n", "C   oucou ", 434343);

//     myPrintf( "Begin %s End\n", "Middle" );
//     //assert( size == 17 );

//     myPrintf( "Begin %d End\n", 123 );
//     // assert( size == 14 );

//     myPrintf( "Begin %f End\n", 123.456 );
//     // assert( size == 18 );

//     myPrintf( "Begin %s%d %f End\n", "toto", 421, 123.456 );
//     // assert( size == 27 );

//     return EXIT_SUCCESS;

// }