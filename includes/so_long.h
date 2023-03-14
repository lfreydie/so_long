/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:26:52 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/14 15:42:37 by lfreydie         ###   ########.fr       */
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
	int			collect;
}	t_infos;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

# define ERROR 1
# define SUCCESS 0
# define ERR "Error\n"
# define ERR_ARG "Error\nInvalid number of arguments"
# define ERR_ENV "Error\nEnvironnement error"
# define ERR_MAP "Error\nMap error"
# define ERR_MLX "Error\nMinilibx error"
# define IMG_W 60
# define IMG_H 60

//	MAP PARSING
t_infos	*check_map(char *file);
void	check_file_name(char *file);
void	check_map_shape(t_infos *infos);
void	check_map_border(t_infos *infos);
void	check_map_char(t_infos *infos, int count_p, int count_e);

//	CREATE MAP
char	**fill_map(int fd, char *file);
int		ft_count_line(int fd);

//	INIT
t_infos	*init_infos(void);
int		take_coordinate_perso(t_infos *infos, int x, int y);

//	PATH_VALIDITY
void	check_map_path(t_infos *infos);
char	**ft_map_dup(t_infos *infos);
int		try_paths(t_infos *infos, char **map_dup, int x, int y);
int		check_exit_possible(t_infos *infos, char **map);

//	GAME
void	ft_game(t_infos *infos);

//	FREE
void	free_all(t_infos *infos);
void	free_map(char **map);

//	ERROR
void	put_error(char *error, char *explc, int code, t_infos *infos);

//	DELETE LATER
void	show_infos(t_infos *infos);
void	show_map(char **map);

#endif
