/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:03:01 by vipereir          #+#    #+#             */
/*   Updated: 2022/10/06 10:57:11 by vipereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_window {
	char	**map;
	void	*mlx;
	void	*win;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		line_length;
	int		c_count;
	int		p_count;
	int		e_count;
	int		error;
	int		moves;
}				t_window;

/* create functions */
char	**map_create(char	*map_path);
int		map_lines(char	*map_path);
void	ft_zero(t_window *win);

/* print map funcs */
void	initialize_line_row(int *i, int *j, int *x, int *y);
void	set_values(int *i, int *j, int *x, int *y);
void	print_map(t_window *win);
void	put_sprite(t_window *win, char *path, int x, int y);
void	create_win(t_window *win);

/* move player */
int		key_hook(int keycode, t_window *win);
void	player_possition(t_window *win);
void	move_player(t_window *win, int x, int y);

/* close funcs*/
void	ft_win(t_window *win);
int		close_x(t_window *win);
void	map_error_free(char *err, t_window *win);
void	map_error(char *err);
void	ft_error(t_window *win);
void	ft_free_matrix(char **matrix);

/* map validation */
int		map_name(char	*map);
int		valid_map(t_window *win);
void	border_valid(t_window *win);
void	info_count(t_window *win);
void	map_size_verify(t_window *win);

int		is_playable(t_window *win);
char	**map_copy(char **map);
size_t	line_count(char	**map);
int		check_exit(t_window *win, char **map);
void	exit_possition(t_window *win);
int		collect_count(char **map);
void	iterate_map(char **map, int i, int j);

#endif
