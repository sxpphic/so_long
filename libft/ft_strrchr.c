/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:12:34 by vipereir          #+#    #+#             */
/*   Updated: 2022/06/09 10:27:18 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*safe;

	safe = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			safe = (char *)s;
	s++;
	}
	if (c == '\0')
		safe = (char *)s;
	return (safe);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	string[42] =  "zaaaaaaaaabbbbccccccbcccccccc";
	char	string2[42] = "zaaaaaaaaabbbbccccccbcccccccc";
	printf("%s\n", strrchr(string, '\0'));
	printf("%s\n", ft_strrchr(string2, '\0'));
	return(0);
}
*/
