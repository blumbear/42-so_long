/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:26:23 by ttaquet           #+#    #+#             */
/*   Updated: 2024/03/09 15:07:05 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_env *env, char axis, int move)
{
	if (axis == 'y')
	{
		env->player_image.down->instances[0].y += move;
		env->player_image.left->instances[0].y += move;
		env->player_image.right->instances[0].y += move;
		env->player_image.up->instances[0].y += move;
	}
	else if (axis == 'x')
	{
		env->player_image.down->instances[0].x += move;
		env->player_image.left->instances[0].x += move;
		env->player_image.right->instances[0].x += move;
		env->player_image.up->instances[0].x += move;
	}
}

void	up(t_env	*env)
{
	ft_collectible_test(env, env->player_coord.x, env->player_coord.y - 1);
	update_dir(env->player_dir, UP, env);
	env->player_dir = UP;
	if (env->map[env->player_coord.y - 1][env->player_coord.x] != '1')
	{
		env->map[env->player_coord.y][env->player_coord.x]
			= env->player_pos_chunck;
		env->player_pos_chunck
			= env->map[env->player_coord.y - 1][env->player_coord.x];
		env->map[env->player_coord.y - 1][env->player_coord.x] = 'P';
		move_player(env, 'y', -32);
		env->player_coord.y -= 1;
		env->player_movement += 1;
	}
	ft_player_on_trap(env, env->player_coord.x, env->player_coord.y);
	ft_exit_test(env, env->player_coord.x, env->player_coord.y);
	print_on_move(env);
}

void	down(t_env	*env)
{
	ft_collectible_test(env, env->player_coord.x, env->player_coord.y + 1);
	update_dir(env->player_dir, DOWN, env);
	env->player_dir = DOWN;
	if (env->map[env->player_coord.y + 1][env->player_coord.x] != '1')
	{
		env->map[env->player_coord.y][env->player_coord.x]
			= env->player_pos_chunck;
		env->player_pos_chunck
			= env->map[env->player_coord.y + 1][env->player_coord.x];
		env->map[env->player_coord.y + 1][env->player_coord.x] = 'P';
		move_player(env, 'y', +32);
		env->player_coord.y += 1;
		env->player_movement += 1;
	}
	ft_player_on_trap(env, env->player_coord.x, env->player_coord.y);
	ft_exit_test(env, env->player_coord.x, env->player_coord.y);
	print_on_move(env);
}

void	left(t_env	*env)
{
	ft_collectible_test(env, env->player_coord.x - 1, env->player_coord.y);
	update_dir(env->player_dir, LEFT, env);
	env->player_dir = LEFT;
	if (env->map[env->player_coord.y][env->player_coord.x - 1] != '1')
	{
		env->map[env->player_coord.y][env->player_coord.x]
			= env->player_pos_chunck;
		env->player_pos_chunck
			= env->map[env->player_coord.y][env->player_coord.x - 1];
		env->map[env->player_coord.y][env->player_coord.x - 1] = 'P';
		move_player(env, 'x', -32);
		env->player_coord.x -= 1;
		env->player_movement += 1;
	}
	ft_player_on_trap(env, env->player_coord.x, env->player_coord.y);
	ft_exit_test(env, env->player_coord.x, env->player_coord.y);
	print_on_move(env);
}

void	right(t_env	*env)
{
	ft_collectible_test(env, env->player_coord.x + 1, env->player_coord.y);
	update_dir(env->player_dir, RIGHT, env);
	env->player_dir = RIGHT;
	if (env->map[env->player_coord.y][env->player_coord.x + 1] != '1')
	{
		env->map[env->player_coord.y][env->player_coord.x]
			= env->player_pos_chunck;
		env->player_pos_chunck
			= env->map[env->player_coord.y][env->player_coord.x + 1];
		env->map[env->player_coord.y][env->player_coord.x + 1] = 'P';
		move_player(env, 'x', +32);
		env->player_coord.x += 1;
		env->player_movement += 1;
	}
	ft_player_on_trap(env, env->player_coord.x, env->player_coord.y);
	ft_exit_test(env, env->player_coord.x, env->player_coord.y);
	print_on_move(env);
}
