/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:08:29 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/15 16:27:49 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		signal;

	i = 0;
	nb = 0;
	signal = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = signal * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb + (str[i] - '0');
		i++;
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10;
	}
	return (nb * signal);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*num = "       234242343";
	printf("%d\n", atoi(num));
	printf("%d\n", ft_atoi(num));
	printf("%d\n", atoi("-2147483648"));
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", atoi("2147483647"));
	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n", atoi("++++-+-+1234"));
	printf("%d\n", ft_atoi("++++-+-+1234"));
	return (0);
}*/
