/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:09:41 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/28 16:52:00 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_name(char	*map)
{
	char	*check;

	check = ft_strrchr(map, '.');
	if (check == 0)
		return (1);
	if (ft_strncmp(check, ".ber", ft_strlen(check)))
		return (1);
	return (0);
}

char	**map_create(char	*map_path)
{
	char	**map;
	char	*line1;
	int		fd;
	int		i;

	i = 0;
	fd = open(map_path, O_RDWR);
	line1 = get_next_line(fd);
	map = ft_calloc(sizeof(char *), ft_strlen(line1) + 1);
	map[i++] = line1;
	while (1)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break;
		i++;
	}
	close(fd);
	return (map);
}

int	put_sprite(t_window *win, char *path, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(win->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(win->mlx, win->win, img, x, y);
	mlx_destroy_image(win->mlx, img);
	return (1);
}

void	set_values(int *i, int *j, int *x, int *y)
{
	(*i) = 0;
	(*j)++;
	(*y) += 64;
	(*x) = 0;
}

void	initialize_line_row(int *i, int *j, int *x, int *y)
{
	(*i) = 0;
	(*j) = 0;
	(*y) = 0;
	(*x) = 0;
}

void	print_map(t_window *win)
{
	int	i;
	int	j;
	int	x;
	int	y;

	initialize_line_row(&i, &j, &x, &y);
	while (win->map[j] != NULL)
	{
		if (win->map[j][i] == '1')
			put_sprite(win, "./assets/wall64.xpm", x, y);
		else if (win->map[j][i] == '0')
			put_sprite(win, "./assets/ground64.xpm", x, y);
		else if (win->map[j][i] == 'P')
			put_sprite(win, "./assets/player64.xpm", x, y);
		else if (win->map[j][i] == 'C')
			win->colect += put_sprite(win, "./assets/colect64.xpm", x, y);
		else if (win->map[j][i] == 'E')
			put_sprite(win, "./assets/exit64.xpm", x, y);
		x += 64;
		i++;
		if (win->map[j][i] == '\n')
			set_values(&i, &j, &x, &y);
	}
}

void	create_win(t_window *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (win->map[0][x] != '\n')
		x++;
	while (win->map[y] != NULL)
		y++;
	win->line_length = x;
	win->win = mlx_new_window(win->mlx, (x * 64), (y * 64), "so_long");
}

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

char	*step_left(t_window *win)
{
	char	*new_row;
	int	i;

	i = 0;
	ft_printf("d");
	new_row = ft_calloc(sizeof(char) * (win->line_length + 2), 1); // +2 para o \n
	while (win->map[win->p_y][i] != '\n')
	{
		if (win->map[win->p_y][i + 1] == 'E' && win->colect == 0)
			exit(0);
		else if (win->map[win->p_y][i] == 'P' && win->map[win->p_y][i + 1] != '1'
				&& (win->map[win->p_y][i + 1] != 'E' && win->colect > 0))
		{
			if (win->map[win->p_y][i + 1] == 'C')
				win->colect--;
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

char	*step_right(t_window *win)
{
	char	*new_row;
	int	i;

	i = 0;
	ft_printf("a");
	new_row = ft_calloc(sizeof(char) * (win->line_length + 2), 1); // +2 para o \n
	while (win->map[win->p_y][i] != '\n')
	{
		if (win->map[win->p_y][i - 1] == 'E' && win->colect == 0)
			exit(0);
		else if (win->map[win->p_y][i] == 'P' && win->map[win->p_y][i - 1] != '1'
				&& win->map[win->p_y][i - 1] != 'E')
		{
			if (win->map[win->p_y][i - 1] == 'C')
				win->colect--;
			new_row[i] = '0';
			new_row[i - 1] = 'P';
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
	win->map[win->p_y - 1] = new_row;
	return (remove_player(win));
}

char	*step_down(t_window *win)
{
	char	*new_row;
	int	i;

	i = 0;
	ft_printf("s");
	if (win->map[win->p_y + 1][win->p_x] == '1')
		return (win->map[win->p_y]);
	new_row = ft_calloc(sizeof(char) * (win->line_length + 2), 1); 
	while (win->map[win->p_y + 1][i] != '\n')
	{
		if (i == win->p_x)
			new_row[i] = 'P';
		else
			new_row[i] = win->map[win->p_y + 1][i];
		i++;
	}
	new_row[i] = '\n';
	i++;
	new_row[i] = '\0';
	win->map[win->p_y + 1] = new_row;
	return (remove_player(win));
}
