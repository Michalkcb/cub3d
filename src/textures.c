/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:42:26 by mbany             #+#    #+#             */
/*   Updated: 2025/03/11 20:08:16 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void load_textures(t_game *game)
{
    game->textures[0] = mlx_xpm_file_to_image(game->mlx, "textures/mossy.xpm", &game->tex_width, &game->tex_height);
	if (!game->textures[0])
        exit(printf("Error: failed to load texture1\n"));
    game->textures[1] = mlx_xpm_file_to_image(game->mlx, "textures/color_stone.xpm", &game->tex_width, &game->tex_height);
	if (!game->textures[1])
        exit(printf("Error: failed to load texture2\n"));
    game->textures[2] = mlx_xpm_file_to_image(game->mlx, "textures/red_brick.xpm", &game->tex_width, &game->tex_height);
	if (!game->textures[2])
        exit(printf("Error: failed to load texture3\n"));
    game->textures[3] = mlx_xpm_file_to_image(game->mlx, "textures/purple_stone.xpm", &game->tex_width, &game->tex_height);
	if (!game->textures[3])
        printf("Error: failed to load texture4\n"), exit(1);
	printf("Texture width: %d, height: %d\n", game->tex_width, game->tex_height);
}
