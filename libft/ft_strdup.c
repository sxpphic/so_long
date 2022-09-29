/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:47:40 by vipereir          #+#    #+#             */
/*   Updated: 2022/06/14 10:21:46 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char	*s1)
{
	char	*string;
	size_t	i;

	i = 0;
	string = (char *)malloc(sizeof(*string) * (ft_strlen(s1) + 1));
	if (string == NULL)
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

/*
#include <stdio.h>

int	main (void)
{
	char	*str = "cópia, copy, kopi";
	printf("%s\n", ft_strdup(str));
	return (0);
}*/
