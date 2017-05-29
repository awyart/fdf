void	ft_put_px(t_env *env, int y, int x)
{
	if ((x > 0 && y > 0) && (x <= 1280 && y <= 720))
	{
		env->data[(x * 4) + (y * 1280 * 4)] = env->r;
		env->data[(x * 4) + (y * 1280 * 4) + 1] = env->g;
		env->data[(x * 4) + (y * 1280 * 4) + 2] = env->b;
	}
}

void	ft_draw_lines(t_env *env)
{
	double dx;
	double dy;
	double x;
	double y;
	double temp;

	x = env->x1;
	y = env->y1;
	dx = env->x2 - env->x1;
	dy = env->y2 - env->y1;
	temp = sqrt((dx * dx) + (dy * dy));
	dx /= temp;
	dy /= temp;
	while (temp >= 0)
	{
		ft_put_px(env, y, x);
		x += dx;
		y += dy;
		temp--;
	}
}

void	ft_display_img(t_env *env)
{
	int		sizeline;
	int		endian;
	int		bpp;
	
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}

void	ft_create_img(t_env *env)
{
	int		sizeline;
	int		endian;
	int		bpp;

	env->img = mlx_new_image(e->mlx, 1280, 720);
	env->data = mlx_get_data_addr(e->img, &bpp, &sizeline, &endian);
}

void	ft_translate(t_env *env, int x, int y, int n)
{
	int		xt;
	int		yt;

	xt = x - env->x_max / 2;
	yt = y - env->y_max / 2;
	env->x1 = 0.40 * (xt - yt) * env->zoom;
	env->y1 = 0.20 * (xt + yt) * env->zoom;
	env->y1 -= env->map[y][x] * env->z_ch;
	if (n)
	{
		env->x2 = 0.40 * ((xt + 1) - yt) * env->zoom;
		env->y2 = 0.20 * ((xt + 1) + yt) * env->zoom;
		env->y2 -= env->map[y][x + 1] * env->z_ch;
	}
	else
	{
		env->x2 = 0.40 * (xt - (yt + 1)) * env->zoom;
		env->y2 = 0.20 * (xt + (yt + 1)) * env->zoom;
		env->y2 -= env->map[y + 1][x] * env->z_ch;
	}
	env->x1 += 1280 / 2;
	env->x2 += 1280 / 2;
	env->y1 += 720 / 2;
	env->y2 += 720 / 2;
}
s
void	ft_draw(t_env *env)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_create_img(env);
	while (y != env->y_max)
	{
		while (x != env->x_max)
		{
			env->x1 = x;
			env->y1 = y;
			if (x + 1 < env->x_max && env->map[y][x] !=\
				INVALID_Z && env->map[y][x + 1] != INVALID_Z)
				ft_translate(env, x, y, 1), ft_draw_lines(env);
			if (y + 1 < env->y_max && env->map[y][x] != \
				INVALID_Z && env->map[y + 1][x] != INVALID_Z)
				ft_translate(env, x, y, 0), ft_draw_lines(env);
			x++;
		}
		x = 0;
		y++;
	}
	ft_display_img(env);
}