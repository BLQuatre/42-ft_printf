/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 01:40:34 by cauvray           #+#    #+#             */
/*   Updated: 2024/10/21 01:43:24 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	myPrintf(const char * format, ...)
{

	va_list	parametersInfos;
	va_start(parametersInfos, format);
	size_t	writtenCharacters = 0;
	char currentChar;

	currentChar = *format;
	while (currentChar != '\0') {
		currentChar = *format;
		format ++;
		if ( currentChar != '%' ) {
			putchar( currentChar );
			writtenCharacters ++;
			continue;
		}

		switch( *format++ ) {
			case 'd':
				{
					int integerValue = (int) va_arg(parametersInfos, int);
					writtenCharacters += displayInteger(integerValue);
				}
				break;
			case 'f':
				{
					double doubleValue = (double) va_arg(parametersInfos, double);
					int leftPart = (int) doubleValue;
					writtenCharacters += displayInteger(leftPart);
					doubleValue -= leftPart;

					putchar( '.' );
					writtenCharacters ++;

					while((doubleValue - (int) doubleValue) > 10e-6) {
						doubleValue *= 10;
					}
					writtenCharacters += displayInteger((int) doubleValue);
				}
				break;
			case 's':
				{
					const char * string = (const char *) va_arg(parametersInfos, const char *);
					while(*string != '\0') {
						putchar(*string++);
						writtenCharacters ++;
					}
				}
				break;
			default:
				fprintf(stderr, "Specified format is not supported!");
				abort();
		}
	}
	va_end(parametersInfos);
	return (writtenCharacters);
}
