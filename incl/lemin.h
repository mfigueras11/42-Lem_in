/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:31:55 by mfiguera          #+#    #+#             */
/*   Updated: 2018/05/27 19:16:51 by mfiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# define START 1
# define END 2
# define NORMAL 0

# include "libft/libft.h"

typedef struct	s_room
{
	char			*name;
	char			type;
	int				seen;
	int				x;
	int				y;
	int				nl;
	struct s_room	**linked;
	struct s_room	*next;
}				t_room;

typedef struct	s_path
{
	int				ants;
	int				antss;
	int				nrooms;
	t_room			**room;
}				t_path;

typedef struct	s_sol
{
	int				npaths;
	t_path			**path;
	struct s_sol	*next;
}				t_sol;

typedef struct	s_que
{
	t_room			*room;
	struct s_que	*father;
	struct s_que	*next;
}				t_que;

typedef struct	s_map
{
	int		ants;
	t_room	*rooms;
	t_room	*first;
	t_sol	*solution;
}				t_map;

int				parsing_manager(t_map *map, char *line, int *stage);
void			check_map(t_map *map);
void			error(int errno, t_map map);
int				solving(t_map *map);
void			print_solution(t_map *map);
t_sol			*newsolution(t_sol *next);
t_path			**pathadd(t_path **path, t_path *link, int np);
t_que			*queueadd(t_que *queue, t_room *room);
t_que			*pathfinding(t_que *que);
void			zero_seen(int np, t_path **paths, t_room *first);
int				sumlengths(t_sol sol, int total, int npaths);
void			distribute_ants(t_sol *sol, int total, int npaths);
void			free_everything(t_map map);

#endif
