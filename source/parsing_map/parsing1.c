/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_map_name_check(t_cub *c, char *map_path)
{
	int	l;

	l = ft_strlen(map_path);
	if (l < 4 || map_path[l - 4] != '.' || map_path[l - 3] != 'c' \
		|| map_path[l - 2] != 'u' || map_path[l - 1] != 'b')
		ft_error(c, "non valid name of map!\n", 1);
}

int	ft_empty_or_only_spaces_str(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = -1;
	while (str[++i])
		if (str[i] != ' ')
			return (0);
	return (1);
}

int	ft_begins_with_valid_xpm_name(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == ' ')
		i++;
	if (!ft_strncmp(str + i, "NO", 2))
		return (1);
	if (!ft_strncmp(str + i, "SO", 2))
		return (2);
	if (!ft_strncmp(str + i, "WE", 2))
		return (3);
	if (!ft_strncmp(str + i, "EA", 2))
		return (4);
	return (0);
}

int	ft_valid_xpm_names(t_cub *c, char *map_path, char *buff, int cnt)
{
	int	rt;
	int	fd;

	rt = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		ft_error(c, "unable to open map!\n", 1);
	while (true)
	{
		ft_strfree(buff);
		buff = get_next_line(fd);
		if (!buff)
			break ;
		if (ft_empty_or_only_spaces_str(buff))
			continue ;
		if (ft_begins_with_valid_xpm_name(buff) == 0)
			break ;
		cnt++;
		rt += ft_begins_with_valid_xpm_name(buff);
	}
	ft_strfree(buff);
	close(fd);
	if (cnt == 4 && rt == 1 + 2 + 3 + 4)
		return (1);
	return (ft_error(c, "invalid xmp names in map!\n", 1));
}
