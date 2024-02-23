/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:38:29 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/23 16:05:34 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	post_process_test(t_env *env)
{
	if (env->collectible < 1)
		stop_prog("Not enough collectible.", env, true);
	if (env->player == false)
		stop_prog("Not enough player.", env, true);
	if (env->exit == false)
		stop_prog("Not enough exit.", env, true);
}

int	chunck_test(char c, t_env	*env, int y, int x)
{
	if (ft_strchr("01CPE", c) != NULL)
	{
		if (c == 'C')
			env->collectible += 1;
		if (c == 'P' && env->player == true)
			stop_prog("Too much exit.", env, true);
		else if (c == 'P' && env->player == false)
			ft_init_player(env, x, y);
		if (c == 'E' && env->exit == true)
			stop_prog("Too much exit.", env, true);
		else if (c == 'E' && env->exit == false)
			ft_init_exit(env, x, y);
		return (1);
	}
	stop_prog("An undefined character are use.", env, true);
	return (0);
}

void	map_pathway(char	**map, int y, int x)
{
	map[y][x] *= -1;
	if (ft_strchr("E0C", map[y + 1][x]))
		map_pathway(map, y + 1, x);
	if (ft_strchr("E0C", map[y - 1][x]))
		map_pathway(map, y - 1, x);
	if (ft_strchr("E0C", map[y][x + 1]))
		map_pathway(map, y, x + 1);
	if (ft_strchr("E0C", map[y][x - 1]))
		map_pathway(map, y, x - 1);
}

void	post_pathway(char	**map, t_env *env)
{
	int	i;
	int	j;
	int	res;

	i = -1;
	res = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] < 0)
			{
				map[i][j] *= -1;
				if (map[i][j] == 'C')
					res++;
			}
			j++;
		}
	}
	if (res != env->collectible)
		stop_prog("The player cant optain every collectible.", env, true);
}
