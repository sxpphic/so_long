/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:14:39 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/27 14:47:16 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_sprite(t_window *win, char *path, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(win->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(win->mlx, win->mlx_win, img, x, y);
}
/*
void	put_sprite(t_window *win, char *path)
{
	t_data	img;
	int		img_width;
	int		img_height;

	img.img = mlx_xpm_file_to_image(win->mlx, path, &img_width, &img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(win->mlx, win->mlx_win, img.img, 0, 0);
}*/

int	main(int argc, char *argv[])
{
	t_window	win;

	if (argc != 2 || map_name(argv[1]))
		return (write(2, "error\n", 6));
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx, 500, 500, "so_long");
	win.map = map_create(argv[1]);
	put_sprite(&win, "./assets/wall64.xpm", 0, 0);
	put_sprite(&win, "./assets/wall64.xpm", 15, 0);
	ft_printf("teste");

	mlx_loop(win.mlx);

	return (0);
}

/*
int	main(void)
{

	void	*mlx;
	void	*mlx_win;
	t_data	img;
	char	*relative_path = "./assets/wall64.xpm";
	int		img_width;
	int		img_height;


	ft_printf("teste");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");

	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 64, 0);
	mlx_loop(mlx);

}

*/
