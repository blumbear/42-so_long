/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:26:23 by ttaquet           #+#    #+#             */
/*   Updated: 2024/03/07 17:07:21 by ttaquet          ###   ########.fr       */
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
	collectible_test(env, env->player_coord.x, env->player_coord.y - 1);
	update_dir(env->player_dir, UP, env);
	env->player_dir = UP;
	if (env->map[env->player_coord.y - 1][env->player_coord.x] != '1')
	{
		env->map[env->player_coord.y - 1][env->player_coord.x] = 'P';
		env->map[env->player_coord.y][env->player_coord.x] = '0';
		if (env->player_coord.y + 1 == env->exit_coord.y
			&& env->player_coord.x == env->exit_coord.x)
			env->map[env->player_coord.y][env->player_coord.x] = 'E';
		move_player(env, 'y', -32);
		env->player_coord.y -= 1;
		env->player_movement += 1;
		print_on_move(env);
	}
	exit_test(env, env->player_coord.x, env->player_coord.y);
}

void	down(t_env	*env)
{
	collectible_test(env, env->player_coord.x, env->player_coord.y + 1);
	update_dir(env->player_dir, DOWN, env);
	env->player_dir = DOWN;
	if (env->map[env->player_coord.y + 1][env->player_coord.x] != '1')
	{
		env->map[env->player_coord.y + 1][env->player_coord.x] = 'P';
		env->map[env->player_coord.y][env->player_coord.x] = '0';
		if (env->player_coord.y + 1 == env->exit_coord.y
			&& env->player_coord.x == env->exit_coord.x)
			env->map[env->player_coord.y][env->player_coord.x] = 'E';
		move_player(env, 'y', +32);
		env->player_coord.y += 1;
		env->player_movement += 1;
		print_on_move(env);
	}
	exit_test(env, env->player_coord.x, env->player_coord.y);
}

void	left(t_env	*env)
{
	collectible_test(env, env->player_coord.x - 1, env->player_coord.y);
	update_dir(env->player_dir, LEFT, env);
	env->player_dir = LEFT;
	if (env->map[env->player_coord.y][env->player_coord.x - 1] != '1')
	{
		env->map[env->player_coord.y][env->player_coord.x - 1] = 'P';
		env->map[env->player_coord.y][env->player_coord.x] = '0';
		if (env->player_coord.y == env->exit_coord.y
			&& env->player_coord.x == env->exit_coord.x)
			env->map[env->player_coord.y][env->player_coord.x - 1] = 'E';
		move_player(env, 'x', -32);
		env->player_coord.x -= 1;
		env->player_movement += 1;
		print_on_move(env);
	}
	exit_test(env, env->player_coord.x, env->player_coord.y);
}

void	right(t_env	*env)
{
	collectible_test(env, env->player_coord.x + 1, env->player_coord.y);
	update_dir(env->player_dir, RIGHT, env);
	env->player_dir = RIGHT;
	if (env->map[env->player_coord.y][env->player_coord.x + 1] != '1')
	{
		env->map[env->player_coord.y][env->player_coord.x + 1] = 'P';
		env->map[env->player_coord.y][env->player_coord.x] = '0';
		if (env->player_coord.y == env->exit_coord.y
			&& env->player_coord.x == env->exit_coord.x)
			env->map[env->player_coord.y][env->player_coord.x] = 'E';
		move_player(env, 'x', +32);
		env->player_coord.x += 1;
		env->player_movement += 1;
		print_on_move(env);
	}
	exit_test(env, env->player_coord.x, env->player_coord.y);
}
