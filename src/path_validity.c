/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:48:55 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/04 20:51:38 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_path(t_infos *infos)
{
	char	**map_dup;
	int		res;

	map_dup = ft_map_dup(infos);
	// show_map(map_dup);
	res = try_paths(map_dup, infos->x_p, infos->y_p);
	// show_map(infos->map);
	free_map(map_dup);
	if (!res)
		put_error(ERR_MAP, "no path", 1, infos);
}

char	**ft_map_dup(t_infos *infos)
{
	char	**map_dup;
	int		y;

	y = 0;
	map_dup = malloc(sizeof(*map_dup) * infos->y_max);
	if (!map_dup)
		put_error(ERR, NULL, 1, infos);
	while (infos->map[y])
	{
		map_dup[y] = ft_strdup(infos->map[y]);
		y++;
	}
	// show_map(infos->map);
	map_dup[y] = "\0";
	// show_map(map_dup);
	return (map_dup);
}

int	try_paths(char **map_dup, int x, int y)
{
	if (map_dup[y][x] == 'E')
		return (check_exit_possible(map_dup));
	else if (map_dup[y][x] == '1')
		return (0);
	else
	{
		map_dup[y][x] = '1';
		if (try_paths(map_dup, x, y + 1))
			return (1);
		else if (try_paths(map_dup, x + 1, y))
			return (1);
		else if (try_paths(map_dup, x, y - 1))
			return (1);
		else if (try_paths(map_dup, x - 1, y))
			return (1);
		else
		{
			map_dup[y][x] = '0';
			return (0);
		}
	}
	return (1);
}

int	check_exit_possible(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
