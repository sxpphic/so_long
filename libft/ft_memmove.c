/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:54:25 by vipereir          #+#    #+#             */
/*   Updated: 2022/11/20 18:01:14 by sphh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void	*dst, const void	*src, size_t	n)
{
	size_t	i;

	if (!dst && !src && n)
		return (0);
	if ((size_t)dst - (size_t)src > n)
		ft_memcpy(dst, src, n);
	else
	{
	i = n - 1;
		//while (i >= 0 && i < n)
		while (i > 0 && i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>
//	while (i >= 0 && i < n)

int	main(void)
{
	// memmove use a buffer and memcpy does not;	
	char	str[42] = "123456789";
	//char	dest[] = "";

	char	str2[42] = "123456789";
	//char	dest2[] = "";

	memmove(str + 3, str, 10);
	printf("%s\n", str);
	ft_memmove(str2 + 3, str2, 10);
	printf("%s\n", str2);
	
	return (0);
}*/
