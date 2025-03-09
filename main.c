/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:45:26 by ltomasze          #+#    #+#             */
/*   Updated: 2025/03/04 18:21:55 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_check_args(int argc, char **argv)
{
	if(argc != 2)
		return(printf("Error: wrong number of arguments.\n"), 1);
	int len;
	len = ft_strlen(argv[1]);
	if(len < 4 || ft_strncmp(argv[1] + len - 4, ".cub", len) != 0)
		return(printf("Error: wrong file extension, expected '.cub'.\n"), 1);
	int fd = open(argv[1], O_RDONLY);
	if(fd == - 1)
		return(printf("Error: file does not exist.\n"), 1);
	close(fd);
	return 0;
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


int	main(int argc, char **argv)
{
    t_game game;
	if(ft_check_args(argc, argv))
	{
		printf("Usage: ./cub3d maps/<map_file.cub>\n");
		return 1;
	}
	if(ft_check_tcm(argv[1]))
		return 1;
    new_window(&game, argv[1]);

	return 0;
}
