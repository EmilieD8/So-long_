/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:16:19 by edrouot           #+#    #+#             */
/*   Updated: 2023/05/21 18:44:04 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	// int		fd;
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (argc != 2 || check_arg(argv[1]) == 0)
		ft_error(game, "Invalid arguments !");
	ft_initialize_variables(game);
	game->map.full_map = get_map(argv[1], game);
	if (!check_map(game))
		ft_error(game, "The map is not valid !");
	ft_initialize_game(game);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	ft_render_images(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, *input_keyboard, game);
	mlx_hook(game->win_ptr, 17, 0L, *close_game, game);
	mlx_loop(game->mlx_ptr);
	// free_all(game);
	return (0);
}
