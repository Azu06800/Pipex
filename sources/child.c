/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:50:31 by nihamdan          #+#    #+#             */
/*   Updated: 2023/03/17 23:25:49 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child1_process(t_pipex *pipex)
{
	close(pipex->pipefd[0]);
	dup2(pipex->fd1, 0);
	dup2(pipex->pipefd[1], 1);
	execve(pipex->cmd[0].cmd, pipex->cmd[0].opt, pipex->envp);
	close(pipex->pipefd[1]);
	return (0);
}

int	child2_process(t_pipex *pipex)
{
	close(pipex->pipefd[1]);
	dup2(pipex->pipefd[0], 0);
	dup2(pipex->fd2, 1);
	printf("test2");
	execve(pipex->cmd[1].cmd, pipex->cmd[1].opt, pipex->envp);
	close(pipex->pipefd[0]);
	return (0);
}
