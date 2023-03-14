/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:57:19 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/14 15:44:17 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);

	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	(void)data;
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

void	ft_game(t_infos *infos)
{
	t_data	*data;

	data = ft_calloc(sizeof(*data), 1);
	if (!data)
		put_error(ERR_MLX, NULL, 1, infos);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free(data);
		put_error(ERR_MLX, NULL, 1, infos);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
	infos->x_max * IMG_W, infos->y_max * IMG_H, "so_long");
	if (!data->win_ptr)
	{
		free(data);
		free(data->mlx_ptr);
		put_error(ERR_MLX, NULL, 1, infos);
	}
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, &data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, \
	&handle_keyrelease, &data);

	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
