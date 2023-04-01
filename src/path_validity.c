/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:48:55 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/01 17:13:35 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_path(t_infos *infos)
{
	char	**map_dup;
	int		res;

	map_dup = ft_map_dup(infos);
	if (!map_dup)
		return (ft_putstr_fd(ERR, 2), free_infos(infos, NULL), 0);
	res = try_paths(infos, map_dup, infos->x_p, infos->y_p);
	free_map(map_dup);
	if (!res)
		return (free_infos(infos, "no path\n"), 0);
	return (1);
}

char	**ft_map_dup(t_infos *infos)
{
	char	**map_dup;
	int		y;

	y = 0;
	map_dup = ft_calloc(sizeof(*map_dup), infos->y_max + 1);
	if (!map_dup)
		return (NULL);
	while (&map_dup[y] && y < infos->y_max)
	{
		map_dup[y] = ft_strdup(infos->map[y]);
		y++;
	}
	return (map_dup);
}

int	try_paths(t_infos *infos, char **map_dup, int x, int y)
{
	if (map_dup[y][x] == 'E')
		return (check_exit_possible(infos, map_dup));
	else if (map_dup[y][x] == '1')
		return (0);
	else
	{
		map_dup[y][x] = '1';
		if (try_paths(infos, map_dup, x, y + 1))
			return (1);
		else if (try_paths(infos, map_dup, x + 1, y))
			return (1);
		else if (try_paths(infos, map_dup, x, y - 1))
			return (1);
		else if (try_paths(infos, map_dup, x - 1, y))
			return (1);
		else
		{
			map_dup[y][x] = '0';
			return (0);
		}
	}
	return (1);
}

int	check_exit_possible(t_infos *infos, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (y < infos->y_max)
	{
		x = 0;
		while (x < infos->x_max)
		{
			if (map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
