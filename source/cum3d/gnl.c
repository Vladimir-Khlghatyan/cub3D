/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_add_char_to_buf(char *buf, char c)
{
	char	*new_buf;
	int		i;

	if (!buf)
	{
		buf = (char *)malloc(sizeof(char) * 2);
		if (!buf)
			return (NULL);
		buf[0] = c;
		buf[1] = '\0';
		return (buf);
	}
	new_buf = (char *)malloc(sizeof(char) * (ft_strlen(buf) + 2));
	if (!new_buf)
	{
		free(buf);
		return (NULL);
	}
	i = -1;
	while (buf[++i])
		new_buf[i] = buf[i];
	new_buf[i] = c;
	new_buf[i + 1] = '\0';
	free(buf);
	return (new_buf);
}

char	*get_next_line(int fd)
{
	int		rd;
	char	c;
	char	*buffer;

	buffer = NULL;
	while (true)
	{
		rd = read(fd, &c, 1);
		if (rd <= 0 || c == '\n')
			break ;
		buffer = ft_add_char_to_buf(buffer, c);
	}
	if (!buffer && rd == 1)
	{
		buffer = (char *)malloc(sizeof(char));
		buffer[0] = '\0';
	}
	return (buffer);
}
