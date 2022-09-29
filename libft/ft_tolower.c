/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:36:06 by vipereir          #+#    #+#             */
/*   Updated: 2022/05/04 13:52:44 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

/*#include <stdio.h>
#include <ctype.h>

int	main(void)
{	
	printf("output: %c\n", ft_tolower('F'));
	return (0);
}*/
