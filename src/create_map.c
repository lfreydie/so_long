/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:02:35 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/03 18:36:12 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**fill_map(int fd, char *file)
{
	int		y;
	int		count_line;
	char	*line;
	char	**map;

	y = 0;
	count_line = ft_count_line(fd);
	line = "map";
	map = malloc(sizeof(**map) * count_line);
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
