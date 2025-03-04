/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:16:49 by ltomasze          #+#    #+#             */
/*   Updated: 2025/03/04 19:58:29 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/libft.h"
# include "../includes/get_next_line.h"

typedef struct s_game
{
    void *mlx;
    void *win;
    char **map;
    int player_x;
    int player_y;
    int player_dir;
    int move_speed;
    int rotate_speed;
    // Add other game-related variables here
} t_game;

#define ESC_KEY 65307  // ESC
#define W_KEY 119 // ASCII code for 'w'
#define A_KEY 97  // ASCII code for 'a'
#define S_KEY 115 // ASCII code for 's'
#define D_KEY 100 // ASCII code for 'd'
#define LEFT_ARROW_KEY 65361 // ASCII code for left arrow
#define RIGHT_ARROW_KEY 65363 // ASCII code for right arrow

#define INITIAL_PLAYER_X 5
#define INITIAL_PLAYER_Y 5
#define INITIAL_PLAYER_DIR 0

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