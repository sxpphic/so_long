/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:13:30 by vipereir          #+#    #+#             */
/*   Updated: 2022/06/07 09:50:15 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int c)
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

char	*ft_itoa(int n)
{
	char			*nb;
	int				t;
	unsigned int	nn;

	t = ft_intlen(n);
	nn = n;
	nb = malloc(sizeof(char) * t + 1);
	if (nb == NULL)
		return (NULL);
	nb[0] = '0';
	if (n < 0)
		nb[0] = '-';
	if (n < 0)
		nn = -n;
	nb[t--] = '\0';
	while (nn > 0)
	{
		nb[t--] = nn % 10 + '0';
		nn = nn / 10;
	}
	return (nb);
}

/*
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_intlen(+1000));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(1));
	printf("%s\n", ft_itoa(2));
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(INT_MIN));
	printf("%s\n", ft_itoa('\0'));
	return (0);
}*/
