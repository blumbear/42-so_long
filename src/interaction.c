/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:48:25 by ttaquet           #+#    #+#             */
/*   Updated: 2024/03/14 13:23:25 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectible_test(t_env *env)
{
	t_coord	tmp;

	if (env->player_pos_chunck == 'C')
	{
		if (env ->player_hp < 3)
			env->player_hp += 1;
		tmp.x = env->player_coord.x;
		tmp.y = env->player_coord.y + 1;
		tmp.z = COLLECIBLE_DEPTH + 1;
		env->collectible_obtained += 1;
		env->player_pos_chunck = '0';
		load_image(env->mlx, tmp, env->floor_image, true);
	}
}

void	exit_test(t_env *env)
{
	t_texture	*strwin_texture;

	if (env->collectible_obtained == env->collectible
		&& env->player_pos_chunck == 'E')
	{
		strwin_texture = malloc(sizeof(t_texture));
		if (!strwin_texture)
			stop_prog("Malloc have failed", env);
		env->key_enaled = false;
		strwin_texture->a = mlx_load_png("texture/text/you_won.png");
		mlx_image_to_window(env->mlx,
			mlx_texture_to_image(env->mlx, strwin_texture->a),
			((env->map_width / 2) - ((210 / 32) / 2)) * 32,
			((env->map_height / 2)) * 32);
		del_texture(strwin_texture, 1);
	}
}

void	player_on_trap(t_env *env)
{
	t_texture	*strlose_texture;

	if (env->player_pos_chunck == 'T')
	{
		strlose_texture = malloc(sizeof(t_texture));
		if (!strlose_texture)
			stop_prog("Malloc have failed", env);
		strlose_texture->a = mlx_load_png("texture/text/you_lose.png");
		env->player_hp -= 2;
		if (env->player_hp < 1)
		{
			env->key_enaled = false;
			mlx_image_to_window(env->mlx,
				mlx_texture_to_image(env->mlx, strlose_texture->a),
				((env->map_width / 2) - 3) * 32, ((env->map_height / 2)) * 32);
		}
		del_texture(strlose_texture, 1);
	}
}
