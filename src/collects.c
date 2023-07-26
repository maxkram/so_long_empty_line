/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collects.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:04 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/26 15:50:56 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_collectible_count(char *map)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (map[++i])
		if (map[i] == 'C')
			count++;
	return (count);
}

void	free_and_remove_image(t_data **data, mlx_image_t *image, t_list *head)
{
	t_list	*temp;

	temp = head->next;
	mlx_delete_image((*data)->mlx, image);
	free(temp);
}

void	remove_collect(t_data **data)
{
	t_list	*tmp;
	t_list	*prev;
	int		pos_y;
	int		pos_x;

	pos_x = (*data)->hero_box->instances[0].x / SIZE;
	pos_y = (*data)->hero_box->instances[0].y / SIZE;
	tmp = (*data)->collectible_list;
	if (tmp->x == pos_x && tmp->y == pos_y)
	{
		(*data)->collectible_list = tmp->next;
		mlx_delete_image((*data)->mlx, tmp->position);
		free(tmp);
		return ;
	}
	while (tmp != NULL && !(tmp->x == pos_x && tmp->y == pos_y))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = tmp->next;
	mlx_delete_image((*data)->mlx, tmp->position);
	free(tmp);
}

void	player_is_on_colectible(t_data **data)
{
	mlx_instance_t	*player;
	int				pos_x;
	int				pos_y;

	player = (*data)->hero_box->instances;
	pos_x = player[0].x / SIZE;
	pos_y = player[0].y / SIZE;
	if ((*data)->map[pos_y][pos_x] == 'C')
	{
		(*data)->map[pos_y][pos_x] = '0';
		remove_collect(data);
	}
}

void	all_collected(t_data *data)
{
	mlx_image_t		*exit_closed;
	mlx_image_t		*exit_opened;

	if (!data->collectible_list)
	{
		exit_closed = data->tiles->exit_image[0];
		exit_opened = data->tiles->exit_image[1];
		ft_memcpy(exit_closed->pixels, exit_opened->pixels,
			SIZE * SIZE * 4);
	}
}
