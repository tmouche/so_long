/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:53:48 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/22 16:30:39 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H
# define SPR_S 60
# define BUFFER_SIZE 1000000
# define SSIZE_X 1920
# define SSIZE_Y 1010
# define POWER 150
# include <stddef.h>

typedef struct	s_opps
{
	int				x1;
	int				x2;
	int				dir;
	int				sens;
	int				state;
	struct s_opps	*prev;
	struct s_opps	*next;
}				t_opps;

typedef	struct	s_block
{
	char	nature;
	int		life_state;
	t_opps	*bad;
}				t_block;

typedef struct	s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef	struct	s_colors
{
	int			*p_r;
	int			*p_l;
	int			*opps_bot;
	int			*opps_top;
	int			*opps_mid;
	int 		*empty;
	int 		*wall;
	int 		*collect;
	int			*door;
	int			*proj;
	int			*p_shoot2_l;
	int			*p_shoot1_l;
	int			*p_shoot3_l;
	int			*p_shoot4_l;
	int			*p_shoot5_l;
	int			*p_shoot1_r;
	int			*p_shoot2_r;
	int			*p_shoot3_r;
	int			*p_shoot4_r;
	int			*p_shoot5_r;
	int			*explosion_1;
	int			*explosion_2;
	int			*explosion_3;
	int			*explosion_4;
	int			*explosion_5;
	int			*explosion_6;
}				t_colors;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_offs
{
	int	u;
	int	d;
	int	l;
	int	r;
}				t_offs;

typedef struct	s_proj
{
	int	o_x1;
	int o_x2;
	int x1;
	int	x2;
	int	limit;
	int i;
	int	shoot;
}				t_proj;

typedef struct	s_map
{
	int			map_width;
	int			map_height;
	char		**c_map;
	int			p_x1;
	int			p_x2;
	int			collect;
	char		event;
	int			step;
	int			vec;
	int			player_state;
	int			mv_x;
	int			mv_y;
	t_block		***s_map;
	t_opps		**bad;
	t_colors	*colors;
	t_proj		*proj;
}				t_map;

typedef	struct	s_path
{
	char	*empty;
	char	*door;
	char	*collec;
	char	*player;
	char	*wall;
	char	*opps;
	char	*proj;
}				t_path;

typedef struct	s_perf
{
	unsigned int	fps;
}				t_perf;

typedef struct	s_struct
{
	t_map			*info;
	t_vars			*vars;
	t_data			*img;
	t_perf			*perf;
}				t_struct;

int		_lstsize(t_opps *lst);
t_opps	*_lstlast(t_opps *lst);
void	_lstclear(t_opps **lst);
t_opps	*_lstnew(int x1, int x2);
int		_lstadd_back(t_opps **lst, t_opps *new);
void	_lstadd_front(t_opps **lst, t_opps *new);

void	_free_all(t_struct *glob, int stop);
void	_freemap(char **map);

void	_init_t_colors(t_colors *colors);

#endif