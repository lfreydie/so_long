/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:26:52 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/01 17:54:59 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <time.h>

typedef struct s_infos
{
	char		**map;
	int			x_p;
	int			y_p;
	int			x_max;
	int			y_max;
	int			count_step;
	int			collect;
}	t_infos;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_infos	*infos;
}	t_data;

# define ERROR 1
# define SUCCESS 0
# define ERR "Error\n"
# define ERR_ARG "Invalid number of arguments\n"
# define ERR_ENV "Environnement error\n"
# define ERR_NOP "The file doesn't open\n"
# define ERR_MAP "Map error\n"
# define ERR_MLX "Minilibx error\n"
# define IMG_SIZE 150

//	MAP PARSING
t_infos	*check_map(char *file);
int		check_file_name(char *file);
int		check_map_shape(t_infos *infos);
int		check_map_border(t_infos *infos);
int		check_map_char(t_infos *infos, int count_p, int count_e);

//	INIT
t_infos	*init_infos(void);
char	**fill_map(int fd, char *file);
int		ft_count_line(int fd);
int		take_coordinate_perso(t_infos *infos, int x, int y);

//	PATH_VALIDITY
int		check_map_path(t_infos *infos);
char	**ft_map_dup(t_infos *infos);
int		try_paths(t_infos *infos, char **map_dup, int x, int y);
int		check_exit_possible(t_infos *infos, char **map);

//	GAME
void	ft_game(t_infos *infos);
t_data	*ft_init_game(t_infos *infos);

//	PLAY
int		handle_no_event(void *game);
int		handle_keypress(int keysym, t_data *game);
void	ft_play(t_data *game);

//	BACKGROUND
void	ft_put_background(t_data *game);

//	FREE
void	free_infos(t_infos *infos, char *err);
void	free_map(char **map);
void	free_data(t_data *game, char *err);

//	ERROR
void	ft_error(char *error);

//	DELETE LATER
void	show_infos(t_infos *infos);
void	show_map(char **map);

#endif
