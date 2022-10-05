/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:51:01 by vipereir          #+#    #+#             */
/*   Updated: 2022/10/05 09:52:51 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collect_count(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		if (map[j][i] == 'C')
			return (1);
		if (map[j][i] == '\n')
		{
			j++;
			i = 0;
		}
		i++;
	}
	return (0);
}

char	**map_copy(char **map)
{
	char	**copy;
	int		j;

	j = 0;
	copy = ft_calloc(sizeof(char *), line_count(map) + 1);
	while (map[j] != NULL)
	{
		copy[j] = ft_strdup(map[j]);
		j++;
	}
	return (copy);
}
