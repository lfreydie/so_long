/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:56:28 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/02 17:34:14 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_listen_event(int keysym, t_data *game)
{
	if (keysym == XK_Escape)
		ft_exit(game, NULL, 0);
	else if (keysym == XK_w)
	{
		ft_move(game, 0, -1);
		ft_place_img(game);
	}
	else if (keysym == XK_a)
	{
		ft_move(game, -1, 0);
		ft_place_img(game);
	}
	else if (keysym == XK_s)
	{
		ft_move(game, 0, 1);
		ft_place_img(game);
	}
	else if (keysym == XK_d)
	{
		ft_move(game, 1, 0);
		ft_place_img(game);
	}
	return (0);
}
