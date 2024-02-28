/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:26:23 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/28 16:01:38 by ttaquet          ###   ########.fr       */
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
	collectible_test(env, env->player_pos_x, env->player_pos_y - 1);
	if (env->map[env->player_pos_y - 1][env->player_pos_x] != '1')
	{
		env->map[env->player_pos_y - 1][env->player_pos_x] = 'P';
		env->map[env->player_pos_y][env->player_pos_x] = '0';
		if (env->player_pos_y + 1 == env->exit_pos_y
			&& env->player_pos_x == env->exit_pos_x)
			env->map[env->player_pos_y][env->player_pos_x] = 'E';
		update_dir(env->player_dir, UP, env);
		move_player(env, 'y', -32);
		env->player_dir = UP;
		env->player_pos_y -= 1;
		env->player_movement += 1;
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
		env->map[env->player_pos_y][env->player_pos_x] = '0';
		if (env->player_pos_y + 1 == env->exit_pos_y
			&& env->player_pos_x == env->exit_pos_x)
			env->map[env->player_pos_y][env->player_pos_x] = 'E';
		update_dir(env->player_dir, DOWN, env);
		move_player(env, 'y', +32);
		env->player_dir = DOWN;
		env->player_pos_y += 1;
		env->player_movement += 1;
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
		if (env->player_pos_y == env->exit_pos_y
			&& env->player_pos_x == env->exit_pos_x)
			env->map[env->player_pos_y][env->player_pos_x - 1] = 'E';
		update_dir(env->player_dir, LEFT, env);
		move_player(env, 'x', -32);
		env->player_dir = LEFT;
		env->player_pos_x -= 1;
		env->player_movement += 1;
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
		if (env->player_pos_y == env->exit_pos_y
			&& env->player_pos_x == env->exit_pos_x)
			env->map[env->player_pos_y][env->player_pos_x] = 'E';
		update_dir(env->player_dir, RIGHT, env);
		move_player(env, 'x', +32);
		env->player_dir = RIGHT;
		env->player_pos_x += 1;
		env->player_movement += 1;
		print_on_move(env);
	}
	exit_test(env, env->player_pos_x, env->player_pos_y);
}
