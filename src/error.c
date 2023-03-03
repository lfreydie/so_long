/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:15:56 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/03 18:35:02 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_error(char *error, char *file, int code, t_infos *infos)
{
	free_all(infos);
	write(2, error, ft_strlen(error));
	if (file)
	{
		write(2, " : ", 3);
		write(2, file, ft_strlen(file));
	}
	write(2, "\n", 1);
	if (code)
		exit (code);
	exit (ERROR);
}
