/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:00:17 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/15 21:55:01 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	check_horizontal_walls(t_scene *scene, int map_len)
{
	int	i;

	i = 0;
	while (scene->map[0][i])
	{
		if (scene->map[0][i] == '1' || scene->map[0][i] == ' ')
			i++;
		else
			return (0);
	}
	i = 0;
	while (scene->map[map_len - 1][i])
	{
		if (scene->map[map_len - 1][i] == '1' ||
				scene->map[map_len - 1][i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_vertical_walls(t_scene *scene, int map_len)
{
	int	i;

	i = 1;
	while (i < map_len - 1)
	{
		if ((scene->map[i][0] != '1' && scene->map[i][0] != ' ')
		|| (scene->map[i][ft_strlen(scene->map[i]) - 1] != '1' &&
		scene->map[i][ft_strlen(scene->map[i]) - 1] != ' '))
			return (0);
		i++;
	}
	return (1);
}

int	is_map_walled(t_scene *scene)
{
	int	map_len;

	map_len = 0;
	while (scene->map[map_len])
		map_len++;
	if (!check_horizontal_walls(scene, map_len))
		return (0);
	if (!check_vertical_walls(scene, map_len))
		return (0);
	return (1);
}

int	are_map_chars_valid_utils(t_scene *scene, size_t i, size_t j)
{
	if (!ft_strchr(VALID_CHARS, scene->map[i][j]))
		return (0);
	if (ft_strchr(VALID_CHAR_V, scene->map[i][j])
				&& (ft_strlen(scene->map[i - 1]) < j + 1
				|| ft_strlen(scene->map[i + 1]) < j + 1
				|| ft_strlen(scene->map[i]) == j + 1))
		return (0);
	if (ft_strchr(VALID_CHAR_V, scene->map[i][j]) && (!ft_strchr(VALID_CHAR_0,
						scene->map[i - 1][j]) || !ft_strchr(VALID_CHAR_0,
						scene->map[i + 1][j]) || !ft_strchr(VALID_CHAR_0,
						scene->map[i][j - 1]) || !ft_strchr(VALID_CHAR_0,
						scene->map[i][j + 1])))
		return (0);
	return (1);
}

/* vpc_count = valid_player_char_count  */
int	are_map_players_valid(t_scene *scene)
{
	int	i;
	int	j;
	int	vpc_count;

	i = 0;
	vpc_count = 0;
	while (scene->map[i])
	{
		j = 0;
		while (scene->map[i][j])
		{
			if (ft_strchr(VALID_PLAYER_CHARS, scene->map[i][j]))
			{
				if (vpc_count == 0)
					vpc_count += init_player(scene, i, j, scene->map[i][j]);
				else
					vpc_count++;
			}
			j++;
		}
		i++;
	}
	if (vpc_count != 1)
		return (0);
	return (1);
}
