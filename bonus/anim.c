/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:10:35 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/04 12:48:12 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_die(t_data *game, int new_x, int new_y)
{
	char	*zombie_path;

	while (++game->sprite_z <= 24)
	{
		zombie_path = ft_die_path(game);
		if (!zombie_path)
			ft_exit(game, NULL, 1);
		mlx_destroy_image(game->mlx_ptr, game->img_z);
		game->img_z = mlx_xpm_file_to_image(game->mlx_ptr, zombie_path, \
		&game->img_s, &game->img_s);
		if (!game->img_z)
		{
			free(zombie_path);
			ft_exit(game, ERR_IMG, 1);
		}
		usleep(20000);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img_z, new_x * game->img_s, new_y * game->img_s);
		free(zombie_path);
	}
}

char	*ft_die_path(t_data *game)
{
	char	*nbr;
	char	*tmp;
	char	*zombie_path;

	nbr = malloc(sizeof(char) * 3);
	if (!nbr)
		return (NULL);
	nbr[0] = ('0' + (game->sprite_z / 10));
	nbr[1] = ('0' + (game->sprite_z % 10));
	nbr[2] = '\0';
	tmp = ft_strjoin("./img/ZOMBIE_EAT/Z", nbr);
	if (!tmp)
		return (free(nbr), NULL);
	zombie_path = ft_strjoin(tmp, ".xpm");
	free(nbr);
	free(tmp);
	return (zombie_path);
}
