/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:14:39 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/28 11:46:06 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_possition(t_window *win)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (win->map[j] != NULL)
	{
		if (win->map[j][i] == 'P')
		{
			win->p_x = i;
			win->p_y = j;
		}
		i++;
		if (win->map[j][i] == '\n')
		{
			j++;
			i = 0;
		}
	}
}

char	*c_to_s(char c) // char to string
{
	char *s;

	s = malloc(sizeof(char) + 1);
	(*s) = c;
	s++;
	(*s) = '\0';
	return (s);
}

char	*step_left(t_window *win)
{
	char	*new_row;
	int	i;

	i = 0;
	ft_printf("d");
	new_row = ft_calloc(sizeof(char) * (win->line_length + 2), 1); // +2 para o \n
	while (win->map[win->p_y][i] != '\n')
	{
		if (win->map[win->p_y][i] == 'P' && win->map[win->p_y][i + 1] != '1')
		{
			new_row[i] = '0';
			new_row[++i] = 'P';
		}
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
//eu posso meio q fazer a join na mao;

int	key_hook(int keycode, t_window *win)
{
	(void)win;
	player_possition(win);
	if (keycode == 13)
		ft_printf("w", keycode);
	else if (keycode == 0)
		ft_printf("a", keycode);
	else if (keycode == 1)
		ft_printf("s", keycode);
	else if (keycode == 2)
	{
		win->map[win->p_y] = step_left(win);
	}
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
