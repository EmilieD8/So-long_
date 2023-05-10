#include "so_long.h"

void    ft_initialize_variables(t_game *game)
{
    game->map.item = 0;
    game->map.exit = 0;
    game->map.entrance = 0;
    game->movements = 0;
    game->player = game->player_front;
}

void    ft_initialize_mlx(t_game *game)
{
    game->mlx_ptr = mlx_init();
    if (game->mlx_ptr == NULL)
        ft_error(game, "Error while initiating the game.");
    game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns * IMG_HEIGHT, game->map.rows * IMG_WIDTH, "so_long de Emilie"); // adapt dimensions
    if (game->win_ptr == NULL)
        ft_error(game, "Error while initiating the window.");

}

t_image ft_new_image(void *mlx_ptr, char *path, t_game *game)
{
    t_image sprite;
    
    sprite.xpm_ptr = mlx_xpm_file_to_image(mlx_ptr, path, &sprite.x, &sprite.y);
    if (sprite.xpm_ptr == NULL)
        ft_error(game, "The image was not allocated correctly");
    return (sprite);
}

void ft_initialize_images(t_game *game)
{    
    game->wall = ft_new_image(game->mlx_ptr, WALL_IMG, game); // enlever game->mlx 
    game->floor = ft_new_image(game->mlx_ptr, FLOOR_IMG, game);
    game->exit_close = ft_new_image(game->mlx_ptr, EXIT_CLOSE_IMG, game);
    game->exit_open = ft_new_image(game->mlx_ptr, EXIT_OPEN_IMG, game);
    game->player_front = ft_new_image(game->mlx_ptr, PLAYER_F_IMG, game);
    game->player = ft_new_image(game->mlx_ptr, PLAYER_F_IMG, game);
    game->player_back = ft_new_image(game->mlx_ptr, PLAYER_B_IMG, game);
    game->player_right = ft_new_image(game->mlx_ptr, PLAYER_R_IMG, game);
    game->player_left = ft_new_image(game->mlx_ptr, PLAYER_L_IMG, game);
    game->item = ft_new_image(game->mlx_ptr, ITEM_IMG, game);
    game->obstacles = ft_new_image(game->mlx_ptr, OBSTACLES_IMG, game);
}

void    ft_initialize_game(t_game *game)
{
    ft_initialize_mlx(game);
    ft_initialize_images(game);  
}

