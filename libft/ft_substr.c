/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:26:36 by vipereir          #+#    #+#             */
/*   Updated: 2022/06/07 16:09:09 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const	*s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = (char *)malloc(len * sizeof(*str) + 1);
	if (str == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str[i] = '\0';
		return (str);
	}
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*string = "ABCDEFGHIJ";
	printf("%s\n", string);
	printf("%s\n", ft_substr(string, 3, 30));
	return (0);
}*/
