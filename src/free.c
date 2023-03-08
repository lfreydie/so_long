/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:16:49 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/08 16:58:11 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_all(t_infos *infos)
{
	if (infos)
	{
		if (infos->map)
			free_map(infos->map);
		free(infos);
	}
}

void	free_map(char **map)
{
	int	y;

	y = 0;
	if (!map)
		return ;
	else
	{
		while (map[y])
		{
			free(map[y]);
			y++;
		}
		free(map);
	}
}
