/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:14:39 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/26 11:55:04 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_square(t_data *img, int x, int y, int size, int color)
{
	int	i;

	(void)x;
	i = 0;
	while (i <= size)
		my_mlx_pixel_put(img, (x + i++), y, color);
	i = 0;
	while (i <= size)
		my_mlx_pixel_put(img, x + size, (y + i++), color);
	i = size;
	while (i >= 0)
		my_mlx_pixel_put(img, (x + i--), y + size, color);
	i = size;
	while (i >= 0)
		my_mlx_pixel_put(img, x, (y + i--), color);
}

int	main(void)
{
	int	i;
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	i = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 720, 720, "Hello world!");
	img.img = mlx_new_image(mlx, 720, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	print_square(&img, 5, 5, 20, 0x00FF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
}


