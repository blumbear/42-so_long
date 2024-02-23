/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:56:19 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/22 16:07:00 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	stop_prog(char	*error, t_env	*env)
{
	ft_printf("ERROR: %s\n", error);
	if (env->map)
	{
		ft_free_lststr(env->map);
		free(env->map);
	}
	mlx_terminate(env->mlx);
	exit(0);
}

void	ft_del_texture(t_texture *texture, int n)
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

void	print_data(t_env env)
{
	int	i;

	i = -1;
	ft_printf("Height -> %d, Width -> %d\n\n", env.map_height, env.map_width);
	while (env.map[++i])
		ft_printf("%s", env.map[i]);
	ft_printf("\n\n");
}

void	print_on_move(t_env *env)
{
	ft_printf("y -> %d | x -> %d | ", env->player_pos_y, env->player_pos_x);
	ft_printf("collectible obtained -> %d | ", env->collectible_obtained);
	ft_printf("number of movement -> %d\n", env->player_movement);
}
