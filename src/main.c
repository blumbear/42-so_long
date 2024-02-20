/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:44:53 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/20 14:18:19 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	env_t	*env;

	env = (env_t *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(env->mlx);
		exit(0);
	}
	else if (mlx_is_key_down(env->mlx, MLX_KEY_W) 
				|| mlx_is_key_down(env->mlx, MLX_KEY_UP))
		up(env);
	else if (mlx_is_key_down(env->mlx, MLX_KEY_S) 
				|| mlx_is_key_down(env->mlx, MLX_KEY_DOWN))
		down(env);
	else if (mlx_is_key_down(env->mlx, MLX_KEY_A) 
				|| mlx_is_key_down(env->mlx, MLX_KEY_LEFT))
		left(env);
	else if (mlx_is_key_down(env->mlx, MLX_KEY_D) 
				|| mlx_is_key_down(env->mlx, MLX_KEY_RIGHT))
		right(env);
	else if (mlx_is_key_down(env->mlx, MLX_KEY_P))
		print_data(*env);
}

int main(int ac, char **av)
{
	env_t	env;

	env.mlx = NULL;
	env.llcollectible = NULL;
	if (ac != 2)
		stop_prog("Not enought arguments.");
	check_path_name(av[1]);
	env.map = NULL;
	ft_init_env(&env);
	env.map = parse(av[1], &env);
	map_is_verified(env.map, &env);
	env.mlx = mlx_init((env.map_width + 1) * 32, (env.map_height + 1) * 32, "OUI", true);
	print_data(env);
	init_image(env.mlx, &env);
	load_map(env.mlx, &env, env.map);
	mlx_key_hook(env.mlx, &keyhook, &env);
	mlx_loop(env.mlx);
	mlx_terminate(env.mlx);
}
