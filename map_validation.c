/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:39:22 by vipereir          #+#    #+#             */
/*   Updated: 2022/10/04 17:08:02 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map(t_window *win)
{
	info_count(win);
	border_valid(win);
	map_size_verify(win);
	if (win->p_count != 1 || win->c_count == 0 || 
				win->e_count != 1 || win->error == 1)
		map_error();
	if (is_playable(win) == 1)
		map_error();
	return (0);
}

int	is_playable(t_window *win)
{
	char	**temp;

	player_possition(win);
	temp = map_copy(win->map);
	iterate_map(temp, win->p_x, win->p_y);
//	print_array(temp);
	if (check_exit(win, temp) == 1 || collect_count(temp) == 1)
		return (1);
	ft_free_matrix(temp);
	return (0);
}

int	check_exit(t_window *win, char **map)
{
	exit_possition(win);
	if (map[win->e_y][win->e_x + 1] == 'X'
			|| map[win->e_y][win->e_x - 1] == 'X'
			|| map[win->e_y + 1][win->e_x] == 'X'
			|| map[win->e_y - 1][win->e_x] == 'X')
		return (0);
	return (1);
}

void	iterate_map(char **map, int	i, int	j)
{
	if (map[j][i + 1] == '0' || map[j][i + 1] == 'C')
	{
		map[j][i + 1] = 'X';
		iterate_map(map, i + 1, j);
	}
	if (map[j][i - 1] == '0' || map[j][i - 1] == 'C')
	{
		map[j][i - 1] = 'X';
		iterate_map(map, i - 1, j);
	}
	if (map[j - 1][i] == '0' || map[j - 1][i] == 'C')
	{
		map[j - 1][i] = 'X';
		iterate_map(map, i, j - 1);
	}
	if (map[j + 1][i] == '0' || map[j + 1][i] == 'C')
	{
		map[j + 1][i] = 'X';
		iterate_map(map, i, j + 1);
	}
}

void	border_valid(t_window *win)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	win->line_length = ft_strlen(win->map[0]);
	while (win->map[0][i] != '\n')
	{
		if (win->map[0][i] != '1' || win->map[0][i] != '1')
			return ft_error(win);
		i++;
	}
	while (win->map[j] != NULL)
	{
		if (win->map[j][0] != '1' || win->map[j][win->line_length - 2 ] != '1')
			return (ft_error(win));
		j++;
	}
}

void info_count(t_window *win)
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
		else if (win->map[j][i] != '0' && (win->map[j][i] != '1') && (win->map[j][i] != '\n'))
			win->error = 1;
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
				win->error = 1;
			i = 0;
		}
		i++;
	}
	if (j == line_len -1)
		win->error = 1;
}

int	map_name(char	*map)
{
	int	len;

	len = ft_strlen(map);
	while(len > 4)
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


