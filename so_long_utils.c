
#include "so_long.h"

void	free_all(t_game *game)
{
	if (game->allocate_img == 1)
	{
		game = NULL;
		free(game->mlx_ptr);
		free(game->win_ptr);
		mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->item.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->player_front.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->player_right.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->player_back.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->player_left.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->door.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->exit_open.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->exit_close.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->obstacles.xpm_ptr);
		mlx_destroy_image(game->mlx_ptr, game->player.xpm_ptr);
	}
	if (game->map.allocate_map == 1)
		free_map(game);
}


void    ft_error(t_game *game, char *string)
{
	free_all(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	ft_printf("%s", string);
	exit(1);
}

void	free_map(t_game *game)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i != game->map.rows)
    {
        while (j != game->map.columns)
        {
			free((void *)game->map.full_map[i]);
            j++;
        }
        j = 0;
        i++;
    }
	free(game->map.full_map[i]);
	return ;
}
