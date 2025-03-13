/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:16:49 by ltomasze          #+#    #+#             */
/*   Updated: 2025/03/13 20:11:40 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"
# include "../includes/get_next_line.h"

typedef struct s_game
{
    void *mlx;
    void *win;
    char **map;
    double player_x;
    double player_y;
    double move_speed;
    void *textures[4];
    int tex_width;
    int tex_height;
    int bpp;
    int size_line;
    int endian;
} t_game;



#define ESC_KEY 65307  // ESC
#define W_KEY 119 // ASCII code for 'w'
#define A_KEY 97  // ASCII code for 'a'
#define S_KEY 115 // ASCII code for 's'
#define D_KEY 100 // ASCII code for 'd'

#define INITIAL_PLAYER_X 2
#define INITIAL_PLAYER_Y 6

//check_tcm.c
char *ft_skip_spaces(char *line);
int ft_is_texture_line(char *line);
int ft_is_color_line(char *line);
int ft_is_map_line(char *line);
int ft_check_tcm(const char *filename);

//free.c
//main.c
void clean_exit(t_game *game);

//kay.c
int handle_key(int key, t_game *game);

//map.c
void free_map(char **map);
char **ft_load_map(const char *filename);
void draw_map(t_game *game);

//window.c
void new_window(t_game *game, const char *map_file);

//raycasting.c
void draw_3d_view(t_game *game);

//textures.c
void load_textures(t_game *game);
