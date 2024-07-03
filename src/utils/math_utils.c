/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:52:22 by mcarecho          #+#    #+#             */
/*   Updated: 2023/10/14 16:04:07 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

float	fix_ang(float ang)
{
	ang = fmod(ang, 360.0);
	if (ang < 0)
		ang += 360.0;
	return (ang);
}

float	deg_to_rad(float deg)
{
	return (deg * (M_PI / 180));
}
