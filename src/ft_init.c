/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:20:43 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/05 14:37:16 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_player(env_t **env, int pos_x, int pos_y)
{
	(*env)->player = true;
	(*env)->player_pos_x = pos_x;
	(*env)->player_pos_y = pos_y;
}

void	ft_init_exit(env_t **env, int pos_x, int pos_y)
{
	(*env)->exit = true;
	(*env)->exit_pos_x = pos_x;
	(*env)->exit_pos_y = pos_y;
}
void	ft_init_env(mlx_t mlx, env_t **env)
{
	(*env)->player = false;
	(*env)->player_pos_x = 0;
	(*env)->player_pos_y = 0;
	(*env)->player_dir = RIGHT;
	(*env)->exit = false;
	(*env)->exit_pos_x = 0;
	(*env)->exit_pos_y = 0;
	(*env)->collectible = 0;
	init_texture(mlx, env);

}

void	init_texture(mlx_t mlx, env_t **env)
{
	
	(*env)->t_player = mlx_load_png("texture/");
	(*env)->t_floor = mlx_load_png("texture/");
	(*env)->t_wall = mlx_load_png("texture/");
}
