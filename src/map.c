/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:21:04 by cbignon           #+#    #+#             */
/*   Updated: 2021/11/18 18:11:59 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map_char(char *line, t_data *data, int line_n)
{
	int	i;

	i = 0;
	data->map->width = ft_strlen(line);
	if (line[0] != '1' || line[data->map->width - 1] != '1')
		data->map->error++;
	while (i < data->map->width)
	{
		if (line[i] == 'P')
		{
			data->map->pl++;
			data->player->x = line_n - 1;
			data->player->y = i;
		}
		else if (line[i] == 'E')
			data->map->exit++;
		else if (line[i] == 'C')
			data->map->coll++;
		else if (line[i] != '0' && line[i] != '1' && line[i] != 'P' &&
			line[i] != 'E' && line[i] != 'C')
			data->map->error++;
		i++;
	}
}

void	check_map_size(char **argv, t_data *data)
{
	int		fd;
	int		ret;
	char	*line;
	int		line_n;

	fd = open(argv[1], O_RDONLY);
	ret = 1;
	line_n = 0;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (data->map->map_row == 0)
			data->map->map_row = ft_strlen(line);
		else if (data->map->map_row > 0)
			if ((int)ft_strlen(line) != data->map->map_row)
				data->map->error++;
		data->map->map_line++;
		line_n++;
		valid_map_char(line, data, line_n);
		if (line)
			free(line);
	}
	data->map->map2d = (char **)malloc(sizeof(char *) * ((data->map->map_line) + 1));
	if (!data->map->map2d)
		data->map->error++;
	close(fd);
}

void	map_is_closed(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->map->map_row)
	{
		if (data->map->map2d[0][j] != '1')
		{
			data->map->error++;
			return ;
		}
		else
			j++;
	}
	j = 0;
	while (j < data->map->map_row)
	{
		if (data->map->map2d[(data->map->map_line - 1)][j] != '1')
		{
			data->map->error++;
			return ;
		}
		else
			j++;
	}
}

int	check_map(char **argv, t_data *data)
{
	int		fd;
	char	*line;
	int		ret;
	int		i;

	i = -1;
	fd = open(argv[1], O_RDONLY);
	check_map_size(argv, data);
	line = NULL;
	ret = 1;
	if (fd == -1)
		return (ft_map_error(1, data));
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		data->map->map2d[++i] = ft_strdup(line);
		if (line)
			free(line);
	}
	data->map->map2d[i + 1] = NULL;
	map_is_closed(data);
	if (data->map->pl != 1 || data->map->exit == 0 || data->map->coll == 0
		|| data->map->error > 0)
	{
		close(fd);
		return (ft_map_error(2, data));
	}
	data->map->height = data->map->map_line * 32;
	data->map->width = data->map->map_row * 32;
	return (0);
}
