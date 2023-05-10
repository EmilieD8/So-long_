/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:16:19 by edrouot           #+#    #+#             */
/*   Updated: 2023/05/10 14:01:55 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// t_bool is_valid_path(int start_i, int start_j, int end_i, int end_j, t_bool visited[game->map.rows][game->map.columns]) 
// {
//     // Base cases: out of bounds or visited
//     int start_i;
//     int start_j;
//     int end_i;
//     int end_j;
    
//     if (start_i < 0 || start_i >= ROWS || start_j < 0 || start_j >= COLS) {
//         return false;
//     }
//     if (visited[start_i][start_j]) {
//         return false;
//     }

//     // Base case: found end
//     if (start_i == end_i && start_j == end_j) {
//         return true;
//     }

//     // Mark current cell as visited
//     visited[start_i][start_j] = true;

//     // Recursively search in all valid neighboring cells
//     if (grid[start_i][start_j-1] == '0' && is_valid_path(start_i, start_j-1, end_i, end_j, visited)) {
//         return true;
//     }
//     if (grid[start_i][start_j+1] == '0' && is_valid_path(start_i, start_j+1, end_i, end_j, visited)) {
//         return true;
//     }
//     if (grid[start_i-1][start_j] == '0' && is_valid_path(start_i-1, start_j, end_i, end_j, visited)) {
//         return true;
//     }
//     if (grid[start_i+1][start_j] == '0' && is_valid_path(start_i+1, start_j, end_i, end_j, visited)) {
//         return true;
//     }

//     // No valid path found
//     return false;
// }

// int     test_map(t_game *game)
// {
//     int start_i;
//     int start_j;
//     int end_i;
//     int end_j;
//     t_bool visited[game->map.rows][game->map.columns] = { false };

//     int i;
//     int j;
//     i = 0;
//     j = 0;
//     while (i != game->map.rows && j != game->map.columns)
//     {
//         while (j != game->map.columns)
//         {
//             if (game->map.full_map[i][j] == 'P')
//             {
//                 start_i = i;
//                 start_j = j;
//             }
//             if (game->map.full_map[i][j] == 'E')
//             {
//                 end_i = i;
//                 end_j = j;
//             }
//             j++;
//         }
//         j = 0;
//         i++;
//     }
//     if (is_valid_path(start_i, start_j, end_i, end_j, visited[game->map.rows][game->map.columns])) 
//     {
//         printf("There is a valid path from P to E.\n");
//     } else {
//         printf("There is no valid path from P to E.\n");
//     }
//     return 0;
// }



int main(int argc, char **argv)
{
    int fd;
    t_game *game;
    
    game = malloc(sizeof(t_game));
    if (argc != 2)
        ft_error(game, "Not enough arguments !");
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        ft_error(game, "Incorrect file name, cannot be open");
    ft_initialize_variables(game);
    game->map.full_map = get_map(fd);
    if (!check_map(game))
        ft_error(game, "The map is not valid !");
    ft_initialize_game(game);
    ft_render_images(game);
    mlx_hook(game->win_ptr, KeyPress, KeyPressMask, *input_keyboard, game);
    mlx_loop(game->mlx_ptr);
	close(fd);
    return (0);
}
