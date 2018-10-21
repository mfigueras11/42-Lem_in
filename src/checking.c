/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:14:09 by mfiguera          #+#    #+#             */
/*   Updated: 2018/05/27 14:48:40 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

void	free_everything(t_map map)
{
	t_room	*tmp;
	t_sol	*tmp2;
	int		i;

	while (map.first)
	{
		tmp = map.first->next;
		free(map.first->name);
		(map.first->linked) ? free(map.first->linked) : 0;
		free(map.first);
		map.first = tmp;
	}
	i = 0;
	while (map.solution && i < map.solution->npaths)
	{
		free(map.solution->path[i]->room);
		free(map.solution->path[i++]);
	}
	while (map.solution)
	{
		tmp2 = map.solution->next;
		free(map.solution->path);
		free(map.solution);
		map.solution = tmp2;
	}
}

void	error(int errno, t_map map)
{
	ft_putstr("ERROR");
	if (errno == 1)
		ft_putstr(" - Some rooms share name or coordinates.");
	if (errno == 2)
		ft_printf("%s%s", " - Room names should not start with 'L' or",
				" '#' and/or not contain '-'.");
	if (errno == 3)
		ft_putstr(" - Map cannot contain empty lines.");
	if (errno == 5)
		ft_putstr(" - Empty map.");
	if (errno == 6)
		ft_putstr(" - Provide one (1) start and one (1) end.");
	if (errno == 7)
		ft_putstr(" - Make sure start and end are connected.");
	if (errno == 8)
		ft_putstr(" - Make sure to give a number of ants greater than 0.");
	if (errno == 9)
		ft_putstr(" - Invalid link.");
	if (errno == 10)
		ft_putstr(" - Coordinates must contain only digits.");
	ft_putchar('\n');
	free_everything(map);
	exit(1);
}

void	check_map2(t_map *map, int start, int end)
{
	if (map->ants <= 0)
		error(8, *map);
	if (start != 1 || end != 1)
		error(6, *map);
	map->rooms = map->first;
	map->solution = NULL;
	while (map->rooms && map->rooms->type != START)
		map->rooms = map->rooms->next;
}

void	check_map(t_map *map)
{
	t_room	*j;
	t_room	*i;
	int		start;
	int		end;

	start = 0;
	end = 0;
	i = map->first;
	while (i)
	{
		j = map->first;
		while (j)
		{
			if (i != j && (!ft_strcmp(i->name, j->name) ||
						(i->x == j->x && i->y == j->y)))
				error(1, *map);
			j = j->next;
		}
		if (!ft_strncmp(i->name, "L", 1) || ft_strchr(i->name, '-'))
			error(2, *map);
		if (i->type != NORMAL)
			i->type == START ? start++ : end++;
		i = i->next;
	}
	check_map2(map, start, end);
}
