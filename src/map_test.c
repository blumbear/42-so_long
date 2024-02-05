/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:38:29 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/05 14:27:34 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_stop_function(char	*error)
{
	ft_printf("\nERROR: %s\n",error);
	exit(0);
}

void post_process_test(env_t **env)
{
	if ((*env)->collectible < 1){
		ft_stop_function("NOT_ENOUGHT_COLLECTIBLE");}
	if ((*env)->player == false)
		ft_stop_function("NOT_ENOUGHT_PLAYER");
	if ((*env)->exit == false){ft_printf("%d",(*env)->exit);
		ft_stop_function("NOT_ENOUGHT_EXIT");}
}

int	chunck_test(char c, env_t	**env, int	i, int	j)
{
	if (ft_strchr("01CPE",c) != NULL)
	{
		if (c == 'C')
			(*env)->collectible += 1;
		if (c == 'P' && (*env)->player == true)
			ft_stop_function("TOO_MUCH_PLAYER");
		else if (c == 'P' && (*env)->player == false)
			ft_init_player(env, j, i);
		if (c == 'E' && (*env)->exit == true)
			ft_stop_function("TOO_MUCH_EXIT");
		else if (c == 'E' && (*env)->exit == false)
			ft_init_exit(env, j, i);
		return (1);
	}
	ft_stop_function("UNDEFINED_CHARACTER_USED");
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

void	post_pathway(char	**map, env_t **env)
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
					res++;
			}
			j++;
		}
		i++;
	}
	if (res != (*env)->collectible)
		ft_stop_function("THE_PLAYER_CANT_OPTAIN_EVERY_COLLECTIBLE_OR_THE_EXIT");
}

int	map_surrounded(char **map, env_t **env)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		if (i == (*env)->map_height - 1 || i == 0)
		{
			j = 0;
			while (map[i][j] == '1')
				j++;
			if (j != (*env)->map_width - 1)
				ft_stop_function("MAP_IS_NOT_SURROUNDED_BY_WALLS");
		}
		else
			if (map[i][0] != '1' || map[i][(*env)->map_width - 2] != '1')
				ft_stop_function("MAP_IS_NOT_SURROUNDED_BY_WALLS");
		i++;
	}
	return (1);
}

int	map_is_verified(char **map, env_t **env)
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
	map_pathway(map, (*env)->player_pos_y, (*env)->player_pos_x);
	post_pathway(map, env);
	return(1);
}
