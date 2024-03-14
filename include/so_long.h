/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:05:50 by ttaquet           #+#    #+#             */
/*   Updated: 2024/03/14 16:03:29 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "libamoa.h"

/**
 * @brief The different texture's depths
 * 
 */
# define PLAYER_DEPTH 3
# define FLOOR_DEPTH 0
# define COLLECIBLE_DEPTH 1
# define EXIT_DEPTH 1
# define TRAP_DEPTH 1
# define TEXT_DEPTH 1
//-----------------------

/**
 * @brief This enum contains every possible directions of the player
 * 
 */
typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_direction;

/**
 * @brief This structure contains every player's images
 * 
 */
typedef struct s_player_image
{
	mlx_image_t	*down;
	mlx_image_t	*up;
	mlx_image_t	*left;
	mlx_image_t	*right;
}	t_player_image;

/**
 * @brief This stucture contains every walls images
 * 
 */
typedef struct s_wall_image
{
	mlx_image_t	*reduced_full;
	mlx_image_t	*reduced_top;
	mlx_image_t	*full;
	mlx_image_t	*top;
}	t_wall_image;

/**
 * @brief This structure contains the texture temporarily
 * 
 */
typedef struct texture
{
	mlx_texture_t		*a;
	mlx_texture_t		*b;
	mlx_texture_t		*c;
	mlx_texture_t		*d;
}	t_texture;

/**
 * @brief This structure contains the coords to print or to update an image
 * 
 */
typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
}	t_coord;

/**
 * @brief A structure that contains every environment's variables
 * 
 */
typedef struct s_env
{
//-----------------------
	mlx_t			*mlx;
//-----------------------
	bool			key_enaled;
//-----------------------
	char			**map;
	int				map_height;
	int				map_width;
//-----------------------
	int				trap_number;
//-----------------------
	t_coord			player_coord;
	t_direction		player_dir;
	t_player_image	player_image;
	int				player_movement;
	int				player_hp;
	char			player_pos_chunck;
//-----------------------
	bool			exit;
	mlx_image_t		*exit_image;
//-----------------------
	int				collectible;
	int				collectible_obtained;
	mlx_image_t		*collectible_image;
//-----------------------
	mlx_texture_t	*icon_texture;
//-----------------------*
	mlx_image_t		*strmove;
	t_coord			strmove_coord;
//-----------------------
	mlx_image_t		*strpoint;
	t_coord			strpoint_coord;
//-----------------------
	mlx_image_t		*strhp;
	t_coord			strhp_coord;
//-----------------------
	t_wall_image	wall_image;
//-----------------------
	mlx_image_t		*floor_image;
//-----------------------
	mlx_image_t		*trap_image;
//-----------------------
}	t_env;

/******************************************************************************/
/*                                                                            */
/* init_image                                                                 */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function initializes the ground, collectibles and the exit image
 * in env and call the other functions init_wall_image and init_player_image
 * 
 * @param mlx The variable mlx_t
 * @param env The struct t_env
 */
void	init_image(mlx_t *mlx, t_env *env);

/**
 * @brief This function initializes the wall's images in env
 * 
 * @param mlx The variable mlx_t
 * @param env The struct t_env
 */
void	init_wall_image(mlx_t *mlx, t_env *env);

/**
 * @brief This function initializes player's images in env
 * 
 * @param mlx The variable mlx_t
 * @param env The struct t_env
 */
void	init_player_image(mlx_t *mlx, t_env *env);

/******************************************************************************/
/*                                                                            */
/* Interaction                                                                */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function checks if the player has collectibles in the
 * direction he goes
 * 
 * @param env The struct t_env
 */
void	collectible_test(t_env *env);

/**
 * @brief This function checks if the player has all collectibles at the exit
 * 
 * @param env The struct t_env
 */
void	exit_test(t_env *env);

/**
 * @brief This function check whether the player is on a trap or not
 * 
 * @param env The struct t_env
 */
void	player_on_trap(t_env *env);

/******************************************************************************/
/*                                                                            */
/* Load_map                                                                   */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function prints the map's images in the game's window
 * 
 * @param mlx The variable mlx_t
 * @param coord The variable that contains the coord x, y and z of the image
 * @param image The image which will be printed
 */
void	load_image(mlx_t	*mlx, t_coord	coord,
			mlx_image_t *image, bool enabled);

/**
 * @brief This fuction initializes the variable t_coord for the function
 * load_image
 * 
 * @param y The position Y of the image
 * @param x The position X of the image
 * @param env The struct t_env
 */
void	pre_load_image(int i, int j, t_env	*env);

/**
 * @brief This function redirects to load_image in order to load every player's
 * images
 * 
 * @param coord The coord to load the player's images
 * @param env The struct t_env
 */
void	pre_load_player(t_coord coord, t_env *env);

/**
 * @brief This function prints the wall's images in the game's window
 * 
 * @param x The position X of the image
 * @param y The position Y of the image
 * @param env The struct t_env
 */
void	load_wall(int x, int y, t_env	*env);

/**
 * @brief This function reads the map and calls pre_load_image or load_wall
 * in order to print the map in game's window.
 * 
 * @param env The struct t_env
 * @param map The map in char **
 */
void	load_map(t_env	*env, char	**map);

/******************************************************************************/
/*                                                                            */
/* Load_Text                                                                  */
/*                                                                            */
/******************************************************************************/
/**
 * @brief This function loads every images used as text
 * 
 * @param The struct t_env
*/
void	load_text(t_env *env);

void	load_text_bis(t_env *env);

/******************************************************************************/
/*                                                                            */
/* Map_test_bis                                                               */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function sets all characters of the map to negative if it
 * ain't a wall
 * 
 * @param map The map in char **
 * @param y The position Y of the image
 * @param x The position X of the image
 */
void	map_pathway(char	**map, int y, int x);

/**
 * @brief This function will check whether the map is feasible or not
 * and redirects to post_pathway_variable_test
 * 
 * @param map the map in char **
 * @param env The struct t_env
 */
void	post_pathway(char	**map, t_env *env);

/**
 * @brief This function tests if the player can optain all
 * collectibles and reach the exit
 * 
 * @param nb_collectible The number of collectibles found by post_pathway
 * @param env The struct t_env
 */
void	post_pathway_variable_test(int nb_collectible, t_env *env);

/******************************************************************************/
/*                                                                            */
/* Map_test                                                                   */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function will call every other function to test whether the
 * map is valid or not
 * 
 * @param map The map in char **
 * @param env The struct t_env
 */
void	map_is_verified(char **map, t_env *env);

/**
 * @brief This function checks a map's char whether it is valid or not
 * 
 * @param c The char
 * @param env The struct t_env
 * @param y The position Y of the image
 * @param x The position X of the image
 * @return int Whether or not the char is valid
 */
int		chunck_test(char c, t_env	*env, int i, int j);

/**
 * @brief This function checks if the map has a player, an exit and
 * enough collectibles
 * 
 * @param env The struct t_env
 */
void	check_variable(t_env *env);

/**
 * @brief This function checks if the map is surrounded by walls like Mexico
 * 
 * @param map The map in char **
 * @param env The struct t_env
 */
void	map_surrounded(char **map, t_env *env);

/******************************************************************************/
/*                                                                            */
/* Move                                                                       */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function moves every image of the player on the axis X or Y
 * 
 * @param env The struct t_env
 * @param axis The axis 
 * @param move The size of the move, here it's 32 and we just give +32 or -32
 */
void	move_player(t_env *env, char axis, int move);

/**
 * @brief This function checks if the player can go upwards
 * 
 * @param env The struct t_env
 */
void	up(t_env	*env);

/**
 * @brief This function checks if the player can go downwards
 * 
 * @param env The struct t_env
 */
void	down(t_env	*env);

/**
 * @brief This function checks if the player can go left
 * 
 * @param env The struct t_env
 */
void	left(t_env	*env);

/**
 * @brief This function checks if the player can go right
 * 
 * @param env The struct t_env
 */
void	right(t_env	*env);

/******************************************************************************/
/*                                                                            */
/* Parsing                                                                    */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function checks if the line does not contain any wrong characters
 * 
 * @param line The line
 * @param width The size of the line
 * @return int Whether the line is valid or not
 */
int		line_check(char	*line, size_t width);

/**
 * @brief This function will test if the map is valid and calls the function
 * parse
 * 
 * @param env The struct t_env
 * @param map_path The path to find the map
 */
void	parse(t_env *env, char *map_path);

/**
 * @brief This function will read the map recursively and puts it in the struct
 * t_env env.
 * The function parse frees every line of the map if one of them ain't valid
 * 
 * @param depth The depth of the line, it is like the axis Y
 * @param env The struct env_t
 * @param fd The file descriptor
 * @return int whether the map is valid or not
 */
int		read_map(int depth, t_env *env, int fd);

/******************************************************************************/
/*                                                                            */
/* Print_&_Error                                                              */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function stops the program and frees every variable which needs to
 * be freed
 * 
 * @param error The error to print
 * @param env The struct t_env
 * @param print_error An bool whether print error or not
 */
void	stop_prog(char	*error, t_env	*env);

/**
 * @brief This function prints the map and its data in the terminal
 * 
 * @param env The struct t_env
 */
void	print_data(t_env env);

/**
 * @brief This function prints at every movement the player does its position
 * and the number
 * of collectibles he has
 * 
 * @param env The struct t_env
 */
void	print_on_move(t_env *env);

/******************************************************************************/
/*                                                                            */
/* Utils                                                                      */
/*                                                                            */
/******************************************************************************/

/**
 * @brief This function updates the image of the player to update his direction
 * 
 * @param old_dir The old direction
 * @param new_dir The new direction
 * @param env The struct t_env
 */
void	update_dir(t_direction old_dir, t_direction new_dir, t_env *env);

/**
 * @brief this function deletes n textures of the variable t_texture
 * 
 * @param texture The variable t_texture
 * @param n The number of textures to delete
 */
void	del_texture(t_texture *texture, int n);

/**
 * @brief This function redirects to an other function depending on the keydata
 * 
 * @param keydata The keydata
 * @param param The struct t_env in void type
 */
void	keyhook(mlx_key_data_t keydata, void *param);

/**
 * @brief This function will check if the map has the right format.
 * Here it's a ".ber"
 * 
 * @param path The path to find the map
 * @param env The struct t_env
 */
void	check_path_name(char	*path, t_env	*env);

/**
 * @brief This function initializes player's variables
 * 
 * @param env The struct t_env
 * @param pos_x The player's X position
 * @param pos_y The player's Y position
 */
void	init_player(t_env *env, int pos_x, int pos_y);
#endif
