/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:43:45 by awyart            #+#    #+#             */
/*   Updated: 2017/06/02 12:02:50 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 1000
# define NOZ 2000000
# define SIZEX 1280
# define SIZEY 720
# define NBEVE 25
# define ZZ env->map[y][x]
# define ZZZ env->map[y][x + 1]
# define ZZZZ env->map[y + 1][x]
# include "mlx.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>

typedef struct		s_gnl
{
	char			*tmp;
	char			*s;
	int				fd;
	struct s_gnl	*head;
	struct s_gnl	*next;
	struct s_gnl	*last;
}					t_gnl;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pix;
	int				x_max;
	int				y_max;
	int				zmax;
	int				r;
	int				g;
	int				b;
	double			zoomx;
	double			zoomy;
	double			zoomz;
	double			cx;
	double			cy;
	double			cz;
	double			mvx;
	double			mvy;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				**map;
}					t_env;

typedef struct		s_ev
{
	int				key;
	void			(*f)(t_env *env);
}					t_ev;

void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					get_next_line(const int fd, char **line);
void				*ft_memalloc(size_t size);
char				**ft_strsplit(char const *s, char c);
int					ft_isdigit(int c);
int					ft_atoi(const char *str);

void				ft_fill(char *av, t_env *env);
int					ft_draw(t_env *env);
void				ft_draw_lines(t_env *env);

int					ft_init_mlx(t_env *env);
void				ft_getsize(char *av, t_env *env);
void				ft_create_img(t_env *env);
int					ft_display_img(t_env *env);

void				ft_apply_proj_isoh(t_env *env, int x, int y);
void				ft_apply_proj_isov(t_env *env, int x, int y);
void				ft_get_color(t_env *env, int z);

void				ft_ev69(t_env *env);
void				ft_ev78(t_env *env);
void				ft_ev87(t_env *env);
void				ft_ev88(t_env *env);
void				ft_ev123(t_env *env);
void				ft_ev124(t_env *env);
void				ft_ev125(t_env *env);
void				ft_ev126(t_env *env);
void				ft_ev43(t_env *env);
void				ft_ev47(t_env *env);
void				ft_ev6(t_env *env);
void				ft_evx(t_env *env);
void				ft_ev15(t_env *env);
void				ft_ev5(t_env *env);
void				ft_ev11(t_env *env);
void				ft_exit(t_env *env);
void				ft_evi(t_env *env);
void				ft_evu(t_env *env);
void				ft_evo(t_env *env);
void				ft_colorset1(t_env *env);
void				ft_colorset2(t_env *env);
void				ft_evmv(t_env *env);
void				ft_evmv1(t_env *env);
void				ft_evmv2(t_env *env);
void				ft_evmv3(t_env *env);

void				ft_define_sea(int b[2], int r[2], int g[2]);
void				ft_define_earth(int b[2], int r[2], int g[2]);
void				ft_define_beach(int b[2], int r[2], int g[2]);
void				ft_define_forrest(int b[2], int r[2], int g[2]);
void				ft_define_moutain(int b[2], int r[2], int g[2]);

#endif
