/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:31:41 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/01 18:32:55 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_infos	*check_map(char *file)
{
	int		fd;
	t_infos	*infos;

	if (!check_file_name(file))
		return (ft_error("wrong filename\n"), NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_error(ERR_NOP), NULL);
	infos = init_infos();
	if (!infos)
		return (NULL);
	infos->map = fill_map(fd, file);
	if (!infos->map)
		return (free_infos(infos, NULL), NULL);
	if (!check_map_shape(infos))
		return (NULL);
	if (!check_map_border(infos))
		return (NULL);
	if (!check_map_char(infos, 0, 0))
		return (NULL);
	if (!check_map_path(infos))
		return (NULL);
	return (infos);
}

int	check_file_name(char *file)
{
	int	cmp;

	file = ft_strrchr(file, '.');
	if (!file)
		return (0);
	cmp = ft_memcmp(file, ".ber", ft_strlen(file));
	if (cmp)
		return (0);
	return (1);
}

int	check_map_shape(t_infos *infos)
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
			return (free_infos(infos, "Map must be rectangular\n"), 0);
		y++;
	}
	infos->y_max = y;
	if (infos->y_max > 9 || infos->x_max > 17)
		return (free_infos(infos, "Map too big to play\n"), 0);
	return (1);
}

int	check_map_border(t_infos *infos)
{
	int	y;
	int	x;

	y = -1;
	while (++y < infos->y_max - 1)
	{
		x = -1;
		while (++x < infos->x_max - 1)
		{
			if ((y == 0 || y == infos->y_max - 1)
				&& infos->map[y][x] != '1')
				return (ft_printf("%d\n", infos->map[y][x]), \
				ft_printf("x=%d, x_m=%d\n", x, infos->x_max), \
				ft_printf("y=%d, y_m=%d\n", y, infos->y_max), \
				free_infos(infos, "There are some leaks on walls\n"), 0);
			if ((x == 0 || x == infos->x_max - 1)
				&& infos->map[y][x] != '1')
				return (ft_printf("%d\n", infos->map[y][x]), \
				ft_printf("x=%d, x_m=%d\n", x, infos->x_max), \
				ft_printf("y=%d, y_m=%d\n", y, infos->y_max), \
				free_infos(infos, "There are some leaks on walls\n"), 0);
		}
	}
	return (1);
}

int	check_map_char(t_infos *infos, int count_p, int count_e)
{
	int	x;
	int	y;

	y = 0;
	while (y < infos->y_max)
	{
		x = 0;
		while (x < infos->x_max)
		{
			if (infos->map[y][x] == 'C')
				infos->collect++;
			else if (infos->map[y][x] == 'P')
				count_p += take_coordinate_perso(infos, x, y);
			else if (infos->map[y][x] == 'E')
				count_e++;
			else if (infos->map[y][x] != '1' && infos->map[y][x] != '0')
				return (free_infos(infos, "map contains false charactere\n"), 0);
			x++;
		}
		y++;
	}
	if (infos->collect == 0 || count_p != 1 || count_e != 1)
		return (free_infos(infos, "map isn't correctly configure\n"), 0);
	return (1);
}
