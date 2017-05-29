/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:35:38 by awyart            #+#    #+#             */
/*   Updated: 2017/05/29 14:35:40 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_fillmap(t_env *env, char **split, int *i, int j)
{
	int		k;

	k = 0;
	while (split[k] && *i != env->x_max)
	{
		env->map[j][*i] = ft_atoi(split[k]);
		(*i)++;
		k++;
	}
	while (*i != env->x_max)
	{
		env->map[j][*i] = NOZ;
		(*i)++;
	}
}

void	ft_fill(char *av, t_env *env)
{
	char	*line;
	char	**split;
	int		j;
	int		i;
	int		fd;

	i = 0;
	j = 0;
	if (!av)
		return ;
	fd = open(av, O_RDONLY);
	env->map = (int**)malloc(sizeof(int*) * env->y_max);
	while (get_next_line(fd, &line) == 1 && j != env->y_max)
	{
		env->map[j] = (int*)malloc(sizeof(int) * env->x_max);
		split = ft_strsplit(line, ' ');
		if (split)
			ft_fillmap(env, split, &i, j);
		i = 0;
		if (split)
			free(split);
		j++;
	}
	close(fd);
}
