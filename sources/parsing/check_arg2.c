/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:37:06 by nihamdan          #+#    #+#             */
/*   Updated: 2023/03/17 22:11:42 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*only_cmd(char *av)
{
	char	*cmd;
	int		i;

	i = 0;
	while (av[i] && av[i] != ' ')
		i++;
	cmd = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (av[i] && av[i] != ' ')
	{
		cmd[i] = av[i];
		i++;
	}
	cmd[i] = '\0';
	return (cmd);
}

char	**get_path(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			break ;
		i++;
	}
	path = ft_split(envp[i] + 5, ":");
	return (path);
}

char	*boucle_iscmd(char *av, char **path)
{
	int		j;
	char	*tmp;
	char	*cmd;
	int		i;

	j = -1;
	i = without_space(av);
	cmd = only_cmd(av + i);
	while (path[++j])
	{
		tmp = ft_strjoin(path[j], cmd);
		if (!access(tmp, X_OK))
		{
			free(cmd);
			free(tmp);
			return (ft_strjoin(path[j], av + i));
		}
		free(tmp);
	}
	free(cmd);
	return (NULL);
}

void	freepath(char **path)
{
	int	i;

	i = -1;
	while (path[++i])
		free(path[i]);
	free(path);
}

char	**check_iscmd(char **av, char	**envp)
{
	int		i;
	char	**cmd;
	char	**path;

	i = -1;
	cmd = malloc(sizeof(char *) * 2);
	path = get_path(envp);
	while (av[++i + 1])
	{
		cmd[i] = boucle_iscmd(av[i], path);
		if (cmd[i] == NULL)
		{
			if (i == 1)
				free(cmd);
			eprint_cmd(av[i]);
			return (NULL);
		}
	}
	freepath(path);
	return (cmd);
}
