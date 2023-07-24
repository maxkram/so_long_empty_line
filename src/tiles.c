/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:37 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/24 14:42:53 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_tile_images(t_data **data)
{
	t_texture	*tiles;
	mlx_t		*mlx;

	mlx = (*data)->mlx;
	tiles = (*data)->tiles;
	tiles->floor_img = mlx_texture_to_image(mlx, tiles->floor);
	tiles->wall_img = mlx_texture_to_image(mlx, tiles->wall);
	tiles->exit_img[0] = mlx_texture_to_image(mlx, tiles->exit[0]);
	tiles->exit_img[1] = mlx_texture_to_image(mlx, tiles->exit[1]);
	tiles->player_img = mlx_texture_to_image(mlx, tiles->player);
}

void	init_tile_textures(t_data **data)
{
	t_texture	*tiles;

	(*data)->tiles = (t_texture *)malloc(sizeof(t_texture));
	tiles = (*data)->tiles;
	tiles->floor = mlx_load_png("assets/tiles/floor/floor.png");
	tiles->wall = mlx_load_png("assets/tiles/wall/wall.png");
	tiles->player = mlx_load_png("assets/player/1.png");
	tiles->exit[0] = mlx_load_png("assets/tiles/other/32.png");
	tiles->exit[1] = mlx_load_png("assets/tiles/other/34.png");
	tiles->exit[2] = NULL;
	load_tile_images(data);
	delete_tile_textures(data);
}
