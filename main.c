#include "fdf.h"
#include "stdlib.h"

int		loop_event(t_env *env)
{
	ft_draw(env);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac == 1)
		return (0);
	env = (t_env *)malloc(sizeof(t_env));
	if (ft_init_mlx(env) == 1)
		return (0);
	ft_count_size(av[1], env);
	ft_fill(av[1], env);
	mlx_hook(env->window, 2, 3, keyrelease, env);
	mlx_loop_hook(env->mlx, &loop_event, env);
	mlx_loop(env->mlx);
	return (0);
}