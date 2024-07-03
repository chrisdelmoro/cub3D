/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:57:00 by mcarecho          #+#    #+#             */
/*   Updated: 2023/10/14 16:14:11 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	verify_shade(t_ray *ray, t_ray_print *p_ray)
{
	p_ray->ty = p_ray->ty_off * p_ray->ty_step;
	if (p_ray->shade == 1)
	{
		p_ray->tx = (int)(ray->rx) % 64;
		if (ray->ra > 180)
			p_ray->tx = 63 - p_ray->tx;
	}
	else
	{
		p_ray->tx = (int)(ray->ry) % 64;
		if (ray->ra > 90 && ray->ra < 270)
			p_ray->tx = 63 - p_ray->tx;
	}
}

int	get_sprite_color(int pixel, char *sprite, int shade)
{
	return (create_trgb(shade, get_r((int)sprite[pixel + 2]),
			get_g((int)sprite[pixel + 1]),
			get_b((int)sprite[pixel])));
}

void	draw_wall(t_game *game, t_ray *ray, t_ray_print *p_ray)
{
	int	y;

	verify_shade(ray, p_ray);
	y = -1;
	while (++y < p_ray->line_h)
	{
		p_ray->color = ((int)(p_ray->ty) * 64 + (int)(p_ray->tx)) * 4;
		if (ray->eye_h == 'N')
			p_ray->color = get_sprite_color(p_ray->color, \
		game->sprites->so->addr, p_ray->shade);
		if (ray->eye_h == 'E')
			p_ray->color = get_sprite_color(p_ray->color, \
		game->sprites->we->addr, p_ray->shade);
		if (ray->eye_h == 'W')
			p_ray->color = get_sprite_color(p_ray->color, \
		game->sprites->ea->addr, p_ray->shade);
		if (ray->eye_h == 'S')
			p_ray->color = get_sprite_color(p_ray->color, \
		game->sprites->no->addr, p_ray->shade);
		my_mlx_pixel_put(game->img, ray->r, p_ray->line_off + y, p_ray->color);
		p_ray->ty += p_ray->ty_step;
	}
}
