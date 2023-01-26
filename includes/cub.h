/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:38:22 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/10/31 00:56:55 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "libft.h"
# include "keys.h"

# ifdef OS_NAME
#  if OS_NAME == Darwin
#   define OS 1
#  else
#   define OS 0
#  endif
# endif

# define POSIBLE_CHARS	" 0123NSEW"
# define INSIDE_CHARS	"023NSEW"
# define DIRECTIONS		"NSEW"
# define WALL_OR_DOOR	"12"
# define SPRITES		"3"

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

# define FOV				1.2
# define SIZE				1000
# define STEP				200
# define WIDTH_WINDOW		1533 //2040
# define HEIGHT_WINDOW		790 //1000
# define TURN_AROUND_STEP	60
# define DIST_FROM_WALL		500
# define WALL_HEIGHT_RATIO	1
# define MOUSE_RATIO		1.0
# define MOUSE_SIDE_RATIO	1.5
# define MINIMAP_RATIO		5
# define MINIMAP_STEP		83
# define DOOR_OPEN_DIST		1100
# define SPRT_ANIM_SPEED	4
# define SPRT_NIKOL			0
# define DOOR_PIC			"./xpm/door2.xpm"
# define SPRT_PIC1			"./xpm/sprite/s1.xpm"
# define SPRT_PIC2			"./xpm/sprite/s2.xpm"
# define SPRT_PIC3			"./xpm/sprite/s3.xpm"
# define SPRT_PIC4			"./xpm/sprite/s4.xpm"
# define SPRT_PIC5			"./xpm/sprite/s5.xpm"
# define SPRT_PIC6			"./xpm/sprite/s6.xpm"
# define SPRT_PIC7			"./xpm/sprite/s7.xpm"
# define SPRT_PIC8			"./xpm/sprite/s8.xpm"
# define SPRT_PIC9			"./xpm/sprite/s9.xpm"
# define SPRT_PIC10			"./xpm/sprite/s10.xpm"
# define SPRT_PIC11			"./xpm/sprite/s11.xpm"
# define SPRT_PIC12			"./xpm/sprite/s12.xpm"
# define SPRT_PIC_NIKOL		"./xpm/nik.xpm"

typedef struct s_sprt
{
	struct s_sprt	*prev;
	struct s_sprt	*next;
	double			rds;
	double			pbx;
	double			pby;
	double			ccx;
	double			ccy;
	double			ccx0;
	double			ccy0;
	double			cx;
	double			cy;
	double			rr;
	double			cr;
	double			crt;
	int				iytr;
	int				jytr;
	double			iyt;
	double			jyt;
	double			sdp;
	char			rpfcr;
	double			pdfc;
	double			pdfcc;
	double			ccdfc;
	double			angl_spo;
	double			angl_hpo;
	double			angl_sph;
	double			l_ho;
	double			l_hs;
	double			l_ps;
	double			l_so;
	double			area_sph;
	double			area_oph;
	double			area_spo;
	char			s_pos;
	double			l_se;
	double			angl_po_vec;
	char			po_vec_pos;
	double			xpm_x_ratio;
}	t_sprt;

struct s_sprt_tmp
{
	double	x;
	double	y;
	int		i;
	int		j;
	double	step;
}	sprt_tmp;

typedef struct s_xpm
{
	void		*ptr;
	int			width;
	int			height;
	char		*addr;
	int			bpp;
	int			linelen;
	int			endian;
}	t_xpm;

typedef struct s_cub
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	char		**init_map;
	char		**map;
	void		*xpm_no;
	void		*xpm_so;
	void		*xpm_we;
	void		*xpm_ea;
	int			floor_clr;
	int			ceiling_clr;
	int			wxpm[4];
	int			hxpm[4];
	t_xpm		*xpm;
	int			bpp;
	int			line_length;
	int			endian;
	int			w_win;
	int			h_win;
	int			w_map;
	int			h_map;
	double		dir_vec_x;
	double		dir_vec_y;
	double		s_dist_x;
	double		s_dist_y;
	double		d_dist_x;
	double		d_dist_y;
	int			pl_map_x;
	int			pl_map_y;
	double		pl_board_x;
	double		pl_board_y;
	char		compass_x;
	char		compass_y;
	char		pic;
	int			w_or_d;
	int			door_is_open;
	double		fov;
	double		cntr_rad;
	double		cross_coor_x;
	double		cross_coor_y;
	double		ray_length;
	double		ray_projection;
	t_sprt		*sprt;
	t_sprt		*sprt_tmp;
	int			s_num;
	int			s_speed;
}			t_cub;

struct	s_vertical
{
	double		x;
	double		y;
	double		ray_length;
}	vertical;

struct	s_horizon
{
	double		x;
	double		y;
	double		ray_length;
}	horizon;

struct	s_way_length
{
	double		forward;
	double		back;
	double		left;
	double		right;
	double		f_radian;
	double		b_radian;
	double		l_radian;
	double		r_radian;
	double		forward_for_door;
}	way_length;

struct	s_mouse
{
	int			old_x;
	int			mouse_enable;
}	mouse;

struct	s_minimap
{
	double		start_x;
	double		start_y;
	int			i;
	int			j;
	int			pl_x;
	int			pl_y;
	int			pl_delta_x;
	int			pl_delta_y;
}	minimap;

// int	g_mouse_enable;

//===========================================================================
// cub3D
//===========================================================================

void		ft_win_msg(t_cub *c);
int			ft_cub3d(t_cub *c);
char		*ft_add_char_to_buf(char *buf, char c);
char		*get_next_line(int fd);
void		ft_initiator(t_cub *c, char **argv);
void		ft_error(char *message, int exit_code);
char		*ft_strfree(char *str);
char		*ft_strfree2(char *str1, char *str2);
char		**ft_arrfree(char **arr);
double		ft_max(double x, double y);
char		**ft_copy_map(char **map);
void		ft_reset_map(t_cub *c);

//===========================================================================
// distance
//===========================================================================

double		ft_cntr_rad(t_cub *c);
int			ft_coord_quart(double radian);
void		ft_side_dist_xy(t_cub *c, double step);
void		ft_delta_dist_xy(t_cub *c, double step);
void		ft_crossing_direction_with_map(t_cub *c, double step);
double		ft_correct_radian(double radian);
double		ft_ray_sharp_radian(double radian);
double		ft_s_horizon_x(t_cub *c, double step);
double		ft_s_horizon_y(t_cub *c, double step);
double		ft_s_vertical_x(t_cub *c, double step);
double		ft_s_vertical_y(t_cub *c, double step);
double		ft_d_horizon_x(t_cub *c, double step);
double		ft_d_horizon_y(t_cub *c, double step);
double		ft_d_vertical_x(t_cub *c, double step);
double		ft_d_vertical_y(t_cub *c, double step);
void		ft_ray_length(t_cub *c, double step, int flag);
void		ft_ray_projection(t_cub *c, double step, int flag);
double		ft_ray_cast(t_cub *c, double step, int flag);
int			ft_iswall(t_cub *c, double x, double y, int flag);
int			ft_wall_or_door_set(t_cub *c, char chr);
char		**ft_select_map(t_cub *c, int flag);
int			ft_iswall_util(t_cub *c, double x, double y, int flag);

//===========================================================================
// draw
//===========================================================================

void		my_mlx_pixel_put(t_cub *c, int x, int y, int color);
int			ft_get_xmp_pixel_color(t_xpm xpm, int x, int y);
int			ft_draw_floor_and_ceilling(t_cub *c);
int			ft_draw_red_arrow(t_cub *c);
int			ft_line_point(t_cub *c, int line_height, char *place);
void		ft_draw_wall_by_map(t_cub *c, int map_flag);
void		ft_set_ways_length(t_cub *c);
void		ft_draw_minimap(t_cub *c);
void		ft_draw_player(t_cub *c);
int			ft_xpm_color_no(t_cub *c, int start, int end, int win_y);
int			ft_xpm_color_so(t_cub *c, int start, int end, int win_y);
int			ft_xpm_color_we(t_cub *c, int start, int end, int win_y);
int			ft_xpm_color_ea(t_cub *c, int start, int end, int win_y);

//===========================================================================
// hooks
//==========================================================================

void		ft_turn_around_util1(t_cub *c, double angle);
void		ft_turn_around_util2(t_cub *c, double angle);
void		ft_turn_around(t_cub *c, int keycode, double acceleration);
int			key_hook(int keycode, t_cub *c);
void		ft_open_door(t_cub *c);
int			ft_close(t_cub *c);
void		ft_go_forward(t_cub *c);
void		ft_go_back(t_cub *c);
void		ft_go_left(t_cub *c);
void		ft_go_right(t_cub *c);
int			mouse_hook(int x, int y, t_cub *c);
void		ft_mouse_move(t_cub *c);
int			mouse_click(int button);

//===========================================================================
// parsing
//===========================================================================

void		ft_map_name_check(char *map_path);
int			ft_empty_or_only_spaces_str(char *str);
int			ft_begins_with_valid_xpm_name(char *str);
int			ft_valid_xpm_names(char	*map_path, char *buff, int cnt, int rt);
int			ft_begins_with_valid_color_name(char *str);
int			ft_valid_color_names(char *map_path, char *buff, int cnt, int rt);
char		*ft_color_or_xpm_path(char *str, int flag);
void		ft_xpm_path_check(char *map_path, t_cub *c);
void		ft_check_comma_count(char *map_path, char *buff, int cnt);
void		ft_check_allowed_chars(char *map_path, char *buff, int cnt);
int			ft_check_long_long_limits(char *str);
void		ft_get_color_values(char *map_path, t_cub *c);
void		ft_chek_nsew_char_cnt(char **map);
char		**ft_get_map(char *map_path, t_cub *c);
void		ft_align_arr(char **arr);
void		ft_check_inside_chars(char **map);

//===========================================================================
// sprite
//===========================================================================

double		ft_distance(double x1, double y1, double x2, double y2);
double		ft_heron_forumla(double a, double b, double c);
double		ft_cosine_length(double a, double b, double angle);
double		ft_cosine_angle(double a, double b, double c);
t_sprt		*ft_new_sprt_node(int i, int j);
void		ft_add_sprt_node(t_sprt **head, t_sprt *new);
void		ft_fill_sprt_tmp(double x, double y);
void		ft_free_sprt_list(t_cub *c);
void		ft_fill_node1(t_cub *c, t_sprt *node);
void		ft_fill_node2(t_cub *c, t_sprt *node);
void		ft_fill_node3(t_cub *c, t_sprt *node);
void		ft_fill_node4(t_cub *c, t_sprt *node);
void		ft_fill_node(t_cub *c, t_sprt *node);
void		ft_create_sprt_list(t_cub *c, int i, int j);
double		ft_abgle_of_vector(double x, double y);
int			ft_is_1st_grater_than_2nd(double angle1, double angle2);
int			ft_xpm_color_sprt(t_cub *c, int start, int end, int win_y);
int			ft_sprt_line_height(t_cub *c);
void		ft_draw_sprt_line(t_cub *c, int x);
void		ft_draw_sprites(t_cub *c, int x);
void		ft_animation_speed(t_cub *c);
void		ft_open_sprites(t_cub *c);

#endif
