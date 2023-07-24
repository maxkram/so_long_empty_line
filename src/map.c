/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:27 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/23 21:01:16 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_component(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if ((str[i] == 'E' || str[i] == 'P') || str[i] == 'C')
			return (TRUE);
	return (FALSE);
}

int	contains_component(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		if (check_component(map[i]))
			return (TRUE);
	return (FALSE);
}

int	broken_path(t_map *map)
{
	check_map_path(map);
	ft_lstclear(&map->double_visited, free);
	if (contains_component(map->map))
		return (TRUE);
	return (FALSE);
}

int	empty(char *map_string)
{
	if (map_string[0] == 0)
		return (TRUE);
	return (FALSE);
}

int	map_with_errors(char *argv)
{
	char	*map_string;
	t_map	*map;

	if (broken_map_name(argv))
		return (TRUE);
	map_string = read_map(argv);
	if (empty(map_string))
		return (empty_map(map_string));
	if (broken_components(map_string))
		return (components_error(map_string));
	map = init_structure(map_string);
	free(map_string);
	if (broken_map(map->map))
		return (structure_error(map));
	if (broken_path(map))
		return (no_valid_path(map));
	break_struct(map);
	return (FALSE);
}
