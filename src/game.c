/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:57:19 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/01 18:39:30 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_game(t_infos *infos)
{
	t_data	*game;

	game = ft_init_game(infos);
	if (!game)
		return ;
	// ft_put_background(game);
	// ft_play(game);
	free_data(game, NULL);
}

t_data	*ft_init_game(t_infos *infos)
{
	t_data	*game;

	game = ft_calloc(sizeof(*game), 1);
	if (!game)
		return (ft_putstr_fd(ERR, 2), free_infos(infos, NULL), NULL);
	game->infos = infos;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (free_data(game, ERR_MLX), NULL);
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	infos->x_max * IMG_SIZE, infos->y_max * IMG_SIZE, "so_long");
	if (!game->win_ptr)
		return (free(game->win_ptr), free_data(game, ERR_MLX), NULL);
	return (game);
}
