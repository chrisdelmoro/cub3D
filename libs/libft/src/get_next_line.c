/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:08:30 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/03 20:44:58 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static void	freethis(char **str, void *content)
{
	if (*str)
	{
		free(*str);
		*str = (char *) content;
	}
}

static int	feed_accumulator(char **accumulator, int fd)
{
	char	*tmp;
	char	*buffer;
	int		read_count;

	buffer = (char *) malloc(BUFFER_SIZE + 1 * sizeof(char));
	read_count = read(fd, buffer, BUFFER_SIZE);
	if (read_count <= 0)
	{
		freethis(&buffer, NULL);
		return (read_count);
	}
	buffer[read_count] = '\0';
	tmp = *accumulator;
	*accumulator = ft_strjoin(tmp, buffer);
	freethis(&tmp, NULL);
	freethis(&buffer, NULL);
	return (read_count);
}

static void	close_line_n(char **accumulator, char **line, int read_count)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while ((*accumulator)[i] != '\n' && (*accumulator)[i])
		i++;
	*line = ft_substr(*accumulator, 0, i + 1);
	tmp = *accumulator;
	if (read_count > 0)
		*accumulator = ft_substr(tmp, i + 1, ft_strlen(tmp));
	freethis(&tmp, NULL);
}

static int	close_gnl(char **accumulator, char **line, int read_count)
{
	if (ft_strchr(*accumulator, '\n'))
	{
		close_line_n(&*accumulator, &*line, read_count);
		if (ft_strlen(*accumulator) == 0)
		{
			freethis(&*accumulator, NULL);
			*accumulator = ft_strdup("");
		}
	}
	else
	{
		if (!ft_strlen(*accumulator) && read_count == 0)
			return (0);
		*line = ft_strdup(*accumulator);
		freethis(&*accumulator, NULL);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*accumulator[OPEN_MAX];
	char		*line;
	int			read_count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!accumulator[fd])
		accumulator[fd] = ft_strdup("");
	read_count = BUFFER_SIZE;
	while (read_count > 0 && !ft_strchr(accumulator[fd], '\n'))
	{
		read_count = feed_accumulator(&accumulator[fd], fd);
		if (read_count <= 0 && !ft_strlen(accumulator[fd]))
		{
			freethis(&accumulator[fd], NULL);
			return (NULL);
		}
	}
	if (!close_gnl(&accumulator[fd], &line, read_count))
		return (NULL);
	return (line);
}
