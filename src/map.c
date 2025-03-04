/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:19:05 by mbany             #+#    #+#             */
/*   Updated: 2025/03/04 19:16:45 by mbany            ###   ########.fr       */
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

char **ft_load_map(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (printf("Error: Cannot open file\n"), NULL);

    char **map = NULL;
    char *line;
    int lines = 0;

    while ((line = get_next_line(fd)) != NULL)
    {
        char *trimmed = line;
        if (ft_is_map_line(trimmed))
        {
            map = realloc(map, sizeof(char *) * (lines + 2));
            map[lines] = ft_strdup(trimmed);
            lines++;
        }
        free(line);
    }
    close(fd);

    if (!map)
        return (printf("Error: No map found in file\n"), NULL);

    map[lines] = NULL;
    return map;
}

void draw_map(t_game *game)
{
    int x, y;
    int tile_size = 32;
    
    for (y = 0; game->map[y] != NULL; y++) // Iteracja po liniach mapy
    {
        int x_offset = 0;

        // Obliczamy przesunięcie w poziomie na podstawie liczby spacji na początku wiersza
        while (game->map[y][x_offset] == ' ') {

            x_offset++;  // Liczymy, ile spacji jest na początku
        }

        for (x = 0; game->map[y][x] != '\0'; x++) // Iteracja po znakach w linii
        {
            if (game->map[y][x] == '1') // Ściana
            {
                // Rysowanie całego kwadratu 32x32 piksele w kolorze czerwonym
                for (int i = 0; i < tile_size; i++)
                {
                    for (int j = 0; j < tile_size; j++)
                    {
                        mlx_pixel_put(game->mlx, game->win, (x) * tile_size + i, y * tile_size + j, 0xFF0000); // Czerwony kolor
                    }
                }
            }
            else if (game->map[y][x] == '0' || game->map[y][x] == ' ') // Puste miejsce
            {
                // Rysowanie całego kwadratu 32x32 piksele w kolorze czarnym
                for (int i = 0; i < tile_size; i++)
                {
                    for (int j = 0; j < tile_size; j++)
                    {
                        mlx_pixel_put(game->mlx, game->win, (x) * tile_size + i, y * tile_size + j, 0x000000); // Czarny kolor
                    }
                }
            }
        }
    }

    // Draw the player
    for (int i = 0; i < tile_size; i++)
    {
        for (int j = 0; j < tile_size; j++)
        {
            mlx_pixel_put(game->mlx, game->win, game->player_x * tile_size + i, game->player_y * tile_size + j, 0x00FF00); // Zielony kolor
        }
    }
}