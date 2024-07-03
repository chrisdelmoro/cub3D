/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:47:18 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/15 21:56:00 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_scene_valid(char *map_path, t_scene *scene)
{
	if (!initialize_scene(scene, map_path))
	{
		throw_err(END_LINE_INVALID);
		return (0);
	}
	if (!feed_scene_textures(scene) || !feed_scene_floor_and_celling(scene) || \
	!feed_scene_map(scene))
		return (0);
	return (1);
}
