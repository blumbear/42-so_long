/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:28:13 by ttaquet           #+#    #+#             */
/*   Updated: 2024/03/10 14:53:13 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_check(char	*line, size_t width)
{
	if (!ft_strchr(line, '\n') && ft_strlen(line) - 1 == width)
		return (1);
	else if (ft_strlen(line) - 2 == width)
		return (1);
	return (0);
}

void	parse(t_env *env, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (!fd)
		stop_prog("The file are not found.", env);
	if (read_map(0, env, fd) == -1)
		stop_prog("The map are not rectangular", env);
	if (env->map_height < 3 && env->map_width < 3)
		stop_prog("The map are not usable.", env);
}

int	read_map(int depth, t_env *env, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
	{
		env->map = ft_calloc(depth + 1, sizeof(char *));
		env->map[depth] = NULL;
		env->map_height = depth;
		return (0);
	}
	if (depth == 0)
		env->map_width = ft_strlen(line) - 2;
	else if (!line_check(line, env->map_width))
		return (free(line), -1);
	if (read_map(depth + 1, env, fd) == -1)
		return (free(line), -1);
	env->map[depth] = line;
	return (1);
}
