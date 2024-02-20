/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structure.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:53:48 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/20 13:48:00 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H
# include <stddef.h>

typedef struct	s_opps
{
	int				x1;
	int				x2;
	int				dir;
	int				sens;
	int				state;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_opps;

/*typedef struct	s_opps
{
	int	**pos;
	int	number;
	int state;
}				t_opps;*/

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
	int			*player_right;
	int			*player_left;
	int			*opps_low;
	int			*opps_top;
	int			*opps_mid;
	int 		*empty;
	int 		*wall;
	int 		*collect;
	int			*door;
	int			*proj;
	int			*player_shoot1_left;
	int			*player_shoot2_left;
	int			*player_shoot3_left;
	int			*player_shoot4_left;
	int			*player_shoot5_left;
	int			*player_shoot1_right;
	int			*player_shoot2_right;
	int			*player_shoot3_right;
	int			*player_shoot4_right;
	int			*player_shoot5_right;
	int			*explosion_1;
	int			*explosion_2;
	int			*explosion_3;
	int			*explosion_4;
}				t_colors;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_offs
{
	int	up;
	int	down;
	int	left;
	int	right;
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
	char		**map;
	int			p_x1;
	int			p_x2;
	int			collect;
	char		event;
	int			step;
	int			vec;
	int			player_state;
	int			mv_x;
	int			mv_y;
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

#endif