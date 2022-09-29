/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 08:19:17 by vipereir          #+#    #+#             */
/*   Updated: 2022/05/31 08:33:49 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (src[l])
		l++;
	if (dstsize == 0)
		return (l);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (l);
}

/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char src[42] = "123456789";
	char dest[42];
	int	aa;
	aa = ft_strlcpy(dest, src, 3);
	printf("%s\n", dest);
	printf("%i\n", aa);
}*/
