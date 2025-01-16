/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkheired <hkheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:32:52 by hkheired          #+#    #+#             */
/*   Updated: 2025/01/16 08:32:54 by hkheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	clean_parse(t_game *cub3d)
{
	if (!cub3d)
		return ;
	if (cub3d->north)
		free (cub3d->north);
	if (cub3d->south)
		free (cub3d->south);
	if (cub3d->east)
		free (cub3d->east);
	if (cub3d->west)
		free (cub3d->west);
	if (cub3d->line)
		free (cub3d->line);
	if (cub3d->colors)
		free_matrix(cub3d->colors);
	if (cub3d->temp_map)
		free (cub3d->temp_map);
	if (cub3d->map)
		free_matrix(cub3d->map);
}

int	exit_error(t_game *cub3d, char *msg)
{
	clean_parse(cub3d);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

void	invalid_xpm_error(t_game *game, char *msg)
{
	if (game->north_img.img)
		mlx_destroy_image(game->mlx, game->north_img.img);
	if (game->south_img.img)
		mlx_destroy_image(game->mlx, game->south_img.img);
	if (game->east_img.img)
		mlx_destroy_image(game->mlx, game->east_img.img);
	if (game->west_img.img)
		mlx_destroy_image(game->mlx, game->west_img.img);
	if (game->frame.img)
		mlx_destroy_image(game->mlx, game->frame.img);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	clean_parse(game);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

int	end_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->frame.img);
	mlx_destroy_image(game->mlx, game->north_img.img);
	mlx_destroy_image(game->mlx, game->south_img.img);
	mlx_destroy_image(game->mlx, game->east_img.img);
	mlx_destroy_image(game->mlx, game->west_img.img);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	clean_parse(game);
	printf("\n	\033[0;91mThank you for playing our cub3D maze!\033[0m\n\n");
	exit(EXIT_SUCCESS);
}

//clean_parse() function is used to free dynamically allocated 
//memory associated with a t_game structure (cub3d).
//
//exit_error() function handles errors by cleaning up allocated memory,
//displaying an error message, and terminating the program.
//
//free_matrix() function is used to free the double arrays(matrix) from struct.
//
//The invalid_xpm_error function is designed to handle errors related to loading
//XPM textures and clean up resources properly before exiting the program.
//
//end_game() function is typically called when the player chooses to quit the 
//game or when the game needs to exit for any reason