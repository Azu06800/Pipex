/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:41:46 by nihamdan          #+#    #+#             */
/*   Updated: 2023/03/17 21:57:01 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_printerr(char *fn)
{
	ft_putstr_fd(fn, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	eprint_cmd(char *str)
{
	ft_putstr_fd("zsh: command not found: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	eprint_ac(void)
{
	return (write(2, "need 4 args: ./pipex infile cmd cmd outfile\n", 44));
}

int	eprint_perror(char *str)
{
	perror(str);
	return (0);
}
