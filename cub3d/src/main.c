

#include "../includes/cub.h"

void	launch_game(char *file)
{
	t_game	cub3d;

	ft_memset(&cub3d, 0, sizeof(t_game));
	init_game(&cub3d);
	parse_file(&cub3d, file);
	get_screen_size(&cub3d, NULL, NULL);
	render_game(&cub3d);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, ERR_ARGS);
	check_filename(NULL, av[1], CUB);
	launch_game(av[1]);
}

