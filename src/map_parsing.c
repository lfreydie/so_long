/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:31:41 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/04 20:49:20 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_infos	*check_map(char *file)
{
	int		fd;
	t_infos	*infos;

	if (!file)
		put_error(ERR_MAP, NULL, ERROR, NULL);
	check_file_name(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		put_error(ERR_MAP, file, ERROR, NULL);
	infos = init_infos();
	infos->map = fill_map(fd, file);
	if (!infos->map)
		put_error(ERR_MAP, NULL, 1, infos);
	check_map_shape(infos);
	check_map_border(infos);
	check_map_char(infos, 0, 0, 0);
	check_map_path(infos);
	show_infos(infos);
	return (infos);
}

void	check_file_name(char *file)
{
	int	cmp;

	file = ft_strrchr(file, '.');
	if (!file)
		put_error(ERR_MAP, file, ERROR, NULL);
	cmp = ft_memcmp(file, ".ber", ft_strlen(file));
	if (cmp)
		put_error(ERR_MAP, file, ERROR, NULL);
}

void	check_map_shape(t_infos *infos)
{
	int	y;
	int	x;
	int	size_x;

	y = 0;
	size_x = 0;
	while (infos->map[y][size_x])
		size_x++;
	infos->x_max = size_x - 1;
	y++;
	while (infos->map[y])
	{
		x = 0;
		while (infos->map[y][x])
			x++;
		if (x != size_x)
			put_error(ERR_MAP, NULL, ERROR, infos);
		y++;
	}
	infos->y_max = y;
}

void	check_map_border(t_infos *infos)
{
	char	*check;
	int		y;

	y = 0;
	check = ft_memchr(infos->map[0], '1', infos->x_max);
	if (!check)
		put_error(ERR_MAP, NULL, 1, infos);
	check = ft_memchr(infos->map[infos->y_max - 1], '1', infos->x_max);
	if (!check)
		put_error(ERR_MAP, NULL, 1, infos);
	while (infos->map[y])
	{
		check = ft_memchr(infos->map[y], '1', 1);
		if (!check)
			put_error(ERR_MAP, NULL, 1, infos);
		check = ft_memchr(infos->map[y] + (infos->x_max - 1), '1', 1);
		if (!check)
			put_error(ERR_MAP, NULL, 1, infos);
		y++;
	}
}

void	check_map_char(t_infos *infos, int count_c, int count_p, int count_e)
{
	int	x;
	int	y;

	y = 0;
	while (infos->map[y])
	{
		x = 0;
		while (infos->map[y][x])
		{
			if (infos->map[y][x] == 'C')
				count_c++;
			if (infos->map[y][x] == 'P')
				count_p += take_coordinate_perso(infos, x, y);
			if (infos->map[y][x] == 'E')
				count_e++;
			x++;
		}
		y++;
	}
	if (count_c < 1)
		put_error(ERR_MAP, "not enough collectibles\n", 1, infos);
	else if (count_p != 1 || count_e != 1)
		put_error(ERR_MAP, "map contains duplicates\n", 1, infos);
}
