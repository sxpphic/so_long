/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:19:18 by vipereir          #+#    #+#             */
/*   Updated: 2022/05/04 11:00:07 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
#include <ctype.h>
#include <stdio.h>
int	main(void)
{
	int	n;

	n = '5';
	printf("output: %i\n", ft_isdigit(n));
	printf("output: %i\n", isdigit(n));
}
*/
