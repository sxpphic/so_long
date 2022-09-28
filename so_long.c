/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:14:39 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/28 17:55:36 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map(t_window *win)
{
	int	i;
	int j;

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
		if (win->map[j][i] == '\n')
		{
			j++;
			i = 0;
		}
		i++;
	}
}

void	ft_win(void)
{
	ft_printf("\033[22;95mYou Win!\033[0m");
	exit(0);
}

void	move_player(t_window *win, int x, int y)
{
	if (win->map[win->p_y + y][win->p_x + x] == '1')
		return ;
	if (win->map[win->p_y + y][win->p_x + x] == 'E' && win->c_count == 0)
		ft_win();
	else if (win->map[win->p_y + y][win->p_x + x] == 'E' && win->c_count > 0)
		return ;
	if (win->map[win->p_y + y][win->p_x + x] == 'C')
		win->c_count--;
	ft_printf("c_count :%i\n", win->c_count);
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
	valid_map(&win);
	win.mlx = mlx_init();
	create_win(&win);
	print_map(&win);

	mlx_key_hook(win.win, key_hook, &win);
	mlx_loop(win.mlx);

	return (0);
}
