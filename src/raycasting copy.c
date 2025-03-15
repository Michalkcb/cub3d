/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:40:28 by mbany             #+#    #+#             */
/*   Updated: 2025/03/15 13:53:17 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void draw_3d_view(t_game *game)
{
    int w = 1440; // szerokość okna
    int h = 720;  // wysokość okna
    double posX = game->player_x;
    double posY = game->player_y;
    double dirX = 1, dirY = 0; // kierunek gracza
    double planeX = 0, planeY = 0.66; // płaszczyzna kamery

    int x = 0;
    while (x < w)
    {
        double cameraX = 2 * x / (double)w - 1;
        double rayDirX = dirX + planeX * cameraX;
        double rayDirY = dirY + planeY * cameraX;

        int mapX = (int)posX;
        int mapY = (int)posY;

        double sideDistX;
        double sideDistY;

        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (posX - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - posX) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (posY - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - posY) * deltaDistY;
        }

        while (hit == 0)
        {
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (game->map[mapY][mapX] == '1') hit = 1;
        }

        if (side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
        else           perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(h / perpWallDist);

        int drawStart = -lineHeight / 2 + h / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + h / 2;
        if (drawEnd >= h) drawEnd = h - 1;

        int texNum;
        if (side == 1)
        {
            if (rayDirY > 0)
                texNum = 0; // prawa ściana - red_stone
            else
                texNum = 1; // lewa ściana - blue_stone
        }
        else
        {
            if (rayDirX > 0)
                texNum = 2; // przednia ściana - grey_stone
            else
                texNum = 3; // tylna ściana - color_stone
        }

        double wallX;
        if (side == 0) wallX = posY + perpWallDist * rayDirY;
        else           wallX = posX + perpWallDist * rayDirX;
        wallX -= floor(wallX);

        int texX = (int)(wallX * (double)game->tex_width);
        if (side == 0 && rayDirX > 0) texX = game->tex_width - texX - 1;
        if (side == 1 && rayDirY < 0) texX = game->tex_width - texX - 1;

        char *texture_data = mlx_get_data_addr(game->textures[texNum], &game->bpp, &game->size_line, &game->endian);
        for (int y = drawStart; y < drawEnd; y++)
        {
            int d = y * 256 - h * 128 + lineHeight * 128;
            int texY = ((d * game->tex_height) / lineHeight) / 256;
            if (texY < 0 || texY >= game->tex_height) continue; // Sprawdź zakres texY
            int color = *(int *)(texture_data + (texY * game->size_line + texX * (game->bpp / 8)));
            mlx_pixel_put(game->mlx, game->win, x, y, color);
        }
        x++;
    }
}