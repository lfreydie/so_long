/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_later.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:05:00 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/03 19:09:10 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	show_infos(t_infos *infos)
{
	if (infos)
	{
		if (infos->map)
			show_map(infos->map);
		ft_printf("x = %d, y = %d\n", infos->x_max, infos->y_max);
		if (infos->perso)
		{
			write(1, "perso :\n", 8);
			show_position(infos->perso);
		}
		if (infos->collect)
		{
			write(1, "collect :\n", 10);
			show_position(infos->collect);
		}
		if (infos->exit)
		{
			write(1, "exit :\n", 7);
			show_position(infos->exit);
		}
	}
}

void	show_map(char **map)
{
	int	x;
	int	y;

	y = 0;
	write(1, "map :\n", 6);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			write(1, &map[y][x], 1);
			x++;
		}
		y++;
	}
	write(1, "\n", 1);
}

void	show_position(t_position *lst)
{
	while (lst)
	{
		ft_printf("x = %d, y = %d\n", lst->x, lst->y);
		lst = lst->next;
	}
}
