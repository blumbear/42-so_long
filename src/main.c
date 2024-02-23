/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:44:53 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/23 14:01:48 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	static t_env	env = {};

	if (ac != 2)
		stop_prog("Not enough arguments.", &env);
	check_path_name(av[1], &env);
	env.map = parse(av[1], &env);
	map_is_verified(env.map, &env);
	env.mlx = mlx_init((env.map_width + 1) * 32,
			(env.map_height + 1) * 32, "OUI", true);
	print_data(env);
	init_image(env.mlx, &env);
	load_map(&env, env.map);
	mlx_key_hook(env.mlx, &keyhook, &env);
	mlx_loop(env.mlx);
	mlx_terminate(env.mlx);
}
