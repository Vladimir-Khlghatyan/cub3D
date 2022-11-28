/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:38:22 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/10/31 00:56:55 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# if defined(linux) || defined(__linux)
#  define RED_CROSS	17
#  define KEY_SPACE	32
#  define KEY_A 	97
#  define KEY_D 	100
#  define KEY_S 	115
#  define KEY_W 	119
#  define KEY_ESC 	65307
#  define KEY_LEFT 	65361
#  define KEY_UP 	65362
#  define KEY_RIGHT 65363
#  define KEY_DOWN 	65364
# else
#  define KEY_A 	0
#  define KEY_S 	1
#  define KEY_D 	2
#  define KEY_W 	13
#  define RED_CROSS	17
#  define KEY_SPACE	49
#  define KEY_ESC 	53
#  define KEY_LEFT 	123
#  define KEY_RIGHT 124
#  define KEY_DOWN 	125
#  define KEY_UP 	126
# endif

#endif
