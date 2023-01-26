/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <vkhlghat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:46:00 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/04/11 18:57:00 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	ft_llnumlen(long long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len += 1;
		n = n / 10;
	}
	return (len);
}

char	*ft_lltoa(long long n)
{
	int		rem;
	int		len;
	char	*str;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_llnumlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
	{
		rem = n % 10;
		n = n / 10;
		if (rem < 0)
			rem = -rem;
		str[len] = rem + '0';
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
