/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:16:49 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/01 18:29:22 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_infos(t_infos *infos, char *err)
{
	if (err)
	{
		ft_putstr_fd(ERR, 2);
		ft_putstr_fd(err, 2);
	}
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

void	free_data(t_data *game, char *err)
{
	if (err)
	{
		ft_putstr_fd(ERR, 2);
		ft_putstr_fd(err, 2);
	}
	if (game)
	{
		if (game->infos)
			free_infos(game->infos, NULL);
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		if (game->mlx_ptr)
		{
			mlx_destroy_display(game->mlx_ptr);
			free(game->mlx_ptr);
		}
		free(game);
	}
}
