/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_n_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:01:53 by jeshin            #+#    #+#             */
/*   Updated: 2024/02/20 19:35:13 by jeshin           ###   ########.fr       */
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
