#ifndef FDF_H
# define FDF_H

# define INVALID_Z	2000000

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		x_max;
	int		y_max;
	int		r;
	int		g;
	int		b;
	int		zoom;
	int		z_ch;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		**map;
}				t_env;

int				get_next_line(int const fd, char **line);

#endif
