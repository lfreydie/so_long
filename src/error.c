/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:15:56 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/08 19:13:35 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_error(char *error, char *explc, int code, t_infos *infos)
{
	free_all(infos);
	write(2, error, ft_strlen(error));
	if (explc)
	{
		write(2, " : ", 3);
		write(2, explc, ft_strlen(explc));
	}
	write(2, "\n", 1);
	if (code)
		exit (code);
	exit (ERROR);
}
