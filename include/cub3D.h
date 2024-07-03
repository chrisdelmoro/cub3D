/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:37:56 by mcarecho          #+#    #+#             */
/*   Updated: 2023/10/15 20:55:46 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* MiniLibX Library */
//# include <mlx.h>

/* Native libraries */

# include <stdlib.h>
# include <math.h>

/* open() function includes */
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/* read() and close() include */
# include <unistd.h>

/* Libft */

# include <libft.h>
# include <ft_printf.h>
# include <get_next_line.h>

/* MiniLibX */

# include <mlx.h>

/* Define */

# define NUM_PARAM 1
# define WRONG_FILE 2
# define MAP_NONEXISTENT 3
# define TEXTURES_INVALID 4
# define COLORS_INVALID 5
# define MAP_NOT_LAST 6
# define MAP_NOT_WALLED 7
# define MAP_CHARS_NOT_VALID 8
# define MAP_PLAYERS_NOT_VALID 9
# define MINILIB_FAILED_WINDOW 10
# define MINILIB_FAILED_SPRITE 11
# define END_LINE_INVALID 12
# define VALID_CHARS "10NSEW "
# define VALID_PLAYER_CHARS "NSEW"
# define VALID_CHAR_0 "10NSEW"
# define VALID_CHAR_V "0NSEW"
# define MAP_X 800
# define MAP_Y 600
# define MAP_S 64 // tamanho da sprite
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define ROT_SPEED 1.6
# define MOVE_SPEED 2.0

/* Structs */

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_player
{
	int		x;
	int		y;
	float	px;
	float	py;
	float	pdx;
	float	pdy;
	float	pa;

}				t_player;

typedef struct s_img
{
	void	*sprite_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
	int		color;
}				t_img;

typedef struct s_scene
{
	int					fd;
	char				**scene_lines;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	unsigned int		f;
	unsigned int		c;
	char				**map;
	int					max_x;
	int					max_y;
	t_player			*player;
}				t_scene;

typedef struct s_sprite
{
	t_img	*ea;
	t_img	*no;
	t_img	*so;
	t_img	*we;
}			t_sprite;

typedef struct s_input_keys
{
	t_bool		w;
	t_bool		a;
	t_bool		s;
	t_bool		d;
	t_bool		left;
	t_bool		right;
}				t_input_keys;

typedef struct s_ray {
	int			r;
	int			mx;
	int			my;
	int			mp;
	int			dof;
	float		rx;
	float		ry;
	float		ra;
	float		xo;
	float		yo;
	float		vx;
	float		vy;
	float		dis_v;
	float		dis_h;
	float		tan;
	char		eye_v;
	char		eye_h;
}				t_ray;

typedef struct s_ray_print{
	int			ca;
	int			line_h;
	int			line_off;
	int			color;
	double		ty;
	double		tx;
	double		ty_step;
	float		ty_off;
	float		shade;
}				t_ray_print;

typedef struct s_game
{
	t_img			*img;
	void			*mlx;
	void			*win;
	t_sprite		*sprites;
	t_scene			*scene;
	t_input_keys	input_keys;
	t_player		*player;
}				t_game;

/* Functions */
void			throw_err(int err);
int				is_param_valid(int argc, char **argv);
int				is_scene_valid(char *map_path, t_scene *scene);
int				initialize_scene(t_scene *scene, char *map_path);
int				check_textures_exist(t_scene *scene);
int				feed_scene_textures(t_scene *scene);
int				feed_scene_floor_and_celling(t_scene *scene);
int				final_scene_checks(t_scene *scene);
void			close_scene(t_scene *scene);
int				create_rgb(int r, int g, int b);
int				get_r(int rgb);
int				get_g(int rgb);
int				get_b(int rgb);
unsigned int	parse_color(char *RGB);
int				feed_scene_map(t_scene *scene);
int				is_map_walled(t_scene *scene);
int				are_map_chars_valid(t_scene *scene);
int				are_map_players_valid(t_scene *scene);
void			init_game(t_game *game, t_scene *scene);
float			deg_to_rad(float deg);
float			fix_ang(float ang);
int				key_pressed(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
void			draw_mini_map(t_game *game, int a, int b, int y);
int				print_view(t_game *game);
int				init_player(t_scene *scene, int i, int j, char direction);
int				img_init(char *file_path, void *mlx, t_img *img);
t_sprite		*sprite_init(t_game *game);
void			square(t_game *game, int x, int y, int color);
void			horizontal_ray_check(t_game *game, t_ray *ray);
void			vertical_ray_check(t_game *game, t_ray *ray);
void			horizontal_ray_dist(t_game *game, t_ray *ray);
void			vertical_ray_dist(t_game *game, t_ray *ray);
int				create_trgb(int t, int r, int g, int b);
void			calculate_ray_wall_height(t_game *game, t_ray *ray, \
t_ray_print *p_ray);
int				get_sprite_color(int pixel, char *sprite, int shade);
void			verify_shade(t_ray *ray, t_ray_print *p_ray);
void			draw_wall(t_game *game, t_ray *ray, t_ray_print *p_ray);
void			draw_floor_celing(t_game *game, t_ray *ray, t_ray_print *p_ray);
int				draw_line(t_game *game, int begin[2], int end[2], int color);
void			cam_rotation(t_game *game);
int				collision(float p, float pd, t_bool is_sub);
void			move_front_back(t_game *game);
void			move_right_left(t_game *game);
void			move_player(t_game *game);
int				clean_all(t_game *game);
void			free_ptr(void **ptr);
int				are_map_chars_valid_utils(t_scene *scene, size_t i, size_t j);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);

#endif
