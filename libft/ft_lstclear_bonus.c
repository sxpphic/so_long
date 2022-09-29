/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:07:02 by vipereir          #+#    #+#             */
/*   Updated: 2022/06/09 12:07:04 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p;

	p = *lst;
	while (*lst != NULL)
	{
		p = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = p;
	}
	*lst = NULL;
}
