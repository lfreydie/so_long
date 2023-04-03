/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:23:15 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/03 14:32:48 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_img(t_data *game)
{
	game->img_0 = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./img/BG.xpm", &game->img_s, &game->img_s);
	if (!game->img_0)
		ft_exit(game, ERR_IMG, 1);
	game->img_1 = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./img/WALL.xpm", &game->img_s, &game->img_s);
	if (!game->img_1)
		ft_exit(game, ERR_IMG, 1);
	game->img_p = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./img/VIKING.xpm", &game->img_s, &game->img_s);
	if (!game->img_p)
		ft_exit(game, ERR_IMG, 1);
	game->img_z = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./img/ZOMBIE_EAT/Z00.xpm", &game->img_s, &game->img_s);
	if (!game->img_z)
		ft_exit(game, ERR_IMG, 1);
	game->img_c = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./img/MAP.xpm", &game->img_s, &game->img_s);
	if (!game->img_c)
		ft_exit(game, ERR_IMG, 1);
	game->img_e = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./img/CHEST_CLOSED.xpm", &game->img_s, &game->img_s);
	if (!game->img_e)
		ft_exit(game, ERR_IMG, 1);
}

void	ft_put_img_to_win(t_data *game, int x, int y)
{
	if (game->infos->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img_0, x * game->img_s, y * game->img_s);
	else if (game->infos->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img_1, x * game->img_s, y * game->img_s);
	else if (game->infos->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img_p, x * game->img_s, y * game->img_s);
	else if (game->infos->map[y][x] == 'M')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img_z, x * game->img_s, y * game->img_s);
	else if (game->infos->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img_c, x * game->img_s, y * game->img_s);
	else if (game->infos->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img_e, x * game->img_s, y * game->img_s);
}

void	ft_place_img(t_data *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->infos->y_max)
	{
		x = -1;
		while (++x < game->infos->x_max)
		{
			ft_put_img_to_win(game, x, y);
			if (y == 0 && x == 0)
				ft_put_count_to_win(game);
		}
	}
}

void	ft_open_exit(t_data *game)
{
	if (game->img_e)
		mlx_destroy_image(game->mlx_ptr, game->img_e);
	game->img_e = mlx_xpm_file_to_image(game->mlx_ptr, \
	"./img/CHEST_OPEN.xpm", &game->img_s, &game->img_s);
	if (!game->img_e)
		ft_exit(game, ERR_IMG, 1);
}

void	ft_put_count_to_win(t_data *game)
{
	char	*count;

	count = ft_itoa(game->infos->count_step);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 5, 22, 0x3a3232, "count :");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 50, 22, 0x3a3232, count);
	free(count);
}
