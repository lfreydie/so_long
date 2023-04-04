/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:57:19 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/04 14:38:23 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_game(t_infos *infos)
{
	t_data	*game;

	game = ft_init_game(infos);
	if (!game)
		return ;
	ft_init_img(game);
	ft_place_img(game);
	ft_printf("\rstep: %d", game->infos->count_step);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask, \
	&ft_exit, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &ft_listen_event, game);
	mlx_hook(game->win_ptr, 17, 1L << 2, ft_stop_game, game);
	mlx_loop(game->mlx_ptr);
	free_data(game, NULL);
}

t_data	*ft_init_game(t_infos *infos)
{
	t_data	*game;

	game = ft_calloc(sizeof(*game), 1);
	if (!game)
		return (ft_putstr_fd(ERR, 2), free_infos(infos, NULL), NULL);
	game->infos = infos;
	game->img_s = 150;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (free_data(game, ERR_ENV), NULL);
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	infos->x_max * game->img_s, infos->y_max * game->img_s, "so_long");
	if (!game->win_ptr)
		return (free(game->win_ptr), free_data(game, ERR_MLX), NULL);
	return (game);
}
