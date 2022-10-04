/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipereir <vipereir@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 10:03:01 by vipereir          #+#    #+#             */
/*   Updated: 2022/10/04 16:44:41 by vipereir         ###   ########.fr       */
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

/* validation functions */
int		map_name(char	*map);
char	**map_create(char	*map_path);

/* sprite put */
void	put_sprite(t_window *win, char *path, int x, int y);


/* print map funcs */
void	initialize_line_row(int *i, int *j, int *x, int *y);
void	set_values(int *i, int *j, int *x, int *y);
void	print_map(t_window *win);
void	create_win(t_window *win);

 /* move player */
void	player_possition(t_window *win);
int		key_hook(int keycode, t_window *win);
void	move_player(t_window *win, int x, int y);

/* others */
void	ft_win(void);

/* close funcs*/

int		close_x(void);
void	map_error(void);

/* map verify */

void	border_valid(t_window *win);
void	info_count(t_window *win);
void	map_size_verify(t_window *win);
void	exit_possition(t_window *win);


void	map_error(void);
void	print_array(char	**map);
size_t	columns_count(char **map);
char	**map_copy(char **map);
void	iterate_map(char **map, int	i, int	j);
int		check_exit(t_window *win, char **map);
int		collect_count(char **map);
void	ft_free_matrix(char **matrix);
int		is_playable(t_window *win);
int		valid_map(t_window *win);
int		key_hook(int keycode, t_window *win);
void	ft_zero(t_window *win);
void	ft_error(t_window *win);

#endif
