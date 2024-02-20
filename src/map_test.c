/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:38:29 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/20 14:30:47 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void post_process_test(env_t *env)
{
	if (env->collectible < 1)
		stop_prog("Not enought collectible.");
	if (env->player == false)
		stop_prog("Not enought player.");
	if (env->exit == false)
		stop_prog("Not enought exit.");
}

int	chunck_test(char c, env_t	*env, int	i, int	j)
{
	if (ft_strchr("01CPE",c) != NULL)
	{
		if (c == 'C')
			env->collectible += 1;
		if (c == 'P' && env->player == true)
			stop_prog("Too much exit.");
		else if (c == 'P' && env->player == false)
			ft_init_player(env, j, i);
		if (c == 'E' && env->exit == true)
			stop_prog("Too much exit.");
		else if (c == 'E' && env->exit == false)
			ft_init_exit(env, j, i);
		return (1);
	}
	stop_prog("An undefined character are use.");
	return (0);
}

void	map_pathway(char	**map, int	y, int	x)
{
	map[y][x] *= -1;
	if (ft_strchr("E0C",map[y + 1][x]))
		map_pathway(map, y + 1, x);
	if (ft_strchr("E0C",map[y - 1][x]))
		map_pathway(map, y - 1, x);
	if (ft_strchr("E0C",map[y][x + 1]))
		map_pathway(map, y, x + 1);
	if (ft_strchr("E0C",map[y][x - 1]))
		map_pathway(map, y, x - 1);
}

void	post_pathway(char	**map, env_t *env)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] < 0)
			{
				map[i][j] *= -1;
				if (map[i][j] == 'C')
				{
					res++;
				}
			}
			j++;
		}
		i++;
	}
	if (res != env->collectible)
		stop_prog("The player cant optain every collectible.");
}

int	map_surrounded(char **map, env_t *env)
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
				stop_prog("The map is not surrounded by wall.");
		}
		else
			if (map[i][0] != '1' || map[i][env->map_width] != '1')
				stop_prog("The map is not surrounded by wall.");
		i++;
	}
	return (1);
}

int	map_is_verified(char **map, env_t *env)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (!chunck_test(map[i][j], env, i, j))
				exit(0);
			j++;
		}
		i++;
	}
	post_process_test(env);
	map_surrounded(map, env);
	map_pathway(map, env->player_pos_y, env->player_pos_x);
	post_pathway(map, env);
	return(1);
}

void	check_path_name(char	*path)
{
	if (ft_strncmp(path + (ft_strlen(path) - 4), ".ber",4) != 0)
		stop_prog("The map must be in the format '.ber'.");
}
