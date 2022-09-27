/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:14:39 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/27 11:06:54 by vipereir         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	if (argc != 2 || map_name(argv[1]))
		return (write(2, "error\n", 6));

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
