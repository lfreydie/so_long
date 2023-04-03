/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:16:49 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/03 14:59:36 by lfreydie         ###   ########.fr       */
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

void	ft_destroy_img(t_data *game)
{
	if (game->img_0)
		mlx_destroy_image(game->mlx_ptr, game->img_0);
	if (game->img_1)
		mlx_destroy_image(game->mlx_ptr, game->img_1);
	if (game->img_p)
		mlx_destroy_image(game->mlx_ptr, game->img_p);
	if (game->img_c)
		mlx_destroy_image(game->mlx_ptr, game->img_c);
	if (game->img_e)
		mlx_destroy_image(game->mlx_ptr, game->img_e);
	if (game->img_z)
		mlx_destroy_image(game->mlx_ptr, game->img_z);
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
		ft_destroy_img(game);
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

int	ft_exit(t_data *game, char *msg, int err)
{
	free_data(game, NULL);
	if (err)
	{
		ft_putstr_fd(ERR, 2);
		if (msg)
			ft_putstr_fd(msg, 2);
	}
	else
		ft_putstr_fd(msg, 1);
	exit (1);
}
