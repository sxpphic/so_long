/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:36:45 by vipereir          #+#    #+#             */
/*   Updated: 2022/06/07 11:28:10 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

/*
#include <stdio.h>
int		main(void)
{
	printf("SIZE: %zu\n", ft_strlen("aasdfsdf"));
	return(0);
}*/
