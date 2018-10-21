/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:13:39 by mfiguera          #+#    #+#             */
/*   Updated: 2018/05/27 20:33:20 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

void	distribute_ants(t_sol *sol, int total, int npaths)
{
	int	i;
	int	count;
	int	np;
	int	no;

	i = 0;
	np = npaths - 1;
	count = sumlengths(*sol, total, npaths);
	while (np >= 0)
	{
		no = count / (np + 1) - (int)(count / (np + 1)) > 0 ?
			count / (np + 1) + 1 : count / (np + 1);
		sol->path[np]->ants = no - (sol->path[np]->nrooms - 2);
		sol->path[np]->antss = no - (sol->path[np]->nrooms - 2);
		count -= no;
		np--;
	}
}

int		print_solution2(int i, t_map *map)
{
	int			j;
	int			ret;
	static int	numbers;

	if (numbers == 0)
		numbers++;
	ret = 0;
	j = map->solution->path[i]->nrooms - 1;
	while (j)
	{
		map->solution->path[i]->room[j]->seen =
			map->solution->path[i]->room[j - 1]->seen;
		if (j == 1 && map->solution->path[i]->ants)
			map->solution->path[i]->room[j]->seen = numbers++;
		if (map->solution->path[i]->room[j - 1]->seen ||
			(map->solution->path[i]->ants && j == 1))
		{
			ft_printf("L%d-%s ", map->solution->path[i]->room[j]->seen,
				map->solution->path[i]->room[j]->name, (ret = 1));
		}
		if (j == 1 && map->solution->path[i]->ants)
			map->solution->path[i]->ants--;
		j--;
	}
	return (ret);
}

int		bestnpaths(t_sol *sol, int ants)
{
	int	ret;
	int mov;

	mov = sol->path[0]->nrooms - 2 + ants;
	ret = 1;
	while (ret < sol->npaths && mov > sol->path[ret]->nrooms - 1)
	{
		mov = sumlengths(*sol, ants, ret) / ret;
		((sumlengths(*sol, ants, ret) / ret) -
			(int)(sumlengths(*sol, ants, ret) / ret)) > 0 ? mov++ : 0;
		ret++;
	}
	return (ret);
}

void	print_solution(t_map *map)
{
	int ret;
	int	i;
	int max;
	int numbers;

	ret = 1;
	numbers = 1;
	max = bestnpaths(map->solution, map->ants);
	distribute_ants(map->solution, map->ants, max);
	zero_seen(0, NULL, map->first);
	while (ret)
	{
		ret = 0;
		i = 0;
		ft_putchar('\n');
		while (i < max)
			ret += print_solution2(i++, map);
	}
}
