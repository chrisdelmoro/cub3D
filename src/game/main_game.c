/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:32:42 by mcarecho          #+#    #+#             */
/*   Updated: 2023/10/14 16:39:20 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_mini_map(t_game *game, int a, int b, int y)
{
	int	x;

	a = game->player->y - 5;
	while (a++ < game->player->y + 4)
	{
		x = 10;
		b = game->player->x - 5;
		while (a >= 0 && a < game->scene->max_y && b++ < game->player->x + 4)
		{
			if (b >= 0 && b < (int)ft_strlen(game->scene->map[a]))
			{
				if (game->player->y == a && game->player->x == b)
					square(game, x, y, 0x00FF00);
				else if (game->scene->map[a][b] == '1')
					square(game, x, y, 0x000000);
				else if (game->scene->map[a][b] == ' ')
					square(game, x, y, 0x000000);
				else
					square(game, x, y, 0xAFAFAF);
			}
			x += 22;
		}
		y += 22;
	}
}

void	draw_3d_map(t_game *game)
{
	t_ray_print	p_ray;
	t_ray		ray;

	ray.ra = fix_ang(game->player->pa + 35);
	ray.xo = 0;
	ray.yo = 0;
	ray.r = -1;
	while (++ray.r < 800)
	{
		ray.dof = 0;
		ray.dis_v = 100000;
		ray.tan = tan(deg_to_rad(ray.ra));
		horizontal_ray_check(game, &ray);
		horizontal_ray_dist(game, &ray);
		ray.dof = 0;
		ray.dis_h = 100000;
		ray.tan = 1.0 / ray.tan;
		vertical_ray_check(game, &ray);
		vertical_ray_dist(game, &ray);
		calculate_ray_wall_height(game, &ray, &p_ray);
		draw_floor_celing(game, &ray, &p_ray);
		draw_wall(game, &ray, &p_ray);
		ray.ra = fix_ang(ray.ra - 0.0875);
	}
}

int	print_view(t_game *game)
{
	draw_3d_map(game);
	draw_mini_map(game, 10, 10, 10);
	mlx_put_image_to_window(game->mlx, game->win, game->img->sprite_img, 0, 0);
	move_player(game);
	game->player->x = (int)game->player->px / MAP_S;
	game->player->y = (int)game->player->py / MAP_S;
	cam_rotation(game);
	return (0);
}
