/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:21:36 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/23 16:04:52 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
				stop_prog("The map is not surrounded by wall.", env, true);
		}
		else
			if (map[i][0] != '1' || map[i][env->map_width] != '1')
				stop_prog("The map is not surrounded by wall.", env, true);
		i++;
	}
}

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
	post_process_test(env);
	map_surrounded(map, env);
	map_pathway(map, env->player_pos_y, env->player_pos_x);
	post_pathway(map, env);
}

void	check_path_name(char	*path, t_env	*env)
{
	if (ft_strncmp(path + (ft_strlen(path) - 4), ".ber", 4) != 0)
		stop_prog("The map must be in the format '.ber'.", env, true);
}
