/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:26:23 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/21 17:17:18 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_env	*env)
{
	collectible_test(env, env->player_pos_x, env->player_pos_y - 1);
	if (env->map[env->player_pos_y - 1][env->player_pos_x] != '1')
	{
		env->map[env->player_pos_y - 1][env->player_pos_x] = 'P';
		if (env->player_pos_y != env->exit_pos_y
			|| env->player_pos_x != env->exit_pos_x)
			env->map[env->player_pos_y][env->player_pos_x] = '0';
		else
			env->map[env->player_pos_y][env->player_pos_x] = 'E';
		env->player_image.down->instances[0].y -= 32;
		env->player_pos_y -= 1;
		print_on_move(env);
	}
	exit_test(env, env->player_pos_x, env->player_pos_y);
}

void	down(t_env	*env)
{
	collectible_test(env, env->player_pos_x, env->player_pos_y + 1);
	if (env->map[env->player_pos_y + 1][env->player_pos_x] != '1')
	{
		env->map[env->player_pos_y + 1][env->player_pos_x] = 'P';
		env->map[env->player_pos_y][env->player_pos_x] = 'E';
		if (env->player_pos_y + 1 != env->exit_pos_y
			|| env->player_pos_x != env->exit_pos_x)
			env->map[env->player_pos_y][env->player_pos_x] = '0';
		env->player_image.down->instances[0].y += 32;
		env->player_pos_y += 1;
		print_on_move(env);
	}
	exit_test(env, env->player_pos_x, env->player_pos_y);
}

void	left(t_env	*env)
{
	collectible_test(env, env->player_pos_x - 1, env->player_pos_y);
	if (env->map[env->player_pos_y][env->player_pos_x - 1] != '1')
	{
		env->map[env->player_pos_y][env->player_pos_x - 1] = 'P';
		env->map[env->player_pos_y][env->player_pos_x] = '0';
		if (env->player_pos_y != env->exit_pos_y
			|| env->player_pos_x != env->exit_pos_x)
			env->map[env->player_pos_y][env->player_pos_x - 1] = 'E';
		env->player_image.down->instances[0].x -= 32;
		env->player_pos_x -= 1;
		print_on_move(env);
	}
	exit_test(env, env->player_pos_x, env->player_pos_y);
}

void	right(t_env	*env)
{
	collectible_test(env, env->player_pos_x + 1, env->player_pos_y);
	if (env->map[env->player_pos_y][env->player_pos_x + 1] != '1')
	{
		env->map[env->player_pos_y][env->player_pos_x + 1] = 'P';
		env->map[env->player_pos_y][env->player_pos_x] = '0';
		if (env->player_pos_y != env->exit_pos_y
			|| env->player_pos_x != env->exit_pos_x)
			env->map[env->player_pos_y][env->player_pos_x + 1] = 'E';
		env->player_image.down->instances[0].x += 32;
		env->player_pos_x += 1;
		print_on_move(env);
	}
	exit_test(env, env->player_pos_x, env->player_pos_y);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_env	*env;

	env = (t_env *)param;
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
