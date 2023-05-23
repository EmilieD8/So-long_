/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:42:21 by edrouot           #+#    #+#             */
/*   Updated: 2023/05/23 12:55:58 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_length_lines(t_game *game)
{
	int	j;

	j = 0;

	game->map.columns = (int)ft_strlen(game->map.full_map[0]);
	while (game->map.full_map[j] != (void *) '\0')
	{
		if ((int)ft_strlen(game->map.full_map[j]) != game->map.columns)
			return (0);
		else
			j++;
	}
	if (game->map.columns == j)
		return (0);
	else
		game->map.rows = j;
	return (1);
}

int	check_first_and_last_lines(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '1' || line[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_other_lines(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[0] != '1')
			return (0);
		if (line[i] == 'P')
        {
            game->map.entrance++;
            game->map.player.x = i;
        }
		if (line[i] == 'E')
			game->map.exit++;
		if (line[i] == 'C')
			game->map.item++;
		i++;
	}
	if (line[i - 1] != '1')
		return (0);
	return (1);
}

char	**get_map(char *argv, t_game *game)
{
	char	*final_line;
	char	*line;
	char	**map;
	int		fd;
	int		j;

	j = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error(game, "Incorrect file name, cannot be open !");
	final_line = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		final_line = ft_strjoin(final_line, line);
		line = get_next_line(fd);
	}
	free(line);
	map = ft_split(final_line, '\n');
	// map = strtok(final_line, "\n");

	free(final_line);
	close(fd);
	return (map);
}

int	check_map(t_game *game)
{
	int	j;

	j = 0;
	if (check_length_lines(game) == 0)
		return (0);
	if (check_first_and_last_lines(game->map.full_map[0]) == 0)
		return (0);
	while (game->map.full_map[j] != (void *) '\0')
	{
		if (check_other_lines(game, game->map.full_map[j]) == 0)
			return (0);
        else if (game->map.player.y == 0 && game->map.entrance == 1)
        {
            game->map.player.y = j;
            j++;
        }
		else
			j++;
	}
	if (game->map.exit != 1 || game->map.entrance != 1 || game->map.item == 0
		|| check_first_and_last_lines(game->map.full_map[j - 1]) == 0)
		return (0);
	game->map.allocate_map = 1;
    flood_fill(game);
	return (1);
}
