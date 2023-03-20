/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanas <tanas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:21:35 by tanas             #+#    #+#             */
/*   Updated: 2023/01/10 17:12:21 by tanas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// finds a line and returns it
char	*get_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *) malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

// reads the file and then stores the read content in the stash
char	*read_file(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

// updates the stash by removing the line that was returned before,
// frees stash and returns NULL once EOF is reached
char	*update_stash(char *old_stash)
{
	char	*updated_stash;
	int		i;
	int		j;

	i = 0;
	while (old_stash[i] && old_stash[i] != '\n')
		i++;
	if (!old_stash[i])
	{
		free(old_stash);
		return (NULL);
	}
	updated_stash = (char *) malloc(ft_strlen(old_stash) - i + 1);
	if (!updated_stash)
		return (NULL);
	i++;
	j = 0;
	while (old_stash[i])
		updated_stash[j++] = old_stash[i++];
	updated_stash[j] = '\0';
	free(old_stash);
	return (updated_stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	stash = update_stash(stash);
	return (line);
}
