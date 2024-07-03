/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:09:30 by mcarecho          #+#    #+#             */
/*   Updated: 2023/10/14 15:59:52 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	horizontal_ray_check(t_game *game, t_ray *ray)
{
	if (cos(deg_to_rad(ray->ra)) > 0.001)
	{
		ray->vx = (((int)game->player->px >> 6) << 6) + 64;
		ray->vy = (game->player->px - ray->vx) * ray->tan + game->player->py;
		ray->xo = 64;
		ray->yo = -ray->xo * ray->tan;
		ray->eye_v = 'E';
	}
	else if (cos(deg_to_rad(ray->ra)) < -0.001)
	{
		ray->vx = (((int)game->player->px >> 6) << 6) - 0.0001;
		ray->vy = (game->player->px - ray->vx) * ray->tan + game->player->py;
		ray->xo = -64;
		ray->yo = -ray->xo * ray->tan;
		ray->eye_v = 'W';
	}
	else
	{
		ray->vx = game->player->px;
		ray->vy = game->player->py;
		ray->dof = game->scene->max_x;
	}
}

void	vertical_ray_check(t_game *game, t_ray *ray)
{
	if (sin(deg_to_rad(ray->ra)) > 0.001)
	{
		ray->ry = (((int)game->player->py >> 6) << 6) - 0.0001;
		ray->rx = (game->player->py - ray->ry) * ray->tan + game->player->px;
		ray->yo = -64;
		ray->xo = -ray->yo * ray->tan;
		ray->eye_h = 'N';
	}
	else if (sin(deg_to_rad(ray->ra)) < -0.001)
	{
		ray->ry = (((int)game->player->py >> 6) << 6) + 64;
		ray->rx = (game->player->py - ray->ry) * ray->tan + game->player->px;
		ray->yo = 64;
		ray->xo = -ray->yo * ray->tan;
		ray->eye_h = 'S';
	}
	else
	{
		ray->rx = game->player->px;
		ray->ry = game->player->py;
		ray->dof = game->scene->max_y;
	}
}

void	horizontal_ray_dist(t_game *game, t_ray *ray)
{
	while (ray->dof < game->scene->max_x || ray->dof < game->scene->max_y)
	{
		ray->mx = (int)(ray->vx) >> 6;
		ray->my = (int)(ray->vy) >> 6;
		ray->mp = ray->my * game->scene->max_x + ray->mx;
		if (ray->mp > 0 && ray->my >= 0 && ray->my < game->scene->max_y && \
		ray->mx >= 0 && ray->mx < (int)ft_strlen(game->scene->map[ray->my]) \
		&& game->scene->map[ray->my][ray->mx] == '1')
		{
			ray->dof = game->scene->max_x;
			ray->dis_v = cos(deg_to_rad(ray->ra)) * (ray->vx - \
			game->player->px) - sin(deg_to_rad(ray->ra)) * \
			(ray->vy - game->player->py);
		}
		else
		{
			ray->vx += ray->xo;
			ray->vy += ray->yo;
			ray->dof += 1;
		}
	}
}

void	vertical_ray_dist(t_game *game, t_ray *ray)
{
	while (ray->dof < game->scene->max_y)
	{
		ray->mx = (int)(ray->rx) >> 6;
		ray->my = (int)(ray->ry) >> 6;
		ray->mp = ray->my * game->scene->max_x + ray->mx;
		if (ray->mp > 0 && ray->my >= 0 && ray->my < game->scene->max_y && \
		ray->mx >= 0 && ray->mx < (int)ft_strlen(game->scene->map[ray->my]) \
		&& game->scene->map[ray->my][ray->mx] == '1')
		{
				ray->dof = game->scene->max_y;
				ray->dis_h = cos(deg_to_rad(ray->ra)) * (ray->rx - \
				game->player->px) - sin(deg_to_rad(ray->ra)) * \
				(ray->ry - game->player->py);
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}
	}
}

void	calculate_ray_wall_height(t_game *game, t_ray *ray, t_ray_print *p_ray)
{
	p_ray->shade = 1;
	if (ray->dis_v < ray->dis_h)
	{
		ray->rx = ray->vx;
		ray->ry = ray->vy;
		p_ray->shade = 0.5;
		ray->dis_h = ray->dis_v;
		ray->eye_h = ray->eye_v;
	}
	p_ray->ca = fix_ang(game->player->pa - ray->ra);
	ray->dis_h = ray->dis_h * cos(deg_to_rad(p_ray->ca));
	p_ray->line_h = (MAP_S * 600) / (ray->dis_h);
	p_ray->ty_step = 64.0 / (float)p_ray->line_h;
	p_ray->ty_off = 0;
	if (p_ray->line_h > MAP_Y)
	{
		p_ray->ty_off = (p_ray->line_h - MAP_Y) / 2.0;
		p_ray->line_h = MAP_Y;
	}
	p_ray->line_off = 300 - (p_ray->line_h >> 1);
}
