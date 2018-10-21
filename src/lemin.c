/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:36:36 by mfiguera          #+#    #+#             */
/*   Updated: 2018/05/27 20:19:01 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/lemin.h"

int		main(void)
{
	char	*line;
	int		stage;
	t_map	map;
	int		ret;

	stage = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!ft_strcmp(line, ""))
			error(3, map);
		if (parsing_manager(&map, line, &stage))
			error(4, map);
		ft_putendl(line);
		free(line);
	}
	if (ret != 0)
		error(4, map);
	if (ret == 0 && stage == 0)
		error(5, map);
	check_map(&map);
	if (!solving(&map))
		error(7, map);
	print_solution(&map);
	free_everything(map);
	return (0);
}
