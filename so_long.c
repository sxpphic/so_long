/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:14:39 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/29 22:56:33 by sphh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(t_window *win)
{
	win->error = 1;
	return ;
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
//	ft_printf("x :%i\n", win->line_length);
	while (win->map[j] != NULL)
	{
		if (win->map[j][0] != '1' || win->map[j][win->line_length - 2 ] != '1')
			return ft_error(win);
		j++;
	}
}

void info_count(t_window *win)
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

void	map_error(void)
{
	ft_printf("\033[22;31mMap error!\n\033[0m");
	exit(0);
}

int	valid_map(t_window *win)
{
	info_count(win);
	border_valid(win);
	if (win->p_count != 1 || win->c_count == 0 || win->e_count != 1 || win->error == 1)
		map_error();
	return (0);
}

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
