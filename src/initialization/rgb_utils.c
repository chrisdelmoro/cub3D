/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:50:51 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/14 16:16:17 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static int	is_rgb_valid(char *RGB)
{
	int	i;

	i = 0;
	while (RGB[i])
	{
		if (ft_isdigit(RGB[i]) == 0 && RGB[i] != ',' && RGB[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static char	*catch_next_color(char *next_color)
{
	int	i;
	int	j;

	i = 0;
	while (!ft_isdigit(next_color[i]))
		i++;
	j = i;
	while (ft_isdigit(next_color[j]))
		j++;
	return (ft_substr(next_color, i, j));
}

static void	free_rgb(char *RGB, char *r, char *g, char *b)
{
	ft_freethis(&r, NULL);
	ft_freethis(&g, NULL);
	ft_freethis(&b, NULL);
	ft_freethis(&RGB, NULL);
}

//parse_color
unsigned int	parse_color(char *RGB)
{
	char			*r;
	char			*g;
	char			*b;
	unsigned int	color;

	if (!is_rgb_valid(RGB))
	{
		ft_freethis(&RGB, NULL);
		return (1 << 31);
	}
	r = ft_substr(RGB, 0, ft_strchr(RGB, ',') - RGB);
	g = catch_next_color(ft_strchr(RGB, ',') + 1);
	b = ft_substr(RGB, ft_strrchr(RGB, ',') - RGB + 1, ft_strlen(RGB));
	if ((ft_atoi(r) > 255 || ft_atoi(g) > 255 || ft_atoi(b) > 255) || \
	(ft_atoi(r) < 0 || ft_atoi(g) < 0 || ft_atoi(b) < 0))
	{
		free_rgb(RGB, r, g, b);
		return (1 << 31);
	}
	color = create_rgb(ft_atoi(r), ft_atoi(g), ft_atoi(b));
	free_rgb(RGB, r, g, b);
	return (color);
}
