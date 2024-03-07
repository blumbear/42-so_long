/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:48:25 by ttaquet           #+#    #+#             */
/*   Updated: 2024/03/07 16:50:53 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectible_test(t_env *env, int pos_x, int pos_y)
{
	t_coord	tmp;

	if (env->map[pos_y][pos_x] == 'C')
	{
		tmp.x = pos_x;
		tmp.y = pos_y + 1;
		tmp.z = COLLECIBLE_DEPTH + 1;
		env->collectible_obtained += 1;
		env->map[pos_y][pos_x] = '0';
		load_image(env->mlx, tmp, env->floor_image, true);
	}
}

void	exit_test(t_env *env, int pos_x, int pos_y)
{
	if (env->collectible_obtained == env->collectible
		&& pos_x == env->exit_coord.x && pos_y == env->exit_coord.y)
		stop_prog("", env, false, NULL);
}
