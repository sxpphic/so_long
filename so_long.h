/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:03:01 by vipereir          #+#    #+#             */
/*   Updated: 2022/09/28 16:24:23 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "libft/libft.h"
#include <fcntl.h>

typedef struct	s_data {
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_window {
	char	**map;
	void	*mlx;
	void	*win;
	int		p_x;
	int		p_y;
	int		line_length;
	int		colect;
}				t_window;

/* validation functions */
int	map_name(char	*map);
char	**map_create(char	*map_path);

/* sprite put */
int	put_sprite(t_window *win, char *path, int x, int y);


/* print map funcs */
void	initialize_line_row(int *i, int *j, int *x, int *y);
void	set_values(int *i, int *j, int *x, int *y);
void	print_map(t_window *win);
void	create_win(t_window *win);

 /* move player */
char	*remove_player(t_window *win);
char	*step_up(t_window *win);
char	*step_down(t_window *win);
char	*step_left(t_window *win);
char	*step_right(t_window *win);
void	player_possition(t_window *win);
int	key_hook(int keycode, t_window *win);


