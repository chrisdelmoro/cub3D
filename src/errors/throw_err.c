/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarecho <mcarecho@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:42:11 by ccamargo          #+#    #+#             */
/*   Updated: 2023/10/15 21:55:42 by mcarecho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

static void	print_model_colors(void)
{
	ft_printf("One or more colors could not be parsed correctly!\n");
	ft_printf("Only values from 0 to 255 are valid!\n");
	ft_printf("Only one color for the floor and one for the celling is \
valid!\n");
	ft_printf("Colors must be specified as follows:\n");
	ft_printf("F 255,255,0\n");
	ft_printf("C 0,255,255\n");
}

static void	print_model_textures(void)
{
	ft_printf("One or more textures could not be found on specified path, \
some file could not be open or there is more than one texture per \
position!\n\n");
	ft_printf("Textures must be specified as follows:\n");
	ft_printf("NO ./path_to_the_north_texture\n");
	ft_printf("SO ./path_to_the_south_texture\n");
	ft_printf("WE ./path_to_the_west_texture\n");
	ft_printf("EA ./path_to_the_east_texture\n");
}

void	throw_err(int err)
{
	ft_printf("Error\n");
	if (err == NUM_PARAM)
		ft_printf("Cub3D only accepts one parameter!\n");
	if (err == WRONG_FILE)
		ft_printf("Cub3D only accepts files of .cub type!\n");
	if (err == MAP_NONEXISTENT)
		ft_printf("Could not find scene file on specified path or file failed \
to open!\n");
	if (err == TEXTURES_INVALID)
		print_model_textures();
	if (err == COLORS_INVALID)
		print_model_colors();
	if (err == MAP_NOT_LAST)
		ft_printf("The map must come last on the scene file!\n");
	if (err == MAP_NOT_WALLED)
		ft_printf("The map must be fully walled!\n");
	if (err == MAP_CHARS_NOT_VALID)
		ft_printf("The map must only contain valid characters! (01NWSE )\n");
	if (err == MAP_PLAYERS_NOT_VALID)
		ft_printf("The map must only contain one player starting position!\n");
	if (err == MINILIB_FAILED_WINDOW)
		ft_printf("Minilib's windows failed to load!\n");
	if (err == MINILIB_FAILED_SPRITE)
		ft_printf("Minilib failed to load sprites\n");
	if (err == END_LINE_INVALID)
		ft_printf("The map must end without a line break\n");
}
