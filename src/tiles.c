/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:37 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/26 17:00:09 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_tile_images(t_data **data)
{
	t_texture	*tiles;
	mlx_t		*mlx;

	mlx = (*data)->mlx;
	tiles = (*data)->tiles;
	tiles->floor_image = mlx_texture_to_image(mlx, tiles->floor);
	tiles->wall_image = mlx_texture_to_image(mlx, tiles->wall);
	tiles->exit_image[0] = mlx_texture_to_image(mlx, tiles->exit[0]);
	tiles->exit_image[1] = mlx_texture_to_image(mlx, tiles->exit[1]);
	tiles->hero_image = mlx_texture_to_image(mlx, tiles->hero);
}

void	init_tile_textures(t_data **data)
{
	t_texture	*tiles;

	(*data)->tiles = (t_texture *)malloc(sizeof(t_texture));
	tiles = (*data)->tiles;
	tiles->floor = mlx_load_png("assets/floor.png");
	tiles->wall = mlx_load_png("assets/wall.png");
	tiles->hero = mlx_load_png("assets/hero.png");
	tiles->exit[0] = mlx_load_png("assets/close.png");
	tiles->exit[1] = mlx_load_png("assets/open.png");
	tiles->exit[2] = NULL;
	load_tile_images(data);
	delete_tile_textures(data);
}
