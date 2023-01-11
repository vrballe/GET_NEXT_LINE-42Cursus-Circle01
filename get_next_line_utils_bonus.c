/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vballe <vballe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:22:47 by vballe            #+#    #+#             */
/*   Updated: 2023/01/11 13:33:44 by vballe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_nl(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str && str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_nl(char *s1, char *s2)
{
	char	*conc_str;
	int		i;
	int		aux;

	conc_str = malloc((ft_strlen_nl(s1) + ft_strlen_nl(s2) + 1) * sizeof(char));
	if (!conc_str)
		return (NULL);
	i = 0;
	aux = 0;
	while (s1 && s1[i] != '\0')
		conc_str[aux++] = s1[i++];
	free (s1);
	i = 0;
	while (s2 && s2[i] != '\0' && s2[i] != '\n')
		conc_str[aux++] = s2[i++];
	if (s2[i] == '\n')
		conc_str[aux++] = s2[i];
	conc_str[aux] = '\0';
	return (conc_str);
}

int	ft_organize_buffer(char *buffer)
{
	int	check;
	int	i;
	int	aux;

	check = 0;
	i = 0;
	aux = 0;
	while (buffer[i] != '\0')
	{
		if (check == 1)
		buffer[aux++] = buffer[i];
		if (buffer[i] == '\n')
			check = 1;
		buffer[i] = '\0';
		i++;
	}
	return (check);
}
