/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:16:26 by edrouot           #+#    #+#             */
/*   Updated: 2023/05/10 14:02:02 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <string.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "Printf/ft_printf.h"

# define true   1
# define false  0

# define IMG_HEIGHT			50
# define IMG_WIDTH			50

# define WALL '1'
# define FLOOR '0'
# define ITEM 'C'
# define PLAYER 'P'
# define EXIT 'E'

# define UP     65362
# define DOWN   65364
# define LEFT   65361
# define RIGHT  65363
# define KEY_W   122
# define KEY_S   115
# define KEY_A   113
# define KEY_D   100
# define ESC     65307
# define KEY_Q   97


# define WALL_IMG "assets/bush.xpm"
# define FLOOR_IMG "assets/grass.xpm"
# define ITEM_IMG "assets/acorn.xpm"
# define PLAYER_F_IMG "assets/front.xpm"
# define PLAYER_R_IMG "assets/right.xpm"
# define PLAYER_B_IMG "assets/back.xpm"
# define PLAYER_L_IMG "assets/left.xpm"
# define EXIT_OPEN_IMG "assets/exit_open.xpm"
# define EXIT_CLOSE_IMG "assets/exit_close.xpm"
# define OBSTACLES_IMG "assets/obstacles.xpm"

typedef struct s_bool
{
    int value;
} t_bool;


typedef struct s_image
{
    void *xpm_ptr;
    int x;
    int y; 
} t_image;

typedef struct s_player
{
    int x;
    int y;    
} t_player;

typedef struct s_map
{
    char **full_map;
    int rows;
    int columns;
    int movements;
    int item;
    int exit;
    int entrance;
    t_player player;
    int allocate_map;
} t_map;


typedef struct t_game
{
    void *mlx_ptr;
    void *win_ptr;
    int movements;
    t_map map;
    t_image player;
    t_image wall;
    t_image floor;
    t_image item;
    t_image door;
    t_image exit_open;
    t_image exit_close;
    t_image player_front;
    t_image player_back;
    t_image player_right;
    t_image player_left;
    t_image obstacles;
    int allocate_img;
} t_game;


int     check_first_and_last_lines(char *line);
int	check_other_lines(t_game *game, char *line);
int check_map(t_game *game);
char **get_map(int fd);
void	free_map(t_game *game);
int check_length_lines(t_game *game);


int		searchn(char *tmp);
char	*memcpyb(char *dest, char *src, size_t n);
size_t	ft_strlen(const char *s);
char	*join_buffer_tmp(char *buffer, char *tmp);
char	*memmovegnl(char *dest, char *src, size_t n);
char	*splitmp(char *tmp);
char	*readtmp(int fd, char *tmp);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);


void    ft_initialize_game(t_game *game);
void ft_initialize_images(t_game *game);
t_image ft_new_image(void *mlx_ptr, char *path, t_game *game);
void    ft_error(t_game *game, char *string);
void    ft_initialize_mlx(t_game *game);
void    ft_initialize_variables(t_game *game);



void ft_render_images(t_game *game);
void move_player (t_game *game, int x, int y, t_image new_player);
int    input_keyboard (int key, t_game *game);

void victory(t_game *game);
void	free_all(t_game *game);

// t_bool is_valid_path(int start_i, int start_j, int end_i, int end_j, t_bool visited[ROWS][COLS]);
// int     test_map(t_game *game);

#endif