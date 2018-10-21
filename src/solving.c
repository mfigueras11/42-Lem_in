/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:51:51 by mfiguera          #+#    #+#             */
/*   Updated: 2018/05/27 20:33:11 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

t_que	*queueadd(t_que *queue, t_room *room)
{
	t_que *link;
	t_que *ret;

	ret = queue;
	link = (t_que*)malloc(sizeof(t_que));
	link->room = room;
	link->father = queue;
	link->next = NULL;
	if (queue)
	{
		while (queue->next)
			queue = queue->next;
	}
	else
		return (link);
	queue->next = link;
	return (ret);
}

t_que	*pathfinding(t_que *queue)
{
	int i;

	while (queue)
	{
		i = 0;
		if (queue->room->type == END && (!queue->room->seen ||
					(queue->room->seen && queue->father->room->type != START)))
			return (queue);
		queue->room->seen = 1;
		while (i < queue->room->nl)
		{
			if (!queue->room->linked[i]->seen ||
					queue->room->linked[i]->type == END)
				queueadd(queue, queue->room->linked[i]);
			i++;
		}
		queue = queue->next;
	}
	return (NULL);
}

t_path	*savepath(t_que *queue)
{
	t_que	*tmp;
	int		i;
	t_path	*path;

	tmp = queue;
	i = 0;
	while (tmp)
	{
		tmp = tmp->father;
		i++;
	}
	path = (t_path*)malloc(sizeof(t_path));
	path->room = (t_room**)malloc(sizeof(t_room*) * i);
	path->nrooms = i;
	while (i--)
	{
		path->room[i] = queue->room;
		queue->room->seen = 0;
		queue = queue->father;
	}
	return (path);
}

int		solving(t_map *map)
{
	t_que	*queue;
	t_que	*queue2;
	int		ret;

	ret = 1;
	while (ret)
	{
		ret = 0;
		queue = queueadd(NULL, map->rooms);
		if ((queue2 = pathfinding(queue)))
		{
			ret = 1;
			map->solution = newsolution(map->solution);
			map->solution->path = pathadd(map->solution->path,
					savepath(queue2), map->solution->npaths++);
			zero_seen(map->solution->npaths, map->solution->path, map->first);
		}
		while (queue)
		{
			queue2 = queue;
			queue = queue->next;
			free(queue2);
		}
	}
	return (map->solution ? 1 : 0);
}
