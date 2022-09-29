/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:13:18 by vipereir          #+#    #+#             */
/*   Updated: 2022/06/09 11:51:08 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char	*s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
void	ft_change(unsigned int	i, char* c)
{
	c[i] = 'A';
}

#include <stdio.h>

// nao to entendendo isso

int	main(void)
{
	char	*voo = "1234";

	ft_striteri(voo, ft_change);
	printf("%s\n", voo);
	return (0);
}*/
