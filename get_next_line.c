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
	// tests if there's any issue on file descriptors.
	if (read(fd, NULL, 0) < 0)
	{
		// If the file descriptor is valid and it's not the EOF or end of BUFFER_SIZE, it will clean the buffer and return NULL.
		while (fd >= 0 && fd <= FOPEN_MAX && (buffer[i] || i < BUFFER_SIZE))
			buffer[i++] = '\0';
		// If the file descriptor is invalid, it will just return NULL.
		return (NULL);
	}
	/* if the first element of the buffer array is not NULL or while the read function returns value greater than 0,
	the function will concatenate what's left on the result line and what was read on the buffer. (strlen and strjoin will consider '\n' as a limit.
	Then, the organize function will clean the buffer until the '\n' and put a new index pointing to the first element after '\n' copying its content before cleaning.
	In the end, if there's a '\n', it will return 1 and break.*/
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		result_line = ft_strjoin_nl(result_line, buffer);
		if (ft_organize_buffer(buffer) == 1)
			break ;
	}
	// Return the concatenated str until the '\n' + '\0'.
	// If the return value of read is 0 or -1, it will return the result_line as it was before (NULL or line).
	return (result_line);
}
