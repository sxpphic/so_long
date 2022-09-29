/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 07:35:22 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/28 15:40:23 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	params;
	int		len;

	va_start(params, s);
	len = 0;
	while (*s)
	{
		if (*s++ == '%')
			len += ft_print_params(*(s)++, params);
		else if (*--s != '\0')
			len += write(1, s++, 1);
	}
	va_end(params);
	return (len);
}

int	ft_print_params(char c, va_list params)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_print(va_arg(params, int));
	if (c == 's')
		len += ft_putstr_print(va_arg(params, char *));
	if (c == 'i' || c == 'd')
		len += ft_putnbr_print(va_arg(params, int));
	if (c == 'u')
		len += ft_putunbr_print(va_arg(params, unsigned int));
	if (c == 'x')
		len += ft_hex_print('x', va_arg(params, unsigned int));
	if (c == 'X')
		len += ft_hex_print('X', va_arg(params, unsigned int));
	if (c == 'p')
	{
		len += ft_putstr_print("0x");
		len += ft_pointeraddress_print(va_arg(params, unsigned long));
	}
	if (c == '%')
		len += ft_putchar_print('%');
	return (len);
}

/*#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("\n");
	printf("len: %i", ft_printf(" %i", INT_MAX));
	printf("\n");
	printf("len: %i", printf(" %i", INT_MAX));
}*/
