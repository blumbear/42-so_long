/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:21:36 by ttaquet           #+#    #+#             */
/*   Updated: 2024/03/14 15:43:17 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_pathway(char	**map, int y, int x)
{
	map[y][x] *= -1;
	if (ft_strchr("E0CT", map[y + 1][x]))
		map_pathway(map, y + 1, x);
	if (ft_strchr("E0CT", map[y - 1][x]))
		map_pathway(map, y - 1, x);
	if (ft_strchr("E0CT", map[y][x + 1]))
		map_pathway(map, y, x + 1);
	if (ft_strchr("E0CT", map[y][x - 1]))
		map_pathway(map, y, x - 1);
}

void	post_pathway(char	**map, t_env *env)
{
	int	i;
	int	j;
	int	nb_collectible_find;

	i = 0;
	nb_collectible_find = 0;
	env->exit = false;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] < 0)
			{
				map[i][j] *= -1;
				if (map[i][j] == 'C')
					nb_collectible_find++;
				else if (map[i][j] == 'E')
					env->exit = true;
			}
		}
	}
	post_pathway_variable_test(nb_collectible_find, env);
}

void	post_pathway_variable_test(int nb_collectible, t_env *env)
{
	if (nb_collectible != env->collectible)
		stop_prog("The player cant optain every collectible.", env);
	if (env->exit == false)
		stop_prog("The player cant reach the exit.", env);
}
