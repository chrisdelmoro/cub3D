/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_textures_and_colors_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:09:03 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/15 19:33:58 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	check_and_parse_no(t_scene *scene, int i)
{
	if (ft_strncmp(scene->scene_lines[i], "NO ", 3) == 0)
	{
		if (scene->no == NULL)
			scene->no = ft_substr(scene->scene_lines[i], \
		ft_strrchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, \
		ft_strlen(scene->scene_lines[i]));
		else
		{
			throw_err(TEXTURES_INVALID);
			return (0);
		}
	}
	return (1);
}

static int	check_and_parse_so(t_scene *scene, int i)
{
	if (ft_strncmp(scene->scene_lines[i], "SO ", 3) == 0)
	{
		if (scene->so == NULL)
			scene->so = ft_substr(scene->scene_lines[i], \
		ft_strrchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, \
		ft_strlen(scene->scene_lines[i]));
		else
		{
			throw_err(TEXTURES_INVALID);
			return (0);
		}
	}
	return (1);
}

static int	check_and_parse_we(t_scene *scene, int i)
{
	if (ft_strncmp(scene->scene_lines[i], "WE ", 3) == 0)
	{
		if (scene->we == NULL)
			scene->we = ft_substr(scene->scene_lines[i], \
		ft_strrchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, \
		ft_strlen(scene->scene_lines[i]));
		else
		{
			throw_err(TEXTURES_INVALID);
			return (0);
		}
	}
	return (1);
}

static int	check_and_parse_ea(t_scene *scene, int i)
{
	if (ft_strncmp(scene->scene_lines[i], "EA ", 3) == 0)
	{
		if (scene->ea == NULL)
			scene->ea = ft_substr(scene->scene_lines[i], \
		ft_strrchr(scene->scene_lines[i], ' ') - scene->scene_lines[i] + 1, \
		ft_strlen(scene->scene_lines[i]));
		else
		{
			throw_err(TEXTURES_INVALID);
			return (0);
		}
	}
	return (1);
}

/*
Scans for textures path in .cub scene file.
Checks if there is only one texture per cardinal direction.
Checks if there are textures for all cardinal directions.
*/

int	feed_scene_textures(t_scene *scene)
{
	size_t	i;

	i = 0;
	while (scene->scene_lines[i])
	{
		if (!check_and_parse_no(scene, i))
			return (0);
		if (!check_and_parse_so(scene, i))
			return (0);
		if (!check_and_parse_we(scene, i))
			return (0);
		if (!check_and_parse_ea(scene, i))
			return (0);
		i++;
	}
	return (final_scene_checks(scene));
}
