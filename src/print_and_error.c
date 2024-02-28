/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:40:10 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/28 16:19:48 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	stop_prog(char	*error, t_env	*env, bool print_error, char *to_free)
{
	if (print_error)
		ft_printf("ERROR\n%s\n", error);
	if (env->map)
	{
		ft_free_lststr(env->map);
		free(env->map);
	}
	if (env->icon_texture)
		mlx_delete_texture(env->icon_texture);
	if (to_free)
		free(to_free);
	if (env->mlx)
		mlx_terminate(env->mlx);
	exit(0);
}

void	print_data(t_env env)
{
	int	i;

	i = -1;
	ft_printf("DIRECTION = %d", env.player_dir);
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
