/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:25 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/24 17:27:59 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_data(t_data **data, char *argv)
{
	int	width;
	int	height;

	(*data)->map_string = read_map(argv);
	(*data)->map = ft_split((*data)->map_string, '\n');
	width = SIZE * ft_strlen(*(*data)->map);
	height = SIZE * arrlength((*data)->map);
	(*data)->mlx = mlx_init(width, height, "so_long", true);
	(*data)->img = mlx_new_image((*data)->mlx, width, height);
	(*data)->collectible_list = NULL;
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	init_moves(data);
}

void	ft_move(t_data *data, t_position *position)
{
	mlx_image_t		*player;
	mlx_image_t		*player_box;
	static int		move;

	player = data->tiles->player_img;
	player_box = data->player_box;
	if (check_valid_move(data, position))
	{
		player_box->instances[0].y += position->y * SIZE;
		player_box->instances[0].x += position->x * SIZE;
		player->instances[0].y += position->y * SIZE;
		player->instances[0].x += position->x * SIZE;
		move++;
		ft_printf("Player moves: ");
		ft_printf("%d", move);
		ft_printf("\n");
	}
}

void	hook(void *param)
{
	t_data	*data;

	data = param;
	player_is_on_colectible(&data);
	all_collected(data);
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_data			*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_move(data, data->game_movement[1]);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_move(data, data->game_movement[3]);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_move(data, data->game_movement[0]);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_move(data, data->game_movement[2]);
	if (hero_is_on_exit(&data) && !data->collectible_list)
	{
		ft_printf("\n>>>  Game over <<<\n");
		ft_printf("\n");
		mlx_close_window(data->mlx);
	}
}

void	loop(char *argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	init_data(&data, argv);
	draw_map(&data);
	mlx_key_hook(data->mlx, keyhook, data);
	mlx_loop_hook(data->mlx, hook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	if (data->collectible_list)
		list_clear(&data->collectible_list);
	break_and_free(&data);
	free(data);
}
