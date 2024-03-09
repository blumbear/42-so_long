/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:48:25 by ttaquet           #+#    #+#             */
/*   Updated: 2024/03/09 15:23:48 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collectible_test(t_env *env, int pos_x, int pos_y)
{
	t_coord	tmp;

	if (env->map[pos_y][pos_x] == 'C')
	{
		if (env ->player_hp < 3)
			env->player_hp += 1;
		tmp.x = pos_x;
		tmp.y = pos_y + 1;
		tmp.z = COLLECIBLE_DEPTH + 1;
		env->collectible_obtained += 1;
		env->map[pos_y][pos_x] = '0';
		load_image(env->mlx, tmp, env->floor_image, true);
	}
}

void	ft_exit_test(t_env *env, int pos_x, int pos_y)
{
	t_texture *strlose_texture;

	strlose_texture = malloc(sizeof(t_texture));
	if (env->collectible_obtained == env->collectible
		&& pos_x == env->exit_coord.x && pos_y == env->exit_coord.y)
	{
		env->key_enaled = false;
		strlose_texture->a = mlx_load_png("texture/text/you_won.png");
		mlx_image_to_window(env->mlx, mlx_texture_to_image(env->mlx, strlose_texture->a),
				((env->map_width / 2) - 3) * 32, ((env->map_height / 2)) * 32);
		ft_del_texture(strlose_texture, 1);
	}
}

void	ft_player_on_trap(t_env *env, int pos_x, int pos_y)
{
	t_texture *strwon_texture;

	strwon_texture = malloc(sizeof(t_texture));
	if (env->map[pos_y][pos_x] == 'T')
	{
		strwon_texture->a = mlx_load_png("texture/text/you_lose.png");
		env->player_hp -= 2;
		if (env->player_hp < 0)
		{
			env->key_enaled = false;
			mlx_image_to_window(env->mlx, mlx_texture_to_image(env->mlx, strwon_texture->a),
				((env->map_width / 2) - 3) * 32, ((env->map_height / 2)) * 32);
		}
		ft_del_texture(strwon_texture, 1);
	}
}
