/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:26:23 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/19 16:53:50 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(env_t	*env)
{
	collectible_test(env, env->player_pos_x, env->player_pos_y - 1);
	if (env->map[env->player_pos_y - 1][env->player_pos_x] != '1')
	{
		env->map[env->player_pos_y - 1][env->player_pos_x] = 'P';
		if (env->player_pos_y != env->exit_pos_y || env->player_pos_x != env->exit_pos_x)
			env->map[env->player_pos_y][env->player_pos_x] = '0';
		else
			env->map[env->player_pos_y][env->player_pos_x] = 'E';
		env->player_image.down->instances[0].y -= 32;
		env->player_pos_y -= 1;
		ft_printf("y -> %d | x -> %d | ",env->player_pos_y, env->player_pos_x);
		ft_printf("collectible obtained -> %d\n",env->collectible_obtained);
	}
}

void	down(env_t	*env)
{
	collectible_test(env, env->player_pos_x, env->player_pos_y + 1);
	if (env->map[env->player_pos_y + 1][env->player_pos_x] != '1')
	{
		env->map[env->player_pos_y + 1][env->player_pos_x] = 'P';
		env->map[env->player_pos_y][env->player_pos_x] = 'E';
		if (env->player_pos_y + 1 != env->exit_pos_y || env->player_pos_x != env->exit_pos_x)
			env->map[env->player_pos_y][env->player_pos_x] = '0';
		env->player_image.down->instances[0].y += 32;
		env->player_pos_y += 1;
		ft_printf("y -> %d | x -> %d | ",env->player_pos_y, env->player_pos_x);
		ft_printf("collectible obtained -> %d\n",env->collectible_obtained);
	}
}

void	left(env_t	*env)
{
	collectible_test(env, env->player_pos_x - 1, env->player_pos_y);
	if (env->map[env->player_pos_y][env->player_pos_x - 1] != '1')
	{
		env->map[env->player_pos_y][env->player_pos_x - 1] = 'P';
		env->map[env->player_pos_y][env->player_pos_x] = '0';
		if (env->player_pos_y == env->exit_pos_y && env->player_pos_x == env->exit_pos_x)
			env->map[env->player_pos_y][env->player_pos_x - 1] = 'E';
		env->player_image.down->instances[0].x -= 32;
		env->player_pos_x -= 1;
		ft_printf("y -> %d | x -> %d | ",env->player_pos_y, env->player_pos_x);
		ft_printf("collectible obtained -> %d\n",env->collectible_obtained);
	}
}

void	right(env_t	*env)
{

	collectible_test(env, env->player_pos_x + 1, env->player_pos_y);
	if (env->map[env->player_pos_y][env->player_pos_x + 1] != '1')
	{
		env->map[env->player_pos_y][env->player_pos_x + 1] = 'P';
		env->map[env->player_pos_y][env->player_pos_x] = '0';
		if (env->player_pos_y == env->exit_pos_y && env->player_pos_x == env->exit_pos_x)
			env->map[env->player_pos_y][env->player_pos_x + 1] = 'E';
		env->player_image.down->instances[0].x += 32;
		env->player_pos_x += 1;
		ft_printf("y -> %d | x -> %d | ",env->player_pos_y, env->player_pos_x);
		ft_printf("collectible obtained -> %d\n",env->collectible_obtained);
	}
}