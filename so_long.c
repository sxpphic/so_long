/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:14:39 by vipereir          #+#    #+#             */
/*   Updated: 2022/10/03 09:37:09 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(void)
{
	ft_putstr_fd("\033[22;31mError\n\033[0m", 2);
	ft_putstr_fd("\033[22;31mMap error\n\033[0m", 2);
	exit(0);
}

int	valid_map(t_window *win)
{
	info_count(win);
	border_valid(win);
	map_size_verify(win);
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
