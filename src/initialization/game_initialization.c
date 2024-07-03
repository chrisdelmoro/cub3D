/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:08:03 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/14 16:18:38 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_game(t_game *game, t_scene *scene)
{
	game->scene = scene;
	game->player = scene->player;
	game->mlx = NULL;
	game->win = NULL;
	game->input_keys.a = FALSE;
	game->input_keys.s = FALSE;
	game->input_keys.d = FALSE;
	game->input_keys.w = FALSE;
	game->input_keys.left = FALSE;
	game->input_keys.right = FALSE;
}

int	init_player(t_scene *scene, int i, int j, char direction)
{
	scene->player = malloc(sizeof(t_player));
	scene->player->x = j;
	scene->player->y = i;
	scene->player->px = MAP_S * (j + 0.5);
	scene->player->py = MAP_S * (i + 0.5);
	if (direction == 'N')
		scene->player->pa = 90;
	else if (direction == 'S')
		scene->player->pa = 270;
	else if (direction == 'W')
		scene->player->pa = 180;
	else if (direction == 'E')
		scene->player->pa = 0;
	scene->player->pdx = cos(deg_to_rad(scene->player->pa));
	scene->player->pdy = -sin(deg_to_rad(scene->player->pa));
	return (1);
}

int	img_init(char *file_path, void *mlx, t_img *img)
{
	img->sprite_img = mlx_xpm_file_to_image(mlx, file_path, &img->width, \
	&img->height);
	if (img->sprite_img == NULL || img->width != 64 || img->height != 64)
	{
		throw_err(MINILIB_FAILED_SPRITE);
		return (0);
	}
	img->addr = mlx_get_data_addr(img->sprite_img, &img->bpp, \
	&img->line_len, &img->endian);
	return (1);
}

t_sprite	*sprite_init(t_game *game)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	sprite->ea = malloc(sizeof(t_img));
	sprite->no = malloc(sizeof(t_img));
	sprite->so = malloc(sizeof(t_img));
	sprite->we = malloc(sizeof(t_img));
	if (!img_init(game->scene->no, game->mlx, sprite->no) || \
	!img_init(game->scene->so, game->mlx, sprite->so) || \
	!img_init(game->scene->we, game->mlx, sprite->we) || \
	!img_init(game->scene->ea, game->mlx, sprite->ea))
		return (NULL);
	return (sprite);
}
