/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:02:06 by tom               #+#    #+#             */
/*   Updated: 2024/03/14 14:51:35 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_coord(int x, int y, t_coord *coord, int incr)
{
	coord->x = x + incr;
	coord->y = y;
}

void	load_text(t_env *e)
{
	t_coord		coord;
	t_texture	*tmp;

	if (e->map_width > 15)
	{
		tmp = NULL;
		tmp = malloc(sizeof(t_texture));
		coord.x = (((e->map_width) / 4) - 1);
		coord.y = (e->map_height + 1);
		coord.z = TEXT_DEPTH;
		tmp->a = mlx_load_png("texture/text/move.png");
		tmp->b = mlx_load_png("texture/text/point.png");
		tmp->c = mlx_load_png("texture/text/hp.png");
		init_coord(coord.x, coord.y, &e->strmove_coord, 3);
		load_image(e->mlx, coord, mlx_texture_to_image(e->mlx, tmp->a), true);
		coord.x = ((((e->map_width) / 4)) * 2) - 1;
		init_coord(coord.x, coord.y, &e->strpoint_coord, 3);
		load_image(e->mlx, coord, mlx_texture_to_image(e->mlx, tmp->b), true);
		coord.x = ((((e->map_width) / 4)) * 3) - 1;
		init_coord(coord.x, coord.y, &e->strhp_coord, 1);
		load_image(e->mlx, coord, mlx_texture_to_image(e->mlx, tmp->c), true);
		del_texture(tmp, 3);
		free(tmp);
	}
}

void	load_text_bis(t_env *e)
{
	t_coord		coord;
	t_texture	*tmp;

	if (e->map_width <= 15)
	{
		tmp = NULL;
		tmp = malloc(sizeof(t_texture));
		coord.x = ((e->map_width) + 1);
		coord.y = 2;
		coord.z = TEXT_DEPTH;
		tmp->a = mlx_load_png("texture/text/move.png");
		tmp->b = mlx_load_png("texture/text/point.png");
		tmp->c = mlx_load_png("texture/text/hp.png");
		init_coord(coord.x, coord.y, &e->strmove_coord, 3);
		load_image(e->mlx, coord, mlx_texture_to_image(e->mlx, tmp->a), true);
		coord.y += 2;
		init_coord(coord.x, coord.y, &e->strpoint_coord, 3);
		load_image(e->mlx, coord, mlx_texture_to_image(e->mlx, tmp->b), true);
		coord.y += 2;
		init_coord(coord.x, coord.y, &e->strhp_coord, 1);
		load_image(e->mlx, coord, mlx_texture_to_image(e->mlx, tmp->c), true);
		del_texture(tmp, 3);
		free(tmp);
	}
}
