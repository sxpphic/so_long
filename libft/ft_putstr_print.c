/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 07:34:57 by vipereir          #+#    #+#             */
/*   Updated: 2022/07/28 15:41:31 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_print(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
	{
		write(1, s++, 1);
		len++;
	}
	return (len);
}
