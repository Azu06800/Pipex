/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:43:00 by nihamdan          #+#    #+#             */
/*   Updated: 2023/03/17 23:45:09 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freeall(t_pipex *pipex)
{
	int	i;

	i = -1;
	free(pipex->cmd[0].cmd);
	if (!pipex->cmd[0].opt[0])
	{
		while (pipex->cmd[0].opt[++i])
			free(pipex->cmd[0].opt[i]);
	}
	free(pipex->cmd[0].opt);
	i = -1;
	free(pipex->cmd[1].cmd);
	if (!pipex->cmd[1].opt[0])
	{
		while (pipex->cmd[1].opt[++i])
			free(pipex->cmd[1].opt[i]);
	}
	free(pipex->cmd[1].opt);
	close(pipex->fd1);
	close(pipex->fd2);
}

int	ft_pipex(t_pipex *pipex)
{
	pipex->fd1 = open(pipex->cmd[0].file, O_RDONLY);
	pipex->fd2 = open(pipex->cmd[1].file, O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->fd1 < 0 || pipex->fd2 < 0)
		return (eprint_perror("open failed :"));//refaire
	pipe(pipex->pipefd);
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		return (eprint_perror("Fork : "));
	if (!pipex->pid1)
		return (child1_process(pipex));
	else
	{
		pipex->pid2 = fork();
		if (pipex->pid2 < 0)
			return (eprint_perror("Fork : "));
		if (!pipex->pid2)
			return (child2_process(pipex));
	}
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	waitpid(-1, &pipex->status, 0);
	waitpid(-1, &pipex->status, 0);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	char		**av_cmd;
	t_pipex		pipex[1];

	av_cmd = check_arg(ac, av + 1, envp);
	if (av_cmd == NULL)
		return (1);
	pipex->cmd = get_cmd(av_cmd, av + 1);
	pipex->envp = envp;
	//ft_pipex(pipex);
	freeall(pipex);
	while (1)
		;
}
