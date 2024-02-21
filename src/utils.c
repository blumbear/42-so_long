/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:56:19 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/21 17:16:45 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	stop_prog(char	*error, t_env	*env)
{
	ft_printf("ERROR: %s\n", error);
	ft_freellst(env->map);
	exit(0);
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
	ft_printf("collectible obtained -> %d\n", env->collectible_obtained);
}
