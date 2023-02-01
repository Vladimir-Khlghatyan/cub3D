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

int	ft_valid_color_names(t_cub *c, char *map_path, char *b, int cnt)
{
	int	rt;
	int	fd;

	rt = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		ft_error(c, "unable to open map!\n", 1);
	while (true)
	{
		ft_strfree(b);
		b = get_next_line(fd);
		if (!b)
			break ;
		if (ft_empty_or_only_spaces_str(b) || ft_begins_with_valid_xpm_name(b))
			continue ;
		if (ft_begins_with_valid_color_name(b) == 0)
			break ;
		cnt++;
		rt += ft_begins_with_valid_color_name(b);
	}
	ft_strfree(b);
	close(fd);
	if (cnt == 2 && rt == 1 + 2)
		return (1);
	return (ft_error(c, "invalid color names in map!\n", 1));
}
