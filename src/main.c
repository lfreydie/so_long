/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:05:02 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/08 19:29:22 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av, char **envp)
{
	t_infos	*infos;

	if (!envp || !envp[0])
		put_error(ERR_ENV, NULL, ERROR, NULL);
	if (ac != 2)
		put_error(ERR_ARG, NULL, ERROR, NULL);
	infos = check_map(av[1]);
	show_infos(infos);
	free_all(infos);
}
