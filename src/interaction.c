/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:48:25 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/19 16:54:16 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectible_test(env_t *env, int pos_x, int pos_y)
{
	if (env->map[pos_y][pos_x] == 'C')
	{
		env->collectible_obtained += 1;
		env->map[pos_y][pos_x] = '0';
		load_image(env->mlx, pos_x, pos_y, 2, env->floor_image);
	}
}
