/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:05:52 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/04 20:41:19 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_infos	*init_infos(void)
{
	t_infos	*infos;

	infos = malloc(sizeof(*infos));
	if (!infos)
		put_error("error", NULL, 1, infos);
	else
	{
		infos->map = NULL;
		infos->x_p = 0;
		infos->y_p = 0;
		infos->x_max = 0;
		infos->y_max = 0;
		infos->collect = 0;
	}
	return (infos);
}

char	**fill_map(int fd, char *file)
{
	int		y;
	int		count_line;
	char	*line;
	char	**map;

	y = 0;
	count_line = ft_count_line(fd);
	line = "map";
	map = malloc(sizeof(*map) * count_line);
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free_map(map), NULL);
	while (y < count_line)
	{
		if (!line)
			return (free_map(map), NULL);
		line = get_next_line(fd);
		map[y] = line;
		y++;
	}
	close(fd);
	return (map);
}

int	ft_count_line(int fd)
{
	char	*line;
	int		res;

	line = "file";
	res = 0;
	while (line)
	{
		line = get_next_line(fd);
		res++;
	}
	close(fd);
	return (res);
}

int	take_coordinate_perso(t_infos *infos, int x, int y)
{
	infos->x_p = x;
	infos->y_p = y;
	return (1);
}
