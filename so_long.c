/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:14:39 by vipereir          #+#    #+#             */
/*   Updated: 2022/10/04 14:26:30 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(void)
{
	ft_putstr_fd("\033[22;31mError\n\033[0m", 2);
	ft_putstr_fd("\033[22;31mMap error\n\033[0m", 2);
	exit(0);
}

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
}

size_t	columns_count(char **map)
{
	int	j;

	j = 0;
	while (map[j] != NULL)
		j++;
	return (j);
}

char	**map_copy(char **map)
{
	char	**copy;
	int	j;

	j = 0;
	copy = ft_calloc(1, (sizeof(char *) * ft_strlen(map[j]) * columns_count(map)));
	while (map[j] != NULL)
	{
		copy[j] = ft_strdup(map[j]);
		j++;
	}
	return (copy);
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

int	is_playable(t_window *win)
{
	char	**temp;

	player_possition(win);
	temp = map_copy(win->map);
	iterate_map(temp, win->p_x, win->p_y);
	print_array(temp);
	if (check_exit(win, temp) == 1 || collect_count(temp) == 1)
		return (1);
	return (0);
}

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

int	key_hook(int keycode, t_window *win)
{
	player_possition(win);
	if (keycode == 13)
	  move_player(win, 0, -1);
	else if (keycode == 0)
	  move_player(win, -1, 0);
	else if (keycode == 1)
	  move_player(win, 0, +1);
	else if (keycode == 2)
	  move_player(win, +1, 0);
	else if (keycode == 53)
		exit(0);
	print_map(win);
	return (0);
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

int	main(int argc, char *argv[])
{
	t_window	win;

	if (argc != 2 || map_name(argv[1]))
		return (write(2, "error\n", 6));
	win.map = map_create(argv[1]);
	ft_zero(&win);
	valid_map(&win);
	win.mlx = mlx_init();
	create_win(&win);
	print_map(&win);
	mlx_hook(win.win, 17, 0, close_x, &win);
	mlx_key_hook(win.win, key_hook, &win);
	mlx_loop(win.mlx);
	return (0);
}
