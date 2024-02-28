/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:20:43 by ttaquet           #+#    #+#             */
/*   Updated: 2024/02/28 15:43:49 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_player(t_env *env, int pos_x, int pos_y)
{
	env->player = true;
	env->player_pos_x = pos_x;
	env->player_pos_y = pos_y;
}

void	ft_init_exit(t_env *env, int pos_x, int pos_y)
{
	env->exit = true;
	env->exit_pos_x = pos_x;
	env->exit_pos_y = pos_y;
}

void	init_image(mlx_t *mlx, t_env *env)
{
	t_texture	*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(t_texture));
	tmp->a = mlx_load_png("texture/floor.png");
	tmp->b = mlx_load_png("texture/exit.png");
	tmp->c = mlx_load_png("texture/collectible.png");
	env->icon_texture = mlx_load_png("texture/icon.png");
	env->floor_image = mlx_texture_to_image(mlx, tmp->a);
	env->exit_image = mlx_texture_to_image(mlx, tmp->b);
	env->collectible_image = mlx_texture_to_image(mlx, tmp->c);
	ft_del_texture(tmp, 3);
	free(tmp);
	init_wall_image(mlx, env);
	init_player_image(mlx, env);
}

void	init_wall_image(mlx_t *mlx, t_env *env)
{
	t_texture	*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(t_texture));
	tmp->a = mlx_load_png("texture/wall/reduced_full.png");
	tmp->b = mlx_load_png("texture/wall/full.png");
	tmp->c = mlx_load_png("texture/wall/top.png");
	env->wall_image.reduced_full = mlx_texture_to_image(mlx, tmp->a);
	env->wall_image.full = mlx_texture_to_image(mlx, tmp->b);
	env->wall_image.top = mlx_texture_to_image(mlx, tmp->c);
	ft_del_texture(tmp, 3);
	free(tmp);
}

void	init_player_image(mlx_t *mlx, t_env *env)
{
	t_texture	*tmp;

	tmp = malloc(sizeof(t_texture));
	tmp->a = mlx_load_png("texture/player/player_down.png");
	tmp->b = mlx_load_png("texture/player/player_up.png");
	tmp->c = mlx_load_png("texture/player/player_left.png");
	tmp->d = mlx_load_png("texture/player/player_right.png");
	env->player_image.down = mlx_texture_to_image(mlx, tmp->a);
	env->player_image.up = mlx_texture_to_image(mlx, tmp->b);
	env->player_image.left = mlx_texture_to_image(mlx, tmp->c);
	env->player_image.right = mlx_texture_to_image(mlx, tmp->d);
	ft_del_texture(tmp, 4);
	free(tmp);
}
