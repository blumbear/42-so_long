/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:05:50 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/20 14:23:54 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "libamoa.h"

# define WIDTH 512
# define HEIGHT 512
//-------------------
# define UP 10
# define RIGHT 11
# define DOWN 12
# define LEFT 13
//-------------------

typedef struct player_image
{
	mlx_image_t	*down;
	mlx_image_t	*up;
	mlx_image_t	*left;
	mlx_image_t	*right;
}	player_image_t;

typedef	struct wall_image
{
	mlx_image_t	*reduced_full;
	mlx_image_t	*full;
	mlx_image_t	*top;
}	wall_image_t;


typedef struct llcollectible
{
	struct llcollectible	*next;
	int						x;
	int						y;
	bool					enable;
	size_t					instance;
}	llcollectible_t;

/**
 * @brief an struct who contain every environment variable
 * 
 */
typedef struct env
{
	mlx_t				*mlx;
	char				**map;
	bool				player;
	int					player_pos_x;
	int					player_pos_y;
	int					player_dir;
	bool				exit;
	int					exit_pos_x;
	int					exit_pos_y;
	int					collectible;
	int					collectible_obtained;
	int					map_height;
	int 				map_width;
	wall_image_t		wall_image;
	mlx_image_t			*floor_image;
	mlx_image_t			*exit_image;
	mlx_image_t			*collectible_image;
	player_image_t		player_image;
	llcollectible_t		*llcollectible;
}	env_t;

typedef	struct texture
{
	mlx_texture_t		*a;
	mlx_texture_t		*b;
	mlx_texture_t		*c;
	mlx_texture_t		*d;
}	texture_t;



/**
 * @brief parse the map and put it in an tab
 * 
 * @param fd the files who contain the map
 * @param env the variable who contain every information of the environment
 * @return char** the tab who contain the char
 */
char	**parse(char *fd, env_t *env);

/**
 * @brief thiss function check if the map are playable
 * 
 * @param map the map who are verified
 * @param env the variable who contain every information of the environment
 * @return int whether or not the map are playable
 */
int		map_is_verified(char **map, env_t *env);

void	stop_prog(char	*error);

void	print_data(env_t env);
void	load_map(mlx_t	*mlx, env_t	*env, char	**map);
void	ft_init_player(env_t *env, int pos_x, int pos_y);
void	ft_init_exit(env_t *env, int pos_x, int pos_y);
void	ft_init_env(env_t *env);
void	init_image(mlx_t *mlx, env_t *env);
void	check_path_name(char	*path);
void	up(env_t	*env);
void	down(env_t	*env);
void	left(env_t	*env);
void	right(env_t	*env);
void	load_image(mlx_t	*mlx, int	i, int	j, int	z, mlx_image_t *image);
void	collectible_test(env_t *env, int pos_x, int pos_y);
void ft_lstadd_back(llcollectible_t *llist, llcollectible_t *new_node);
llcollectible_t	*ft_lstnew(int	x, int	y, env_t	*env);
# endif
