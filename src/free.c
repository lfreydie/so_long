/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:16:49 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/03 18:43:33 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_all(t_infos *infos)
{
	if (infos)
	{
		if (infos->map)
			free_map(infos->map);
		if (infos->perso)
			free_position(infos->perso);
		if (infos->collect)
			free_position(infos->collect);
		if (infos->exit)
			free_position(infos->exit);
		free(infos);
	}
}

void	free_position(t_position *lst)
{
	t_position	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
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
