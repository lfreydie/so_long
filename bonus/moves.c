/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:12:03 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/04 12:48:41 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_move(t_data *game, int diff_x, int diff_y)
{
	int	new_y;
	int	new_x;

	new_x = game->infos->x_p + diff_x;
	new_y = game->infos->y_p + diff_y;
	if (game->infos->map[new_y][new_x] != '1')
	{
		if (game->infos->map[new_y][new_x] == 'E' && !game->infos->collect)
		{
			ft_remove_p(game);
			ft_exit(game, "YOU WON !\n", 0);
		}
		else if (game->infos->map[new_y][new_x] == 'C')
			ft_move_p(game, new_x, new_y);
		else if (game->infos->map[new_y][new_x] == '0')
			ft_move_p(game, new_x, new_y);
		else if (game->infos->map[new_y][new_x] == 'M')
		{
			ft_die(game, new_x, new_y);
			ft_remove_p(game);
			ft_place_img(game);
			usleep(20000);
			ft_exit(game, "YOU LOST !\n", 0);
		}
	}
}

void	ft_move_p(t_data *game, int new_x, int new_y)
{
	game->infos->map[game->infos->y_p][game->infos->x_p] = '0';
	if (game->infos->map[new_y][new_x] == 'C')
	{
		game->infos->collect--;
		if (!game->infos->collect)
			ft_open_exit(game);
	}
	game->infos->map[new_y][new_x] = 'P';
	take_coordinate_perso(game->infos, new_x, new_y);
	game->infos->count_step++;
	ft_put_count_to_win(game);
}

void	ft_remove_p(t_data *game)
{
	game->infos->map[game->infos->y_p][game->infos->x_p] = '0';
	game->infos->count_step++;
	ft_put_count_to_win(game);
}
