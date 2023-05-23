#include "so_long.h"

// static void	free_map_copy(char **copy)
// {
// 	int	i;

// 	i = 0;
// 	while (i < game->map.rows)
// 		free(copy[i++]);
// 	free(copy);
// }

int check_path(t_game *copy, int x, int y)
{
    if (copy->map.full_map[y][x] == '1' || copy->map.full_map[y][x] == 'X')
        return (0);
    if (copy->map.full_map[y][x] == 'E')
    {
        copy->map.exit = 1;
        return (0);
    }
    copy->map.full_map[y][x] = '1';
    if (check_path(copy, x, y + 1))
        return (1);
    if (check_path(copy, x, y - 1))
        return (1);
    if (check_path(copy, x + 1, y))
        return (1);
    if (check_path(copy, x - 1, y))
        return (1);
    return (0);
}

void flood_fill(t_game *game)
{
    t_game copy;

    int i;
    copy.map.exit = 0;
    copy.map.full_map = (char **)malloc((game->map.rows) * sizeof(char *));   // +1 in map rows
    if (!copy.map.full_map)
        ft_error(game, "Memory allocation failed");
    i = 0;
    while (i < game->map.rows)
	{
       copy.map.full_map[i] = ft_strdup(game->map.full_map[i]);
	    i++;
	}
    // copy.map.full_map = get_map("map_invalid.ber", game);
    copy.map.exit = 0;
    copy.map.player.x = game->map.player.x;
    copy.map.player.y = game->map.player.y;
    copy.map.rows = game->map.rows;
    check_path(&copy, copy.map.player.x, copy.map.player.y);
    if (copy.map.exit == 0)
    {
        free_map(&copy);
        ft_error(game, "Valid path not found !");
    }
    free_map(&copy);
 }
