/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 07:35:02 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/28 15:41:17 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen_print(int c)
{
	int	len;

	if (c == 0)
		return (1);
	len = 0;
	if (c < 0)
		len++;
	while (c)
	{
		c = c / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_print(int n)
{
	int			len_n;
	long int	un;

	len_n = ft_intlen_print(n);
	un = n;
	if (n < 0)
	{
		un *= -1;
		write (1, "-", 1);
	}
	if (un >= 10)
	{
		ft_putnbr_print(un / 10);
	}
	un = (un % 10) + 48;
	ft_putchar_print(un);
	return (len_n);
}

/*
#include <stdio.h>
int	main (void)
{
	int	tamanho;

	tamanho = ft_putnbr_print(0);
	printf("\n len: %i\n", tamanho);
	return (0);
}*/
