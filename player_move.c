/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:46:30 by vipereir          #+#    #+#             */
/*   Updated: 2022/10/06 09:40:22 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_window *win)
{
	if (keycode == 13)
		move_player(win, 0, -1);
	else if (keycode == 0)
		move_player(win, -1, 0);
	else if (keycode == 1)
		move_player(win, 0, +1);
	else if (keycode == 2)
		move_player(win, +1, 0);
	else if (keycode == 53)
		close_x(win);
	mlx_clear_window(win->mlx, win->win);
	print_map(win);
	return (0);
}

void	move_player(t_window *win, int x, int y)
{
	if (win->map[win->p_y + y][win->p_x + x] == '1')
		return ;
	if (win->map[win->p_y + y][win->p_x + x] == 'E' && win->c_count == 0)
		ft_win(win);
	else if (win->map[win->p_y + y][win->p_x + x] == 'E' && win->c_count > 0)
		return ;
	if (win->map[win->p_y + y][win->p_x + x] == 'C')
		win->c_count--;
	win->map[win->p_y][win->p_x] = '0';
	win->map[win->p_y + y][win->p_x + x] = 'P';
	win->p_y += y;
	win->p_x += x;
	win->moves++;
	ft_printf("%i\n", win->moves);
}

void	player_possition(t_window *win)
{
	int	i;
	int	j;

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
