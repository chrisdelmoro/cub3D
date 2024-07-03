/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:28:33 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/15 21:52:42 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	open_fd(t_scene *scene, char *map_path)
{
	scene->fd = open(map_path, O_RDONLY);
	if (scene->fd < 0)
	{
		throw_err(MAP_NONEXISTENT);
		return (0);
	}
	return (1);
}

static int	count_lines(t_scene *scene, char *map_path, int line_count)
{
	char	*gnl_line;
	t_bool	b;

	b = TRUE;
	if (!open_fd(scene, map_path))
		return (-1);
	gnl_line = get_next_line(scene->fd);
	while (gnl_line)
	{
		b = FALSE;
		line_count++;
		if (ft_strchr(gnl_line, '\n'))
			b = TRUE;
		ft_freethis(&gnl_line, NULL);
		gnl_line = get_next_line(scene->fd);
	}
	ft_freethis(&gnl_line, NULL);
	close(scene->fd);
	if (b == TRUE)
		return (-1);
	return (line_count);
}

static int	feed_scene_lines(t_scene *scene, char *map_path, int line_count)
{
	char	*treated_line;
	char	*gnl_line;

	if (!open_fd(scene, map_path))
		return (0);
	gnl_line = get_next_line(scene->fd);
	while (gnl_line)
	{
		if (ft_strrchr(gnl_line, '\n'))
		{
			treated_line = ft_substr(gnl_line, 0, ft_strrchr(gnl_line, '\n') \
			- gnl_line);
			ft_freethis(&gnl_line, NULL);
			scene->scene_lines[line_count] = treated_line;
		}
		else
			scene->scene_lines[line_count] = gnl_line;
		gnl_line = get_next_line(scene->fd);
		line_count++;
	}
	ft_freethis(&gnl_line, NULL);
	close(scene->fd);
	return (1);
}

int	initialize_scene(t_scene *scene, char *map_path)
{
	int		line_count;

	scene->no = NULL;
	scene->so = NULL;
	scene->we = NULL;
	scene->ea = NULL;
	scene->f = 0;
	scene->c = 0;
	scene->map = NULL;
	scene->scene_lines = NULL;
	scene->player = NULL;
	line_count = count_lines(scene, map_path, 0);
	if (line_count < 1)
		return (0);
	scene->scene_lines = (char **) ft_calloc(line_count + 1, sizeof(char *));
	if (!scene->scene_lines)
		return (0);
	if (!feed_scene_lines(scene, map_path, 0))
		return (0);
	return (1);
}
