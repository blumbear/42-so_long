/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:40:10 by ttaquet           #+#    #+#             */
/*   Updated: 2024/03/09 15:04:13 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	stop_prog(char	*error, t_env	*env, bool print_error)
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
	if (env->mlx)
		mlx_terminate(env->mlx);
	exit(0);
}

void	print_data(t_env env)
{
	int	i;

	i = -1;
	ft_printf("trap number -> %d\n", env.trap_number);
	ft_printf("Height -> %d, Width -> %d\n", env.map_height, env.map_width);
	ft_printf("player_pos_chunck -> %c\n\n",env.player_pos_chunck);
	while (env.map[++i])
		ft_printf("%s", env.map[i]);
	ft_printf("\n\n");
}

void	print_on_move(t_env *env)
{
	char	*tmp;

	ft_printf("y -> %d | x -> %d | ", env->player_coord.y, env->player_coord.x);
	ft_printf("collectible obtained -> %d | ", env->collectible_obtained);
	ft_printf("number of movement -> %d\n", env->player_movement);
	mlx_delete_image(env->mlx, env->strmove);
	mlx_delete_image(env->mlx, env->strpoint);
	tmp = ft_itoa(env->player_movement);
	env->strmove = mlx_put_string(env->mlx, tmp,
			(env->strmove_coord.x + 3) * 32, env->strmove_coord.y * 32);
	free(tmp);
	tmp = ft_itoa(env->collectible_obtained);
	env->strpoint = mlx_put_string(env->mlx, tmp,
			(env->strpoint_coord.x + env->strlose_size) * 32,
			env->strpoint_coord.y * 32);
	free(tmp);
}
