/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:35:04 by awyart            #+#    #+#             */
/*   Updated: 2017/05/29 14:35:05 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init_mlx(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		return (1);
	env->win = mlx_new_window(env->mlx, SIZEX, SIZEY, "FDF");
	env->r = 100;
	env->g = 100;
	env->b = 100;
	env->zoom = 50;
	return (0);
}

int		ft_getline(char *line)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			j++;
			while (ft_isdigit(line[i]))
				i++;
		}
		i++;
	}
	return (j);
}

void	ft_getsize(char *av, t_env *env)
{
	char	*line;
	int		c_max;
	int		lin;
	int		c;
	int		fd;

	lin = 0;
	c = 0;
	c_max = 0;
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		c = ft_getline(line);
		if (c > c_max)
			c_max = c;
		lin++;
		if (line)
			free(line);
	}
	close(fd);
	env->x_max = c_max;
	env->y_max = lin - 1;
}
