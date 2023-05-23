
#include "so_long.h"

int    close_game(t_game *game)
{
    free_all(game);
    exit(1);
}

void	free_all(t_game *game)
{
	// write(1, "NNN",3 );
	// ft_printf("alloc img = %d, alloc map = %d", game->allocate_img, game->map.allocate_map);
	if (game->allocate_img == 1)
	{
		mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->exit_close.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->exit_open.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->player_front.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->player_back.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->player_right.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->player_left.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->item.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->obstacles.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->umbrella.xpm_ptr);
		//mlx_destroy_image(game->mlx_ptr, game->player.xpm_ptr);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->map.allocate_map == 1)
		free_map(game);
	free(game);
	//mlx_destroy_image(game->mlx_ptr, game->player.xpm_ptr);

}

void    ft_error(t_game *game, char *string)
{
	free_all(game);
	ft_printf("%s", string);
	exit(1);
}

int check_arg(char *argv)
{
    int i;
    i = 0;

    while (argv[i] != '\0')
        i++;
    i = i - 4;
    if (argv[i] != '.' && argv[i + 1] != 'b' && argv[i + 2] != 'e' && argv[i + 3] != 'r')
        return (0);
    else
        return (1);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
		free(game->map.full_map[i++]);
	free (game->map.full_map);
}