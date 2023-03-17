/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:37:19 by nihamdan          #+#    #+#             */
/*   Updated: 2023/03/17 22:56:52 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_isfile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
		return (ft_printerr(infile));
	close(fd);
	return (0);
}

char	**check_arg(int ac, char **av, char	**envp)
{
	char	**cmd;

	if (ac != 5)
	{
		eprint_ac();
		return (NULL);
	}
	if (check_isfile(av[0]))
		return (NULL);
	cmd = check_iscmd(av + 1, envp);
	if (cmd == NULL)
		return (NULL);
	return (cmd);
}
