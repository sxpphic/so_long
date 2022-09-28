/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:14:39 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/28 17:09:45 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_window *win, int x, int y)
{
	if (win->map[win->p_y + y][win->p_x + x] == '1')
		return ;
	win->map[win->p_y][win->p_x] = '0';
	win->map[win->p_y + y][win->p_x + x] = 'P';
}

int	key_hook(int keycode, t_window *win)
{
	static int	count;

	player_possition(win);
	if (keycode == 13)
		move_player(win, 0, -1);
	else if (keycode == 0)
		move_player(win, -1, 0);
	else if (keycode == 1)
		move_player(win, 0, + 1);
	else if (keycode == 2)
		move_player(win, +1, 0);
	else if (keycode == 53)
		exit(0);
	count++;
	ft_printf(" %i\n", count);
	print_map(win);
	return (0);
}


int	main(int argc, char *argv[])
{
	t_window	win;

	if (argc != 2 || map_name(argv[1]))
		return (write(2, "error\n", 6));
	win.map = map_create(argv[1]);
	win.mlx = mlx_init();
	create_win(&win);
	print_map(&win);
	ft_printf("%i", win.colect);

	mlx_key_hook(win.win, key_hook, &win);
	mlx_loop(win.mlx);

	return (0);
}
