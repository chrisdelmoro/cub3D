/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_textures_and_colors_3.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:19:25 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/14 17:19:36 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	final_scene_checks(t_scene *scene)
{
	if (!scene->no || !scene->so || !scene->we || !scene->ea)
	{
		throw_err(TEXTURES_INVALID);
		return (0);
	}
	if (!check_textures_exist(scene))
	{
		throw_err(TEXTURES_INVALID);
		return (0);
	}
	return (1);
}
