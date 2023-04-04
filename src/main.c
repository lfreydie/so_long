/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:05:02 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/04 14:38:36 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_infos	*infos;

	if (ac != 2)
		return (ft_error(ERR_ARG), ERROR);
	infos = check_map(av[1]);
	if (!infos)
		return (ERROR);
	ft_game(infos);
}
