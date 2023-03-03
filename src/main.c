/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:05:02 by lfreydie          #+#    #+#             */
/*   Updated: 2023/03/03 18:32:03 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av, char **envp)
{
	if (!envp || !envp[0])
		put_error(ERR_ENV, NULL, ERROR, NULL);
	if (ac != 2)
		put_error(ERR_ARG, NULL, ERROR, NULL);
	check_map(av[1]);
}
