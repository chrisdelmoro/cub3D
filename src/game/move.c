/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:49:51 by mcarecho          #+#    #+#             */
/*   Updated: 2023/10/14 16:38:35 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	cam_rotation(t_game *game)
{
	if (game->input_keys.right == TRUE)
	{
		game->player->pa -= ROT_SPEED;
		game->player->pa = fix_ang(game->player->pa);
		game->player->pdx = cos(deg_to_rad(game->player->pa));
		game->player->pdy = -sin(deg_to_rad(game->player->pa));
	}
	if (game->input_keys.left == TRUE)
	{
		game->player->pa += ROT_SPEED;
		game->player->pa = fix_ang(game->player->pa);
		game->player->pdx = cos(deg_to_rad(game->player->pa));
		game->player->pdy = -sin(deg_to_rad(game->player->pa));
	}
}

int	collision(float p, float pd, t_bool is_sub)
{
	int	o;

	if (pd < 0)
		o = -20;
	else
		o = 20;
	if (is_sub == TRUE)
		return ((int)((p / MAP_S + (pd - o) / MAP_S)));
	else
		return ((int)((p / MAP_S + (pd + o) / MAP_S)));
}

void	move_front_back(t_game *game)
{
	if (game->input_keys.w == TRUE)
	{
		if (game->scene->map[game->player->y]
			[collision(game->player->px, game->player->pdx, FALSE)]
			!= '1')
			game->player->px += game->player->pdx * MOVE_SPEED;
		if (game->scene->map[collision(game->player->py, game->player->pdy, \
		FALSE)]
			[game->player->x] != '1')
			game->player->py += game->player->pdy * MOVE_SPEED;
	}
	if (game->input_keys.s == TRUE)
	{
		if (game->scene->map[game->player->y]
			[collision(game->player->px, game->player->pdx, TRUE)]
			!= '1')
			game->player->px -= game->player->pdx * MOVE_SPEED;
		if (game->scene->map[collision(game->player->py, game->player->pdy, \
		TRUE)]
			[game->player->x] != '1')
			game->player->py -= game->player->pdy * MOVE_SPEED;
	}
}

void	move_right_left(t_game *game)
{
	if (game->input_keys.d == TRUE)
	{
		if (game->scene->map[game->player->y]
			[collision(game->player->px, game->player->pdy, TRUE)] != '1')
			game->player->px -= game->player->pdy * MOVE_SPEED;
		if (game->scene->map[collision(game->player->py, game->player->pdx, \
		FALSE)]
			[game->player->x] != '1')
			game->player->py += game->player->pdx * MOVE_SPEED;
	}
	if (game->input_keys.a == TRUE)
	{
		if (game->scene->map[game->player->y]
			[collision(game->player->px, game->player->pdy, FALSE)]
			!= '1')
			game->player->px += game->player->pdy * MOVE_SPEED;
		if (game->scene->map[collision(game->player->py, game->player->pdx, \
		TRUE)]
			[game->player->x] != '1')
			game->player->py -= game->player->pdx * MOVE_SPEED;
	}
}

void	move_player(t_game *game)
{
	move_front_back(game);
	move_right_left(game);
}
