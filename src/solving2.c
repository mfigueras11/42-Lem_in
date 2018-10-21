/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:19:35 by mfiguera          #+#    #+#             */
/*   Updated: 2018/05/27 20:21:00 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

t_sol	*newsolution(t_sol *next)
{
	t_sol	*sol;
	int		i;

	sol = (t_sol*)malloc(sizeof(t_sol));
	sol->path = NULL;
	sol->npaths = 0;
	sol->next = next;
	if (next)
	{
		i = 0;
		while (i < next->npaths)
			sol->path = pathadd(sol->path, next->path[i++], sol->npaths++);
	}
	return (sol);
}

t_path	**pathadd(t_path **path, t_path *link, int np)
{
	int		i;
	t_path	**newpath;

	i = 0;
	newpath = (t_path**)malloc(sizeof(t_path*) * (np + 1));
	while (path && i < np)
	{
		newpath[i] = path[i];
		i++;
	}
	newpath[i] = link;
	if (path)
		free(path);
	return (newpath);
}

int		sumlengths(t_sol sol, int total, int npaths)
{
	int i;

	i = 0;
	while (i < npaths)
		total += sol.path[i++]->nrooms - 2;
	return (total);
}

void	zero_seen(int np, t_path **paths, t_room *first)
{
	int i;
	int j;

	i = 0;
	while (first)
	{
		first->seen = 0;
		first = first->next;
	}
	while (paths && i < np)
	{
		j = 0;
		while (j < paths[i]->nrooms)
			paths[i]->room[j++]->seen = 1;
		i++;
	}
}
