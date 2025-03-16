/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:21:28 by mbany             #+#    #+#             */
/*   Updated: 2025/03/16 16:53:17 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int handle_key(int key, t_game *game)
{
    int new_x = game->player_x;
    int new_y = game->player_y;

    if (key == ESC_KEY)
        clean_exit(game);
    else if (key == W_KEY)
        new_y -= game->move_speed;
    else if (key == S_KEY)
        new_y += game->move_speed;
    else if (key == A_KEY)
        new_x -= game->move_speed;
    else if (key == D_KEY)
        new_x += game->move_speed;
        
    else if (key == LEFT_ARROW_KEY || key == RIGHT_ARROW_KEY)
    {
        double oldDirX = game->dirX;
        double oldPlaneX = game->planeX;
        double rotAngle = (key == LEFT_ARROW_KEY ? -1 : 1) * game->rot_speed;

        // Obrót wektora kierunku
        game->dirX = game->dirX * cos(rotAngle) - game->dirY * sin(rotAngle);
        game->dirY = oldDirX * sin(rotAngle) + game->dirY * cos(rotAngle);

        // Obrót płaszczyzny kamery
        game->planeX = game->planeX * cos(rotAngle) - game->planeY * sin(rotAngle);
        game->planeY = oldPlaneX * sin(rotAngle) + game->planeY * cos(rotAngle);
    }

    // Check for collision with walls
    if (game->map[new_y][new_x] != '1')
    {
        game->player_x = new_x;
        game->player_y = new_y;
    }

    draw_3d_view(game);
    // draw_map(game);
    return (0);
}