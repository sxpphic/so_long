/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:14:39 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/28 11:53:46 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"




int	key_hook(int keycode, t_window *win)
{
	(void)win;
	player_possition(win);
	if (keycode == 13)
		ft_printf("w", keycode);
	else if (keycode == 0)
		win->map[win->p_y] = step_right(win);
	else if (keycode == 1)
		ft_printf("s", keycode);
	else if (keycode == 2)
		win->map[win->p_y] = step_left(win);
	print_map(win);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_window	win;

	if (argc != 2 || map_name(argv[1]))
		return (write(2, "error\n", 6));
	win.mlx = mlx_init();
	win.map = map_create(argv[1]);
	create_win(&win);
	print_map(&win);
	ft_printf("teste");

	mlx_key_hook(win.win, key_hook, &win);
	mlx_loop(win.mlx);

	return (0);
}
