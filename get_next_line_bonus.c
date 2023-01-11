/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vballe <vballe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:05:22 by vballe            #+#    #+#             */
/*   Updated: 2023/01/11 14:49:23 by vballe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*result_line;
	int			i;

	result_line = NULL;
	i = 0;
	if (read(fd, NULL, 0) < 0)
	{
		while (fd >= 0 && fd <= FOPEN_MAX && (buffer[fd][i] || i < BUFFER_SIZE))
			buffer[fd][i++] = '\0';
		return (NULL);
	}
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		result_line = ft_strjoin_nl(result_line, buffer[fd]);
		if (ft_organize_buffer(buffer[fd]) == 1)
			break ;
	}
	return (result_line);
}
