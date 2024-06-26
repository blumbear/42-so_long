/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:38:29 by ttaquet           #+#    #+#             */
/*   Updated: 2024/03/14 16:00:46 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_is_verified(char **map, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (env->map[i][j] != '\n' && env->map[i][j] != '\0')
		{
			if (!chunck_test(env->map[i][j], env, i, j))
				continue ;
			j++;
		}
		i++;
	}
	map_surrounded(map, env);
	check_variable(env);
	map_pathway(map, env->player_coord.y, env->player_coord.x);
	post_pathway(map, env);
}

int	chunck_test(char c, t_env	*env, int y, int x)
{
	if (ft_strchr("01CPET", c) != NULL)
	{
		if (c == 'C')
			env->collectible ++;
		if (c == 'P' && env->player_hp == 3)
			stop_prog("Too much player.", env);
		else if (c == 'P')
			init_player(env, x, y);
		if (c == 'E' && env->exit == true)
			stop_prog("Too much exit.", env);
		else if (c == 'E')
			env->exit = true;
		else if (c == 'T')
			env->trap_number += 1;
		return (1);
	}
	stop_prog("An undefined character is used.", env);
	return (0);
}

void	check_variable(t_env *env)
{
	if (env->collectible < 1)
		stop_prog("Not enough collectible.", env);
	if (env->player_hp == 0)
		stop_prog("Not enough player.", env);
	if (env->exit == false)
		stop_prog("Not enough exit.", env);
}

void	map_surrounded(char **map, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		if (i == env->map_height - 1 || i == 0)
		{
			j = 0;
			while (map[i][j] == '1')
				j++;
			if (j - 1 != env->map_width)
				stop_prog("The map is not surrounded by wall.",
					env);
		}
		else
			if (map[i][0] != '1' || map[i][env->map_width] != '1')
				stop_prog("The map is not surrounded by wall.",
					env);
		i++;
	}
}
