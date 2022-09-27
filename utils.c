/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:09:41 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/27 14:48:52 by vipereir         ###   ########.fr       */
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

void	put_sprite(t_window *win, char *path, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(win->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(win->mlx, win->mlx_win, img, x, y);
}
