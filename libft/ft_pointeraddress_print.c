/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointeraddress_print.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 07:35:32 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/28 15:40:22 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexlen_print(unsigned long c)
{
	int	len;

	if (c == 0)
		return (1);
	len = 0;
	while (c)
	{
		c = c / 16;
		len++;
	}
	return (len);
}

int	ft_pointeraddress_print(unsigned long nb)
{
	int				len_p;
	unsigned long	a;
	char			*x;

	len_p = ft_hexlen_print(nb);
	x = "0123456789abcdef";
	a = 0;
	if (nb > 0)
	{
		a = nb % 16;
		if (nb / 16 > 0)
			ft_pointeraddress_print(nb / 16);
	}
	write(1, &x[a], 1);
	return (len_p);
}
