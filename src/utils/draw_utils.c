/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:37:58 by mcarecho          #+#    #+#             */
/*   Updated: 2023/10/14 16:14:04 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	square(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 20)
	{
		j = -1;
		while (++j < 20)
		{
			if (i == 0 || i == 20)
				my_mlx_pixel_put(game->img, x + j, y + i, 0xfff);
			else if (j == 0 || j == 20)
				my_mlx_pixel_put(game->img, x + j, y + i, 0xfff);
			else
				my_mlx_pixel_put(game->img, x + j, y + i, color);
		}
	}
}

int	draw_line(t_game *game, int begin[2], int end[2], int color)
{
	double	delta[2];
	int		pixels;
	double	pixel[2];

	delta[0] = end[0] - begin[0];
	delta[1] = end[1] - begin[1];
	pixels = sqrt((delta[0] * delta[0]) + (delta[1] * delta[1]));
	if (pixels != 0)
	{
		delta[0] /= pixels;
		delta[1] /= pixels;
	}
	pixel[0] = begin[0];
	pixel[1] = begin[1];
	while (pixels)
	{
		my_mlx_pixel_put(game->img, pixel[0], pixel[1], color);
		pixel[0] += delta[0];
		pixel[1] += delta[1];
		--pixels;
	}
	return (0);
}

void	draw_floor_celing(t_game *game, t_ray *ray, t_ray_print *p_ray)
{
	draw_line(game, (int [2]){ray->r, 0}, (int [2]){ray->r, p_ray->line_off}, \
	game->scene->c);
	draw_line(game, (int [2]){ray->r, p_ray->line_off + p_ray->line_h}, \
	(int [2]){ray->r, MAP_Y}, game->scene->f);
}
