/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:11:49 by mbany             #+#    #+#             */
/*   Updated: 2025/03/18 20:18:39 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void init_game(t_game *game)
{
    game->player_x = 2.5; // Początkowa pozycja gracza
    game->player_y = 6;
    game->dirX = -1; // Początkowy kierunek gracza (np. patrzy na zachód)
    game->dirY = 0;
    game->planeX = 0; // Płaszczyzna kamery (np. skierowana na północ)
    game->planeY = 0.66;
    game->move_speed = 0.3; // Prędkość ruchu
    game->rot_speed = 0.1; // Prędkość obrotu
}