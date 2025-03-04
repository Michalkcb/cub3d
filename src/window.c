/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:19:57 by mbany             #+#    #+#             */
/*   Updated: 2025/03/04 19:59:15 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void new_window(t_game *game, const char *map_file)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        exit(printf("Error: mlx init failed\n"));

    game->win = mlx_new_window(game->mlx, 1440, 720, "Cub3D");
    if (!game->win)
        exit(printf("Error: window creation failed\n"));

    game->map = ft_load_map(map_file);
    if (!game->map)
        exit(printf("Error: failed to load map\n"));

    game->player_x = INITIAL_PLAYER_X; // Set initial player x position
    game->player_y = INITIAL_PLAYER_Y; // Set initial player y position
    game->move_speed = 1; // Set player movement speed
	game->move_speed = 1; // Set player movement speed
    game->rotate_speed = 15; 

    draw_map(game);
    mlx_key_hook(game->win, handle_key, game);
    mlx_loop(game->mlx);
    free_map(game->map);

}