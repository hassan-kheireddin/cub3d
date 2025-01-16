/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdel-f <rabdel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:06:56 by rabdel-f          #+#    #+#             */
/*   Updated: 2025/01/16 12:06:57 by rabdel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	have_numbers(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (NO);
	return (YES);
}

int	have_all_params(t_game *cub3d)
{
	if (cub3d->north && cub3d->south && cub3d->east && cub3d->west
		&& cub3d->floor != -1 && cub3d->ceiling != -1 && cub3d->start_map == 1)
		return (YES);
	return (NO);
}

void	check_texture_file(t_game *cub3d, char *file, int fd)
{
	check_filename(cub3d, file, XPM);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(cub3d, ERR_XPM_OPEN);
	close(fd);
}

char	*get_value(char *line, int i, int mode)
{
	int	end;

	while (line && ft_isspace(line[i]))
		i++;
	end = i;
	if (mode == TEXTURE)
	{
		while (line[end] && !ft_isspace(line[end]) && line[end] != '\n')
			end++;
	}
	else if (mode == COLOR)
	{
		while (line[end] && line[end] != '\n')
			end++;
	}
	line[end] = '\0';
	return (line + i);
}

void	check_filename(t_game *cub3d, char *file, int mode)
{
	size_t	i;

	i = ft_strlen(file) - 4;
	if (mode == CUB && ft_strncmp(&file[i], ".cub", 4) != 0)
		exit_error(NULL, ERR_CUB_EXT);
	else if (mode == XPM && ft_strncmp(&file[i], ".xpm", 4) != 0)
		exit_error(cub3d, ERR_XPM_EXT);
}

//check_filename() function verifies if a given filename
//(file) meets specific criteria based on its extension 
//and the mode (CUB or XPM). If the filename is invalid,
//it handles the error appropriately, including cleanup if necessary.
//
//The get_value() function is responsible for extracting a substring
//from the given line, starting from a specified index i and continuing
//based on the provided mode. The function handles different modes 
//(such as TEXTURE or COLOR) and returns the extracted value as a string.
//
//The check_texture_file() function is responsible for validating a
//texture file, specifically ensuring the file has the correct extension
//and can be opened successfully.
//
//have_number() function checks if all chars are digits
//
//have_all_params() function checks if all required parameters
//have been set in the cub3d structure. It returns YES if all
//the necessary parameters (textures for each side, floor and
//ceiling colors, and the map start flag) are initialized, and NO if
//any of them are missing.
