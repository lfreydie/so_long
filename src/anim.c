/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:10:35 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/02 18:36:54 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_die(t_data *game, int new_x, int new_y)
{
	char	*zombie_path;

	while (game->sprite_z++ <= 25)
	{
		zombie_path = malloc(sizeof(char) * 14);
		if (!zombie_path)
			ft_exit(game, NULL, 1);
		zombie_path = ft_die_path(game, zombie_path);
		mlx_destroy_image(game->mlx_ptr, game->img_z);
		game->img_z = mlx_xpm_file_to_image(game->mlx_ptr, zombie_path, \
		&game->img_s, &game->img_s);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_z, \
		(new_x * game->img_s), (new_y * game->img_s));
		free(zombie_path);
	}
}

char	*ft_die_path(t_data *game, char *zombie_path)
{
	int	j;

	j = 0;
	zombie_path[j++] = '.';
	zombie_path[j++] = '/';
	zombie_path[j++] = 'i';
	zombie_path[j++] = 'm';
	zombie_path[j++] = 'g';
	zombie_path[j++] = '/';
	zombie_path[j++] = 'Z';
	zombie_path[j++] = (char)('0' + (game->sprite_z / 10));
	zombie_path[j++] = (char)('0' + (game->sprite_z % 10));
	zombie_path[j++] = '.';
	zombie_path[j++] = 'x';
	zombie_path[j++] = 'p';
	zombie_path[j++] = 'm';
	zombie_path[j] = '\0';
	return (zombie_path);
}
