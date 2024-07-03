/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:51:16 by ccamargo          #+#    #+#             */
/*   Updated: 2022/09/03 20:45:29 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <libft.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/**
 * @brief The get_next_line() function allocates (with malloc(3)) and returns a
 * new string, which is the current found line of the opened file.
 *
 * @param fd The file descriptor of the opened file.
 * 
 * @return (char *) Returns found line or NULL file ended or error occured.
 */
char	*get_next_line(int fd);

#endif
