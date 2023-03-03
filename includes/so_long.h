/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:26:52 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/03 19:40:05 by lfreydie         ###   ########.fr       */
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

typedef struct s_position
{
	int					x;
	int					y;
	struct s_position	*next;
}	t_position;

typedef struct s_infos
{
	char		**map;
	int			x_max;
	int			y_max;
	t_position	*perso;
	t_position	*collect;
	t_position	*exit;
}	t_infos;

# define ERROR 1
# define SUCCESS 0
# define ERR_ARG "Invalid number of arguments"
# define ERR_ENV "Environnement error"
# define ERR_MAP "Map error"

//	MAP PARSING
t_infos	*check_map(char *file);
void	check_file_name(char *file);
void	check_map_shape(t_infos *infos);
void	check_map_border(t_infos *infos);
void	check_map_char(t_infos *infos);

//	CREATE MAP
char	**fill_map(int fd, char *file);
int		ft_count_line(int fd);

//	INIT
t_infos	*init_infos(void);

//	FREE
void	free_all(t_infos *infos);
void	free_position(t_position *lst);
void	free_map(char **map);

//	ERROR
void	put_error(char *error, char *file, int code, t_infos *infos);

//	DELETE LATER
void	show_infos(t_infos *infos);
void	show_map(char **map);
void	show_position(t_position *lst);

#endif
