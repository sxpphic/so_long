/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 07:35:38 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/28 15:40:18 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexlen_print(unsigned int c)
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

int	ft_hex_print(char xx, unsigned int nb)
{
	int				len_h;
	unsigned int	a;
	char			*xy;
	char			*x;

	len_h = ft_hexlen_print(nb);
	x = "0123456789abcdef";
	xy = "0123456789ABCDEF";
	a = 0;
	if (nb > 0)
	{
		a = nb % 16;
		if (nb / 16 > 0)
			ft_hex_print(xx, nb / 16);
	}
	if (xx == 'x')
		write(1, &x[a], 1);
	if (xx == 'X')
		write(1, &xy[a], 1);
	return (len_h);
}
