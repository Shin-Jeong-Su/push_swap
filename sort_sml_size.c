/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sml_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:01:53 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/21 20:28:57 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_a_of_size_5(t_dq *a, t_dq *b, int min)
{
	t_node	*here;
	int		cnt;

	here = a->head;
	cnt = 0;
	while (here && here->data != min)
	{
		cnt++;
		here = here->next;
	}
	if (cnt < 3)
	{
		while (cnt-- > 0)
			go_cmds(a, b, "ra");
		go_cmds(a, b, "pb");
	}
	if (cnt >= 3)
	{
		while (cnt++ < 5)
			go_cmds(a, b, "rra");
		go_cmds(a, b, "pb");
	}
	return (sort_a_of_size_4(a, b, 1) & go_cmds(a, b, "pa"));
}

int	sort_a_of_size_4(t_dq *a, t_dq *b, int min)
{
	t_node	*here;
	int		cnt;

	here = a->head;
	cnt = 0;
	while (here && here->data != min)
	{
		cnt++;
		here = here->next;
	}
	if (cnt < 2)
	{
		while (cnt-- > 0)
			go_cmds(a, b, "ra");
		go_cmds(a, b, "pb");
	}
	if (cnt >= 2)
	{
		while (cnt++ < 4)
			go_cmds(a, b, "rra");
		go_cmds(a, b, "pb");
	}
	return (sort_a_of_size_3(a) & go_cmds(a, b, "pa"));
}

int	sort_sml_a(t_dq *a, int size)
{
	if (is_asc(a, size) || size == 0 || size == 1)
		return (1);
	if (size == 2)
		return (go_cmds(a, 0, "sa"));
	if (size == 3 && a->size == 3)
		return (sort_a_of_size_3(a));
	return (sort_a_of_rng_3(a));
}

int	sort_sml_b(t_dq *a, t_dq *b, int size)
{
	if (size == 0)
		return (1);
	if (size == 1)
		return (go_cmds(a, b, "pa"));
	if (size == 2)
	{
		if (b->head->data > b->head->next->data)
			return (go_cmds(a, b, "pa") & go_cmds(a, b, "pa"));
		return (go_cmds(0, b, "sb") & go_cmds(a, b, "pa") \
		& go_cmds(a, b, "pa"));
	}
	if (size == 3 && b->size == 3)
		return (sort_b_of_size_3(a, b));
	if (size == 3)
		return (sort_b_of_rng_3(a, b));
	return (0);
}
