/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:56:19 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/28 14:41:03 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_dir(int old_dir, int new_dir, t_env *env)
{
	if (old_dir == UP && old_dir != new_dir)
		mlx_set_instance_depth(&env->player_image.up->instances
		[env->player_image.up->count - 1], 0);
	else if (old_dir == LEFT && old_dir != new_dir)
		mlx_set_instance_depth(&env->player_image.left->instances
		[env->player_image.left->count - 1], 0);
	else if (old_dir == RIGHT && old_dir != new_dir)
		mlx_set_instance_depth(&env->player_image.right->instances
		[env->player_image.right->count - 1], 0);
	else if (old_dir == DOWN && old_dir != new_dir)
		mlx_set_instance_depth(&env->player_image.down->instances
		[env->player_image.down->count - 1], 0);
	if (new_dir == UP && old_dir != new_dir)
		mlx_set_instance_depth(&env->player_image.up->instances
		[env->player_image.up->count - 1], PLAYER_DEPTH);
	else if (new_dir == LEFT && old_dir != new_dir)
		mlx_set_instance_depth(&env->player_image.left->instances
		[env->player_image.left->count - 1], PLAYER_DEPTH);
	else if (new_dir == RIGHT && old_dir != new_dir)
		mlx_set_instance_depth(&env->player_image.right->instances
		[env->player_image.right->count - 1], PLAYER_DEPTH);
	else if (new_dir == DOWN && old_dir != new_dir)
		mlx_set_instance_depth(&env->player_image.down->instances
		[env->player_image.up->count - 1], PLAYER_DEPTH);
}

void	ft_del_texture(t_texture *texture, int n)
{
	if (n > 0)
		mlx_delete_texture(texture->a);
	if (n > 1)
		mlx_delete_texture(texture->b);
	if (n > 2)
		mlx_delete_texture(texture->c);
	if (n > 3)
		mlx_delete_texture(texture->d);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		stop_prog("\0", env, false, NULL);
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
