/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:56:58 by nihamdan          #+#    #+#             */
/*   Updated: 2023/03/17 19:57:00 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	sepcmp(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!sepcmp(str[i], charset))
		{
			j++;
			while (!sepcmp(str[i], charset) && str[i])
				i++;
			continue ;
		}
		i++;
	}
	return (j);
}

char	*setline(char *str, int *i, char *charset)
{
	char	*r;
	int		j;

	j = *i;
	while (!sepcmp(str[j], charset) && str[j])
		j++;
	r = malloc(sizeof(char) * (j - *i + 1));
	j = 0;
	while (!sepcmp(str[*i], charset) && str[*i])
		r[j++] = str[(*i)++];
	r[j] = '\0';
	return (r);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**r;

	i = 0;
	j = 0;
	r = malloc(sizeof(char *) * count_word(str, charset) + 1);
	if (!r)
		return (0);
	while (str[i])
	{
		if (!sepcmp(str[i], charset))
		{
			r[j++] = setline(str, &i, charset);
			continue ;
		}
		i++;
	}
	r[j] = 0;
	return (r);
}

char	**ft_split2(char *str, char *charset)
{
	int		i;
	int		j;
	char	**r;

	i = 0;
	j = 0;
	r = malloc(sizeof(char *) * count_word(str, charset));
	if (!r)
		return (0);
	while (str[i] && sepcmp(str[i], charset))
		i++;
	while (str[i])
	{
		if (!sepcmp(str[i], charset))
		{
			r[j++] = setline(str, &i, charset);
			continue ;
		}
		i++;
	}
	r[j] = 0;
	return (r);
}
