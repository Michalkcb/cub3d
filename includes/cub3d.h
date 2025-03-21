/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:16:49 by ltomasze          #+#    #+#             */
/*   Updated: 2025/03/16 17:06:24 by mbany            ###   ########.fr       */
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

    double dirX;
    double dirY;
    
    double planeX;
    double planeY;
    
    double move_speed;
    double rot_speed;
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

#define LEFT_ARROW_KEY 65361
#define RIGHT_ARROW_KEY 65363



//check_tcm.c
char *ft_skip_spaces(char *line);
int ft_is_texture_line(char *line);
int ft_is_color_line(char *line);
int ft_is_map_line(char *line);
int ft_check_tcm(const char *filename);

//main.c

//kay.c
int handle_key(int key, t_game *game);

//map.c
char **ft_load_map(const char *filename);
void draw_map(t_game *game);

//window.c
void new_window(t_game *game, const char *map_file);

//raycasting.c
void draw_3d_view(t_game *game);

//textures.c
void load_textures(t_game *game);

//free.c
// void free_textures(t_game *game);
void free_map(char **map);
void clean_exit(t_game *game);

//init_game.c
void init_game(t_game *game);
