/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:58:41 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/27 19:32:57 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_same_int(t_dq *dq)
{
	t_node	*start;
	t_node	*cmp;

	start = dq->head;
	while (start)
	{
		cmp = start->next;
		while (cmp)
		{
			if (start->data == cmp->data)
				return (1);
			cmp = cmp->next;
		}
		start = start->next;
	}
	return (0);
}

static int	push_each_to_b(char **each, t_dq *b)
{
	int			i;

	if (*each == 0)
		return (0);
	while (*each)
	{
		i = 0;
		if ((*each)[0] == '-')
			i++;
		if ((*each)[i] == 0 || (*each)[0] == 0)
			return (0);
		while ((*each)[i])
		{
			if (ft_isdigit((*each)[i]) == 0)
				return (0);
			i++;
		}
		if (!is_in_int_rng(*each, i))
			return (0);
		push_back_dq(b, ft_atoi(*each));
		each++;
	}
	return (1);
}

static char	***av_to_b(int ac, char **av, t_dq *b)
{
	int		i;
	char	***tab;

	i = 0;
	tab = (char ***)malloc(sizeof(char **) * ac);
	if (tab == 0)
		return (0);
	tab[ac - 1] = 0;
	while (av[++i])
		tab[i - 1] = ft_split(av[i], ' ');
	i = -1;
	while (tab[++i])
	{
		if (!push_each_to_b(tab[i], b))
		{
			free_all(tab);
			clear_dq(b);
			return (0);
		}
	}
	return (tab);
}

static void	push_idx_to_a(int *idx_tab, t_dq *a, t_dq *b)
{
	t_node	*here;
	int		i;

	here = b->head;
	i = 0;
	while (here)
	{
		idx_tab[i++] = here->data;
		here = here->next;
	}
	quick_sort(idx_tab, 0, b->size - 1);
	here = b->tail;
	while (here)
	{
		i = 0;
		while (i < b->size)
		{
			if (here->data == idx_tab[i])
				push_front_dq(a, i);
			i++;
		}
		here = here->prev;
	}
}

int	init(int ac, char **av, t_dq *a, t_dq *b)
{
	char	***tab;
	int		*idx_tab;

	if (ac <= 1)
		exit(EXIT_FAILURE);
	init_dq(a);
	init_dq(b);
	tab = av_to_b(ac, av, b);
	if (tab == 0)
		return (0);
	if (has_same_int(b))
	{
		free_all(tab);
		clear_dq(b);
		return (0);
	}
	idx_tab = (int *)malloc(sizeof(int) * b->size);
	if (idx_tab == 0)
		return (0);
	push_idx_to_a(idx_tab, a, b);
	while (!is_empty_dq(b))
		pop_back_dq(b);
	free(idx_tab);
	free_all(tab);
	return (1);
}
