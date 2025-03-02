/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:22:02 by mbany             #+#    #+#             */
/*   Updated: 2025/03/02 14:22:15 by mbany            ###   ########.fr       */
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
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    exit(0);
}