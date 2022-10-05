/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:09:41 by vipereir          #+#    #+#             */
/*   Updated: 2022/10/05 09:13:22 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
int	key_hook(int keycode, t_window *win)
{
	player_possition(win);
	//if (keycode == 13)
	if (keycode == 119)
		move_player(win, 0, -1);
	//else if (keycode == 0)
	else if (keycode == 97)
		move_player(win, -1, 0);
	//else if (keycode == 1)
	else if (keycode == 115)
		move_player(win, 0, +1);
	//else if (keycode == 2)
	else if (keycode == 100)
		move_player(win, +1, 0);
	//else if (keycode == 53)
	else if (keycode == 65307)
		exit(0);
	print_map(win);
	return (0);
}*/
/*
void	print_array(char	**map)
{
	int	j;

	j = 0;
	while(map[j] != NULL)
	{
		ft_printf("%s", map[j]);
		j++;
	}
	ft_printf("\n");
}*/

size_t	line_count(char **map)
{
	int	j;

	j = 0;
	while (map[j] != NULL)
		j++;
	return (j);
}

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
	int	j;

	j = 0;
	copy = ft_calloc(1, (sizeof(char *) * ft_strlen(map[j]) * line_count(map)));
	while (map[j] != NULL)
	{
		copy[j] = ft_strdup(map[j]);
		j++;
	}
	return (copy);
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	ft_zero(t_window *win)
{
	win->p_count = 0;
	win->c_count = 0;
	win->e_count = 0;
	win->p_count = 0;
	win->error = 0;
	win->moves = 0;
}
