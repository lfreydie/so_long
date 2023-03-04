/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_later.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:05:00 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/04 20:00:10 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	show_infos(t_infos *infos)
{
	if (infos)
	{
		if (infos->map)
			show_map(infos->map);
		ft_printf("x_perso = %d, y_perso = %d\n", infos->x_p, infos->y_p);
		ft_printf("x = %d, y = %d\n", infos->x_max, infos->y_max);
		ft_printf("collect = %d\n", infos->collect);
	}
}

void	show_map(char **map)
{
	int	y;

	y = 0;
	write(1, "map :\n", 6);
	while (map[y])
	{
		ft_printf("%s", map[y]);
		y++;
	}
	write(1, "\n", 1);
}
