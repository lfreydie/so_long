/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:57:19 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/08 19:11:55 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_game(t_infos *infos)
{
	t_game	*data;

	data = ft_calloc(sizeof(*data), 1);
	if (!data)
		put_error(ERR_MLX, NULL, 1, infos);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		put_error(ERR_MLX, NULL, infos);
	data->wind_ptr = mlx_new_window(data->mlx_ptr, win_width, win_height, "so_long");
}

