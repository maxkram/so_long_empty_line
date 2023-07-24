/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:33 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/24 16:50:01 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	free_and_return(void *memory)
{
	free(memory);
	return (TRUE);
}

int	get_map_size(char *map)
{
	int		fd;
	char	*buffer;
	int		read_byte;
	int		total_bytes;

	total_bytes = 0;
	fd = open (map, O_RDONLY);
	buffer = malloc(100);
	read_byte = read(fd, buffer, 100);
	// if (read_byte == -1)
	// 		return (free_and_return(buffer));
	if (read_byte <= 0)
		return (free_and_return(buffer));
	total_bytes += read_byte;
	while (read_byte != 0)
	{
		read_byte = read(fd, buffer, 100);
		total_bytes += read_byte;
	}
	close(fd);
	free(buffer);
	return (total_bytes);
}

char	*read_map(char *map)
{
	int		file;
	int		bytes;
	char	*map_b;

	bytes = get_map_size(map) + 1;
	map_b = ft_calloc(sizeof(char), bytes);
	file = open(map, O_RDONLY);
	read(file, map_b, bytes);
	close(file);
	return (map_b);
}
