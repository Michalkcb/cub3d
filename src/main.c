/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:26 by ltomasze          #+#    #+#             */
/*   Updated: 2025/04/03 20:10:31 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_game(t_game *game)
{
	//free_texture_paths(game);
	 free_all_textures(game);
	if (game->map)
		free_map(game->map);
	if (game->copy_map)
		free_map(game->copy_map);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	return (1);
}

int	close_button(t_game *game)
{
	close_game(game);
	exit(0);
	return (0);
}

int	draw_loop(t_game *game)
{
	t_player	*player;
	float		ray_angle;
	float		angle_increment;
	int			column;

	player = &game->player;
	rotate_player(player);
	move_player(player, game);
	clear_image(game);
	draw_floor_ceiling(game);
	ray_angle = player->angle - (PI / 6);
	angle_increment = (PI / 3) / WIDTH;
	column = 0;
	while (column < WIDTH)
	{
		draw_line(player, game, ray_angle, column);
		ray_angle += angle_increment;
		column++;
	}
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	// t_config	config;
	t_game		game;

	game.config.map = NULL;
	game.config.textures[0] = NULL;
	game.config.textures[1] = NULL;
	game.config.textures[2] = NULL;
	game.config.textures[3] = NULL;
	game.config.floor_color = -1;
	game.config.ceiling_color = -1;
	if (ft_check(argc, argv))
		return (1);
	if (ft_parse(argv[1], &game.config))
	{
		printf("Error: Failed to parse .cub file\n");
		ft_free_config(&game.config);
		return (1);
	}
	// printf("1 Address of north texture path: %s\n", game.n_tex_path);
	game.n_tex_path = game.config.textures[0];
	game.s_tex_path = game.config.textures[1];
	game.w_tex_path = game.config.textures[2];
	game.e_tex_path = game.config.textures[3];
	printf("1 Address of north texture path: %s\n", game.n_tex_path);
	game.color_floor = game.config.floor_color;
	game.color_ceiling = game.config.ceiling_color;
	game.map = game.config.map;
	printf("2 Address of north texture path: %s\n", game.n_tex_path);
	printf("3 Address of north texture path: %s\n", game.n_tex_path);
	if (!init_game(&game, argv[1]))
	{
		printf("Error: Failed to initialize game\n");
		return (1);
	}
	printf("5 Address of north texture path: %s\n", game.n_tex_path);
	ft_free_config(&game.config);
	mlx_hook(game.win, 2, 1L << 0, key_down, &game);
	mlx_hook(game.win, 3, 1L << 1, key_up, &game.player);
	mlx_hook(game.win, 17, 0, close_button, &game);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
