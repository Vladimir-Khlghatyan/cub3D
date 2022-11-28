/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_begins_with_valid_color_name(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == ' ')
		i++;
	if (!ft_strncmp(str + i, "F", 1))
		return (1);
	if (!ft_strncmp(str + i, "C", 1))
		return (2);
	return (0);
}

int	ft_valid_color_names(char *map_path, char *buff, int cnt, int rt)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		ft_error("unable to open map!\n", 1);
	while (1)
	{
		ft_strfree(buff);
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (ft_empty_or_only_spaces_str(buff) || \
			ft_begins_with_valid_xpm_name(buff))
			continue ;
		if (ft_begins_with_valid_color_name(buff) == 0)
			break ;
		cnt++;
		rt += ft_begins_with_valid_color_name(buff);
	}
	ft_strfree(buff);
	close(fd);
	if (cnt == 2 && rt == 1 + 2)
		return (1);
	ft_error("invalid color names in map!\n", 1);
	return (0);
}
