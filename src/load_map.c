/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:45:13 by ttaquet           #+#    #+#             */
/*   Updated: 2024/03/07 17:42:29 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(mlx_t	*mlx, t_coord coord, mlx_image_t *image, bool enabled)
{
	mlx_image_to_window(mlx, image, coord.x * 32, coord.y * 32);
	mlx_set_instance_depth(&image->instances[image->count - 1], coord.z);
	image->instances->enabled = enabled;
}

void	pre_load_image(int y, int x, t_env	*env)
{
	t_coord	tmp;

	tmp.x = x;
	tmp.y = y + 1;
	tmp.z = FLOOR_DEPTH;
	load_image(env->mlx, tmp, env->floor_image, true);
	if (env->map[y][x] == 'E')
	{
		tmp.z = EXIT_DEPTH;
		load_image(env->mlx, tmp, env->exit_image, true);
	}
	if (env->map[y][x] == 'C')
	{
		tmp.z = COLLECIBLE_DEPTH;
		load_image(env->mlx, tmp, env->collectible_image, true);
	}
	if (env->map[y][x] == 'P')
		pre_load_player(tmp, env);
}

void	pre_load_player(t_coord coord, t_env *env)
{
	env->player_dir = DOWN;
	coord.z = PLAYER_DEPTH;
	load_image(env->mlx, coord, env->player_image.down, true);
	load_image(env->mlx, coord, env->player_image.up, false);
	load_image(env->mlx, coord, env->player_image.left, false);
	load_image(env->mlx, coord, env->player_image.right, false);
}

void	load_wall(int x, int y, t_env	*env)
{
	if (y == 0)
	{
		mlx_image_to_window(env->mlx, env->wall_image.full, x * 32, 0);
		if (x == 0 || x == env->map_width)
			mlx_image_to_window(env->mlx, env->wall_image.full, x * 32, 32);
	}
	else if (x == 0 || x == env->map_width || y == env->map_height - 1)
		mlx_image_to_window(env->mlx, env->wall_image.top,
			x * 32, (y + 1) * 32);
	else
		if (env->map[y + 1][x] == '1')
			mlx_image_to_window(env->mlx, env->wall_image.reduced_top,
				x * 32, (y + 1) * 32);
		else
			mlx_image_to_window(env->mlx, env->wall_image.reduced_full,
				x * 32, (y + 1) * 32);
}

void	load_map(t_env	*env, char	**map)
{	
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				load_wall(j, i, env);
			else if (map[i][j] != '\n')
				pre_load_image(i, j, env);
			j++;
		}
		i++;
	}
}
