/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:21 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/24 13:36:08 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_args(void)
{
	ft_printf(FILE_MSG);
	return (TRUE);
}

int	print_usage(void)
{
	// write(1, "Usage: ./Game <name>.ber\n", 25);
	ft_printf("Usage: ./Game <name>.ber\n");
	return (TRUE);
}

int	components_error(char *map_string)
{
	ft_printf(MIN_TILES_MSG);
	free(map_string);
	return (TRUE);
}

int	structure_error(t_map *map)
{
	ft_printf(STRUCT_MSG);
	free(map->player);
	break_struct(map);
	return (TRUE);
}

int	no_valid_path(t_map *map)
{
	ft_printf(PATH_MSG);
	break_struct(map);
	return (TRUE);
}

int	empty_map(char *map_string)
{
	ft_printf(EMPTY_MSG);
	free(map_string);
	return (TRUE);
}
