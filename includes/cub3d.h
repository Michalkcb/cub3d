/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:16:49 by ltomasze          #+#    #+#             */
/*   Updated: 2025/03/02 14:23:47 by mbany            ###   ########.fr       */
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
    void    *mlx;
    void    *win;
	char    **map;
}   t_game;

#define ESC_KEY 65307  // ESC

//check_tcm.c
char *ft_skip_spaces(char *line);
int ft_is_texture_line(char *line);
int ft_is_color_line(char *line);
int ft_is_map_line(char *line);
int ft_check_tcm(const char *filename);

//window.c
void new_window(t_game *game, const char *map_file);

//map.c
char **ft_load_map(const char *filename);
void draw_map(t_game *game);

//key.c
int handle_key(int key, t_game *game);

//free.c
void free_map(char **map);
void clean_exit(t_game *game);


