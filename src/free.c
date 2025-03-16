/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:23:41 by mbany             #+#    #+#             */
/*   Updated: 2025/03/16 14:30:53 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void free_map(char **map)
{
    if (!map)
        return;
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}
void clean_exit(t_game *game)
{

    if (game->map)
        free_map(game->map);
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
    {
		mlx_destroy_image(game->mlx, game->textures[0]);
		mlx_destroy_image(game->mlx, game->textures[1]);
		mlx_destroy_image(game->mlx, game->textures[2]);
		mlx_destroy_image(game->mlx, game->textures[3]);
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    exit(0);
}

