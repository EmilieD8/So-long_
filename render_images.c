#include "so_long.h"

void    correct_image(int element, t_game *game, int row, int column)
{
    if (element == '1')
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall.xpm_ptr, column * game->wall.x, row * game->wall.y);
    else if (element == '0')
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->floor.xpm_ptr, column * game->floor.x, row * game->floor.y);
    else if (element == 'C')
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->item.xpm_ptr, column * game->item.x, row * game->item.y);
    else if (element == 'E' && game->map.item != 0)
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_close.xpm_ptr, column * game->exit_close.x, row * game->exit_close.y);
    else if (element == 'E' && game->map.item == 0)
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->exit_open.xpm_ptr, column * game->exit_open.x, row * game->exit_open.y);
    else if (element == 'P')
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.xpm_ptr, column * game->player_front.x, row * game->player_front.y);
    else if (element == 'X')
        mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->obstacles.xpm_ptr, column * game->obstacles.x, row * game->obstacles.y);
}

void ft_render_images(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    game->allocate_img = 1;
    while (i != game->map.rows)
    {
        while (j != game->map.columns)
        {
            if (game->map.full_map[i][j] == 'P')
            {
                game->map.player.x = i;
                game->map.player.y = j;
            }
            correct_image(game->map.full_map[i][j], game, i, j);
            j++;
        }
        j = 0;
        i++;
    }
}