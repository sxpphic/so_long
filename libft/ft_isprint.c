/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:46:00 by vipereir          #+#    #+#             */
/*   Updated: 2022/05/04 10:59:25 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>
int	main(void)
{
	int	n;

	n = '\n';
	printf("output: %i\n", ft_isprint(n));
	printf("output: %i\n", isprint(n));
}*/	
