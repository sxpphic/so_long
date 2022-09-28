/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:14:39 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/28 13:42:38 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*remove_player(t_window *win)
{
	char	*new_row;
	int	i;

	i = 0;
	new_row = ft_calloc(sizeof(char) * (win->line_length + 2), 1); // +2 para o \n
	while (win->map[win->p_y][i] != '\n')
	{
		if (win->map[win->p_y][i] == 'P')
			new_row[i] = '0';
		else
			new_row[i] = win->map[win->p_y][i];
		i++;
	}
	new_row[i] = '\n';
	i++;
	new_row[i] = '\0';
	free(win->map[win->p_y]);
	return (new_row);
}


char	*step_up(t_window *win)
{
	char	*new_row;
	int	i;

	i = 0;
	ft_printf("w");
	if (win->map[win->p_y - 1][win->p_x] == '1')
		return (win->map[win->p_y]);
	new_row = ft_calloc(sizeof(char) * (win->line_length + 2), 1); 
	while (win->map[win->p_y - 1][i] != '\n')
	{
		if (i == win->p_x)
			new_row[i] = 'P';
		else
			new_row[i] = win->map[win->p_y - 1][i];
		i++;
	}
	new_row[i] = '\n';
	i++;
	new_row[i] = '\0';
	//free(win->map[win->p_y - 1]);
	win->map[win->p_y - 1] = new_row;
	return (remove_player(win));
}


int	key_hook(int keycode, t_window *win)
{
	(void)win;
	player_possition(win);
	if (keycode == 13)
			win->map[win->p_y] = step_up(win);
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
