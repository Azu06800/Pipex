/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:56:38 by nihamdan          #+#    #+#             */
/*   Updated: 2023/03/17 23:33:56 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>

typedef struct s_cmd {
	char	*cmd;
	char	**opt;
	char	*file;
}	t_cmd;

typedef struct s_pipex {
	t_cmd	*cmd;

	int		status;
	int		pipefd[2];
	int		fd1;
	int		fd2;
	pid_t	pid1;
	pid_t	pid2;

	char	**envp;
}	t_pipex;

int		eprint_ac(void);
int		eprint_cmd(char *str);
int		ft_printerr(char *fn);
int		eprint_perror(char *str);

size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *str, int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strndup(const char *s1, char c);

int		without_space(char *av);
char	**check_iscmd(char **av, char	**envp);
char	**check_arg(int ac, char **av, char	**envp);

char	**ft_split(char *str, char *charset);
char	**ft_split2(char *str, char *charset);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		child1_process(t_pipex *pipex);
int		child2_process(t_pipex *pipex);

t_cmd	*get_cmd(char **av_cmd, char **av);

#endif
