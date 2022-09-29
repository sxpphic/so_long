/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 07:34:32 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/28 15:40:48 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen_print(unsigned int c)
{
	int	len;

	if (c == 0)
		return (1);
	len = 0;
	while (c)
	{
		c = c / 10;
		len++;
	}
	return (len);
}

int	ft_putunbr_print(unsigned int n)
{
	char		c;
	int			len_u;

	len_u = ft_intlen_print(n);
	if (n >= 10)
	{
		ft_putunbr_print(n / 10);
		n = n % 10;
	}
	c = n + 48;
	write (1, &c, 1);
	return (len_u);
}
