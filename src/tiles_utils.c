/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:36 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/26 17:03:30 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	delete_tile_textures(t_data **data)
{
	t_texture	*tiles;

	tiles = (*data)->tiles;
	mlx_delete_texture(tiles->floor);
	mlx_delete_texture(tiles->wall);
	mlx_delete_texture(tiles->exit[0]);
	mlx_delete_texture(tiles->exit[1]);
	mlx_delete_texture(tiles->hero);
}

void	destroy_movements(t_data **data)
{
	free((*data)->game_move[0]);
	free((*data)->game_move[1]);
	free((*data)->game_move[2]);
	free((*data)->game_move[3]);
}

void	break_tile_struct(t_data **data)
{
	t_texture	*image;

	image = (*data)->tiles;
	free(image);
}
