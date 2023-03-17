/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:56:47 by nihamdan          #+#    #+#             */
/*   Updated: 2023/03/17 23:44:33 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*get_cmd(char **av_cmd, char **av)
{
	t_cmd	*cmd;
	int		i;

	cmd = malloc(sizeof(t_cmd) * 2);
	i = -1;
	while (++i != 2)
	{
		cmd[i].cmd = ft_strndup(av_cmd[i], ' ');
		cmd[i].opt = ft_split2(av_cmd[i], " ");
		cmd[i].file = av[0];
		if (i == 1)
			cmd[i].file = av[3];
		free(av_cmd[i]);
	}
	free(av_cmd);
	return (cmd);
}

int	without_space(char *av)
{
	int	i;

	i = 0;
	if (av[0] != ' ')
		return (0);
	while (av[i] == ' ' && av[i])
		i++;
	return (i);
}
