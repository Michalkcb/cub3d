/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:19:05 by mbany             #+#    #+#             */
/*   Updated: 2025/03/23 12:50:42 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



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
    int tile_size = BLOCK / 8; // Rozmiar kafelka na minimapie (1/8 rozmiaru bloku)
    int offset_x = 10;        // Przesunięcie minimapy od lewej krawędzi
    int offset_y = 10;        // Przesunięcie minimapy od górnej krawędzi

    // Iteracja po mapie
    for (y = 0; game->map[y] != NULL; y++)
    {
        for (x = 0; game->map[y][x] != '\0'; x++)
        {
            int color = 0x000000; // Domyślny kolor (czarny)

            if (game->map[y][x] == '1') // Ściana
                color = 0xFF0000; // Czerwony
            else if (game->map[y][x] == '0') // Puste miejsce
                color = 0x2F2F2F; // Szary

            // Rysowanie kafelka na obrazie
            for (int i = 0; i < tile_size; i++)
            {
                for (int j = 0; j < tile_size; j++)
                {
                    put_pixel(offset_x + x * tile_size + i,
                              offset_y + y * tile_size + j,
                              color, game);
                }
            }
        }
    }

    // Rysowanie gracza na minimapie
    int player_tile_x = offset_x + (game->player.x / BLOCK) * tile_size;
    int player_tile_y = offset_y + (game->player.y / BLOCK) * tile_size;

    for (int i = 0; i < tile_size; i++)
    {
        for (int j = 0; j < tile_size; j++)
        {
            put_pixel(player_tile_x + i,
                      player_tile_y + j,
                      0x00FF00, game); // Zielony kolor dla gracza
        }
    }
}

