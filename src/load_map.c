/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:45:13 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/19 17:41:33 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_wall(mlx_t	*mlx, int	i, int	j, env_t	*env)
{
	if (i == 0)
	{
		mlx_image_to_window(mlx, env->wall_image.full, j * 32, 0);
		if (j == 0 || j == env->map_width)
			mlx_image_to_window(mlx, env->wall_image.full, j * 32, 32);
	}
	else if (j == 0 || j == env->map_width || i == env->map_height - 1)
		mlx_image_to_window(mlx, env->wall_image.top, j * 32, (i + 1) * 32);
	else
		mlx_image_to_window(mlx, env->wall_image.reduced_full, j * 32, (i + 1) * 32);
}

void	load_image(mlx_t	*mlx, int	x, int	y, int	z, mlx_image_t *image)
{
	mlx_image_to_window(mlx, image, (y) * 32, (x + 1) * 32);
	image->instances[image->count - 1].z = z;
	//mlx_set_instance_depth(image->instances, z);
}

void	load_map(mlx_t	*mlx, env_t	*env, char	**map)
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
				load_wall(mlx, i, j, env);
			else
			{
				load_image(mlx, i, j, 0, env->floor_image);
				if (map[i][j] == 'E')
					load_image(mlx, i, j, 1, env->exit_image);
				if (map[i][j] == 'P')
					load_image(mlx, i, j, 3, env->player_image.down);
				if (map[i][j] == 'C')
					load_image(mlx, i, j, 1, env->collectible_image);
			}
			j++;
		}
		i++;
	}
}

void	print_data(env_t env)
{
	int	i;

	i = -1;
	ft_printf("Height -> %d, Width -> %d\n\n",env.map_height,env.map_width);
	while (env.map[++i])
		ft_printf("%s",env.map[i]);
	ft_printf("\n\n");
}
