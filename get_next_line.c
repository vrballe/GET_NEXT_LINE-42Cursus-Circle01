/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vballe <vballe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:13:06 by vballe            #+#    #+#             */
/*   Updated: 2023/01/11 15:05:22 by vballe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result_line;
	int			i;

	i = 0;
	result_line = NULL;
	if (read(fd, NULL, 0) < 0)
	{
		while (buffer[i] || i < BUFFER_SIZE)
			buffer[i++] = '\0';
		return (NULL);
	}
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		result_line = ft_strjoin_nl(result_line, buffer);
		if (ft_organize_buffer(buffer) == 1)
			break ;
	}
	return (result_line);
}
