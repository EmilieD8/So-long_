/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:49:25 by edrouot           #+#    #+#             */
/*   Updated: 2023/05/21 18:34:45 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_keyboard(int key, t_game *game)
{
	if (key == UP || key == KEY_W)
		move_player(game, game->map.player.x - 1,
			game->map.player.y, game->player_back);
	else if (key == DOWN || key == KEY_S)
		move_player(game, game->map.player.x + 1,
			game->map.player.y, game->player_front);
	else if (key == LEFT || key == KEY_A)
		move_player(game, game->map.player.x,
			game->map.player.y - 1, game->player_left);
	else if (key == RIGHT || key == KEY_D)
		move_player(game, game->map.player.x,
			game->map.player.y + 1, game->player_right);
	else if (key == ESC || key == KEY_Q || key == 17)
		close_game(game);
	return (0);
}

void	victory(t_game *game)
{
	ft_printf("You won in %d moves !", game->movements);
	// free(game->movements);
	close_game(game);
}

void	show_movements(t_game *game)
{
	int	i;

	i = 2;
	// int color = 0x00FF0000;
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 838980, "test");
}

void	move_player(t_game *game, int x, int y, t_image new_player)
{
	int	prev_x;
	int	prev_y;

	prev_x = game->map.player.x;
	prev_y = game->map.player.y;
	game->player = new_player;
	if (game->map.full_map[x][y] == 'E' && game->map.item == 0)
		victory(game);
	else if (game->map.full_map[x][y] == 'X')
	{
		ft_printf("You fell in the water ! Gloup gloup !");
		close_game(game);
	}
	else if ((game->map.full_map[x][y] == '0' 
		|| game->map.full_map[x][y] == 'C'))
	{
		game->map.full_map[prev_x][prev_y] = '0';
		if (game->map.full_map[x][y] == 'C')
		{
			game->map.item--;
			game->map.full_map[x][y] = 'U';
		}
	game->map.player.x = x;
	game->map.player.y = y;
	if (game->map.full_map[x][y] != 'U')
		game->map.full_map[x][y] = 'P';
	game->movements++;
	ft_printf("So far, you did %d moves ! Keep it going !\n", game->movements);
	// show_movements(game);
	ft_render_images(game);

	}
}
