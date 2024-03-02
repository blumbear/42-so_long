/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:02:06 by tom               #+#    #+#             */
/*   Updated: 2024/03/02 15:27:13 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_text(t_env *env)
{
	t_coord coord;

	coord.x = (env->map_width / 6);
	coord.y = (env->map_height + 1);
	coord.z = 25;
	
	env->strmove_coord = coord;
	load_image(env->mlx, coord, mlx_texture_to_image(env->mlx, (mlx_load_png("texture/move.png"))) , true);
	env->strmove = mlx_put_string(env->mlx, "0", (coord.x + 3) * 32, coord.y * 32);
}