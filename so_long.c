/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:14:39 by vipereir          #+#    #+#             */
/*   Updated: 2022/10/04 11:11:56 by vipereir         ###   ########.fr       */
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
	while (map[j][i] != '1')
	{
		map[j][i] = 'X';
		i++;
		if (map[j][i] == '1')
		{
			j++;
			i = 1;
		}
	}
	j = 1;
	i = 1;
	while (map[j][i] != '\n')
	{
		if (map[j][i] == 'X')
			i++;
		if (map[j][i] == '0' && (map[j - 1][i] == 'X'
					|| map[j + 1][i] == 'X'
					|| map[j][i - 1] == 'X'
					|| map[j][i + 1] == 'X'))
			map[j][i] = 'X';
		i++;
		if (map[j][i] == '\n')
		{
			j++;
			i = 1;
			if (map[j] == NULL)
				break ;
		}
	}

}

void	is_playable(t_window *win)
{
	char	**temp;

	temp = map_copy(win->map);
	iterate_map(temp, 1, 1);
	print_array(temp);
}

int	valid_map(t_window *win)
{
	info_count(win);
	border_valid(win);
	map_size_verify(win);
	is_playable(win);
	if (win->p_count != 1 || win->c_count == 0 || 
				win->e_count != 1 || win->error == 1)
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
