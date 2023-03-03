/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:05:52 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/03 18:32:21 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_infos	*init_infos(void)
{
	t_infos	*infos;

	infos = malloc(sizeof(*infos));
	if (!infos)
		put_error("error", NULL, 1, infos);
	else
	{
		infos->map = NULL;
		infos->x_max = 0;
		infos->y_max = 0;
		infos->perso = NULL;
		infos->collect = NULL;
		infos->exit = NULL;
	}
	return (infos);
}
