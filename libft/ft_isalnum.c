/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:44:26 by vipereir          #+#    #+#             */
/*   Updated: 2022/05/04 10:22:46 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int n;

	n = '5';
	printf("output: %i\n", ft_isalnum(n));
	printf("output: %i\n", isalnum(n));
}*/
