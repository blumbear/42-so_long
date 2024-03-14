/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:56:19 by ttaquet           #+#    #+#             */
/*   Updated: 2024/03/10 15:05:13 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_dir(t_direction old_dir, t_direction new_dir, t_env *env)
{
	if (old_dir == UP && old_dir != new_dir)
		env->player_image.up->instances->enabled = false;
	else if (old_dir == LEFT && old_dir != new_dir)
		env->player_image.left->instances->enabled = false;
	else if (old_dir == RIGHT && old_dir != new_dir)
		env->player_image.right->instances->enabled = false;
	else if (old_dir == DOWN && old_dir != new_dir)
		env->player_image.down->instances->enabled = false;
	if (new_dir == UP && old_dir != new_dir)
		env->player_image.up->instances->enabled = true;
	else if (new_dir == LEFT && old_dir != new_dir)
		env->player_image.left->instances->enabled = true;
	else if (new_dir == RIGHT && old_dir != new_dir)
		env->player_image.right->instances->enabled = true;
	else if (new_dir == DOWN && old_dir != new_dir)
		env->player_image.down->instances->enabled = true;
}

void	del_texture(t_texture *texture, int n)
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

	(void)keydata;
	env = (t_env *)param;
	if (mlx_is_key_down(env->mlx, MLX_KEY_ESCAPE))
		stop_prog("\0", env);
	if (env->key_enaled)
	{
		if (mlx_is_key_down(env->mlx, MLX_KEY_W)
			|| mlx_is_key_down(env->mlx, MLX_KEY_UP))
			up(env);
		if (mlx_is_key_down(env->mlx, MLX_KEY_S)
			|| mlx_is_key_down(env->mlx, MLX_KEY_DOWN))
			down(env);
		if (mlx_is_key_down(env->mlx, MLX_KEY_A)
			|| mlx_is_key_down(env->mlx, MLX_KEY_LEFT))
			left(env);
		if (mlx_is_key_down(env->mlx, MLX_KEY_D)
			|| mlx_is_key_down(env->mlx, MLX_KEY_RIGHT))
			right(env);
		if (mlx_is_key_down(env->mlx, MLX_KEY_P))
			print_data(*env);
	}
}

void	check_path_name(char	*path, t_env	*env)
{
	if (ft_strncmp(path + (ft_strlen(path) - 4), ".ber", 4) != 0)
		stop_prog("The map must be in the format '.ber'.", env);
}

void	init_player(t_env *env, int pos_x, int pos_y)
{
	env->player_coord.x = pos_x;
	env->player_coord.y = pos_y;
	env->player_hp = 3;
	env->key_enaled = true;
	env->player_pos_chunck = '0';
}
