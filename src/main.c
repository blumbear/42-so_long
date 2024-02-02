/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:44:53 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/01 17:59:05 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	char	**map;
	env_t	*env;
	mlx_t	*mlx;

	if (ac != 2)
		ft_stop_function("NOT_ENOUGHT_ARGS");
	map = NULL;
	env = NULL;
	env = malloc (sizeof (env_t *));
	map = parse(av[1], &env);
	for (int i=0;map[i];i++)ft_printf("%s",map[i]);
	map_is_verified(map, &env);
	mlx = mlx_init(WIDTH, HEIGHT, "OUI", true);
	
}
