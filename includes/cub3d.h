/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:16:49 by ltomasze          #+#    #+#             */
/*   Updated: 2025/03/25 20:12:17 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"
# include "../includes/get_next_line.h"

typedef struct s_player
{
	bool		key_left;
	bool		key_right;
	bool		key_up;
	bool		key_down;
	bool		rotate_left;
	bool		rotate_right;
	float		x;
	float		y;
	float		angle;
}	t_player;

typedef struct s_texture
{
	int			line_size;
	int			h;
	int			endian;
	int			w;
	char		*data;
	int			bpp;
	void		*img;
}	t_tex;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	char		**map;
	char		**copy_map;
	int			fd;
	int			bpp;
	int			line_size;
	int			endian;
	int			color_floor;
	int			color_ceiling;
	int			n_path;
	int			s_path;
	int			w_path;
	int			e_path;
	char		*n_tex_path;
	char		*s_tex_path;
	char		*w_tex_path;
	char		*e_tex_path;
	t_player	player;
	t_tex		n_tex;
	t_tex		s_tex;
	t_tex		w_tex;
	t_tex		e_tex;
}	t_game;

typedef enum s_error
{
	NO_FILE,
	INVALID_FILE,
	INVALID_SPAWN,
	INVALID_MAP,
	INVALID_INPUT
}	t_error;


typedef struct s_line
{
	float		dist;
	float		wall_h;
	int			start_y;
	int			end_y;
	int			tex_x;
}	t_line;

typedef struct s_ray
{
	float		deltadistx;
	float		raydirx;
	float		sidedistx;
	float		deltadisty;
	float		raydiry;
	float		sidedisty;
	float		perpwalldist;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
}	t_ray;

#define ESC_KEY 65307
#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100

#define LEFT_ARROW_KEY 65361
#define RIGHT_ARROW_KEY 65363

# define WIDTH 1440
# define HEIGHT 720
# define BLOCK 64
# define DEBUG 0
# define COLLISION_RADIUS 10
# define PI 3.14159265359

# define FLOOR 0x009600
# define CELING 0x000096




//main.c
int		close_game(t_game *game);
int		close_button(t_game *game);
int	draw_loop(t_game *game);


//kay.c
// int mouse_move(int x, int y, t_game *game);
int		key_down(int keycode, t_game *game);
int		key_up(int keycode, t_player *player);
void	rotate_player(t_player *player);
void	move_player(t_player *player, t_game *game);


//map.c
char **ft_load_map(const char *filename);
void draw_map(t_game *game);

//window.c
void 	new_window(t_game *game, const char *map_file);
void	put_pixel(int x, int y, int color, t_game *game);
void	clear_image(t_game *game);
void	draw_floor_ceiling(t_game *game);
bool 	touch(float px, float py, t_game *game);

//raycasting.c
void 	draw_3d_view(t_game *game);
void	draw_column(t_game *game, t_tex *texture, int column, t_line *line);
float	compute_corrected_dist(t_ray *ray, t_player *player, float ray_angle);
void	perform_dda(t_ray *ray, t_game *game);
void	calc_delta_dist(t_ray *ray);
void	calc_line(t_player *player, t_ray *ray, t_tex *tex, t_line *line);
void	init_sidedist_step(t_ray *ray, t_player *player);
void	draw_line(t_player *player, t_game *game, float ray_angle, int column);


//textures.c
//void load_textures(t_game *game);
int		load_texture(t_game *game, t_tex *tex, char *path); 
int		load_all_textures(t_game *game);
t_tex	*choose_texture(t_ray *ray, t_game *game);

//free.c
// void free_textures(t_game *game);
void 	free_map(char **map);
void	free_texture(t_game *game, t_tex *texture);
void    clean_exit(t_game *game);
void	free_texture_paths(t_game *game);
void	free_all_textures(t_game *game);


//error.c
//static void	error_clean_up(t_game *game);
int		error(t_error code, t_game *game);

//init_game.c
void	init_ray(t_ray *ray, t_player *player, float ray_angle);
int	    init_game(t_game *game, char *file);
void	init_game_struct(t_game *game);
void	init_player(t_player *player);
int	    parsing(t_game *data);
int     parse_color(char *str);
int     line_redirection(char *line, int *is_map_started, t_game *data);
int     parsing(t_game *data);
void    free_split(char **split);
int	    line_check(char *line, t_game *data);
int	    create_map(char *line, t_game *data);
int	    texture_identifier(int code, char *line, t_game *game);
char	*ft_strjoin_gnl(char *buffer, char *new_s);
char	*tex_path_creator(char *line);
void	path_counter(int code, t_game *data);
char	*load_map(const char *file_path);


