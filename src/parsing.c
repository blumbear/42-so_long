/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:28:13 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/02 15:31:47 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_check(char	*line, size_t width)
{
	if (!ft_strchr(line, '\n') && ft_strlen(line) + 1 == width)
		return (1);
	else if (ft_strlen(line) == width)
		return (1);
	return (0);
}

int	pre_parse(env_t **env, int fd)
{
	char	*tmp;
	int		height;

	height = 0;
	tmp = get_next_line(fd);
	(*env)->map_width = ft_strlen(tmp);
	while (tmp != NULL)
	{
		if (!line_check(tmp, (*env)->map_width))
			ft_stop_function("MAP_IS_NOT_RECTANGULAR");
		height++;
		tmp = get_next_line(fd);
	}
	(*env)->map_height = height;
	close(fd);
	return (1);
}

char	**parse(char *path, env_t **env)
{
	char	**map;
	char	*tmp;
	int		i;
	int		fd;

	fd = open(path,O_RDONLY);
	pre_parse(env, fd);
	fd = open(path,O_RDONLY);
	tmp = get_next_line(fd);
	if (!tmp)
		ft_stop_function("MAP_NOT_USABLE");
	map = NULL;
	map = malloc(sizeof(char *) * (*env)->map_height + 1);
	i = 0;
	while (tmp != NULL)
	{
		map[i] = tmp;
		i++;
		tmp = get_next_line(fd);
	}
	return (map);
}
