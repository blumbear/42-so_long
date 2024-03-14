/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:44:53 by ttaquet           #+#    #+#             */
/*   Updated: 2024/03/10 15:59:36 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	static t_env	env = {};

	if (ac != 2)
		stop_prog("Not enough arguments.", &env);
	check_path_name(av[1], &env);
	parse(&env, av[1]);
	map_is_verified(env.map, &env);
	if (env.map_width > 15)
		env.mlx = mlx_init((env.map_width + 1) * 32,
				(env.map_height + 3) * 32, "OUI", true);
	else
		env.mlx = mlx_init((env.map_width + 5) * 32,
				(env.map_height + 1) * 32, "OUI", true);
	if (!env.mlx)
		stop_prog("mlx_init crash", &env);
	init_image(env.mlx, &env);
	mlx_set_icon(env.mlx, env.icon_texture);
	load_map(&env, env.map);
	print_data(env);
	load_text(&env);
	load_text_bis(&env);
	print_on_move(&env);
	mlx_key_hook(env.mlx, &keyhook, &env);
	mlx_loop(env.mlx);
	stop_prog("\0", &env);
}
