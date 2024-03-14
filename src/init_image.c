/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:13:06 by ttaquet           #+#    #+#             */
/*   Updated: 2024/03/10 14:41:17 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(mlx_t *mlx, t_env *env)
{
	t_texture	*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(t_texture));
	if (!tmp)
		stop_prog("Malloc have failed", env);
	tmp->a = mlx_load_png("texture/floor.png");
	tmp->b = mlx_load_png("texture/exit.png");
	tmp->c = mlx_load_png("texture/collectible.png");
	tmp->d = mlx_load_png("texture/trap.png");
	env->icon_texture = mlx_load_png("texture/icon.png");
	env->floor_image = mlx_texture_to_image(mlx, tmp->a);
	env->exit_image = mlx_texture_to_image(mlx, tmp->b);
	env->trap_image = mlx_texture_to_image(mlx, tmp->d);
	env->collectible_image = mlx_texture_to_image(mlx, tmp->c);
	del_texture(tmp, 4);
	free(tmp);
	init_wall_image(mlx, env);
	init_player_image(mlx, env);
}

void	init_wall_image(mlx_t *mlx, t_env *env)
{
	t_texture	*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(t_texture));
	if (!tmp)
		stop_prog("Malloc have failed", env);
	tmp->a = mlx_load_png("texture/wall/reduced_full.png");
	tmp->b = mlx_load_png("texture/wall/full.png");
	tmp->c = mlx_load_png("texture/wall/top.png");
	tmp->d = mlx_load_png("texture/wall/reduced_top.png");
	env->wall_image.reduced_full = mlx_texture_to_image(mlx, tmp->a);
	env->wall_image.full = mlx_texture_to_image(mlx, tmp->b);
	env->wall_image.top = mlx_texture_to_image(mlx, tmp->c);
	env->wall_image.reduced_top = mlx_texture_to_image(mlx, tmp->d);
	del_texture(tmp, 4);
	free(tmp);
}

void	init_player_image(mlx_t *mlx, t_env *env)
{
	t_texture	*tmp;

	tmp = malloc(sizeof(t_texture));
	if (!tmp)
		stop_prog("Malloc have failed", env);
	tmp->a = mlx_load_png("texture/player/player_down.png");
	tmp->b = mlx_load_png("texture/player/player_up.png");
	tmp->c = mlx_load_png("texture/player/player_left.png");
	tmp->d = mlx_load_png("texture/player/player_right.png");
	env->player_image.down = mlx_texture_to_image(mlx, tmp->a);
	env->player_image.up = mlx_texture_to_image(mlx, tmp->b);
	env->player_image.left = mlx_texture_to_image(mlx, tmp->c);
	env->player_image.right = mlx_texture_to_image(mlx, tmp->d);
	del_texture(tmp, 4);
	free(tmp);
}
