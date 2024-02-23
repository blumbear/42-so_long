/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:05:50 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/23 16:41:33 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "libamoa.h"

//-------------------
# define UP 10
# define DOWN 12
# define LEFT 13
# define RIGHT 11
//-------------------

/**
 * @brief This structure contain every player's images
 * 
 */
typedef struct player_image
{
	mlx_image_t	*down;
	mlx_image_t	*up;
	mlx_image_t	*left;
	mlx_image_t	*right;
}	t_player_image;

/**
 * @brief This stucture contain every wall's images
 * 
 */
typedef struct wall_image
{
	mlx_image_t	*reduced_full;
	mlx_image_t	*full;
	mlx_image_t	*top;
}	t_wall_image;

typedef struct llcollectible
{
	struct llcollectible	*next;
	int						x;
	int						y;
	bool					enable;
	size_t					instance;
}	t_llcollectible;

/**
 * @brief An structure who contain every environments variable
 * 
 */
typedef struct env
{
	mlx_t			*mlx;
	char			**map;
	int				map_height;
	int				map_width;
	bool			player;
	int				player_pos_x;
	int				player_pos_y;
	int				player_dir;
	t_player_image	player_image;
	int				player_movement;
	bool			exit;
	int				exit_pos_x;
	int				exit_pos_y;
	mlx_image_t		*exit_image;
	int				collectible;
	int				collectible_obtained;
	mlx_image_t		*collectible_image;
	t_wall_image	wall_image;
	mlx_image_t		*floor_image;
}	t_env;

typedef struct texture
{
	mlx_texture_t		*a;
	mlx_texture_t		*b;
	mlx_texture_t		*c;
	mlx_texture_t		*d;
}	t_texture;

typedef struct coord
{
	int	x;
	int	y;
	int	z;
}	t_coord;

/******************************************************************************/
/*                                                                            */
/* Init                                                                       */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function initializes the player's variable in env
 * 
 * @param env The variable t_env
 * @param pos_x The position X of the player
 * @param pos_y The position Y of the player
 */
void	ft_init_player(t_env *env, int pos_x, int pos_y);

/**
 * @brief This function initializes the exit's variable in env
 * 
 * @param env The variable t_env
 * @param pos_x The position X of the exit
 * @param pos_y The position Y of the exit
 */
void	ft_init_exit(t_env *env, int pos_x, int pos_y);

/**
 * @brief This function initializes the ground, collectible and exit images
 * in env and call the other function init_wall_image and init_player_image
 * 
 * @param mlx The variable mlx_t
 * @param env The variable t_env
 */
void	init_image(mlx_t *mlx, t_env *env);

/**
 * @brief This function initializes the wall images in env
 * 
 * @param mlx The variable mlx_t
 * @param env The variable t_env
 */
void	init_wall_image(mlx_t *mlx, t_env *env);

/**
 * @brief This function initializes player images in env
 * 
 * @param mlx The variable mlx_t
 * @param env The variable t_env
 */
void	init_player_image(mlx_t *mlx, t_env *env);

/******************************************************************************/
/*                                                                            */
/* Interaction                                                                */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function check if the player have collectible in the direction
 * where he go
 * 
 * @param env The variable t_env
 * @param pos_x The position X of the player
 * @param pos_y The position Y of the player
 */
void	collectible_test(t_env *env, int pos_x, int pos_y);

/**
 * @brief This function check if the exit have collectible in the direction
 * where he go
 * 
 * @param env The variable t_env
 * @param pos_x The position X of the exit
 * @param pos_y The position Y of the exit
 */
void	exit_test(t_env *env, int pos_x, int pos_y);

/******************************************************************************/
/*                                                                            */
/* Load_map                                                                   */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function print the map's image in the game's window
 * 
 * @param mlx The variable mlx_t
 * @param coord The variable who contain the coord x, y and z of the image
 * @param image The image who will be print
 */
void	load_image(mlx_t	*mlx, t_coord	coord, mlx_image_t *image);

/**
 * @brief This fuction initializes the variable t_coord for the function
 * load_image
 * 
 * @param y The position Y of the image
 * @param x The position X of the image
 * @param env The variable t_env
 */
void	pre_load_image(int i, int j, t_env	env);

/**
 * @brief This function print the wall's images in the game's window
 * 
 * @param x The position X of the image
 * @param y The position Y of the image
 * @param env The variable t_env
 */
void	load_wall(int x, int y, t_env	*env);

/**
 * @brief This function read the map and call pre_load_image or load_wall
 * for print the map in game's window.
 * 
 * @param env The variable t_env
 * @param map The map in char **
 */
void	load_map(t_env	*env, char	**map);

/******************************************************************************/
/*                                                                            */
/* Map_test_bis                                                               */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function check if the map are surrounded by wall
 * 
 * @param map The map in char **
 * @param env The variable t_env
 */
void	map_surrounded(char **map, t_env *env);

/**
 * @brief This function will call every other function to test if the
 * map is valid
 * 
 * @param map The map in char **
 * @param env The variable t_env
 */
void	map_is_verified(char **map, t_env *env);

/**
 * @brief This function will check if the map have the good format.
 * Here it's an ".ber"
 * 
 * @param path The path to find the map
 * @param env The variable t_env
 */
void	check_path_name(char	*path, t_env	*env);

/******************************************************************************/
/*                                                                            */
/* Map_test                                                                   */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function check if the map have an player, an exit and
 * enough collectible
 * 
 * @param env The variable t_env
 */
void	post_process_test(t_env *env);

/**
 * @brief This function check the map's chunk and
 * 
 * @param c The chunk
 * @param env The variable t_env
 * @param y The position Y of the image
 * @param x The position X of the image
 * @return int Whether or not the chunck are valid
 */
int		chunck_test(char c, t_env	*env, int i, int j);

/**
 * @brief This function sets the entire character of the map to negative
 * 
 * @param map The map in char **
 * @param y The position Y of the image
 * @param x The position X of the image
 */
void	map_pathway(char	**map, int y, int x);

/**
 * @brief This function will check if the map is résiliable or not
 * 
 * @param map the map in char **
 * @param env The variable t_env
 */
void	post_pathway(char	**map, t_env *env);

/******************************************************************************/
/*                                                                            */
/* Move                                                                       */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function check if the player con go upward
 * 
 * @param env The variable t_env
 */
void	up(t_env	*env);

/**
 * @brief This function check if the player con go downward
 * 
 * @param env The variable t_env
 */
void	down(t_env	*env);

/**
 * @brief This function check if the player con go leftward
 * 
 * @param env The variable t_env
 */
void	left(t_env	*env);

/**
 * @brief This function check if the player con go rightward
 * 
 * @param env The variable t_env
 */
void	right(t_env	*env);

/**
 * @brief This function redirect to the function up, down, right,
 * left, and print data
 * 
 * @param keydata The key who are press
 * @param param The variable t_env
 */
void	keyhook(mlx_key_data_t keydata, void *param);

/******************************************************************************/
/*                                                                            */
/* Parsing                                                                    */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function check if the line does not contain any wrong character
 * 
 * @param line The line
 * @param width The size of the line
 * @return int Whether the line is valid or not
 */
int		line_check(char	*line, size_t width);

/**
 * @brief This function check if the map have dimension upper than 2x2 and
 * whether the map are rectangle or not
 * 
 * @param env The variable t_env
 * @param fd The file descriptor
 */
void	pre_parse(t_env *env, int fd);

/**
 * @brief This function put the map in the structure t_env
 * 
 * @param fd The filedescriptor
 * @param env The variable t_env
 * @return char** The map in the structure
 */
char	**parse(char *fd, t_env *env);

/******************************************************************************/
/*                                                                            */
/* Utils                                                                      */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function stop the programme and free every variable who need to
 * be free
 * 
 * @param error The error to print
 * @param env The variable t_env
 * @param print_error An bool whether print error or not
 */
void	stop_prog(char	*error, t_env	*env, bool print_error, char *to_free);

/**
 * @brief This function print The map and his this in the terminal
 * 
 * @param env The variable t_env
 */
void	print_data(t_env env);

/**
 * @brief This function print the position of the player and the number
 * of collectible he obtain
 * 
 * @param env The variable t_env
 */
void	print_on_move(t_env *env);

void	ft_del_texture(t_texture *texture, int	n);
#endif
