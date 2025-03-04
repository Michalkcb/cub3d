/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kay.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:21:28 by mbany             #+#    #+#             */
/*   Updated: 2025/03/04 19:12:03 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int handle_key(int key, t_game *game)
{
    if (key == ESC_KEY)
        clean_exit(game);
    else if (key == W_KEY)
        game->player_y -= game->move_speed;
    else if (key == S_KEY)
        game->player_y += game->move_speed;
    else if (key == A_KEY)
        game->player_x -= game->move_speed;
    else if (key == D_KEY)
        game->player_x += game->move_speed;

    draw_map(game); // Redraw the map with the updated player position
    return (0);
}