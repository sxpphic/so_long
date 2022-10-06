/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:05:25 by vipereir          #+#    #+#             */
/*   Updated: 2022/10/05 17:07:37 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	info_count(t_window *win)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (win->map[j] != NULL)
	{
		if (win->map[j][i] == 'P')
			win->p_count++;
		else if (win->map[j][i] == 'C')
			win->c_count++;
		else if (win->map[j][i] == 'E')
			win->e_count++;
		else if (win->map[j][i] != '0' && (win->map[j][i] != '1')
				&& (win->map[j][i] != '\n'))
			win->error = -1;
		if (win->map[j][i] == '\n')
		{
			j++;
			i = 0;
		}
		i++;
	}
}

void	map_size_verify(t_window *win)
{
	int	i;
	int	j;
	int	line_len;
	int	next_len;

	i = 0;
	j = 0;
	line_len = ft_strlen(win->map[j]);
	next_len = ft_strlen(win->map[j]);
	while (win->map[j] != NULL)
	{
		if (win->map[j][i] == '\n')
		{
			j++;
			if (win->map[j] != NULL)
				next_len = ft_strlen(win->map[j]);
			if (line_len != next_len)
				win->error = -2;
			i = 0;
		}
		i++;
	}
	if (j == line_len -1)
		win->error = -4;
}

int	map_name(char	*map)
{
	int	len;

	len = ft_strlen(map);
	while (len > 4)
	{
		map++;
		len--;
	}
	return (ft_strncmp(map, ".ber", len));
}

void	exit_possition(t_window *win)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (win->map[j] != NULL)
	{
		if (win->map[j][i] == 'E')
		{
			win->e_x = i;
			win->e_y = j;
		}
		i++;
		if (win->map[j][i] == '\n')
		{
			j++;
			i = 0;
		}
	}
}
