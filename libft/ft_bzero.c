/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:10:04 by vipereir          #+#    #+#             */
/*   Updated: 2022/05/27 11:16:47 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*tempchar;

	i = 0;
	tempchar = (char *)s;
	while (i < n)
	{
		tempchar[i] = '\0';
		i++;
	}
}

/*
#include <stdio.h>
#include <strings.h>

int	main(void)
{
	char st2[42] = "asdfasdfasdfa";
	char str[42] = "asdfasdfasdfa";
	int	i;
	
	// bzero test
	i = 0;
	printf("%s\n", str);
	bzero(str, 7);
	while (i++ < 10)
		printf("%i", str[i]);
	printf("\n");
	// ft_bzero test
	i = 0;
	printf("%s\n", st2);
	ft_bzero(st2, 7);
	while (i++ < 10)
		printf("%i", st2[i]);
	return (0);
}*/
