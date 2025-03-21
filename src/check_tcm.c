/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tcm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltomasze <ltomasze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:22:40 by ltomasze          #+#    #+#             */
/*   Updated: 2025/03/02 12:27:38 by ltomasze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char *ft_skip_spaces(char *line)
{
    while (*line && *line == ' ')
        line++;
    return line;
}

int ft_is_texture_line(char *line)
{
    line = ft_skip_spaces(line);
    if (ft_strncmp(line, "NO", 2) == 0)
        return 1;
    else if (ft_strncmp(line, "SO", 2) == 0)
        return 1;
    else if (ft_strncmp(line, "WE", 2) == 0)
        return 1;
    else if (ft_strncmp(line, "EA", 2) == 0)
        return 1;
    return 0;
}

int ft_is_color_line(char *line)
{
    line = ft_skip_spaces(line);

    if (line[0] == 'F')
        return 1;
    else if (line[0] == 'C')
        return 1;
    return 0;
}

int ft_is_map_line(char *line)
{
    line = ft_skip_spaces(line);
	if (line[0] == '1')
        return 1;
    return 0;
}

int ft_check_tcm(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    char *line;
    int has_texture = 0;
    int has_color = 0;
    int has_map = 0;

    while ((line = get_next_line(fd)) != NULL)
	{
		if (line == NULL)
		{
            free(line);
            continue;
		}
        char *trimmed = ft_skip_spaces(line);
		if (*trimmed == '\0') 
		{
            free(line);
            continue;
        }
        if (ft_is_texture_line(trimmed))
            has_texture = 1;
        else if (ft_is_color_line(trimmed))
            has_color = 1;
        else if (ft_is_map_line(trimmed))
            has_map = 1;
        free(line);
    }
    close(fd);
    if (!has_texture || !has_color || !has_map)
    {
        printf("Error: Missing textures, colors, or map in .cub file.\n");
        return (1);
    }
    return (0);
}

