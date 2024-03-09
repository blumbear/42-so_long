/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:20:43 by ttaquet           #+#    #+#             */
/*   Updated: 2024/03/09 15:05:00 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_player(t_env *env, int pos_x, int pos_y)
{
	env->player = true;
	env->player_coord.x = pos_x;
	env->player_coord.y = pos_y;
	env->player_hp = 3;
	env->key_enaled = true;
	env->player_pos_chunck = '0';
}

void	ft_init_exit(t_env *env, int pos_x, int pos_y)
{
	env->exit = true;
	env->exit_coord.x = pos_x;
	env->exit_coord.y = pos_y;
}
