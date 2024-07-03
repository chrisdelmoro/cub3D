/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_textures_and_colors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:56:45 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/14 17:10:36 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

/*
Check if provided texture files exist in specified path.
*/

int	check_textures_exist(t_scene *scene)
{
	scene->fd = open(scene->no, O_RDONLY);
	if (scene->fd < 0)
		return (0);
	close(scene->fd);
	scene->fd = open(scene->so, O_RDONLY);
	if (scene->fd < 0)
		return (0);
	close(scene->fd);
	scene->fd = open(scene->we, O_RDONLY);
	if (scene->fd < 0)
		return (0);
	close(scene->fd);
	scene->fd = open(scene->ea, O_RDONLY);
	if (scene->fd < 0)
		return (0);
	close(scene->fd);
	return (1);
}

static int	check_and_parse_floor(t_scene *scene, int i)
{
	if (ft_strncmp(scene->scene_lines[i], "F ", 2) == 0)
	{
		if (scene->f >> 30 == 0)
		{
			scene->f = parse_color(ft_substr(scene->scene_lines[i], \
			ft_strchr(scene->scene_lines[i], ' ') - \
			scene->scene_lines[i] + 1, \
			ft_strlen(scene->scene_lines[i])));
			scene->f = (1 << 30 | scene->f);
		}
		else
		{
			throw_err(COLORS_INVALID);
			return (0);
		}
	}
	return (1);
}

static int	check_and_parse_celling(t_scene *scene, int i)
{
	if (ft_strncmp(scene->scene_lines[i], "C ", 2) == 0)
	{
		if (scene->c >> 30 == 0)
		{
			scene->c = parse_color(ft_substr(scene->scene_lines[i], \
			ft_strchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] \
			+ 1, ft_strlen(scene->scene_lines[i])));
			scene->c = (1 << 30 | scene->c);
		}
		else
		{
			throw_err(COLORS_INVALID);
			return (0);
		}
	}
	return (1);
}

/*
Scans for colors for floor and celling in .cub scene file.
Checks if there is only one color for possible locales.
Checks if there are colors for possible locales.
*/

int	feed_scene_floor_and_celling(t_scene *scene)
{
	size_t	i;

	i = 0;
	while (scene->scene_lines[i])
	{
		if (!check_and_parse_floor(scene, i))
			return (0);
		if (!check_and_parse_celling(scene, i))
			return (0);
		i++;
	}
	if (scene->f >> 31 == 1 || scene->c >> 31 == 1)
	{
		throw_err(COLORS_INVALID);
		return (0);
	}
	return (1);
}
