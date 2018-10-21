/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:59:15 by mfiguera          #+#    #+#             */
/*   Updated: 2018/05/26 19:01:21 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

t_room		**linkjoin(t_room **list, t_room *new, int nl)
{
	t_room	**ret;
	int		i;

	i = 0;
	ret = (t_room**)malloc(sizeof(t_room*) * (nl + 1));
	while (list && i < nl)
	{
		ret[i] = list[i];
		i++;
	}
	ret[i] = new;
	if (list)
		free(list);
	return (ret);
}

void		link_rooms(t_room *input, char **info, t_map map)
{
	t_room	*rooms;

	rooms = input;
	while (rooms)
	{
		if (!ft_strcmp(rooms->name, info[0]))
			break ;
		rooms = rooms->next;
	}
	while (input)
	{
		if (!ft_strcmp(input->name, info[1]))
			break ;
		input = input->next;
	}
	free(info[0]);
	free(info[1]);
	free(info);
	if (!input || !rooms || input == rooms)
		error(9, map);
	rooms->linked = linkjoin(rooms->linked, input, rooms->nl++);
	input->linked = linkjoin(input->linked, rooms, input->nl++);
}

void		new_room(t_map *map, char **info, int type)
{
	t_room	*node;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	node = (t_room*)malloc(sizeof(t_room));
	node->name = ft_strdup(info[0]);
	!(ft_isnumstr(info[1]) && ft_isnumstr(info[2])) ? ret = 1 : 0;
	node->x = ft_atoi(info[1]);
	node->y = ft_atoi(info[2]);
	node->next = map->first;
	node->type = type;
	node->linked = NULL;
	node->nl = 0;
	node->seen = 0;
	map->first = node;
	while (i < 3)
		free(info[i++]);
	free(info);
	if (ret)
		error(10, *map);
}

int			parsing_manager(t_map *map, char *line, int *stage)
{
	static int	type;

	if (!line || !map || !stage)
		return (-1);
	if (*stage == 0 && line[0] != '#' && ft_isnumstr(line) && (*stage = 1))
		map->ants = ft_atoi(line);
	else if (*stage == 1 && line[0] != '#' && ft_wordcount(line, ' ') == 3)
	{
		new_room(map, ft_strsplit(line, ' '), type);
		type = NORMAL;
	}
	else if (line[0] != '#' && (*stage == 2 || (*stage == 1 &&
			ft_wordcount(line, ' ') == 1)) && ft_wordcount(line, '-') == 2)
	{
		link_rooms(map->first, ft_strsplit(line, '-'), *map);
		*stage = 2;
	}
	else if (line[0] == '#')
	{
		!ft_strcmp(line, "##start") ? type = START : 0;
		!ft_strcmp(line, "##end") ? type = END : 0;
	}
	else
		return (1);
	return (0);
}
