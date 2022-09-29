/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:36:01 by vipereir          #+#    #+#             */
/*   Updated: 2022/06/09 11:28:45 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*temp;

	temp = (char *)s;
	i = 0;
	while (i < n)
	{
		if (c < 0)
		{
			if (temp[i] == c)
				return ((void *)&temp[i]);
		}
		else
		{
			if (temp[i] == (unsigned char)c)
				return ((void *)&temp[i]);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[42] = "aaada\0dsadas";

	printf("%s\n", ft_memchr(str, '\0', 5));
	return (0);
}
*/
