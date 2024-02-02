/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:05:50 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/02 15:25:02 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "../lib/libamoa/include/libamoa.h"
# include <stdlib.h>
# include <stdbool.h>

# define WIDTH 512
# define HEIGHT 512
//-------------------
# define UP 10
# define RIGHT 11
# define DOWN 12
# define LEFT 13
//-------------------

/**
 * @brief an struct who contain every environment variable
 * 
 */
typedef struct env
{
	bool	player;
	int		player_pos_x;
	int		player_pos_y;
	int		player_dir;
	bool	exit;
	int		exit_pos_x;
	int		exit_pos_y;
	int		collectible;
	int		map_height;
	int 	map_width;

}	env_t;


static mlx_image_t* image;

/**
 * @brief parse the map and put it in an tab
 * 
 * @param fd the files who contain the map
 * @param env the variable who contain every information of the environment
 * @return char** the tab who contain the char
 */
char	**parse(char *fd, env_t **env);

/**
 * @brief thiss function check if the map are playable
 * 
 * @param map the map who are verified
 * @param env the variable who contain every information of the environment
 * @return int whether or not the map are playable
 */
int		map_is_verified(char **map, env_t **env);

void	ft_stop_function(char	*error);

void	ft_init_player(env_t **env, int pos_x, int pos_y);
void	ft_init_exit(env_t **env, int pos_x, int pos_y);
void	ft_init_env(env_t	**env);
# endif
