/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:48:05 by vipereir          #+#    #+#             */
/*   Updated: 2022/10/05 14:44:38 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_create(char	*map_path)
{
	char	**map;
	char	*line1;
	int		fd;
	int		i;

	i = 0;
	map = ft_calloc(sizeof(char *), map_lines(map_path));
	fd = open(map_path, O_RDWR);
	line1 = get_next_line(fd);
	if (ft_strlen(line1) < 3)
	{
		free(line1);
		free(map);
		map_error("Map too small");
	}
	map[i++] = line1;
	while (1)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
		i++;
	}
	close(fd);
	return (map);
}

void	put_sprite(t_window *win, char *path, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(win->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(win->mlx, win->win, img, x, y);
	mlx_destroy_image(win->mlx, img);
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
			put_sprite(win, "./assets/colect64.xpm", x, y);
		else if (win->map[j][i] == 'E' && win->c_count > 0)
			put_sprite(win, "./assets/exit64.xpm", x, y);
		else if (win->map[j][i] == 'E' && win->c_count == 0)
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
	win->win = mlx_new_window(win->mlx, (x * 64), (y * 64), "so_long");
}


