/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:38:33 by mkramer           #+#    #+#             */
/*   Updated: 2023/07/26 14:46:27 by mkramer          ###   ########.fr       */
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

int	first_line_length(char *str)
{
	int	i;
	int	first_line;

	i = 0;
	first_line = 0;
	while (str[i] != '\n')
	{
		first_line++;
		i++;
	}
	return (first_line);
}

int	ft_validate_line_length(char *str_map)
{
	int	i;
	int	count_first_line;
	int	count_other_lines;

	i = 0;
	count_first_line = 0;
	count_other_lines = 0;
	count_first_line = first_line_length(str_map);
	i = count_first_line;
	i++;
	while (str_map[i] != '\0')
	{
		if (str_map[i] == '\n')
		{
			if (count_other_lines != count_first_line)
				return (TRUE);
			count_other_lines = 0;
		}
		else
			count_other_lines++;
		i++;
	}
	return (FALSE);
}
