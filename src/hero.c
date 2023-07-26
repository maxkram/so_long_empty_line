/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:30 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/26 17:04:23 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	hero_is_on_exit(t_data **data)
{
	mlx_instance_t	*player;
	mlx_instance_t	*exit;

	player = &(*data)->hero_box->instances[0];
	exit = &(*data)->tiles->exit_image[0]->instances[0];
	if (player->x == exit->x && player->y == exit->y)
		return (1);
	return (0);
}

int	check_valid_move(t_data *data, t_position *position)
{
	mlx_instance_t	*player;
	int				posx;
	int				posy;

	posx = position->x;
	posy = position->y;
	player = data->hero_box->instances;
	posx = posx + player->x / SIZE;
	posy = posy + player->y / SIZE;
	if (data->map[posy][posx] != '1')
		return (1);
	return (0);
}

void	init_moves(t_data **data)
{
	(*data)->game_move[0] = (t_position *)malloc(sizeof(t_position));
	(*data)->game_move[1] = (t_position *)malloc(sizeof(t_position));
	(*data)->game_move[2] = (t_position *)malloc(sizeof(t_position));
	(*data)->game_move[3] = (t_position *)malloc(sizeof(t_position));
	(*data)->game_move[4] = NULL;
	(*data)->game_move[0]->x = 0;
	(*data)->game_move[0]->y = -1;
	(*data)->game_move[1]->x = 0;
	(*data)->game_move[1]->y = 1;
	(*data)->game_move[2]->x = 1;
	(*data)->game_move[2]->y = 0;
	(*data)->game_move[3]->x = -1;
	(*data)->game_move[3]->y = 0;
}
