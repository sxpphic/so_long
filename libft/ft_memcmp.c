/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:49:00 by vipereir          #+#    #+#             */
/*   Updated: 2022/05/31 08:36:44 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void	*s1, const void	*s2, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*temp2;

	temp = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (temp[i] != temp2[i])
			return (temp[i] - temp2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main (void)
{
	char	str[] = "aaaaaabzccccccccc";
	char	st2[] = "aaaaaabccccccccc";
	int	n;

	n = 40;
	printf("original: %d\n", memcmp(str, st2, n));
	printf("      ft: %d\n", ft_memcmp(str, st2, n));
	printf("original: %d\n", memcmp(str, st2, n));
	printf("      ft: %d\n", ft_memcmp(str, st2, n));
	printf("original: %d\n", memcmp(str, st2, n));
	printf("      ft: %d\n", ft_memcmp(str, st2, n));
	printf("original: %d\n", memcmp(str, st2, n));
	printf("      ft: %d\n", ft_memcmp(str, st2, n));
	return (0);
}*/
