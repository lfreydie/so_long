/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:26:52 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/02 18:34:02 by lfreydie         ###   ########.fr       */
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
	void	*img_0;
	void	*img_1;
	void	*img_p;
	void	*img_c;
	void	*img_e;
	void	*img_z;
	int		img_s;
	int		sprite_z;
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
# define ERR_IMG "Image error\n"

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

//	VISUEL
void	ft_init_img(t_data *game);
void	ft_put_img_to_win(t_data *game, int x, int y);
void	ft_place_img(t_data *game);
void	ft_open_exit(t_data *game);

//	EVENT
int		ft_listen_event(int keysym, t_data *game);

//	MOVE
void	ft_move(t_data *game, int diff_x, int diff_y);
void	ft_move_p(t_data *game, int new_x, int new_y);
void	ft_remove_p(t_data *game);

//	ANIM
void	ft_die(t_data *game, int new_x, int new_y);
char	*ft_die_path(t_data *game, char *zombie_path);

//	FREE
void	free_infos(t_infos *infos, char *err);
void	free_map(char **map);
void	ft_destroy_img(t_data *game);
void	free_data(t_data *game, char *err);
int		ft_exit(t_data *game, char *msg, int err);

//	ERROR
void	ft_error(char *error);

//	DELETE LATER
void	show_infos(t_infos *infos);
void	show_map(char **map);

#endif
